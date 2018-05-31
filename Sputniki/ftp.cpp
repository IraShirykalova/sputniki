#include "ftp.h"
#include <ctime>
#include <vcclr.h>

#define CHUNK_SIZE 4096

ftp::ftp(String^ type)
{

	this->generateFileName(type);
	this->currentAddress(type);
	this->download();
}
void ftp::download()
{
	String^ myStringWebResource = nullptr;
	// Create a new WebClient instance.
	WebClient^ myWebClient = gcnew WebClient;
	// Concatenate the domain with the Web resource filename.
	myStringWebResource = String::Concat(this->address, this->filename + ".Z");
	//Console::WriteLine("Downloading File \"{0}\" from \"{1}\" .......\n\n", fileName, myStringWebResource);
	// Download the Web resource and save it into the current filesystem folder.
	myWebClient->DownloadFile(myStringWebResource, this->filename + ".Z");
	//Console::WriteLine("Successfully Downloaded File \"{0}\" from \"{1}\"", fileName, myStringWebResource);
	//Console::WriteLine("\nDownloaded file saved in the following file system folder:\n\t {0}", Application::StartupPath);
}

void ftp::publicDecompress()
{
	char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi("7z.exe e " + this->filename + ".Z -y");
	system(str2);
}

void ftp::currentAddress(String^ type)
{
	String^ brdc = "brdc";
	String^ year;


	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	year = Convert::ToString(1900 + ltm->tm_year);
	if (type == "GLONASS")
	{
		this->address = this->address + year + "/" + brdc + "/";
	}
	else
	{
		this->address = this->addressgps + year + "/" + brdc + "/";
	}
}

void ftp::generateFileName(String^ type)
{
	String^ wer;
	int fe;

	time_t now = time(0);
	tm *ltm = localtime(&now);

	fe = ltm->tm_yday + 1;
	if (fe > 100)
	{
		wer = Convert::ToString(fe) + "0";

	}
	else
	{
		wer = "0" + Convert::ToString(fe) + "0";
	}

	if (type == "GLONASS")
	{	
	this->filename = "brdc" + wer + "." + Convert::ToString(ltm->tm_year % 100) + "g";
	}
	else
	{
		this->filename = "brdc" + wer + "." + Convert::ToString(ltm->tm_year % 100) + "n";
	}
} 
String^ ftp::getFileName() 
{
	return this->filename;
}

