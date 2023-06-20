#pragma once

#include "dhkClassMember.h"

class dhkClass
{
public:

	enum HAVOK_VERSION 
	{
		HK410,
		HK450,
		HK510,
		HK550,
		OTHER
	};

	dhkClass(const char* name,
			 const char** parent,
			 int numParents,
			 int objectSize,
			 const dhkClassMember* declaredMembers,
			 int numDeclaredMembers);

	const char* m_name;
	const char** m_parent;
	int m_numParents;
	int m_alignedObjectSize;
	const dhkClassMember* m_declaredMembers;
	int m_numDeclaredMembers;
};

