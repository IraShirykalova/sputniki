#pragma once
#using <System.dll>
#include <iostream>

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
ref class ftp
{
public:
	ftp(String^ type);
	void download();
	void currentAddress(String^ type);
	void generateFileName(String^ type);
	String^ getFileName();
	void publicDecompress();
private:
	String^	address= "ftp://cddis.gsfc.nasa.gov/gnss/data/daily/";
	String^ filename;
	String ^ addressgps = "ftp://cddis.gsfc.nasa.gov/gps/data/daily/";
	

};



