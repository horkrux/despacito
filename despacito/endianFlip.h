#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <direct.h>
#include <vector>
#include <tuple>
//#include <Windows.h>
//#include "resource.h"

#include "hkstructs_450.h"
#include "hkstructs_550.h"
//#include "hkstructs_2010.2.0-r1.h"
//#include "hkstructs_20150100.h"
//#include "hkstructs_20160200.h"
#include "hkstructs_common.h"

//typedef struct {
//	int	min[3];
//	char expansionMin[3];
//	char expansionShift;
//	int	max[3];
//	char expansionMax[3];
//	short numChildShapeAabbs;
//} BoundingVolumeData;
//
//typedef struct {
//	char broadphasehandle_type;
//	short broadphasehandle_objectQualityType;
//	int broadphasehandle_collisionFilterInfo;
//	BoundingVolumeData boundingVolumeData;
//	int allowedPenetrationDepth;
//	char name[16];
//	char material_responseType;
//	short material_rollingFrictionMultiplier;
//	int material_friction;
//	int material_restitution;
//	char spuCollisionCallback_eventFilter;
//	char spuCollisionCallback_userFilter;
//	float motion_transform[16];
//	float motion_sweptTransform[20];
//	float motion_deltaAngle[4];
//	float motion_objectRadius;
//} hkpRigidBody;
//
//typedef struct {
//	float info_offset[4];
//	int data_size;
//	char* data;
//} hkpMoppCode;

void convertSkeleton(FILE*, char*);
void convertHavok4Animation(FILE*, char*);
void convertHavok4Skeleton(FILE*, char*);
int checkRootContainer(hkRootLevelContainer_550*);
int checkAnimContainer(hkaAnimationContainer_550*);
int checkAnimBinding(hkaAnimationBinding_550*);
int checkInterleavedSkeletalAnim(hkaInterleavedSkeletalAnimation_550*);
int checkScene(hkxScene_550*);
void flipEndianRootContainer(hkRootLevelContainer_550*);
void flipEndianAnimContainer(hkaAnimationContainer_550*);
void flipEndianWaveletSkeletalAnim450(hkaWaveletSkeletalAnimation_450*);
void flipEndianWaveletSkeletalAnim(hkaWaveletSkeletalAnimation_550*);
void flipEndianInterleavedSkeletalAnim(hkaInterleavedSkeletalAnimation_550*);
void flipEndianDeltaCompressedSkeletalAnim(hkaDeltaCompressedSkeletalAnimation_550*);
void flipEndianDeltaCompressedSkeletalAnim450(hkaDeltaCompressedSkeletalAnimation_450*);
void flipEndianReferenceFrame(hkaDefaultAnimatedReferenceFrame_550*);
void flipEndianAnimBinding(hkaAnimationBinding_550*);
void flipEndianAnimBinding450(hkAnimationBinding_450*);
void flipEndianScene(hkxScene_550*);
void flipEndianQsTranform(QsTransform*);
void flipEndianSkeleton(hkaSkeleton_550*);
void flipEndianSkeleton450(hkaSkeleton_450*);
void hkaDeltaCompressedSkeletalAnimation_450to550(hkaDeltaCompressedSkeletalAnimation_550*, hkaDeltaCompressedSkeletalAnimation_450*);
void hkaWaveletSkeletalAnimation_450to550(hkaWaveletSkeletalAnimation_550*, hkaWaveletSkeletalAnimation_450*);
void hkaAnimationBinding_450to550(hkaAnimationBinding_550*, hkAnimationBinding_450*);
void hkaSkeleton_450to550(hkaSkeleton_550*, hkaSkeleton_450*);

//int process_hk2010col(FILE*, CustomParamStorageExtendedMeshShape_hk2010*, hkpRigidBody*, hkpMoppCode*);
//int write_ds1rcol(char*, CustomParamStorageExtendedMeshShape_SDKV20150100*, hkpRigidBody*, hkpMoppCode*);
//void cleanup(hkpStorageExtendedMeshShape_hk2010*, hkpMoppCode*);
//void pad_pow2(FILE*);
//size_t fwritebe_int(int*, size_t, FILE*);
//void transfer_storage_to_SDKV20150100(CustomParamStorageExtendedMeshShape_hk2010*, CustomParamStorageExtendedMeshShape_SDKV20150100*);