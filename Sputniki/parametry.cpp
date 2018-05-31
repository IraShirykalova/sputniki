#include "parametry.h"

parametry::parametry()
{
}


double parametry::stringToDouble(const string &str) 
{

	istringstream stm;
	double val = 0;

	stm.str(str);
	stm >> val;

	return val;
}

int parametry::stringToInt(const string &str)
{

	istringstream stm;
	int val = 0;

	stm.str(str);
	stm >> val;

	return val;
}

void parametry::MarshalString(String ^ s, string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

bool parametry::replace(string& str, const string& from, const string& to)
{
	size_t start_pos = str.find(from);
	if (start_pos == string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

void parametry::SummaChasov(int &hours, int &mins, const int kolvoH, const int kolvoM)
{
	int i = 0;
	i = hours + kolvoH;
	if (i >= 24)
	{
		hours = i - 24;
	}
	else hours = i;

	int j = 0;
	j = mins + kolvoM;
	if (j >= 60)
	{
		mins = j - 60;
	}
	else mins = j;
}