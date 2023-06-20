#include "dhkClassLibrary550.h"

const dhkClassMember dhkClassLibrary550::hkRootLevelContainerNamedVariantMembers[] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0), 
																		 dhkClassMember("className", dhkClassMember::PTR_IGNORE, true, 4), 
																		 dhkClassMember("variant", dhkClassMember::CLASS, false, 8, "hkVariant") };
const dhkClassMember dhkClassLibrary550::hkRootLevelContainerMembers[2] = { dhkClassMember("namedVariants", dhkClassMember::PTR_CLASS, true, 0, "hkRootLevelContainerNamedVariant"),
															 dhkClassMember("numNamedVariants", dhkClassMember::DWORD, false, 4) };
const dhkClassMember dhkClassLibrary550::hkVariantMembers[2] = { dhkClassMember("object", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary550::hkArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0), 
												dhkClassMember("size", dhkClassMember::DWORD, false, 4), 
												dhkClassMember("capacityAndFlags", dhkClassMember::DWORD, false, 8) };
const dhkClassMember dhkClassLibrary550::hkSmallArrayMembers[3] = { dhkClassMember("data", dhkClassMember::PTR_GENERIC, true, 0),
											dhkClassMember("size", dhkClassMember::WORD, false, 4), //uh oh
											dhkClassMember("capacityAndFlags", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary550::hkaAnimationContainerMembers[10] = { dhkClassMember("skeletons", dhkClassMember::PTR_IGNORE, true, 0), 
															   dhkClassMember("numSkeletons", dhkClassMember::DWORD, false, 4), 
															   dhkClassMember("animations", dhkClassMember::PTR_IGNORE, true, 8),
															   dhkClassMember("numAnimations", dhkClassMember::DWORD, false, 12),
															   dhkClassMember("bindings", dhkClassMember::PTR_IGNORE, true, 16),
															   dhkClassMember("numBindings", dhkClassMember::DWORD, false, 20),
															   dhkClassMember("attachments", dhkClassMember::PTR_IGNORE, true, 24),
															   dhkClassMember("numAttachments", dhkClassMember::DWORD, false, 28),
															   dhkClassMember("skins", dhkClassMember::PTR_IGNORE, true, 32),
															   dhkClassMember("numSkins", dhkClassMember::DWORD, false, 36)};
const dhkClassMember dhkClassLibrary550::hkReferencedObjectMembers[2] = { dhkClassMember("memSizeAndFlags", dhkClassMember::WORD, false, 4),
														   dhkClassMember("referenceCount", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary550::hkaSkeletalAnimationMembers[7] = { dhkClassMember("type", dhkClassMember::DWORD, false, 8),
															 dhkClassMember("duration", dhkClassMember::DWORD, false, 12),
															 dhkClassMember("numberOfTransformTracks", dhkClassMember::DWORD, false, 16),
															 dhkClassMember("numberOfFloatTracks", dhkClassMember::DWORD, false, 20),
															 dhkClassMember("extractedMotion", dhkClassMember::PTR_CLASS, false, 24), //not sure
															 dhkClassMember("annotationTracks", dhkClassMember::PTR_IGNORE, true, 28),
															 dhkClassMember("numAnnotationTracks", dhkClassMember::DWORD, false, 32)};
const char* dhkClassLibrary550::hkaSkeletalAnimationParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkaWaveletSkeletalAnimationMembers[11] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 36),
																	 dhkClassMember("blockSize", dhkClassMember::DWORD, false, 40),
																	 dhkClassMember("qFormat", dhkClassMember::CLASS, false, 44, "hkaWaveletSkeletalAnimationQuantizationFormat"),
																	 dhkClassMember("staticMaskIdx", dhkClassMember::DWORD, false, 64),
																	 dhkClassMember("staticDOFsIdx", dhkClassMember::DWORD, false, 68),
																	 dhkClassMember("blockIndexIdx", dhkClassMember::DWORD, false, 72),
																	 dhkClassMember("blockIndexSize", dhkClassMember::DWORD, false, 76),
																	 dhkClassMember("quantizedDataIdx", dhkClassMember::DWORD, false, 80),
																	 dhkClassMember("quantizedDataSize", dhkClassMember::DWORD, false, 84),
																	 dhkClassMember("dataBuffer", dhkClassMember::PTR_IGNORE, true, 88),
																	 dhkClassMember("numDataBuffer", dhkClassMember::DWORD, false, 92)};
const char* dhkClassLibrary550::hkaWaveletSkeletalAnimationParents[1] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary550::hkaWaveletSkeletalAnimationQuantizationFormatMembers[6] = { dhkClassMember("maxBitWidth", dhkClassMember::BYTE, false, 0),
																					 dhkClassMember("preserved", dhkClassMember::BYTE, false, 1),
																					 dhkClassMember("numD", dhkClassMember::DWORD, false, 4),
																					 dhkClassMember("offsetIdx", dhkClassMember::DWORD, false, 8),
																					 dhkClassMember("scaleIdx", dhkClassMember::DWORD, false, 12),
																					 dhkClassMember("bitWidthIdx", dhkClassMember::DWORD, false, 16)};
const dhkClassMember dhkClassLibrary550::hkaInterleavedSkeletalAnimationMembers[4] = { dhkClassMember("transforms", dhkClassMember::PTR_CLASS, true, 36, "hkQsTransform"),
																						dhkClassMember("numTransforms", dhkClassMember::DWORD, false, 40),
																						dhkClassMember("floats", dhkClassMember::PTR_DWORD, true, 44),
																						dhkClassMember("numFloats", dhkClassMember::DWORD, false, 48)};
const char* dhkClassLibrary550::hkaInterleavedSkeletalAnimationParents[1] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary550::hkaDeltaCompressedSkeletalAnimationMembers[13] = { dhkClassMember("numberOfPoses", dhkClassMember::DWORD, false, 36),
																							dhkClassMember("blockSize", dhkClassMember::DWORD, false, 40),
																							dhkClassMember("qFormat", dhkClassMember::CLASS, false, 44, "hkaWaveletSkeletalAnimationQuantizationFormat"),
																							dhkClassMember("quantizedDataIdx", dhkClassMember::DWORD, false, 64),
																							dhkClassMember("quantizedDataSize", dhkClassMember::DWORD, false, 68),
																							dhkClassMember("staticMaskIdx", dhkClassMember::DWORD, false, 72),
																							dhkClassMember("staticMaskSize", dhkClassMember::DWORD, false, 76),
																							dhkClassMember("staticDOFsIdx", dhkClassMember::DWORD, false, 80),
																							dhkClassMember("staticDOFsSize", dhkClassMember::DWORD, false, 84),
																							dhkClassMember("totalBlockSize", dhkClassMember::DWORD, false, 88),
																							dhkClassMember("lastBlockSize", dhkClassMember::DWORD, false, 92),
																							dhkClassMember("dataBuffer", dhkClassMember::PTR_IGNORE, true, 96),
																							dhkClassMember("numDataBuffer", dhkClassMember::DWORD, false, 100)};
const char* dhkClassLibrary550::hkaDeltaCompressedSkeletalAnimationParents[1] = { "hkaSkeletalAnimation" };
const dhkClassMember dhkClassLibrary550::hkaDefaultAnimatedReferenceFrameMembers[5] = { dhkClassMember("up", dhkClassMember::VECTOR4, false, 16),
																		 dhkClassMember("forward", dhkClassMember::VECTOR4, false, 32),
																		 dhkClassMember("duration", dhkClassMember::DWORD, false, 48),
																		 dhkClassMember("referenceFrameSamples", dhkClassMember::PTR_VECTOR4, true, 52),
																		 dhkClassMember("numReferenceFrameSamples", dhkClassMember::DWORD, false, 56)};
const char* dhkClassLibrary550::hkaDefaultAnimatedReferenceFrameMembersParents[1] = { "hkReferencedObject" };
//const dhkClassMember* hkVector4Members[4] = { new dhkClassMember("x", dhkClassMember::DWORD, false, 0),
//												  new dhkClassMember("y", dhkClassMember::DWORD, false, 4),
//												  new dhkClassMember("z", dhkClassMember::DWORD, false, 8),
//												  new dhkClassMember("w", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkaAnnotationTrackMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
														   dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 4, "hkaAnnotationTrackAnnotation"),
														   dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkaAnnotationTrackAnnotationMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																	 dhkClassMember("text", dhkClassMember::PTR_IGNORE, true, 4)};
const dhkClassMember dhkClassLibrary550::hkaAnimationBindingMembers[6] = { dhkClassMember("animation", dhkClassMember::PTR_IGNORE, false, 0),
															dhkClassMember("transformTrackToBoneIndices", dhkClassMember::PTR_WORD, true, 4),
															dhkClassMember("numTransformTrackToBoneIndices", dhkClassMember::DWORD, false, 8),
															dhkClassMember("floatTrackToFloatSlotIndices", dhkClassMember::PTR_WORD, true, 12),
															dhkClassMember("numFloatTrackToFloatSlotIndices", dhkClassMember::DWORD, false, 16),
															dhkClassMember("blendHint", dhkClassMember::BYTE, false, 20)};
