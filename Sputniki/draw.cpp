#include "draw.h"

static String^ generatestring(double X, double Y, double Z);

draw::draw()
{
}

void draw::generateCoord(string filename, vector<Parametry> sattelites,int colichestvo)
{
	String^ io;
	string mardhal;
	for (int i = 0;i < colichestvo;i++)
	{
		io = generatestring(sattelites[i].X, sattelites[i].Y, sattelites[i].Z);
		parametry::MarshalString(io,mardhal);
		filereader::writefile(filename, mardhal);
	}
	filereader::writefile(filename, "\n endsolid");
};

String^ generatestring(double X, double Y, double Z)
{
	String^ result;
	String^ end;
	String^ facet;
	facet = "\n   facet normal -1.319869e-02 9.999129e-01 1.734698e-04 \n" + "      outer loop \n";
	end = "      endloop \n" + "   endfacet";

	result = facet;
	result = result + "         vertex "+ Convert::ToString(X)->Replace(",",".")+ " " + Convert::ToString(Y)->Replace(",", ".") +" " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X+1000)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y+1000)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + end;

	result = result + facet;
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y+1000)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z+1000)->Replace(",", ".") + "\n";
	result = result + end;

	result = result + facet;
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X+1000)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z)->Replace(",", ".") + "\n";
	result = result + "         vertex " + Convert::ToString(X)->Replace(",", ".") + " " + Convert::ToString(Y)->Replace(",", ".") + " " + Convert::ToString(Z+1000)->Replace(",", ".") + "\n";
	result = result + end;

	return result;
};

void draw::generateCoordGPS(string filename, vector<ParametryGPS> sattelite, int colichestvo)
{
	String^ io;
	string mardhal;
	for (int i = 0;i < colichestvo;i++)
	{
		io = generatestring(sattelite[i].X / 1000, sattelite[i].Y/1000, sattelite[i].Z/1000);
		parametry::MarshalString(io,mardhal);
		filereader::writefile(filename, mardhal);
	}
	filereader::writefile(filename, "\n endsolid");
};