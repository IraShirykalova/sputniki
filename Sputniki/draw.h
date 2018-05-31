#pragma once
#include "calculation.h"
#include "parametry.h"
#include "filereader.h"
#include "filereaderGPS.h"
#include "calcgps.h"
#include <math.h>

ref class draw
{
public:
	draw();
	static void generateCoord(string filename, vector<Parametry> sattelites, int colichestvo);
	
	static void generateCoordGPS(string filename, vector<ParametryGPS> sattelite, int colichestvo);
};

