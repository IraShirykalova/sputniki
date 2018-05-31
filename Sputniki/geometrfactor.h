#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#using <System.dll>
#include "parametry.h"
# define M_PI 3.14159265358979323846  /* pi */

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ios_base;
using std::cout;

using namespace System;
ref class Geometrfactor
{
public:
	Geometrfactor(double x, double y, double z,double b,double l);
	

private:
	double X, Y, Z;
	double B, L, H, Bz, Lz;	
	double altitude, azimuth;
	void GeocGeodez();
	void calculateAE();

	double R0 = 6370;
};

