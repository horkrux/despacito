#pragma once

#include "hkstructs_common.h"
#include "hkstructs_20150100.h"

//This is for the switch version of DS1

typedef struct {
	int ref_obj[4];
	int hkcd[4];
	//hkpShape-->
	unsigned long long userData;
	//<--hkpShape
	//hkpShapeCollection-->
	char disableWelding;
	char collectionType;
	char pad0[6];
	//<--hkpShapeCollection
	//hkpExtendedMeshShape-->
	TrianglesSubpart_SDKV20150100 embeddedTrianglesSubpart;
	Vector4 aabbHalfExtents;
	Vector4 aabbCenter;
	long long materialClass;
	int numBitsForSubpartIndex;
	int trianglesSubparts[4];
	int shapesSubparts[4];
	int weldingInfo[4];
	char weldingType;
	char pad1[3];
	unsigned int defaultCollisionFilterInfo;
	int cachedNumChildShapes;
	float triangleRadius;
	int padding[2];
	//<--hkpExtendedMeshShape
	//hkpStorageExtendedMeshShape-->
	int meshstorage[4];
	int shapestorage[4];
	//<--hkpStorageExtendedMeshShape
	int materialArray[4];
} CustomParamStorageExtendedMeshShape_SDKV20160200;
