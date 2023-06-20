#pragma once

#include <fstream>
#include <vector>

#include "dhkClassParser.h"

using namespace std;

class dhkPackfileReader
{
public:

	enum PACKFILE_STATUS {
		OK,
		EMPTY,
		FILEERR
	};

	dhkPackfileReader();
	~dhkPackfileReader();
	
	PACKFILE_STATUS loadPackfile(wstring);
	void fixDataSection();
	void writeFixedPackfile(wstring);
	char* getPackfileContents();
	int getPackfileSize();

private:
	PACKFILE_STATUS fixPackfileOffsets();
	void removeTypeInfo();
	void fixHeader();
	void fixClassNameSection();

	ifstream m_packfile;

	int* m_dataOffsets;
	int* m_typeOffsets;
	int* m_classNameOffsets;
	dhkClass::HAVOK_VERSION m_havokVersion;

	dhkClassParser* m_parser;
	vector<char> m_packfileContents;
};

