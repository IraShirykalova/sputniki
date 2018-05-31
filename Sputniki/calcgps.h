#pragma once
#include <math.h>
#include <cmath>
#include "parametryGPS.h"
#include "parametry.h"
#include <ctime>

ref class calcgps
{
public:
	calcgps();
	
public:
	float EkstrAnom(float E0, float e);	//эксц. аномалия
	float IstAnom(float Ek, float e0);	//истинная аномалия  

	float GradtoRad(float X); //превод коорд.в радиус
	float Vidimost(float Xsi, float Ysi, float Zsi); //расчёт видимости
	void calcSattelite(ParametryGPS &sattelite); //параметры спутника
	void GeoXYZ(float B, float L, float H); //коорд.точки на Земле
	int calcNumberSattelites(float B, float L, float H, vector<ParametryGPS> &sattelite, vector<ParametryGPS> &vidimye);
	void calcT(int h, int m);
	vector<ParametryGPS> satteliteT(int h, int m, vector<ParametryGPS> satt);

private:
	float	 B, L, H,X1,Y1,Z1, deltaT;;
	float	 BPL = 6378136; //большая полуось
	float	 sg = 1 / 298.25784;//сжатие элипсойда
	float	 C = -4.442807633 * 10e-10; // с/м(1/2)
	float	 c = 2.99792458*10e+8; // м/с скорость света
	float	 mu = 3.986005*10e+10;// m^3 c^-2 геоцентр.гравитационная постоянная
	float	 omegaZ = 7.2921151467*10e-5;//угловая скорость вращения Земли
	float	 X, Y, Z, Mk,Fk,Ek,T;
};

