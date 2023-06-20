/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2010 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef CUSTOM_MESHPARAMETER_H
#define CUSTOM_MESHPARAMETER_H

#include <Common/Base/Object/hkReferencedObject.h>

//meta information
extern const class hkClass CustomMeshParameterClass;

#include <stdlib.h>

using namespace std;

class CustomMeshParameter : public hkReferencedObject
{
	//+vtable(1)
	public:

		HK_DECLARE_REFLECTION();
		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SHAPE);
		CustomMeshParameter( hkFinishLoadedObjectFlag f ) : hkReferencedObject(f) {};
		CustomMeshParameter();
		~CustomMeshParameter();

	public:

		hkUint32 m_version;
		hkUint8* m_vertexDataBuffer;
		int m_numVertexDataBuffer;
		hkInt32 m_vertexDataStride;
		hkUint8* m_primitiveDataBuffer;
		int m_numPrimitiveDataBuffer;
		hkUint32 m_materialNameData;
};

#endif //CUSTOM_MESHPARAMETER_H

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