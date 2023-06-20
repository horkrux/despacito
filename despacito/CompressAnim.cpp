// CompressAnim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dhkPackfileReader.h"

// Keycode
#include <Common/Base/keycode.cxx>

//#define HK_CLASSES_FILE <Common/Serialize/Classlist/hkClasses.h>
//#include <Common/Serialize/Util/hkBuiltinTypeRegistry.cxx>
#include <Common/Serialize/Util/hkSerializeUtil.h>
#include <Common/Serialize/Util/hkBuiltinTypeRegistry.h>
#include <Common/Base/Reflection/Registry/hkVtableClassRegistry.h>
//#include <Common/Base/Reflection/hkClass.h>
#include <Common/Base/Reflection/hkTypeInfo.h>
#include <Common/Base/Reflection/Registry/hkDefaultClassNameRegistry.h>

//#define HK_EXCLUDE_FEATURE_MemoryTracker
//#undef HK_FEATURE_PRODUCT_PHYSICS
#undef HK_FEATURE_PRODUCT_BEHAVIOR
#undef HK_FEATURE_PRODUCT_CLOTH
#undef HK_FEATURE_PRODUCT_DESTRUCTION
#undef HK_FEATURE_PRODUCT_AI

#define HK_EXCLUDE_FEATURE_hkpKdTreeWorldManager
#define HK_EXCLUDE_LIBRARY_hkVisualize
//#define HK_EXCLUDE_LIBRARY_hkpUtilities
#define HK_EXCLUDE_LIBRARY_hkpVehicle
#define HK_EXCLUDE_FEATURE_hkpHeightField
#define HK_EXCLUDE_FEATURE_hkpContinuousSimulation
#define HK_EXCLUDE_FEATURE_hkpMultiThreadedSimulation
#define HK_EXCLUDE_FEATURE_hkpAabbTreeWorldManager
#define HK_EXCLUDE_FEATURE_hkpAccurateInertiaTensorComputer

#define HK_CLASSES_FILE "customDarkSoulsClasses.h"
//#define HK_CLASSES_FILE <Common/Serialize/Classlist/hkKeyCodeClasses.h>
//#define HK_CLASSES_FILE <Common/Serialize/Classlist/hkAnimationClasses.h>
#include <Common/Base/Config/hkProductFeatures.cxx>
//#include <Common/Base/Config/hkProductFeaturesNoPatchesOrCompat.h>
//extern const hkClass CustomMeshParameterClass;
//extern const hkClass CustomParamStorageExtendedMeshShapeClass;



static hkaSplineCompressedAnimation::TrackCompressionParams compressParams;

static void HK_CALL errorReport(const char* msg, void*)
{
	printf("%s\n", msg);
}

