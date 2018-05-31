#include "calcgps.h"
#define _USE_MATH_DEFINES
# define M_PI 3.14159265358979323846  /* pi */


calcgps::calcgps()
{
}

int calcgps::calcNumberSattelites(float B, float L, float H, vector<ParametryGPS> &sattelite, vector<ParametryGPS> &vidimye)
{
	double cosinus;
	int kolvo = 0;
	float deltaT = 3600;
	this->GeoXYZ(B, L, H);
	for (int i = 0; i < sattelite.size(); i++)
	{
		this->calcSattelite(sattelite[i]);
		cosinus = Vidimost(sattelite[i].X / 1000, sattelite[i].Y / 1000 , sattelite[i].Z / 1000 );
		if (cosinus > cos(75 * M_PI / 180))
		{
			kolvo = kolvo + 1;
			vidimye.push_back(sattelite[i]);
		}
	}
	return kolvo;
	
}

void calcgps::GeoXYZ(float B, float L, float H)
{
	float lm, N, e;
	e = 2 * sg - sg * sg;
	N = BPL / (pow(1 - e * sin(B)*sin(B), 2));
	X1 = (N + H)*cos(B)*cos(L) / 1000;
	Y1 = (N + H)*cos(B)*sin(L) / 1000;
	Z1 = ((1 - e * e)*N + H)*sin(B) / 1000;
}


float calcgps::GradtoRad(float X)
{
	return M_PI * X / 180;
}

float calcgps::Vidimost(float Xsi, float Ysi, float Zsi)
{
	float l1, l, CosAlpha, CosAlphaK, MsX, MsY, MsZ;
	MsX = Xsi - X1;
	MsY = Ysi - Y1;
	MsZ = Zsi - Z1;
	l = sqrt(pow(X1, 2) + pow(Y1, 2) + pow(Z1, 2));
	l1 = sqrt(pow(MsX, 2) + pow(MsY, 2) + pow(MsZ, 2));
	CosAlpha = (X1*MsX + Y1 * MsY + Z1 * MsZ) / (l1*l);
	return CosAlpha;
}

void calcgps::calcSattelite(ParametryGPS &sattelite)
{
	float A = sattelite.sqrtA * sattelite.sqrtA;
	float Tk = T - sattelite.Toe;
	float n0 = sqrt(mu / pow(A, 3));
	float n = n0 + sattelite.delnaN;
	float Mk = sattelite.OMEGA + n * Tk;
	float Ek1 = EkstrAnom( Mk,sattelite.e);
	float Fk = IstAnom(sattelite.e,Mk) + sattelite.omega;
	float TruAnom = IstAnom(sattelite.e, Ek1);
	float ArgShiroty = TruAnom + sattelite.omega;
	float du = sattelite.Cus * sin(2 * Fk) + sattelite.Cuc * cos(2 * Fk);
	float dr = sattelite.Crs * sin(2 * Fk) + sattelite.Crc * cos(2 * Fk);
	float di = sattelite.Cis * sin(2 * Fk) + sattelite.Cic * cos(2 * Fk);
	float Uk = Fk + du;
	float rk = A * (1 - sattelite.e * cos(Ek)) + dr;
	float ik = sattelite.i0 + di + sattelite.IDOT * Tk;
	float Dolgota = sattelite.OMEGA + (sattelite.OMEGADOt - omegaZ)* Tk - omegaZ * sattelite.Toe;
	sattelite.X = rk * (cos(Uk)*cos(Dolgota) - sin(Uk) * sin(Dolgota) * cos(ik));
	sattelite.Y = rk * (cos(Uk)*sin(Dolgota) + sin(Uk) * cos(Dolgota) * cos(ik));
	sattelite.Z = rk * (sin(Uk) * sin(ik));

}


float calcgps::EkstrAnom(float E0, float e)
{

	float E, Ek1 = E0;
	do {
		E = Ek1;
		Ek1 = E0 + e * sin(E);
	} while (abs(Ek1 - E) > 10e-6);
	return Ek1;
}

float calcgps::IstAnom(float e, float E)
{
	float snu = sqrt(1 - e * e) * sin(E) / (1 - e * cos(E));
	float cnu = (cos(E) - e) / (1 - e * cos(E));
	return atan2(snu, cnu);
	
}


void calcgps::calcT(int h, int m)
{

	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	T =( ltm->tm_wday ) * 24 * 3600 + 3600 * h + m * 60;

}

vector<ParametryGPS> calcgps::satteliteT(int h, int m, vector<ParametryGPS> satt)
{
	calcT(h, m);
	vector<ParametryGPS> vozrv;
	float razn = T;

	for (int i = 0;i < satt.size();i++)
	{
		if (satt[i].Toe < T)
		{
			if (T-satt[i].Toe < razn)
			{
				razn = T - satt[i].Toe;
				vozrv.clear();
				vozrv.push_back(satt[i]);
				continue;
			}		
			if (T - satt[i].Toe == razn)
			{
				vozrv.push_back(satt[i]);
			}
		}
	}
	return vozrv;
}