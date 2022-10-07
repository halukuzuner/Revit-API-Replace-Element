#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Resources;
using namespace System::Windows;
using namespace System::Windows::Forms;

using namespace Autodesk::Revit;
using namespace Autodesk::Revit::Attributes;
using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI;

namespace ChangeElementCpp
{
	[Transaction(TransactionMode::Manual)]
	[Regeneration(RegenerationOption::Manual)]
	public ref class ExtApp : IExternalApplication
	{
#pragma region Cached Variables

	public:	static UIControlledApplication^ _cachedUiCtrApp;

#pragma endregion

#pragma region IExternalApplication Members

		  virtual Result OnStartup(UIControlledApplication^ uiApp)
		  {
			  _cachedUiCtrApp = uiApp;
			  try
			  {
				  RibbonPanel^ ribbonPanel = createribbonpanel();

				  //TODO: add you code below->

				  return Result::Succeeded;
			  }
			  catch (Exception^ ex)
			  {
				  MessageBox::Show(ex->ToString());
				  return Result::Failed;
			  }
		  }

		  virtual Result OnShutdown(UIControlledApplication^ uiApp)
		  {
			  try
			  {
				  //TODO: add you code below->

				  return Result::Succeeded;
			  }
			  catch (Exception^ ex)
			  {
				  MessageBox::Show(ex->ToString());
				  return Result::Failed;
			  }
		  }

#pragma endregion

#pragma region Local Methods

	private: RibbonPanel^ createribbonpanel()
		{
			//	"ChangeElement" writes below ribbon.
			RibbonPanel^ panel = _cachedUiCtrApp->CreateRibbonPanel("Change Element");

			////Default button:
			//	"Change\nElement" writes on button.
			PushButtonData^ pbDataExtCmd = gcnew PushButtonData("pbExtCmd", "Change\nElement", Assembly::GetExecutingAssembly()->Location, "ChangeElementCpp.ExtCmd");
			PushButton^ pbExtCmd = static_cast<PushButton^>(panel->AddItem(pbDataExtCmd));
			pbExtCmd->ToolTip = "Starts Change Element External App";
			pbExtCmd->LargeImage = BmpImageSource("ExtCmd32x32");
			pbExtCmd->Image = BmpImageSource("ExtCmd16x16");

			////More buttons:

			return panel;
		}


	private: System::Windows::Media::ImageSource^ BmpImageSource(String^ imagename)
	{
		// Grab the assembly this is being called from
		Assembly^ assembly = Assembly::GetExecutingAssembly();
		AssemblyName^ assemblyName = assembly->GetName();

		// Grab the images from the assembly
		System::Resources::ResourceManager^ rm = gcnew ResourceManager(assemblyName->Name + ".Resource", assembly);
		try
		{
		System::Drawing::Bitmap^ img = (cli::safe_cast<System::Drawing::Bitmap^>(rm->GetObject(imagename)));

		IntPtr hBitmap = img->GetHbitmap();
		return System::Windows::Interop::Imaging::CreateBitmapSourceFromHBitmap(hBitmap, IntPtr::Zero, Int32Rect::Empty, System::Windows::Media::Imaging::BitmapSizeOptions::FromEmptyOptions());
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("!", ex->Message->ToString());
			//return Autodesk::Revit::UI::Result::Failed;
		}


	}

#pragma endregion
	};
}