void loadEntireFileIntoBuffer(const char* filepath, hkArray<char>& outBuf)
{
	// Load the entire file
	// Open a stream to read the file
	hkIstream infile( filepath );
	HK_ASSERT( 0x215d080c, infile.isOk() );

	if( infile.getStreamReader()->seekTellSupported() )
	{
		infile.getStreamReader()->seek(0, hkStreamReader::STREAM_END);
		outBuf.reserve( infile.getStreamReader()->tell() );
		infile.getStreamReader()->seek(0, hkStreamReader::STREAM_SET);
	}

	// read entire file into local buffer
	int nread = 1;
	while( nread )
	{
		const int CSIZE = 8192;
		char* b = outBuf.expandBy( CSIZE ); // outBuf.reserve( outBuf.getSize() + CSIZE ); b = outBuf.begin() + outBuf.getSize();
		nread = infile.read( b, CSIZE );
		outBuf.setSize( outBuf.getSize() + nread - CSIZE );
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool isXml = false;
	bool isDecompress = false;

	if (argc < 2 || argc > 4) {
		printf("despacito version 1.0\nUsage: despacito [options] infiles\n\nSeparate file paths/names with ; in one string\n\nOptions:\n  -t  --output as xml\n  -d  --decompress animations (if present)\n");
		return 0;
	}

	dhkPackfileReader packfileReader;
	hkMemoryRouter* memoryRouter = hkMemoryInitUtil::initDefault(hkMallocAllocator::m_defaultMallocAllocator, hkMemorySystem::FrameInfo(0));
	hkBaseSystem::init( memoryRouter, errorReport );

	if (argc == 3)
	{
		if (!wcscmp(argv[1], L"-t"))
		{
			isXml = true;
		}

		if (!wcscmp(argv[1], L"-d"))
		{
			isDecompress = true;
		}

	} else if (argc == 4) {
		if (!wcscmp(argv[1], L"-t") || !wcscmp(argv[2], L"-t")) {
			isXml = true;
		}

		if (!wcscmp(argv[1], L"-d") || !wcscmp(argv[2], L"-d")) {
			isDecompress = true;
		}
	}

	wstring filenames = argv[argc - 1];
	wstring filename;
	size_t pos;



	while ((pos = filenames.find(L";")) != std::wstring::npos || filenames.length() > 0)
	{
		if (pos != std::wstring::npos) {
			filename = filenames.substr(0, pos);
			filenames.erase(0, pos + 1);
		} else {
			filename = filenames;
			filenames.erase(0, filenames.length());
		}

		if (filename.length() == 0) break;

		wstring displayname;

		size_t found = filename.find_last_of(L"/\\");

		if (found == std::wstring::npos)
			displayname = filename;
		else
			displayname = filename.substr(found + 1);

		printf("Processing %S ...\n", displayname.c_str());

		dhkPackfileReader::PACKFILE_STATUS packfileStatus;

		if ((packfileStatus = packfileReader.loadPackfile(filename)) != dhkPackfileReader::FILEERR) {
			if (packfileStatus != dhkPackfileReader::EMPTY)
				packfileReader.fixDataSection();

			//packfileReader.writeFixedPackfile(filename);
	
			char* contents = packfileReader.getPackfileContents();
			int packfileSize = packfileReader.getPackfileSize();

			hkArray<char> buf;
			char* b = buf.expandBy(packfileSize);
			memcpy(b, contents, packfileSize);
			hkRootLevelContainer* container = HK_NULL;

			hkResource* res = hkSerializeUtil::load(buf.begin(), buf.getSize());

			if (!res)
			{
				printf("Failed to load havok file!\n");
				continue;
			}

			container = res->getContents<hkRootLevelContainer>();

			if (isDecompress)
				decompressAnims(container);

			hkPackfileWriter::Options options;
			hkSerializeUtil::SaveOptions saveOptions = hkSerializeUtil::SAVE_DEFAULT;

			if (isXml)
				saveOptions = hkSerializeUtil::SAVE_TEXT_FORMAT;

			if (filename.length() > 4)
			{
				filename.insert(filename.length()-4, L"hk2010");
			} else {
				filename.append(L"hk2010");
			}

			_bstr_t out(filename.c_str());

			printf("Saving hk2010 file...");

			if (!hkSerializeUtil::savePackfile( container, hkRootLevelContainerClass, hkOstream(out).getStreamWriter(), options, HK_NULL, saveOptions)) {
				printf("SUCCESS\n");
			} else {
				printf("FAILURE\n");
			}
		}
	}

	hkBaseSystem::quit();
	hkMemoryInitUtil::quit();

	return 0;
}

void decompressAnims(hkRootLevelContainer* container)
{
	if (container)
	{
		hkaAnimationContainer* animationContainer = static_cast<hkaAnimationContainer*>(container->findObjectByType(hkaAnimationContainerClass.getName()));

		if (animationContainer)
		{
			for (int i = 0; i < animationContainer->m_animations.getSize(); i++)
			{
				if (animationContainer->m_animations[i]->getType() == hkaAnimation::HK_WAVELET_COMPRESSED_ANIMATION || animationContainer->m_animations[i]->getType() == hkaAnimation::HK_DELTA_COMPRESSED_ANIMATION || animationContainer->m_animations[i]->getType() == hkaAnimation::HK_SPLINE_COMPRESSED_ANIMATION)
				{
					hkaAnimation* waveletAnim = static_cast<hkaAnimation*>(animationContainer->m_animations[i].val());
					hkaInterleavedUncompressedAnimation* anim = new hkaInterleavedUncompressedAnimation();
					anim->m_duration = waveletAnim->m_duration;
					anim->m_numberOfTransformTracks = waveletAnim->m_numberOfTransformTracks;

					int numFrames = waveletAnim->getNumOriginalFrames();

					hkReal step = anim->m_duration / numFrames;

					hkQsTransform transformTracks[1000]; //LOOOOL HAHA
					hkQsTransform whatever[1000];

					hkReal* floatTracks = new hkReal[waveletAnim->m_numberOfFloatTracks];

					hkInt16* tracks = new hkInt16[numFrames * waveletAnim->m_numberOfTransformTracks];

					for (hkInt16 j = 0; j < waveletAnim->m_numberOfTransformTracks; j++)
					{
						tracks[j] = j;
					}

					for (int j = 0; j < numFrames; j++)
					{
						waveletAnim->sampleTracks(j * step, transformTracks, floatTracks, HK_NULL);

						anim->m_transforms.append(transformTracks, waveletAnim->m_numberOfTransformTracks);
						anim->m_floats.append(floatTracks, waveletAnim->m_numberOfFloatTracks);
					}

					anim->m_annotationTracks = waveletAnim->m_annotationTracks;

					anim->m_extractedMotion = waveletAnim->m_extractedMotion;

					animationContainer->m_animations[i].setAndDontIncrementRefCount(anim);
					animationContainer->m_bindings[i].val()->m_animation.setAndDontIncrementRefCount(anim);

					delete[] tracks;
					delete[] floatTracks;
				}
			}
		}
	}
}