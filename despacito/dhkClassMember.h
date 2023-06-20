#pragma once

class dhkClassMember
{
public:
	//TODO: maybe remove PTR items and introduce isPtr instead
	enum MEMBER_TYPE {
		PTR_IGNORE,
		PTR_WORD,
		PTR_DWORD,
		PTR_QWORD,
		PTR_VECTOR4,
		PTR_MATRIX3,
		PTR_MATRIX4,
		PTR_CLASS,
		PTR_GENERIC,
		PTR_HOMOGENEOUS,
		BYTE,
		WORD,
		DWORD,
		QWORD,
		VECTOR4,
		MATRIX3,
		MATRIX4,
		CLASS
	};

	dhkClassMember();
	dhkClassMember(const char* name, MEMBER_TYPE memberType, bool isArray, int offset, const char* className = 0, MEMBER_TYPE subType = PTR_IGNORE, const char* subTypeName = 0);
	void Init(const char* name, MEMBER_TYPE memberType, bool isArray, int offset, const char* className = 0, MEMBER_TYPE subType = PTR_IGNORE, const char* subTypeName = 0);
	

	const char* m_name;
	MEMBER_TYPE m_memberType;
	bool m_isArray;
	int m_offset;
	const char* m_className;
	MEMBER_TYPE m_subType;
	const char* m_subTypeName;
};