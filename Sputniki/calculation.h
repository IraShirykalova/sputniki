#pragma once
#include "parametry.h"

ref class calculation
{
public:
	calculation();
public:
	static vector<Parametry> calculation::SatteliteH(int h, int m, vector<Parametry> satt);

	static vector<Parametry> calculation::SatteliteM(int m, vector<Parametry> satt);

	vector<Parametry> calculation::SatteliteHM(int h, int m, vector<Parametry> satt);


	/* functions*/
	static float rCalc(float x, float y, float z);
	float DvxCalc(float x0, float y0, float z0, float Ax0, float Vy0) ;
	float DvyCalc(float x0, float y0, float z0, float Ay0, float Vx0);
	float DvzCalc(float x0, float y0, float z0, float Az0);

	float VxCalc(float x0, float y0, float z0, float Vy0, float Ax0, float Vx0);
	float VyCalc(float x0, float y0, float z0, float Vx0, float Ay0, float Vy0);
	float VzCalc(float x0, float y0, float z0, float Az0, float Vz0);

	void Calc(float x0, float y0, float z0, float Vx0, float Vy0, float Vz0, float Ax0, float Ay0, float Az0);

	float Vidimost(float Xsi, float Ysi, float Zsi);

	float GradtoRad(float X);

	void GeoXYZ(float B, float L, float H);

	int calcNumberSattelites(float B, float L, float H, vector<Parametry> sattelite, vector<Parametry> &vidimye);

private:
	/*parameters*/
	float GravPar = 398600.448;
	float Ae = 6378.136;
	float J = 1082625.75*0.00000001;
	float w = 7.292115*0.00001;
	float BPL = 6378136; //большая полуось
	float sg = 1 / 298.25784;//сжатие элипсойда
	float Xs, Ys, Zs, Radiosa,Vxs,Vys,Vzs;
	float L, x, y, X1, Y1, Z1, H;
	float deltaT;
};


