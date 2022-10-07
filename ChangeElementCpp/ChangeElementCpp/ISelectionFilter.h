#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI::Selection;
	
namespace ChangeElementCpp
{


	public ref class pickSelectionFilter : public Autodesk::Revit::UI::Selection::ISelectionFilter
	{
	public: virtual bool AllowElement(Element^ element)
	{
		if (element->Category->Id->IntegerValue == (int)BuiltInCategory::OST_PipeAccessory)
		{
			return true;
		}
		return false;
	}

	public: virtual bool AllowReference(Reference^ refer, XYZ^ point)
	{
		return false;
	}
	};

}
