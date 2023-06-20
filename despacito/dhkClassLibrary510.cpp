#include "dhkClassLibrary510.h"

const dhkClassMember dhkClassLibrary510::hkRootLevelContainerNamedVariantMembers[] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0), 
																		 dhkClassMember("className", dhkClassMember::PTR_IGNORE, true, 4), 
																		 dhkClassMember("variant", dhkClassMember::CLASS, false, 8, "hkVariant") };
const dhkClassMember dhkClassLibrary510::hkRootLevelContainerMembers[2] = { dhkClassMember("namedVariants", dhkClassMember::PTR_CLASS, true, 0, "hkRootLevelContainerNamedVariant"),
															 dhkClassMember("numNamedVariants", dhkClassMember::DWORD, false, 4) };
const dhkClassMember dhkClassLibrary510::hkVariantMembers[2] = { dhkClassMember("object", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary510::hkArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0), 
												dhkClassMember("size", dhkClassMember::DWORD, false, 4), 
												dhkClassMember("capacityAndFlags", dhkClassMember::DWORD, false, 8) };
const dhkClassMember dhkClassLibrary510::hkSmallArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0),
											dhkClassMember("size", dhkClassMember::WORD, false, 4), //uh oh
											dhkClassMember("capacityAndFlags", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary510::hkaAnimationContainerMembers[10] = { dhkClassMember("skeletons", dhkClassMember::PTR_IGNORE, true, 0), 
															   dhkClassMember("numSkeletons", dhkClassMember::DWORD, false, 4), 
															   dhkClassMember("animations", dhkClassMember::PTR_IGNORE, true, 8),
															   dhkClassMember("numAnimations", dhkClassMember::DWORD, false, 12),
															   dhkClassMember("bindings", dhkClassMember::PTR_IGNORE, true, 16),
															   dhkClassMember("numBindings", dhkClassMember::DWORD, false, 20),
															   dhkClassMember("attachments", dhkClassMember::PTR_IGNORE, true, 24),
															   dhkClassMember("numAttachments", dhkClassMember::DWORD, false, 28),
															   dhkClassMember("skins", dhkClassMember::PTR_IGNORE, true, 32),
															   dhkClassMember("numSkins", dhkClassMember::DWORD, false, 36)};
const dhkClassMember dhkClassLibrary510::hkReferencedObjectMembers[2] = { dhkClassMember("memSizeAndFlags", dhkClassMember::WORD, false, 4),
														   dhkClassMember("referenceCount", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary510::hkaSkeletalAnimationMembers[6] = { dhkClassMember("type", dhkClassMember::DWORD, false, 8),
															 dhkClassMember("duration", dhkClassMember::DWORD, false, 12),
															 dhkClassMember("numberOfTracks", dhkClassMember::DWORD, false, 16),
															 dhkClassMember("extractedMotion", dhkClassMember::PTR_CLASS, false, 20), //not sure
															 dhkClassMember("annotationTracks", dhkClassMember::PTR_IGNORE, true, 24),
															 dhkClassMember("numAnnotationTracks", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary510::hkaSkeletalAnimationParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkaWaveletSkeletalAnimationMembers[11] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
																	 dhkClassMember("blockSize", dhkClassMember::DWORD, false, 36),
																	 dhkClassMember("qFormat", dhkClassMember::CLASS, false, 40, "hkaWaveletSkeletalAnimationQuantizationFormat"),
																	 dhkClassMember("staticMaskIdx", dhkClassMember::DWORD, false, 60),
																	 dhkClassMember("staticDOFsIdx", dhkClassMember::DWORD, false, 64),
																	 dhkClassMember("blockIndexIdx", dhkClassMember::DWORD, false, 68),
																	 dhkClassMember("blockIndexSize", dhkClassMember::DWORD, false, 72),
																	 dhkClassMember("quantizedDataIdx", dhkClassMember::DWORD, false, 76),
																	 dhkClassMember("quantizedDataSize", dhkClassMember::DWORD, false, 80),
																	 dhkClassMember("dataBuffer", dhkClassMember::PTR_IGNORE, true, 84),
																	 dhkClassMember("numDataBuffer", dhkClassMember::DWORD, false, 88)};
const char* dhkClassLibrary510::hkaWaveletSkeletalAnimationParents[1] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary510::hkaWaveletSkeletalAnimationQuantizationFormatMembers[6] = { dhkClassMember("maxBitWidth", dhkClassMember::BYTE, false, 0),
																					 dhkClassMember("preserved", dhkClassMember::BYTE, false, 1),
																					 dhkClassMember("numD", dhkClassMember::DWORD, false, 4),
																					 dhkClassMember("offsetIdx", dhkClassMember::DWORD, false, 8),
																					 dhkClassMember("scaleIdx", dhkClassMember::DWORD, false, 12),
																					 dhkClassMember("bitWidthIdx", dhkClassMember::DWORD, false, 16)};
const dhkClassMember dhkClassLibrary510::hkaInterleavedSkeletalAnimationMembers[2] = { dhkClassMember("transforms", dhkClassMember::PTR_CLASS, true, 32, "hkQsTransform"),
																						dhkClassMember("numTransforms", dhkClassMember::DWORD, false, 36)};
const char* dhkClassLibrary510::hkaInterleavedSkeletalAnimationParents[1] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary510::hkaDeltaCompressedSkeletalAnimationMembers[13] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 32),
																						dhkClassMember("blockSize", dhkClassMember::DWORD, false, 36),
																						dhkClassMember("qFormat", dhkClassMember::CLASS, false, 40, "hkaWaveletSkeletalAnimationQuantizationFormat"),
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
const char* dhkClassLibrary510::hkaDeltaCompressedSkeletalAnimationParents[] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary510::hkaDefaultAnimatedReferenceFrameMembers[5] = { dhkClassMember("up", dhkClassMember::VECTOR4, false, 16),
																		 dhkClassMember("forward", dhkClassMember::VECTOR4, false, 32),
																		 dhkClassMember("duration", dhkClassMember::DWORD, false, 48),
																		 dhkClassMember("referenceFrameSamples", dhkClassMember::PTR_VECTOR4, true, 52),
																		 dhkClassMember("numReferenceFrameSamples", dhkClassMember::DWORD, false, 56)};
const char* dhkClassLibrary510::hkaDefaultAnimatedReferenceFrameMembersParents[1] = { "hkReferencedObject" };
//const dhkClassMember* hkVector4Members[4] = { new dhkClassMember("x", dhkClassMember::DWORD, false, 0),
//												  new dhkClassMember("y", dhkClassMember::DWORD, false, 4),
//												  new dhkClassMember("z", dhkClassMember::DWORD, false, 8),
//												  new dhkClassMember("w", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary510::hkaAnnotationTrackMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
														   dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 4, "hkaAnnotationTrackAnnotation"),
														   dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary510::hkaAnnotationTrackAnnotationMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																	 dhkClassMember("text", dhkClassMember::PTR_IGNORE, true, 4)};
const dhkClassMember dhkClassLibrary510::hkaAnimationBindingMembers[4] = { dhkClassMember("animation", dhkClassMember::PTR_IGNORE, false, 0),
															dhkClassMember("animationTrackToBoneIndices", dhkClassMember::PTR_WORD, true, 4),
															dhkClassMember("numAnimationTrackToBoneIndices", dhkClassMember::DWORD, false, 8),
															dhkClassMember("blendHint", dhkClassMember::BYTE, false, 12)};
const dhkClassMember dhkClassLibrary510::hkxSceneMembers[21] = { dhkClassMember("modeller", dhkClassMember::PTR_IGNORE, true, 0),
												  dhkClassMember("asset", dhkClassMember::PTR_IGNORE, true, 4),
												  dhkClassMember("sceneLength", dhkClassMember::DWORD, false, 8),
												  dhkClassMember("rootNode", dhkClassMember::PTR_IGNORE, false, 12),
												  dhkClassMember("selectionSets", dhkClassMember::PTR_IGNORE, true, 16),
												  dhkClassMember("numSelectionSets", dhkClassMember::DWORD, false, 20),
												  dhkClassMember("cameras", dhkClassMember::PTR_IGNORE, true, 24),
												  dhkClassMember("numCameras", dhkClassMember::DWORD, false, 28),
												  dhkClassMember("lights", dhkClassMember::PTR_IGNORE, true, 32),
												  dhkClassMember("numLights", dhkClassMember::DWORD, false, 36),
												  dhkClassMember("meshes", dhkClassMember::PTR_IGNORE, true, 40),
												  dhkClassMember("numMeshes", dhkClassMember::DWORD, false, 44),
												  dhkClassMember("materials", dhkClassMember::PTR_IGNORE, true, 48),
												  dhkClassMember("numMaterials", dhkClassMember::DWORD, false, 52),
												  dhkClassMember("inplaceTextures", dhkClassMember::PTR_IGNORE, true, 56),
												  dhkClassMember("numInplaceTextures", dhkClassMember::DWORD, false, 60),
												  dhkClassMember("externalTextures", dhkClassMember::PTR_IGNORE, true, 64),
												  dhkClassMember("numExternalTextures", dhkClassMember::DWORD, false, 68),
												  dhkClassMember("skinBindings", dhkClassMember::PTR_IGNORE, true, 72),
												  dhkClassMember("numSkinBindings", dhkClassMember::DWORD, false, 76),
												  dhkClassMember("appliedTransform", dhkClassMember::MATRIX3, false, 80)};
const dhkClassMember dhkClassLibrary510::hkaSkeletonMembers[7] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
												dhkClassMember("parentIndices", dhkClassMember::PTR_WORD, true, 4),
												dhkClassMember("numParentIndices", dhkClassMember::DWORD, false, 8),
												dhkClassMember("bones", dhkClassMember::PTR_IGNORE, true, 12),
												dhkClassMember("numBones", dhkClassMember::DWORD, false, 16),
												dhkClassMember("referencePose", dhkClassMember::PTR_CLASS, true, 20, "hkQsTransform"),
												dhkClassMember("numReferencePose", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary510::hkQsTransformMembers[3] = { dhkClassMember("translation", dhkClassMember::VECTOR4, false, 0),
													dhkClassMember("rotation", dhkClassMember::VECTOR4, false, 16),
													dhkClassMember("scale", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary510::hkaBoneMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
											dhkClassMember("lockTranslation", dhkClassMember::BYTE, false, 4)};

const dhkClassMember dhkClassLibrary510::hkpPhysicsDataMembers[2] = { dhkClassMember("worldCinfo", dhkClassMember::PTR_IGNORE, false, 8),
											dhkClassMember("systems", dhkClassMember::CLASS, false, 12, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary510::hkpPhysicsDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkpPhysicsSystemMembers[7] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("actions", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("phantoms", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 56),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 60),
													dhkClassMember("active", dhkClassMember::BYTE, false, 64)};
const char* dhkClassLibrary510::hkpPhysicsSystemParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkpCdBodyMembers[4] = { dhkClassMember("shape", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("shapeKey", dhkClassMember::DWORD, false, 4),
												dhkClassMember("motion", dhkClassMember::PTR_IGNORE, false, 8),
												dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary510::hkpBroadPhaseHandleMembers[1] = { dhkClassMember("id", dhkClassMember::DWORD, false, 0)};
const dhkClassMember dhkClassLibrary510::hkpTypedBroadPhaseHandleMembers[4] = { dhkClassMember("type", dhkClassMember::BYTE, false, 4),
															dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 5),
															dhkClassMember("objectQualityType", dhkClassMember::WORD, false, 6),
															dhkClassMember("collisionFilterInfo", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary510::hkpTypedBroadPhaseHandleParents[1] = { "hkpBroadPhaseHandle" };
const dhkClassMember dhkClassLibrary510::hkpCollidableBoundingVolumeDataMembers[16] = { dhkClassMember("min_0", dhkClassMember::DWORD, false, 0),
																	dhkClassMember("min_1", dhkClassMember::DWORD, false, 4),
																	dhkClassMember("min_2", dhkClassMember::DWORD, false, 8),
																	dhkClassMember("expansionMin_0", dhkClassMember::BYTE, false, 12),
																	dhkClassMember("expansionMin_1", dhkClassMember::BYTE, false, 13),
																	dhkClassMember("expansionMin_2", dhkClassMember::BYTE, false, 14),
																	dhkClassMember("expansionShift", dhkClassMember::BYTE, false, 15),
																	dhkClassMember("max_0", dhkClassMember::DWORD, false, 16),
																	dhkClassMember("max_1", dhkClassMember::DWORD, false, 20),
																	dhkClassMember("max_2", dhkClassMember::DWORD, false, 24),
																	dhkClassMember("expansionMax_0", dhkClassMember::BYTE, false, 28),
																	dhkClassMember("expansionMax_1", dhkClassMember::BYTE, false, 29),
																	dhkClassMember("expansionMax_2", dhkClassMember::BYTE, false, 30),
																	dhkClassMember("padding", dhkClassMember::BYTE, false, 31),
																	dhkClassMember("numChildShapeAabbs", dhkClassMember::DWORD, false, 32),	//<--
																	dhkClassMember("childShapeAabbs", dhkClassMember::PTR_IGNORE, true, 36)}; //this is bullshit. would have to be hardcoded as well
const char* dhkClassLibrary510::hkpCollidableParents[1] = { "hkpCdBody" };
const dhkClassMember dhkClassLibrary510::hkpCollidableMembers[6] = { dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 16),
													dhkClassMember("forceCollideOntoPpu", dhkClassMember::BYTE, false, 17),
													dhkClassMember("shapeSizeOnSpu", dhkClassMember::WORD, false, 18),
													dhkClassMember("broadPhaseHandle", dhkClassMember::CLASS, false, 20, "hkpTypedBroadPhaseHandle"),
													dhkClassMember("boundingVolumeData", dhkClassMember::CLASS, false, 32, "hkpCollidableBoundingVolumeData"),
													dhkClassMember("allowedPenetrationDepth", dhkClassMember::DWORD, false, 72)};
const dhkClassMember dhkClassLibrary510::hkpLinkedCollidableMembers[1] = { dhkClassMember("collisionEntries", dhkClassMember::CLASS, false, 76, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary510::hkpLinkedCollidableParents[1] = { "hkpCollidable" };
const dhkClassMember dhkClassLibrary510::hkMultiThreadCheckMembers[3] = { dhkClassMember("threadId", dhkClassMember::DWORD, false, 0),
													dhkClassMember("markCount", dhkClassMember::WORD, false, 4),
													dhkClassMember("markBitStack", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary510::hkpPropertyValueMembers[1] = { dhkClassMember("data", dhkClassMember::QWORD, false, 0)};
const dhkClassMember dhkClassLibrary510::hkpPropertyMembers[3] = { dhkClassMember("key", dhkClassMember::DWORD, false, 0),
												dhkClassMember("alignmentPadding", dhkClassMember::DWORD, false, 4),
												dhkClassMember("value", dhkClassMember::CLASS, false, 8, "hkpPropertyValue")};
const dhkClassMember dhkClassLibrary510::hkpMaterialMembers[3] = { dhkClassMember("responseType", dhkClassMember::BYTE, false, 0),
												dhkClassMember("friction", dhkClassMember::DWORD, false, 4),
												dhkClassMember("restitution", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary510::hkpWorldObjectMembers[6] = { dhkClassMember("world", dhkClassMember::PTR_IGNORE, false, 8),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 12),
													dhkClassMember("collidable", dhkClassMember::CLASS, false, 16, "hkpLinkedCollidable"),
													dhkClassMember("multiThreadCheck", dhkClassMember::CLASS, false, 104, "hkMultiThreadCheck"),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 112),
													dhkClassMember("properties", dhkClassMember::CLASS, false, 116, "hkArray", dhkClassMember::PTR_IGNORE)}; //TODO: I think I'm ignoring this??
const char* dhkClassLibrary510::hkpWorldObjectParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkTransformMembers[2] = { dhkClassMember("rotation", dhkClassMember::MATRIX3, false, 0),
												dhkClassMember("translation", dhkClassMember::VECTOR4, false, 48)};
const dhkClassMember dhkClassLibrary510::hkSweptTransformMembers[5] = { dhkClassMember("centerOfMass0", dhkClassMember::VECTOR4, false, 0),
											dhkClassMember("centerOfMass1", dhkClassMember::VECTOR4, false, 16),
											dhkClassMember("rotation0", dhkClassMember::VECTOR4, false, 32),
											dhkClassMember("rotation1", dhkClassMember::VECTOR4, false, 48),
											dhkClassMember("centerOfMassLocal", dhkClassMember::VECTOR4, false, 64)};
const dhkClassMember dhkClassLibrary510::hkMotionStateMembers[9] = { dhkClassMember("transform", dhkClassMember::CLASS, false, 0, "hkTransform"),
													dhkClassMember("sweptTransform", dhkClassMember::CLASS, false, 64, "hkSweptTransform"),
													dhkClassMember("deltaAngle", dhkClassMember::VECTOR4, false, 144),
													dhkClassMember("objectRadius", dhkClassMember::DWORD, false, 160),
													dhkClassMember("linearDamping", dhkClassMember::DWORD, false, 164),
													dhkClassMember("angularDamping", dhkClassMember::DWORD, false, 168),
													dhkClassMember("maxLinearVelocity", dhkClassMember::BYTE, false, 172),
													dhkClassMember("maxAngularVelocity", dhkClassMember::BYTE, false, 173),
													dhkClassMember("deactivationClass", dhkClassMember::BYTE, false, 174)};

const dhkClassMember dhkClassLibrary510::hkpMotionMembers[14] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8),
												dhkClassMember("deactivationIntegrateCounter", dhkClassMember::BYTE, false, 9),
												dhkClassMember("deactivationNumInactiveFrames_0", dhkClassMember::WORD, false, 10),
												dhkClassMember("deactivationNumInactiveFrames_1", dhkClassMember::WORD, false, 12),
												dhkClassMember("motionState", dhkClassMember::CLASS, false, 16, "hkMotionState"),
												dhkClassMember("inertiaAndMassInv", dhkClassMember::VECTOR4, false, 192),
												dhkClassMember("linearVelocity", dhkClassMember::VECTOR4, false, 208),
												dhkClassMember("angularVelocity", dhkClassMember::VECTOR4, false, 224),
												dhkClassMember("deactivationRefPosition_0", dhkClassMember::VECTOR4, false, 240),
												dhkClassMember("deactivationRefPosition_1", dhkClassMember::VECTOR4, false, 256),
												dhkClassMember("deactivationRefOrientation_0", dhkClassMember::DWORD, false, 272),
												dhkClassMember("deactivationRefOrientation_1", dhkClassMember::DWORD, false, 276),
												dhkClassMember("savedMotion", dhkClassMember::PTR_IGNORE, false, 280),
												dhkClassMember("savedQualityTypeIndex", dhkClassMember::WORD, false, 284)};
const char* dhkClassLibrary510::hkpMotionParents[1] = { "hkReferencedObject" };
const char* dhkClassLibrary510::hkpKeyframedRigidMotionParents[1] = { "hkpMotion" };
const char* dhkClassLibrary510::hkpMaxSizeMotionParents[1] = { "hkpKeyframedRigidMotion" };
const dhkClassMember dhkClassLibrary510::hkpEntitySpuCollisionCallbackMembers[4] = { dhkClassMember("util", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("capacity", dhkClassMember::WORD, false, 4),
																	dhkClassMember("eventFilter", dhkClassMember::BYTE, false, 6),
																	dhkClassMember("userFilter", dhkClassMember::BYTE, false, 7)};
const char* dhkClassLibrary510::hkpEntityParents[1] = { "hkpWorldObject" };
const dhkClassMember dhkClassLibrary510::hkpEntityMembers[17] = { dhkClassMember("material", dhkClassMember::CLASS, false, 128, "hkpMaterial"),
											dhkClassMember("breakOffPartsUtil", dhkClassMember::PTR_IGNORE, false, 140),
											dhkClassMember("solverData", dhkClassMember::DWORD, false, 144),
											dhkClassMember("storageIndex", dhkClassMember::WORD, false, 148),
											dhkClassMember("processContactCallbackDelay", dhkClassMember::WORD, false, 150),
											dhkClassMember("constraintsMaster", dhkClassMember::CLASS, false, 152, "hkSmallArray", dhkClassMember::PTR_IGNORE), //hkConstraintInternal
											dhkClassMember("constraintsSlave", dhkClassMember::CLASS, false, 160, "hkArray", dhkClassMember::PTR_IGNORE), //hkpConstraintInstance
											dhkClassMember("constraintRuntime", dhkClassMember::CLASS, false, 172, "hkArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("simulationIsland", dhkClassMember::PTR_IGNORE, false, 184), //hkpSimulationIsland
											dhkClassMember("autoRemoveLevel", dhkClassMember::BYTE, false, 188),
											dhkClassMember("numUserDatasInContactPointProperties", dhkClassMember::BYTE, false, 189),
											dhkClassMember("uid", dhkClassMember::DWORD, false, 192),
											dhkClassMember("spuCollisionCallback", dhkClassMember::CLASS, false, 196, "hkpEntitySpuCollisionCallback"),
											dhkClassMember("extendedListeners", dhkClassMember::PTR_IGNORE, false, 204),
											dhkClassMember("motion", dhkClassMember::CLASS, false, 208, "hkpMaxSizeMotion"),
											dhkClassMember("collisionListeners", dhkClassMember::CLASS, false, 496, "hkSmallArray", dhkClassMember::PTR_IGNORE),
											dhkClassMember("actions", dhkClassMember::CLASS, false, 504, "hkSmallArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary510::hkpRigidBodyParents[1] = { "hkpEntity" };
const char* dhkClassLibrary510::hkpShapeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkpShapeMembers[2] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8),
											dhkClassMember("type", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary510::hkpSphereRepShapeParents[1] = { "hkpShape" };
const dhkClassMember dhkClassLibrary510::hkpConvexShapeMembers[1] = { dhkClassMember("radius", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary510::hkpConvexShapeParents[1] = { "hkpSphereRepShape" };
const dhkClassMember dhkClassLibrary510::hkpCapsuleShapeMembers[2] = { dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48)};
const char* dhkClassLibrary510::hkpCapsuleShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary510::hkpConstraintDataMembers[1] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary510::hkpConstraintDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkpConstraintAtomMembers[1] = { dhkClassMember("type", dhkClassMember::WORD, false, 0)};
const dhkClassMember dhkClassLibrary510::hkpSetLocalTransformsConstraintAtomMembers[2] = { dhkClassMember("transformA", dhkClassMember::CLASS, false, 16, "hkTransform"),
																		dhkClassMember("transformB", dhkClassMember::CLASS, false, 80, "hkTransform")};
const char* dhkClassLibrary510::hkpSetLocalTransformsConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpRagdollMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
																dhkClassMember("previousTargetAnglesOffset", dhkClassMember::WORD, false, 6),
																dhkClassMember("targetFrameAinB", dhkClassMember::MATRIX3, false, 16),
																dhkClassMember("motors_0", dhkClassMember::PTR_IGNORE, false, 64),
																dhkClassMember("motors_1", dhkClassMember::PTR_IGNORE, false, 68),
																dhkClassMember("motors_2", dhkClassMember::PTR_IGNORE, false, 72)};
const char* dhkClassLibrary510::hkpRagdollMotorConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpAngFrictionConstraintAtomMembers[4] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("firstFrictionAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("numFrictionAxes", dhkClassMember::BYTE, false, 4),
																dhkClassMember("maxFrictionTorque", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary510::hkpAngFrictionConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpTwistLimitConstraintAtomMembers[6] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxis", dhkClassMember::BYTE, false, 4),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary510::hkpTwistLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpConeLimitConstraintAtomMembers[8] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxisInA", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxisInB", dhkClassMember::BYTE, false, 4),
																dhkClassMember("angleMeasurementMode", dhkClassMember::BYTE, false, 5),
																dhkClassMember("memOffsetToAngleOffset", dhkClassMember::BYTE, false, 6),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary510::hkpConeLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const char* dhkClassLibrary510::hkpBallSocketConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpRagdollConstraintDataAtomsMembers[7] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkpSetLocalTransformsConstraintAtom"),
														  dhkClassMember("ragdollMotors", dhkClassMember::CLASS, false, 144, "hkpRagdollMotorConstraintAtom"),
														  dhkClassMember("angFriction", dhkClassMember::CLASS, false, 224, "hkpAngFrictionConstraintAtom"),
														  dhkClassMember("twistLimit", dhkClassMember::CLASS, false, 236, "hkpTwistLimitConstraintAtom"),
														  dhkClassMember("coneLimit", dhkClassMember::CLASS, false, 256, "hkpConeLimitConstraintAtom"),
														  dhkClassMember("planesLimit", dhkClassMember::CLASS, false, 276, "hkpConeLimitConstraintAtom"),
														  dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 296, "hkpBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary510::hkpRagdollConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkpRagdollConstraintDataAtoms")};
const char* dhkClassLibrary510::hkpRagdollConstraintDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary510::hkpConstraintInstanceMembers[10] = { dhkClassMember("owner", dhkClassMember::PTR_IGNORE, false, 8), //hkpConstraintOwner
														dhkClassMember("data", dhkClassMember::PTR_IGNORE, false, 12),	//hkpConstraintData
														dhkClassMember("constraintModifiers", dhkClassMember::PTR_IGNORE, false, 16), //hkpModifierConstraintAtom
														dhkClassMember("entities_0", dhkClassMember::PTR_IGNORE, false, 20), //hkpEntity
														dhkClassMember("entities_1", dhkClassMember::PTR_IGNORE, false, 24),
														dhkClassMember("priority", dhkClassMember::BYTE, false, 28),
														dhkClassMember("wantRuntime", dhkClassMember::BYTE, false, 29),
														dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 32),
														dhkClassMember("userData", dhkClassMember::DWORD, false, 36),
														dhkClassMember("internal", dhkClassMember::PTR_IGNORE, false, 40)}; 
const char* dhkClassLibrary510::hkpConstraintInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkaRagdollInstanceMembers[4] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("boneToRigidBodyMap", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::DWORD),
														dhkClassMember("skeleton", dhkClassMember::PTR_IGNORE, false, 44)};
const char* dhkClassLibrary510::hkaRagdollInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkaSkeletonMapperDataSimpleMappingMembers[3] = { dhkClassMember("boneA", dhkClassMember::WORD, false, 0),
																		dhkClassMember("boneB", dhkClassMember::WORD, false, 2),
																		dhkClassMember("aFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform")};
const dhkClassMember dhkClassLibrary510::hkaSkeletonMapperDataChainMappingMembers[6] = { dhkClassMember("startBoneA", dhkClassMember::WORD, false, 0),
																	dhkClassMember("endBoneA", dhkClassMember::WORD, false, 2),
																	dhkClassMember("startBoneB", dhkClassMember::WORD, false, 4),
																	dhkClassMember("endBoneB", dhkClassMember::WORD, false, 6),
																	dhkClassMember("startAFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform"),
																	dhkClassMember("endAFromBTransform", dhkClassMember::CLASS, false, 64, "hkQsTransform")};
const dhkClassMember dhkClassLibrary510::hkaSkeletonMapperDataMembers[6] = { dhkClassMember("skeletonA", dhkClassMember::PTR_IGNORE, false, 0),
														dhkClassMember("skeletonB", dhkClassMember::PTR_IGNORE, false, 4),
														dhkClassMember("simpleMappings", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::CLASS, "hkaSkeletonMapperDataSimpleMapping"),
														dhkClassMember("chainMappings", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::CLASS, "hkaSkeletonMapperDataChainMapping"),
														dhkClassMember("unmappedBones", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::WORD),
														dhkClassMember("keepUnmappedLocal", dhkClassMember::BYTE, false, 44)};
const dhkClassMember dhkClassLibrary510::hkaSkeletonMapperMembers[1] = { dhkClassMember("mapping", dhkClassMember::CLASS, false, 8, "hkaSkeletonMapperData")};
const char* dhkClassLibrary510::hkaSkeletonMapperParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary510::hkpAngMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("motorAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
															dhkClassMember("previousTargetAngleOffset", dhkClassMember::WORD, false, 6),
															dhkClassMember("correspondingAngLimitSolverResultOffset", dhkClassMember::WORD, false, 8),
															dhkClassMember("targetAngle", dhkClassMember::DWORD, false, 12),
															dhkClassMember("motor", dhkClassMember::PTR_IGNORE, false, 16)}; //hkpConstraintMotor
const char* dhkClassLibrary510::hkpAngMotorConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpAngLimitConstraintAtomMembers[5] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("limitAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("minAngle", dhkClassMember::DWORD, false, 4),
															dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 8),
															dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary510::hkpAngLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkp2dAngConstraintAtomMembers[1] = { dhkClassMember("freeRotationAxis", dhkClassMember::BYTE, false, 2)};
const char* dhkClassLibrary510::hkp2dAngConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary510::hkpLimitedHingeConstraintDataAtomsMembers[6] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkpSetLocalTransformsConstraintAtom"),
																	dhkClassMember("angMotor", dhkClassMember::CLASS, false, 144, "hkpAngMotorConstraintAtom"),
																	dhkClassMember("angFriction", dhkClassMember::CLASS, false, 164, "hkpAngFrictionConstraintAtom"),
																	dhkClassMember("angLimit", dhkClassMember::CLASS, false, 176, "hkpAngLimitConstraintAtom"),
																	dhkClassMember("2dAng", dhkClassMember::CLASS, false, 192, "hkp2dAngConstraintAtom"),
																	dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 196, "hkpBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary510::hkpLimitedHingeConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkpLimitedHingeConstraintDataAtoms")};
const char* dhkClassLibrary510::hkpLimitedHingeConstraintDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary510::hkpConstraintMotorMembers[1] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8)};
const char* dhkClassLibrary510::hkpConstraintMotorParents[1] = { "hkReferencedObject" };
//const dhkClassMember dhkClassLibrary510::hkpMaxSizeConstraintMotorMembers[9] = { dhkClassMember("dummy_0", dhkClassMember::DWORD, false, 12),
//															dhkClassMember("dummy_1", dhkClassMember::DWORD, false, 16),
//															dhkClassMember("dummy_2", dhkClassMember::DWORD, false, 20),
//															dhkClassMember("dummy_3", dhkClassMember::DWORD, false, 24),
//															dhkClassMember("dummy_4", dhkClassMember::DWORD, false, 28),
//															dhkClassMember("dummy_5", dhkClassMember::DWORD, false, 32),
//															dhkClassMember("dummy_6", dhkClassMember::DWORD, false, 36),
//															dhkClassMember("dummy_7", dhkClassMember::DWORD, false, 40),
//															dhkClassMember("dummy_8", dhkClassMember::DWORD, false, 44)};
//const char* dhkClassLibrary510::hkpMaxSizeConstraintMotorParents[1] = { "hkpConstraintMotor" };
const dhkClassMember dhkClassLibrary510::hkpLimitedForceConstraintMotorMembers[2] = { dhkClassMember("minForce", dhkClassMember::DWORD, false, 12),
																	dhkClassMember("maxForce", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary510::hkpLimitedForceConstraintMotorParents[1] = { "hkpConstraintMotor" };
const dhkClassMember dhkClassLibrary510::hkpPositionConstraintMotorMembers[4] = { dhkClassMember("tau", dhkClassMember::DWORD, false, 20),
																dhkClassMember("damping", dhkClassMember::DWORD, false, 24),
																dhkClassMember("proportionalRecoveryVelocity", dhkClassMember::DWORD, false, 28),
																dhkClassMember("constantRecoveryVelocity", dhkClassMember::DWORD, false, 32)};
const char* dhkClassLibrary510::hkpPositionConstraintMotorParents[1] = { "hkpLimitedForceConstraintMotor" };
const dhkClassMember dhkClassLibrary510::hkpConvexVerticesShapeFourVectorsMembers[3] = { dhkClassMember("x", dhkClassMember::VECTOR4, false, 0),
												dhkClassMember("y", dhkClassMember::VECTOR4, false, 16),
												dhkClassMember("z", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary510::hkpConvexVerticesShapeMembers[5] = { dhkClassMember("aabbHalfExtents", dhkClassMember::VECTOR4, false, 32),
															dhkClassMember("aabbCenter", dhkClassMember::VECTOR4, false, 48),
															dhkClassMember("rotatedVertices", dhkClassMember::CLASS, false, 64, "hkArray", dhkClassMember::CLASS, "hkConvexVerticesShapeFourVectors"),
															dhkClassMember("numVertices", dhkClassMember::DWORD, false, 76),
															dhkClassMember("planeEquations", dhkClassMember::CLASS, false, 80, "hkArray", dhkClassMember::VECTOR4)};
const char* dhkClassLibrary510::hkpConvexVerticesShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary510::hkpSingleShapeContainerMembers[1] = { dhkClassMember("childShape", dhkClassMember::PTR_IGNORE, false, 0)}; //hkpShape
const char* dhkClassLibrary510::hkpSingleShapeContainerParents[1] = { "hkpShapeContainer" };
const dhkClassMember dhkClassLibrary510::hkpConvexTranslateShapeMembers[3] = { dhkClassMember("childShape", dhkClassMember::CLASS, false, 20, "hkpSingleShapeContainer"),
															dhkClassMember("childShapeSize", dhkClassMember::DWORD, false, 24),
															dhkClassMember("translation", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary510::hkpConvexTranslateShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary510::hkpBoxShapeMembers[1] = { dhkClassMember("halfExtents", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary510::hkpBoxShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary510::hkpSphereShapeMembers[3] = { dhkClassMember("pad16_0", dhkClassMember::DWORD, false, 20),
													dhkClassMember("pad16_1", dhkClassMember::DWORD, false, 24),
													dhkClassMember("pad16_2", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary510::hkpSphereShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary510::hkpCylinderShapeMembers[6] = { dhkClassMember("cylRadius", dhkClassMember::DWORD, false, 20),
													dhkClassMember("cylBaseRadiusFactorForHeightFieldCollisions", dhkClassMember::DWORD, false, 24),
													dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48),
													dhkClassMember("perpendicular1", dhkClassMember::VECTOR4, false, 64),
													dhkClassMember("perpendicular2", dhkClassMember::VECTOR4, false, 80)};
const char* dhkClassLibrary510::hkpCylinderShapeParents[1] = { "hkpConvexShape" };

dhkClassLibrary510::dhkClassLibrary510(void)
{
	m_classMap.insert(make_pair("hkRootLevelContainerNamedVariant", dhkClass("hkRootLevelContainerNamedVariant", NULL, 0, 16, hkRootLevelContainerNamedVariantMembers, 3)));
	m_classMap.insert(make_pair("hkRootLevelContainer", dhkClass("hkRootLevelContainer", NULL, 0, 16, hkRootLevelContainerMembers, 2)));
	m_classMap.insert(make_pair("hkVariant", dhkClass("hkVariant", NULL, 0, 8, hkVariantMembers, 2)));
	m_classMap.insert(make_pair("hkArray", dhkClass("hkArray", NULL, 0, 12, hkArrayMembers, 3)));
	m_classMap.insert(make_pair("hkSmallArray", dhkClass("hkSmallArray", NULL, 0, 8, hkSmallArrayMembers, 3)));
	m_classMap.insert(make_pair("hkaAnimationContainer", dhkClass("hkaAnimationContainer", NULL, 0, 40, hkaAnimationContainerMembers, 10)));
	m_classMap.insert(make_pair("hkReferencedObject", dhkClass("hkReferencedObject", NULL, 0, 8, hkReferencedObjectMembers, 2)));
	m_classMap.insert(make_pair("hkaSkeletalAnimation", dhkClass("hkaSkeletalAnimation", hkaSkeletalAnimationParents, 1, 0x20, hkaSkeletalAnimationMembers, 6)));
	m_classMap.insert(make_pair("hkaWaveletSkeletalAnimation", dhkClass("hkaWaveletSkeletalAnimation", hkaWaveletSkeletalAnimationParents, 1, 92, hkaWaveletSkeletalAnimationMembers, 11)));
	m_classMap.insert(make_pair("hkaWaveletSkeletalAnimationQuantizationFormat", dhkClass("hkaWaveletSkeletalAnimationQuantizationFormat", NULL, 0, 20, hkaWaveletSkeletalAnimationQuantizationFormatMembers, 6)));
	m_classMap.insert(make_pair("hkaInterleavedSkeletalAnimation", dhkClass("hkaInterleavedSkeletalAnimation", hkaInterleavedSkeletalAnimationParents, 1, 40, hkaInterleavedSkeletalAnimationMembers, 2)));
	m_classMap.insert(make_pair("hkaDeltaCompressedSkeletalAnimation", dhkClass("hkaDeltaCompressedSkeletalAnimation", hkaDeltaCompressedSkeletalAnimationParents, 1, 100, hkaDeltaCompressedSkeletalAnimationMembers, 13)));
	m_classMap.insert(make_pair("hkaDefaultAnimatedReferenceFrame", dhkClass("hkaDefaultAnimatedReferenceFrame", hkaDefaultAnimatedReferenceFrameMembersParents, 1, 0x40, hkaDefaultAnimatedReferenceFrameMembers, 5)));
	//m_classMap550.insert(make_pair("hkVector4", new dhkClass("hkVector4", NULL, 0, 16, hkVector4Members, 4)));
	m_classMap.insert(make_pair("hkaAnnotationTrack", dhkClass("hkaAnnotationTrack", NULL, 0, 16, hkaAnnotationTrackMembers, 3)));
	m_classMap.insert(make_pair("hkaAnnotationTrackAnnotation", dhkClass("hkaAnnotationTrackAnnotation", NULL, 0, 16, hkaAnnotationTrackAnnotationMembers, 2)));
	m_classMap.insert(make_pair("hkaAnimationBinding", dhkClass("hkaAnimationBinding", NULL, 0, 0x10, hkaAnimationBindingMembers, 4)));
	m_classMap.insert(make_pair("hkxScene", dhkClass("hkxScene", NULL, 0, 0x80, hkxSceneMembers, 21)));
	m_classMap.insert(make_pair("hkaSkeleton", dhkClass("hkaSkeleton", NULL, 0, 0x1C, hkaSkeletonMembers, 7)));
	m_classMap.insert(make_pair("hkQsTransform", dhkClass("hkQsTransform", NULL, 0, 0x30, hkQsTransformMembers, 3)));
	m_classMap.insert(make_pair("hkaBone", dhkClass("hkaBone", NULL, 0, 16, hkaBoneMembers, 2)));
	m_classMap.insert(make_pair("hkpPhysicsData", dhkClass("hkpPhysicsData", hkpPhysicsDataParents, 1, 24, hkpPhysicsDataMembers, 2)));
	m_classMap.insert(make_pair("hkpPhysicsSystem", dhkClass("hkpPhysicsSystem", hkpPhysicsSystemParents, 1, 68, hkpPhysicsSystemMembers, 7)));
	m_classMap.insert(make_pair("hkpCdBody", dhkClass("hkpCdBody", NULL, 0, 16, hkpCdBodyMembers, 4)));
	m_classMap.insert(make_pair("hkpBroadPhaseHandle", dhkClass("hkpBroadPhaseHandle", NULL, 0, 4, hkpBroadPhaseHandleMembers, 1)));
	m_classMap.insert(make_pair("hkpTypedBroadPhaseHandle", dhkClass("hkpTypedBroadPhaseHandle", hkpTypedBroadPhaseHandleParents, 1, 12, hkpTypedBroadPhaseHandleMembers, 4)));
	m_classMap.insert(make_pair("hkpCollidableBoundingVolumeData", dhkClass("hkpCollidableBoundingVolumeData", NULL, 0, 40, hkpCollidableBoundingVolumeDataMembers, 16)));
	m_classMap.insert(make_pair("hkpCollidable", dhkClass("hkpCollidable", hkpCollidableParents, 1, 76, hkpCollidableMembers, 6)));
	m_classMap.insert(make_pair("hkpLinkedCollidable", dhkClass("hkpLinkedCollidable", hkpLinkedCollidableParents, 1, 88, hkpLinkedCollidableMembers, 1)));
	m_classMap.insert(make_pair("hkMultiThreadCheck", dhkClass("hkMultiThreadCheck", NULL, 0, 8, hkMultiThreadCheckMembers, 3)));
	m_classMap.insert(make_pair("hkpPropertyValue", dhkClass("hkpPropertyValue", NULL, 0, 8, hkpPropertyValueMembers, 1)));
	m_classMap.insert(make_pair("hkpProperty", dhkClass("hkpProperty", NULL, 0, 16, hkpPropertyMembers, 3)));
	m_classMap.insert(make_pair("hkpMaterial", dhkClass("hkpMaterial", NULL, 0, 12, hkpMaterialMembers, 3)));
	m_classMap.insert(make_pair("hkpWorldObject", dhkClass("hkpWorldObject", hkpWorldObjectParents, 1, 128, hkpWorldObjectMembers, 6)));
	m_classMap.insert(make_pair("hkTransform", dhkClass("hkTransform", NULL, 0, 64, hkTransformMembers, 2)));
	m_classMap.insert(make_pair("hkSweptTransform", dhkClass("hkSweptTransform", NULL, 0, 80, hkSweptTransformMembers, 5)));
	m_classMap.insert(make_pair("hkMotionState", dhkClass("hkMotionState", NULL, 0, 178, hkMotionStateMembers, 9)));
	m_classMap.insert(make_pair("hkpMotion", dhkClass("hkpMotion", hkpMotionParents, 1, 288, hkpMotionMembers, 14)));
	m_classMap.insert(make_pair("hkpKeyframedRigidMotion", dhkClass("hkpKeyframedRigidMotion", hkpKeyframedRigidMotionParents, 1, 288, NULL, 0)));
	m_classMap.insert(make_pair("hkpMaxSizeMotion", dhkClass("hkpMaxSizeMotion", hkpMaxSizeMotionParents, 1, 288, NULL, 0)));
	m_classMap.insert(make_pair("hkpEntitySpuCollisionCallback", dhkClass("hkpEntitySpuCollisionCallback", NULL, 0, 8, hkpEntitySpuCollisionCallbackMembers, 4)));
	m_classMap.insert(make_pair("hkpEntity", dhkClass("hkpEntity", hkpEntityParents, 1, 512, hkpEntityMembers, 17)));
	m_classMap.insert(make_pair("hkpRigidBody", dhkClass("hkpRigidBody", hkpRigidBodyParents, 1, 512, NULL, 0)));
	m_classMap.insert(make_pair("hkpShape", dhkClass("hkpShape", hkpShapeParents, 1, 16, hkpShapeMembers, 2)));
	m_classMap.insert(make_pair("hkpSphereRepShape", dhkClass("hkpSphereRepShape", hkpSphereRepShapeParents, 1, 16, NULL, 0)));
	m_classMap.insert(make_pair("hkpConvexShape", dhkClass("hkpConvexShape", hkpConvexShapeParents, 1, 20, hkpConvexShapeMembers, 1)));
	m_classMap.insert(make_pair("hkpCapsuleShape", dhkClass("hkpCapsuleShape", hkpCapsuleShapeParents, 1, 64, hkpCapsuleShapeMembers, 2)));
	m_classMap.insert(make_pair("hkpConstraintData", dhkClass("hkpConstraintData", hkpConstraintDataParents, 1, 12, hkpConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkpConstraintAtom", dhkClass("hkpConstraintAtom", NULL, 0, 4, hkpConstraintAtomMembers, 1)));
	m_classMap.insert(make_pair("hkpSetLocalTransformsConstraintAtom", dhkClass("hkpSetLocalTransformsConstraintAtom", hkpSetLocalTransformsConstraintAtomParents, 1, 144, hkpSetLocalTransformsConstraintAtomMembers, 2)));
	m_classMap.insert(make_pair("hkpRagdollMotorConstraintAtom", dhkClass("hkpRagdollMotorConstraintAtom", hkpRagdollMotorConstraintAtomParents, 1, 80, hkpRagdollMotorConstraintAtomMembers, 7)));
	m_classMap.insert(make_pair("hkpAngFrictionConstraintAtom", dhkClass("hkpAngFrictionConstraintAtom", hkpAngFrictionConstraintAtomParents, 1, 12, hkpAngFrictionConstraintAtomMembers, 4)));
	m_classMap.insert(make_pair("hkpTwistLimitConstraintAtom", dhkClass("hkpTwistLimitConstraintAtom", hkpTwistLimitConstraintAtomParents, 1, 20, hkpTwistLimitConstraintAtomMembers, 6)));
	m_classMap.insert(make_pair("hkpConeLimitConstraintAtom", dhkClass("hkpConeLimitConstraintAtom", hkpConeLimitConstraintAtomParents, 1, 20, hkpConeLimitConstraintAtomMembers, 8)));
	m_classMap.insert(make_pair("hkpBallSocketConstraintAtom", dhkClass("hkpBallSocketConstraintAtom", hkpBallSocketConstraintAtomParents, 1, 4, NULL, 0)));
	m_classMap.insert(make_pair("hkpRagdollConstraintDataAtoms", dhkClass("hkpRagdollConstraintDataAtoms", NULL, 0, 300, hkpRagdollConstraintDataAtomsMembers, 7)));
	m_classMap.insert(make_pair("hkpRagdollConstraintData", dhkClass("hkpRagdollConstraintData", hkpRagdollConstraintDataParents, 1, 316, hkpRagdollConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkpConstraintInstance", dhkClass("hkpConstraintInstance", hkpConstraintInstanceParents, 1, 44, hkpConstraintInstanceMembers, 10)));
	m_classMap.insert(make_pair("hkaRagdollInstance", dhkClass("hkaRagdollInstance", hkaRagdollInstanceParents, 1, 48, hkaRagdollInstanceMembers, 4)));
	m_classMap.insert(make_pair("hkaSkeletonMapperDataSimpleMapping", dhkClass("hkaSkeletonMapperDataSimpleMapping", NULL, 0, 64, hkaSkeletonMapperDataSimpleMappingMembers, 3)));
	m_classMap.insert(make_pair("hkaSkeletonMapperDataChainMapping", dhkClass("hkaSkeletonMapperDataChainMapping", NULL, 0, 112, hkaSkeletonMapperDataChainMappingMembers, 6)));
	m_classMap.insert(make_pair("hkaSkeletonMapperData", dhkClass("hkaSkeletonMapperData", NULL, 0, 48, hkaSkeletonMapperDataMembers, 6)));
	m_classMap.insert(make_pair("hkaSkeletonMapper", dhkClass("hkaSkeletonMapper", hkaSkeletonMapperParents, 1, 56, hkaSkeletonMapperMembers, 1)));
	m_classMap.insert(make_pair("hkpAngMotorConstraintAtom", dhkClass("hkpAngMotorConstraintAtom", hkpAngMotorConstraintAtomParents, 1, 20, hkpAngMotorConstraintAtomMembers, 7)));
	m_classMap.insert(make_pair("hkpAngLimitConstraintAtom", dhkClass("hkpAngLimitConstraintAtom", hkpAngLimitConstraintAtomParents, 1, 16, hkpAngLimitConstraintAtomMembers, 5)));
	m_classMap.insert(make_pair("hkp2dAngConstraintAtom", dhkClass("hkp2dAngConstraintAtom", hkp2dAngConstraintAtomParents, 1, 4, hkp2dAngConstraintAtomMembers, 1)));
	m_classMap.insert(make_pair("hkpLimitedHingeConstraintDataAtoms", dhkClass("hkpLimitedHingeConstraintDataAtoms", NULL, 0, 200, hkpLimitedHingeConstraintDataAtomsMembers, 6)));
	m_classMap.insert(make_pair("hkpLimitedHingeConstraintData", dhkClass("hkpLimitedHingeConstraintData", hkpLimitedHingeConstraintDataParents, 1, 216, hkpLimitedHingeConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkpConstraintMotor", dhkClass("hkpConstraintMotor", hkpConstraintMotorParents, 1, 12, hkpConstraintMotorMembers, 1)));
	//m_classMap.insert(make_pair("hkpMaxSizeConstraintMotor", dhkClass("hkpMaxSizeConstraintMotor", hkpMaxSizeConstraintMotorParents, 1, 48, hkpMaxSizeConstraintMotorMembers, 9)));
	m_classMap.insert(make_pair("hkpLimitedForceConstraintMotor", dhkClass("hkpLimitedForceConstraintMotor", hkpLimitedForceConstraintMotorParents, 1, 20, hkpLimitedForceConstraintMotorMembers, 2)));
	m_classMap.insert(make_pair("hkpPositionConstraintMotor", dhkClass("hkpPositionConstraintMotor", hkpPositionConstraintMotorParents, 1, 36, hkpPositionConstraintMotorMembers, 4)));
	m_classMap.insert(make_pair("hkpConvexVerticesShapeFourVectors", dhkClass("hkpConvexVerticesShapeFourVectors", NULL, 0, 48, hkpConvexVerticesShapeFourVectorsMembers, 3)));
	m_classMap.insert(make_pair("hkpConvexVerticesShape", dhkClass("hkpConvexVerticesShape", hkpConvexVerticesShapeParents, 1, 92, hkpConvexVerticesShapeMembers, 5)));
	m_classMap.insert(make_pair("hkpSingleShapeContainer", dhkClass("hkpSingleShapeContainer", hkpSingleShapeContainerParents, 1, 4, hkpSingleShapeContainerMembers, 1)));
	m_classMap.insert(make_pair("hkpShapeContainer", dhkClass("hkpShapeContainer", NULL, 0, 0, NULL, 0)));
	m_classMap.insert(make_pair("hkpConvexTranslateShape", dhkClass("hkpConvexTranslateShape", hkpConvexTranslateShapeParents, 1, 48, hkpConvexTranslateShapeMembers, 3)));
	m_classMap.insert(make_pair("hkpBoxShape", dhkClass("hkpBoxShape", hkpBoxShapeParents, 1, 48, hkpBoxShapeMembers, 1)));
	m_classMap.insert(make_pair("hkpSphereShape", dhkClass("hkpSphereShape", hkpSphereShapeParents, 1, 32, hkpSphereShapeMembers, 3)));
	m_classMap.insert(make_pair("hkpCylinderShape", dhkClass("hkpCylinderShape", hkpCylinderShapeParents, 1, 96, hkpCylinderShapeMembers, 6)));
}


dhkClassLibrary510::~dhkClassLibrary510(void)
{
}

dhkClass* dhkClassLibrary510::getClass(const char* className) {
	try {
		return &m_classMap.at(className);
	} catch (const out_of_range& e) {
		printf("Couldn't find class %s in library!\n", className);
		return 0;
	}
}
