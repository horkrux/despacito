#include "endianFlip.h"

using namespace std;

int convertHkxFileBigEndian(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Usage: ./EndianFlip <filename>\n");
		return 0;
	}

	FILE* desfile = fopen(argv[1], "rb");

	if (!desfile)
	{
		printf("Cannot open file \"%s\": %s\n", argv[1], strerror(errno));
		return 1;
	}

	printf("Converting %s...\n", argv[1]);

	fseek(desfile, 0x28, SEEK_SET);
	char havok_version[15];

	fread(havok_version, 1, 15, desfile);

	if (strcmp(havok_version, "Havok-5.5.0-r1"))
	{
		int classNameSectionSize = 0;
		fseek(desfile, 0x58, SEEK_SET);
		fread(&classNameSectionSize, 4, 1, desfile);
		classNameSectionSize = _byteswap_ulong(classNameSectionSize);

		if (classNameSectionSize > 0x330)
		{
			convertHavok4Animation(desfile, argv[1]);
		}
		else {
			convertHavok4Skeleton(desfile, argv[1]);
		}
		
		fclose(desfile);
		return 0;
	}

	//hardcoded LUL
	int dataOffsets[7];
	int* dataSectionOffsets;
	int classNameSectionSize = 0;
	int* classNameOffsets;
	char classShit[1000];
	//int numDataSectionOffsets = 0;
	//int numClassNameSectionOffsets = 0;
	int offsetDataSection = 0;

	fseek(desfile, 0x58, SEEK_SET);
	fread(&classNameSectionSize, 4, 1, desfile);
	classNameSectionSize = _byteswap_ulong(classNameSectionSize);

	if (classNameSectionSize == 0x350)
	{
		//skeleton
		convertSkeleton(desfile, argv[1]);
		fclose(desfile);
		return 1;
	}

	fseek(desfile, 0xB4, SEEK_SET);
	fread(dataOffsets, 4, 7, desfile);
	offsetDataSection = _byteswap_ulong(dataOffsets[0]);

	fseek(desfile, 0xD0, SEEK_SET);
	fread(classShit, 1, classNameSectionSize, desfile);

	fseek(desfile, offsetDataSection, SEEK_SET);

	hkRootLevelContainer_550 rootContainer;
	hkaAnimationContainer_550 animContainer;

	const char* namedVariant1Name = "Merged Animation Container";
	const char* namedVariant1ClassName = "hkaAnimationContainer";
	const char* namedVariant2Name = "Scene Data";
	const char* namedVariant2ClassName = "hkxScene";

	fread(&rootContainer, sizeof(rootContainer), 1, desfile);
	flipEndianRootContainer(&rootContainer);

	if (checkRootContainer(&rootContainer))
	{
		fclose(desfile);
		return 1;
	}

	//we expect this to be the same on ALL files
	fseek(desfile, 0x80, SEEK_CUR);

	fread(&animContainer, sizeof(animContainer), 1, desfile);
	flipEndianAnimContainer(&animContainer);

	if (checkAnimContainer(&animContainer))
	{
		fclose(desfile);
		return 1;
	}

	//skip over array
	fseek(desfile, 0x20, SEEK_CUR);

	hkaWaveletSkeletalAnimation_550 waveletAnim;
	hkaInterleavedSkeletalAnimation_550 interleavedAnim;
	hkaDeltaCompressedSkeletalAnimation_550 deltaCompressedAnim;

	char* dataBuffer = NULL;
	QsTransform* transforms = NULL;

	int numAnnotationTracks = 0;

	if (classNameSectionSize == 0x3D0)
	{
		fread(&waveletAnim, sizeof(waveletAnim), 1, desfile);
		flipEndianWaveletSkeletalAnim(&waveletAnim);

		//skip over annotation track array
		if (waveletAnim.numAnnotationTracks)
		{
			numAnnotationTracks = waveletAnim.numAnnotationTracks;
			fseek(desfile, waveletAnim.numAnnotationTracks * 4, SEEK_CUR);
			//waveletAnim.numAnnotationTracks = 0;
		}

		dataBuffer = (char*)malloc(waveletAnim.numDataBuffer);

		fread(dataBuffer, 1, waveletAnim.numDataBuffer, desfile);

		//if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);
	} 
	else if (classNameSectionSize == 0x3E0)
	{
		fread(&deltaCompressedAnim, sizeof(deltaCompressedAnim), 1, desfile);
		flipEndianDeltaCompressedSkeletalAnim(&deltaCompressedAnim);

		dataBuffer = (char*)malloc(deltaCompressedAnim.numDataBuffer);

		fread(dataBuffer, 1, deltaCompressedAnim.numDataBuffer, desfile);

		//int shit = ftell(desfile);

		//if (shit % 16) 
		//	fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);
	}
	else {
		fread(&interleavedAnim, sizeof(interleavedAnim), 1, desfile);
		flipEndianInterleavedSkeletalAnim(&interleavedAnim);

		if (interleavedAnim.numTransforms)
		{
			transforms = (QsTransform*)malloc(interleavedAnim.numTransforms * sizeof(QsTransform));

			fread(transforms, sizeof(QsTransform), interleavedAnim.numTransforms, desfile);

			for (int i = 0; i < interleavedAnim.numTransforms; i++)
			{
				flipEndianQsTranform(&transforms[i]);
			}
		}

		if (checkInterleavedSkeletalAnim(&interleavedAnim))
		{
			if (dataBuffer)
				free(dataBuffer);
			if (transforms)
				free(transforms);
			fclose(desfile);
			return 1;
		}
	}

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	hkaDefaultAnimatedReferenceFrame_550 refFrame;

	fread(&refFrame, sizeof(refFrame), 1, desfile);
	flipEndianReferenceFrame(&refFrame);

	Vector4* refFrameSamples = 0;

	if (refFrame.numReferenceFrameSamples)
	{
		refFrameSamples = (Vector4*)malloc(sizeof(Vector4) * refFrame.numReferenceFrameSamples);
		fread(refFrameSamples, sizeof(Vector4), refFrame.numReferenceFrameSamples, desfile);

		for (int i = 0; i < refFrame.numReferenceFrameSamples; i++)
		{
			refFrameSamples[i].x = _byteswap_ulong(refFrameSamples[i].x);
			refFrameSamples[i].y = _byteswap_ulong(refFrameSamples[i].y);
			refFrameSamples[i].z = _byteswap_ulong(refFrameSamples[i].z);
			refFrameSamples[i].w = _byteswap_ulong(refFrameSamples[i].w);
		}
	}

	hkaAnnotationTrack* annotationTracks = NULL;
	AnnotationTrackName* annotationTrackNames = NULL;

	if (numAnnotationTracks)
	{
		annotationTracks = (hkaAnnotationTrack*)malloc(sizeof(hkaAnnotationTrack) * numAnnotationTracks);
		annotationTrackNames = (AnnotationTrackName*)malloc(sizeof(AnnotationTrackName) * numAnnotationTracks);

		for (int i = 0; i < numAnnotationTracks; i++)
		{
			fread(&annotationTracks[i], sizeof(hkaAnnotationTrack), 1, desfile);

			annotationTracks[i].numAnnotations = _byteswap_ulong(annotationTracks[i].numAnnotations);

			if (annotationTracks[i].numAnnotations)
			{
				printf("ERROR: Annotation found. Exiting\n");
				if (dataBuffer)
					free(dataBuffer);
				if (transforms)
					free(transforms);
				if (refFrameSamples)
					free(refFrameSamples);
				if (annotationTracks)
					free(annotationTracks);
				if (annotationTrackNames)
					free(annotationTrackNames);
				fclose(desfile);
				return 1;
			}

			fread(annotationTrackNames[i].name, 1, 16, desfile);
				
		}


	}

	hkaAnimationBinding_550 binding;

	fread(&binding, sizeof(binding), 1, desfile);
	flipEndianAnimBinding(&binding);

	if (checkAnimBinding(&binding))
	{
		if (dataBuffer)
			free(dataBuffer);
		if (transforms)
			free(transforms);
		if (refFrameSamples)
			free(refFrameSamples);
		if (annotationTracks)
			free(annotationTracks);
		if (annotationTrackNames)
			free(annotationTrackNames);
		fclose(desfile);
		return 1;
	}

	short* transformTrackToBoneIndices = 0;

	if (binding.numTransformTrackToBoneIndices)
	{
		transformTrackToBoneIndices = (short*)malloc(2 * binding.numTransformTrackToBoneIndices);
		fread(transformTrackToBoneIndices, 2, binding.numTransformTrackToBoneIndices, desfile);

		for (int i = 0; i < binding.numTransformTrackToBoneIndices; i++)
		{
			transformTrackToBoneIndices[i] = _byteswap_ushort(transformTrackToBoneIndices[i]);
		}
	}

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	hkxScene_550 scene;

	char sceneAssetName[320];
	char sceneModellerName[320];

	fread(&scene, sizeof(scene), 1, desfile);
	flipEndianScene(&scene);

	if (checkScene(&scene))
	{
		if (dataBuffer)
			free(dataBuffer);
		if (transformTrackToBoneIndices)
			free(transformTrackToBoneIndices);
		if (transforms)
			free(transforms);
		if (refFrameSamples)
			free(refFrameSamples);
		if (annotationTracks)
			free(annotationTracks);
		if (annotationTrackNames)
			free(annotationTrackNames);
		fclose(desfile);
		return 1;
	}

	char read;
	char* tempSceneAssetName = sceneAssetName;
	char* tempSceneModellerName = sceneModellerName;
	
	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneModellerName = read;
		fread(&read, 1, 1, desfile);
		tempSceneModellerName++;
	}

	*tempSceneModellerName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneAssetName = read;
		fread(&read, 1, 1, desfile);
		tempSceneAssetName++;
	}

	*tempSceneAssetName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);
	


	//fread(dataSectionOffsets, 4, 48, desfile);
	//fread(classNameOffsets, 4, 20, desfile);

	//swap endian on offsets
	for (int i = 0; i < 7; i++)
	{
		dataOffsets[i] = _byteswap_ulong(dataOffsets[i]);
	}

	int numDataSectionOffsets = (dataOffsets[3] - dataOffsets[1]) / 4;
	int numClassNameOffsets = (dataOffsets[6] - dataOffsets[3]) / 4;

	dataSectionOffsets = (int*)malloc(4 * numDataSectionOffsets);
	classNameOffsets = (int*)malloc(4 * numClassNameOffsets);

	fread(dataSectionOffsets, 4, numDataSectionOffsets, desfile);
	fread(classNameOffsets, 4, numClassNameOffsets, desfile);

	for (int i = 0; i < numDataSectionOffsets; i++)
	{
		dataSectionOffsets[i] = _byteswap_ulong(dataSectionOffsets[i]);
	}

	for (int i = 0; i < numClassNameOffsets; i++)
	{
		classNameOffsets[i] = _byteswap_ulong(classNameOffsets[i]);
	}

	fclose(desfile);
	printf("finished reading\n");

	//READING FINISHED

	//START WRITING

	char le_filename[256];
	char* shortened_path;

	shortened_path = strrchr(argv[1], '\\');

	if (shortened_path) {
		sprintf(le_filename, "le/%s", shortened_path);
	}
	else {
		sprintf(le_filename, "le/%s", argv[1]);
	}

	_mkdir("le");

	FILE* output = fopen(le_filename, "wb");

	int out = 0x57e0e057;

	fwrite(&out, 4, 1, output);

	out = 0x10c0c010;

	fwrite(&out, 4, 1, output);

	fseek(output, 4, SEEK_CUR);

	out = 5;

	fwrite(&out, 4, 1, output);

	out = 0x1000104;

	fwrite(&out, 4, 1, output);

	out = 3;

	fwrite(&out, 4, 1, output);

	out = 2;

	fwrite(&out, 4, 1, output);

	fseek(output, 8, SEEK_CUR);

	//determine offset to hkRootLevelContainer name
	if (classNameSectionSize == 0x3E0) {
		out = 0x202;
	}
	else {
		out = 0x1C7;
	}

	fwrite(&out, 4, 1, output);

	const char* havokVersion = "Havok-5.5.0-r1";

	fwrite(havokVersion, 1, 15, output);

	short pad = 0xffff;
	int pad2 = 0xffffffff;

	fwrite(&pad, 1, 1, output);
	fwrite(&pad2, 4, 1, output);
	fwrite(&pad2, 4, 1, output);

	const char* classNames = "__classnames__";
	const char* types = "__types__";
	const char* data = "__data__";

	fwrite(classNames, 1, 15, output);
	fseek(output, 4, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0;

	fwrite(&out, 4, 1, output);

	out = classNameSectionSize;

	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);

	fwrite(types, 1, 10, output);
	fseek(output, 9, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0 + classNameSectionSize;

	fwrite(&out, 4, 1, output);

	fseek(output, 0x18, SEEK_CUR);

	fwrite(data, 1, 9, output);

	fseek(output, 10, SEEK_CUR);

	fwrite(&pad, 1, 1, output);

	fwrite(dataOffsets, 4, 7, output);

	int hash = 0x38771F8E;
	char pado = 9;

	char classString[128];

	strcpy(classString, "hkClass");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA5240F57;
	strcpy(classString, "hkClassMember");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8A3609CF;
	strcpy(classString, "hkClassEnum");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCE6F8A6C;
	strcpy(classString, "hkClassEnumItem");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x731888CA;
	strcpy(classString, "hkaAnnotationTrackAnnotation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF2EC0C9C;
	strcpy(classString, "hkxMaterial");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1C8A8C37;
	strcpy(classString, "hkxIndexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF64B134C;
	strcpy(classString, "hkxTextureInplace");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA74011F0;
	strcpy(classString, "hkaBone");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x912C8863;
	strcpy(classString, "hkxMeshSection");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x0217EF77;
	strcpy(classString, "hkxTextureFile");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3E0)
	{
		hash = 0x724A7561;
		strcpy(classString, "hkaDeltaCompressedSkeletalAnimationQuantizationFormat");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x334DBE6C;
	strcpy(classString, "hkaSkeleton");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x379FD194;
	strcpy(classString, "hkxVertexFormat");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xC532C710;
	strcpy(classString, "hkxSkinBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x4DA6A6F4;
	strcpy(classString, "hkaMeshBindingMapping");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1FB22361;
	strcpy(classString, "hkxScene");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCDB31E0C;
	strcpy(classString, "hkaMeshBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x3B1C1113;
	strcpy(classString, "hkReferencedObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF456626D;
	strcpy(classString, "hkaAnimationContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x846FC690;
	strcpy(classString, "hkaAnnotationTrack");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xFB496074;
	strcpy(classString, "hkaAnimationBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8E92A993;
	strcpy(classString, "hkxLight");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF598A34E;
	strcpy(classString, "hkRootLevelContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xDA8C7D7D;
	strcpy(classString, "hkaAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x64E9A03C;
	strcpy(classString, "hkxMeshUserChannelInfo");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x914DA6C1;
	strcpy(classString, "hkxAttribute");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x98F9313D;
	strcpy(classString, "hkaSkeletalAnimation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x158BEA87;
	strcpy(classString, "hkxNodeSelectionSet");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x521E9517;
	strcpy(classString, "hkxNodeAnnotationData");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE0708A00;
	strcpy(classString, "hkBaseObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x445A443A;
	strcpy(classString, "hkxAttributeHolder");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xD5C65FAE;
	strcpy(classString, "hkxCamera");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3D0)
	{
		hash = 0x724A7561;
		strcpy(classString, "hkaWaveletSkeletalAnimationQuantizationFormat");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}
	

	hash = 0xE085BA9F;
	strcpy(classString, "hkxMaterialTextureStage");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3A0)
	{
		hash = 0x62B02E7B;
		strcpy(classString, "hkaInterleavedSkeletalAnimation");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x72E8E849;
	strcpy(classString, "hkxMesh");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8BDD3E9A;
	strcpy(classString, "hkaBoneAttachment");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3D0)
	{
		hash = 0x5974FFE8;
		strcpy(classString, "hkaWaveletSkeletalAnimation");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x122F506B;
	strcpy(classString, "hkaDefaultAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x853A899C;
	strcpy(classString, "hkRootLevelContainerNamedVariant");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3E0)
	{
		hash = 0x83C6794C;
		strcpy(classString, "hkaDeltaCompressedSkeletalAnimation");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x06AF1B5A;
	strcpy(classString, "hkxNode");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1667C01C;
	strcpy(classString, "hkxAttributeGroup");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x57061454;
	strcpy(classString, "hkxVertexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize != 0x3A0)
	{
		fwrite(&pad2, 1, 1, output);
	}
	fwrite(&pad2, 1, 1, output);
	fwrite(&pad2, 4, 1, output);

	//fwrite(classShit, 1, 976, output);

	fwrite(&rootContainer, sizeof(hkRootLevelContainer_550), 1, output);
	fseek(output, 0x20, SEEK_CUR);

	fprintf(output, namedVariant1Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant1ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(&animContainer, sizeof(animContainer), 1, output);
	
	fseek(output, 0x20, SEEK_CUR);

	if (classNameSectionSize == 0x3D0)
	{
		fwrite(&waveletAnim, sizeof(waveletAnim), 1, output);

		if (numAnnotationTracks)
		{
			fseek(output, 4 * numAnnotationTracks, SEEK_CUR);
		}

		fwrite(dataBuffer, 1, waveletAnim.numDataBuffer, output);

		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}
	else if (classNameSectionSize == 0x3E0)
	{
		fwrite(&deltaCompressedAnim, sizeof(deltaCompressedAnim), 1, output);
		fwrite(dataBuffer, 1, deltaCompressedAnim.numDataBuffer, output);

		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}
	else {
		fwrite(&interleavedAnim, sizeof(interleavedAnim), 1, output);
		fwrite(transforms, sizeof(QsTransform), interleavedAnim.numTransforms, output);
	}

	fwrite(&refFrame, sizeof(refFrame), 1, output);

	if (refFrame.numReferenceFrameSamples)
		fwrite(refFrameSamples, sizeof(Vector4), refFrame.numReferenceFrameSamples, output);

	if (numAnnotationTracks)
	{
		for (int i = 0; i < numAnnotationTracks; i++)
		{
			fwrite(&annotationTracks[i], sizeof(hkaAnnotationTrack), 1, output);
			fwrite(annotationTrackNames[i].name, 1, 16, output);
		}


	}

	fwrite(&binding, sizeof(binding), 1, output);
	
	if (binding.numTransformTrackToBoneIndices)
	{
		fwrite(transformTrackToBoneIndices, 2, binding.numTransformTrackToBoneIndices, output);
		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}

	fwrite(&scene, sizeof(scene), 1, output);

	fprintf(output, sceneModellerName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, sceneAssetName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(dataSectionOffsets, 4, numDataSectionOffsets, output);
	fwrite(classNameOffsets, 4, numClassNameOffsets, output);

	if (dataSectionOffsets)
		free(dataSectionOffsets);
	if (classNameOffsets)
		free(classNameOffsets);
	if (dataBuffer)
		free(dataBuffer);
	if (transformTrackToBoneIndices)
		free(transformTrackToBoneIndices);
	if (transforms)
		free(transforms);
	if (refFrameSamples)
		free(refFrameSamples);
	if (annotationTracks)
		free(annotationTracks);
	if (annotationTrackNames)
		free(annotationTrackNames);
	fclose(output);

	printf("finished writing\n");

	return 0;
}

int checkRootContainer(hkRootLevelContainer_550* root)
{
	int result = 0;
	if (root->numNamedVariants != 2)
	{
		printf("ERROR: numNamedVariants == %d\n", root->numNamedVariants);
		result = 1;
	}
	
	return result;
}

int checkAnimContainer(hkaAnimationContainer_550* animContainer)
{
	int result = 0;

	if (animContainer->numAnimations != 1)
	{
		printf("ERROR: numAnimations == %d\n", animContainer->numAnimations);
		result = 1;
	}

	if (animContainer->numAttachments != 0)
	{
		printf("ERROR: numAttachments == %d\n", animContainer->numAttachments);
		result = 1;
	}

	if (animContainer->numBindings != 1)
	{
		printf("ERROR: numBindings == %d\n", animContainer->numBindings);
		result = 1;
	}

	if (animContainer->numSkeletons != 0)
	{
		printf("ERROR: numSkeletons == %d\n", animContainer->numSkeletons);
		result = 1;
	}

	if (animContainer->numSkins != 0)
	{
		printf("ERROR: numSkins == %d\n", animContainer->numSkins);
		result = 1;
	}

	return result;
}

int checkInterleavedSkeletalAnim(hkaInterleavedSkeletalAnimation_550* anim)
{
	int result = 0;

	if (anim->numFloats != 0)
	{
		printf("ERROR: numFloats == %d\n", anim->numFloats);
		result = 1;
	}

	return result;
}

int checkAnimBinding(hkaAnimationBinding_550* binding)
{
	int result = 0;

	if (binding->numFloatTrackToFloatSlotIndices != 0)
	{
		printf("ERROR: numFloatTrackToFloatSlotIndices == %d\n", binding->numFloatTrackToFloatSlotIndices);
		result = 1;
	}

	return result;
}

int checkScene(hkxScene_550* scene)
{
	int result = 0;

	if (scene->numSelectionSets)
	{
		printf("ERROR: numSelectionSets == %d\n", scene->numSelectionSets);
		result = 1;
	}

	if (scene->numCameras)
	{
		printf("ERROR: numCameras == %d\n", scene->numCameras);
		result = 1;
	}

	if (scene->numLights)
	{
		printf("ERROR: numLights == %d\n", scene->numLights);
		result = 1;
	}

	if (scene->numMeshes)
	{
		printf("ERROR: numMeshes == %d\n", scene->numMeshes);
		result = 1;
	}

	if (scene->numMaterials)
	{
		printf("ERROR: numMaterials == %d\n", scene->numMaterials);
		result = 1;
	}

	if (scene->numInplaceTextures)
	{
		printf("ERROR: numInplaceTextures == %d\n", scene->numInplaceTextures);
		result = 1;
	}

	if (scene->numExternalTextures)
	{
		printf("ERROR: numExternalTextures == %d\n", scene->numExternalTextures);
		result = 1;
	}

	if (scene->numSkinBindings)
	{
		printf("ERROR: numSkinBindings == %d\n", scene->numSkinBindings);
		result = 1;
	}

	return result;
}

void flipEndianRootContainer(hkRootLevelContainer_550* rootContainer)
{
	rootContainer->numNamedVariants = _byteswap_ulong(rootContainer->numNamedVariants);
}

void flipEndianAnimContainer(hkaAnimationContainer_550* animContainer)
{
	animContainer->numAnimations = _byteswap_ulong(animContainer->numAnimations);
	animContainer->numBindings = _byteswap_ulong(animContainer->numBindings);
	animContainer->numSkeletons = _byteswap_ulong(animContainer->numSkeletons);
	animContainer->numAttachments = _byteswap_ulong(animContainer->numAttachments);
	animContainer->numSkins = _byteswap_ulong(animContainer->numSkins);
}

void flipEndianWaveletSkeletalAnim(hkaWaveletSkeletalAnimation_550* anim)
{
	anim->type = _byteswap_ulong(anim->type);
	anim->duration = _byteswap_ulong(anim->duration);
	anim->numberOfTransformTracks = _byteswap_ulong(anim->numberOfTransformTracks);
	anim->numberOfFloatTracks = _byteswap_ulong(anim->numberOfFloatTracks);
	anim->numAnnotationTracks = _byteswap_ulong(anim->numAnnotationTracks);
	anim->numberOfPoses = _byteswap_ulong(anim->numberOfPoses);
	anim->blockSize = _byteswap_ulong(anim->blockSize);
	anim->numD = _byteswap_ulong(anim->numD);
	anim->offsetIdx = _byteswap_ulong(anim->offsetIdx);
	anim->scaleIdx = _byteswap_ulong(anim->scaleIdx);
	anim->bitWidthIdx = _byteswap_ulong(anim->bitWidthIdx);
	anim->staticMaskIdx = _byteswap_ulong(anim->staticMaskIdx);
	anim->staticDOFsIdx = _byteswap_ulong(anim->staticDOFsIdx);
	anim->blockIndexIdx = _byteswap_ulong(anim->blockIndexIdx);
	anim->blockIndexSize = _byteswap_ulong(anim->blockIndexSize);
	anim->quantizedDataIdx = _byteswap_ulong(anim->quantizedDataIdx);
	anim->quantizedDataSize = _byteswap_ulong(anim->quantizedDataSize);
	anim->numDataBuffer = _byteswap_ulong(anim->numDataBuffer);
}

void flipEndianWaveletSkeletalAnim450(hkaWaveletSkeletalAnimation_450* anim)
{
	anim->type = _byteswap_ulong(anim->type);
	anim->duration = _byteswap_ulong(anim->duration);
	anim->numberOfTracks = _byteswap_ulong(anim->numberOfTracks);
	anim->numAnnotationTracks = _byteswap_ulong(anim->numAnnotationTracks);
	anim->numberOfPoses = _byteswap_ulong(anim->numberOfPoses);
	anim->blockSize = _byteswap_ulong(anim->blockSize);
	anim->numD = _byteswap_ulong(anim->numD);
	anim->offsetIdx = _byteswap_ulong(anim->offsetIdx);
	anim->scaleIdx = _byteswap_ulong(anim->scaleIdx);
	anim->bitWidthIdx = _byteswap_ulong(anim->bitWidthIdx);
	anim->staticMaskIdx = _byteswap_ulong(anim->staticMaskIdx);
	anim->staticDOFsIdx = _byteswap_ulong(anim->staticDOFsIdx);
	anim->blockIndexIdx = _byteswap_ulong(anim->blockIndexIdx);
	anim->blockIndexSize = _byteswap_ulong(anim->blockIndexSize);
	anim->quantizedDataIdx = _byteswap_ulong(anim->quantizedDataIdx);
	anim->quantizedDataSize = _byteswap_ulong(anim->quantizedDataSize);
	anim->numDataBuffer = _byteswap_ulong(anim->numDataBuffer);
}

void flipEndianInterleavedSkeletalAnim(hkaInterleavedSkeletalAnimation_550* anim)
{
	anim->type = _byteswap_ulong(anim->type);
	anim->duration = _byteswap_ulong(anim->duration);
	anim->numberOfTransformTracks = _byteswap_ulong(anim->numberOfTransformTracks);
	anim->numberOfFloatTracks = _byteswap_ulong(anim->numberOfFloatTracks);
	anim->numAnnotationTracks = _byteswap_ulong(anim->numAnnotationTracks);
	anim->numTransforms = _byteswap_ulong(anim->numTransforms);
	anim->numFloats = _byteswap_ulong(anim->numFloats);
}

void flipEndianDeltaCompressedSkeletalAnim(hkaDeltaCompressedSkeletalAnimation_550* anim)
{
	anim->type = _byteswap_ulong(anim->type);
	anim->duration = _byteswap_ulong(anim->duration);
	anim->numberOfTransformTracks = _byteswap_ulong(anim->numberOfTransformTracks);
	anim->numberOfFloatTracks = _byteswap_ulong(anim->numberOfFloatTracks);
	anim->numAnnotationTracks = _byteswap_ulong(anim->numAnnotationTracks);
	anim->numberOfPoses = _byteswap_ulong(anim->numberOfPoses);
	anim->blockSize = _byteswap_ulong(anim->blockSize);
	anim->numD = _byteswap_ulong(anim->numD);
	anim->offsetIdx = _byteswap_ulong(anim->offsetIdx);
	anim->scaleIdx = _byteswap_ulong(anim->scaleIdx);
	anim->bitWidthIdx = _byteswap_ulong(anim->bitWidthIdx);
	anim->quantizedDataIdx = _byteswap_ulong(anim->quantizedDataIdx);
	anim->quantizedDataSize = _byteswap_ulong(anim->quantizedDataSize);
	anim->staticMaskIdx = _byteswap_ulong(anim->staticMaskIdx);
	anim->staticMaskSize = _byteswap_ulong(anim->staticMaskSize);
	anim->staticDOFsIdx = _byteswap_ulong(anim->staticDOFsIdx);
	anim->staticDOFsSize = _byteswap_ulong(anim->staticDOFsSize);
	anim->totalBlockSize = _byteswap_ulong(anim->totalBlockSize);
	anim->lastBlockSize = _byteswap_ulong(anim->lastBlockSize);
	anim->numDataBuffer = _byteswap_ulong(anim->numDataBuffer);
}

void flipEndianDeltaCompressedSkeletalAnim450(hkaDeltaCompressedSkeletalAnimation_450* anim)
{
	anim->type = _byteswap_ulong(anim->type);
	anim->duration = _byteswap_ulong(anim->duration);
	anim->numberOfTracks = _byteswap_ulong(anim->numberOfTracks);
	anim->numAnnotationTracks = _byteswap_ulong(anim->numAnnotationTracks);
	anim->numberOfPoses = _byteswap_ulong(anim->numberOfPoses);
	anim->blockSize = _byteswap_ulong(anim->blockSize);
	anim->numD = _byteswap_ulong(anim->numD);
	anim->offsetIdx = _byteswap_ulong(anim->offsetIdx);
	anim->scaleIdx = _byteswap_ulong(anim->scaleIdx);
	anim->bitWidthIdx = _byteswap_ulong(anim->bitWidthIdx);
	anim->quantizedDataIdx = _byteswap_ulong(anim->quantizedDataIdx);
	anim->quantizedDataSize = _byteswap_ulong(anim->quantizedDataSize);
	anim->staticMaskIdx = _byteswap_ulong(anim->staticMaskIdx);
	anim->staticMaskSize = _byteswap_ulong(anim->staticMaskSize);
	anim->staticDOFsIdx = _byteswap_ulong(anim->staticDOFsIdx);
	anim->staticDOFsSize = _byteswap_ulong(anim->staticDOFsSize);
	anim->totalBlockSize = _byteswap_ulong(anim->totalBlockSize);
	anim->lastBlockSize = _byteswap_ulong(anim->lastBlockSize);
	anim->numDataBuffer = _byteswap_ulong(anim->numDataBuffer);
}

void flipEndianReferenceFrame(hkaDefaultAnimatedReferenceFrame_550* refFrame)
{
	refFrame->up.x = _byteswap_ulong(refFrame->up.x);
	refFrame->up.y = _byteswap_ulong(refFrame->up.y);
	refFrame->up.z = _byteswap_ulong(refFrame->up.z);
	refFrame->up.w = _byteswap_ulong(refFrame->up.w);
	refFrame->forward.x = _byteswap_ulong(refFrame->forward.x);
	refFrame->forward.y = _byteswap_ulong(refFrame->forward.y);
	refFrame->forward.z = _byteswap_ulong(refFrame->forward.z);
	refFrame->forward.w = _byteswap_ulong(refFrame->forward.w);
	refFrame->duration = _byteswap_ulong(refFrame->duration);
	refFrame->numReferenceFrameSamples = _byteswap_ulong(refFrame->numReferenceFrameSamples);
}

void flipEndianAnimBinding(hkaAnimationBinding_550* binding)
{
	binding->numFloatTrackToFloatSlotIndices = _byteswap_ulong(binding->numFloatTrackToFloatSlotIndices);
	binding->numTransformTrackToBoneIndices = _byteswap_ulong(binding->numTransformTrackToBoneIndices);
}

void flipEndianAnimBinding450(hkAnimationBinding_450* binding)
{
	binding->numAnimationTrackToBoneIndices = _byteswap_ulong(binding->numAnimationTrackToBoneIndices);
}

void flipEndianScene(hkxScene_550* scene)
{
	scene->sceneLength = _byteswap_ulong(scene->sceneLength);
	scene->numSelectionSets = _byteswap_ulong(scene->numSelectionSets);
	scene->numCameras = _byteswap_ulong(scene->numCameras);
	scene->numLights = _byteswap_ulong(scene->numLights);
	scene->numMeshes = _byteswap_ulong(scene->numMeshes);
	scene->numMaterials = _byteswap_ulong(scene->numMaterials);
	scene->numInplaceTextures = _byteswap_ulong(scene->numInplaceTextures);
	scene->numExternalTextures = _byteswap_ulong(scene->numExternalTextures);
	scene->numSkinBindings = _byteswap_ulong(scene->numSkinBindings);
	scene->appliedTransform[0].x = _byteswap_ulong(scene->appliedTransform[0].x);
	scene->appliedTransform[0].y = _byteswap_ulong(scene->appliedTransform[0].y);
	scene->appliedTransform[0].z = _byteswap_ulong(scene->appliedTransform[0].z);
	scene->appliedTransform[0].w = _byteswap_ulong(scene->appliedTransform[0].w);
	scene->appliedTransform[1].x = _byteswap_ulong(scene->appliedTransform[1].x);
	scene->appliedTransform[1].y = _byteswap_ulong(scene->appliedTransform[1].y);
	scene->appliedTransform[1].z = _byteswap_ulong(scene->appliedTransform[1].z);
	scene->appliedTransform[1].w = _byteswap_ulong(scene->appliedTransform[1].w);
	scene->appliedTransform[2].x = _byteswap_ulong(scene->appliedTransform[2].x);
	scene->appliedTransform[2].y = _byteswap_ulong(scene->appliedTransform[2].y);
	scene->appliedTransform[2].z = _byteswap_ulong(scene->appliedTransform[2].z);
	scene->appliedTransform[2].w = _byteswap_ulong(scene->appliedTransform[2].w);
}

void flipEndianQsTranform(QsTransform* transform)
{
	transform->translation.x = _byteswap_ulong(transform->translation.x);
	transform->translation.y = _byteswap_ulong(transform->translation.y);
	transform->translation.z = _byteswap_ulong(transform->translation.z);
	transform->translation.w = _byteswap_ulong(transform->translation.w);
	transform->rotation.x = _byteswap_ulong(transform->rotation.x);
	transform->rotation.y = _byteswap_ulong(transform->rotation.y);
	transform->rotation.z = _byteswap_ulong(transform->rotation.z);
	transform->rotation.w = _byteswap_ulong(transform->rotation.w);
	transform->scale.x = _byteswap_ulong(transform->scale.x);
	transform->scale.y = _byteswap_ulong(transform->scale.y);
	transform->scale.z = _byteswap_ulong(transform->scale.z);
	transform->scale.w = _byteswap_ulong(transform->scale.w);
}

void flipEndianSkeleton(hkaSkeleton_550* skeleton)
{
	skeleton->numParentIndices = _byteswap_ulong(skeleton->numParentIndices);
	skeleton->numBones = _byteswap_ulong(skeleton->numBones);
	skeleton->numReferencePose = _byteswap_ulong(skeleton->numReferencePose);
	skeleton->numFloatSlots = _byteswap_ulong(skeleton->numFloatSlots);
}

void flipEndianSkeleton450(hkaSkeleton_450* skeleton)
{
	skeleton->numParentIndices = _byteswap_ulong(skeleton->numParentIndices);
	skeleton->numBones = _byteswap_ulong(skeleton->numBones);
	skeleton->numReferencePose = _byteswap_ulong(skeleton->numReferencePose);
}

void hkaDeltaCompressedSkeletalAnimation_450to550(hkaDeltaCompressedSkeletalAnimation_550* animNew, hkaDeltaCompressedSkeletalAnimation_450* animOld)
{
	animNew->ignore1 = 0;
	animNew->ignore2 = 0;
	animNew->type = animOld->type;
	animNew->duration = animOld->duration;
	animNew->numberOfTransformTracks = animOld->numberOfTracks;
	animNew->numberOfFloatTracks = 0;
	animNew->extractedMotion = 0;
	animNew->annotationTracks = 0;
	animNew->numAnnotationTracks = 0;
	animNew->numberOfPoses = animOld->numberOfPoses;
	animNew->blockSize = animOld->blockSize;
	animNew->maxBitWidth = animOld->maxBitWidth;
	animNew->preserved = 1;
	animNew->pad1 = 0;
	animNew->pad2 = 0;
	animNew->numD = animOld->numD;
	animNew->offsetIdx = animOld->offsetIdx;
	animNew->scaleIdx = animOld->scaleIdx;
	animNew->bitWidthIdx = animOld->bitWidthIdx;
	animNew->quantizedDataIdx = animOld->quantizedDataIdx;
	animNew->quantizedDataSize = animOld->quantizedDataSize;
	animNew->staticMaskIdx = animOld->staticMaskIdx;
	animNew->staticMaskSize = animOld->staticMaskSize;
	animNew->staticDOFsIdx = animOld->staticDOFsIdx;
	animNew->staticDOFsSize = animOld->staticDOFsSize;
	animNew->totalBlockSize = animOld->totalBlockSize;
	animNew->lastBlockSize = animOld->lastBlockSize;
	animNew->dataBuffer = 0;
	animNew->numDataBuffer = animOld->numDataBuffer;
	animNew->pad[0] = 0;
	animNew->pad[1] = 0;
}

void hkaWaveletSkeletalAnimation_450to550(hkaWaveletSkeletalAnimation_550* animNew, hkaWaveletSkeletalAnimation_450* animOld)
{
	animNew->ignore1 = 0;
	animNew->ignore2 = 0;
	animNew->type = 3;
	animNew->duration = animOld->duration;
	animNew->numberOfTransformTracks = animOld->numberOfTracks;
	animNew->numberOfFloatTracks = 0;
	animNew->extractedMotion = 0;
	animNew->annotationTracks = 0;
	animNew->numAnnotationTracks = 0;
	animNew->numberOfPoses = animOld->numberOfPoses;
	animNew->blockSize = animOld->blockSize;
	animNew->maxBitWidth = animOld->maxBitWidth;
	animNew->preserved = 1;
	animNew->pad1 = 0;
	animNew->pad2 = 0;
	animNew->numD = animOld->numD;
	animNew->offsetIdx = animOld->offsetIdx;
	animNew->scaleIdx = animOld->scaleIdx;
	animNew->bitWidthIdx = animOld->bitWidthIdx;
	animNew->staticMaskIdx = animOld->staticMaskIdx;
	animNew->staticDOFsIdx = animOld->staticDOFsIdx;
	animNew->blockIndexIdx = animOld->blockIndexIdx;
	animNew->blockIndexSize = animOld->blockIndexSize;
	animNew->quantizedDataIdx = animOld->quantizedDataIdx;
	animNew->quantizedDataSize = animOld->quantizedDataSize;
	animNew->dataBuffer = 0;
	animNew->numDataBuffer = animOld->numDataBuffer;
}

void hkaAnimationBinding_450to550(hkaAnimationBinding_550* bindingNew, hkAnimationBinding_450* bindingOld)
{
	bindingNew->animation = 0;
	bindingNew->transformTrackToBoneIndices = 0;
	bindingNew->numTransformTrackToBoneIndices = bindingOld->numAnimationTrackToBoneIndices;
	bindingNew->floatTrackToFloatSlotIndices = 0;
	bindingNew->numFloatTrackToFloatSlotIndices = 0;
	bindingNew->blendHint = bindingOld->blendHint;
	bindingNew->pad1 = 0;
	bindingNew->pad2 = 0;
	bindingNew->pad3 = 0;
	bindingNew->pad4 = 0;
}

void hkaSkeleton_450to550(hkaSkeleton_550* skeletonNew, hkaSkeleton_450* skeletonOld)
{
	skeletonNew->name = 0;
	skeletonNew->bones = 0;
	skeletonNew->numBones = skeletonOld->numBones;
	skeletonNew->parentIndices = 0;
	skeletonNew->numParentIndices = skeletonOld->numParentIndices;
	skeletonNew->referencePose = 0;
	skeletonNew->numReferencePose = skeletonOld->numReferencePose;
	skeletonNew->floatSlots = 0;
	skeletonNew->numFloatSlots = 0;
	skeletonNew->pad[0] = 0;
	skeletonNew->pad[1] = 0;
	skeletonNew->pad[2] = 0;
}

void convertHavok4Animation(FILE* desfile, char* filename)
{
	int dataOffsets[7];
	int* shitOffsets;
	int dataSectionOffsets[284];
	int classNameSectionSize = 0;
	int classNameOffsets[276];
	char classShit[1000];
	int numDataSectionOffsets = 0;
	int numClassNameSectionOffsets = 0;

	int offsetRefFrameFrameSamples = 0;
	int offsetRefFrameFrameSamplesData = 0;
	int offsetAnimBindingtransformTrackToBoneIndices = 0;
	int offsetAnimBindingtransformTrackToBoneIndicesData = 0;
	int offsetHkxSceneModeller = 0;
	int offsetHkxSceneModellerData = 0;
	int offsetHkxSceneAsset = 0;
	int offsetHkxSceneAssetData = 0;
	int offsetAnimBindingAnimation = 0;
	int offsetRefFrame = 0;
	int offsetOffsetSection = 0;

	vector<pair<int, int>> arrayOffsets;
	vector<tuple<int, int, int>> ptrOffsets;
	vector<tuple<int, int, int>> classOffsets;

	fseek(desfile, 0x58, SEEK_SET);
	fread(&classNameSectionSize, 4, 1, desfile);
	classNameSectionSize = _byteswap_ulong(classNameSectionSize);

	fseek(desfile, 0x84, SEEK_SET);
	fread(dataOffsets, 4, 7, desfile);

	for (int i = 0; i < 7; i++)
	{
		dataOffsets[i] = _byteswap_ulong(dataOffsets[i]);
	}

	shitOffsets = (int*)malloc(dataOffsets[2] - dataOffsets[1]);

	fseek(desfile, 0xD0, SEEK_SET);
	fread(classShit, 1, classNameSectionSize, desfile);

	fseek(desfile, classNameSectionSize + 0xD0, SEEK_SET);

	hkRootLevelContainer_550 rootContainer;
	hkaAnimationContainer_550 animContainer;

	const char* namedVariant1Name = "Scene Data";
	const char* namedVariant1ClassName = "hkxScene";
	const char* namedVariant2Name = "Animation Container";
	const char* namedVariant2ClassName = "hkaAnimationContainer";

	fread(&rootContainer, sizeof(rootContainer), 1, desfile);
	flipEndianRootContainer(&rootContainer);
	if (checkRootContainer(&rootContainer))
	{
		//fclose(desfile);
		return;
	}

	//we expect this to be the same on ALL files
	fseek(desfile, 0x80, SEEK_CUR);
	//if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	hkxScene_550 scene;

	char sceneAssetName[320];
	char sceneModellerName[320];

	fread(&scene, sizeof(scene), 1, desfile);
	flipEndianScene(&scene);

	if (checkScene(&scene))
	{
		if (shitOffsets)
			free(shitOffsets);
		//fclose(desfile);
		return;
	}

	char read;
	char* tempSceneAssetName = sceneAssetName;
	char* tempSceneModellerName = sceneModellerName;

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneModellerName = read;
		fread(&read, 1, 1, desfile);
		tempSceneModellerName++;
	}

	*tempSceneModellerName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneAssetName = read;
		fread(&read, 1, 1, desfile);
		tempSceneAssetName++;
	}

	*tempSceneAssetName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	fread(&animContainer, sizeof(animContainer), 1, desfile);
	flipEndianAnimContainer(&animContainer);

	if (checkAnimContainer(&animContainer))
	{
		if (shitOffsets)
			free(shitOffsets);
		//fclose(desfile);
		return;
	}

	//skip over array
	fseek(desfile, 0x20, SEEK_CUR);

	//hkaWaveletSkeletalAnimation_550 waveletAnim;
	//hkaInterleavedSkeletalAnimation_550 interleavedAnim;
	hkaDeltaCompressedSkeletalAnimation_450 deltaCompressedAnim;
	hkaDeltaCompressedSkeletalAnimation_550 deltaCompressedAnimNew;
	hkaWaveletSkeletalAnimation_450 waveletAnim;
	hkaWaveletSkeletalAnimation_550 waveletAnimNew;

	hkaAnnotationTrack* annotationTracks = NULL;
	char* dataBuffer = NULL;
	QsTransform* transforms = NULL;
	int numAnnotationTracks = 0;

	if (classNameSectionSize == 0x3C0)
	{
		fread(&deltaCompressedAnim, sizeof(deltaCompressedAnim), 1, desfile);
		flipEndianDeltaCompressedSkeletalAnim450(&deltaCompressedAnim);

		hkaDeltaCompressedSkeletalAnimation_450to550(&deltaCompressedAnimNew, &deltaCompressedAnim);

		//skip over annotation track array
		fseek(desfile, deltaCompressedAnim.numAnnotationTracks * 4, SEEK_CUR);
		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

		dataBuffer = (char*)malloc(deltaCompressedAnimNew.numDataBuffer);

		fread(dataBuffer, 1, deltaCompressedAnimNew.numDataBuffer, desfile);

		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

		numAnnotationTracks = deltaCompressedAnim.numAnnotationTracks;

		annotationTracks = (hkaAnnotationTrack*)malloc(sizeof(hkaAnnotationTrack) * numAnnotationTracks);

	}
	else if (classNameSectionSize == 0x3B0) {
		fread(&waveletAnim, sizeof(waveletAnim), 1, desfile);
		flipEndianWaveletSkeletalAnim450(&waveletAnim);

		hkaWaveletSkeletalAnimation_450to550(&waveletAnimNew, &waveletAnim);

		//skip over annotation track array
		fseek(desfile, waveletAnim.numAnnotationTracks * 4, SEEK_CUR);
		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

		dataBuffer = (char*)malloc(waveletAnimNew.numDataBuffer);

		fread(dataBuffer, 1, waveletAnimNew.numDataBuffer, desfile);

		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

		numAnnotationTracks = waveletAnim.numAnnotationTracks;

		annotationTracks = (hkaAnnotationTrack*)malloc(sizeof(hkaAnnotationTrack) * numAnnotationTracks);
	}
	else {
		if (shitOffsets)
			free(shitOffsets);
		printf("ERROR: Unhandled classNameSectionSize == %x", classNameSectionSize);
		return;
	}

	hkaDefaultAnimatedReferenceFrame_550 refFrame;

	fread(&refFrame, sizeof(refFrame), 1, desfile);
	flipEndianReferenceFrame(&refFrame);

	Vector4* refFrameSamples = 0;

	if (refFrame.numReferenceFrameSamples)
	{
		refFrameSamples = (Vector4*)malloc(sizeof(Vector4) * refFrame.numReferenceFrameSamples);
		fread(refFrameSamples, sizeof(Vector4), refFrame.numReferenceFrameSamples, desfile);

		for (int i = 0; i < refFrame.numReferenceFrameSamples; i++)
		{
			refFrameSamples[i].x = _byteswap_ulong(refFrameSamples[i].x);
			refFrameSamples[i].y = _byteswap_ulong(refFrameSamples[i].y);
			refFrameSamples[i].z = _byteswap_ulong(refFrameSamples[i].z);
			refFrameSamples[i].w = _byteswap_ulong(refFrameSamples[i].w);
		}
	}

	char annotationTrackNames[200][16];
	char annotationNames[200][16];

	int currAnnotationIdx = 0;

	for (int i = 0; i < numAnnotationTracks; i++)
	{
		fread(&annotationTracks[i], sizeof(hkaAnnotationTrack), 1, desfile);
		fread(annotationTrackNames[i], 1, 16, desfile);

		annotationTracks[i].numAnnotations = _byteswap_ulong(annotationTracks[i].numAnnotations);

		for (int j = 0; j < annotationTracks[i].numAnnotations; j++)
		{
			//ignore time or w/e
			fseek(desfile, 16, SEEK_CUR);
			fread(annotationNames[currAnnotationIdx], 1, 16, desfile);
			currAnnotationIdx++;
		}
	}

	hkAnimationBinding_450 binding;
	hkaAnimationBinding_550 bindingNew;

	fread(&binding, sizeof(binding), 1, desfile);
	flipEndianAnimBinding450(&binding);

	hkaAnimationBinding_450to550(&bindingNew, &binding);
	if (checkAnimBinding(&bindingNew))
	{
		if (dataBuffer)
			free(dataBuffer);
		if (transforms)
			free(transforms);
		if (refFrameSamples)
			free(refFrameSamples);
		if (annotationTracks)
			free(annotationTracks);
		fclose(desfile);
		return;
	}

	short* animationTrackToBoneIndices = 0;

	if (binding.numAnimationTrackToBoneIndices)
	{
		animationTrackToBoneIndices = (short*)malloc(2 * binding.numAnimationTrackToBoneIndices);
		fread(animationTrackToBoneIndices, 2, binding.numAnimationTrackToBoneIndices, desfile);

		for (int i = 0; i < binding.numAnimationTrackToBoneIndices; i++)
		{
			animationTrackToBoneIndices[i] = _byteswap_ushort(animationTrackToBoneIndices[i]);
		}
	}

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	//fread(shitOffsets, 1, dataOffsets[2] - dataOffsets[1], desfile);
	//fread(dataSectionOffsets, 4, 284, desfile);
	//fread(classNameOffsets, 4, 276, desfile);

	////swap endian on offsets
	//for (int i = 0; i < (dataOffsets[2] - dataOffsets[1]) / 4; i++)
	//{
	//	shitOffsets[i] = _byteswap_ulong(shitOffsets[i]);
	//}

	//for (int i = 0; i < 284; i++)
	//{
	//	dataSectionOffsets[i] = _byteswap_ulong(dataSectionOffsets[i]);
	//}

	//for (int i = 0; i < 276; i++)
	//{
	//	classNameOffsets[i] = _byteswap_ulong(classNameOffsets[i]);
	//}

	printf("finished reading\n");

	//READING FINISHED

	//START WRITING

	classNameSectionSize += 0x20;

	char le_filename[256];
	char* shortened_path;

	shortened_path = strrchr(filename, '\\');

	if (shortened_path) {
		sprintf(le_filename, "le/%s", shortened_path);
	}
	else {
		sprintf(le_filename, "le/%s", filename);
	}

	_mkdir("le");

	FILE* output = fopen(le_filename, "wb");

	int out = 0x57e0e057;

	fwrite(&out, 4, 1, output);

	out = 0x10c0c010;

	fwrite(&out, 4, 1, output);

	fseek(output, 4, SEEK_CUR);

	out = 5;

	fwrite(&out, 4, 1, output);

	out = 0x1000104;

	fwrite(&out, 4, 1, output);

	out = 3;

	fwrite(&out, 4, 1, output);

	out = 2;

	fwrite(&out, 4, 1, output);

	fseek(output, 8, SEEK_CUR);

	if (classNameSectionSize == 0x3E0)
	{
		out = 0x202;
	}
	else {
		out = 0x1C7;
	}

	fwrite(&out, 4, 1, output);

	const char* havokVersion = "Havok-5.5.0-r1";

	fwrite(havokVersion, 1, 15, output);

	short pad = 0xffff;
	int pad2 = 0xffffffff;

	fwrite(&pad, 1, 1, output);
	fwrite(&pad2, 4, 1, output);
	fwrite(&pad2, 4, 1, output);

	const char* classNames = "__classnames__";
	const char* types = "__types__";
	const char* data = "__data__";

	fwrite(classNames, 1, 15, output);
	fseek(output, 4, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0;

	fwrite(&out, 4, 1, output);

	out = classNameSectionSize;

	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);

	fwrite(types, 1, 10, output);
	fseek(output, 9, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0 + classNameSectionSize;

	fwrite(&out, 4, 1, output);

	fseek(output, 0x18, SEEK_CUR);

	fwrite(data, 1, 9, output);

	fseek(output, 10, SEEK_CUR);

	fwrite(&pad, 1, 1, output);

	fwrite(dataOffsets, 4, 7, output);

	int hash = 0x38771F8E;
	char pado = 9;

	char classString[128];

	strcpy(classString, "hkClass");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA5240F57;
	strcpy(classString, "hkClassMember");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8A3609CF;
	strcpy(classString, "hkClassEnum");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCE6F8A6C;
	strcpy(classString, "hkClassEnumItem");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x731888CA;
	strcpy(classString, "hkaAnnotationTrackAnnotation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF2EC0C9C;
	strcpy(classString, "hkxMaterial");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1C8A8C37;
	strcpy(classString, "hkxIndexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF64B134C;
	strcpy(classString, "hkxTextureInplace");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA74011F0;
	strcpy(classString, "hkaBone");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x912C8863;
	strcpy(classString, "hkxMeshSection");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x0217EF77;
	strcpy(classString, "hkxTextureFile");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3E0)
	{
		hash = 0x724A7561;
		strcpy(classString, "hkaDeltaCompressedSkeletalAnimationQuantizationFormat");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x334DBE6C;
	strcpy(classString, "hkaSkeleton");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x379FD194;
	strcpy(classString, "hkxVertexFormat");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xC532C710;
	strcpy(classString, "hkxSkinBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x4DA6A6F4;
	strcpy(classString, "hkaMeshBindingMapping");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1FB22361;
	strcpy(classString, "hkxScene");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCDB31E0C;
	strcpy(classString, "hkaMeshBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x3B1C1113;
	strcpy(classString, "hkReferencedObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF456626D;
	strcpy(classString, "hkaAnimationContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x846FC690;
	strcpy(classString, "hkaAnnotationTrack");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xFB496074;
	strcpy(classString, "hkaAnimationBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8E92A993;
	strcpy(classString, "hkxLight");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF598A34E;
	strcpy(classString, "hkRootLevelContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xDA8C7D7D;
	strcpy(classString, "hkaAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x64E9A03C;
	strcpy(classString, "hkxMeshUserChannelInfo");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x914DA6C1;
	strcpy(classString, "hkxAttribute");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x98F9313D;
	strcpy(classString, "hkaSkeletalAnimation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x158BEA87;
	strcpy(classString, "hkxNodeSelectionSet");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x521E9517;
	strcpy(classString, "hkxNodeAnnotationData");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE0708A00;
	strcpy(classString, "hkBaseObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x445A443A;
	strcpy(classString, "hkxAttributeHolder");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xD5C65FAE;
	strcpy(classString, "hkxCamera");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3D0)
	{
		hash = 0x724A7561;
		strcpy(classString, "hkaWaveletSkeletalAnimationQuantizationFormat");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0xE085BA9F;
	strcpy(classString, "hkxMaterialTextureStage");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x72E8E849;
	strcpy(classString, "hkxMesh");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8BDD3E9A;
	strcpy(classString, "hkaBoneAttachment");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3D0)
	{
		hash = 0x5974FFE8;
		strcpy(classString, "hkaWaveletSkeletalAnimation");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x122F506B;
	strcpy(classString, "hkaDefaultAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x853A899C;
	strcpy(classString, "hkRootLevelContainerNamedVariant");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	if (classNameSectionSize == 0x3E0)
	{
		hash = 0x83C6794C;
		strcpy(classString, "hkaDeltaCompressedSkeletalAnimation");
		fwrite(&hash, 4, 1, output);
		fwrite(&pado, 1, 1, output);
		fprintf(output, classString);
		fseek(output, 1, SEEK_CUR);
	}

	hash = 0x06AF1B5A;
	strcpy(classString, "hkxNode");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1667C01C;
	strcpy(classString, "hkxAttributeGroup");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x57061454;
	strcpy(classString, "hkxVertexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	fwrite(&pad2, 1, 1, output);
	fwrite(&pad2, 1, 1, output);
	fwrite(&pad2, 4, 1, output);

	//fwrite(classShit, 1, 976, output);

	fwrite(&rootContainer, sizeof(hkRootLevelContainer_550), 1, output);
	fseek(output, 0x20, SEEK_CUR);

	fprintf(output, namedVariant2Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant1Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant1ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(&animContainer, sizeof(animContainer), 1, output);

	fseek(output, 0x20, SEEK_CUR);
	
	if (classNameSectionSize == 0x3E0)
	{
		fwrite(&deltaCompressedAnimNew, sizeof(deltaCompressedAnimNew), 1, output);
		fwrite(dataBuffer, 1, deltaCompressedAnimNew.numDataBuffer, output);
	}
	else {
		fwrite(&waveletAnimNew, sizeof(waveletAnimNew), 1, output);
		fwrite(dataBuffer, 1, waveletAnimNew.numDataBuffer, output);
	}

	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	offsetRefFrame = ftell(output) - classNameSectionSize - 0xD0;
	offsetRefFrameFrameSamples = offsetRefFrame + 0x34;

	fwrite(&refFrame, sizeof(refFrame), 1, output);

	offsetRefFrameFrameSamplesData = ftell(output) - classNameSectionSize - 0xD0;

	if (refFrame.numReferenceFrameSamples)
		fwrite(refFrameSamples, sizeof(Vector4), refFrame.numReferenceFrameSamples, output);

	offsetAnimBindingAnimation = ftell(output) -classNameSectionSize - 0xD0;
	offsetAnimBindingtransformTrackToBoneIndices = offsetAnimBindingAnimation + 4;

	fwrite(&bindingNew, sizeof(bindingNew), 1, output);

	offsetAnimBindingtransformTrackToBoneIndicesData = ftell(output) - classNameSectionSize - 0xD0;

	if (bindingNew.numTransformTrackToBoneIndices)
	{
		fwrite(animationTrackToBoneIndices, 2, bindingNew.numTransformTrackToBoneIndices, output);
		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}

	offsetHkxSceneModeller = ftell(output) - classNameSectionSize - 0xD0;
	offsetHkxSceneAsset = offsetHkxSceneModeller + 4;

	fwrite(&scene, sizeof(scene), 1, output);

	offsetHkxSceneModellerData = ftell(output) - classNameSectionSize - 0xD0;

	fprintf(output, sceneModellerName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	offsetHkxSceneAssetData = ftell(output) - classNameSectionSize - 0xD0;

	fprintf(output, sceneAssetName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	offsetOffsetSection = ftell(output) - classNameSectionSize - 0xD0;

	int value = 0;

	fwrite(&value, 4, 1, output);
	value = 0x10;
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	value = 0x30;
	fwrite(&value, 4, 1, output);
	value = 0x14;
	fwrite(&value, 4, 1, output);
	value = 0x50;
	fwrite(&value, 4, 1, output);
	value = 0x20;
	fwrite(&value, 4, 1, output);
	value = 0x70;
	fwrite(&value, 4, 1, output);
	value = 0x24;
	fwrite(&value, 4, 1, output);
	value = 0x80;
	fwrite(&value, 4, 1, output);
	value = 0x98;
	fwrite(&value, 4, 1, output);
	value = 0xC0;
	fwrite(&value, 4, 1, output);
	value = 0xA0;
	fwrite(&value, 4, 1, output);
	value = 0xD0;
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x140;
	}
	else {
		value = 0x138;
	}
	
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x150;
	}
	else {
		value = 0x140;
	}

	fwrite(&value, 4, 1, output);
	fwrite(&offsetRefFrameFrameSamples, 4, 1, output);
	fwrite(&offsetRefFrameFrameSamplesData, 4, 1, output);
	fwrite(&offsetAnimBindingtransformTrackToBoneIndices, 4, 1, output);
	fwrite(&offsetAnimBindingtransformTrackToBoneIndicesData, 4, 1, output);
	fwrite(&offsetHkxSceneModeller, 4, 1, output);
	fwrite(&offsetHkxSceneModellerData, 4, 1, output);
	fwrite(&offsetHkxSceneAsset, 4, 1, output);
	fwrite(&offsetHkxSceneAssetData, 4, 1, output);
	value = 0x18;
	fwrite(&value, 4, 1, output);
	value = 2;
	fwrite(&value, 4, 1, output);
	value = 0x90;
	fwrite(&value, 4, 1, output);
	value = 0x28;
	fwrite(&value, 4, 1, output);
	value = 2;
	fwrite(&value, 4, 1, output);
	fwrite(&offsetHkxSceneModeller, 4, 1, output);
	value = 0xC0;
	fwrite(&value, 4, 1, output);
	value = 2;
	fwrite(&value, 4, 1, output);
	value = 0xE0;
	fwrite(&value, 4, 1, output);
	value = 0xD0;
	fwrite(&value, 4, 1, output);
	value = 2;
	fwrite(&value, 4, 1, output);
	fwrite(&offsetAnimBindingAnimation, 4, 1, output);
	value = 0xF8;
	fwrite(&value, 4, 1, output);
	value = 2;
	fwrite(&value, 4, 1, output);
	fwrite(&offsetRefFrame, 4, 1, output);
	fwrite(&offsetAnimBindingAnimation, 4, 1, output);
	fwrite(&value, 4, 1, output);
	value = 0xE0;
	fwrite(&value, 4, 1, output);
	value = 0xFFFFFFFF;
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x202;
	}
	else {
		value = 0x1C7;
	}

	fwrite(&value, 4, 1, output);
	value = 0x90;
	fwrite(&value, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x1A8;
	}
	else {
		value = 0x16D;
	}

	fwrite(&value, 4, 1, output);
	value = 0xE0;
	fwrite(&value, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);
	
	if (classNameSectionSize == 0x3E0)
	{
		value = 0x37D;
	}
	else {
		value = 0x329;
	}
	
	fwrite(&value, 4, 1, output);
	fwrite(&offsetRefFrame, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x331;
	}
	else {
		value = 0x34A;
	}
	
	fwrite(&value, 4, 1, output);
	fwrite(&offsetAnimBindingAnimation, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x1DB;
	}
	else {
		value = 0x1A0;
	}

	fwrite(&value, 4, 1, output);
	fwrite(&offsetHkxSceneModeller, 4, 1, output);
	value = 0;
	fwrite(&value, 4, 1, output);

	if (classNameSectionSize == 0x3E0)
	{
		value = 0x16E;
	}
	else {
		value = 0x133;
	}

	fwrite(&value, 4, 1, output);
	value = 0xFFFFFFFF;
	fwrite(&value, 4, 1, output);
	fwrite(&value, 4, 1, output);
	/*int offsetRefFrameFrameSamples = 0;
	int offsetRefFrameFrameSamplesData = 0;
	int offsetAnimBindingtransformTrackToBoneIndices = 0;
	int offsetAnimBindingtransformTrackToBoneIndicesData = 0;
	int offsetHkxSceneModeller = 0;
	int offsetHkxSceneModellerData = 0;
	int offsetHkxSceneAsset = 0;
	int offsetHkxSceneAssetData = 0;
	int offsetAnimBindingAnimation = 0;
	int offsetRefFrame = 0;*/

	//fwrite(dataSectionOffsets, 4, 48, output);
	//fwrite(classNameOffsets, 4, 20, output);

	//fix offsets
	fseek(output, 0xB4, SEEK_SET);

	dataOffsets[0] = 0xD0 + classNameSectionSize;
	dataOffsets[1] = offsetOffsetSection;
	dataOffsets[2] = offsetOffsetSection + 0x60;
	dataOffsets[3] = offsetOffsetSection + 0xC0;
	dataOffsets[4] = offsetOffsetSection + 0x110;
	dataOffsets[5] = offsetOffsetSection + 0x110;
	dataOffsets[6] = offsetOffsetSection + 0x110;

	fwrite(dataOffsets, 4, 7, output);

	if (shitOffsets)
		free(shitOffsets);
	if (dataBuffer)
		free(dataBuffer);
	if (animationTrackToBoneIndices)
		free(animationTrackToBoneIndices);
	if (transforms)
		free(transforms);
	if (refFrameSamples)
		free(refFrameSamples);
	fclose(output);

	printf("finished writing\n");

}

void convertSkeleton(FILE* desfile, char* filename)
{
	int offsetDataSection = 0;
	int dataOffsets[7];
	int* offsetsBones = NULL;

	int offsetBonePointers = 0;
	int offsetScene = 0;

	vector<pair<int, int>> arrayOffsets;
	vector<tuple<int, int, int>> ptrOffsets;
	vector<tuple<int, int, int>> classOffsets;

	fseek(desfile, 0xB4, SEEK_SET);
	fread(dataOffsets, 4, 7, desfile);
	offsetDataSection = _byteswap_ulong(dataOffsets[0]);

	fseek(desfile, 0xD0, SEEK_SET);
	//fread(classShit, 1, classNameSectionSize, desfile);

	fseek(desfile, offsetDataSection, SEEK_SET);

	hkRootLevelContainer_550 rootContainer;
	hkaAnimationContainer_550 animContainer;

	arrayOffsets.push_back(make_pair(0, 0x10));
	arrayOffsets.push_back(make_pair(0x10, 0x30));
	arrayOffsets.push_back(make_pair(0x14, 0x50));
	arrayOffsets.push_back(make_pair(0x20, 0x70));
	arrayOffsets.push_back(make_pair(0x24, 0x80));
	arrayOffsets.push_back(make_pair(0x90, 0xC0));
	arrayOffsets.push_back(make_pair(0xD0, 0x100));
	arrayOffsets.push_back(make_pair(0xD4, 0x110));

	ptrOffsets.push_back(make_tuple(0x18, 2, 0x90));

	classOffsets.push_back(make_tuple(0, 0, 0x1C7));

	const char* namedVariant1Name = "Merged Animation Container";
	const char* namedVariant1ClassName = "hkaAnimationContainer";
	const char* namedVariant2Name = "Scene Data";
	const char* namedVariant2ClassName = "hkxScene";

	fread(&rootContainer, sizeof(rootContainer), 1, desfile);
	flipEndianRootContainer(&rootContainer);

	if (checkRootContainer(&rootContainer))
	{
		fclose(desfile);
		return;
	}

	//we expect this to be the same on ALL files
	fseek(desfile, 0x80, SEEK_CUR);

	fread(&animContainer, sizeof(animContainer), 1, desfile);
	flipEndianAnimContainer(&animContainer);

	classOffsets.push_back(make_tuple(0x90, 0, 0x155));

	/*if (checkAnimContainer(&animContainer))
	{
		fclose(desfile);
		return 1;
	}*/

	hkaSkeleton_550 skeleton;
	QsTransform* referencePose = NULL;
	hkaBone* bones = NULL;

	//skip array
	fseek(desfile, 0x10, SEEK_CUR);

	fread(&skeleton, sizeof(skeleton), 1, desfile);
	flipEndianSkeleton(&skeleton);

	classOffsets.push_back(make_tuple(0xD0, 0, 0xDE));

	char skeletonName[16];

	fread(skeletonName, 1, 16, desfile);

	short* parentIndices = 0;
	parentIndices = (short*)malloc(2 * skeleton.numParentIndices);
	fread(parentIndices, 2, skeleton.numParentIndices, desfile);
	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	for (int i = 0; i < skeleton.numParentIndices; i++)
	{
		parentIndices[i] = _byteswap_ushort(parentIndices[i]);
	}


	arrayOffsets.push_back(make_pair(0xDC, ftell(desfile) - offsetDataSection));
	offsetBonePointers = ftell(desfile) - offsetDataSection;

	//skip bone array
	fseek(desfile, 4 * skeleton.numBones, SEEK_CUR);
	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	arrayOffsets.push_back(make_pair(0xE4, ftell(desfile) - offsetDataSection));

	referencePose = (QsTransform*)malloc(sizeof(QsTransform) * skeleton.numReferencePose);

	fread(referencePose, sizeof(QsTransform), skeleton.numReferencePose, desfile);

	for (int i = 0; i < skeleton.numReferencePose; i++)
	{
		flipEndianQsTranform(&referencePose[i]);
	}

	bones = (hkaBone*)malloc(sizeof(hkaBone) * skeleton.numBones);
	offsetsBones = (int*)malloc(4 * skeleton.numBones);

	char currChar = 0;

	//I limit bone names to 32 chars.............
	for (int i = 0; i < skeleton.numBones; i++)
	{
		hkaBone bone;
		bone.pName = 0;
		bone.pad = 0;
		bone.pad1 = 0;

		offsetsBones[i] = ftell(desfile) - offsetDataSection;
		arrayOffsets.push_back(make_pair(ftell(desfile) - offsetDataSection, ftell(desfile) - offsetDataSection + 0x10));
		classOffsets.push_back(make_tuple(ftell(desfile) - offsetDataSection, 0, 0xA9));

		fseek(desfile, 4, SEEK_CUR);
		fread(&bone.lockTranslation, 4, 1, desfile);
		fseek(desfile, 8, SEEK_CUR);

		int idx = 0;
		
		do {
			fread(&currChar, 1, 1, desfile);

			if (idx == 31)
				break;

			bone.name[idx] = currChar;
			idx++;
		} while (currChar);

		bone.name[idx] = 0;

		bones[i] = bone;

		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);
	}

	hkxScene_550 scene;

	char sceneAssetName[320];
	char sceneModellerName[320];

	offsetScene = ftell(desfile) - offsetDataSection;
	ptrOffsets.push_back(make_tuple(0x28, 2, offsetScene));
	ptrOffsets.push_back(make_tuple(0xC0, 2, 0xD0));
	classOffsets.push_back(make_tuple(offsetScene, 0, 0x133));

	fread(&scene, sizeof(scene), 1, desfile);
	flipEndianScene(&scene);

	if (checkScene(&scene))
	{
		if (parentIndices)
			free(parentIndices);
		if (bones)
			free(bones);
		return;
	}

	char read;
	char* tempSceneAssetName = sceneAssetName;
	char* tempSceneModellerName = sceneModellerName;

	arrayOffsets.push_back(make_pair(offsetScene, ftell(desfile) - offsetDataSection));

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneModellerName = read;
		fread(&read, 1, 1, desfile);
		tempSceneModellerName++;
	}

	*tempSceneModellerName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	arrayOffsets.push_back(make_pair(offsetScene + 4, ftell(desfile) - offsetDataSection));

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneAssetName = read;
		fread(&read, 1, 1, desfile);
		tempSceneAssetName++;
	}

	*tempSceneAssetName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	int* offsetBlob = NULL;

	for (int i = 0; i < 7; i++)
	{
		dataOffsets[i] = _byteswap_ulong(dataOffsets[i]);
	}

	dataOffsets[0] = 0x420;

	int numOffsetBlob = (dataOffsets[6] - dataOffsets[1]) / 4;

	offsetBlob = (int*)malloc(numOffsetBlob * 4);

	fread(offsetBlob, 4, numOffsetBlob, desfile);

	for (int i = 0; i < numOffsetBlob; i++)
	{
		offsetBlob[i] = _byteswap_ulong(offsetBlob[i]);
	}

	if (arrayOffsets.size() % 2)
	{
		arrayOffsets.push_back(make_pair(-1, -1));
	}

	printf("finished reading\n");

	//READING FINISHED

	//WRITING STARTED

	char le_filename[256];
	char* shortened_path;

	shortened_path = strrchr(filename, '\\');

	if (shortened_path) {
		sprintf(le_filename, "le/%s", shortened_path);
	}
	else {
		sprintf(le_filename, "le/%s", filename);
	}

	_mkdir("le");

	FILE* output = fopen(le_filename, "wb");

	int out = 0x57e0e057;

	fwrite(&out, 4, 1, output);

	out = 0x10c0c010;

	fwrite(&out, 4, 1, output);

	fseek(output, 4, SEEK_CUR);

	out = 5;

	fwrite(&out, 4, 1, output);

	out = 0x1000104;

	fwrite(&out, 4, 1, output);

	out = 3;

	fwrite(&out, 4, 1, output);

	out = 2;

	fwrite(&out, 4, 1, output);

	fseek(output, 8, SEEK_CUR);

	out = 0x1C7;

	fwrite(&out, 4, 1, output);

	const char* havokVersion = "Havok-5.5.0-r1";

	fwrite(havokVersion, 1, 15, output);

	short pad = 0xffff;
	int pad2 = 0xffffffff;

	fwrite(&pad, 1, 1, output);
	fwrite(&pad2, 4, 1, output);
	fwrite(&pad2, 4, 1, output);

	const char* classNames = "__classnames__";
	const char* types = "__types__";
	const char* data = "__data__";

	fwrite(classNames, 1, 15, output);
	fseek(output, 4, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0;

	fwrite(&out, 4, 1, output);

	out = 0x350;

	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);

	fwrite(types, 1, 10, output);
	fseek(output, 9, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0x420;

	fwrite(&out, 4, 1, output);

	fseek(output, 0x18, SEEK_CUR);

	fwrite(data, 1, 9, output);

	fseek(output, 10, SEEK_CUR);

	fwrite(&pad, 1, 1, output);

	fwrite(dataOffsets, 4, 7, output);

	int hash = 0x38771F8E;
	char pado = 9;

	char classString[128];

	strcpy(classString, "hkClass");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA5240F57;
	strcpy(classString, "hkClassMember");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8A3609CF;
	strcpy(classString, "hkClassEnum");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCE6F8A6C;
	strcpy(classString, "hkClassEnumItem");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x731888CA;
	strcpy(classString, "hkaAnnotationTrackAnnotation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF2EC0C9C;
	strcpy(classString, "hkxMaterial");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1C8A8C37;
	strcpy(classString, "hkxIndexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF64B134C;
	strcpy(classString, "hkxTextureInplace");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA74011F0;
	strcpy(classString, "hkaBone");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x912C8863;
	strcpy(classString, "hkxMeshSection");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x0217EF77;
	strcpy(classString, "hkxTextureFile");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x334DBE6C;
	strcpy(classString, "hkaSkeleton");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x379FD194;
	strcpy(classString, "hkxVertexFormat");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xC532C710;
	strcpy(classString, "hkxSkinBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x4DA6A6F4;
	strcpy(classString, "hkaMeshBindingMapping");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1FB22361;
	strcpy(classString, "hkxScene");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCDB31E0C;
	strcpy(classString, "hkaMeshBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF456626D;
	strcpy(classString, "hkaAnimationContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x3B1C1113;
	strcpy(classString, "hkReferencedObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x846FC690;
	strcpy(classString, "hkaAnnotationTrack");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xFB496074;
	strcpy(classString, "hkaAnimationBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8E92A993;
	strcpy(classString, "hkxLight");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF598A34E;
	strcpy(classString, "hkRootLevelContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xDA8C7D7D;
	strcpy(classString, "hkaAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x64E9A03C;
	strcpy(classString, "hkxMeshUserChannelInfo");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x914DA6C1;
	strcpy(classString, "hkxAttribute");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x98F9313D;
	strcpy(classString, "hkaSkeletalAnimation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x158BEA87;
	strcpy(classString, "hkxNodeSelectionSet");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x521E9517;
	strcpy(classString, "hkxNodeAnnotationData");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE0708A00;
	strcpy(classString, "hkBaseObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x445A443A;
	strcpy(classString, "hkxAttributeHolder");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xD5C65FAE;
	strcpy(classString, "hkxCamera");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE085BA9F;
	strcpy(classString, "hkxMaterialTextureStage");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x72E8E849;
	strcpy(classString, "hkxMesh");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8BDD3E9A;
	strcpy(classString, "hkaBoneAttachment");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x853A899C;
	strcpy(classString, "hkRootLevelContainerNamedVariant");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x06AF1B5A;
	strcpy(classString, "hkxNode");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1667C01C;
	strcpy(classString, "hkxAttributeGroup");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x57061454;
	strcpy(classString, "hkxVertexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	//fwrite(classShit, 1, 976, output);

	fwrite(&rootContainer, sizeof(hkRootLevelContainer_550), 1, output);
	fseek(output, 0x20, SEEK_CUR);

	fprintf(output, namedVariant1Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant1ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(&animContainer, sizeof(animContainer), 1, output);

	fseek(output, 0x10, SEEK_CUR);

	fwrite(&skeleton, sizeof(skeleton), 1, output);

	fwrite(skeletonName, 1, 16, output);

	fwrite(parentIndices, 2, skeleton.numParentIndices, output);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	//skip bone array
	fseek(output, 4 * skeleton.numBones, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(referencePose, sizeof(QsTransform), skeleton.numReferencePose, output);

	for (int i = 0; i < skeleton.numBones; i++)
	{
		ptrOffsets.push_back(make_tuple(offsetBonePointers + i * 4, 2, offsetsBones[i]));

		fwrite(&bones[i].pName, 4, 1, output);
		fwrite(&bones[i].lockTranslation, 4, 1, output);
		fwrite(&bones[i].pad, 4, 1, output);
		fwrite(&bones[i].pad1, 4, 1, output);
		fputs(bones[i].name, output);
		fseek(output, 1, SEEK_CUR);

		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}

	fwrite(&scene, sizeof(scene), 1, output);

	fprintf(output, sceneModellerName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, sceneAssetName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	dataOffsets[1] = ftell(output) - 0x420;

	fwrite(arrayOffsets.data(), 8, arrayOffsets.size(), output);

	dataOffsets[2] = ftell(output) - 0x420;

	for (int i = 0; i < ptrOffsets.size(); i++)
	{
		fwrite(&get<0>(ptrOffsets.data()[i]), 4, 1, output);
		fwrite(&get<1>(ptrOffsets.data()[i]), 4, 1, output);
		fwrite(&get<2>(ptrOffsets.data()[i]), 4, 1, output);
	}

	int pos = ftell(output);

	if (int gap = pos % 16)
	{
		char pad = 0xFF;
		for (int i = 0; i < 16 - gap; i++)
		{
			fwrite(&pad, 1, 1, output);
		}
	}

	dataOffsets[3] = ftell(output) - 0x420;

	for (int i = 0; i < classOffsets.size(); i++)
	{
		fwrite(&get<0>(classOffsets.data()[i]), 4, 1, output);
		fwrite(&get<1>(classOffsets.data()[i]), 4, 1, output);
		fwrite(&get<2>(classOffsets.data()[i]), 4, 1, output);
	}

	//fwrite(classOffsets.data(), 4, classOffsets.size() * 3, output);

	pos = ftell(output);

	if (int gap = pos % 16)
	{
		char pad = 0xFF;
		for (int i = 0; i < 16 - gap; i++)
		{
			fwrite(&pad, 1, 1, output);
		}
	}

	dataOffsets[4] = ftell(output) - 0x420;
	dataOffsets[5] = dataOffsets[4];
	dataOffsets[6] = dataOffsets[4];

	//fwrite(offsetBlob, 4, numOffsetBlob, output);

	fseek(output, 0xB4, SEEK_SET);
	fwrite(dataOffsets, 4, 7, output);

	printf("finished writing\n");

	if (offsetsBones)
		free(offsetsBones);
	if (referencePose)
		free(referencePose);
	if (parentIndices)
		free(parentIndices);
	if (bones)
		free(bones);
	if (offsetBlob)
		free(offsetBlob);
	fclose(output);
}

void convertHavok4Skeleton(FILE* desfile, char* filename)
{
	int offsetDataSection = 0;
	int dataOffsets[7];
	int* offsetsBones = NULL;

	int offsetBonePointers = 0;
	int offsetScene = 0;
	int offsetTransforms = 0;

	vector<pair<int, int>> arrayOffsets;
	vector<tuple<int, int, int>> ptrOffsets;
	vector<tuple<int, int, int>> classOffsets;

	fseek(desfile, 0x84, SEEK_SET);
	fread(dataOffsets, 4, 7, desfile);
	offsetDataSection = _byteswap_ulong(dataOffsets[0]);

	//fseek(desfile, 0xD0, SEEK_SET);
	//fread(classShit, 1, classNameSectionSize, desfile);

	fseek(desfile, offsetDataSection, SEEK_SET);

	hkRootLevelContainer_550 rootContainer;
	hkaAnimationContainer_550 animContainer;

	arrayOffsets.push_back(make_pair(0, 0x10));
	arrayOffsets.push_back(make_pair(0x10, 0x30));
	arrayOffsets.push_back(make_pair(0x14, 0x50));
	arrayOffsets.push_back(make_pair(0x20, 0x70));
	arrayOffsets.push_back(make_pair(0x24, 0x80));
	arrayOffsets.push_back(make_pair(0x90, 0xC0));
	arrayOffsets.push_back(make_pair(0xD0, 0x100));
	arrayOffsets.push_back(make_pair(0xD4, 0x110));

	ptrOffsets.push_back(make_tuple(0x18, 2, 0x90));

	classOffsets.push_back(make_tuple(0, 0, 0x1C7));

	const char* namedVariant1Name = "Merged Animation Container";
	const char* namedVariant1ClassName = "hkaAnimationContainer";
	const char* namedVariant2Name = "Scene Data";
	const char* namedVariant2ClassName = "hkxScene";

	fread(&rootContainer, sizeof(rootContainer), 1, desfile);
	flipEndianRootContainer(&rootContainer);

	if (checkRootContainer(&rootContainer))
	{
		fclose(desfile);
		return;
	}

	//we expect this to be the same on ALL files
	fseek(desfile, 0x80, SEEK_CUR);

	hkxScene_550 scene;

	char sceneAssetName[320];
	char sceneModellerName[320];

	

	fread(&scene, sizeof(scene), 1, desfile);
	flipEndianScene(&scene);

	if (checkScene(&scene))
	{
		return;
	}

	char read;
	char* tempSceneAssetName = sceneAssetName;
	char* tempSceneModellerName = sceneModellerName;

	

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneModellerName = read;
		fread(&read, 1, 1, desfile);
		tempSceneModellerName++;
	}

	*tempSceneModellerName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	

	fread(&read, 1, 1, desfile);

	while (read)
	{
		*tempSceneAssetName = read;
		fread(&read, 1, 1, desfile);
		tempSceneAssetName++;
	}

	*tempSceneAssetName = read;

	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	fread(&animContainer, sizeof(animContainer), 1, desfile);
	flipEndianAnimContainer(&animContainer);

	

	hkaSkeleton_450 skeletonOld;
	hkaSkeleton_550 skeletonNew;
	QsTransform* referencePose = NULL;
	hkaBone* bones = NULL;

	//skip array
	fseek(desfile, 0x10, SEEK_CUR);

	fread(&skeletonOld, sizeof(skeletonOld), 1, desfile);
	flipEndianSkeleton450(&skeletonOld);
	hkaSkeleton_450to550(&skeletonNew, &skeletonOld);

	

	char skeletonName[16];

	fread(skeletonName, 1, 16, desfile);

	short* parentIndices = 0;
	parentIndices = (short*)malloc(2 * skeletonNew.numParentIndices);
	fread(parentIndices, 2, skeletonNew.numParentIndices, desfile);
	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	for (int i = 0; i < skeletonNew.numParentIndices; i++)
	{
		parentIndices[i] = _byteswap_ushort(parentIndices[i]);
	}


	

	//skip bone array
	fseek(desfile, 4 * skeletonNew.numBones, SEEK_CUR);
	if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);

	

	referencePose = (QsTransform*)malloc(sizeof(QsTransform) * skeletonNew.numReferencePose);

	fread(referencePose, sizeof(QsTransform), skeletonNew.numReferencePose, desfile);

	for (int i = 0; i < skeletonNew.numReferencePose; i++)
	{
		flipEndianQsTranform(&referencePose[i]);
	}

	bones = (hkaBone*)malloc(sizeof(hkaBone) * skeletonNew.numBones);
	offsetsBones = (int*)malloc(4 * skeletonNew.numBones);

	char currChar = 0;

	//I limit bone names to 32 chars.............
	for (int i = 0; i < skeletonNew.numBones; i++)
	{
		hkaBone bone;
		bone.pName = 0;
		bone.pad = 0;
		bone.pad1 = 0;

		

		fseek(desfile, 4, SEEK_CUR);
		fread(&bone.lockTranslation, 4, 1, desfile);
		fseek(desfile, 8, SEEK_CUR);

		int idx = 0;

		do {
			fread(&currChar, 1, 1, desfile);

			if (idx == 31)
				break;

			bone.name[idx] = currChar;
			idx++;
		} while (currChar);

		bone.name[idx] = 0;

		bones[i] = bone;

		if (ftell(desfile) % 16) fseek(desfile, 16 - ftell(desfile) % 16, SEEK_CUR);
	}

	

	int* offsetBlob = NULL;

	for (int i = 0; i < 7; i++)
	{
		dataOffsets[i] = _byteswap_ulong(dataOffsets[i]);
	}

	dataOffsets[0] = 0x420;

	int numOffsetBlob = (dataOffsets[6] - dataOffsets[1]) / 4;

	offsetBlob = (int*)malloc(numOffsetBlob * 4);

	fread(offsetBlob, 4, numOffsetBlob, desfile);

	for (int i = 0; i < numOffsetBlob; i++)
	{
		offsetBlob[i] = _byteswap_ulong(offsetBlob[i]);
	}

	if (arrayOffsets.size() % 2)
	{
		arrayOffsets.push_back(make_pair(-1, -1));
	}

	printf("finished reading\n");

	//READING FINISHED

	//WRITING STARTED

	char le_filename[256];
	char* shortened_path;

	shortened_path = strrchr(filename, '\\');

	if (shortened_path) {
		sprintf(le_filename, "le/%s", shortened_path);
	}
	else {
		sprintf(le_filename, "le/%s", filename);
	}

	_mkdir("le");

	FILE* output = fopen(le_filename, "wb");

	int out = 0x57e0e057;

	fwrite(&out, 4, 1, output);

	out = 0x10c0c010;

	fwrite(&out, 4, 1, output);

	fseek(output, 4, SEEK_CUR);

	out = 5;

	fwrite(&out, 4, 1, output);

	out = 0x1000104;

	fwrite(&out, 4, 1, output);

	out = 3;

	fwrite(&out, 4, 1, output);

	out = 2;

	fwrite(&out, 4, 1, output);

	fseek(output, 8, SEEK_CUR);

	out = 0x1C7;

	fwrite(&out, 4, 1, output);

	const char* havokVersion = "Havok-5.5.0-r1";

	fwrite(havokVersion, 1, 15, output);

	short pad = 0xffff;
	int pad2 = 0xffffffff;

	fwrite(&pad, 1, 1, output);
	fwrite(&pad2, 4, 1, output);
	fwrite(&pad2, 4, 1, output);

	const char* classNames = "__classnames__";
	const char* types = "__types__";
	const char* data = "__data__";

	fwrite(classNames, 1, 15, output);
	fseek(output, 4, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0xD0;

	fwrite(&out, 4, 1, output);

	out = 0x350;

	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);
	fwrite(&out, 4, 1, output);

	fwrite(types, 1, 10, output);
	fseek(output, 9, SEEK_CUR);
	fwrite(&pad, 1, 1, output);

	out = 0x420;

	fwrite(&out, 4, 1, output);

	fseek(output, 0x18, SEEK_CUR);

	fwrite(data, 1, 9, output);

	fseek(output, 10, SEEK_CUR);

	fwrite(&pad, 1, 1, output);

	fwrite(dataOffsets, 4, 7, output);

	int hash = 0x38771F8E;
	char pado = 9;

	char classString[128];

	strcpy(classString, "hkClass");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA5240F57;
	strcpy(classString, "hkClassMember");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8A3609CF;
	strcpy(classString, "hkClassEnum");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCE6F8A6C;
	strcpy(classString, "hkClassEnumItem");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x731888CA;
	strcpy(classString, "hkaAnnotationTrackAnnotation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF2EC0C9C;
	strcpy(classString, "hkxMaterial");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1C8A8C37;
	strcpy(classString, "hkxIndexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF64B134C;
	strcpy(classString, "hkxTextureInplace");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xA74011F0;
	strcpy(classString, "hkaBone");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x912C8863;
	strcpy(classString, "hkxMeshSection");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x0217EF77;
	strcpy(classString, "hkxTextureFile");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x334DBE6C;
	strcpy(classString, "hkaSkeleton");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x379FD194;
	strcpy(classString, "hkxVertexFormat");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xC532C710;
	strcpy(classString, "hkxSkinBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x4DA6A6F4;
	strcpy(classString, "hkaMeshBindingMapping");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1FB22361;
	strcpy(classString, "hkxScene");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xCDB31E0C;
	strcpy(classString, "hkaMeshBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF456626D;
	strcpy(classString, "hkaAnimationContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x3B1C1113;
	strcpy(classString, "hkReferencedObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x846FC690;
	strcpy(classString, "hkaAnnotationTrack");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xFB496074;
	strcpy(classString, "hkaAnimationBinding");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8E92A993;
	strcpy(classString, "hkxLight");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xF598A34E;
	strcpy(classString, "hkRootLevelContainer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xDA8C7D7D;
	strcpy(classString, "hkaAnimatedReferenceFrame");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x64E9A03C;
	strcpy(classString, "hkxMeshUserChannelInfo");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x914DA6C1;
	strcpy(classString, "hkxAttribute");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x98F9313D;
	strcpy(classString, "hkaSkeletalAnimation");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x158BEA87;
	strcpy(classString, "hkxNodeSelectionSet");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x521E9517;
	strcpy(classString, "hkxNodeAnnotationData");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE0708A00;
	strcpy(classString, "hkBaseObject");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x445A443A;
	strcpy(classString, "hkxAttributeHolder");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xD5C65FAE;
	strcpy(classString, "hkxCamera");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0xE085BA9F;
	strcpy(classString, "hkxMaterialTextureStage");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x72E8E849;
	strcpy(classString, "hkxMesh");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x8BDD3E9A;
	strcpy(classString, "hkaBoneAttachment");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x853A899C;
	strcpy(classString, "hkRootLevelContainerNamedVariant");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x06AF1B5A;
	strcpy(classString, "hkxNode");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x1667C01C;
	strcpy(classString, "hkxAttributeGroup");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	hash = 0x57061454;
	strcpy(classString, "hkxVertexBuffer");
	fwrite(&hash, 4, 1, output);
	fwrite(&pado, 1, 1, output);
	fprintf(output, classString);
	fseek(output, 1, SEEK_CUR);

	//fwrite(classShit, 1, 976, output);

	fwrite(&rootContainer, sizeof(hkRootLevelContainer_550), 1, output);
	fseek(output, 0x20, SEEK_CUR);

	fprintf(output, namedVariant1Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant1ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2Name);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	fprintf(output, namedVariant2ClassName);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	fwrite(&animContainer, sizeof(animContainer), 1, output);

	fseek(output, 0x10, SEEK_CUR);

	fwrite(&skeletonNew, sizeof(skeletonNew), 1, output);

	fwrite(skeletonName, 1, 16, output);

	fwrite(parentIndices, 2, skeletonNew.numParentIndices, output);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	offsetBonePointers = ftell(output) - 0x420;

	//skip bone array
	fseek(output, 4 * skeletonNew.numBones, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	offsetTransforms = ftell(output) - 0x420;

	fwrite(referencePose, sizeof(QsTransform), skeletonNew.numReferencePose, output);

	for (int i = 0; i < skeletonNew.numBones; i++)
	{
		
		offsetsBones[i] = ftell(output) - 0x420;
		fwrite(&bones[i].pName, 4, 1, output);
		fwrite(&bones[i].lockTranslation, 4, 1, output);
		fwrite(&bones[i].pad, 4, 1, output);
		fwrite(&bones[i].pad1, 4, 1, output);
		fputs(bones[i].name, output);
		fseek(output, 1, SEEK_CUR);

		if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);
	}

	offsetScene = ftell(output) - 0x420;
	fwrite(&scene, sizeof(scene), 1, output);

	//arrayOffsets.push_back(make_pair(offsetScene, ftell(output) - 0x420));

	int offsetSceneModellerName = ftell(output) - 0x420;
	fprintf(output, sceneModellerName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	//arrayOffsets.push_back(make_pair(offsetScene + 4, ftell(output) - 0x420));

	int offsetSceneAssetName = ftell(output) - 0x420;
	fprintf(output, sceneAssetName);
	fseek(output, 1, SEEK_CUR);
	if (ftell(output) % 16) fseek(output, 16 - ftell(output) % 16, SEEK_CUR);

	//2nd pass for offsets

	ptrOffsets.push_back(make_tuple(0x28, 2, offsetScene));
	ptrOffsets.push_back(make_tuple(0xC0, 2, 0xD0));
	//classOffsets.push_back(make_tuple(offsetScene, 0, 0x133));

	dataOffsets[1] = ftell(output) - 0x420;
	//int tempPos = ftell(output);

	classOffsets.push_back(make_tuple(0x90, 0, 0x155));
	classOffsets.push_back(make_tuple(0xD0, 0, 0xDE));
	arrayOffsets.push_back(make_pair(0xDC, offsetBonePointers));
	arrayOffsets.push_back(make_pair(0xE4, offsetTransforms));

	for (int i = 0; i < skeletonNew.numBones; i++)
	{
		ptrOffsets.push_back(make_tuple(offsetBonePointers + i * 4, 2, offsetsBones[i]));
		arrayOffsets.push_back(make_pair(offsetsBones[i], offsetsBones[i] + 0x10));
		classOffsets.push_back(make_tuple(offsetsBones[i], 0, 0xA9));
	}

	arrayOffsets.push_back(make_pair(offsetScene, offsetSceneModellerName));
	arrayOffsets.push_back(make_pair(offsetScene + 4, offsetSceneAssetName));
	classOffsets.push_back(make_tuple(offsetScene, 0, 0x133));

	//fseek(output, tempPos, SEEK_SET);

	fwrite(arrayOffsets.data(), 8, arrayOffsets.size(), output);

	dataOffsets[2] = ftell(output) - 0x420;

	for (int i = 0; i < ptrOffsets.size(); i++)
	{
		fwrite(&get<0>(ptrOffsets.data()[i]), 4, 1, output);
		fwrite(&get<1>(ptrOffsets.data()[i]), 4, 1, output);
		fwrite(&get<2>(ptrOffsets.data()[i]), 4, 1, output);
	}

	int pos = ftell(output);

	if (int gap = pos % 16)
	{
		char pad = 0xFF;
		for (int i = 0; i < 16 - gap; i++)
		{
			fwrite(&pad, 1, 1, output);
		}
	}

	dataOffsets[3] = ftell(output) - 0x420;

	for (int i = 0; i < classOffsets.size(); i++)
	{
		fwrite(&get<0>(classOffsets.data()[i]), 4, 1, output);
		fwrite(&get<1>(classOffsets.data()[i]), 4, 1, output);
		fwrite(&get<2>(classOffsets.data()[i]), 4, 1, output);
	}

	//fwrite(classOffsets.data(), 4, classOffsets.size() * 3, output);

	pos = ftell(output);

	if (int gap = pos % 16)
	{
		char pad = 0xFF;
		for (int i = 0; i < 16 - gap; i++)
		{
			fwrite(&pad, 1, 1, output);
		}
	}

	dataOffsets[4] = ftell(output) - 0x420;
	dataOffsets[5] = dataOffsets[4];
	dataOffsets[6] = dataOffsets[4];

	//fwrite(offsetBlob, 4, numOffsetBlob, output);

	fseek(output, 0xB4, SEEK_SET);
	fwrite(dataOffsets, 4, 7, output);

	printf("finished writing\n");

	if (offsetsBones)
		free(offsetsBones);
	if (referencePose)
		free(referencePose);
	if (parentIndices)
		free(parentIndices);
	if (bones)
		free(bones);
	if (offsetBlob)
		free(offsetBlob);
	fclose(output);
}
