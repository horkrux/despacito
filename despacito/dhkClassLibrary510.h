#pragma once

#include "dhkClass.h"
#include <unordered_map>
#include <string>

using namespace std;

class dhkClassLibrary510
{
public:
	dhkClassLibrary510(void);
	~dhkClassLibrary510(void);

	dhkClass* getClass(const char*);

private:
	static const dhkClassMember hkRootLevelContainerNamedVariantMembers[];
	static const dhkClassMember hkRootLevelContainerMembers[];
	static const dhkClassMember hkVariantMembers[];
	static const dhkClassMember hkArrayMembers[];
	static const dhkClassMember hkSmallArrayMembers[];
	static const dhkClassMember hkaAnimationContainerMembers[];
	static const dhkClassMember hkReferencedObjectMembers[];
	static const dhkClassMember hkaSkeletalAnimationMembers[];
	static const char* hkaSkeletalAnimationParents[];
	static const dhkClassMember hkaWaveletSkeletalAnimationMembers[];
	static const char* hkaWaveletSkeletalAnimationParents[];
	static const dhkClassMember hkaWaveletSkeletalAnimationQuantizationFormatMembers[];
	static const dhkClassMember hkaInterleavedSkeletalAnimationMembers[];
	static const char* hkaInterleavedSkeletalAnimationParents[];
	static const dhkClassMember hkaDeltaCompressedSkeletalAnimationMembers[];
	static const char* hkaDeltaCompressedSkeletalAnimationParents[];
	static const dhkClassMember hkaDefaultAnimatedReferenceFrameMembers[];
	static const char* hkaDefaultAnimatedReferenceFrameMembersParents[];
	static const dhkClassMember hkaAnnotationTrackMembers[];
	static const dhkClassMember hkaAnnotationTrackAnnotationMembers[];
	static const dhkClassMember hkaAnimationBindingMembers[];
	static const dhkClassMember hkxSceneMembers[];
	static const dhkClassMember hkaSkeletonMembers[];
	static const dhkClassMember hkQsTransformMembers[];
	static const dhkClassMember hkaBoneMembers[];
	static const dhkClassMember hkpPhysicsDataMembers[];
	static const char* hkpPhysicsDataParents[];
	static const dhkClassMember hkpPhysicsSystemMembers[];
	static const char* hkpPhysicsSystemParents[];
	static const dhkClassMember hkpCdBodyMembers[];
	static const dhkClassMember hkpBroadPhaseHandleMembers[];
	static const dhkClassMember hkpTypedBroadPhaseHandleMembers[];
	static const char* hkpTypedBroadPhaseHandleParents[];
	static const dhkClassMember hkpCollidableBoundingVolumeDataMembers[];
	static const char* hkpCollidableParents[];
	static const dhkClassMember hkpCollidableMembers[];
	static const dhkClassMember hkpLinkedCollidableMembers[];
	static const char* hkpLinkedCollidableParents[];
	static const dhkClassMember hkMultiThreadCheckMembers[];
	static const dhkClassMember hkpPropertyValueMembers[];
	static const dhkClassMember hkpPropertyMembers[];
	static const dhkClassMember hkpMaterialMembers[];
	static const dhkClassMember hkpWorldObjectMembers[];
	static const char* hkpWorldObjectParents[];
	static const dhkClassMember hkTransformMembers[];
	static const dhkClassMember hkSweptTransformMembers[];
	static const dhkClassMember hkMotionStateMembers[];
	static const dhkClassMember hkpMotionMembers[];
	static const char* hkpMotionParents[];
	static const char* hkpKeyframedRigidMotionParents[];
	static const char* hkpMaxSizeMotionParents[];
	static const dhkClassMember hkpEntitySpuCollisionCallbackMembers[];
	static const char* hkpEntityParents[];
	static const dhkClassMember hkpEntityMembers[];
	static const char* hkpRigidBodyParents[];
	static const char* hkpShapeParents[];
	static const dhkClassMember hkpShapeMembers[];
	static const char* hkpSphereRepShapeParents[];
	static const dhkClassMember hkpConvexShapeMembers[];
	static const char* hkpConvexShapeParents[];
	static const dhkClassMember hkpCapsuleShapeMembers[];
	static const char* hkpCapsuleShapeParents[];
	static const dhkClassMember hkpConstraintDataMembers[];
	static const char* hkpConstraintDataParents[];
	static const dhkClassMember hkpConstraintAtomMembers[];
	static const dhkClassMember hkpSetLocalTransformsConstraintAtomMembers[];
	static const char* hkpSetLocalTransformsConstraintAtomParents[];
	static const dhkClassMember hkpRagdollMotorConstraintAtomMembers[];
	static const char* hkpRagdollMotorConstraintAtomParents[];
	static const dhkClassMember hkpAngFrictionConstraintAtomMembers[];
	static const char* hkpAngFrictionConstraintAtomParents[];
	static const dhkClassMember hkpTwistLimitConstraintAtomMembers[];
	static const char* hkpTwistLimitConstraintAtomParents[];
	static const dhkClassMember hkpConeLimitConstraintAtomMembers[];
	static const char* hkpConeLimitConstraintAtomParents[];
	static const char* hkpBallSocketConstraintAtomParents[];
	static const dhkClassMember hkpRagdollConstraintDataAtomsMembers[];
	static const dhkClassMember hkpRagdollConstraintDataMembers[];
	static const char* hkpRagdollConstraintDataParents[];
	static const dhkClassMember hkpConstraintInstanceMembers[];
	static const char* hkpConstraintInstanceParents[];
	static const dhkClassMember hkaRagdollInstanceMembers[];
	static const char* hkaRagdollInstanceParents[];
	static const dhkClassMember hkaSkeletonMapperDataSimpleMappingMembers[];
	static const dhkClassMember hkaSkeletonMapperDataChainMappingMembers[];
	static const dhkClassMember hkaSkeletonMapperDataMembers[];
	static const dhkClassMember hkaSkeletonMapperMembers[];
	static const char* hkaSkeletonMapperParents[];
	static const dhkClassMember hkpAngMotorConstraintAtomMembers[];
	static const char* hkpAngMotorConstraintAtomParents[];
	static const dhkClassMember hkpAngLimitConstraintAtomMembers[];
	static const char* hkpAngLimitConstraintAtomParents[];
	static const dhkClassMember hkp2dAngConstraintAtomMembers[];
	static const char* hkp2dAngConstraintAtomParents[];
	static const dhkClassMember hkpLimitedHingeConstraintDataAtomsMembers[];
	static const dhkClassMember hkpLimitedHingeConstraintDataMembers[];
	static const char* hkpLimitedHingeConstraintDataParents[];
	static const dhkClassMember hkpConstraintMotorMembers[];
	static const char* hkpConstraintMotorParents[];
	//static const dhkClassMember hkpMaxSizeConstraintMotorMembers[];
	//static const char* hkpMaxSizeConstraintMotorParents[];
	static const dhkClassMember hkpLimitedForceConstraintMotorMembers[];
	static const char* hkpLimitedForceConstraintMotorParents[];
	static const dhkClassMember hkpPositionConstraintMotorMembers[];
	static const char* hkpPositionConstraintMotorParents[];
	static const dhkClassMember hkpConvexVerticesShapeFourVectorsMembers[];
	static const dhkClassMember hkpConvexVerticesShapeMembers[];
	static const char* hkpConvexVerticesShapeParents[];
	static const dhkClassMember hkpSingleShapeContainerMembers[];
	static const char* hkpSingleShapeContainerParents[];
	static const dhkClassMember hkpConvexTranslateShapeMembers[];
	static const char* hkpConvexTranslateShapeParents[];
	static const dhkClassMember hkpBoxShapeMembers[];
	static const char* hkpBoxShapeParents[];
	static const dhkClassMember hkpSphereShapeMembers[];
	static const char* hkpSphereShapeParents[];
	static const dhkClassMember hkpCylinderShapeMembers[];
	static const char* hkpCylinderShapeParents[];
	//static const char* hkpEntityDeactivatorParents[];
	//static const char* hkpRigidBodyDeactivatorParents[];
	//static const dhkClassMember hkSpatialRigidBodyDeactivatorMembers[];
	//static const char* hkSpatialRigidBodyDeactivatorParents[];
	//static const dhkClassMember hkSpatialRigidBodyDeactivatorSampleMembers[];

	unordered_map<string, dhkClass> m_classMap;
};

