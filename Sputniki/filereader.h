#pragma once
#include "filereader.h"
#include "parametry.h"
#using <System.dll>


using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::IO::Compression;
ref class filereader
{
public:
	filereader();
public: 
	static vector<Parametry> readfile(const string &filename);

	static void copyFile(const string &filename_old, const string &filename_new);

	static void writefile(const string &filename, const string &text);

	/*static vector<Parametry> readfile__old(const string &filename,
		const string &csvdelimiter,const int n);*/
};

