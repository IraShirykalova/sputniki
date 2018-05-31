
#include "calculation.h"
#include <math.h>
#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846  /* pi */

calculation::calculation()
{
	
}


vector<Parametry> calculation::SatteliteHM(int h, int m, vector<Parametry> satt)
{
	vector<Parametry> vozrv;
	if (m < 15)
	{
		deltaT = m + 15;
		h = h - 1;
		m = 45;
	}
	else if (m >= 15 & m < 45)
	{
		deltaT = m - 15;
		m = 15;
	}
	else
	{
		deltaT = m - 45;
		m = 45;
		
	}
	for (int i = 0;i < satt.size();i++)
	{
		if (satt[i].minutes == m & satt[i].hours == h)
		{
			vozrv.push_back(satt[i]);
		}
	}
	return vozrv;
}

vector<Parametry> calculation::SatteliteH(int h, int m, vector<Parametry> satt)
{
	vector<Parametry> vozrv;
	for (int i = 0;i < satt.size();i++)
	{
		if (satt[i].hours == h)
		{
			vozrv.push_back(satt[i]);
		}
	}
	return vozrv;
}

vector<Parametry> calculation::SatteliteM(int m, vector<Parametry> satt)
{
	vector<Parametry> vozvr;
	int delta15 = Math::Abs(m - 15);
	int delta45 = Math::Abs(m - 25);
	if (delta15 < delta45)
	{
		m = 15;
	}
	else
	{
		m = 45;
	}
	for (int i = 0;i < satt.size();i++)
	{
		if (satt[i].minutes == m)
		{
			vozvr.push_back(satt[i]);
		}
	}
	return vozvr;
}

float calculation::rCalc(float x, float y, float z)
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float calculation::DvxCalc(float x0, float y0, float z0, float Ax0, float Vy0)
{
	float r;
	r= rCalc(x0, y0, z0);
	return (-(GravPar / pow(r,3))*x0) - ((3 / 2 * J*J)*(GravPar*Ae*Ae / pow(r,5)) *x0*(1 - (5 * z0*z0 / (r*r)))) + w * w*x0 + 2 * w*Vy0 + Ax0;
}

float calculation::DvyCalc(float x0, float y0, float z0, float Ay0, float Vx0)
{
	float r;
	r = rCalc(x0, y0, z0);
	return (-(GravPar / pow(r,3))*y0) - (3 / 2 * J*J*(GravPar*Ae*Ae / pow(r,5)) *y0*(1 - (5 * z0*z0 / pow(r,2)))) + w * w*y0 + 2 * w*Vx0 + Ay0;
}

float calculation::DvzCalc(float x0, float y0, float z0, float Az0)
{
	float r;
	r = rCalc(x0, y0, z0);
	return (-(GravPar / pow(r,3))*z0) - (3 / 2 * J*J*(GravPar*Ae*Ae / pow(r,5)) *z0*(1 - (5 * z0*z0 / pow(r,2)))) + Az0;
}

float calculation::VxCalc(float x0, float y0, float z0, float Vy0, float Ax0, float Vx0)
{
	float t, Vx;
	t =  1;
	Vx = Vx0;
	Xs = x0;
	while (t <= 15)
	{
		Vx0 = DvxCalc(x0, y0, z0, Ax0, Vy0);
		Vx = Vx + Vx0 * 60;
		Xs = Xs + Vx * 60;
		t = t + 1;
	}
	return Vx;
}

float calculation::VyCalc(float x0, float y0, float z0, float Vx0, float Ay0, float Vy0)
{
	float t, Vy;
		t = 1;
		Vy = Vy0;
		Ys = y0;
	while (t <= 15)
	{
		Vy0 = DvyCalc(x0, y0, z0, Ay0, Vy0);
		Vy = Vy + Vy0 * 60;
		Ys = Ys + Vy * 60;
		t = t + 1;
	}
	return Vy;
}

float calculation::VzCalc(float x0, float y0, float z0, float Az0, float Vz0)
{
	float t, Vz;
	t = 1;
	Vz = Vz0;
	Zs = z0;
	while (t <= 15)
	{
		Vz0 = DvzCalc(x0, y0, z0, Az0);
		Vz = Vz + Vz0 * 60;
		Zs = Zs + Vz * 60;
		t = t + 1;
	}
	return Vz;
}

void calculation::Calc(float x0, float y0, float z0, float Vx0, float Vy0, float Vz0, float Ax0, float Ay0, float Az0)
{
	float t,Dvx,Dvy,Dvz;
	t = 1;
	Vzs = Vz0;
	Vys = Vy0;
	Vxs = Vx0;

	Dvx = Ax0;
	Dvy = Ay0;
	Dvz = Az0;

	Zs = z0;
	Ys = y0;
	Xs = x0;
	while (t <= deltaT)
	{
		Dvx = DvxCalc(Xs, Ys, Zs, Ax0, Vys);
		Dvy = DvyCalc(Xs, Ys, Zs, Ay0, Vxs);
		Dvz = DvzCalc(Xs, Ys, Zs, Az0);
		Vxs = Vxs + Dvx * 60;
		Vys = Vys + Dvy * 60;
		Vzs = Vzs + Dvz * 60;
		Xs = Xs + Vxs * 60;
		Ys = Ys + Vys * 60;
		Zs = Zs + Vzs * 60;
		t = t + 1;
	}

}



float calculation::GradtoRad(float X)
{
	return M_PI * X / 180;
}

void calculation::GeoXYZ(float B, float L, float H)
{
	float lm, N, e;
	e  = 2 * sg - sg * sg;
	N = BPL / (pow(1 - e * sin(B)*sin(B),2));
	X1 = (N + H)*cos(B)*cos(L) / 1000;
	Y1 = (N + H)*cos(B)*sin(L) / 1000;
	Z1 = ((1 - e * e)*N + H)*sin(B) / 1000;
}

float calculation::Vidimost(float Xsi, float Ysi, float Zsi)
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

int calculation::calcNumberSattelites(float B, float L, float H, vector<Parametry> sattelite, vector<Parametry> &vidimye)
{
	double VxDu;
	double VyDu;
	double VzDu;
	double cosinus;
	int kolvo=0;
	this->GeoXYZ(B, L, H);
	for (int i = 0; i < sattelite.size(); i++)
	{
		/*VxDu = this->VxCalc(sattelite[i].X, sattelite[i].Y, sattelite[i].Z, sattelite[i].Vy, sattelite[i].Ax, sattelite[i].Vx);
		VyDu = this->VyCalc(sattelite[i].X, sattelite[i].Y, sattelite[i].Z, sattelite[i].Vx, sattelite[i].Ay, sattelite[i].Vy);
		VzDu = this->VzCalc(sattelite[i].X, sattelite[i].Y, sattelite[i].Z, sattelite[i].Az, sattelite[i].Vz);
		*/
		this->Calc(sattelite[i].X, sattelite[i].Y, sattelite[i].Z, sattelite[i].Vx, sattelite[i].Vy, sattelite[i].Vz, sattelite[i].Ax, sattelite[i].Ay, sattelite[i].Az);

		cosinus = Vidimost(Xs, Ys, Zs);
		if (cosinus > cos(75 * M_PI / 180))
		{
			kolvo = kolvo + 1;
			vidimye.push_back(sattelite[i]);
		}
	}
	return kolvo;
}