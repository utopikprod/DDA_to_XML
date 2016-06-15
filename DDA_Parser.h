/*
DDAToXML Converter - Copyright (c) 2016 Matthieu Dirrenberger

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

This program idea is mainly based on the work done by Andrew Allan in 2009.
The white paper he wrote and the code he gave me was really helpfull for speedup
the reverse engineering part (http://www.ducati.ms/).

This software XML parser/writer is based on pugixml library (http://pugixml.org).
pugixml is Copyright (C) 2006-2015 Arseny Kapoulkine.
*/

#include "DDA_FileFormat.h"

using namespace std;

#define DEBUG_ON 1
#define BYTE_SIZE 8
#define BUFFER_SIZE 16

class CDDAParser{

public:

	CDDAParser::CDDAParser() :m_seekPos(0), m_fileSize(0){}
	CDDAParser::~CDDAParser(){}

	void ParseFile(const char* fileName);

private:

	unsigned int GetBytes(ifstream* file, char* buffer, unsigned int size, unsigned int offset = 0);
	void WriteDDAXMLFile(const char* fileName, ifstream* stream);

	SDDADefinition* m_definition;
	unsigned int m_fileSize;
	unsigned int m_seekPos;
};