#include "hkstructs_common.h"

typedef struct {
//Subpart-->(not sure about this layout, since it doesn't really match up)
	char type;											//hkEnum<SubpartType, hkInt8> m_type;
	char materialIndexStridingType;						//hkEnum<MaterialIndexStridingType, hkInt8> m_materialIndexStridingType;
	short materialStriding;
	int* materialIndexBase;
	unsigned short materialIndexStriding;
	unsigned short numMaterials;
	int* materialBase;
	int userData;										
//<--Subpart
	int numTriangleShapes;
	float* vertexBase;
	int numVertices;
	int* indexBase;
	unsigned short vertexStriding;
	short pad0;
	int triangleOffset;
	unsigned short indexStriding;
	char stridingType;									//hkEnum<IndexStridingType, hkInt8>
	char flipAlternateTriangles;
	Vector4 extrusion;
	QsTransform transform;
} TrianglesSubpart_hk2010;

typedef struct {
	hkReferencedObject ref_obj;
	hkArray vertices;//hkArray<hkVector4>
	hkArray indices8;//hkArray<hkUint8>
	hkArray indices16;//hkArray<hkUint16>
	hkArray indices32;//hkArray<hkUint32>
	hkArray materialIndices; //materialIndices8
	hkArray materials;//hkArray<struct Material>
	hkArray namedMaterials;//hkArray<class hkpNamedMeshMaterial>
	hkArray materialIndices16;//hkArray<hkUint16>
} MeshSubpartStorage_hk2010;

#pragma pack(push)
#pragma pack(4)
typedef struct {
	hkReferencedObject ref_obj;
//hkpShape-->
	unsigned long long userData;
	int type;											//hkEnum< ::hkpShapeType, hkUint32>
//<--hkpShape
//hkpShapeCollection-->
	char disableWelding;								//hkBool
	char collectionType;							//hkEnum<CollectionType, hkUint8>
	char pad0[10];
//<--hkpShapeCollection
//hkpExtendedMeshShape-->
	TrianglesSubpart_hk2010 embeddedTrianglesSubpart;
	Vector4 aabbHalfExtents;
	Vector4 aabbCenter;
	int* materialClass;
	int numBitsForSubpartIndex;
	hkArray trianglesSubparts;							//hkArray<struct TrianglesSubpart>
	hkArray shapesSubparts;								//hkArray<struct ShapesSubpart>
	hkArray weldingInfo;								//hkArray<hkUint16>
	char weldingType;									//hkEnum<hkpWeldingUtility::WeldingType, hkUint8>
	char pad1[3];
	unsigned int defaultCollisionFilterInfo;
	int cachedNumChildShapes;
	float triangleRadius;
	int padding;
//<--hkpExtendedMeshShape
//hkpStorageExtendedMeshShape-->
	hkArray meshstorage;								//hkArray<struct MeshSubpartStorage*>
	hkArray shapestorage;								//hkArray<struct ShapeSubpartStorage*>
	int pad2[2];
//<--hkpStorageExtendedMeshShape
	hkArray materialArray;
	int pad3;
} CustomParamStorageExtendedMeshShape_hk2010;

typedef struct {
	hkReferencedObject ref_obj;
	unsigned int version;
	SimpleArray vertexDataBuffer;
	int vertexDataStride;
	SimpleArray primitiveDataBuffer;
	unsigned int materialNameData;
} CustomMeshParameter_hk2010;

typedef struct {
	hkReferencedObject ref_obj;
	//hkpShape-->
	unsigned long long userData;
	int type;											//hkEnum< ::hkpShapeType, hkUint32>
//<--hkpShape
//hkpShapeCollection-->
	char disableWelding;								//hkBool
	char collectionType;							//hkEnum<CollectionType, hkUint8>
	char pad0[10];
	//<--hkpShapeCollection
	//hkpExtendedMeshShape-->
	TrianglesSubpart_hk2010 embeddedTrianglesSubpart;
	Vector4 aabbHalfExtents;
	Vector4 aabbCenter;
	int* materialClass;
	int numBitsForSubpartIndex;
	hkArray trianglesSubparts;							//hkArray<struct TrianglesSubpart>
	hkArray shapesSubparts;								//hkArray<struct ShapesSubpart>
	hkArray weldingInfo;								//hkArray<hkUint16>
	char weldingType;									//hkEnum<hkpWeldingUtility::WeldingType, hkUint8>
	char pad1[3];
	unsigned int defaultCollisionFilterInfo;
	int cachedNumChildShapes;
	float triangleRadius;
	int padding;
	//<--hkpExtendedMeshShape
	hkArray meshstorage;								//hkArray<struct MeshSubpartStorage*>
	hkArray shapestorage;								//hkArray<struct ShapeSubpartStorage*>
	int pad2[2];
} hkpStorageExtendedMeshShape_hk2010;
#pragma pack(pop)

