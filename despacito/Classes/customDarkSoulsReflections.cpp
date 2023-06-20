/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2010 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */
//HK_REFLECTION_PARSER_EXCLUDE_FILE

//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>
#include <ContentTools/Common/Filters/Common/hctFilterCommon.h>
// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'ContentTools/Common/Filters/FilterCustomShit/CustomShit/CustomMeshParameter.h'
//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>
#include <Common/Base/Reflection/hkClass.h>
#include <Common/Base/Reflection/hkInternalClassMember.h>
#include <Common/Base/Reflection/hkTypeInfo.h>
#include <Common/Base/Reflection/Attributes/hkAttributes.h>
#include "../CustomMeshParameter.h"
#define True true
#define False false

//
// Class CustomParamStorageExtendedMeshShape
//
static const hkInternalClassMember CustomMeshParameterClass_Members[] =
{
	{ "version", HK_NULL, HK_NULL, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(CustomMeshParameter,m_version), HK_NULL },
	{ "vertexDataBuffer", HK_NULL, HK_NULL, hkClassMember::TYPE_SIMPLEARRAY, hkClassMember::TYPE_UINT8, 0, 0, HK_OFFSET_OF(CustomMeshParameter,m_vertexDataBuffer), HK_NULL },
	{ "vertexDataStride", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(CustomMeshParameter,m_vertexDataStride), HK_NULL },
	{ "primitiveDataBuffer", HK_NULL, HK_NULL, hkClassMember::TYPE_SIMPLEARRAY, hkClassMember::TYPE_UINT8, 0, 0, HK_OFFSET_OF(CustomMeshParameter,m_primitiveDataBuffer), HK_NULL },
	{ "materialNameData", HK_NULL, HK_NULL, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(CustomMeshParameter,m_materialNameData), HK_NULL }
};
//extern const hkClass hkReferencedObjectClass;

extern const hkClass CustomMeshParameterClass;
const hkClass CustomMeshParameterClass(
	"CustomMeshParameter",
	&hkReferencedObjectClass, // parent
	sizeof(CustomMeshParameter),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(CustomMeshParameterClass_Members),
	HK_COUNT_OF(CustomMeshParameterClass_Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	0 // version
	);
HK_REFLECTION_DEFINE_VIRTUAL(CustomMeshParameter, CustomMeshParameter);

//HK_REFLECTION_PARSER_EXCLUDE_FILE

//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>

// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'ContentTools/Common/Filters/FilterCustomShit/CustomShit/CustomParamStorageExtendedMeshShape.h'
//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>
#include <Common/Base/Reflection/hkClass.h>
#include <Common/Base/Reflection/hkInternalClassMember.h>
#include <Common/Base/Reflection/hkTypeInfo.h>
#include <Common/Base/Reflection/Attributes/hkAttributes.h>
#include "../CustomParamStorageExtendedMeshShape.h"
#define True true
#define False false

//
// Class CustomParamStorageExtendedMeshShape
//
static const hkInternalClassMember CustomParamStorageExtendedMeshShapeClass_Members[] =
{
	{ "materialArray", &CustomMeshParameterClass, HK_NULL, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_POINTER, 0, 0, HK_OFFSET_OF(CustomParamStorageExtendedMeshShape,m_materialArray), HK_NULL }
};
//extern const hkClass hkpStorageExtendedMeshShapeClass;

extern const hkClass CustomParamStorageExtendedMeshShapeClass;
const hkClass CustomParamStorageExtendedMeshShapeClass(
	"CustomParamStorageExtendedMeshShape",
	&hkpStorageExtendedMeshShapeClass, // parent
	sizeof(CustomParamStorageExtendedMeshShape),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(CustomParamStorageExtendedMeshShapeClass_Members),
	HK_COUNT_OF(CustomParamStorageExtendedMeshShapeClass_Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	0 // version
	);
HK_REFLECTION_DEFINE_VIRTUAL(CustomParamStorageExtendedMeshShape, CustomParamStorageExtendedMeshShape);


//HK_REFLECTION_PARSER_EXCLUDE_FILE

//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>

// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'ContentTools/Common/Filters/FilterCustomShit/CustomShit/hctCustomShitOptions.h'
//#include <ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h>
//#include <Common/Base/Reflection/hkClass.h>
//#include <Common/Base/Reflection/hkInternalClassMember.h>
//#include <Common/Base/Reflection/hkTypeInfo.h>
//#include <Common/Base/Reflection/Attributes/hkAttributes.h>
//#include <ContentTools/Common/Filters/FilterCustomShit/CustomShit/hctCustomShitOptions.h>
//#define True true
//#define False false
//
//
//
////
//// Class hctCustomShitOptions
////
////static const hkInternalClassMember hctCustomShitOptionsClass_Members[] =
////{
////	{ "removeMeshes", HK_NULL, HK_NULL, hkClassMember::TYPE_BOOL, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hctCustomShitOptions,m_removeMeshes), HK_NULL }
////};
//extern const hkClass hctCustomShitOptionsClass;
//const hkClass hctCustomShitOptionsClass(
//	"hctCustomShitOptions",
//	HK_NULL, // parent
//	sizeof(hctCustomShitOptions),
//	HK_NULL,
//	0, // interfaces
//	HK_NULL,
//	0, // enums
//	//reinterpret_cast<const hkClassMember*>(hctCustomShitOptionsClass_Members),
//	HK_NULL,
//	//HK_COUNT_OF(hctCustomShitOptionsClass_Members),
//	0,
//	HK_NULL, // defaults
//	HK_NULL, // attributes
//	0, // flags
//	0 // version
//	);
//HK_REFLECTION_DEFINE_SIMPLE(hctCustomShitOptions, hctCustomShitOptions);

/*
* Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20101115)
* 
* Confidential Information of Havok.  (C) Copyright 1999-2010
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
* 
* Use of this software for evaluation purposes is subject to and indicates
* acceptance of the End User licence Agreement for this product. A copy of
* the license is included with this software and is also available at www.havok.com/tryhavok.
* 
*/
