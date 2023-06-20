#include "dhkClassMember.h"

dhkClassMember::dhkClassMember()
{
}

dhkClassMember::dhkClassMember(const char* name, MEMBER_TYPE memberType, bool isArray, int offset, const char* className, MEMBER_TYPE subType, const char* subTypeName) 
	: m_name(name), m_memberType(memberType), m_isArray(isArray), m_offset(offset), m_className(className), m_subType(subType), m_subTypeName(subTypeName)
{
}

void dhkClassMember::Init(const char* name, MEMBER_TYPE memberType, bool isArray, int offset, const char* className, MEMBER_TYPE subType, const char* subTypeName)
{
	m_name = name;
	m_memberType = memberType;
	m_isArray = isArray;
	m_className = className;
	m_subType = subType;
	m_subTypeName = subTypeName;
}