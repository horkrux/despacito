#include "dhkClassParser.h"

const char* g_dataPtr = nullptr;
const int* g_dataArrayPtr = nullptr;
const int* g_dataClassPtr = nullptr;
const int* g_dataClassNamePtr = nullptr;
char* g_classNamesOffset = nullptr;
ofstream dbgLogFile;

dhkClassParser::dhkClassParser(void)
{
	m_classLibrary410 = new dhkClassLibrary410();
	m_classLibrary450 = new dhkClassLibrary450();
	m_classLibrary510 = new dhkClassLibrary510();
	m_classLibrary550 = new dhkClassLibrary550();
}


dhkClassParser::~dhkClassParser(void)
{
	if (m_classLibrary410) {
		delete m_classLibrary410;
		m_classLibrary410 = 0;
	}

	if (m_classLibrary450) {
		delete m_classLibrary450;
		m_classLibrary450 = 0;
	}
		
	if (m_classLibrary510) {
		delete m_classLibrary510;
		m_classLibrary510 = 0;
	}

	if (m_classLibrary550) {
		delete m_classLibrary550;
		m_classLibrary550 = 0;
	}
}

int dhkClassParser::parseAndFixData(char* contents, int* dataOffsets, char* classNamesOffset, dhkClass::HAVOK_VERSION havokVersion)
{
	if (havokVersion == dhkClass::OTHER) {
		return 1;
	}
	
	//initial clean-up in case we already processed a file

	if (m_arrayOffsetMap.size())
		m_arrayOffsetMap.clear();

	if (m_classOffsetMap.size())
		m_classOffsetMap.clear();

	if (m_classNameOffsetMap.size())
		m_classNameOffsetMap.clear();

	if (m_offsetsToDelete.size())
		vector<int>().swap(m_offsetsToDelete);

	m_currFileHavokVersion = havokVersion;

	int* dataArrayOffsets = (int*)(contents + dataOffsets[0] + dataOffsets[1]);
	int* dataClassOffsets = (int*)(contents + dataOffsets[0] + dataOffsets[2]);
	int* dataClassNameOffsets = (int*)(contents + dataOffsets[0] + dataOffsets[3]);
	int* fileEnd = (int*)(contents + dataOffsets[0] + dataOffsets[4]);

	char* dataPtr = contents + dataOffsets[0];

	int* arrayPtr = dataArrayOffsets;
	int* classPtr = dataClassOffsets;
	int* classNamePtr = dataClassNameOffsets;

	g_dataPtr = dataPtr;
	g_dataArrayPtr = arrayPtr;
	g_dataClassPtr = classPtr;
	g_dataClassNamePtr = classNamePtr;
	g_classNamesOffset = classNamesOffset;

	do 
	{
		if (*arrayPtr == -1)
			break;

		m_arrayOffsetMap.insert(make_pair(*arrayPtr, *(arrayPtr + 1)));
		
		arrayPtr += 2;
	} while (arrayPtr < (int*)classPtr);

	do
	{
		if (*classPtr == -1)
			break;

		m_classOffsetMap.insert(make_pair(*classPtr, *(classPtr + 2)));

		classPtr += 3;
	} while (classPtr < (int*)classNamePtr);

	do
	{
		if (*classNamePtr == -1)
			break;

		m_classNameOffsetMap.insert(make_pair(*classNamePtr, *(classNamePtr + 2)));

		classNamePtr += 3;
	} while (classNamePtr < fileEnd);



	do
	{
		if (*g_dataClassNamePtr < 0)
			break;

		char* className = (char*)(*(g_dataClassNamePtr + 2) + classNamesOffset);


		dataPtr = contents + dataOffsets[0] + *g_dataClassNamePtr;

		parseClass(className, dataPtr);
		
		g_dataClassNamePtr += 3;

	} while (g_dataClassNamePtr < fileEnd);


	return 0;

}

