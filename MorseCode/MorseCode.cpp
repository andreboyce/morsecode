// MorseCode.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace MorseCode;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	try
	{
	   // Enabling Windows XP visual effects before any controls are created
	   Application::EnableVisualStyles();
	   Application::SetCompatibleTextRenderingDefault(false); 

	   // Create the main window and run it
	   Application::Run(gcnew Form1());
	   return 0;
	}
	catch( System::Exception^ e )
	{
	   MessageBox::Show( e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
	   return -1;
    }

}
