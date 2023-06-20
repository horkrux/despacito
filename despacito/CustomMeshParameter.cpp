/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2010 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

//#include "ContentTools/Common/Filters/FilterCustomShit/hctFilterCustomShit.h"
#include <ContentTools/Common/Filters/Common/hctFilterCommon.h>
#include "CustomMeshParameter.h"

CustomMeshParameter::CustomMeshParameter()
	: m_version(0x9100), m_vertexDataBuffer(0), m_numVertexDataBuffer(0), m_vertexDataStride(1), m_primitiveDataBuffer(0), m_numPrimitiveDataBuffer(0), m_materialNameData(0)
{
}

CustomMeshParameter::~CustomMeshParameter()
{
	if (m_vertexDataBuffer)
	{
		free(m_vertexDataBuffer);
	}

	if (m_primitiveDataBuffer)
	{
		free(m_primitiveDataBuffer);
	}
}

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
