#include "filereaderGPS.h"



filereaderGPS::filereaderGPS()
{
}

void splitStringCoordGPS(const string &fullstr,
	vector<string> &elements);

void splitStringTimeGPS(const string &fullstr,
	vector<string> &elements);

void zapisParametrovGPS(vector<string> elements, vector<ParametryGPS> &bulion);

void splitStringCoordGPS(const string &fullstr,vector<string> &elements)
{
	string fullstr_mode = string(fullstr);
	parametry::replace(fullstr_mode, string("D"), string("E"));
	parametry::replace(fullstr_mode, string("D"), string("E"));
	parametry::replace(fullstr_mode, string("D"), string("E"));
	parametry::replace(fullstr_mode, string("D"), string("E"));
	elements.push_back(fullstr_mode.substr(3, 19));
	elements.push_back(fullstr_mode.substr(22, 19));
	elements.push_back(fullstr_mode.substr(41, 19));
	elements.push_back(fullstr_mode.substr(60, 19));
}


void splitStringTimeGPS(const string &fullstr,
	vector<string> &elements)
{
	elements.push_back(fullstr.substr(0, 2));
	elements.push_back(fullstr.substr(12, 2));
	elements.push_back(fullstr.substr(15, 2));
}

vector<ParametryGPS> filereaderGPS::readfile(const string &filename)
{
	vector<ParametryGPS> bulion;
	string buff;
	vector<string> selements;

	ifstream fin(filename);
	int i = 0;
	int j = 0;
	bool time = true;
	while (!fin.eof())
	{
		i++;
		getline(fin, buff);
		if (i < 9)
		{
			continue;
		}
		if (!buff.empty())
		{
			if (time)
			{
				time = false;
				splitStringTimeGPS(buff, selements);
			}
			else {
				if (j > 4)
				{
					j++;
					
				}
				else 
				{
					splitStringCoordGPS(buff, selements);
					j++;
				}
				
				
			}
			if (j == 7)
			{
				time = true;
				j = 0;
			}

		}
	}
	zapisParametrovGPS(selements, bulion);
	return bulion;
}

void zapisParametrovGPS(vector<string> elements, vector<ParametryGPS> &bulion)
{
	int allCount = elements.size();
	int n = 23;
	int rows = round(allCount / n);
	ParametryGPS sattelite;
	for (int i = 0; i < rows; i++)
	{

		//1
		sattelite.Crs = parametry::stringToDouble(elements[i*n + 4]);
		sattelite.delnaN = parametry::stringToDouble(elements[i*n + 5]);
		//2
		sattelite.Cuc = parametry::stringToDouble(elements[i*n + 7]);
		sattelite.e = parametry::stringToDouble(elements[i*n + 8]);
		sattelite.Cus = parametry::stringToDouble(elements[i*n + 9]);
		sattelite.sqrtA = parametry::stringToDouble(elements[i*n + 10]);

		//3
		sattelite.Toe = parametry::stringToDouble(elements[i*n + 11]);
		sattelite.Cic = parametry::stringToDouble(elements[i*n + 12]);
		sattelite.OMEGA = parametry::stringToDouble(elements[i*n + 13]);
		sattelite.Cis = parametry::stringToDouble(elements[i*n + 14]);

		//4
		sattelite.i0 = parametry::stringToDouble(elements[i*n + 15]);
		sattelite.Crc = parametry::stringToDouble(elements[i*n + 16]);
		sattelite.omega = parametry::stringToDouble(elements[i*n + 17]);
		sattelite.OMEGADOt = parametry::stringToDouble(elements[i*n + 18]);

		//5
		sattelite.IDOT = parametry::stringToInt(elements[i*n + 19]);

		sattelite.number = parametry::stringToInt(elements[i*n]);
		sattelite.hours = parametry::stringToInt(elements[i*n + 1]);
		sattelite.minutes = parametry::stringToDouble(elements[i*n + 2]);



		bulion.push_back(sattelite);
	}
}