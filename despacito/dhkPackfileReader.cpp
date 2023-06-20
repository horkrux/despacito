#include "dhkPackfileReader.h"


dhkPackfileReader::dhkPackfileReader()
{
	printf("Init class libraries...\n");
	m_parser = new dhkClassParser();
	printf("Finished loading class libraries\n");
}

dhkPackfileReader::~dhkPackfileReader()
{
	if (m_parser) {
		delete m_parser;
		m_parser = 0;
	}
}

dhkPackfileReader::PACKFILE_STATUS dhkPackfileReader::loadPackfile(wstring path)
{
	m_packfile = ifstream(path, ios::in | ios::binary | ios::ate);

	if (m_packfile)
	{
		size_t len_packfile = m_packfile.tellg();
		m_packfileContents = vector<char>(len_packfile);

		m_packfile.seekg(0, ios::beg);
		m_packfile.read(&m_packfileContents[0], len_packfile);
		m_packfile.close();

		char* packfileContents = m_packfileContents.data();

		int dataOffsetsIdx = _byteswap_ulong(*(int*)(packfileContents + 0x18));

		m_classNameOffsets = (int*)(packfileContents + 0x54);

		if (dataOffsetsIdx == 1)
		{
			m_dataOffsets = (int*)(packfileContents + 0x84);
			m_typeOffsets = (int*)(packfileContents + 0xB4);
		} 
		else
		{
			m_typeOffsets = (int*)(packfileContents + 0x84);
			m_dataOffsets = (int*)(packfileContents + 0xB4);
		}

		char* havokVersion = packfileContents + 0x28;
		
		if (!strcmp(havokVersion, "Havok-5.5.0-r1"))
		{
			m_havokVersion = dhkClass::HK550;
		} 
		else if (!strcmp(havokVersion, "Havok-5.1.0-r1"))
		{
			m_havokVersion = dhkClass::HK510;
		}
		else if (!strcmp(havokVersion, "Havok-4.5.0-r1"))
		{
			m_havokVersion = dhkClass::HK450;
		}
		else if (!strcmp(havokVersion, "Havok-4.1.0-r1"))
		{
			m_havokVersion = dhkClass::HK410;
		}
		else
		{
			m_havokVersion = dhkClass::OTHER;
			return FILEERR;
		}

		PACKFILE_STATUS retVal = OK;

		if (m_havokVersion != dhkClass::OTHER)
		{
			retVal = fixPackfileOffsets();
			fixHeader();
			fixClassNameSection();

			if (m_typeOffsets[1])
				removeTypeInfo();
		}

		return retVal;
	}

	return FILEERR;
}

dhkPackfileReader::PACKFILE_STATUS dhkPackfileReader::fixPackfileOffsets()
{
	char* packfileContents = m_packfileContents.data();

	for (int i = 0; i < 7; i++)
	{
		m_classNameOffsets[i] = _byteswap_ulong(m_classNameOffsets[i]);
		m_typeOffsets[i] = _byteswap_ulong(m_typeOffsets[i]);
		m_dataOffsets[i] = _byteswap_ulong(m_dataOffsets[i]);
	}

	char* dataOffsetArraySection = packfileContents + m_dataOffsets[0] + m_dataOffsets[1];
	char* dataOffsetClassSection = packfileContents + m_dataOffsets[0] + m_dataOffsets[2];
	char* dataOffsetClassNameSection = packfileContents + m_dataOffsets[0] + m_dataOffsets[3];

	int* packfileEnd = (int*)(packfileContents + m_packfileContents.size());

	int* sectionPtr = (int*)dataOffsetArraySection;

	if (dataOffsetArraySection == dataOffsetClassSection && dataOffsetArraySection == dataOffsetClassNameSection)
	{
		do
		{
			if (*sectionPtr == -1)
				break;

			*sectionPtr = _byteswap_ulong(*sectionPtr);
			*(sectionPtr + 1) = _byteswap_ulong(*(sectionPtr + 1));
			*(sectionPtr + 2) = _byteswap_ulong(*(sectionPtr + 2));
			sectionPtr += 3;
		} while (sectionPtr < packfileEnd);

		return EMPTY;
	}
	

	do 
	{
		if (*sectionPtr == -1)
			break;

		*sectionPtr = _byteswap_ulong(*sectionPtr);
		*(sectionPtr + 1) = _byteswap_ulong(*(sectionPtr + 1));
		sectionPtr += 2;
	} while (sectionPtr < (int*)dataOffsetClassSection);

	sectionPtr = (int*)dataOffsetClassSection;

	do
	{
		if (*sectionPtr == -1)
			break;

		*sectionPtr = _byteswap_ulong(*sectionPtr);
		*(sectionPtr + 1) = _byteswap_ulong(*(sectionPtr + 1));
		*(sectionPtr + 2) = _byteswap_ulong(*(sectionPtr + 2));
		sectionPtr += 3;
	} while (sectionPtr < (int*)dataOffsetClassNameSection);

	sectionPtr = (int*)dataOffsetClassNameSection;

	do
	{
		if (*sectionPtr == -1)
			break;

		*sectionPtr = _byteswap_ulong(*sectionPtr);
		*(sectionPtr + 1) = _byteswap_ulong(*(sectionPtr + 1));
		*(sectionPtr + 2) = _byteswap_ulong(*(sectionPtr + 2));
		sectionPtr += 3;
	} while (sectionPtr < packfileEnd);

	return OK;
}