const dhkClassMember dhkClassLibrary550::hkxSceneMembers[21] = { dhkClassMember("modeller", dhkClassMember::PTR_IGNORE, true, 0),
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
//const dhkClassMember* hkMatrix3Members[3] = { new dhkClassMember("col0", dhkClassMember::CLASS, false, 0, "hkVector4"),
//												  new dhkClassMember("col1", dhkClassMember::CLASS, false, 16, "hkVector4"),
//												  new dhkClassMember("col2", dhkClassMember::CLASS, false, 32, "hkVector4")};
const dhkClassMember dhkClassLibrary550::hkaSkeletonMembers[9] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
												dhkClassMember("parentIndices", dhkClassMember::PTR_WORD, true, 4),
												dhkClassMember("numParentIndices", dhkClassMember::DWORD, false, 8),
												dhkClassMember("bones", dhkClassMember::PTR_IGNORE, true, 12),
												dhkClassMember("numBones", dhkClassMember::DWORD, false, 16),
												dhkClassMember("referencePose", dhkClassMember::PTR_CLASS, true, 20, "hkQsTransform"),
												dhkClassMember("numReferencePose", dhkClassMember::DWORD, false, 24),
												dhkClassMember("floatSlots", dhkClassMember::PTR_IGNORE, true, 28),
												dhkClassMember("numFloatSlots", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary550::hkQsTransformMembers[3] = { dhkClassMember("translation", dhkClassMember::VECTOR4, false, 0),
													dhkClassMember("rotation", dhkClassMember::VECTOR4, false, 16),
													dhkClassMember("scale", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary550::hkaBoneMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 0),
											dhkClassMember("lockTranslation", dhkClassMember::BYTE, false, 4)};

const dhkClassMember dhkClassLibrary550::hkpPhysicsDataMembers[2] = { dhkClassMember("worldCinfo", dhkClassMember::PTR_IGNORE, false, 8),
											dhkClassMember("systems", dhkClassMember::CLASS, false, 12, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary550::hkpPhysicsDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpPhysicsSystemMembers[7] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("actions", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("phantoms", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 56),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 60),
													dhkClassMember("active", dhkClassMember::BYTE, false, 64)};
const char* dhkClassLibrary550::hkpPhysicsSystemParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpCdBodyMembers[4] = { dhkClassMember("shape", dhkClassMember::PTR_IGNORE, false, 0),
												dhkClassMember("shapeKey", dhkClassMember::DWORD, false, 4),
												dhkClassMember("motion", dhkClassMember::PTR_IGNORE, false, 8),
												dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary550::hkpBroadPhaseHandleMembers[1] = { dhkClassMember("id", dhkClassMember::DWORD, false, 0)};
const dhkClassMember dhkClassLibrary550::hkpTypedBroadPhaseHandleMembers[4] = { dhkClassMember("type", dhkClassMember::BYTE, false, 4),
															dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 5),
															dhkClassMember("objectQualityType", dhkClassMember::WORD, false, 6),
															dhkClassMember("collisionFilterInfo", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary550::hkpTypedBroadPhaseHandleParents[1] = { "hkpBroadPhaseHandle" };
const dhkClassMember dhkClassLibrary550::hkpCollidableBoundingVolumeDataMembers[16] = { dhkClassMember("min_0", dhkClassMember::DWORD, false, 0),
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
const char* dhkClassLibrary550::hkpCollidableParents[1] = { "hkpCdBody" };
const dhkClassMember dhkClassLibrary550::hkpCollidableMembers[6] = { dhkClassMember("ownerOffset", dhkClassMember::BYTE, false, 16),
													dhkClassMember("forceCollideOntoPpu", dhkClassMember::BYTE, false, 17),
													dhkClassMember("shapeSizeOnSpu", dhkClassMember::WORD, false, 18),
													dhkClassMember("broadPhaseHandle", dhkClassMember::CLASS, false, 20, "hkpTypedBroadPhaseHandle"),
													dhkClassMember("boundingVolumeData", dhkClassMember::CLASS, false, 32, "hkpCollidableBoundingVolumeData"),
													dhkClassMember("allowedPenetrationDepth", dhkClassMember::DWORD, false, 72)};
const dhkClassMember dhkClassLibrary550::hkpLinkedCollidableMembers[1] = { dhkClassMember("collisionEntries", dhkClassMember::CLASS, false, 76, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary550::hkpLinkedCollidableParents[1] = { "hkpCollidable" };
const dhkClassMember dhkClassLibrary550::hkMultiThreadCheckMembers[3] = { dhkClassMember("threadId", dhkClassMember::DWORD, false, 0),
													dhkClassMember("markCount", dhkClassMember::WORD, false, 4),
													dhkClassMember("markBitStack", dhkClassMember::WORD, false, 6)};
const dhkClassMember dhkClassLibrary550::hkpPropertyValueMembers[1] = { dhkClassMember("data", dhkClassMember::QWORD, false, 0)};
const dhkClassMember dhkClassLibrary550::hkpPropertyMembers[3] = { dhkClassMember("key", dhkClassMember::DWORD, false, 0),
												dhkClassMember("alignmentPadding", dhkClassMember::DWORD, false, 4),
												dhkClassMember("value", dhkClassMember::CLASS, false, 8, "hkpPropertyValue")};
const dhkClassMember dhkClassLibrary550::hkpMaterialMembers[3] = { dhkClassMember("responseType", dhkClassMember::BYTE, false, 0),
												dhkClassMember("friction", dhkClassMember::DWORD, false, 4),
												dhkClassMember("restitution", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkpWorldObjectMembers[6] = { dhkClassMember("world", dhkClassMember::PTR_IGNORE, false, 8),
													dhkClassMember("userData", dhkClassMember::DWORD, false, 12),
													dhkClassMember("collidable", dhkClassMember::CLASS, false, 16, "hkpLinkedCollidable"),
													dhkClassMember("multiThreadCheck", dhkClassMember::CLASS, false, 104, "hkMultiThreadCheck"),
													dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 112),
													dhkClassMember("properties", dhkClassMember::CLASS, false, 116, "hkArray", dhkClassMember::PTR_IGNORE)}; //TODO: I think I'm ignoring this??
const char* dhkClassLibrary550::hkpWorldObjectParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkTransformMembers[2] = { dhkClassMember("rotation", dhkClassMember::MATRIX3, false, 0),
												dhkClassMember("translation", dhkClassMember::VECTOR4, false, 48)};
const dhkClassMember dhkClassLibrary550::hkSweptTransformMembers[5] = { dhkClassMember("centerOfMass0", dhkClassMember::VECTOR4, false, 0),
											dhkClassMember("centerOfMass1", dhkClassMember::VECTOR4, false, 16),
											dhkClassMember("rotation0", dhkClassMember::VECTOR4, false, 32),
											dhkClassMember("rotation1", dhkClassMember::VECTOR4, false, 48),
											dhkClassMember("centerOfMassLocal", dhkClassMember::VECTOR4, false, 64)};
const dhkClassMember dhkClassLibrary550::hkMotionStateMembers[9] = { dhkClassMember("transform", dhkClassMember::CLASS, false, 0, "hkTransform"),
													dhkClassMember("sweptTransform", dhkClassMember::CLASS, false, 64, "hkSweptTransform"),
													dhkClassMember("deltaAngle", dhkClassMember::VECTOR4, false, 144),
													dhkClassMember("objectRadius", dhkClassMember::DWORD, false, 160),
													dhkClassMember("linearDamping", dhkClassMember::DWORD, false, 164),
													dhkClassMember("angularDamping", dhkClassMember::DWORD, false, 168),
													dhkClassMember("maxLinearVelocity", dhkClassMember::BYTE, false, 172),
													dhkClassMember("maxAngularVelocity", dhkClassMember::BYTE, false, 173),
													dhkClassMember("deactivationClass", dhkClassMember::BYTE, false, 174)};

const dhkClassMember dhkClassLibrary550::hkpMotionMembers[14] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8),
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
const char* dhkClassLibrary550::hkpMotionParents[1] = { "hkReferencedObject" };
const char* dhkClassLibrary550::hkpKeyframedRigidMotionParents[1] = { "hkpMotion" };
const char* dhkClassLibrary550::hkpMaxSizeMotionParents[1] = { "hkpKeyframedRigidMotion" };
const dhkClassMember dhkClassLibrary550::hkpEntitySpuCollisionCallbackMembers[4] = { dhkClassMember("util", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("capacity", dhkClassMember::WORD, false, 4),
																	dhkClassMember("eventFilter", dhkClassMember::BYTE, false, 6),
																	dhkClassMember("userFilter", dhkClassMember::BYTE, false, 7)};
const char* dhkClassLibrary550::hkpEntityParents[1] = { "hkpWorldObject" };
const dhkClassMember dhkClassLibrary550::hkpEntityMembers[17] = { dhkClassMember("material", dhkClassMember::CLASS, false, 128, "hkpMaterial"),
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
const char* dhkClassLibrary550::hkpRigidBodyParents[1] = { "hkpEntity" };
const char* dhkClassLibrary550::hkpShapeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpShapeMembers[2] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8),
											dhkClassMember("type", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary550::hkpSphereRepShapeParents[1] = { "hkpShape" };
const dhkClassMember dhkClassLibrary550::hkpConvexShapeMembers[1] = { dhkClassMember("radius", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary550::hkpConvexShapeParents[1] = { "hkpSphereRepShape" };
const dhkClassMember dhkClassLibrary550::hkpCapsuleShapeMembers[2] = { dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48)};
const char* dhkClassLibrary550::hkpCapsuleShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpConstraintDataMembers[1] = { dhkClassMember("userData", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary550::hkpConstraintDataParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpConstraintAtomMembers[1] = { dhkClassMember("type", dhkClassMember::WORD, false, 0)};
const dhkClassMember dhkClassLibrary550::hkpSetLocalTransformsConstraintAtomMembers[2] = { dhkClassMember("transformA", dhkClassMember::CLASS, false, 16, "hkTransform"),
																		dhkClassMember("transformB", dhkClassMember::CLASS, false, 80, "hkTransform")};
const char* dhkClassLibrary550::hkpSetLocalTransformsConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpRagdollMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
																dhkClassMember("previousTargetAnglesOffset", dhkClassMember::WORD, false, 6),
																dhkClassMember("targetFrameAinB", dhkClassMember::MATRIX3, false, 16),
																dhkClassMember("motors_0", dhkClassMember::PTR_IGNORE, false, 64),
																dhkClassMember("motors_1", dhkClassMember::PTR_IGNORE, false, 68),
																dhkClassMember("motors_2", dhkClassMember::PTR_IGNORE, false, 72)};
const char* dhkClassLibrary550::hkpRagdollMotorConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpAngFrictionConstraintAtomMembers[4] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("firstFrictionAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("numFrictionAxes", dhkClassMember::BYTE, false, 4),
																dhkClassMember("maxFrictionTorque", dhkClassMember::DWORD, false, 8)};
const char* dhkClassLibrary550::hkpAngFrictionConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpTwistLimitConstraintAtomMembers[6] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxis", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxis", dhkClassMember::BYTE, false, 4),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary550::hkpTwistLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpConeLimitConstraintAtomMembers[8] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
																dhkClassMember("twistAxisInA", dhkClassMember::BYTE, false, 3),
																dhkClassMember("refAxisInB", dhkClassMember::BYTE, false, 4),
																dhkClassMember("angleMeasurementMode", dhkClassMember::BYTE, false, 5),
																dhkClassMember("memOffsetToAngleOffset", dhkClassMember::BYTE, false, 6),
																dhkClassMember("minAngle", dhkClassMember::DWORD, false, 8),
																dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 12),
																dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary550::hkpConeLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const char* dhkClassLibrary550::hkpBallSocketConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpRagdollConstraintDataAtomsMembers[7] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkpSetLocalTransformsConstraintAtom"),
														  dhkClassMember("ragdollMotors", dhkClassMember::CLASS, false, 144, "hkpRagdollMotorConstraintAtom"),
														  dhkClassMember("angFriction", dhkClassMember::CLASS, false, 224, "hkpAngFrictionConstraintAtom"),
														  dhkClassMember("twistLimit", dhkClassMember::CLASS, false, 236, "hkpTwistLimitConstraintAtom"),
														  dhkClassMember("coneLimit", dhkClassMember::CLASS, false, 256, "hkpConeLimitConstraintAtom"),
														  dhkClassMember("planesLimit", dhkClassMember::CLASS, false, 276, "hkpConeLimitConstraintAtom"),
														  dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 296, "hkpBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary550::hkpRagdollConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkpRagdollConstraintDataAtoms")};
const char* dhkClassLibrary550::hkpRagdollConstraintDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary550::hkpConstraintInstanceMembers[10] = { dhkClassMember("owner", dhkClassMember::PTR_IGNORE, false, 8), //hkpConstraintOwner
														dhkClassMember("data", dhkClassMember::PTR_IGNORE, false, 12),	//hkpConstraintData
														dhkClassMember("constraintModifiers", dhkClassMember::PTR_IGNORE, false, 16), //hkpModifierConstraintAtom
														dhkClassMember("entities_0", dhkClassMember::PTR_IGNORE, false, 20), //hkpEntity
														dhkClassMember("entities_1", dhkClassMember::PTR_IGNORE, false, 24),
														dhkClassMember("priority", dhkClassMember::BYTE, false, 28),
														dhkClassMember("wantRuntime", dhkClassMember::BYTE, false, 29),
														dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 32),
														dhkClassMember("userData", dhkClassMember::DWORD, false, 36),
														dhkClassMember("internal", dhkClassMember::PTR_IGNORE, false, 40)}; 
const char* dhkClassLibrary550::hkpConstraintInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkaRagdollInstanceMembers[4] = { dhkClassMember("rigidBodies", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("constraints", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::PTR_IGNORE),
														dhkClassMember("boneToRigidBodyMap", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::DWORD),
														dhkClassMember("skeleton", dhkClassMember::PTR_IGNORE, false, 44)};
const char* dhkClassLibrary550::hkaRagdollInstanceParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkaSkeletonMapperDataSimpleMappingMembers[3] = { dhkClassMember("boneA", dhkClassMember::WORD, false, 0),
																		dhkClassMember("boneB", dhkClassMember::WORD, false, 2),
																		dhkClassMember("aFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform")};
const dhkClassMember dhkClassLibrary550::hkaSkeletonMapperDataChainMappingMembers[6] = { dhkClassMember("startBoneA", dhkClassMember::WORD, false, 0),
																	dhkClassMember("endBoneA", dhkClassMember::WORD, false, 2),
																	dhkClassMember("startBoneB", dhkClassMember::WORD, false, 4),
																	dhkClassMember("endBoneB", dhkClassMember::WORD, false, 6),
																	dhkClassMember("startAFromBTransform", dhkClassMember::CLASS, false, 16, "hkQsTransform"),
																	dhkClassMember("endAFromBTransform", dhkClassMember::CLASS, false, 64, "hkQsTransform")};
const dhkClassMember dhkClassLibrary550::hkaSkeletonMapperDataMembers[6] = { dhkClassMember("skeletonA", dhkClassMember::PTR_IGNORE, false, 0),
														dhkClassMember("skeletonB", dhkClassMember::PTR_IGNORE, false, 4),
														dhkClassMember("simpleMappings", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::CLASS, "hkaSkeletonMapperDataSimpleMapping"),
														dhkClassMember("chainMappings", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::CLASS, "hkaSkeletonMapperDataChainMapping"),
														dhkClassMember("unmappedBones", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::WORD),
														dhkClassMember("keepUnmappedLocal", dhkClassMember::BYTE, false, 44)};
const dhkClassMember dhkClassLibrary550::hkaSkeletonMapperMembers[1] = { dhkClassMember("mapping", dhkClassMember::CLASS, false, 8, "hkaSkeletonMapperData")};
const char* dhkClassLibrary550::hkaSkeletonMapperParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpAngMotorConstraintAtomMembers[7] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("motorAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("initializedOffset", dhkClassMember::WORD, false, 4),
															dhkClassMember("previousTargetAngleOffset", dhkClassMember::WORD, false, 6),
															dhkClassMember("correspondingAngLimitSolverResultOffset", dhkClassMember::WORD, false, 8),
															dhkClassMember("targetAngle", dhkClassMember::DWORD, false, 12),
															dhkClassMember("motor", dhkClassMember::PTR_IGNORE, false, 16)}; //hkpConstraintMotor
const char* dhkClassLibrary550::hkpAngMotorConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpAngLimitConstraintAtomMembers[5] = { dhkClassMember("isEnabled", dhkClassMember::BYTE, false, 2),
															dhkClassMember("limitAxis", dhkClassMember::BYTE, false, 3),
															dhkClassMember("minAngle", dhkClassMember::DWORD, false, 4),
															dhkClassMember("maxAngle", dhkClassMember::DWORD, false, 8),
															dhkClassMember("angularLimitsTauFactor", dhkClassMember::DWORD, false, 12)};
const char* dhkClassLibrary550::hkpAngLimitConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkp2dAngConstraintAtomMembers[1] = { dhkClassMember("freeRotationAxis", dhkClassMember::BYTE, false, 2)};
const char* dhkClassLibrary550::hkp2dAngConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpLimitedHingeConstraintDataAtomsMembers[6] = { dhkClassMember("transforms", dhkClassMember::CLASS, false, 0, "hkpSetLocalTransformsConstraintAtom"),
																	dhkClassMember("angMotor", dhkClassMember::CLASS, false, 144, "hkpAngMotorConstraintAtom"),
																	dhkClassMember("angFriction", dhkClassMember::CLASS, false, 164, "hkpAngFrictionConstraintAtom"),
																	dhkClassMember("angLimit", dhkClassMember::CLASS, false, 176, "hkpAngLimitConstraintAtom"),
																	dhkClassMember("2dAng", dhkClassMember::CLASS, false, 192, "hkp2dAngConstraintAtom"),
																	dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 196, "hkpBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary550::hkpLimitedHingeConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkpLimitedHingeConstraintDataAtoms")};
const char* dhkClassLibrary550::hkpLimitedHingeConstraintDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary550::hkpConstraintMotorMembers[1] = { dhkClassMember("type", dhkClassMember::BYTE, false, 8)};
const char* dhkClassLibrary550::hkpConstraintMotorParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpMaxSizeConstraintMotorMembers[9] = { dhkClassMember("dummy_0", dhkClassMember::DWORD, false, 12),
															dhkClassMember("dummy_1", dhkClassMember::DWORD, false, 16),
															dhkClassMember("dummy_2", dhkClassMember::DWORD, false, 20),
															dhkClassMember("dummy_3", dhkClassMember::DWORD, false, 24),
															dhkClassMember("dummy_4", dhkClassMember::DWORD, false, 28),
															dhkClassMember("dummy_5", dhkClassMember::DWORD, false, 32),
															dhkClassMember("dummy_6", dhkClassMember::DWORD, false, 36),
															dhkClassMember("dummy_7", dhkClassMember::DWORD, false, 40),
															dhkClassMember("dummy_8", dhkClassMember::DWORD, false, 44)};
const char* dhkClassLibrary550::hkpMaxSizeConstraintMotorParents[1] = { "hkpConstraintMotor" };
const dhkClassMember dhkClassLibrary550::hkpLimitedForceConstraintMotorMembers[2] = { dhkClassMember("minForce", dhkClassMember::DWORD, false, 12),
																	dhkClassMember("maxForce", dhkClassMember::DWORD, false, 16)};
const char* dhkClassLibrary550::hkpLimitedForceConstraintMotorParents[1] = { "hkpConstraintMotor" };
const dhkClassMember dhkClassLibrary550::hkpPositionConstraintMotorMembers[4] = { dhkClassMember("tau", dhkClassMember::DWORD, false, 20),
																dhkClassMember("damping", dhkClassMember::DWORD, false, 24),
																dhkClassMember("proportionalRecoveryVelocity", dhkClassMember::DWORD, false, 28),
																dhkClassMember("constantRecoveryVelocity", dhkClassMember::DWORD, false, 32)};
const char* dhkClassLibrary550::hkpPositionConstraintMotorParents[1] = { "hkpLimitedForceConstraintMotor" };
const dhkClassMember dhkClassLibrary550::hkpConvexVerticesShapeFourVectorsMembers[3] = { dhkClassMember("x", dhkClassMember::VECTOR4, false, 0),
												dhkClassMember("y", dhkClassMember::VECTOR4, false, 16),
												dhkClassMember("z", dhkClassMember::VECTOR4, false, 32)};
const dhkClassMember dhkClassLibrary550::hkpConvexVerticesShapeMembers[6] = { dhkClassMember("aabbHalfExtents", dhkClassMember::VECTOR4, false, 32),
															dhkClassMember("aabbCenter", dhkClassMember::VECTOR4, false, 48),
															dhkClassMember("rotatedVertices", dhkClassMember::CLASS, false, 64, "hkArray", dhkClassMember::CLASS, "hkpConvexVerticesShapeFourVectors"),
															dhkClassMember("numVertices", dhkClassMember::DWORD, false, 76),
															dhkClassMember("planeEquations", dhkClassMember::CLASS, false, 80, "hkArray", dhkClassMember::VECTOR4),
															dhkClassMember("connectivity", dhkClassMember::PTR_IGNORE, false, 92)}; //hkpConvexVerticesConnectivity
const char* dhkClassLibrary550::hkpConvexVerticesShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpConvexVerticesConnectivityMembers[2] = { dhkClassMember("vertexIndices", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::WORD),
																	dhkClassMember("numVerticesPerFace", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::BYTE)};
const char* dhkClassLibrary550::hkpConvexVerticesConnectivityParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpSingleShapeContainerMembers[1] = { dhkClassMember("childShape", dhkClassMember::PTR_IGNORE, false, 0)}; //hkpShape
const char* dhkClassLibrary550::hkpSingleShapeContainerParents[1] = { "hkpShapeContainer" };
const dhkClassMember dhkClassLibrary550::hkpConvexTranslateShapeMembers[3] = { dhkClassMember("childShape", dhkClassMember::CLASS, false, 20, "hkpSingleShapeContainer"),
															dhkClassMember("childShapeSize", dhkClassMember::DWORD, false, 24),
															dhkClassMember("translation", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary550::hkpConvexTranslateShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpBoxShapeMembers[1] = { dhkClassMember("halfExtents", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary550::hkpBoxShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpSphereShapeMembers[3] = { dhkClassMember("pad16_0", dhkClassMember::DWORD, false, 20),
													dhkClassMember("pad16_1", dhkClassMember::DWORD, false, 24),
													dhkClassMember("pad16_2", dhkClassMember::DWORD, false, 28)};
const char* dhkClassLibrary550::hkpSphereShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpCylinderShapeMembers[6] = { dhkClassMember("cylRadius", dhkClassMember::DWORD, false, 20),
													dhkClassMember("cylBaseRadiusFactorForHeightFieldCollisions", dhkClassMember::DWORD, false, 24),
													dhkClassMember("vertexA", dhkClassMember::VECTOR4, false, 32),
													dhkClassMember("vertexB", dhkClassMember::VECTOR4, false, 48),
													dhkClassMember("perpendicular1", dhkClassMember::VECTOR4, false, 64),
													dhkClassMember("perpendicular2", dhkClassMember::VECTOR4, false, 80)};
const char* dhkClassLibrary550::hkpCylinderShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::CustomParamStorageExtendedMeshShapeMembers[1] = { dhkClassMember("materialArray", dhkClassMember::CLASS, false, 216, "hkArray", dhkClassMember::PTR_IGNORE) };
const char* dhkClassLibrary550::CustomParamStorageExtendedMeshShapeParents[1] = { "hkpStorageExtendedMeshShape" };
const dhkClassMember dhkClassLibrary550::CustomMeshParameterMembers[7] = { dhkClassMember("version", dhkClassMember::DWORD, false, 8),
																			dhkClassMember("vertexDataBuffer", dhkClassMember::PTR_IGNORE, true, 12),
																			dhkClassMember("numVertexDataBuffer", dhkClassMember::DWORD, false, 16),
																			dhkClassMember("vertexDataStride", dhkClassMember::DWORD, false, 20),
																			dhkClassMember("primitiveDataBuffer", dhkClassMember::PTR_IGNORE, true, 24),
																			dhkClassMember("numPrimitiveDataBuffer", dhkClassMember::DWORD, false, 28),
																			dhkClassMember("materialNameData", dhkClassMember::DWORD, false, 32)};
const char* dhkClassLibrary550::CustomMeshParameterParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpStorageExtendedMeshShapeMembers[2] = { dhkClassMember("meshstorage", dhkClassMember::CLASS, false, 192, "hkArray", dhkClassMember::PTR_IGNORE),
																					dhkClassMember("shapestorage", dhkClassMember::CLASS, false, 204, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary550::hkpStorageExtendedMeshShapeParents[1] = { "hkpExtendedMeshShape" };
const dhkClassMember dhkClassLibrary550::hkpStorageExtendedMeshShapeMeshSubpartStorageMembers[6] = { dhkClassMember("vertices", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::VECTOR4),
																									dhkClassMember("indices16", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::WORD),
																									dhkClassMember("indices32", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::DWORD),
																									dhkClassMember("materialIndices", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::BYTE),
																									dhkClassMember("materials", dhkClassMember::CLASS, false, 56, "hkArray", dhkClassMember::DWORD),
																									dhkClassMember("materialIndices16", dhkClassMember::CLASS, false, 68, "hkArray", dhkClassMember::WORD)};
const char* dhkClassLibrary550::hkpStorageExtendedMeshShapeMeshSubpartStorageParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpExtendedMeshShapeMembers[15] = { dhkClassMember("numBitsForSubpartIndex", dhkClassMember::DWORD, false, 24),
														dhkClassMember("scaling", dhkClassMember::VECTOR4, false, 32),
														dhkClassMember("aabbHalfExtents", dhkClassMember::VECTOR4, false, 48),
														dhkClassMember("aabbCenter", dhkClassMember::VECTOR4, false, 64),
														dhkClassMember("trianglesSubparts", dhkClassMember::PTR_CLASS, true, 80, "hkpExtendedMeshShapeTrianglesSubpart"),
														dhkClassMember("numTrianglesSubparts", dhkClassMember::DWORD, false, 84),
														dhkClassMember("shapesSubparts", dhkClassMember::PTR_IGNORE, true, 88),
														dhkClassMember("numShapesSubparts", dhkClassMember::DWORD, false, 92),
														dhkClassMember("weldingInfo", dhkClassMember::CLASS, false, 96, "hkArray", dhkClassMember::WORD),
														dhkClassMember("weldingType", dhkClassMember::BYTE, false, 108),
														dhkClassMember("embeddedTrianglesSubpart", dhkClassMember::CLASS, false, 112, "hkpExtendedMeshShapeTrianglesSubpart"),
														dhkClassMember("triangleRadius", dhkClassMember::DWORD, false, 176),
														dhkClassMember("pad_0", dhkClassMember::DWORD, false, 180),
														dhkClassMember("pad_1", dhkClassMember::DWORD, false, 184),
														dhkClassMember("pad_2", dhkClassMember::DWORD, false, 188)};
const char* dhkClassLibrary550::hkpExtendedMeshShapeParents[1] = { "hkpShapeCollection" };
const dhkClassMember dhkClassLibrary550::hkpExtendedMeshShapeTrianglesSubpartMembers[10] = { dhkClassMember("numTriangleShapes", dhkClassMember::DWORD, false, 16),
																							dhkClassMember("vertexBase", dhkClassMember::PTR_IGNORE, false, 20),
																							dhkClassMember("vertexStriding", dhkClassMember::DWORD, false, 24),
																							dhkClassMember("numVertices", dhkClassMember::DWORD, false, 28),
																							dhkClassMember("extrusion", dhkClassMember::VECTOR4, false, 32),
																							dhkClassMember("indexBase", dhkClassMember::PTR_IGNORE, false, 48),
																							dhkClassMember("indexStriding", dhkClassMember::DWORD, false, 52),
																							dhkClassMember("stridingType", dhkClassMember::BYTE, false, 56),
																							dhkClassMember("flipAlternateTriangles", dhkClassMember::BYTE, false, 57),
																							dhkClassMember("triangleOffset", dhkClassMember::DWORD, false, 60)};
const char* dhkClassLibrary550::hkpExtendedMeshShapeTrianglesSubpartParents[1] = { "hkpExtendedMeshShapeSubpart" };
const dhkClassMember dhkClassLibrary550::hkpExtendedMeshShapeSubpartMembers[7] = { dhkClassMember("type", dhkClassMember::BYTE, false, 0),
																					dhkClassMember("materialIndexStridingType", dhkClassMember::BYTE, false, 1),
																					dhkClassMember("materialStriding", dhkClassMember::WORD, false, 2),
																					dhkClassMember("materialIndexBase", dhkClassMember::PTR_IGNORE, false, 4),
																					dhkClassMember("materialIndexStriding", dhkClassMember::WORD, false, 8),
																					dhkClassMember("numMaterials", dhkClassMember::WORD, false, 10),
																					dhkClassMember("materialBase", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary550::hkpShapeCollectionMembers[1] = { dhkClassMember("disableWelding", dhkClassMember::BYTE, false, 16)};
const char* dhkClassLibrary550::hkpShapeCollectionParents[2] = { "hkpShape", "hkpShapeContainer" };
//const dhkClassMember dhkClassLibrary550::hkpShapeContainerMembers[1] = { dhkClassMember("childShape", dhkClassMember::PTR_IGNORE, false, 0) };
const char* dhkClassLibrary550::hkpBvTreeShapeParents[1] = { "hkpShape" };
const dhkClassMember dhkClassLibrary550::hkpMoppCodeMembers[3] = { dhkClassMember("info", dhkClassMember::CLASS, false, 16, "hkpMoppCodeCodeInfo"),
																	dhkClassMember("data", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::PTR_IGNORE),
																	dhkClassMember("buildType", dhkClassMember::BYTE, false, 44)};
const char* dhkClassLibrary550::hkpMoppCodeParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpMoppCodeCodeInfoMembers[1] = { dhkClassMember("offset", dhkClassMember::VECTOR4, false, 0) };
const dhkClassMember dhkClassLibrary550::hkMoppBvTreeShapeBaseMembers[4] = { dhkClassMember("code", dhkClassMember::PTR_IGNORE, false, 16),
																				dhkClassMember("moppData", dhkClassMember::PTR_IGNORE, true, 20),
																				dhkClassMember("moppDataSize", dhkClassMember::DWORD, false, 24),
																				dhkClassMember("codeInfoCopy", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary550::hkMoppBvTreeShapeBaseParents[1] = { "hkpBvTreeShape" };
const dhkClassMember dhkClassLibrary550::hkpMoppBvTreeShapeMembers[2] = { dhkClassMember("child", dhkClassMember::CLASS, false, 48, "hkpSingleShapeContainer"),
																			dhkClassMember("childSize", dhkClassMember::DWORD, false, 52)};
const char* dhkClassLibrary550::hkpMoppBvTreeShapeParents[1] = { "hkMoppBvTreeShapeBase" };
const dhkClassMember dhkClassLibrary550::hkpConvexTransformShapeMembers[3] = { dhkClassMember("childShape", dhkClassMember::CLASS, false, 20, "hkpSingleShapeContainer"),
																				dhkClassMember("childShapeSize", dhkClassMember::DWORD, false, 24),
																				dhkClassMember("transform", dhkClassMember::CLASS, false, 32, "hkTransform")};
const char* dhkClassLibrary550::hkpConvexTransformShapeParents[1] = { "hkpConvexShape" };
const dhkClassMember dhkClassLibrary550::hkpConstraintChainInstanceMembers[2] = { dhkClassMember("chainedEntities", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
																					dhkClassMember("action", dhkClassMember::PTR_IGNORE, false, 56)};
const char* dhkClassLibrary550::hkpConstraintChainInstanceParents[1] = { "hkpConstraintInstance" };
const dhkClassMember dhkClassLibrary550::hkpActionMembers[4] = { dhkClassMember("world", dhkClassMember::PTR_IGNORE, false, 8),
																dhkClassMember("island", dhkClassMember::PTR_IGNORE, false, 12),
																dhkClassMember("userData", dhkClassMember::DWORD, false, 16),
																dhkClassMember("name", dhkClassMember::PTR_IGNORE, true, 20)};
const char* dhkClassLibrary550::hkpActionParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkpConstraintChainInstanceActionMembers[1] = { dhkClassMember("constraintInstance", dhkClassMember::PTR_IGNORE, false, 24)};
const char* dhkClassLibrary550::hkpConstraintChainInstanceActionParents[1] = { "hkpAction" };
const char* dhkClassLibrary550::hkpConstraintChainDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary550::hkpBallSocketChainDataMembers[6] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 12, "hkpBridgeAtoms"),
																				dhkClassMember("infos", dhkClassMember::CLASS, false, 24, "hkArray", dhkClassMember::CLASS, "hkpBallSocketChainDataConstraintInfo"),
																				dhkClassMember("tau", dhkClassMember::DWORD, false, 36),
																				dhkClassMember("damping", dhkClassMember::DWORD, false, 40),
																				dhkClassMember("cfm", dhkClassMember::DWORD, false, 44),
																				dhkClassMember("maxErrorDistance", dhkClassMember::DWORD, false, 48)};
const char* dhkClassLibrary550::hkpBallSocketChainDataParents[1] = { "hkpConstraintChainData" };
const dhkClassMember dhkClassLibrary550::hkpBallSocketChainDataConstraintInfoMembers[2] = { dhkClassMember("pivotInA", dhkClassMember::VECTOR4, false, 0),
																							dhkClassMember("pivotInB", dhkClassMember::VECTOR4, false, 16)};
const dhkClassMember dhkClassLibrary550::hkpBridgeAtomsMembers[1] = { dhkClassMember("bridgeAtom", dhkClassMember::CLASS, false, 0, "hkpBridgeConstraintAtom")};
const dhkClassMember dhkClassLibrary550::hkpBridgeConstraintAtomMembers[2] = { dhkClassMember("buildJacobianFunc", dhkClassMember::PTR_IGNORE, false, 4),
																				dhkClassMember("constraintData", dhkClassMember::PTR_IGNORE, false, 8)};
const char* dhkClassLibrary550::hkpBridgeConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpBallAndSocketConstraintDataMembers[1] = { dhkClassMember("atoms", dhkClassMember::CLASS, false, 16, "hkpBallAndSocketConstraintDataAtoms") };
const char* dhkClassLibrary550::hkpBallAndSocketConstraintDataParents[1] = { "hkpConstraintData" };
const dhkClassMember dhkClassLibrary550::hkpBallAndSocketConstraintDataAtomsMembers[2] = { dhkClassMember("pivots", dhkClassMember::CLASS, false, 0, "hkpSetLocalTranslationsConstraintAtom"),
																							dhkClassMember("ballSocket", dhkClassMember::CLASS, false, 48, "hkpBallSocketConstraintAtom")};
const dhkClassMember dhkClassLibrary550::hkpSetLocalTranslationsConstraintAtomMembers[2] = { dhkClassMember("translationA", dhkClassMember::VECTOR4, false, 16),
																								dhkClassMember("translationB", dhkClassMember::VECTOR4, false, 32)};
const char* dhkClassLibrary550::hkpSetLocalTranslationsConstraintAtomParents[1] = { "hkpConstraintAtom" };
const dhkClassMember dhkClassLibrary550::hkpSimpleMeshShapeMembers[5] = { dhkClassMember("vertices", dhkClassMember::CLASS, false, 24, "hkArray", dhkClassMember::VECTOR4),
																			dhkClassMember("triangles", dhkClassMember::CLASS, false, 36, "hkArray", dhkClassMember::CLASS, "hkpSimpleMeshShapeTriangle"),
																			dhkClassMember("materialIndices", dhkClassMember::CLASS, false, 48, "hkArray", dhkClassMember::PTR_IGNORE),
																			dhkClassMember("radius", dhkClassMember::DWORD, false, 60),
																			dhkClassMember("weldingType", dhkClassMember::BYTE, false, 64)};
const char* dhkClassLibrary550::hkpSimpleMeshShapeParents[1] = { "hkpShapeCollection" };
const dhkClassMember dhkClassLibrary550::hkpSimpleMeshShapeTriangleMembers[4] = { dhkClassMember("a", dhkClassMember::DWORD, false, 0),
																					dhkClassMember("b", dhkClassMember::DWORD, false, 4),
																					dhkClassMember("c", dhkClassMember::DWORD, false, 8),
																					dhkClassMember("weldingInfo", dhkClassMember::WORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkpMeshShapeMembers[9] = { dhkClassMember("scaling", dhkClassMember::VECTOR4, false, 32),
																	dhkClassMember("numBitsForSubpartIndex", dhkClassMember::DWORD, false, 48),
																	dhkClassMember("subparts", dhkClassMember::CLASS, false, 52, "hkArray", dhkClassMember::CLASS, "hkpMeshShapeSubpart"),
																	dhkClassMember("weldingInfo", dhkClassMember::CLASS, false, 64, "hkArray", dhkClassMember::WORD),
																	dhkClassMember("weldingType", dhkClassMember::BYTE, false, 76),
																	dhkClassMember("radius", dhkClassMember::DWORD, false, 80),
																	dhkClassMember("pad_0", dhkClassMember::DWORD, false, 84),
																	dhkClassMember("pad_1", dhkClassMember::DWORD, false, 88),
																	dhkClassMember("pad_2", dhkClassMember::DWORD, false, 92)};
const char* dhkClassLibrary550::hkpMeshShapeParents[1] = { "hkpShapeCollection" };
const dhkClassMember dhkClassLibrary550::hkpMeshShapeSubpartMembers[15] = { dhkClassMember("vertexBase", dhkClassMember::PTR_IGNORE, false, 0),
																			dhkClassMember("vertexStriding", dhkClassMember::DWORD, false, 4),
																			dhkClassMember("numVertices", dhkClassMember::DWORD, false, 8),
																			dhkClassMember("indexBase", dhkClassMember::PTR_IGNORE, false, 12),
																			dhkClassMember("stridingType", dhkClassMember::BYTE, false, 16),
																			dhkClassMember("materialIndexStridingType", dhkClassMember::BYTE, false, 17),
																			dhkClassMember("indexStriding", dhkClassMember::DWORD, false, 20),
																			dhkClassMember("flipAlternateTriangles", dhkClassMember::DWORD, false, 24),
																			dhkClassMember("numTriangles", dhkClassMember::DWORD, false, 28),
																			dhkClassMember("materialIndexBase", dhkClassMember::PTR_IGNORE, false, 32),
																			dhkClassMember("materialIndexStriding", dhkClassMember::DWORD, false, 36),
																			dhkClassMember("materialBase", dhkClassMember::PTR_IGNORE, false, 40),
																			dhkClassMember("materialStriding", dhkClassMember::DWORD, false, 44),
																			dhkClassMember("numMaterials", dhkClassMember::DWORD, false, 48),
																			dhkClassMember("triangleOffset", dhkClassMember::DWORD, false, 52)};
const dhkClassMember dhkClassLibrary550::hkpStorageMeshShapeMembers[1] = { dhkClassMember("storage", dhkClassMember::CLASS, false, 96, "hkArray", dhkClassMember::PTR_IGNORE)};
const char* dhkClassLibrary550::hkpStorageMeshShapeParents[1] = { "hkpMeshShape" };
const dhkClassMember dhkClassLibrary550::hkpStorageMeshShapeSubpartStorageMembers[6] = { dhkClassMember("vertices", dhkClassMember::CLASS, false, 8, "hkArray", dhkClassMember::DWORD),
																						dhkClassMember("indices16", dhkClassMember::CLASS, false, 20, "hkArray", dhkClassMember::WORD),
																						dhkClassMember("indices32", dhkClassMember::CLASS, false, 32, "hkArray", dhkClassMember::DWORD),
																						dhkClassMember("materialIndices", dhkClassMember::CLASS, false, 44, "hkArray", dhkClassMember::PTR_IGNORE),
																						dhkClassMember("materials", dhkClassMember::CLASS, false, 56, "hkArray", dhkClassMember::DWORD),
																						dhkClassMember("materialIndices16", dhkClassMember::CLASS, false, 68, "hkArray", dhkClassMember::WORD)};
const char* dhkClassLibrary550::hkpStorageMeshShapeSubpartStorageParents[1] = { "hkReferencedObject" };
const dhkClassMember dhkClassLibrary550::hkxAttributeHolderMembers[2] = { dhkClassMember("attributeGroups", dhkClassMember::PTR_CLASS, true, 0, "hkxAttributeGroup"),
																			dhkClassMember("numAttributeGroups", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary550::hkxAttributeGroupMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																			dhkClassMember("attributes", dhkClassMember::PTR_CLASS, true, 4, "hkxAttribute"),
																			dhkClassMember("numAttributes", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkxAttributeMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("value", dhkClassMember::CLASS, false, 4, "hkVariant")};
const dhkClassMember dhkClassLibrary550::hkxNodeMembers[10] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																dhkClassMember("object", dhkClassMember::CLASS, false, 12, "hkVariant"),
																dhkClassMember("keyFrames", dhkClassMember::PTR_MATRIX4, true, 20),
																dhkClassMember("numKeyFrames", dhkClassMember::DWORD, false, 24),
																dhkClassMember("children", dhkClassMember::PTR_IGNORE, true, 28),
																dhkClassMember("numChildren", dhkClassMember::DWORD, false, 32),
																dhkClassMember("annotations", dhkClassMember::PTR_CLASS, true, 36, "hkxNodeAnnotationData"),
																dhkClassMember("numAnnotations", dhkClassMember::DWORD, false, 40),
																dhkClassMember("userProperties", dhkClassMember::PTR_IGNORE, false, 44),
																dhkClassMember("selected", dhkClassMember::BYTE, false, 48)};
const char* dhkClassLibrary550::hkxNodeParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary550::hkxAnimatedFloatMembers[3] = { dhkClassMember("floats", dhkClassMember::PTR_DWORD, true, 0),
																		dhkClassMember("numFloats", dhkClassMember::DWORD, false, 4),
																		dhkClassMember("hint", dhkClassMember::BYTE, false, 8)};
const dhkClassMember dhkClassLibrary550::hkxAnimatedVectorMembers[3] = { dhkClassMember("vectors", dhkClassMember::PTR_VECTOR4, true, 0),
																			dhkClassMember("numVectors", dhkClassMember::DWORD, false, 4),
																			dhkClassMember("hint", dhkClassMember::BYTE, false, 8)};
const dhkClassMember dhkClassLibrary550::hkxAnimatedQuaternionMembers[2] = { dhkClassMember("quaternions", dhkClassMember::PTR_VECTOR4, true, 0),
																				dhkClassMember("numQuaternions", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary550::hkxSparselyAnimatedStringMembers[4] = { dhkClassMember("strings", dhkClassMember::PTR_IGNORE, true, 0),
																					dhkClassMember("numStrings", dhkClassMember::DWORD, false, 4),
																					dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																					dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkxSparselyAnimatedBoolMembers[4] = { dhkClassMember("bools", dhkClassMember::PTR_IGNORE, true, 0),
																				dhkClassMember("numBools", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkxSparselyAnimatedIntMembers[4] = { dhkClassMember("ints", dhkClassMember::PTR_DWORD, true, 0),
																				dhkClassMember("numInts", dhkClassMember::DWORD, false, 4),
																				dhkClassMember("times", dhkClassMember::PTR_DWORD, true, 8),
																				dhkClassMember("numTimes", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkxMeshMembers[4] = { dhkClassMember("sections", dhkClassMember::PTR_IGNORE, true, 0),
																dhkClassMember("numSections", dhkClassMember::DWORD, false, 4),
																dhkClassMember("userChannelInfos", dhkClassMember::PTR_CLASS, true, 8, "hkxMeshUserChannelInfo"),
																dhkClassMember("numUserChannelInfos", dhkClassMember::DWORD, false, 12)};
const dhkClassMember dhkClassLibrary550::hkxMeshSectionMembers[6] = { dhkClassMember("vertexBuffer", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("indexBuffers", dhkClassMember::PTR_IGNORE, true, 4),
																		dhkClassMember("numIndexBuffers", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("material", dhkClassMember::PTR_IGNORE, false, 12),
																		dhkClassMember("userChannels", dhkClassMember::PTR_CLASS, true, 16, "hkVariant"),
																		dhkClassMember("numUserChannels", dhkClassMember::DWORD, false, 20)};
const dhkClassMember dhkClassLibrary550::hkxMeshUserChannelInfoMembers[2] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																				dhkClassMember("className", dhkClassMember::PTR_IGNORE, false, 12)};
const char* dhkClassLibrary550::hkxMeshUserChannelInfoParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary550::hkxVertexBufferMembers[4] = { dhkClassMember("vertexDataClass", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("vertexData", dhkClassMember::PTR_HOMOGENEOUS, true, 4),
																		dhkClassMember("numVertexData", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("format", dhkClassMember::PTR_IGNORE, false, 12)};
const dhkClassMember dhkClassLibrary550::hkxVertexFormatMembers[12] = { dhkClassMember("stride", dhkClassMember::BYTE, false, 0),
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
const dhkClassMember dhkClassLibrary550::hkxIndexBufferMembers[7] = { dhkClassMember("indexType", dhkClassMember::BYTE, false, 0),
																		dhkClassMember("indices16", dhkClassMember::PTR_WORD, true, 4),
																		dhkClassMember("numIndices16", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("indices32", dhkClassMember::PTR_DWORD, true, 12),
																		dhkClassMember("numIndices32", dhkClassMember::DWORD, false, 16),
																		dhkClassMember("vertexBaseOffset", dhkClassMember::DWORD, false, 20),
																		dhkClassMember("length", dhkClassMember::DWORD, false, 24)};
const dhkClassMember dhkClassLibrary550::hkxMaterialMembers[10] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 8),
																	dhkClassMember("stages", dhkClassMember::PTR_CLASS, true, 12, "hkxMaterialTextureStage"),
																	dhkClassMember("numStages", dhkClassMember::DWORD, false, 16),
																	dhkClassMember("diffuseColor", dhkClassMember::VECTOR4, false, 32),
																	dhkClassMember("ambientColor", dhkClassMember::VECTOR4, false, 48),
																	dhkClassMember("specularColor", dhkClassMember::VECTOR4, false, 64),
																	dhkClassMember("emissiveColor", dhkClassMember::VECTOR4, false, 80),
																	dhkClassMember("subMaterials", dhkClassMember::PTR_IGNORE, true, 96),
																	dhkClassMember("numSubMaterials", dhkClassMember::DWORD, false, 100),
																	dhkClassMember("extraData", dhkClassMember::CLASS, false, 104, "hkVariant")};
const char* dhkClassLibrary550::hkxMaterialParents[1] = { "hkxAttributeHolder" };
const dhkClassMember dhkClassLibrary550::hkxTextureFileMembers[1] = { dhkClassMember("filename", dhkClassMember::PTR_IGNORE, false, 0)};
const dhkClassMember dhkClassLibrary550::hkxTextureInplaceMembers[3] = { dhkClassMember("fileType", dhkClassMember::BYTE, false, 0),
																			dhkClassMember("data", dhkClassMember::PTR_IGNORE, true, 4),
																			dhkClassMember("numData", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkxTriangleSelectionChannelMembers[2] = { dhkClassMember("selectedTriangles", dhkClassMember::PTR_DWORD, true, 0),
																					dhkClassMember("numSelectedTriangles", dhkClassMember::DWORD, false, 4)};
const dhkClassMember dhkClassLibrary550::hkxNodeAnnotationDataMembers[2] = { dhkClassMember("time", dhkClassMember::DWORD, false, 0),
																				dhkClassMember("description", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary550::hkClassMembers[9] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																dhkClassMember("parent", dhkClassMember::PTR_IGNORE, false, 4),
																dhkClassMember("objectSize", dhkClassMember::DWORD, false, 8),
																dhkClassMember("numImplementedInterfaces", dhkClassMember::DWORD, false, 12),
																dhkClassMember("declaredEnums", dhkClassMember::PTR_CLASS, true, 16, "hkClassEnum"),
																dhkClassMember("numDeclaredEnums", dhkClassMember::DWORD, false, 20),
																dhkClassMember("declaredMembers", dhkClassMember::PTR_CLASS, true, 24, "hkClassMember"),
																dhkClassMember("numDeclaredMembers", dhkClassMember::DWORD, false, 28),
																dhkClassMember("defaults", dhkClassMember::DWORD, false, 32)};
const dhkClassMember dhkClassLibrary550::hkClassEnumMembers[3] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("items", dhkClassMember::PTR_CLASS, true, 4, "hkClassEnumItem"),
																	dhkClassMember("numItems", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkClassEnumItemMembers[2] = { dhkClassMember("value", dhkClassMember::DWORD, false, 0),
																		dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 4)};
const dhkClassMember dhkClassLibrary550::hkClassMemberMembers[8] = { dhkClassMember("name", dhkClassMember::PTR_IGNORE, false, 0),
																	dhkClassMember("class", dhkClassMember::PTR_IGNORE, false, 4),
																	dhkClassMember("enum", dhkClassMember::PTR_IGNORE, false, 8),
																	dhkClassMember("type", dhkClassMember::BYTE, false, 12),
																	dhkClassMember("subtype", dhkClassMember::BYTE, false, 13),
																	dhkClassMember("cArraySize", dhkClassMember::WORD, false, 14),
																	dhkClassMember("flags", dhkClassMember::WORD, false, 16),
																	dhkClassMember("offset", dhkClassMember::WORD, false, 18)};
const dhkClassMember dhkClassLibrary550::hkxMaterialTextureStageMembers[2] = { dhkClassMember("texture", dhkClassMember::CLASS, false, 0, "hkVariant"),
																				dhkClassMember("usageHint", dhkClassMember::DWORD, false, 8)};
const dhkClassMember dhkClassLibrary550::hkxSkinBindingMembers[6] = { dhkClassMember("mesh", dhkClassMember::PTR_IGNORE, false, 0),
																		dhkClassMember("mapping", dhkClassMember::PTR_IGNORE, true, 4),
																		dhkClassMember("numMapping", dhkClassMember::DWORD, false, 8),
																		dhkClassMember("bindPose", dhkClassMember::PTR_MATRIX4, true, 12),
																		dhkClassMember("numBindPose", dhkClassMember::DWORD, false, 16),
																		dhkClassMember("initSkinTransform", dhkClassMember::MATRIX4, false, 32)};
const dhkClassMember dhkClassLibrary550::hkxVertexSelectionChannelMembers[2] = { dhkClassMember("selectedVertices", dhkClassMember::PTR_DWORD, true, 0),
																					dhkClassMember("numSelectedVertices", dhkClassMember::DWORD, false, 4)};

dhkClassLibrary550::dhkClassLibrary550(void)
{
	m_classMap.insert(make_pair("hkRootLevelContainerNamedVariant", dhkClass("hkRootLevelContainerNamedVariant", NULL, 0, 16, hkRootLevelContainerNamedVariantMembers, 3)));
	m_classMap.insert(make_pair("hkRootLevelContainer", dhkClass("hkRootLevelContainer", NULL, 0, 16, hkRootLevelContainerMembers, 2)));
	m_classMap.insert(make_pair("hkVariant", dhkClass("hkVariant", NULL, 0, 8, hkVariantMembers, 2)));
	m_classMap.insert(make_pair("hkArray", dhkClass("hkArray", NULL, 0, 12, hkArrayMembers, 3)));
	m_classMap.insert(make_pair("hkSmallArray", dhkClass("hkSmallArray", NULL, 0, 8, hkSmallArrayMembers, 3)));
	m_classMap.insert(make_pair("hkaAnimationContainer", dhkClass("hkaAnimationContainer", NULL, 0, 40, hkaAnimationContainerMembers, 10)));
	m_classMap.insert(make_pair("hkReferencedObject", dhkClass("hkReferencedObject", NULL, 0, 8, hkReferencedObjectMembers, 2)));
	m_classMap.insert(make_pair("hkaSkeletalAnimation", dhkClass("hkaSkeletalAnimation", hkaSkeletalAnimationParents, 1, 0x24, hkaSkeletalAnimationMembers, 7)));
	m_classMap.insert(make_pair("hkaWaveletSkeletalAnimation", dhkClass("hkaWaveletSkeletalAnimation", hkaWaveletSkeletalAnimationParents, 1, 96, hkaWaveletSkeletalAnimationMembers, 11)));
	m_classMap.insert(make_pair("hkaWaveletSkeletalAnimationQuantizationFormat", dhkClass("hkaWaveletSkeletalAnimationQuantizationFormat", NULL, 0, 20, hkaWaveletSkeletalAnimationQuantizationFormatMembers, 6)));
	m_classMap.insert(make_pair("hkaInterleavedSkeletalAnimation", dhkClass("hkaInterleavedSkeletalAnimation", hkaInterleavedSkeletalAnimationParents, 1, 52, hkaInterleavedSkeletalAnimationMembers, 4)));
	m_classMap.insert(make_pair("hkaDeltaCompressedSkeletalAnimation", dhkClass("hkaDeltaCompressedSkeletalAnimation", hkaDeltaCompressedSkeletalAnimationParents, 1, 104, hkaDeltaCompressedSkeletalAnimationMembers, 13)));
	m_classMap.insert(make_pair("hkaDefaultAnimatedReferenceFrame", dhkClass("hkaDefaultAnimatedReferenceFrame", hkaDefaultAnimatedReferenceFrameMembersParents, 1, 0x40, hkaDefaultAnimatedReferenceFrameMembers, 5)));
	//m_classMap550.insert(make_pair("hkVector4", new dhkClass("hkVector4", NULL, 0, 16, hkVector4Members, 4)));
	m_classMap.insert(make_pair("hkaAnnotationTrack", dhkClass("hkaAnnotationTrack", NULL, 0, 16, hkaAnnotationTrackMembers, 3)));
	m_classMap.insert(make_pair("hkaAnnotationTrackAnnotation", dhkClass("hkaAnnotationTrackAnnotation", NULL, 0, 16, hkaAnnotationTrackAnnotationMembers, 2)));
	m_classMap.insert(make_pair("hkaAnimationBinding", dhkClass("hkaAnimationBinding", NULL, 0, 0x20, hkaAnimationBindingMembers, 6)));
	m_classMap.insert(make_pair("hkxScene", dhkClass("hkxScene", NULL, 0, 0x80, hkxSceneMembers, 21)));
	//m_classMap550.insert(make_pair("hkMatrix3", new dhkClass("hkMatrix3", NULL, 0, 0x30, hkMatrix3Members, 3)));
	m_classMap.insert(make_pair("hkaSkeleton", dhkClass("hkaSkeleton", NULL, 0, 0x30, hkaSkeletonMembers, 9)));
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
	m_classMap.insert(make_pair("hkpMaxSizeConstraintMotor", dhkClass("hkpMaxSizeConstraintMotor", hkpMaxSizeConstraintMotorParents, 1, 48, hkpMaxSizeConstraintMotorMembers, 9)));
	m_classMap.insert(make_pair("hkpLimitedForceConstraintMotor", dhkClass("hkpLimitedForceConstraintMotor", hkpLimitedForceConstraintMotorParents, 1, 20, hkpLimitedForceConstraintMotorMembers, 2)));
	m_classMap.insert(make_pair("hkpPositionConstraintMotor", dhkClass("hkpPositionConstraintMotor", hkpPositionConstraintMotorParents, 1, 36, hkpPositionConstraintMotorMembers, 4)));
	m_classMap.insert(make_pair("hkpConvexVerticesShapeFourVectors", dhkClass("hkpConvexVerticesShapeFourVectors", NULL, 0, 48, hkpConvexVerticesShapeFourVectorsMembers, 3)));
	m_classMap.insert(make_pair("hkpConvexVerticesShape", dhkClass("hkpConvexVerticesShape", hkpConvexVerticesShapeParents, 1, 96, hkpConvexVerticesShapeMembers, 6)));
	m_classMap.insert(make_pair("hkpConvexVerticesConnectivity", dhkClass("hkpConvexVerticesConnectivity", hkpConvexVerticesConnectivityParents, 1, 32, hkpConvexVerticesConnectivityMembers, 2)));
	m_classMap.insert(make_pair("hkpSingleShapeContainer", dhkClass("hkpSingleShapeContainer", hkpSingleShapeContainerParents, 1, 4, hkpSingleShapeContainerMembers, 1)));
	m_classMap.insert(make_pair("hkpShapeContainer", dhkClass("hkpShapeContainer", NULL, 0, 0, NULL, 0)));
	m_classMap.insert(make_pair("hkpConvexTranslateShape", dhkClass("hkpConvexTranslateShape", hkpConvexTranslateShapeParents, 1, 48, hkpConvexTranslateShapeMembers, 3)));
	m_classMap.insert(make_pair("hkpBoxShape", dhkClass("hkpBoxShape", hkpBoxShapeParents, 1, 48, hkpBoxShapeMembers, 1)));
	m_classMap.insert(make_pair("hkpSphereShape", dhkClass("hkpSphereShape", hkpSphereShapeParents, 1, 32, hkpSphereShapeMembers, 3)));
	m_classMap.insert(make_pair("hkpCylinderShape", dhkClass("hkpCylinderShape", hkpCylinderShapeParents, 1, 96, hkpCylinderShapeMembers, 6)));
	m_classMap.insert(make_pair("CustomParamStorageExtendedMeshShape", dhkClass("CustomParamStorageExtendedMeshShape", CustomParamStorageExtendedMeshShapeParents, 1, 228, CustomParamStorageExtendedMeshShapeMembers, 1)));
	m_classMap.insert(make_pair("CustomMeshParameter", dhkClass("CustomMeshParameter", CustomMeshParameterParents, 1, 36, CustomMeshParameterMembers, 7)));
	m_classMap.insert(make_pair("hkpStorageExtendedMeshShape", dhkClass("hkpStorageExtendedMeshShape", hkpStorageExtendedMeshShapeParents, 1, 216, hkpStorageExtendedMeshShapeMembers, 2)));
	m_classMap.insert(make_pair("hkpStorageExtendedMeshShapeMeshSubpartStorage", dhkClass("hkpStorageExtendedMeshShapeMeshSubpartStorage", hkpStorageExtendedMeshShapeMeshSubpartStorageParents, 1, 80, hkpStorageExtendedMeshShapeMeshSubpartStorageMembers, 6)));
	m_classMap.insert(make_pair("hkpExtendedMeshShape", dhkClass("hkpExtendedMeshShape", hkpExtendedMeshShapeParents, 1, 192, hkpExtendedMeshShapeMembers, 15)));
	m_classMap.insert(make_pair("hkpExtendedMeshShapeTrianglesSubpart", dhkClass("hkpExtendedMeshShapeTrianglesSubpart", hkpExtendedMeshShapeTrianglesSubpartParents, 1, 64, hkpExtendedMeshShapeTrianglesSubpartMembers, 10)));
	m_classMap.insert(make_pair("hkpExtendedMeshShapeSubpart", dhkClass("hkpExtendedMeshShapeSubpart", NULL, 0, 16, hkpExtendedMeshShapeSubpartMembers, 7)));
	m_classMap.insert(make_pair("hkpShapeCollection", dhkClass("hkpShapeCollection", hkpShapeCollectionParents, 2, 20, hkpShapeCollectionMembers, 1)));
	m_classMap.insert(make_pair("hkpShapeContainer", dhkClass("hkpShapeContainer", NULL, 0, 0, NULL, 0)));
	m_classMap.insert(make_pair("hkpBvTreeShape", dhkClass("hkpBvTreeShape", hkpBvTreeShapeParents, 1, 16, NULL, 0)));
	m_classMap.insert(make_pair("hkpMoppCode", dhkClass("hkpMoppCode", hkpMoppCodeParents, 1, 48, hkpMoppCodeMembers, 3)));
	m_classMap.insert(make_pair("hkpMoppCodeCodeInfo", dhkClass("hkpMoppCodeCodeInfo", NULL, 0, 16, hkpMoppCodeCodeInfoMembers, 1)));
	m_classMap.insert(make_pair("hkMoppBvTreeShapeBase", dhkClass("hkMoppBvTreeShapeBase", hkMoppBvTreeShapeBaseParents, 1, 48, hkMoppBvTreeShapeBaseMembers, 4)));
	m_classMap.insert(make_pair("hkpMoppBvTreeShape", dhkClass("hkpMoppBvTreeShape", hkpMoppBvTreeShapeParents, 1, 56, hkpMoppBvTreeShapeMembers, 2)));
	m_classMap.insert(make_pair("hkpConvexTransformShape", dhkClass("hkpConvexTransformShape", hkpConvexTransformShapeParents, 1, 96, hkpConvexTransformShapeMembers, 3)));
	m_classMap.insert(make_pair("hkpConstraintChainInstance", dhkClass("hkpConstraintChainInstance", hkpConstraintChainInstanceParents, 1, 60, hkpConstraintChainInstanceMembers, 2)));
	m_classMap.insert(make_pair("hkpAction", dhkClass("hkpAction", hkpActionParents, 1, 24, hkpActionMembers, 4)));
	m_classMap.insert(make_pair("hkpConstraintChainInstanceAction", dhkClass("hkpConstraintChainInstanceAction", hkpConstraintChainInstanceActionParents, 1, 28, hkpConstraintChainInstanceActionMembers, 1)));
	m_classMap.insert(make_pair("hkpConstraintChainData", dhkClass("hkpConstraintChainData", hkpConstraintChainDataParents, 1, 12, NULL, 0)));
	m_classMap.insert(make_pair("hkpBallSocketChainData", dhkClass("hkpBallSocketChainData", hkpBallSocketChainDataParents, 1, 52, hkpBallSocketChainDataMembers, 6)));
	m_classMap.insert(make_pair("hkpBallSocketChainDataConstraintInfo", dhkClass("hkpBallSocketChainDataConstraintInfo", NULL, 0, 32, hkpBallSocketChainDataConstraintInfoMembers, 2)));
	m_classMap.insert(make_pair("hkpBridgeAtoms", dhkClass("hkpBridgeAtoms", NULL, 0, 12, hkpBridgeAtomsMembers, 1)));
	m_classMap.insert(make_pair("hkpBridgeConstraintAtom", dhkClass("hkpBridgeConstraintAtom", hkpBridgeConstraintAtomParents, 1, 12, hkpBridgeConstraintAtomMembers, 2)));
	m_classMap.insert(make_pair("hkpBallAndSocketConstraintData", dhkClass("hkpBallAndSocketConstraintData", hkpBallAndSocketConstraintDataParents, 1, 68, hkpBallAndSocketConstraintDataMembers, 1)));
	m_classMap.insert(make_pair("hkpBallAndSocketConstraintDataAtoms", dhkClass("hkpBallAndSocketConstraintDataAtoms", NULL, 0, 52, hkpBallAndSocketConstraintDataAtomsMembers, 2)));
	m_classMap.insert(make_pair("hkpSetLocalTranslationsConstraintAtom", dhkClass("hkpSetLocalTranslationsConstraintAtom", hkpSetLocalTranslationsConstraintAtomParents, 1, 48, hkpSetLocalTranslationsConstraintAtomMembers, 2)));
	m_classMap.insert(make_pair("hkpSimpleMeshShape", dhkClass("hkpSimpleMeshShape", hkpSimpleMeshShapeParents, 1, 68, hkpSimpleMeshShapeMembers, 5)));
	m_classMap.insert(make_pair("hkpSimpleMeshShapeTriangle", dhkClass("hkpSimpleMeshShapeTriangle", NULL, 0, 16, hkpSimpleMeshShapeTriangleMembers, 4)));
	m_classMap.insert(make_pair("hkpMeshShape", dhkClass("hkpMeshShape", hkpMeshShapeParents, 1, 96, hkpMeshShapeMembers, 9)));
	m_classMap.insert(make_pair("hkpMeshShapeSubpart", dhkClass("hkpMeshShapeSubpart", NULL, 0, 56, hkpMeshShapeSubpartMembers, 15)));
	m_classMap.insert(make_pair("hkpStorageMeshShape", dhkClass("hkpStorageMeshShape", hkpStorageMeshShapeParents, 1, 108, hkpStorageMeshShapeMembers, 1)));
	m_classMap.insert(make_pair("hkpStorageMeshShapeSubpartStorage", dhkClass("hkpStorageMeshShapeSubpartStorage", hkpStorageMeshShapeSubpartStorageParents, 1, 80, hkpStorageMeshShapeSubpartStorageMembers, 6)));
	m_classMap.insert(make_pair("hkxAttributeHolder", dhkClass("hkxAttributeHolder", NULL, 0, 8, hkxAttributeHolderMembers, 2)));
	m_classMap.insert(make_pair("hkxAttributeGroup", dhkClass("hkxAttributeGroup", NULL, 0, 12, hkxAttributeGroupMembers, 3)));
	m_classMap.insert(make_pair("hkxAttribute", dhkClass("hkxAttribute", NULL, 0, 12, hkxAttributeMembers, 2)));
	m_classMap.insert(make_pair("hkxNode", dhkClass("hkxNode", hkxNodeParents, 1, 52, hkxNodeMembers, 10)));
	m_classMap.insert(make_pair("hkxAnimatedFloat", dhkClass("hkxAnimatedFloat", NULL, 0, 12, hkxAnimatedFloatMembers, 3)));
	m_classMap.insert(make_pair("hkxAnimatedVector", dhkClass("hkxAnimatedVector", NULL, 0, 12, hkxAnimatedVectorMembers, 3)));
	m_classMap.insert(make_pair("hkxAnimatedQuaternion", dhkClass("hkxAnimatedQuaternion", NULL, 0, 8, hkxAnimatedQuaternionMembers, 2)));
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
	m_classMap.insert(make_pair("hkxSkinBinding", dhkClass("hkxSkinBinding", NULL, 0, 96, hkxSkinBindingMembers, 6)));
	m_classMap.insert(make_pair("hkxVertexSelectionChannel", dhkClass("hkxVertexSelectionChannel", NULL, 0, 8, hkxVertexSelectionChannelMembers, 2)));
}


dhkClassLibrary550::~dhkClassLibrary550(void)
{
}

dhkClass* dhkClassLibrary550::getClass(const char* className)
{
	try {
		return &m_classMap.at(className);
	} catch (const out_of_range& e) {
		printf("Couldn't find class %s in library!\n", className);
		return 0;
	}
}
