#include "MyForm.h"
#include "filereader.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Sputniki::MyForm form;
	Application::Run(%form);
}