void dhkClassParser::parseClass(const char* className, char* dataPtr, dhkClassMember::MEMBER_TYPE subType, const char* subClassName)
{
	dhkClass* hkClass = getClass(className);

	if (hkClass)
	{
		for (int i = 0; i < hkClass->m_numParents; i++)
		{
			parseClass(hkClass->m_parent[i], dataPtr, subType, subClassName);
		}

		for (int i = 0; i < hkClass->m_numDeclaredMembers; i++)
		{
			parseClassMember(hkClass, &hkClass->m_declaredMembers[i], dataPtr, subType, subClassName);
		}
	}
}

void dhkClassParser::parseClassMember(const dhkClass* holderClass, const dhkClassMember* member, char* dataPtr, dhkClassMember::MEMBER_TYPE classSubType, const char* subClassName)
{
	dataPtr += member->m_offset;
	char* currElemPtr = nullptr;
	int numElem = 0;
	dhkClass* hkClass = nullptr;


	switch (member->m_memberType)
	{
	case dhkClassMember::PTR_IGNORE:
		//HARDCODED SHIT FOR METADATA REMOVAL
		if (!strcmp(holderClass->m_name, "hkVariant") && !strcmp(member->m_name, "class"))
		{
			auto elem = m_classOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_classOffsetMap.end())
			{
				m_offsetsToDelete.push_back(dataPtr - g_dataPtr);
			}
		}
		break;
	case dhkClassMember::PTR_WORD:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{
					*((short*)currElemPtr + i) = _byteswap_ushort(*((short*)currElemPtr + i));
				}
			}
		}
		
		break;
	case dhkClassMember::PTR_DWORD:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{
					*((int*)currElemPtr + i) = _byteswap_ulong(*((int*)currElemPtr + i));
				}
			}
		}
		break;
	case dhkClassMember::PTR_QWORD:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{
					*((long long*)currElemPtr + i) = _byteswap_uint64(*((long long*)currElemPtr + i));
				}
			}
		}
		break;
	case dhkClassMember::PTR_VECTOR4:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						*((int*)currElemPtr + i * 4 + j) = _byteswap_ulong(*((int*)currElemPtr + i * 4 + j));
					}
				}
			}
		}
		break;
	case dhkClassMember::PTR_MATRIX3:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{

					for (int j = 0; j < 12; j++)
					{
						*((int*)currElemPtr + i * 12 + j) = _byteswap_ulong(*((int*)currElemPtr + i * 12 + j));
					}
				}
			}
		}
		break;
	case dhkClassMember::PTR_MATRIX4:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{

					for (int j = 0; j < 16; j++)
					{
						*((int*)currElemPtr + i * 16 + j) = _byteswap_ulong(*((int*)currElemPtr + i * 16 + j));
					}
				}
			}
		}
		break;
	case dhkClassMember::PTR_CLASS:
		if (member->m_isArray)
		{
			auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

			if (elem != m_arrayOffsetMap.end())
			{
				numElem = _byteswap_ulong(*((int*)dataPtr + 1));
				currElemPtr = (*elem).second + (char*)g_dataPtr;

				for (int i = 0; i < numElem; i++)
				{
					if (member->m_className)
					{
						hkClass = getClass(member->m_className);

						if (hkClass)
							parseClass(member->m_className, currElemPtr + i * hkClass->m_alignedObjectSize, classSubType, subClassName);
					}
				}
			}
		}
		break;
	case dhkClassMember::PTR_GENERIC:
		if (classSubType != dhkClassMember::PTR_IGNORE)
			parseGenericArray(holderClass, member, dataPtr, classSubType, subClassName);
		
		break;
	case dhkClassMember::PTR_HOMOGENEOUS:
		{
			//find class to get classname for data
			auto elem = m_classOffsetMap.find(dataPtr - g_dataPtr - 4);

			if (elem != m_classOffsetMap.end())
			{
				//find offset to name string
				elem = m_arrayOffsetMap.find((*elem).second);

				if (elem != m_arrayOffsetMap.end())
				{
					const char* klassName = g_dataPtr + (*elem).second;

					//find offset to array
					elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

					if (elem != m_arrayOffsetMap.end())
					{
						numElem = _byteswap_ulong(*((int*)dataPtr + 1));
						currElemPtr = (*elem).second + (char*)g_dataPtr;

						for (int i = 0; i < numElem; i++)
						{
							hkClass = getClass(klassName);

							if (hkClass)
								parseClass(klassName, currElemPtr + i * hkClass->m_alignedObjectSize);
						}
					}
				}
			} 
			else {
				elem = m_classOffsetMap.find(dataPtr - g_dataPtr + 8);

				if (elem != m_classOffsetMap.end()) {

					const dhkVertexFormat* format = (const dhkVertexFormat*)(g_dataPtr + (*elem).second);
					elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);
					
					if (elem != m_arrayOffsetMap.end()) {

						numElem = _byteswap_ulong(*((int*)dataPtr + 1));
						currElemPtr = (*elem).second + (char*)g_dataPtr;

						for (int i = 0; i < numElem; i++) {

							if (format->positionOffset > -1)
							{
								for (int j = 0; j < 4; j++)
								{
									*(int*)(currElemPtr + format->positionOffset + j * 4) = _byteswap_ulong(*(int*)(currElemPtr + format->positionOffset + j * 4));
								}
							}

							if (format->normalOffset > -1)
							{
								for (int j = 0; j < 4; j++)
								{
									*(int*)(currElemPtr + format->normalOffset + j * 4) = _byteswap_ulong(*(int*)(currElemPtr + format->normalOffset + j * 4));
								}
							}

							if (format->tangentOffset > -1)
							{
								for (int j = 0; j < 4; j++)
								{
									*(int*)(currElemPtr + format->tangentOffset + j * 4) = _byteswap_ulong(*(int*)(currElemPtr + format->tangentOffset + j * 4));
								}
							}

							if (format->binormalOffset > -1)
							{
								for (int j = 0; j < 4; j++)
								{
									*(int*)(currElemPtr + format->binormalOffset + j * 4) = _byteswap_ulong(*(int*)(currElemPtr + format->binormalOffset + j * 4));
								}
							}

							if (format->tFloatCoordOffset > -1)
							{
								for (int j = 0; j < format->numTextureChannels; j++)
								{
									*(int*)(currElemPtr + format->tFloatCoordOffset + j * 4) = _byteswap_ulong(*(int*)(currElemPtr + format->tFloatCoordOffset + j * 4));
								}
							}

							if (format->tQuantizedCoordOffset > -1) {

								for (int j = 0; j < format->numTextureChannels; j++) {
									*(short*)(currElemPtr + format->tQuantizedCoordOffset + j * 4) = _byteswap_ushort(*(short*)(currElemPtr + format->tQuantizedCoordOffset + j * 4));
									*(short*)(currElemPtr + format->tQuantizedCoordOffset + j * 4 + 2) = _byteswap_ushort(*(short*)(currElemPtr + format->tQuantizedCoordOffset + j * 4 + 2));
								}
							}

							currElemPtr += format->striding;
						}
					}
				}
			}
		}
		break;
	case dhkClassMember::BYTE:
		break;
	case dhkClassMember::WORD:
		*(short*)dataPtr = _byteswap_ushort(*(short*)dataPtr);
		break;
	case dhkClassMember::DWORD:
		*(int*)dataPtr = _byteswap_ulong(*(int*)dataPtr);
		break;
	case dhkClassMember::QWORD:
		*(long long*)dataPtr = _byteswap_uint64(*(long long*)dataPtr);
		break;
	case dhkClassMember::VECTOR4:
		for (int i = 0; i < 4; i++)
		{
			*((int*)dataPtr + i) = _byteswap_ulong(*((int*)dataPtr + i));
		}
		break;
	case dhkClassMember::MATRIX3:
		for (int i = 0; i < 12; i++)
		{
			*((int*)dataPtr + i) = _byteswap_ulong(*((int*)dataPtr + i));
		}
		break;
	case dhkClassMember::MATRIX4:
		for (int i = 0; i < 16; i++)
		{
			*((int*)dataPtr + i) = _byteswap_ulong(*((int*)dataPtr + i));
		}
		break;
	case dhkClassMember::CLASS:
		parseClass(member->m_className, dataPtr, member->m_subType, member->m_subTypeName);
		break;
	default:
		break;
	}


}

