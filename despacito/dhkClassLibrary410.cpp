#include "dhkClassLibrary410.h"

const dhkClassMember dhkClassLibrary410::hkRootLevelContainerNamedVariantMembers[] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0), 
																		 dhkClassMember("className", dhkClassMember::PTR_IGNORE, true, 4), 
																		 dhkClassMember("variant", dhkClassMember::CLASS, false, 8, "hkVariant") };
const dhkClassMember dhkClassLibrary410::hkRootLevelContainerMembers[2] = { dhkClassMember("namedVariants", dhkClassMember::PTR_CLASS, true, 0, "hkRootLevelContainerNamedVariant"),
															 dhkClassMember("numNamedVariants", dhkClassMember::DWORD, false, 4) };
const dhkClassMember dhkClassLibrary410::hkVariantMembers[2] = { dhkClassMember("object", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary410::hkArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0), 
												dhkClassMember("size", dhkClassMember::DWORD, false, 4), 
												dhkClassMember("capacityAndFlags", dhkClassMember::DWORD, false, 8) };
const dhkClassMember dhkClassLibrary410::hkSmallArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0),
											dhkClassMember("size", dhkClassMember::WORD, false, 4), //uh oh
											dhkClassMember("capacityAndFlags", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary410::hkAnimationContainerMembers[10] = { dhkClassMember("skeletons", dhkClassMember::PTR_IGNORE, true, 0), 
															   dhkClassMember("numSkeletons", dhkClassMember::DWORD, false, 4), 
															   dhkClassMember("animations", dhkClassMember::PTR_IGNORE, true, 8),
															   dhkClassMember("numAnimations", dhkClassMember::DWORD, false, 12),
															   dhkClassMember("bindings", dhkClassMember::PTR_IGNORE, true, 16),
															   dhkClassMember("numBindings", dhkClassMember::DWORD, false, 20),
															   dhkClassMember("attachments", dhkClassMember::PTR_IGNORE, true, 24),
															   dhkClassMember("numAttachments", dhkClassMember::DWORD, false, 28),
															   dhkClassMember("skins", dhkClassMember::PTR_IGNORE, true, 32),
															   dhkClassMember("numSkins", dhkClassMember::DWORD, false, 36)};
const dhkClassMember dhkClassLibrary410::hkReferencedObjectMembers[2] = { dhkClassMember("memSizeAndFlags", dhkClassMember::WORD, false, 4),
														   dhkClassMember("referenceCount", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary410::hkSkeletalAnimationMembers[6] = { dhkClassMember("type", dhkClassMember::DWORD, false, 8),
															 dhkClassMember("duration", dhkClassMember::DWORD, false, 12),
															 dhkClassMember("numberOfTracks", dhkClassMember::DWORD, false, 16),
															 dhkClassMember("extractedMotion", dhkClassMember::PTR_CLASS, false, 20), //not sure
															 dhkClassMember("annotationTracks", dhkClassMember::PTR_IGNORE, true, 24),
															 dhkClassMember("numAnnotationTracks", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary410::hkSkeletalAnimationParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkWaveletSkeletalAnimationMembers[11] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
																	 dhkClassMember("blockSize", dhkClassMember::DWORD, false, 36),
																	 dhkClassMember("qFormat", dhkClassMember::CLASS, false, 40, "hkWaveletSkeletalAnimationQuantizationFormat"),
																	 dhkClassMember("staticMaskIdx", dhkClassMember::DWORD, false, 60),
																	 dhkClassMember("staticDOFsIdx", dhkClassMember::DWORD, false, 64),
																	 dhkClassMember("blockIndexIdx", dhkClassMember::DWORD, false, 68),
																	 dhkClassMember("blockIndexSize", dhkClassMember::DWORD, false, 72),
																	 dhkClassMember("quantizedDataIdx", dhkClassMember::DWORD, false, 76),
																	 dhkClassMember("quantizedDataSize", dhkClassMember::DWORD, false, 80),
																	 dhkClassMember("dataBuffer", dhkClassMember::PTR_IGNORE, true, 84),
																	 dhkClassMember("numDataBuffer", dhkClassMember::DWORD, false, 88)};
const char* dhkClassLibrary410::hkWaveletSkeletalAnimationParents[1] = { "hkSkeletalAnimation" };
const dhkClassMember dhkClassLibrary410::hkWaveletSkeletalAnimationQuantizationFormatMembers[6] = { dhkClassMember("maxBitWidth", dhkClassMember::BYTE, false, 0),
																					 dhkClassMember("preserved", dhkClassMember::BYTE, false, 1),
																					 dhkClassMember("numD", dhkClassMember::DWORD, false, 4),
																					 dhkClassMember("offsetIdx", dhkClassMember::DWORD, false, 8),
																					 dhkClassMember("scaleIdx", dhkClassMember::DWORD, false, 12),
																					 dhkClassMember("bitWidthIdx", dhkClassMember::DWORD, false, 16)};
const dhkClassMember dhkClassLibrary410::hkDefaultAnimatedReferenceFrameMembers[5] = { dhkClassMember("up", dhkClassMember::VECTOR4, false, 16),
																		 dhkClassMember("forward", dhkClassMember::VECTOR4, false, 32),
																		 dhkClassMember("duration", dhkClassMember::DWORD, false, 48),
																		 dhkClassMember("referenceFrameSamples", dhkClassMember::PTR_VECTOR4, true, 52),
																		 dhkClassMember("numReferenceFrameSamples", dhkClassMember::DWORD, false, 56)};
const char* dhkClassLibrary410::hkDefaultAnimatedReferenceFrameMembersParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkAnnotationTrackMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
														   dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 4, "hkAnnotationTrackAnnotation"),
														   dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkAnnotationTrackAnnotationMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																	 dhkClassMember("text", dhkClassMember::PTR_IGNORE, true, 4)};
const dhkClassMember dhkClassLibrary410::hkDeltaCompressedSkeletalAnimationMembers[13] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
																						dhkClassMember("blockSize", dhkClassMember::DWORD, false, 36),
																						dhkClassMember("qFormat", dhkClassMember::CLASS, false, 40, "hkWaveletSkeletalAnimationQuantizationFormat"),
																						dhkClassMember("quantizedDataIdx", dhkClassMember::DWORD, false, 60),
																						dhkClassMember("quantizedDataSize", dhkClassMember::DWORD, false, 64),
																						dhkClassMember("staticMaskIdx", dhkClassMember::DWORD, false, 68),
																						dhkClassMember("staticMaskSize", dhkClassMember::DWORD, false, 72),
																						dhkClassMember("staticDOFsIdx", dhkClassMember::DWORD, false, 76),
																						dhkClassMember("staticDOFsSize", dhkClassMember::DWORD, false, 80),
																						dhkClassMember("totalBlockSize", dhkClassMember::DWORD, false, 84),
																						dhkClassMember("lastBlockSize", dhkClassMember::DWORD, false, 88),
																						dhkClassMember("dataBuffer", dhkClassMember::PTR_IGNORE, true, 92),
																						dhkClassMember("numDataBuffer", dhkClassMember::DWORD, false, 96)};
const char* dhkClassLibrary410::hkDeltaCompressedSkeletalAnimationParents[] = { "hkSkeletalAnimation" };
const dhkClassMember dhkClassLibrary410::hkAnimationBindingMembers[4] = { dhkClassMember("animation", dhkClassMember::PTR_IGNORE, false, 0),
															dhkClassMember("animationTrackToBoneIndices", dhkClassMember::PTR_WORD, true, 4),
															dhkClassMember("numAnimationTrackToBoneIndices", dhkClassMember::DWORD, false, 8),
															dhkClassMember("blendHint", dhkClassMember::BYTE, false, 12)};
const dhkClassMember dhkClassLibrary410::hkxSceneMembers[19] = { dhkClassMember("modeller", dhkClassMember::PTR_IGNORE, true, 0),
												  dhkClassMember("asset", dhkClassMember::PTR_IGNORE, true, 4),
												  dhkClassMember("sceneLength", dhkClassMember::DWORD, false, 8),
												  dhkClassMember("rootNode", dhkClassMember::PTR_IGNORE, false, 12),
												  dhkClassMember("cameras", dhkClassMember::PTR_IGNORE, true, 16),
												  dhkClassMember("numCameras", dhkClassMember::DWORD, false, 20),
												  dhkClassMember("lights", dhkClassMember::PTR_IGNORE, true, 24),
												  dhkClassMember("numLights", dhkClassMember::DWORD, false, 28),
												  dhkClassMember("meshes", dhkClassMember::PTR_IGNORE, true, 32),
												  dhkClassMember("numMeshes", dhkClassMember::DWORD, false, 36),
												  dhkClassMember("materials", dhkClassMember::PTR_IGNORE, true, 40),
												  dhkClassMember("numMaterials", dhkClassMember::DWORD, false, 44),
												  dhkClassMember("inplaceTextures", dhkClassMember::PTR_IGNORE, true, 48),
												  dhkClassMember("numInplaceTextures", dhkClassMember::DWORD, false, 52),
												  dhkClassMember("externalTextures", dhkClassMember::PTR_IGNORE, true, 56),
												  dhkClassMember("numExternalTextures", dhkClassMember::DWORD, false, 60),
												  dhkClassMember("skinBindings", dhkClassMember::PTR_IGNORE, true, 64),
												  dhkClassMember("numSkinBindings", dhkClassMember::DWORD, false, 68),
												  dhkClassMember("appliedTransform", dhkClassMember::MATRIX3, false, 80)};
const dhkClassMember dhkClassLibrary410::hkSkeletonMembers[7] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
												dhkClassMember("parentIndices", dhkClassMember::PTR_WORD, true, 4),
												dhkClassMember("numParentIndices", dhkClassMember::DWORD, false, 8),
												dhkClassMember("bones", dhkClassMember::PTR_IGNORE, true, 12),
												dhkClassMember("numBones", dhkClassMember::DWORD, false, 16),
												dhkClassMember("referencePose", dhkClassMember::PTR_CLASS, true, 20, "hkQsTransform"),
												dhkClassMember("numReferencePose", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary410::hkQsTransformMembers[3] = { dhkClassMember("translation", dhkClassMember::VECTOR4, false, 0),
													dhkClassMember("rotation", dhkClassMember::VECTOR4, false, 16),
													dhkClassMember("scale", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary410::hkBoneMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
											dhkClassMember("lockTranslation", dhkClassMember::BYTE, false, 4)};
const dhkClassMember dhkClassLibrary410::hkPhysicsDataMembers[2] = { dhkClassMember("worldCinfo", dhkClassMember::PTR_IGNORE, false, 8),
											dhkClassMember("systems", dhkClassMember::CLASS, false, 12, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary410::hkPhysicsDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkPhysicsSystemMembers[7] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("actions", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("phantoms", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 56),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 60),
													dhkClassMember("active", dhkClassMember::BYTE, false, 64)};
const char* dhkClassLibrary410::hkPhysicsSystemParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkCdBodyMembers[4] = { dhkClassMember("shape", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("shapeKey", dhkClassMember::DWORD, false, 4),
												dhkClassMember("motion", dhkClassMember::PTR_IGNORE, false, 8),
												dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary410::hkBroadPhaseHandleMembers[1] = { dhkClassMember("id", dhkClassMember::DWORD, false, 0)};
const dhkClassMember dhkClassLibrary410::hkTypedBroadPhaseHandleMembers[4] = { dhkClassMember("type", dhkClassMember::BYTE, false, 4),
															dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 5),
															dhkClassMember("objectQualityType", dhkClassMember::WORD, false, 6),
															dhkClassMember("collisionFilterInfo", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary410::hkTypedBroadPhaseHandleParents[1] = { "hkBroadPhaseHandle" };
const char* dhkClassLibrary410::hkCollidableParents[1] = { "hkCdBody" };
const dhkClassMember dhkClassLibrary410::hkCollidableMembers[3] = { dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 16),
													dhkClassMember("broadPhaseHandle", dhkClassMember::CLASS, false, 20, "hkTypedBroadPhaseHandle"),
													dhkClassMember("allowedPenetrationDepth", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary410::hkLinkedCollidableMembers[1] = { dhkClassMember("collisionEntries", dhkClassMember::CLASS, false, 36, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary410::hkLinkedCollidableParents[1] = { "hkCollidable" };
const dhkClassMember dhkClassLibrary410::hkMultiThreadLockMembers[3] = { dhkClassMember("threadId", dhkClassMember::DWORD, false, 0),
													dhkClassMember("lockCount", dhkClassMember::WORD, false, 4),
													dhkClassMember("lockBitStack", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary410::hkPropertyValueMembers[1] = { dhkClassMember("data", dhkClassMember::QWORD, false, 0)};
const dhkClassMember dhkClassLibrary410::hkPropertyMembers[3] = { dhkClassMember("key", dhkClassMember::DWORD, false, 0),
												dhkClassMember("alignmentPadding", dhkClassMember::DWORD, false, 4),
												dhkClassMember("value", dhkClassMember::CLASS, false, 8, "hkPropertyValue")};
const dhkClassMember dhkClassLibrary410::hkMaterialMembers[3] = { dhkClassMember("responseType", dhkClassMember::BYTE, false, 0),
												dhkClassMember("friction", dhkClassMember::DWORD, false, 4),
												dhkClassMember("restitution", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkWorldObjectMembers[6] = { dhkClassMember("world", dhkClassMember::PTR_IGNORE, false, 8),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 12),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 16),
													dhkClassMember("multithreadLock", dhkClassMember::CLASS, false, 20, "hkMultiThreadLock"),
													dhkClassMember("collidable", dhkClassMember::CLASS, false, 28, "hkLinkedCollidable"),
													dhkClassMember("properties", dhkClassMember::CLASS, false, 76, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary410::hkWorldObjectParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkTransformMembers[2] = { dhkClassMember("rotation", dhkClassMember::MATRIX3, false, 0),
												dhkClassMember("translation", dhkClassMember::VECTOR4, false, 48)};
const dhkClassMember dhkClassLibrary410::hkSweptTransformMembers[5] = { dhkClassMember("centerOfMass0", dhkClassMember::VECTOR4, false, 0),
											dhkClassMember("centerOfMass1", dhkClassMember::VECTOR4, false, 16),
											dhkClassMember("rotation0", dhkClassMember::VECTOR4, false, 32),
											dhkClassMember("rotation1", dhkClassMember::VECTOR4, false, 48),
											dhkClassMember("centerOfMassLocal", dhkClassMember::VECTOR4, false, 64)};
const dhkClassMember dhkClassLibrary410::hkMotionStateMembers[11] = { dhkClassMember("transform", dhkClassMember::CLASS, false, 0, "hkTransform"),
													dhkClassMember("sweptTransform", dhkClassMember::CLASS, false, 64, "hkSweptTransform"),
													dhkClassMember("deltaAngle", dhkClassMember::VECTOR4, false, 144),
													dhkClassMember("objectRadius", dhkClassMember::DWORD, false, 160),
													dhkClassMember("maxLinearVelocity", dhkClassMember::DWORD, false, 164),
													dhkClassMember("maxAngularVelocity", dhkClassMember::DWORD, false, 168),
													dhkClassMember("linearDamping", dhkClassMember::DWORD, false, 172),
													dhkClassMember("angularDamping", dhkClassMember::DWORD, false, 176),
													dhkClassMember("deactivationClass", dhkClassMember::WORD, false, 180),
													dhkClassMember("deactivationCounter", dhkClassMember::WORD, false, 182),
													dhkClassMember("deactivationRefOrientation", dhkClassMember::DWORD, false, 184)};

const dhkClassMember dhkClassLibrary410::hkMotionMembers[10] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8),
												dhkClassMember("deactivationIntegrateCounter", dhkClassMember::BYTE, false, 9),
												dhkClassMember("deactivationNumInactiveFrames_0", dhkClassMember::BYTE, false, 10),
												dhkClassMember("deactivationNumInactiveFrames_1", dhkClassMember::BYTE, false, 11),
												dhkClassMember("motionState", dhkClassMember::CLASS, false, 16, "hkMotionState"),
												dhkClassMember("inertiaAndMassInv", dhkClassMember::VECTOR4, false, 208),
												dhkClassMember("linearVelocity", dhkClassMember::VECTOR4, false, 224),
												dhkClassMember("angularVelocity", dhkClassMember::VECTOR4, false, 240),
												dhkClassMember("deactivationRefPosition_0", dhkClassMember::VECTOR4, false, 256),
												dhkClassMember("deactivationRefPosition_1", dhkClassMember::VECTOR4, false, 272)};
const char* dhkClassLibrary410::hkMotionParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkKeyframedRigidMotionMembers[2] = { dhkClassMember("savedMotion", dhkClassMember::PTR_IGNORE, false, 288),
																			dhkClassMember("savedQualityTypeIndex", dhkClassMember::DWORD, false, 292)};
const char* dhkClassLibrary410::hkKeyframedRigidMotionParents[1] = { "hkMotion" };
const char* dhkClassLibrary410::hkMaxSizeMotionParents[1] = { "hkKeyframedRigidMotion" };
//const dhkClassMember dhkClassLibrary410::hkEntitySpuCollisionCallbackMembers[4] = { dhkClassMember("util", dhkClassMember::PTR_IGNORE, false, 0),
//																	dhkClassMember("capacity", dhkClassMember::WORD, false, 4),
//																	dhkClassMember("eventFilter", dhkClassMember::BYTE, false, 6),
//																	dhkClassMember("userFilter", dhkClassMember::BYTE, false, 7)};
const char* dhkClassLibrary410::hkEntityParents[1] = { "hkWorldObject" };
const dhkClassMember dhkClassLibrary410::hkEntityMembers[16] = { dhkClassMember("simulationIsland", dhkClassMember::PTR_IGNORE, false, 88),
											dhkClassMember("material", dhkClassMember::CLASS, false, 92, "hkMaterial"),
											dhkClassMember("deactivator", dhkClassMember::PTR_IGNORE, false, 104), //hkEntityDeactivator
											dhkClassMember("constraintsMaster", dhkClassMember::CLASS, false, 108, "hkArray", dhkClassMember::PTR_IGNORE), //hkConstraintInternal
											dhkClassMember("constraintsSlave", dhkClassMember::CLASS, false, 120, "hkArray", dhkClassMember::PTR_IGNORE), //hkConstraintInstance
											dhkClassMember("constraintRuntime", dhkClassMember::CLASS, false, 132, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("storageIndex", dhkClassMember::WORD, false, 144),
											dhkClassMember("processContactCallbackDelay", dhkClassMember::WORD, false, 146),
											dhkClassMember("autoRemoveLevel", dhkClassMember::BYTE, false, 148),
											dhkClassMember("solverData", dhkClassMember::DWORD, false, 152),
											dhkClassMember("uid", dhkClassMember::DWORD, false, 156),
											dhkClassMember("motion", dhkClassMember::CLASS, false, 160, "hkMaxSizeMotion"), //??? aligned
											dhkClassMember("collisionListeners", dhkClassMember::CLASS, false, 456, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("activationListeners", dhkClassMember::CLASS, false, 468, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("entityListeners", dhkClassMember::CLASS, false, 480, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("actions", dhkClassMember::CLASS, false, 492, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary410::hkRigidBodyParents[1] = { "hkEntity" };
const char* dhkClassLibrary410::hkShapeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkShapeMembers[1] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkSingleShapeContainerMembers[1] = { dhkClassMember("childShape", dhkClassMember::PTR_IGNORE, false, 0)}; //hkpShape
const char* dhkClassLibrary410::hkSingleShapeContainerParents[1] = { "hkShapeContainer" };
const char* dhkClassLibrary410::hkEntityDeactivatorParents[1] = { "hkReferencedObject" };
const char* dhkClassLibrary410::hkRigidBodyDeactivatorParents[1] = { "hkEntityDeactivator" };
const dhkClassMember dhkClassLibrary410::hkSpatialRigidBodyDeactivatorMembers[7] = { dhkClassMember("highFrequencySample", dhkClassMember::CLASS, false, 16, "hkSpatialRigidBodyDeactivatorSample"),
																					dhkClassMember("lowFrequencySample", dhkClassMember::CLASS, false, 48, "hkSpatialRigidBodyDeactivatorSample"),
																					dhkClassMember("radiusSqrd", dhkClassMember::DWORD, false, 80),
																					dhkClassMember("minHighFrequencyTranslation", dhkClassMember::DWORD, false, 84),
																					dhkClassMember("minHighFrequencyRotation", dhkClassMember::DWORD, false, 88),
																					dhkClassMember("minLowFrequencyTranslation", dhkClassMember::DWORD, false, 92),
																					dhkClassMember("minLowFrequencyRotation", dhkClassMember::DWORD, false, 96)};
const char* dhkClassLibrary410::hkSpatialRigidBodyDeactivatorParents[1] = { "hkRigidBodyDeactivator" };
const dhkClassMember dhkClassLibrary410::hkSpatialRigidBodyDeactivatorSampleMembers[2] = { dhkClassMember("refPosition", dhkClassMember::VECTOR4, false, 0),
																							dhkClassMember("refRotation", dhkClassMember::VECTOR4, false, 16)};
const dhkClassMember dhkClassLibrary410::hkMoppBvTreeShapeMembers[1] = { dhkClassMember("code", dhkClassMember::PTR_IGNORE, false, 16)};
const char* dhkClassLibrary410::hkMoppBvTreeShapeParents[1] = { "hkBvTreeShape" };
const dhkClassMember dhkClassLibrary410::hkBvTreeShapeMembers[1] = { dhkClassMember("child", dhkClassMember::CLASS, false, 12, "hkSingleShapeContainer")};
const char* dhkClassLibrary410::hkBvTreeShapeParents[1] = { "hkShape" };
const dhkClassMember dhkClassLibrary410::hkMoppCodeMembers[2] = { dhkClassMember("info", dhkClassMember::CLASS, false, 16, "hkMoppCodeCodeInfo"),
																	dhkClassMember("data", dhkClassMember::CLASS, true, 32, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary410::hkMoppCodeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkMoppCodeCodeInfoMembers[1] = { dhkClassMember("offset", dhkClassMember::VECTOR4, false, 0)};
const dhkClassMember dhkClassLibrary410::hkShapeCollectionMembers[1] = { dhkClassMember("disableWelding", dhkClassMember::BYTE, false, 16) };
const char* dhkClassLibrary410::hkShapeCollectionParents[2] = { "hkShape", "hkShapeContainer" };
const dhkClassMember dhkClassLibrary410::hkSimpleMeshShapeMembers[4] = { dhkClassMember("vertices", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::VECTOR4),
																		dhkClassMember("triangles", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::CLASS, "hkSimpleMeshShapeTriangle"),
																		dhkClassMember("materialIndices", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
																		dhkClassMember("radius", dhkClassMember::DWORD, false, 56) };
const char* dhkClassLibrary410::hkSimpleMeshShapeParents[1] = { "hkShapeCollection" };
const dhkClassMember dhkClassLibrary410::hkSimpleMeshShapeTriangleMembers[3] = { dhkClassMember("a", dhkClassMember::DWORD, false, 0),
																				 dhkClassMember("b", dhkClassMember::DWORD, false, 4),
																				 dhkClassMember("c", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkxAttributeGroupMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																			dhkClassMember("attributes", dhkClassMember::PTR_CLASS, true, 4, "hkxAttribute"),
																			dhkClassMember("numAttributes", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkxAttributeMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("value", dhkClassMember::CLASS, false, 4, "hkVariant")};
const dhkClassMember dhkClassLibrary410::hkxNodeMembers[12] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																dhkClassMember("object", dhkClassMember::CLASS, false, 4, "hkVariant"),
																dhkClassMember("keyFrames", dhkClassMember::PTR_MATRIX4, true, 12),
																dhkClassMember("numKeyFrames", dhkClassMember::DWORD, false, 16),
																dhkClassMember("children", dhkClassMember::PTR_IGNORE, true, 20),
																dhkClassMember("numChildren", dhkClassMember::DWORD, false, 24),
																dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 28, "hkxNodeAnnotationData"),
																dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 32),
																dhkClassMember("userProperties", dhkClassMember::PTR_IGNORE, false, 36),
																dhkClassMember("selected", dhkClassMember::BYTE, false, 40),
																dhkClassMember("attributeGroups", dhkClassMember::PTR_CLASS, true, 44, "hkxAttributeGroup"),
																dhkClassMember("numAttributeGroups", dhkClassMember::DWORD, false, 48)};
const dhkClassMember dhkClassLibrary410::hkxAnimatedFloatMembers[3] = { dhkClassMember("floats", dhkClassMember::PTR_DWORD, true, 0),
																		dhkClassMember("numFloats", dhkClassMember::DWORD, false, 4),
																		dhkClassMember("hint", dhkClassMember::BYTE, false, 8)};
const dhkClassMember dhkClassLibrary410::hkxSparselyAnimatedStringMembers[4] = { dhkClassMember("strings", dhkClassMember::PTR_IGNORE, true, 0),
																					dhkClassMember("numStrings", dhkClassMember::DWORD, false, 4),
																					dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																					dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary410::hkxSparselyAnimatedBoolMembers[4] = { dhkClassMember("bools", dhkClassMember::PTR_IGNORE, true, 0),
																				dhkClassMember("numBools", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary410::hkxSparselyAnimatedIntMembers[4] = { dhkClassMember("ints", dhkClassMember::PTR_DWORD, true, 0),
																				dhkClassMember("numInts", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary410::hkxMeshMembers[2] = { dhkClassMember("sections", dhkClassMember::PTR_IGNORE, true, 0),
																dhkClassMember("numSections", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary410::hkxMeshSectionMembers[4] = { dhkClassMember("vertexBuffer", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("indexBuffers", dhkClassMember::PTR_IGNORE, true, 4),
																		dhkClassMember("numIndexBuffers", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("material", dhkClassMember::PTR_IGNORE, false, 12)};
//const dhkClassMember dhkClassLibrary450::hkxMeshUserChannelInfoMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
//																				dhkClassMember("className", dhkClassMember::PTR_IGNORE, false, 12)};
//const char* dhkClassLibrary450::hkxMeshUserChannelInfoParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary410::hkxVertexBufferMembers[4] = { dhkClassMember("vertexDataClass", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("vertexData", dhkClassMember::PTR_HOMOGENEOUS, true, 4),
																		dhkClassMember("numVertexData", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("format", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary410::hkxVertexFormatMembers[12] = { dhkClassMember("stride", dhkClassMember::BYTE, false, 0),
																		dhkClassMember("positionOffset", dhkClassMember::BYTE, false, 1),
																		dhkClassMember("normalOffset", dhkClassMember::BYTE, false, 2),
																		dhkClassMember("tangentOffset", dhkClassMember::BYTE, false, 3),
																		dhkClassMember("binormalOffset", dhkClassMember::BYTE, false, 4),
																		dhkClassMember("numBonesPerVertex", dhkClassMember::BYTE, false, 5),
																		dhkClassMember("boneIndexOffset", dhkClassMember::BYTE, false, 6),
																		dhkClassMember("boneWeightOffset", dhkClassMember::BYTE, false, 7),
																		dhkClassMember("numTextureChannels", dhkClassMember::BYTE, false, 8),
																		dhkClassMember("tFloatCoordOffset", dhkClassMember::BYTE, false, 9),
																		dhkClassMember("tQuantizedCoordOffset", dhkClassMember::BYTE, false, 10),
																		dhkClassMember("colorOffset", dhkClassMember::BYTE, false, 11)};
const dhkClassMember dhkClassLibrary410::hkxIndexBufferMembers[7] = { dhkClassMember("indexType", dhkClassMember::BYTE, false, 0),
																		dhkClassMember("indices16", dhkClassMember::PTR_WORD, true, 4),
																		dhkClassMember("numIndices16", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("indices32", dhkClassMember::PTR_DWORD, true, 12),
																		dhkClassMember("numIndices32", dhkClassMember::DWORD, false, 16),
																		dhkClassMember("vertexBaseOffset", dhkClassMember::DWORD, false, 20),
																		dhkClassMember("length", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary410::hkxMaterialMembers[10] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("stages", dhkClassMember::PTR_CLASS, true, 4, "hkxMaterialTextureStage"),
																	dhkClassMember("numStages", dhkClassMember::DWORD, false, 8),
																	dhkClassMember("diffuseColor", dhkClassMember::VECTOR4, false, 16),
																	dhkClassMember("ambientColor", dhkClassMember::VECTOR4, false, 32),
																	dhkClassMember("specularColor", dhkClassMember::VECTOR4, false, 48),
																	dhkClassMember("emissiveColor", dhkClassMember::VECTOR4, false, 64),
																	dhkClassMember("subMaterials", dhkClassMember::PTR_IGNORE, true, 80),
																	dhkClassMember("numSubMaterials", dhkClassMember::DWORD, false, 84),
																	dhkClassMember("extraData", dhkClassMember::CLASS, false, 88, "hkVariant")};
const dhkClassMember dhkClassLibrary410::hkxTextureFileMembers[1] = { dhkClassMember("filename", dhkClassMember::PTR_IGNORE, false, 0)};
const dhkClassMember dhkClassLibrary410::hkxTextureInplaceMembers[3] = { dhkClassMember("fileType", dhkClassMember::BYTE, false, 0),
																			dhkClassMember("data", dhkClassMember::PTR_IGNORE, true, 4),
																			dhkClassMember("numData", dhkClassMember::DWORD, false, 8)};
//const dhkClassMember dhkClassLibrary450::hkxTriangleSelectionChannelMembers[2] = { dhkClassMember("selectedTriangles", dhkClassMember::PTR_DWORD, true, 0),
//																					dhkClassMember("numSelectedTriangles", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary410::hkxNodeAnnotationDataMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																				dhkClassMember("description", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary410::hkClassMembers[9] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 4),
																dhkClassMember("objectSize", dhkClassMember::DWORD, false, 8),
																dhkClassMember("numImplementedInterfaces", dhkClassMember::DWORD, false, 12),
																dhkClassMember("declaredEnums", dhkClassMember::PTR_CLASS, true, 16, "hkClassEnum"),
																dhkClassMember("numDeclaredEnums", dhkClassMember::DWORD, false, 20),
																dhkClassMember("declaredMembers", dhkClassMember::PTR_CLASS, true, 24, "hkClassMember"),
																dhkClassMember("numDeclaredMembers", dhkClassMember::DWORD, false, 28),
																dhkClassMember("defaults", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary410::hkClassEnumMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("items", dhkClassMember::PTR_CLASS, true, 4, "hkClassEnumItem"),
																	dhkClassMember("numItems", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkClassEnumItemMembers[2] = { dhkClassMember("value", dhkClassMember::DWORD, false, 0),
																		dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary410::hkClassMemberMembers[8] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4),
																	dhkClassMember("enum", dhkClassMember::PTR_IGNORE, false, 8),
																	dhkClassMember("type", dhkClassMember::BYTE, false, 12),
																	dhkClassMember("subtype", dhkClassMember::BYTE, false, 13),
																	dhkClassMember("cArraySize", dhkClassMember::WORD, false, 14),
																	dhkClassMember("flags", dhkClassMember::WORD, false, 16),
																	dhkClassMember("offset", dhkClassMember::WORD, false, 18)};
const dhkClassMember dhkClassLibrary410::hkxMaterialTextureStageMembers[2] = { dhkClassMember("texture", dhkClassMember::CLASS, false, 0, "hkVariant"),
																				dhkClassMember("usageHint", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary410::hkxVertexP4N4T4B4W4I4Q4Members[10] = { dhkClassMember("position", dhkClassMember::VECTOR4, false, 0),
																				dhkClassMember("normal", dhkClassMember::VECTOR4, false, 16),
																				dhkClassMember("tangent", dhkClassMember::VECTOR4, false, 32),
																				dhkClassMember("binormal", dhkClassMember::VECTOR4, false, 48),
																				dhkClassMember("weights", dhkClassMember::DWORD, false, 64),
																				dhkClassMember("indices", dhkClassMember::DWORD, false, 68),
																				dhkClassMember("qu0_0", dhkClassMember::WORD, false, 72),
																				dhkClassMember("qu0_1", dhkClassMember::WORD, false, 74),
																				dhkClassMember("qu1_0", dhkClassMember::WORD, false, 76),
																				dhkClassMember("qu1_1", dhkClassMember::WORD, false, 78)};
const dhkClassMember dhkClassLibrary410::hkxVertexP4N4C1T2Members[6] = { dhkClassMember("position", dhkClassMember::VECTOR4, false, 0),
																		dhkClassMember("normal", dhkClassMember::VECTOR4, false, 16),
																		dhkClassMember("diffuse", dhkClassMember::DWORD, false, 32),
																		dhkClassMember("u", dhkClassMember::DWORD, false, 36),
																		dhkClassMember("v", dhkClassMember::DWORD, false, 40),
																		dhkClassMember("padding", dhkClassMember::DWORD, false, 44)};
const char* dhkClassLibrary410::hkSphereRepShapeParents[1] = { "hkShape" };
const dhkClassMember dhkClassLibrary410::hkConvexShapeMembers[1] = { dhkClassMember("radius", dhkClassMember::DWORD, false, 12) };
const char* dhkClassLibrary410::hkConvexShapeParents[1] = { "hkSphereRepShape" };
const dhkClassMember dhkClassLibrary410::hkConvexVerticesShapeFourVectorsMembers[3] = { dhkClassMember("x", dhkClassMember::VECTOR4, false, 0),
																					dhkClassMember("y", dhkClassMember::VECTOR4, false, 16),
																					dhkClassMember("z", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary410::hkConvexVerticesShapeMembers[5] = { dhkClassMember("aabbHalfExtents", dhkClassMember::VECTOR4, false, 16),
																			dhkClassMember("aabbCenter", dhkClassMember::VECTOR4, false, 32),
																			dhkClassMember("rotatedVertices", dhkClassMember::CLASS, true, 48, "hkArray", dhkClassMember::CLASS, "hkConvexVerticesShapeFourVectors"),
																			dhkClassMember("numVertices", dhkClassMember::DWORD, false, 60),
																			dhkClassMember("planeEquations", dhkClassMember::CLASS, true, 64, "hkArray", dhkClassMember::VECTOR4)};
const char* dhkClassLibrary410::hkConvexVerticesShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary410::hkBoxShapeMembers[1] = { dhkClassMember("halfExtents", dhkClassMember::VECTOR4, false, 16)};
const char* dhkClassLibrary410::hkBoxShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary410::hkConstraintInstanceMembers[10] = { dhkClassMember("owner", dhkClassMember::PTR_IGNORE, false, 8), //hkConstraintOwner
														dhkClassMember("data", dhkClassMember::PTR_IGNORE, false, 12),	//hkConstraintData
														dhkClassMember("constraintModifiers", dhkClassMember::PTR_IGNORE, false, 16), //hkModifierConstraintAtom
														dhkClassMember("entities_0", dhkClassMember::PTR_IGNORE, false, 20), //hkEntity
														dhkClassMember("entities_1", dhkClassMember::PTR_IGNORE, false, 24),
														dhkClassMember("priority", dhkClassMember::BYTE, false, 28),
														dhkClassMember("wantRuntime", dhkClassMember::BYTE, false, 29),
														dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 32),
														dhkClassMember("userData", dhkClassMember::DWORD, false, 36),
														dhkClassMember("internal", dhkClassMember::PTR_IGNORE, false, 40)}; 
const char* dhkClassLibrary410::hkConstraintInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkConstraintAtomMembers[1] = { dhkClassMember("type", dhkClassMember::WORD, false, 0) };
const dhkClassMember dhkClassLibrary410::hkBallAndSocketConstraintDataAtomsMembers[2] = { dhkClassMember("pivots", dhkClassMember::CLASS, false, 0, "hkSetLocalTranslationsConstraintAtom"),
																						dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 48, "hkBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary410::hkBallAndSocketConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkBallAndSocketConstraintDataAtoms")};
const char* dhkClassLibrary410::hkBallAndSocketConstraintDataParents[1] = { "hkConstraintData" };
const dhkClassMember dhkClassLibrary410::hkSetLocalTranslationsConstraintAtomMembers[2] = { dhkClassMember("translationA", dhkClassMember::VECTOR4, false, 16),
																							dhkClassMember("translationB", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary410::hkSetLocalTranslationsConstraintAtomParents[1] = { "hkConstraintAtom" };
const char* dhkClassLibrary410::hkBallSocketConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary410::hkConstraintDataMembers[1] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary410::hkConstraintDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary410::hkConvexTranslateShapeMembers[2] = { dhkClassMember("childShape", dhkClassMember::CLASS, false, 16, "hkSingleShapeContainer"),
																				dhkClassMember("translation", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary410::hkConvexTranslateShapeParents[1] = { "hkConvexShape" };

dhkClassLibrary410::dhkClassLibrary410(void)
{
	m_classMap.insert(make_pair("hkRootLevelContainerNamedVariant", dhkClass("hkRootLevelContainerNamedVariant", NULL, 0, 16, hkRootLevelContainerNamedVariantMembers, 3)));
	m_classMap.insert(make_pair("hkRootLevelContainer", dhkClass("hkRootLevelContainer", NULL, 0, 16, hkRootLevelContainerMembers, 2)));
	m_classMap.insert(make_pair("hkVariant", dhkClass("hkVariant", NULL, 0, 8, hkVariantMembers, 2)));
	m_classMap.insert(make_pair("hkArray", dhkClass("hkArray", NULL, 0, 12, hkArrayMembers, 3)));
	m_classMap.insert(make_pair("hkSmallArray", dhkClass("hkSmallArray", NULL, 0, 8, hkSmallArrayMembers, 3)));
	m_classMap.insert(make_pair("hkAnimationContainer", dhkClass("hkAnimationContainer", NULL, 0, 40, hkAnimationContainerMembers, 10)));
	m_classMap.insert(make_pair("hkReferencedObject", dhkClass("hkReferencedObject", NULL, 0, 8, hkReferencedObjectMembers, 2)));
	m_classMap.insert(make_pair("hkSkeletalAnimation", dhkClass("hkSkeletalAnimation", hkSkeletalAnimationParents, 1, 0x20, hkSkeletalAnimationMembers, 6)));
	m_classMap.insert(make_pair("hkWaveletSkeletalAnimation", dhkClass("hkWaveletSkeletalAnimation", hkWaveletSkeletalAnimationParents, 1, 92, hkWaveletSkeletalAnimationMembers, 11)));
	m_classMap.insert(make_pair("hkWaveletSkeletalAnimationQuantizationFormat", dhkClass("hkWaveletSkeletalAnimationQuantizationFormat", NULL, 0, 20, hkWaveletSkeletalAnimationQuantizationFormatMembers, 6)));
	m_classMap.insert(make_pair("hkDefaultAnimatedReferenceFrame", dhkClass("hkDefaultAnimatedReferenceFrame", hkDefaultAnimatedReferenceFrameMembersParents, 1, 0x40, hkDefaultAnimatedReferenceFrameMembers, 5)));
	//m_classMap550.insert(make_pair("hkVector4", new dhkClass("hkVector4", NULL, 0, 16, hkVector4Members, 4)));
	m_classMap.insert(make_pair("hkAnnotationTrack", dhkClass("hkAnnotationTrack", NULL, 0, 16, hkAnnotationTrackMembers, 3)));
	m_classMap.insert(make_pair("hkAnnotationTrackAnnotation", dhkClass("hkAnnotationTrackAnnotation", NULL, 0, 16, hkAnnotationTrackAnnotationMembers, 2)));
	m_classMap.insert(make_pair("hkDeltaCompressedSkeletalAnimation", dhkClass("hkDeltaCompressedSkeletalAnimation", hkDeltaCompressedSkeletalAnimationParents, 1, 100, hkDeltaCompressedSkeletalAnimationMembers, 13)));
	m_classMap.insert(make_pair("hkAnimationBinding", dhkClass("hkAnimationBinding", NULL, 0, 0x10, hkAnimationBindingMembers, 4)));
	m_classMap.insert(make_pair("hkxScene", dhkClass("hkxScene", NULL, 0, 0x80, hkxSceneMembers, 19)));
	//m_classMap550.insert(make_pair("hkMatrix3", new dhkClass("hkMatrix3", NULL, 0, 0x30, hkMatrix3Members, 3)));
	m_classMap.insert(make_pair("hkSkeleton", dhkClass("hkSkeleton", NULL, 0, 0x1C, hkSkeletonMembers, 7)));
	m_classMap.insert(make_pair("hkQsTransform", dhkClass("hkQsTransform", NULL, 0, 0x30, hkQsTransformMembers, 3)));
	m_classMap.insert(make_pair("hkBone", dhkClass("hkaBone", NULL, 0, 16, hkBoneMembers, 2)));
	m_classMap.insert(make_pair("hkPhysicsData", dhkClass("hkPhysicsData", hkPhysicsDataParents, 1, 24, hkPhysicsDataMembers, 2)));
	m_classMap.insert(make_pair("hkPhysicsSystem", dhkClass("hkPhysicsSystem", hkPhysicsSystemParents, 1, 68, hkPhysicsSystemMembers, 7)));
	m_classMap.insert(make_pair("hkCdBody", dhkClass("hkCdBody", NULL, 0, 16, hkCdBodyMembers, 4)));
	m_classMap.insert(make_pair("hkBroadPhaseHandle", dhkClass("hkBroadPhaseHandle", NULL, 0, 4, hkBroadPhaseHandleMembers, 1)));
	m_classMap.insert(make_pair("hkTypedBroadPhaseHandle", dhkClass("hkTypedBroadPhaseHandle", hkTypedBroadPhaseHandleParents, 1, 12, hkTypedBroadPhaseHandleMembers, 4)));
	m_classMap.insert(make_pair("hkCollidable", dhkClass("hkCollidable", hkCollidableParents, 1, 36, hkCollidableMembers, 3)));
	m_classMap.insert(make_pair("hkLinkedCollidable", dhkClass("hkLinkedCollidable", hkLinkedCollidableParents, 1, 42, hkLinkedCollidableMembers, 1)));
	m_classMap.insert(make_pair("hkMultiThreadLock", dhkClass("hkMultiThreadLock", NULL, 0, 8, hkMultiThreadLockMembers, 3)));
	m_classMap.insert(make_pair("hkPropertyValue", dhkClass("hkPropertyValue", NULL, 0, 8, hkPropertyValueMembers, 1)));
	m_classMap.insert(make_pair("hkProperty", dhkClass("hkProperty", NULL, 0, 16, hkPropertyMembers, 3)));
	m_classMap.insert(make_pair("hkMaterial", dhkClass("hkMaterial", NULL, 0, 12, hkMaterialMembers, 3)));
	m_classMap.insert(make_pair("hkWorldObject", dhkClass("hkWorldObject", hkWorldObjectParents, 1, 88, hkWorldObjectMembers, 6)));
	m_classMap.insert(make_pair("hkTransform", dhkClass("hkTransform", NULL, 0, 64, hkTransformMembers, 2)));
	m_classMap.insert(make_pair("hkSweptTransform", dhkClass("hkSweptTransform", NULL, 0, 80, hkSweptTransformMembers, 5)));
	m_classMap.insert(make_pair("hkMotionState", dhkClass("hkMotionState", NULL, 0, 188, hkMotionStateMembers, 11)));
	m_classMap.insert(make_pair("hkMotion", dhkClass("hkMotion", hkMotionParents, 1, 288, hkMotionMembers, 10)));
	m_classMap.insert(make_pair("hkKeyframedRigidMotion", dhkClass("hkKeyframedRigidMotion", hkKeyframedRigidMotionParents, 1, 296, hkKeyframedRigidMotionMembers, 2)));
	m_classMap.insert(make_pair("hkMaxSizeMotion", dhkClass("hkMaxSizeMotion", hkMaxSizeMotionParents, 1, 296, NULL, 0)));
	//m_classMap.insert(make_pair("hkEntitySpuCollisionCallback", dhkClass("hkEntitySpuCollisionCallback", NULL, 0, 8, hkEntitySpuCollisionCallbackMembers, 4)));
	m_classMap.insert(make_pair("hkEntity", dhkClass("hkEntity", hkEntityParents, 1, 504, hkEntityMembers, 16)));
	m_classMap.insert(make_pair("hkRigidBody", dhkClass("hkRigidBody", hkRigidBodyParents, 1, 504, NULL, 0)));
	m_classMap.insert(make_pair("hkShape", dhkClass("hkShape", hkShapeParents, 1, 12, hkShapeMembers, 1)));
	m_classMap.insert(make_pair("hkSingleShapeContainer", dhkClass("hkSingleShapeContainer", hkSingleShapeContainerParents, 1, 4, hkSingleShapeContainerMembers, 1)));
	m_classMap.insert(make_pair("hkShapeContainer", dhkClass("hkShapeContainer", NULL, 0, 0, NULL, 0)));
	m_classMap.insert(make_pair("hkEntityDeactivator", dhkClass("hkEntityDeactivator", hkEntityDeactivatorParents, 1, 8, NULL, 0)));
	m_classMap.insert(make_pair("hkRigidBodyDeactivator", dhkClass("hkRigidBodyDeactivator", hkRigidBodyDeactivatorParents, 1, 8, NULL, 0)));
	m_classMap.insert(make_pair("hkSpatialRigidBodyDeactivator", dhkClass("hkSpatialRigidBodyDeactivator", hkSpatialRigidBodyDeactivatorParents, 1, 100, hkSpatialRigidBodyDeactivatorMembers, 7)));
	m_classMap.insert(make_pair("hkSpatialRigidBodyDeactivatorSample", dhkClass("hkSpatialRigidBodyDeactivatorSample", NULL, 0, 32, hkSpatialRigidBodyDeactivatorSampleMembers, 2)));
	m_classMap.insert(make_pair("hkMoppBvTreeShape", dhkClass("hkMoppBvTreeShape", hkMoppBvTreeShapeParents, 1, 20, hkMoppBvTreeShapeMembers, 1)));
	m_classMap.insert(make_pair("hkBvTreeShape", dhkClass("hkBvTreeShape", hkBvTreeShapeParents, 1, 16, hkBvTreeShapeMembers, 1)));
	m_classMap.insert(make_pair("hkMoppCode", dhkClass("hkMoppCode", hkMoppCodeParents, 1, 44, hkMoppCodeMembers, 2)));
	m_classMap.insert(make_pair("hkMoppCodeCodeInfo", dhkClass("hkMoppCodeCodeInfo", NULL, 0, 16, hkMoppCodeCodeInfoMembers, 1)));
	m_classMap.insert(make_pair("hkShapeCollection", dhkClass("hkShapeCollection", hkShapeCollectionParents, 2, 20, hkShapeCollectionMembers, 1)));
	m_classMap.insert(make_pair("hkSimpleMeshShape", dhkClass("hkSimpleMeshShape", hkSimpleMeshShapeParents, 1, 60, hkSimpleMeshShapeMembers, 4)));
	m_classMap.insert(make_pair("hkSimpleMeshShapeTriangle", dhkClass("hkSimpleMeshShapeTriangle", NULL, 0, 12, hkSimpleMeshShapeTriangleMembers, 3)));
	m_classMap.insert(make_pair("hkxAttributeGroup", dhkClass("hkxAttributeGroup", NULL, 0, 12, hkxAttributeGroupMembers, 3)));
	m_classMap.insert(make_pair("hkxAttribute", dhkClass("hkxAttribute", NULL, 0, 12, hkxAttributeMembers, 2)));
	m_classMap.insert(make_pair("hkxNode", dhkClass("hkxNode", NULL, 0, 52, hkxNodeMembers, 12)));
	m_classMap.insert(make_pair("hkxAnimatedFloat", dhkClass("hkxAnimatedFloat", NULL, 0, 12, hkxAnimatedFloatMembers, 3)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedString", dhkClass("hkxSparselyAnimatedString", NULL, 0, 16, hkxSparselyAnimatedStringMembers, 4)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedBool", dhkClass("hkxSparselyAnimatedBool", NULL, 0, 16, hkxSparselyAnimatedBoolMembers, 4)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedInt", dhkClass("hkxSparselyAnimatedInt", NULL, 0, 16, hkxSparselyAnimatedIntMembers, 4)));
	m_classMap.insert(make_pair("hkxMesh", dhkClass("hkxMesh", NULL, 0, 8, hkxMeshMembers, 2)));
	m_classMap.insert(make_pair("hkxMeshSection", dhkClass("hkxMeshSection", NULL, 0, 16, hkxMeshSectionMembers, 4)));
	m_classMap.insert(make_pair("hkxVertexBuffer", dhkClass("hkxVertexBuffer", NULL, 0, 16, hkxVertexBufferMembers, 4)));
	m_classMap.insert(make_pair("hkxVertexFormat", dhkClass("hkxVertexFormat", NULL, 0, 12, hkxVertexFormatMembers, 12)));
	m_classMap.insert(make_pair("hkxIndexBuffer", dhkClass("hkxIndexBuffer", NULL, 0, 28, hkxIndexBufferMembers, 7)));
	m_classMap.insert(make_pair("hkxMaterial", dhkClass("hkxMaterial", NULL, 0, 96, hkxMaterialMembers, 10)));
	m_classMap.insert(make_pair("hkxTextureFile", dhkClass("hkxTextureFile", NULL, 0, 4, hkxTextureFileMembers, 1)));
	m_classMap.insert(make_pair("hkxTextureInplace", dhkClass("hkxTextureInplace", NULL, 0, 12, hkxTextureInplaceMembers, 3)));
	m_classMap.insert(make_pair("hkxNodeAnnotationData", dhkClass("hkxNodeAnnotationData", NULL, 0, 8, hkxNodeAnnotationDataMembers, 2)));
	m_classMap.insert(make_pair("hkClass", dhkClass("hkClass", NULL, 0, 36, hkClassMembers, 9)));
	m_classMap.insert(make_pair("hkClassEnum", dhkClass("hkClassEnum", NULL, 0, 12, hkClassEnumMembers, 3)));
	m_classMap.insert(make_pair("hkClassEnumItem", dhkClass("hkClassEnumItem", NULL, 0, 8, hkClassEnumItemMembers, 2)));
	m_classMap.insert(make_pair("hkClassMember", dhkClass("hkClassMember", NULL, 0, 20, hkClassMemberMembers, 8)));
	m_classMap.insert(make_pair("hkxMaterialTextureStage", dhkClass("hkxMaterialTextureStage", NULL, 0, 12, hkxMaterialTextureStageMembers, 2)));
	m_classMap.insert(make_pair("hkxVertexP4N4T4B4W4I4Q4", dhkClass("hkxVertexP4N4T4B4W4I4Q4", NULL, 0, 80, hkxVertexP4N4T4B4W4I4Q4Members, 10)));
	m_classMap.insert(make_pair("hkxVertexP4N4C1T2", dhkClass("hkxVertexP4N4C1T2", NULL, 0, 48,	hkxVertexP4N4C1T2Members, 6)));
	m_classMap.insert(make_pair("hkSphereRepShape", dhkClass("hkSphereRepShape", hkSphereRepShapeParents, 1, 12, NULL, 0)));
	m_classMap.insert(make_pair("hkConvexShape", dhkClass("hkConvexShape", hkConvexShapeParents, 1, 16, hkConvexShapeMembers, 1)));
	m_classMap.insert(make_pair("hkConvexVerticesShapeFourVectors", dhkClass("hkConvexVerticesShapeFourVectors", NULL, 0, 48, hkConvexVerticesShapeFourVectorsMembers, 3)));
	m_classMap.insert(make_pair("hkConvexVerticesShape", dhkClass("hkConvexVerticesShape", hkConvexVerticesShapeParents, 1, 76, hkConvexVerticesShapeMembers, 5)));
	m_classMap.insert(make_pair("hkBoxShape", dhkClass("hkBoxShape", hkBoxShapeParents, 1, 32, hkBoxShapeMembers, 1)));
	m_classMap.insert(make_pair("hkBallAndSocketConstraintData", dhkClass("hkBallAndSocketConstraintData", hkBallAndSocketConstraintDataParents, 1, 68, hkBallAndSocketConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkBallAndSocketConstraintDataAtoms", dhkClass("hkBallAndSocketConstraintDataAtoms", NULL, 0, 52, hkBallAndSocketConstraintDataAtomsMembers, 2)));
	m_classMap.insert(make_pair("hkSetLocalTranslationsConstraintAtom", dhkClass("hkSetLocalTranslationsConstraintAtom", hkSetLocalTranslationsConstraintAtomParents, 1, 48, hkSetLocalTranslationsConstraintAtomMembers, 2)));
	m_classMap.insert(make_pair("hkBallSocketConstraintAtom", dhkClass("hkBallSocketConstraintAtom", hkBallSocketConstraintAtomParents, 1, 4, NULL, 0)));
	m_classMap.insert(make_pair("hkConstraintInstance", dhkClass("hkConstraintInstance", hkConstraintInstanceParents, 1, 44, hkConstraintInstanceMembers, 10)));
	m_classMap.insert(make_pair("hkConstraintAtom", dhkClass("hkConstraintAtom", NULL, 0, 4, hkConstraintAtomMembers, 1)));
	m_classMap.insert(make_pair("hkConstraintData", dhkClass("hkConstraintData", hkConstraintDataParents, 1, 12, hkConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkConvexTranslateShape", dhkClass("hkConvexTranslateShape", hkConvexTranslateShapeParents, 1, 48, hkConvexTranslateShapeMembers, 2)));
}


dhkClassLibrary410::~dhkClassLibrary410(void)
{
}

dhkClass* dhkClassLibrary410::getClass(const char* className) {
	try {
		return &m_classMap.at(className);
	} catch (const out_of_range& e) {
		printf("Couldn't find class %s in library!\n", className);
		return 0;
	}
}
