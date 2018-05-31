#pragma once
#include "filereader.h"
#include "parametryGPS.h"
#include "parametry.h"
#using <System.dll>

ref class filereaderGPS
{
public:
	filereaderGPS();

public:
	static vector<ParametryGPS> readfile(const string &filename);
};

