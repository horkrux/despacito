#include "dhkClassLibrary450.h"

const dhkClassMember dhkClassLibrary450::hkRootLevelContainerNamedVariantMembers[] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0), 
																		 dhkClassMember("className", dhkClassMember::PTR_IGNORE, true, 4), 
																		 dhkClassMember("variant", dhkClassMember::CLASS, false, 8, "hkVariant") };
const dhkClassMember dhkClassLibrary450::hkRootLevelContainerMembers[2] = { dhkClassMember("namedVariants", dhkClassMember::PTR_CLASS, true, 0, "hkRootLevelContainerNamedVariant"),
															 dhkClassMember("numNamedVariants", dhkClassMember::DWORD, false, 4) };
const dhkClassMember dhkClassLibrary450::hkVariantMembers[2] = { dhkClassMember("object", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary450::hkArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0), 
												dhkClassMember("size", dhkClassMember::DWORD, false, 4), 
												dhkClassMember("capacityAndFlags", dhkClassMember::DWORD, false, 8) };
const dhkClassMember dhkClassLibrary450::hkSmallArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0),
											dhkClassMember("size", dhkClassMember::WORD, false, 4), //uh oh
											dhkClassMember("capacityAndFlags", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary450::hkAnimationContainerMembers[10] = { dhkClassMember("skeletons", dhkClassMember::PTR_IGNORE, true, 0), 
															   dhkClassMember("numSkeletons", dhkClassMember::DWORD, false, 4), 
															   dhkClassMember("animations", dhkClassMember::PTR_IGNORE, true, 8),
															   dhkClassMember("numAnimations", dhkClassMember::DWORD, false, 12),
															   dhkClassMember("bindings", dhkClassMember::PTR_IGNORE, true, 16),
															   dhkClassMember("numBindings", dhkClassMember::DWORD, false, 20),
															   dhkClassMember("attachments", dhkClassMember::PTR_IGNORE, true, 24),
															   dhkClassMember("numAttachments", dhkClassMember::DWORD, false, 28),
															   dhkClassMember("skins", dhkClassMember::PTR_IGNORE, true, 32),
															   dhkClassMember("numSkins", dhkClassMember::DWORD, false, 36)};
const dhkClassMember dhkClassLibrary450::hkReferencedObjectMembers[2] = { dhkClassMember("memSizeAndFlags", dhkClassMember::WORD, false, 4),
														   dhkClassMember("referenceCount", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary450::hkSkeletalAnimationMembers[6] = { dhkClassMember("type", dhkClassMember::DWORD, false, 8),
															 dhkClassMember("duration", dhkClassMember::DWORD, false, 12),
															 dhkClassMember("numberOfTracks", dhkClassMember::DWORD, false, 16),
															 dhkClassMember("extractedMotion", dhkClassMember::PTR_CLASS, false, 20), //not sure
															 dhkClassMember("annotationTracks", dhkClassMember::PTR_IGNORE, true, 24),
															 dhkClassMember("numAnnotationTracks", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary450::hkSkeletalAnimationParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkWaveletSkeletalAnimationMembers[11] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
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
const char* dhkClassLibrary450::hkWaveletSkeletalAnimationParents[1] = { "hkSkeletalAnimation" };
const dhkClassMember dhkClassLibrary450::hkWaveletSkeletalAnimationQuantizationFormatMembers[6] = { dhkClassMember("maxBitWidth", dhkClassMember::BYTE, false, 0),
																					 dhkClassMember("preserved", dhkClassMember::BYTE, false, 1),
																					 dhkClassMember("numD", dhkClassMember::DWORD, false, 4),
																					 dhkClassMember("offsetIdx", dhkClassMember::DWORD, false, 8),
																					 dhkClassMember("scaleIdx", dhkClassMember::DWORD, false, 12),
																					 dhkClassMember("bitWidthIdx", dhkClassMember::DWORD, false, 16)};
const dhkClassMember dhkClassLibrary450::hkInterleavedSkeletalAnimationMembers[2] = { dhkClassMember("transforms", dhkClassMember::PTR_CLASS, true, 32, "hkQsTransform"),
																						dhkClassMember("numTransforms", dhkClassMember::DWORD, false, 36)};
const char* dhkClassLibrary450::hkInterleavedSkeletalAnimationParents[1] = { "hkSkeletalAnimation" };
const dhkClassMember dhkClassLibrary450::hkDefaultAnimatedReferenceFrameMembers[5] = { dhkClassMember("up", dhkClassMember::VECTOR4, false, 16),
																		 dhkClassMember("forward", dhkClassMember::VECTOR4, false, 32),
																		 dhkClassMember("duration", dhkClassMember::DWORD, false, 48),
																		 dhkClassMember("referenceFrameSamples", dhkClassMember::PTR_VECTOR4, true, 52),
																		 dhkClassMember("numReferenceFrameSamples", dhkClassMember::DWORD, false, 56)};
const char* dhkClassLibrary450::hkDefaultAnimatedReferenceFrameMembersParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkAnnotationTrackMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
														   dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 4, "hkAnnotationTrackAnnotation"),
														   dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkAnnotationTrackAnnotationMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																	 dhkClassMember("text", dhkClassMember::PTR_IGNORE, true, 4)};
const dhkClassMember dhkClassLibrary450::hkDeltaCompressedSkeletalAnimationMembers[13] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
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
const char* dhkClassLibrary450::hkDeltaCompressedSkeletalAnimationParents[] = { "hkSkeletalAnimation" };
const dhkClassMember dhkClassLibrary450::hkAnimationBindingMembers[4] = { dhkClassMember("animation", dhkClassMember::PTR_IGNORE, false, 0),
															dhkClassMember("animationTrackToBoneIndices", dhkClassMember::PTR_WORD, true, 4),
															dhkClassMember("numAnimationTrackToBoneIndices", dhkClassMember::DWORD, false, 8),
															dhkClassMember("blendHint", dhkClassMember::BYTE, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxSceneMembers[19] = { dhkClassMember("modeller", dhkClassMember::PTR_IGNORE, true, 0),
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
const dhkClassMember dhkClassLibrary450::hkSkeletonMembers[7] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
												dhkClassMember("parentIndices", dhkClassMember::PTR_WORD, true, 4),
												dhkClassMember("numParentIndices", dhkClassMember::DWORD, false, 8),
												dhkClassMember("bones", dhkClassMember::PTR_IGNORE, true, 12),
												dhkClassMember("numBones", dhkClassMember::DWORD, false, 16),
												dhkClassMember("referencePose", dhkClassMember::PTR_CLASS, true, 20, "hkQsTransform"),
												dhkClassMember("numReferencePose", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary450::hkQsTransformMembers[3] = { dhkClassMember("translation", dhkClassMember::VECTOR4, false, 0),
													dhkClassMember("rotation", dhkClassMember::VECTOR4, false, 16),
													dhkClassMember("scale", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary450::hkBoneMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
											dhkClassMember("lockTranslation", dhkClassMember::BYTE, false, 4)};
const dhkClassMember dhkClassLibrary450::hkPhysicsDataMembers[2] = { dhkClassMember("worldCinfo", dhkClassMember::PTR_IGNORE, false, 8),
											dhkClassMember("systems", dhkClassMember::CLASS, false, 12, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary450::hkPhysicsDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkPhysicsSystemMembers[7] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("actions", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("phantoms", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 56),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 60),
													dhkClassMember("active", dhkClassMember::BYTE, false, 64)};
const char* dhkClassLibrary450::hkPhysicsSystemParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkCdBodyMembers[4] = { dhkClassMember("shape", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("shapeKey", dhkClassMember::DWORD, false, 4),
												dhkClassMember("motion", dhkClassMember::PTR_IGNORE, false, 8),
												dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary450::hkBroadPhaseHandleMembers[1] = { dhkClassMember("id", dhkClassMember::DWORD, false, 0)};
const dhkClassMember dhkClassLibrary450::hkTypedBroadPhaseHandleMembers[4] = { dhkClassMember("type", dhkClassMember::BYTE, false, 4),
															dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 5),
															dhkClassMember("objectQualityType", dhkClassMember::WORD, false, 6),
															dhkClassMember("collisionFilterInfo", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary450::hkTypedBroadPhaseHandleParents[1] = { "hkBroadPhaseHandle" };
const char* dhkClassLibrary450::hkCollidableParents[1] = { "hkCdBody" };
const dhkClassMember dhkClassLibrary450::hkCollidableMembers[5] = { dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 16),
													dhkClassMember("forceCollideOntoPpu", dhkClassMember::BYTE, false, 17),
													dhkClassMember("shapeSizeOnSpu", dhkClassMember::WORD, false, 18),
													dhkClassMember("broadPhaseHandle", dhkClassMember::CLASS, false, 20, "hkTypedBroadPhaseHandle"),
													dhkClassMember("allowedPenetrationDepth", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary450::hkLinkedCollidableMembers[1] = { dhkClassMember("collisionEntries", dhkClassMember::CLASS, false, 36, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary450::hkLinkedCollidableParents[1] = { "hkCollidable" };
const dhkClassMember dhkClassLibrary450::hkMultiThreadLockMembers[3] = { dhkClassMember("threadId", dhkClassMember::DWORD, false, 0),
													dhkClassMember("lockCount", dhkClassMember::WORD, false, 4),
													dhkClassMember("lockBitStack", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary450::hkPropertyValueMembers[1] = { dhkClassMember("data", dhkClassMember::QWORD, false, 0)};
const dhkClassMember dhkClassLibrary450::hkPropertyMembers[3] = { dhkClassMember("key", dhkClassMember::DWORD, false, 0),
												dhkClassMember("alignmentPadding", dhkClassMember::DWORD, false, 4),
												dhkClassMember("value", dhkClassMember::CLASS, false, 8, "hkPropertyValue")};
const dhkClassMember dhkClassLibrary450::hkMaterialMembers[3] = { dhkClassMember("responseType", dhkClassMember::BYTE, false, 0),
												dhkClassMember("friction", dhkClassMember::DWORD, false, 4),
												dhkClassMember("restitution", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkWorldObjectMembers[6] = { dhkClassMember("world", dhkClassMember::PTR_IGNORE, false, 8),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 12),
													dhkClassMember("collidable", dhkClassMember::CLASS, false, 16, "hkLinkedCollidable"),
													dhkClassMember("multithreadLock", dhkClassMember::CLASS, false, 64, "hkMultiThreadLock"),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 72),
													dhkClassMember("properties", dhkClassMember::CLASS, false, 76, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary450::hkWorldObjectParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkTransformMembers[2] = { dhkClassMember("rotation", dhkClassMember::MATRIX3, false, 0),
												dhkClassMember("translation", dhkClassMember::VECTOR4, false, 48)};
const dhkClassMember dhkClassLibrary450::hkSweptTransformMembers[5] = { dhkClassMember("centerOfMass0", dhkClassMember::VECTOR4, false, 0),
											dhkClassMember("centerOfMass1", dhkClassMember::VECTOR4, false, 16),
											dhkClassMember("rotation0", dhkClassMember::VECTOR4, false, 32),
											dhkClassMember("rotation1", dhkClassMember::VECTOR4, false, 48),
											dhkClassMember("centerOfMassLocal", dhkClassMember::VECTOR4, false, 64)};
const dhkClassMember dhkClassLibrary450::hkMotionStateMembers[11] = { dhkClassMember("transform", dhkClassMember::CLASS, false, 0, "hkTransform"),
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

const dhkClassMember dhkClassLibrary450::hkMotionMembers[10] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8),
												dhkClassMember("deactivationIntegrateCounter", dhkClassMember::BYTE, false, 9),
												dhkClassMember("deactivationNumInactiveFrames_0", dhkClassMember::WORD, false, 10),
												dhkClassMember("deactivationNumInactiveFrames_1", dhkClassMember::WORD, false, 12),
												dhkClassMember("motionState", dhkClassMember::CLASS, false, 16, "hkMotionState"),
												dhkClassMember("inertiaAndMassInv", dhkClassMember::VECTOR4, false, 208),
												dhkClassMember("linearVelocity", dhkClassMember::VECTOR4, false, 224),
												dhkClassMember("angularVelocity", dhkClassMember::VECTOR4, false, 240),
												dhkClassMember("deactivationRefPosition_0", dhkClassMember::VECTOR4, false, 256),
												dhkClassMember("deactivationRefPosition_1", dhkClassMember::VECTOR4, false, 272)};
const char* dhkClassLibrary450::hkMotionParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkKeyframedRigidMotionMembers[2] = { dhkClassMember("savedMotion", dhkClassMember::PTR_IGNORE, false, 288),
																			dhkClassMember("savedQualityTypeIndex", dhkClassMember::DWORD, false, 292)};
const char* dhkClassLibrary450::hkKeyframedRigidMotionParents[1] = { "hkMotion" };
const char* dhkClassLibrary450::hkMaxSizeMotionParents[1] = { "hkKeyframedRigidMotion" };
const dhkClassMember dhkClassLibrary450::hkEntitySpuCollisionCallbackMembers[4] = { dhkClassMember("util", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("capacity", dhkClassMember::WORD, false, 4),
																	dhkClassMember("eventFilter", dhkClassMember::BYTE, false, 6),
																	dhkClassMember("userFilter", dhkClassMember::BYTE, false, 7)};
const char* dhkClassLibrary450::hkEntityParents[1] = { "hkWorldObject" };
const dhkClassMember dhkClassLibrary450::hkEntityMembers[15] = { dhkClassMember("material", dhkClassMember::CLASS, false, 88, "hkMaterial"),
											dhkClassMember("solverData", dhkClassMember::DWORD, false, 100),
											dhkClassMember("storageIndex", dhkClassMember::WORD, false, 104),
											dhkClassMember("processContactCallbackDelay", dhkClassMember::WORD, false, 106),
											dhkClassMember("constraintsMaster", dhkClassMember::CLASS, false, 108, "hkSmallArray", dhkClassMember::PTR_IGNORE), //hkConstraintInternal
											dhkClassMember("constraintsSlave", dhkClassMember::CLASS, false, 116, "hkArray", dhkClassMember::PTR_IGNORE), //hkConstraintInstance
											dhkClassMember("constraintRuntime", dhkClassMember::CLASS, false, 128, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("deactivator", dhkClassMember::PTR_IGNORE, false, 140), //hkEntityDeactivator
											dhkClassMember("simulationIsland", dhkClassMember::PTR_IGNORE, false, 144), //hkSimulationIsland
											dhkClassMember("autoRemoveLevel", dhkClassMember::BYTE, false, 148),
											dhkClassMember("uid", dhkClassMember::DWORD, false, 152),
											dhkClassMember("motion", dhkClassMember::CLASS, false, 160, "hkMaxSizeMotion"), //??? aligned
											dhkClassMember("collisionListeners", dhkClassMember::CLASS, false, 456, "hkSmallArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("actions", dhkClassMember::CLASS, false, 464, "hkSmallArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("spuCollisionCallback", dhkClassMember::CLASS, false, 472, "hkEntitySpuCollisionCallback")};
const char* dhkClassLibrary450::hkRigidBodyParents[1] = { "hkEntity" };
const char* dhkClassLibrary450::hkShapeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkShapeMembers[2] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8),
											dhkClassMember("type", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary450::hkSphereRepShapeParents[1] = { "hkShape" };
const dhkClassMember dhkClassLibrary450::hkConvexShapeMembers[1] = { dhkClassMember("radius", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary450::hkConvexShapeParents[1] = { "hkSphereRepShape" };
const dhkClassMember dhkClassLibrary450::hkCapsuleShapeMembers[2] = { dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48)};
const char* dhkClassLibrary450::hkCapsuleShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary450::hkConstraintDataMembers[1] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary450::hkConstraintDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkConstraintAtomMembers[1] = { dhkClassMember("type", dhkClassMember::WORD, false, 0)};
const dhkClassMember dhkClassLibrary450::hkSetLocalTransformsConstraintAtomMembers[2] = { dhkClassMember("transformA", dhkClassMember::CLASS, false, 16, "hkTransform"),
																		dhkClassMember("transformB", dhkClassMember::CLASS, false, 80, "hkTransform")};
const char* dhkClassLibrary450::hkSetLocalTransformsConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkRagdollMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
																dhkClassMember("previousTargetAnglesOffset", dhkClassMember::WORD, false, 6),
																dhkClassMember("targetFrameAinB", dhkClassMember::MATRIX3, false, 16),
																dhkClassMember("motors_0", dhkClassMember::PTR_IGNORE, false, 64),
																dhkClassMember("motors_1", dhkClassMember::PTR_IGNORE, false, 68),
																dhkClassMember("motors_2", dhkClassMember::PTR_IGNORE, false, 72)};
const char* dhkClassLibrary450::hkRagdollMotorConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkAngFrictionConstraintAtomMembers[4] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("firstFrictionAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("numFrictionAxes", dhkClassMember::BYTE, false, 4),
																dhkClassMember("maxFrictionTorque", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary450::hkAngFrictionConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkTwistLimitConstraintAtomMembers[6] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxis", dhkClassMember::BYTE, false, 4),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary450::hkTwistLimitConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkConeLimitConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxisInA", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxisInB", dhkClassMember::BYTE, false, 4),
																dhkClassMember("angleMeasurementMode", dhkClassMember::BYTE, false, 5),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary450::hkConeLimitConstraintAtomParents[1] = { "hkConstraintAtom" };
const char* dhkClassLibrary450::hkBallSocketConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkRagdollConstraintDataAtomsMembers[7] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkSetLocalTransformsConstraintAtom"),
														  dhkClassMember("ragdollMotors", dhkClassMember::CLASS, false, 144, "hkRagdollMotorConstraintAtom"),
														  dhkClassMember("angFriction", dhkClassMember::CLASS, false, 224, "hkAngFrictionConstraintAtom"),
														  dhkClassMember("twistLimit", dhkClassMember::CLASS, false, 236, "hkTwistLimitConstraintAtom"),
														  dhkClassMember("coneLimit", dhkClassMember::CLASS, false, 256, "hkConeLimitConstraintAtom"),
														  dhkClassMember("planesLimit", dhkClassMember::CLASS, false, 276, "hkConeLimitConstraintAtom"),
														  dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 296, "hkBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary450::hkRagdollConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkRagdollConstraintDataAtoms")};
const char* dhkClassLibrary450::hkRagdollConstraintDataParents[1] = { "hkConstraintData" };
const dhkClassMember dhkClassLibrary450::hkConstraintInstanceMembers[10] = { dhkClassMember("owner", dhkClassMember::PTR_IGNORE, false, 8), //hkConstraintOwner
														dhkClassMember("data", dhkClassMember::PTR_IGNORE, false, 12),	//hkConstraintData
														dhkClassMember("constraintModifiers", dhkClassMember::PTR_IGNORE, false, 16), //hkModifierConstraintAtom
														dhkClassMember("entities_0", dhkClassMember::PTR_IGNORE, false, 20), //hkEntity
														dhkClassMember("entities_1", dhkClassMember::PTR_IGNORE, false, 24),
														dhkClassMember("priority", dhkClassMember::BYTE, false, 28),
														dhkClassMember("wantRuntime", dhkClassMember::BYTE, false, 29),
														dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 32),
														dhkClassMember("userData", dhkClassMember::DWORD, false, 36),
														dhkClassMember("internal", dhkClassMember::PTR_IGNORE, false, 40)}; 
const char* dhkClassLibrary450::hkConstraintInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkRagdollInstanceMembers[3] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("skeleton", dhkClassMember::PTR_IGNORE, false, 32)};
const char* dhkClassLibrary450::hkRagdollInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkSkeletonMapperDataSimpleMappingMembers[3] = { dhkClassMember("boneA", dhkClassMember::WORD, false, 0),
																		dhkClassMember("boneB", dhkClassMember::WORD, false, 2),
																		dhkClassMember("aFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform")};
const dhkClassMember dhkClassLibrary450::hkSkeletonMapperDataChainMappingMembers[6] = { dhkClassMember("startBoneA", dhkClassMember::WORD, false, 0),
																	dhkClassMember("endBoneA", dhkClassMember::WORD, false, 2),
																	dhkClassMember("startBoneB", dhkClassMember::WORD, false, 4),
																	dhkClassMember("endBoneB", dhkClassMember::WORD, false, 6),
																	dhkClassMember("startAFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform"),
																	dhkClassMember("endAFromBTransform", dhkClassMember::CLASS, false, 64, "hkQsTransform")};
const dhkClassMember dhkClassLibrary450::hkSkeletonMapperDataMembers[6] = { dhkClassMember("skeletonA", dhkClassMember::PTR_IGNORE, false, 0),
														dhkClassMember("skeletonB", dhkClassMember::PTR_IGNORE, false, 4),
														dhkClassMember("simpleMappings", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::CLASS, "hkSkeletonMapperDataSimpleMapping"),
														dhkClassMember("chainMappings", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::CLASS, "hkSkeletonMapperDataChainMapping"),
														dhkClassMember("unmappedBones", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::WORD),
														dhkClassMember("keepUnmappedLocal", dhkClassMember::BYTE, false, 44)};
const dhkClassMember dhkClassLibrary450::hkSkeletonMapperMembers[1] = { dhkClassMember("mapping", dhkClassMember::CLASS, false, 8, "hkSkeletonMapperData")};
const char* dhkClassLibrary450::hkSkeletonMapperParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkAngMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("motorAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
															dhkClassMember("previousTargetAngleOffset", dhkClassMember::WORD, false, 6),
															dhkClassMember("correspondingAngLimitSolverResultOffset", dhkClassMember::WORD, false, 8),
															dhkClassMember("targetAngle", dhkClassMember::DWORD, false, 12),
															dhkClassMember("motor", dhkClassMember::PTR_IGNORE, false, 16)}; //hkpConstraintMotor
const char* dhkClassLibrary450::hkAngMotorConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkAngLimitConstraintAtomMembers[5] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("limitAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("minAngle", dhkClassMember::DWORD, false, 4),
															dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 8),
															dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary450::hkAngLimitConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hk2dAngConstraintAtomMembers[1] = { dhkClassMember("freeRotationAxis", dhkClassMember::BYTE, false, 2)};
const char* dhkClassLibrary450::hk2dAngConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkLimitedHingeConstraintDataAtomsMembers[6] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkSetLocalTransformsConstraintAtom"),
																	dhkClassMember("angMotor", dhkClassMember::CLASS, false, 144, "hkAngMotorConstraintAtom"),
																	dhkClassMember("angFriction", dhkClassMember::CLASS, false, 164, "hkAngFrictionConstraintAtom"),
																	dhkClassMember("angLimit", dhkClassMember::CLASS, false, 176, "hkAngLimitConstraintAtom"),
																	dhkClassMember("2dAng", dhkClassMember::CLASS, false, 192, "hk2dAngConstraintAtom"),
																	dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 196, "hkBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary450::hkLimitedHingeConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkLimitedHingeConstraintDataAtoms")};
const char* dhkClassLibrary450::hkLimitedHingeConstraintDataParents[1] = { "hkConstraintData" };
const dhkClassMember dhkClassLibrary450::hkConstraintMotorMembers[1] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8)};
const char* dhkClassLibrary450::hkConstraintMotorParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary450::hkMaxSizeConstraintMotorMembers[9] = { dhkClassMember("dummy_0", dhkClassMember::DWORD, false, 12),
															dhkClassMember("dummy_1", dhkClassMember::DWORD, false, 16),
															dhkClassMember("dummy_2", dhkClassMember::DWORD, false, 20),
															dhkClassMember("dummy_3", dhkClassMember::DWORD, false, 24),
															dhkClassMember("dummy_4", dhkClassMember::DWORD, false, 28),
															dhkClassMember("dummy_5", dhkClassMember::DWORD, false, 32),
															dhkClassMember("dummy_6", dhkClassMember::DWORD, false, 36),
															dhkClassMember("dummy_7", dhkClassMember::DWORD, false, 40),
															dhkClassMember("dummy_8", dhkClassMember::DWORD, false, 44)};
const char* dhkClassLibrary450::hkMaxSizeConstraintMotorParents[1] = { "hkConstraintMotor" };
const dhkClassMember dhkClassLibrary450::hkLimitedForceConstraintMotorMembers[2] = { dhkClassMember("minForce", dhkClassMember::DWORD, false, 12),
																	dhkClassMember("maxForce", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary450::hkLimitedForceConstraintMotorParents[1] = { "hkConstraintMotor" };
const dhkClassMember dhkClassLibrary450::hkPositionConstraintMotorMembers[4] = { dhkClassMember("tau", dhkClassMember::DWORD, false, 20),
																dhkClassMember("damping", dhkClassMember::DWORD, false, 24),
																dhkClassMember("proportionalRecoveryVelocity", dhkClassMember::DWORD, false, 28),
																dhkClassMember("constantRecoveryVelocity", dhkClassMember::DWORD, false, 32)};
const char* dhkClassLibrary450::hkPositionConstraintMotorParents[1] = { "hkLimitedForceConstraintMotor" };
const dhkClassMember dhkClassLibrary450::hkConvexVerticesShapeFourVectorsMembers[3] = { dhkClassMember("x", dhkClassMember::VECTOR4, false, 0),
												dhkClassMember("y", dhkClassMember::VECTOR4, false, 16),
												dhkClassMember("z", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary450::hkConvexVerticesShapeMembers[5] = { dhkClassMember("aabbHalfExtents", dhkClassMember::VECTOR4, false, 32),
															dhkClassMember("aabbCenter", dhkClassMember::VECTOR4, false, 48),
															dhkClassMember("rotatedVertices", dhkClassMember::CLASS, false, 64, "hkArray", dhkClassMember::CLASS, "hkConvexVerticesShapeFourVectors"),
															dhkClassMember("numVertices", dhkClassMember::DWORD, false, 76),
															dhkClassMember("planeEquations", dhkClassMember::CLASS, false, 80, "hkArray", dhkClassMember::VECTOR4)};
const char* dhkClassLibrary450::hkConvexVerticesShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary450::hkSingleShapeContainerMembers[1] = { dhkClassMember("childShape", dhkClassMember::PTR_IGNORE, false, 0)}; //hkpShape
const char* dhkClassLibrary450::hkSingleShapeContainerParents[1] = { "hkShapeContainer" };
const dhkClassMember dhkClassLibrary450::hkConvexTranslateShapeMembers[3] = { dhkClassMember("childShape", dhkClassMember::CLASS, false, 20, "hkSingleShapeContainer"),
															dhkClassMember("childShapeSize", dhkClassMember::DWORD, false, 24),
															dhkClassMember("translation", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary450::hkConvexTranslateShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary450::hkBoxShapeMembers[1] = { dhkClassMember("halfExtents", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary450::hkBoxShapeParents[1] = { "hkConvexShape" };
//const dhkClassMember dhkClassLibrary450::hkSphereShapeMembers[3] = { dhkClassMember("pad16_0", dhkClassMember::DWORD, false, 20),
//													dhkClassMember("pad16_1", dhkClassMember::DWORD, false, 24),
//													dhkClassMember("pad16_2", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary450::hkSphereShapeParents[1] = { "hkConvexShape" };
const dhkClassMember dhkClassLibrary450::hkCylinderShapeMembers[6] = { dhkClassMember("cylRadius", dhkClassMember::DWORD, false, 20),
													dhkClassMember("cylBaseRadiusFactorForHeightFieldCollisions", dhkClassMember::DWORD, false, 24),
													dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48),
													dhkClassMember("perpendicular1", dhkClassMember::VECTOR4, false, 64),
													dhkClassMember("perpendicular2", dhkClassMember::VECTOR4, false, 80)};
const char* dhkClassLibrary450::hkCylinderShapeParents[1] = { "hkConvexShape" };
const char* dhkClassLibrary450::hkEntityDeactivatorParents[1] = { "hkReferencedObject" };
const char* dhkClassLibrary450::hkRigidBodyDeactivatorParents[1] = { "hkEntityDeactivator" };
const dhkClassMember dhkClassLibrary450::hkSpatialRigidBodyDeactivatorMembers[7] = { dhkClassMember("highFrequencySample", dhkClassMember::CLASS, false, 16, "hkSpatialRigidBodyDeactivatorSample"),
																					dhkClassMember("lowFrequencySample", dhkClassMember::CLASS, false, 48, "hkSpatialRigidBodyDeactivatorSample"),
																					dhkClassMember("radiusSqrd", dhkClassMember::DWORD, false, 80),
																					dhkClassMember("minHighFrequencyTranslation", dhkClassMember::DWORD, false, 84),
																					dhkClassMember("minHighFrequencyRotation", dhkClassMember::DWORD, false, 88),
																					dhkClassMember("minLowFrequencyTranslation", dhkClassMember::DWORD, false, 92),
																					dhkClassMember("minLowFrequencyRotation", dhkClassMember::DWORD, false, 96)};
const char* dhkClassLibrary450::hkSpatialRigidBodyDeactivatorParents[1] = { "hkRigidBodyDeactivator" };
const dhkClassMember dhkClassLibrary450::hkSpatialRigidBodyDeactivatorSampleMembers[2] = { dhkClassMember("refPosition", dhkClassMember::VECTOR4, false, 0),
																							dhkClassMember("refRotation", dhkClassMember::VECTOR4, false, 16)};
const dhkClassMember dhkClassLibrary450::hkxAttributeHolderMembers[2] = { dhkClassMember("attributeGroups", dhkClassMember::PTR_CLASS, true, 0, "hkxAttributeGroup"),
																			dhkClassMember("numAttributeGroups", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary450::hkxAttributeGroupMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																			dhkClassMember("attributes", dhkClassMember::PTR_CLASS, true, 4, "hkxAttribute"),
																			dhkClassMember("numAttributes", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkxAttributeMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("value", dhkClassMember::CLASS, false, 4, "hkVariant")};
const dhkClassMember dhkClassLibrary450::hkxNodeMembers[10] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																dhkClassMember("object", dhkClassMember::CLASS, false, 12, "hkVariant"),
																dhkClassMember("keyFrames", dhkClassMember::PTR_MATRIX4, true, 20),
																dhkClassMember("numKeyFrames", dhkClassMember::DWORD, false, 24),
																dhkClassMember("children", dhkClassMember::PTR_IGNORE, true, 28),
																dhkClassMember("numChildren", dhkClassMember::DWORD, false, 32),
																dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 36, "hkxNodeAnnotationData"),
																dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 40),
																dhkClassMember("userProperties", dhkClassMember::PTR_IGNORE, false, 44),
																dhkClassMember("selected", dhkClassMember::BYTE, false, 48)};
const char* dhkClassLibrary450::hkxNodeParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary450::hkxAnimatedFloatMembers[3] = { dhkClassMember("floats", dhkClassMember::PTR_DWORD, true, 0),
																		dhkClassMember("numFloats", dhkClassMember::DWORD, false, 4),
																		dhkClassMember("hint", dhkClassMember::BYTE, false, 8)};
const dhkClassMember dhkClassLibrary450::hkxSparselyAnimatedStringMembers[4] = { dhkClassMember("strings", dhkClassMember::PTR_IGNORE, true, 0),
																					dhkClassMember("numStrings", dhkClassMember::DWORD, false, 4),
																					dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																					dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxSparselyAnimatedBoolMembers[4] = { dhkClassMember("bools", dhkClassMember::PTR_IGNORE, true, 0),
																				dhkClassMember("numBools", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxSparselyAnimatedIntMembers[4] = { dhkClassMember("ints", dhkClassMember::PTR_DWORD, true, 0),
																				dhkClassMember("numInts", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxMeshMembers[4] = { dhkClassMember("sections", dhkClassMember::PTR_IGNORE, true, 0),
																dhkClassMember("numSections", dhkClassMember::DWORD, false, 4),
																dhkClassMember("userChannelInfos", dhkClassMember::PTR_CLASS, true, 8, "hkxMeshUserChannelInfo"),
																dhkClassMember("numUserChannelInfos", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxMeshSectionMembers[6] = { dhkClassMember("vertexBuffer", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("indexBuffers", dhkClassMember::PTR_IGNORE, true, 4),
																		dhkClassMember("numIndexBuffers", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("material", dhkClassMember::PTR_IGNORE, false, 12),
																		dhkClassMember("userChannels", dhkClassMember::PTR_CLASS, true, 16, "hkVariant"),
																		dhkClassMember("numUserChannels", dhkClassMember::DWORD, false, 20)};
const dhkClassMember dhkClassLibrary450::hkxMeshUserChannelInfoMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																				dhkClassMember("className", dhkClassMember::PTR_IGNORE, false, 12)};
const char* dhkClassLibrary450::hkxMeshUserChannelInfoParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary450::hkxVertexBufferMembers[4] = { dhkClassMember("vertexDataClass", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("vertexData", dhkClassMember::PTR_HOMOGENEOUS, true, 4),
																		dhkClassMember("numVertexData", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("format", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary450::hkxVertexFormatMembers[12] = { dhkClassMember("stride", dhkClassMember::BYTE, false, 0),
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
const dhkClassMember dhkClassLibrary450::hkxIndexBufferMembers[7] = { dhkClassMember("indexType", dhkClassMember::BYTE, false, 0),
																		dhkClassMember("indices16", dhkClassMember::PTR_WORD, true, 4),
																		dhkClassMember("numIndices16", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("indices32", dhkClassMember::PTR_DWORD, true, 12),
																		dhkClassMember("numIndices32", dhkClassMember::DWORD, false, 16),
																		dhkClassMember("vertexBaseOffset", dhkClassMember::DWORD, false, 20),
																		dhkClassMember("length", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary450::hkxMaterialMembers[10] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																	dhkClassMember("stages", dhkClassMember::PTR_CLASS, true, 12, "hkxMaterialTextureStage"),
																	dhkClassMember("numStages", dhkClassMember::DWORD, false, 16),
																	dhkClassMember("diffuseColor", dhkClassMember::VECTOR4, false, 32),
																	dhkClassMember("ambientColor", dhkClassMember::VECTOR4, false, 48),
																	dhkClassMember("specularColor", dhkClassMember::VECTOR4, false, 64),
																	dhkClassMember("emissiveColor", dhkClassMember::VECTOR4, false, 80),
																	dhkClassMember("subMaterials", dhkClassMember::PTR_IGNORE, true, 96),
																	dhkClassMember("numSubMaterials", dhkClassMember::DWORD, false, 100),
																	dhkClassMember("extraData", dhkClassMember::CLASS, false, 104, "hkVariant")};
const char* dhkClassLibrary450::hkxMaterialParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary450::hkxTextureFileMembers[1] = { dhkClassMember("filename", dhkClassMember::PTR_IGNORE, false, 0)};
const dhkClassMember dhkClassLibrary450::hkxTextureInplaceMembers[3] = { dhkClassMember("fileType", dhkClassMember::BYTE, false, 0),
																			dhkClassMember("data", dhkClassMember::PTR_IGNORE, true, 4),
																			dhkClassMember("numData", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkxTriangleSelectionChannelMembers[2] = { dhkClassMember("selectedTriangles", dhkClassMember::PTR_DWORD, true, 0),
																					dhkClassMember("numSelectedTriangles", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary450::hkxNodeAnnotationDataMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																				dhkClassMember("description", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary450::hkClassMembers[9] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 4),
																dhkClassMember("objectSize", dhkClassMember::DWORD, false, 8),
																dhkClassMember("numImplementedInterfaces", dhkClassMember::DWORD, false, 12),
																dhkClassMember("declaredEnums", dhkClassMember::PTR_CLASS, true, 16, "hkClassEnum"),
																dhkClassMember("numDeclaredEnums", dhkClassMember::DWORD, false, 20),
																dhkClassMember("declaredMembers", dhkClassMember::PTR_CLASS, true, 24, "hkClassMember"),
																dhkClassMember("numDeclaredMembers", dhkClassMember::DWORD, false, 28),
																dhkClassMember("defaults", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary450::hkClassEnumMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("items", dhkClassMember::PTR_CLASS, true, 4, "hkClassEnumItem"),
																	dhkClassMember("numItems", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkClassEnumItemMembers[2] = { dhkClassMember("value", dhkClassMember::DWORD, false, 0),
																		dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary450::hkClassMemberMembers[8] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4),
																	dhkClassMember("enum", dhkClassMember::PTR_IGNORE, false, 8),
																	dhkClassMember("type", dhkClassMember::BYTE, false, 12),
																	dhkClassMember("subtype", dhkClassMember::BYTE, false, 13),
																	dhkClassMember("cArraySize", dhkClassMember::WORD, false, 14),
																	dhkClassMember("flags", dhkClassMember::WORD, false, 16),
																	dhkClassMember("offset", dhkClassMember::WORD, false, 18)};
const dhkClassMember dhkClassLibrary450::hkxMaterialTextureStageMembers[2] = { dhkClassMember("texture", dhkClassMember::CLASS, false, 0, "hkVariant"),
																				dhkClassMember("usageHint", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary450::hkxVertexP4N4T4B4W4I4Q4Members[10] = { dhkClassMember("position", dhkClassMember::VECTOR4, false, 0),
																				dhkClassMember("normal", dhkClassMember::VECTOR4, false, 16),
																				dhkClassMember("tangent", dhkClassMember::VECTOR4, false, 32),
																				dhkClassMember("binormal", dhkClassMember::VECTOR4, false, 48),
																				dhkClassMember("weights", dhkClassMember::DWORD, false, 64),
																				dhkClassMember("indices", dhkClassMember::DWORD, false, 68),
																				dhkClassMember("qu0_0", dhkClassMember::WORD, false, 72),
																				dhkClassMember("qu0_1", dhkClassMember::WORD, false, 74),
																				dhkClassMember("qu1_0", dhkClassMember::WORD, false, 76),
																				dhkClassMember("qu1_1", dhkClassMember::WORD, false, 78)};
const dhkClassMember dhkClassLibrary450::hkxVertexP4N4C1T2Members[6] = { dhkClassMember("position", dhkClassMember::VECTOR4, false, 0),
																		dhkClassMember("normal", dhkClassMember::VECTOR4, false, 16),
																		dhkClassMember("diffuse", dhkClassMember::DWORD, false, 32),
																		dhkClassMember("u", dhkClassMember::DWORD, false, 36),
																		dhkClassMember("v", dhkClassMember::DWORD, false, 40),
																		dhkClassMember("padding", dhkClassMember::DWORD, false, 44)};
const dhkClassMember dhkClassLibrary450::hkBallAndSocketConstraintDataAtomsMembers[2] = { dhkClassMember("pivots", dhkClassMember::CLASS, false, 0, "hkSetLocalTranslationsConstraintAtom"),
																						dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 48, "hkBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary450::hkSetLocalTranslationsConstraintAtomMembers[2] = { dhkClassMember("translationA", dhkClassMember::VECTOR4, false, 16),
																							dhkClassMember("translationB", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary450::hkSetLocalTranslationsConstraintAtomParents[1] = { "hkConstraintAtom" };
const dhkClassMember dhkClassLibrary450::hkBallAndSocketConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkBallAndSocketConstraintDataAtoms")};
const char* dhkClassLibrary450::hkBallAndSocketConstraintDataParents[1] = { "hkConstraintData" };

dhkClassLibrary450::dhkClassLibrary450(void)
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
	m_classMap.insert(make_pair("hkInterleavedSkeletalAnimation", dhkClass("hkInterleavedSkeletalAnimation", hkInterleavedSkeletalAnimationParents, 1, 40, hkInterleavedSkeletalAnimationMembers, 2)));
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
	//m_classMap.insert(make_pair("hkpCollidableBoundingVolumeData", dhkClass("hkpCollidableBoundingVolumeData", NULL, 0, 40, hkpCollidableBoundingVolumeDataMembers, 16)));
	m_classMap.insert(make_pair("hkCollidable", dhkClass("hkCollidable", hkCollidableParents, 1, 36, hkCollidableMembers, 5)));
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
	m_classMap.insert(make_pair("hkEntitySpuCollisionCallback", dhkClass("hkEntitySpuCollisionCallback", NULL, 0, 8, hkEntitySpuCollisionCallbackMembers, 4)));
	m_classMap.insert(make_pair("hkEntity", dhkClass("hkEntity", hkEntityParents, 1, 480, hkEntityMembers, 15)));
	m_classMap.insert(make_pair("hkRigidBody", dhkClass("hkRigidBody", hkRigidBodyParents, 1, 480, NULL, 0)));
	m_classMap.insert(make_pair("hkShape", dhkClass("hkShape", hkShapeParents, 1, 16, hkShapeMembers, 2)));
	m_classMap.insert(make_pair("hkSphereRepShape", dhkClass("hkSphereRepShape", hkSphereRepShapeParents, 1, 16, NULL, 0)));
	m_classMap.insert(make_pair("hkConvexShape", dhkClass("hkConvexShape", hkConvexShapeParents, 1, 20, hkConvexShapeMembers, 1)));
	m_classMap.insert(make_pair("hkCapsuleShape", dhkClass("hkCapsuleShape", hkCapsuleShapeParents, 1, 64, hkCapsuleShapeMembers, 2)));
	m_classMap.insert(make_pair("hkConstraintData", dhkClass("hkConstraintData", hkConstraintDataParents, 1, 12, hkConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkConstraintAtom", dhkClass("hkConstraintAtom", NULL, 0, 4, hkConstraintAtomMembers, 1)));
	m_classMap.insert(make_pair("hkSetLocalTransformsConstraintAtom", dhkClass("hkSetLocalTransformsConstraintAtom", hkSetLocalTransformsConstraintAtomParents, 1, 144, hkSetLocalTransformsConstraintAtomMembers, 2)));
	m_classMap.insert(make_pair("hkRagdollMotorConstraintAtom", dhkClass("hkRagdollMotorConstraintAtom", hkRagdollMotorConstraintAtomParents, 1, 80, hkRagdollMotorConstraintAtomMembers, 7)));
	m_classMap.insert(make_pair("hkAngFrictionConstraintAtom", dhkClass("hkAngFrictionConstraintAtom", hkAngFrictionConstraintAtomParents, 1, 12, hkAngFrictionConstraintAtomMembers, 4)));
	m_classMap.insert(make_pair("hkTwistLimitConstraintAtom", dhkClass("hkTwistLimitConstraintAtom", hkTwistLimitConstraintAtomParents, 1, 20, hkTwistLimitConstraintAtomMembers, 6)));
	m_classMap.insert(make_pair("hkConeLimitConstraintAtom", dhkClass("hkConeLimitConstraintAtom", hkConeLimitConstraintAtomParents, 1, 20, hkConeLimitConstraintAtomMembers, 7)));
	m_classMap.insert(make_pair("hkBallSocketConstraintAtom", dhkClass("hkBallSocketConstraintAtom", hkBallSocketConstraintAtomParents, 1, 4, NULL, 0)));
	m_classMap.insert(make_pair("hkRagdollConstraintDataAtoms", dhkClass("hkRagdollConstraintDataAtoms", NULL, 0, 300, hkRagdollConstraintDataAtomsMembers, 7)));
	m_classMap.insert(make_pair("hkRagdollConstraintData", dhkClass("hkRagdollConstraintData", hkRagdollConstraintDataParents, 1, 312, hkRagdollConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkConstraintInstance", dhkClass("hkConstraintInstance", hkConstraintInstanceParents, 1, 44, hkConstraintInstanceMembers, 10)));
	m_classMap.insert(make_pair("hkRagdollInstance", dhkClass("hkRagdollInstance", hkRagdollInstanceParents, 1, 36, hkRagdollInstanceMembers, 3)));
	m_classMap.insert(make_pair("hkSkeletonMapperDataSimpleMapping", dhkClass("hkSkeletonMapperDataSimpleMapping", NULL, 0, 64, hkSkeletonMapperDataSimpleMappingMembers, 3)));
	m_classMap.insert(make_pair("hkSkeletonMapperDataChainMapping", dhkClass("hkSkeletonMapperDataChainMapping", NULL, 0, 112, hkSkeletonMapperDataChainMappingMembers, 6)));
	m_classMap.insert(make_pair("hkSkeletonMapperData", dhkClass("hkSkeletonMapperData", NULL, 0, 48, hkSkeletonMapperDataMembers, 6)));
	m_classMap.insert(make_pair("hkSkeletonMapper", dhkClass("hkSkeletonMapper", hkSkeletonMapperParents, 1, 56, hkSkeletonMapperMembers, 1)));
	m_classMap.insert(make_pair("hkAngMotorConstraintAtom", dhkClass("hkAngMotorConstraintAtom", hkAngMotorConstraintAtomParents, 1, 20, hkAngMotorConstraintAtomMembers, 7)));
	m_classMap.insert(make_pair("hkAngLimitConstraintAtom", dhkClass("hkAngLimitConstraintAtom", hkAngLimitConstraintAtomParents, 1, 16, hkAngLimitConstraintAtomMembers, 5)));
	m_classMap.insert(make_pair("hk2dAngConstraintAtom", dhkClass("hk2dAngConstraintAtom", hk2dAngConstraintAtomParents, 1, 4, hk2dAngConstraintAtomMembers, 1)));
	m_classMap.insert(make_pair("hkLimitedHingeConstraintDataAtoms", dhkClass("hkLimitedHingeConstraintDataAtoms", NULL, 0, 200, hkLimitedHingeConstraintDataAtomsMembers, 6)));
	m_classMap.insert(make_pair("hkLimitedHingeConstraintData", dhkClass("hkLimitedHingeConstraintData", hkLimitedHingeConstraintDataParents, 1, 216, hkLimitedHingeConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkConstraintMotor", dhkClass("hkConstraintMotor", hkConstraintMotorParents, 1, 12, hkConstraintMotorMembers, 1)));
	m_classMap.insert(make_pair("hkMaxSizeConstraintMotor", dhkClass("hkMaxSizeConstraintMotor", hkMaxSizeConstraintMotorParents, 1, 48, hkMaxSizeConstraintMotorMembers, 9)));
	m_classMap.insert(make_pair("hkLimitedForceConstraintMotor", dhkClass("hkLimitedForceConstraintMotor", hkLimitedForceConstraintMotorParents, 1, 20, hkLimitedForceConstraintMotorMembers, 2)));
	m_classMap.insert(make_pair("hkPositionConstraintMotor", dhkClass("hkPositionConstraintMotor", hkPositionConstraintMotorParents, 1, 36, hkPositionConstraintMotorMembers, 4)));
	m_classMap.insert(make_pair("hkConvexVerticesShapeFourVectors", dhkClass("hkConvexVerticesShapeFourVectors", NULL, 0, 48, hkConvexVerticesShapeFourVectorsMembers, 3)));
	m_classMap.insert(make_pair("hkConvexVerticesShape", dhkClass("hkConvexVerticesShape", hkConvexVerticesShapeParents, 1, 92, hkConvexVerticesShapeMembers, 5)));
	//m_classMap.insert(make_pair("hkConvexVerticesConnectivity", dhkClass("hkConvexVerticesConnectivity", hkpConvexVerticesConnectivityParents, 1, 32, hkpConvexVerticesConnectivityMembers, 2)));
	m_classMap.insert(make_pair("hkSingleShapeContainer", dhkClass("hkSingleShapeContainer", hkSingleShapeContainerParents, 1, 4, hkSingleShapeContainerMembers, 1)));
	m_classMap.insert(make_pair("hkShapeContainer", dhkClass("hkShapeContainer", NULL, 0, 0, NULL, 0)));
	m_classMap.insert(make_pair("hkConvexTranslateShape", dhkClass("hkConvexTranslateShape", hkConvexTranslateShapeParents, 1, 48, hkConvexTranslateShapeMembers, 3)));
	m_classMap.insert(make_pair("hkBoxShape", dhkClass("hkpBoxShape", hkBoxShapeParents, 1, 48, hkBoxShapeMembers, 1)));
	m_classMap.insert(make_pair("hkSphereShape", dhkClass("hkSphereShape", hkSphereShapeParents, 1, 20, NULL, 0)));
	m_classMap.insert(make_pair("hkCylinderShape", dhkClass("hkCylinderShape", hkCylinderShapeParents, 1, 96, hkCylinderShapeMembers, 6)));
	m_classMap.insert(make_pair("hkEntityDeactivator", dhkClass("hkEntityDeactivator", hkEntityDeactivatorParents, 1, 8, NULL, 0)));
	m_classMap.insert(make_pair("hkRigidBodyDeactivator", dhkClass("hkRigidBodyDeactivator", hkRigidBodyDeactivatorParents, 1, 8, NULL, 0)));
	m_classMap.insert(make_pair("hkSpatialRigidBodyDeactivator", dhkClass("hkSpatialRigidBodyDeactivator", hkSpatialRigidBodyDeactivatorParents, 1, 100, hkSpatialRigidBodyDeactivatorMembers, 7)));
	m_classMap.insert(make_pair("hkSpatialRigidBodyDeactivatorSample", dhkClass("hkSpatialRigidBodyDeactivatorSample", NULL, 0, 32, hkSpatialRigidBodyDeactivatorSampleMembers, 2)));
	m_classMap.insert(make_pair("hkxAttributeHolder", dhkClass("hkxAttributeHolder", NULL, 0, 8, hkxAttributeHolderMembers, 2)));
	m_classMap.insert(make_pair("hkxAttributeGroup", dhkClass("hkxAttributeGroup", NULL, 0, 12, hkxAttributeGroupMembers, 3)));
	m_classMap.insert(make_pair("hkxAttribute", dhkClass("hkxAttribute", NULL, 0, 12, hkxAttributeMembers, 2)));
	m_classMap.insert(make_pair("hkxNode", dhkClass("hkxNode", hkxNodeParents, 1, 52, hkxNodeMembers, 10)));
	m_classMap.insert(make_pair("hkxAnimatedFloat", dhkClass("hkxAnimatedFloat", NULL, 0, 12, hkxAnimatedFloatMembers, 3)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedString", dhkClass("hkxSparselyAnimatedString", NULL, 0, 16, hkxSparselyAnimatedStringMembers, 4)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedBool", dhkClass("hkxSparselyAnimatedBool", NULL, 0, 16, hkxSparselyAnimatedBoolMembers, 4)));
	m_classMap.insert(make_pair("hkxSparselyAnimatedInt", dhkClass("hkxSparselyAnimatedInt", NULL, 0, 16, hkxSparselyAnimatedIntMembers, 4)));
	m_classMap.insert(make_pair("hkxMesh", dhkClass("hkxMesh", NULL, 0, 16, hkxMeshMembers, 4)));
	m_classMap.insert(make_pair("hkxMeshSection", dhkClass("hkxMeshSection", NULL, 0, 24, hkxMeshSectionMembers, 6)));
	m_classMap.insert(make_pair("hkxMeshUserChannelInfo", dhkClass("hkxMeshUserChannelInfo", hkxMeshUserChannelInfoParents, 1, 16, hkxMeshUserChannelInfoMembers, 2)));
	m_classMap.insert(make_pair("hkxVertexBuffer", dhkClass("hkxVertexBuffer", NULL, 0, 16, hkxVertexBufferMembers, 4)));
	m_classMap.insert(make_pair("hkxVertexFormat", dhkClass("hkxVertexFormat", NULL, 0, 12, hkxVertexFormatMembers, 12)));
	m_classMap.insert(make_pair("hkxIndexBuffer", dhkClass("hkxIndexBuffer", NULL, 0, 28, hkxIndexBufferMembers, 7)));
	m_classMap.insert(make_pair("hkxMaterial", dhkClass("hkxMaterial", hkxMaterialParents, 1, 112, hkxMaterialMembers, 10)));
	m_classMap.insert(make_pair("hkxTextureFile", dhkClass("hkxTextureFile", NULL, 0, 4, hkxTextureFileMembers, 1)));
	m_classMap.insert(make_pair("hkxTextureInplace", dhkClass("hkxTextureInplace", NULL, 0, 12, hkxTextureInplaceMembers, 3)));
	m_classMap.insert(make_pair("hkxTriangleSelectionChannel", dhkClass("hkxTriangleSelectionChannel", NULL, 0, 8, hkxTriangleSelectionChannelMembers, 2)));
	m_classMap.insert(make_pair("hkxNodeAnnotationData", dhkClass("hkxNodeAnnotationData", NULL, 0, 8, hkxNodeAnnotationDataMembers, 2)));
	m_classMap.insert(make_pair("hkClass", dhkClass("hkClass", NULL, 0, 36, hkClassMembers, 9)));
	m_classMap.insert(make_pair("hkClassEnum", dhkClass("hkClassEnum", NULL, 0, 12, hkClassEnumMembers, 3)));
	m_classMap.insert(make_pair("hkClassEnumItem", dhkClass("hkClassEnumItem", NULL, 0, 8, hkClassEnumItemMembers, 2)));
	m_classMap.insert(make_pair("hkClassMember", dhkClass("hkClassMember", NULL, 0, 20, hkClassMemberMembers, 8)));
	m_classMap.insert(make_pair("hkxMaterialTextureStage", dhkClass("hkxMaterialTextureStage", NULL, 0, 12, hkxMaterialTextureStageMembers, 2)));
	m_classMap.insert(make_pair("hkxVertexP4N4T4B4W4I4Q4", dhkClass("hkxVertexP4N4T4B4W4I4Q4", NULL, 0, 80, hkxVertexP4N4T4B4W4I4Q4Members, 10)));
	m_classMap.insert(make_pair("hkxVertexP4N4C1T2", dhkClass("hkxVertexP4N4C1T2", NULL, 0, 48,	hkxVertexP4N4C1T2Members, 6)));
	m_classMap.insert(make_pair("hkBallAndSocketConstraintData", dhkClass("hkBallAndSocketConstraintData", hkBallAndSocketConstraintDataParents, 1, 68, hkBallAndSocketConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkBallAndSocketConstraintDataAtoms", dhkClass("hkBallAndSocketConstraintDataAtoms", NULL, 0, 52, hkBallAndSocketConstraintDataAtomsMembers, 2)));
	m_classMap.insert(make_pair("hkSetLocalTranslationsConstraintAtom", dhkClass("hkSetLocalTranslationsConstraintAtom", hkSetLocalTranslationsConstraintAtomParents, 1, 48, hkSetLocalTranslationsConstraintAtomMembers, 2)));
	//m_classMap.insert(make_pair("hkBallSocketConstraintAtom", dhkClass("hkBallSocketConstraintAtom", hkBallSocketConstraintAtomParents, 1, 4, NULL, 0)));
}


dhkClassLibrary450::~dhkClassLibrary450(void)
{
}

dhkClass* dhkClassLibrary450::getClass(const char* className) {
	try {
		return &m_classMap.at(className);
	} catch (const out_of_range& e) {
		printf("Couldn't find class %s in library!\n", className);
		return 0;
	}
}