void dhkClassParser::parseGenericArray(const dhkClass* holderClass, const dhkClassMember* member, char* dataPtr, dhkClassMember::MEMBER_TYPE classSubType, const char* classSubName)
{
	int numElem = 0;
	char* currElemPtr = nullptr;
	auto elem = m_arrayOffsetMap.find(dataPtr - g_dataPtr);

	dhkClass* hkClass = nullptr;

	if (classSubName)
	 hkClass = getClass(classSubName);

	if (elem != m_arrayOffsetMap.end())
	{
		if (!strcmp(holderClass->m_name, "hkSmallArray"))
		{
			numElem = (int)_byteswap_ushort(*((short*)dataPtr + 2));
		}
		else 
		{
			numElem = _byteswap_ulong(*((int*)dataPtr + 1));
		}
		
		currElemPtr = (*elem).second + (char*)g_dataPtr;

		for (int i = 0; i < numElem; i++)
		{
			switch (classSubType)
			{
			case dhkClassMember::WORD:
				*((short*)currElemPtr + i) = _byteswap_ushort(*((short*)currElemPtr + i));
				break;
			case dhkClassMember::DWORD:
				*((int*)currElemPtr + i) = _byteswap_ulong(*((int*)currElemPtr + i));
				break;
			case dhkClassMember::QWORD:
				*((long long*)currElemPtr + i) = _byteswap_uint64(*((long long*)currElemPtr + i));
				break;
			case dhkClassMember::VECTOR4:
				for (int j = 0; j < 4; j++)
				{
					*((int*)currElemPtr + j + i * 4) = _byteswap_ulong(*((int*)currElemPtr + j + i * 4));
				}
				break;
			case dhkClassMember::MATRIX3:
				for (int j = 0; j < 12; j++)
				{
					*((int*)currElemPtr + j + i * 12) = _byteswap_ulong(*((int*)currElemPtr + j + i * 12));
				}
				break;
			case dhkClassMember::MATRIX4:
				for (int j = 0; j < 16; j++)
				{
					*((int*)currElemPtr + j + i * 16) = _byteswap_ulong(*((int*)currElemPtr + j + i * 16));
				}
				break;
			case dhkClassMember::CLASS:
				if (hkClass)
					parseClass(classSubName, currElemPtr + i * hkClass->m_alignedObjectSize, dhkClassMember::PTR_IGNORE);
				break;
			default:
				break;
			}
		}
	}


	
}

void dhkClassParser::removeMetadataOffsets(char* contents, int* dataOffsets)
{
}

vector<int>* dhkClassParser::getOffsetsToDelete()
{
	return &m_offsetsToDelete;
}

dhkClass* dhkClassParser::getClass(const char* className) {
	if (m_currFileHavokVersion == dhkClass::OTHER) {
		return 0;
	} else if (m_currFileHavokVersion == dhkClass::HK410) {
		return m_classLibrary410->getClass(className);
	} else if (m_currFileHavokVersion == dhkClass::HK450) {
		return m_classLibrary450->getClass(className);
	} else if (m_currFileHavokVersion == dhkClass::HK510) {
		return m_classLibrary510->getClass(className);
	} else if (m_currFileHavokVersion == dhkClass::HK550) {
		return m_classLibrary550->getClass(className);
	} else {
		return 0;
	}
}