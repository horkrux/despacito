#pragma once

#include "hkstructs_common.h"

typedef struct {
	int namedVariants;
	int numNamedVariants;
	int pad1;
	int pad2;
} hkRootLevelContainer_550;

typedef struct {
	int skeletons;
	int numSkeletons;
	int animations;
	int numAnimations;
	int bindings;
	int numBindings;
	int attachments;
	int numAttachments;
	int skins;
	int numSkins;
	int pad1;
	int pad2;
} hkaAnimationContainer_550;

typedef struct {
	int ignore1;
	int ignore2;
	int type;
	unsigned int duration;
	int numberOfTransformTracks;
	int numberOfFloatTracks;
	int extractedMotion;
	int annotationTracks;
	int numAnnotationTracks;
	int numberOfPoses;
	int blockSize;
//QuantizationFormat-->
	char maxBitWidth;
	char preserved;
	char pad1;
	char pad2;
	int numD;
	int offsetIdx;
	int scaleIdx;
	int bitWidthIdx;
//QuantizationFormat<--
	int staticMaskIdx;
	int staticDOFsIdx;
	int blockIndexIdx;
	int blockIndexSize;
	int quantizedDataIdx;
	int quantizedDataSize;
	int dataBuffer;
	int numDataBuffer;
} hkaWaveletSkeletalAnimation_550;

typedef struct {
	int ignore1;
	int ignore2;
	int type;
	unsigned int duration;
	int numberOfTransformTracks;
	int numberOfFloatTracks;
	int extractedMotion;
	int annotationTracks;
	int numAnnotationTracks;
	int transforms;
	int numTransforms;
	int floats;
	int numFloats;
	int pad[3];
} hkaInterleavedSkeletalAnimation_550;

typedef struct {
	int ignore1;
	int ignore2;
	int type;
	unsigned int duration;
	int numberOfTransformTracks;
	int numberOfFloatTracks;
	int extractedMotion;
	int annotationTracks;
	int numAnnotationTracks;
	int numberOfPoses;
	int blockSize;
//QuantizationFormat-->
	char maxBitWidth;
	char preserved;
	char pad1;
	char pad2;
	int numD;
	int offsetIdx;
	int scaleIdx;
	int bitWidthIdx;
//QuantizationFormat<--
	int quantizedDataIdx;
	int quantizedDataSize;
	int staticMaskIdx;
	int staticMaskSize;
	int staticDOFsIdx;
	int staticDOFsSize;
	int totalBlockSize;
	int lastBlockSize;
	int dataBuffer;
	int numDataBuffer;
	int pad[2];
} hkaDeltaCompressedSkeletalAnimation_550;

typedef struct {
	char shit[16];
	Vector4 up;
	Vector4 forward;
	int duration;
	int referenceFrameSamples;
	int numReferenceFrameSamples;
	int pad1;
} hkaDefaultAnimatedReferenceFrame_550;

typedef struct {
	int animation;
	int transformTrackToBoneIndices;
	int numTransformTrackToBoneIndices;
	int floatTrackToFloatSlotIndices;
	int numFloatTrackToFloatSlotIndices;
	char blendHint;
	char pad1;
	short pad2;
	int pad3;
	int pad4;
} hkaAnimationBinding_550;

typedef struct {
	int modeller;
	int asset;
	int sceneLength;
	int rootNode;
	int selectionSets;
	int numSelectionSets;
	int cameras;
	int numCameras;
	int lights;
	int numLights;
	int meshes;
	int numMeshes;
	int materials;
	int numMaterials;
	int inplaceTextures;
	int numInplaceTextures;
	int externalTextures;
	int numExternalTextures;
	int skinBindings;
	int numSkinBindings;
	Vector4 appliedTransform[3];
} hkxScene_550;

typedef struct {
	int name;
	int parentIndices;
	int numParentIndices;
	int bones;
	int numBones;
	int referencePose;
	int numReferencePose;
	int floatSlots;
	int numFloatSlots;
	int pad[3];
} hkaSkeleton_550;