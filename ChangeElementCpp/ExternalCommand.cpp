#include "pch.h"

#include "ExternalCommand.h"
#include "WindowHandler.h"
#include "MainForm.h"
#include "EventHandler.h"
#include "GlobalVariables.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::Reflection;
using namespace System::ComponentModel;
using namespace System::Globalization;
using namespace System::Resources;
using namespace System::Threading;

using namespace Autodesk::Revit;
using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI;

namespace ChangeElementCpp
{
	Result ExtCmd::Execute(ExternalCommandData^ commandData, String^% message, Autodesk::Revit::DB::ElementSet^ elements)
	{	
		//	To handle main Revit window.
		if (nullptr == ExtCmd::_hWndRevit)
		{
			Process^ process = Process::GetCurrentProcess();

			IntPtr h = process->MainWindowHandle;
			ExtCmd::_hWndRevit = gcnew WindowHandle(h);
		}

		try
		{
			// A new handler to handle request posting by the dialog
			iexeventhandler^ handler = gcnew iexeventhandler();

			// External Event for the dialog to use (to post requests)
			ExternalEvent^ exEvent = ExternalEvent::Create(handler);
			
			if (mainForm == nullptr || mainForm->IsDisposed)
			{
				// We give the objects to the new dialog;
				// The dialog becomes the owner responsible for disposing them, eventually.
				// process data from Revit and show dialog
				mainForm = gcnew MainForm(commandData, exEvent, handler);
				mainForm->Show(ExtCmd::_hWndRevit);
			}
		}
		catch (Exception^ ex)
		{
			message = ex->Message;
			return Autodesk::Revit::UI::Result::Failed;
		}
		return Autodesk::Revit::UI::Result::Cancelled;
	}
}