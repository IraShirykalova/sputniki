#include "filereader.h"


void splitStringCoord(const string &fullstr,
	vector<string> &elements);

void splitStringTime(const string &fullstr,
	vector<string> &elements);

void zapisParametrov(vector<string> elements, vector<Parametry> &bulion);
filereader::filereader()
{
}


void filereader::writefile(const string &filename, const string &text)
{
	ofstream fout(filename, ios_base::app);
	fout << text;
	fout.close();
}

void filereader::copyFile(const string &filename_old, const string &filename_new)
{
	std::ifstream  src(filename_old, std::ios::binary);
	std::ofstream  dst(filename_new, std::ios::binary);

	dst << src.rdbuf();
}

vector<Parametry> filereader::readfile(const string &filename)
{
	vector<Parametry> bulion;
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
		if (i < 8) 
		{
			continue;
		}
		if (!buff.empty())
		{
			if (time)
			{
				time = false;
				splitStringTime(buff, selements);
			}
			else {
				splitStringCoord(buff, selements);
				j++;
			}
			if (j == 3) 
			{
				time = true;
				j = 0;
			}
			
		}
	}
	zapisParametrov(selements, bulion);
	return bulion;
}

void splitStringCoord(const string &fullstr,
	vector<string> &elements)
{
	string fullstr_mode = string(fullstr);
	parametry::replace(fullstr_mode, string("D"), string("E"));
	parametry::replace(fullstr_mode, string("D"), string("E"));
	parametry::replace(fullstr_mode, string("D"), string("E"));
	elements.push_back(fullstr_mode.substr(3, 19));
	elements.push_back(fullstr_mode.substr(22, 19));
	elements.push_back(fullstr_mode.substr(41, 19));
}

void splitStringTime(const string &fullstr,
	vector<string> &elements)
{
	elements.push_back(fullstr.substr(0, 2));
	elements.push_back(fullstr.substr(12, 2));
	elements.push_back(fullstr.substr(15, 2));
}

void zapisParametrov(vector<string> elements, vector<Parametry> &bulion)
{
	int allCount = elements.size();
	int n = 12;
	int rows = round(allCount / n);
	Parametry sattelite;
	for (int i = 0; i < rows;i++)
	{
		sattelite.X = parametry::stringToDouble(elements[i*n + 3]);
		sattelite.Y = parametry::stringToDouble(elements[i*n + 6]);
		sattelite.Z = parametry::stringToDouble(elements[i*n + 9]);

		sattelite.Vx = parametry::stringToDouble(elements[i*n + 4]);
		sattelite.Vy = parametry::stringToDouble(elements[i*n + 7]);
		sattelite.Vz = parametry::stringToDouble(elements[i*n + 10]);

		sattelite.Ax = parametry::stringToDouble(elements[i*n + 5]);
		sattelite.Ay = parametry::stringToDouble(elements[i*n + 8]);
		sattelite.Az = parametry::stringToDouble(elements[i*n + 11]);

		sattelite.number = parametry::stringToInt(elements[i*n]);
		sattelite.hours = parametry::stringToInt(elements[i*n + 1]);
		sattelite.minutes = parametry::stringToInt(elements[i*n + 2]);

		//parametry::SummaChasov(sattelite.hours, sattelite.minutes,2,30);

		bulion.push_back(sattelite);
	}
}
