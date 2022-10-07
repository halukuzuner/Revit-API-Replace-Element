#pragma once

namespace ChangeElementCpp
{
	using namespace System;

	using namespace Autodesk::Revit::DB;
	using namespace Autodesk::Revit::UI::Selection;

/// <summary>
/// Class definition for filtering element while selecting.
/// </summary>
public ref class pickSelectionFilter : public Autodesk::Revit::UI::Selection::ISelectionFilter
{
	public: virtual bool AllowElement(Element^ element)
	{
		List<BuiltInCategory>^ categories = gcnew List<BuiltInCategory>();
		categories->Add(BuiltInCategory::OST_PipeAccessory);
		categories->Add(BuiltInCategory::OST_PipeFitting);

		if (BuiltInCategory::OST_PipeAccessory == element->Category->BuiltInCategory)
		{
			return true;
		}
		if (BuiltInCategory::OST_PipeFitting ==element->Category->BuiltInCategory)
		{
			return true;
		}
		else
		{
			return false;
		}

		/*if (element->Category->Id->IntegerValue == (int)BuiltInCategory::OST_PipeAccessory)
		{
			return true;
		}
		if (element->Category->Id->IntegerValue == (int)BuiltInCategory::OST_PipeFitting)
		{
		return true;
		}
		return false;*/
	}

	public: virtual bool AllowReference(Reference^ refer, XYZ^ point)
	{
		return false;
	}
};
}