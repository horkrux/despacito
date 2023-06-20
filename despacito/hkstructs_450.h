#pragma once

typedef struct {
	int ignore1;
	int ignore2;
	int type;
	unsigned int duration;
	int numberOfTracks;
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
	int pad;
} hkaWaveletSkeletalAnimation_450;

typedef struct {
	int ignore1;
	int ignore2;
	int type;
	unsigned int duration;
	int numberOfTracks;
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
	int pad[3];
} hkaDeltaCompressedSkeletalAnimation_450;

typedef struct {
	int animation;
	int animationTrackToBoneIndices;
	int numAnimationTrackToBoneIndices;
	char blendHint;
	char pad[3];
} hkAnimationBinding_450;

typedef struct {
	int name;
	int parentIndices;
	int numParentIndices;
	int bones;
	int numBones;
	int referencePose;
	int numReferencePose;
	int pad;
} hkaSkeleton_450;