#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

#include "dhkClass.h"
#include "dhkClassLibrary410.h"
#include "dhkClassLibrary450.h"
#include "dhkClassLibrary510.h"
#include "dhkClassLibrary550.h"

using namespace std;

class dhkClassParser
{
public:
	dhkClassParser(void);
	~dhkClassParser(void);

	//void initClassLibrary450();
	//void initClassLibrary550();
	int parseAndFixData(char*, int*, char*, dhkClass::HAVOK_VERSION);
	void parseClass(const char*, char*, dhkClassMember::MEMBER_TYPE subType = dhkClassMember::PTR_IGNORE, const char* subClassName = 0);
	void parseClassMember(const dhkClass*, const dhkClassMember*, char*, dhkClassMember::MEMBER_TYPE classSubType = dhkClassMember::PTR_IGNORE, const char* subClassName = 0);
	void parseGenericArray(const dhkClass*, const dhkClassMember*, char*, dhkClassMember::MEMBER_TYPE, const char* classSubName = 0);
	void removeMetadataOffsets(char*, int*);
	vector<int>* getOffsetsToDelete();
	//void parseClassMembers(const dhkClass*, const char*, char*);

	/*class ptrWorklistEntry
	{
	public:
		ptrWorklistEntry(const dhkClassMember*, int, const char*);

		const dhkClassMember* m_member;
		int m_numElem;
		const char* m_offset;
		const char* m_className;
	};*/

	typedef unordered_map<string, dhkClass*> classMap;

private:

	struct dhkVertexFormat {
		char striding;
		char positionOffset;
		char normalOffset;
		char tangentOffset;
		char binormalOffset;
		char numBonesPerVertex;
		char boneIndexOffset;
		char boneWeightOffset;
		char numTextureChannels;
		char tFloatCoordOffset;
		char tQuantizedCoordOffset;
		char colorOffset;
	};

	dhkClass::HAVOK_VERSION m_currFileHavokVersion;
	vector<int> m_offsetsToDelete;
	//unordered_map<string, dhkClass*> m_classMap550;
	unordered_map<int, int> m_arrayOffsetMap;
	unordered_map<int, int> m_classOffsetMap;
	unordered_map<int, int> m_classNameOffsetMap;
	dhkClassLibrary410* m_classLibrary410;
	dhkClassLibrary450* m_classLibrary450;
	dhkClassLibrary510* m_classLibrary510;
	dhkClassLibrary550* m_classLibrary550;

	dhkClass* getClass(const char*);

};

