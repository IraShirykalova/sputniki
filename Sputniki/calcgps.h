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
	float EkstrAnom(float E0, float e);	//����. ��������
	float IstAnom(float Ek, float e0);	//�������� ��������  

	float GradtoRad(float X); //������ �����.� ������
	float Vidimost(float Xsi, float Ysi, float Zsi); //������ ���������
	void calcSattelite(ParametryGPS &sattelite); //��������� ��������
	void GeoXYZ(float B, float L, float H); //�����.����� �� �����
	int calcNumberSattelites(float B, float L, float H, vector<ParametryGPS> &sattelite, vector<ParametryGPS> &vidimye);
	void calcT(int h, int m);
	vector<ParametryGPS> satteliteT(int h, int m, vector<ParametryGPS> satt);

private:
	float	 B, L, H,X1,Y1,Z1, deltaT;;
	float	 BPL = 6378136; //������� �������
	float	 sg = 1 / 298.25784;//������ ���������
	float	 C = -4.442807633 * 10e-10; // �/�(1/2)
	float	 c = 2.99792458*10e+8; // �/� �������� �����
	float	 mu = 3.986005*10e+10;// m^3 c^-2 ��������.�������������� ����������
	float	 omegaZ = 7.2921151467*10e-5;//������� �������� �������� �����
	float	 X, Y, Z, Mk,Fk,Ek,T;
};

