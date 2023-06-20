#include "dhkClass.h"


dhkClass::dhkClass(const char* name,
				   const char** parent,
				   int numParents,
				   int objectSize,
				   const dhkClassMember* declaredMembers,
				   int numDeclaredMembers)
				   : m_name(name),
					 m_parent(parent),
					 m_numParents(numParents),
					 m_alignedObjectSize(objectSize),
					 m_declaredMembers(declaredMembers),
					 m_numDeclaredMembers(numDeclaredMembers)
{
}
