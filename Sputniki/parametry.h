#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#using <System.dll>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ios_base;
using std::cout;

using namespace System;

struct Parametry
{
	int hours;
	int minutes;
	int number;
	double X;
	double Y;
	double Z;
	double Vx;
	double Vy;
	double Vz;
	double Ax;
	double Ay;
	double Az;
};


ref class parametry
{
public:
	static double stringToDouble(const string &str);
	static int stringToInt(const string &str);
	parametry();
	static void SummaChasov(int &hours,int &mins,const int kolvoH,const int kolvoM);

	static void MarshalString(String ^ s, string& os);

	static bool replace(std::string& str, const std::string& from, const std::string& to);
};