void dhkPackfileReader::fixHeader()
{
	char* contents = m_packfileContents.data();

	*(int*)(contents + 8) = _byteswap_ulong(*(int*)(contents + 8));
	*(int*)(contents + 12) = _byteswap_ulong(*(int*)(contents + 12));
	*(contents + 17) = 1;
	*(contents + 18) = 0;
	*(int*)(contents + 20) = _byteswap_ulong(*(int*)(contents + 20));
	*(int*)(contents + 24) = _byteswap_ulong(*(int*)(contents + 24));
	*(int*)(contents + 28) = _byteswap_ulong(*(int*)(contents + 28));
	*(int*)(contents + 32) = _byteswap_ulong(*(int*)(contents + 32));
	*(int*)(contents + 36) = _byteswap_ulong(*(int*)(contents + 36));
	//rip if padding optimization actually matters even once
}

void dhkPackfileReader::fixClassNameSection()
{
	char* classNamePtr = m_packfileContents.data() + m_classNameOffsets[0];
	char* classNamesEnd = classNamePtr + m_classNameOffsets[1];

	do
	{
		if (*(int*)classNamePtr == -1)
			break;

		*(int*)classNamePtr = _byteswap_ulong(*(int*)classNamePtr);

		classNamePtr+=5;

		while (*classNamePtr++);


	} while (classNamePtr < classNamesEnd - 4);
}

void dhkPackfileReader::fixDataSection()
{
	if (!m_parser) {
		printf("Parser not initialized\n");
		return;
	}

	m_parser->parseAndFixData(m_packfileContents.data(), m_dataOffsets, (char*)m_packfileContents.data() + m_classNameOffsets[0], m_havokVersion);
	vector<int>* offsetsToDelete = m_parser->getOffsetsToDelete();
	vector<int> actualOffsetsToDelete;

	char* contents = m_packfileContents.data();

	int* classPtrOffsets = (int*)(contents + m_dataOffsets[0] + m_dataOffsets[2]);

	for (int i = 0; i < offsetsToDelete->size(); i++)
	{

		int offset = (*offsetsToDelete)[i];

		//haha this goes on forever if something's wrong
		while (*classPtrOffsets != offset) classPtrOffsets += 3;

		actualOffsetsToDelete.push_back((int)((char*)classPtrOffsets - contents));
	}

	for (int i = 0; i < actualOffsetsToDelete.size(); i++)
	{
		m_packfileContents.erase(m_packfileContents.begin() + actualOffsetsToDelete[i] - i * 12, m_packfileContents.begin() + actualOffsetsToDelete[i] + 12 - i * 12); //WHAT IS THIS HORSESHIT
	}

	classPtrOffsets = (int*)(contents + m_dataOffsets[0] + m_dataOffsets[3] - actualOffsetsToDelete.size() * 12);

	if (actualOffsetsToDelete.size())
		m_packfileContents.insert(m_packfileContents.begin() + (int)((char*)classPtrOffsets - contents), 12 * actualOffsetsToDelete.size(), 0xFF);

}

void dhkPackfileReader::writeFixedPackfile(wstring path)
{
	if (path.length() > 4) {
		path.insert(path.length()-4, L"test");
	} else {
		path.append(L"test.hkx");
	}
	ofstream out = ofstream(path, ios::out | ios::binary | ios::ate);
	out.write(m_packfileContents.data(), m_packfileContents.size());
	out.close();
}

void dhkPackfileReader::removeTypeInfo()
{
	m_packfileContents.erase(m_packfileContents.begin() + m_typeOffsets[0], m_packfileContents.begin() + m_typeOffsets[0] + m_typeOffsets[4]);

	int numRemoved = m_dataOffsets[0] - m_typeOffsets[0];

	if (m_havokVersion == dhkClass::HK550)
		m_dataOffsets[0] -= numRemoved;

	for (int i = 1; i < 7; i++)
	{
		m_typeOffsets[i] = 0;
	}
}

char* dhkPackfileReader::getPackfileContents()
{
	return m_packfileContents.data();
}

int dhkPackfileReader::getPackfileSize()
{
	return m_packfileContents.size();
}