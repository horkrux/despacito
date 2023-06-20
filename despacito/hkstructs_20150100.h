#pragma once

#include "hkstructs_common.h"

#pragma pack(push)
#pragma pack(8)
typedef struct {
	void* data;
	int pad;
	int size;
	int capacityAndFlags;
} hkArray64;

typedef struct {
	int ref_obj[4];
	hkArray64 vertices;
	hkArray64 indices8;
	hkArray64 indices16;
	hkArray64 indices32;
	hkArray64 materialIndices;
	hkArray64 materials;
	hkArray64 namedMaterials;
	hkArray64 materialIndices16;
} MeshSubpartStorage_SDKV20150100;

typedef struct {
	unsigned short typeAndFlags;
	unsigned short shapeInfo;
	short materialStriding;
	unsigned short materialIndexStriding;
	long long materialIndexBase;
	long long materialBase;
	unsigned long long userData;
	int numTriangleShapes;
	long long vertexBase;
	int numVertices;
	long long indexBase;
	unsigned short vertexStriding;
	int triangleOffset;
	unsigned short indexStriding;
	char stridingType;
	char flipAlternateTriangles;
	int pad;
	Vector4 extrusion;
	QsTransform transform;
} TrianglesSubpart_SDKV20150100;

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
	int pad1;
	hkArray64 trianglesSubparts;
	hkArray64 shapesSubparts;
	hkArray64 weldingInfo;
	char weldingType;
	//char pad1[3];
	unsigned int defaultCollisionFilterInfo;
	int cachedNumChildShapes;
	float triangleRadius;
	int padding[4];
	//<--hkpExtendedMeshShape
	//hkpStorageExtendedMeshShape-->
	hkArray64 meshstorage;
	hkArray64 shapestorage;
	//<--hkpStorageExtendedMeshShape
	hkArray64 materialArray;
} CustomParamStorageExtendedMeshShape_SDKV20150100;

typedef struct {
	int ref_obj[4];
	unsigned int version;
	int pad;
	hkArray64 vertexDataBuffer;
	int vertexDataStride;
	int pad1;
	hkArray64 primitiveDataBuffer;
	unsigned int materialNameData;
} CustomMeshParameter_SDKV20150100;

#pragma pack(pop)