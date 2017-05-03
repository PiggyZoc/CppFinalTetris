#include "MyForm.h"
using namespace CppTeris;
[STAThread]
int main(){
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}

