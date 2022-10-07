#pragma once

using namespace System;
using namespace System::Collections::Generic;

using namespace Autodesk::Revit::DB;

namespace ChangeElementCpp
{
	public ref class globalObjects
	{
		public: static String^ labeltext = "labeltext";
		public: static int glb_x = 0;
		public: static List<String^>^ glb_str_list = nullptr;
		public: static System::Collections::Generic::ICollection<ElementId^>^ glb_elid_icoll = nullptr;
		public: static List<String^>^ categoryfilter = gcnew List<String^>();

		public: static List<BuiltInCategory>^ builtInCats =gcnew List<BuiltInCategory>();

		public: static System::Collections::Generic::ICollection<Element^>^ finsfrom = nullptr;
		public: static System::Collections::Generic::ICollection<Element^>^ finsto = nullptr;
		//	And other global objects you want.
	};
	
	public ref struct elmstoreplace
	{
		public: static ElementId^ elmIdFrom = nullptr;	//	Element will be created.
		public: static ElementId^ elmIdTo = nullptr;	//	Element will be replaced.
		public: static int connNoFrom = -1;	//	Connector will be connected.
		public: static int connNoTo = -1;	//	Connedted will ve connected to.

	};
}