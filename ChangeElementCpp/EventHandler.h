#pragma once

#include "Request.h"
#include "GlobalVariables.h"

namespace ChangeElementCpp
{
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

using namespace Autodesk::Revit;
using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI;

public ref class iexeventhandler : IExternalEventHandler
{
	// A trivial delegate, but handy
	private: delegate void Operation(UIApplication^ uiapp, elmstoreplace^ elms);

	// The value of the latest request made by the modeless form 
	private: Request^ m_request = gcnew ChangeElementCpp::Request;

	/// <summary>
	/// A public property to access the current request value
	/// </summary>
	public: property Request^ request
	{
		ChangeElementCpp::Request^ get()
		{
			return this->m_request;
		}
	}

	/// <summary>
	///   The top method of the event handler.
	/// </summary>
	/// <remarks>
	///   This is called by Revit after the corresponding
	///   external event was raised (by the modeless form)
	///   and Revit reached the time at which it could call
	///   the event's handler (i.e. this object)
	/// </remarks>
	/// 
	public: virtual void Execute(UIApplication^ uiapp)
	{
		try
		{
			switch (request->Take())
			{
			case RequestId::None:
				{
					return;  // no request at this time -> we can leave immediately
				}
			case RequestId::ReplaceSelected:
				{
					Operation^ opr = gcnew Operation(&iexeventhandler::ReplaceSelected);
					modify(uiapp, "Connect selected instances.", opr);
					break;
				}
			case RequestId::CreateAndConnect:
				{
					Operation^ opr = gcnew Operation(&iexeventhandler::CreateAndConnect);
					modify(uiapp, "Create instance and connect.", opr);
					break;
				}
			case RequestId::CreateAndConnectAll:
			{
				Operation^ opr = gcnew Operation(&iexeventhandler::CreateAndConnectAll);
				modify(uiapp, "Create instance and connect.", opr);
				break;
			}
			default:
				{
					// some kind of a warning here should
					// notify us about an unexpected request 
					break;
				}
			}
		}
		finally
		{
			//application->thisApp->WakeFormUp();
		}
	}

	public: virtual String^ GetName()
	{
		return "External Event Example";
	}

	private: static void modify(UIApplication^ uiapp, String^ text, Operation^ operation)
	{
		// Select some elements in Revit before invoking this command

	// Get the handle of current document.
		UIDocument^ uidoc = uiapp->ActiveUIDocument;

		// Get the element selection of current document.
		Autodesk::Revit::UI::Selection::Selection^ selection = uidoc->Selection;
		System::Collections::Generic::ICollection<ElementId^>^ selectedIds = uidoc->Selection->GetElementIds();
		globalObjects::glb_elid_icoll = selectedIds;
		elmstoreplace^ elms = nullptr;
		elms->elmIdFrom = elmstoreplace::elmIdFrom;
		elms->connNoFrom = elmstoreplace::connNoFrom;
		elms->elmIdTo = elmstoreplace::elmIdTo;
		elms->connNoTo = elmstoreplace::connNoTo;

		try
		{
			Transaction^ trans = gcnew Transaction(uidoc->Document);

			// The name of the transaction was given as an argument

			if (trans->Start(text) == TransactionStatus::Started)
			{
				operation(uiapp, elms);
				trans->Commit();
			}
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("Replace element", ex->Message->ToString());
			//return Result::Failed;
		}	
	}

	/// <summary>
	/// Replaces selected element with element symbol.
	/// </summary>
	/// <param name="uiapp"> : Current uiapp</param>
	/// <param name="elms"> : Struct which contains elements will be processed.</param>
	/// <returns>Nothing returned. Runs tranaction.</returns>
	private: static void ReplaceSelected(UIApplication^ uiapp, elmstoreplace^ elms)
	{
		try
		{
			// Select some elements in Revit before invoking this command

			// Get the handle of current document.
			UIDocument^ uidoc = uiapp->ActiveUIDocument;
			Document^ doc = uidoc->Document;
			
			//	Elelements are stored in other header. They will be read from there.
			//	They are saved there by selecting in GUI.
			Element^ elmfrom = doc->GetElement(elmstoreplace::elmIdFrom);
			Element^ elmto = doc->GetElement(elmstoreplace::elmIdTo);
			Element^ elmtoto = nullptr;	//	Element which elmto connected.

			//	Cast element to family instance then get the family symbol. 
			FamilySymbol^ fsymbol = ((FamilyInstance^)elmfrom)->Symbol;

			// 1. Cast Element to FamilyInstance
			FamilyInstance^ faminstfrom = (FamilyInstance^)elmfrom;
			FamilyInstance^ faminstto = (FamilyInstance^)elmto;

			// 2. Get MEPModel Property
			MEPModel^ mepmodelfrom = faminstfrom->MEPModel;
			MEPModel^ mepmodelto = faminstto->MEPModel;

			// 3. Get connector set of MEPModel
			ConnectorSet^ connectorSetfrom = mepmodelfrom->ConnectorManager->Connectors;
			ConnectorSet^ connectorSetto = mepmodelto->ConnectorManager->Connectors;

			// Connector numbers to be aligned to each other are stored in other file.
			//	They saved there by selecting in GUI.
			Connector^ connFrom =nullptr;	// Connector will be aligned.
			Connector^ connTo = nullptr;	// Connector to be aligned to.
			Connector^ connToTo = nullptr;	// Connector to be aligned and connected to.

			// Get connector by iterating in connectorset. 
			for each (Connector ^ connector in connectorSetfrom)
			{
				if (connector->Id == elmstoreplace::connNoFrom)
				{
					connFrom = connector;
				}
			}
			// Get connector by iterating in connectorset.
			for each (Connector ^ connector in connectorSetto)
			{
				if (connector->Id == elmstoreplace::connNoTo)
				{
					connTo = connector;
					if (connector->AllRefs != nullptr)
					{
						connToTo = GetConnectedConnector(connector);
					}
				}
			}

			// Get the element current location
			LocationPoint^ elmfromLoc = (LocationPoint^)elmfrom->Location;

			// Create vector based on element location and connector location.
			XYZ^ diffvec1 = connFrom->Origin->Subtract(elmfromLoc->Point);
			// Subtract element location which will be moved.
			XYZ^ diffvec2 = connTo->Origin->Subtract(elmfromLoc->Point);

			XYZ^ movementvector = diffvec2->Add(diffvec1->Negate());

			if (movementvector->GetLength() > uiapp->Application->ShortCurveTolerance)
			{
				// Bring two connectors to same point
				ElementTransformUtils::MoveElement(doc, elmfrom->Id, movementvector);
			}

			//	Get BasisZ of connectors.
			XYZ^ basisZTo = connTo->CoordinateSystem->BasisZ;
			XYZ^ basisZFrom = connFrom->CoordinateSystem->BasisZ;

			//	Calculate angle between connectors.
			double angle = basisZTo->AngleTo(basisZFrom);

			if (angle == 0)
			{
				//	Do nothing.
			}
			else if (angle == Math::PI)
			{	//	Rotate 180 degrees.
				//	Create rotation axis.
				Line^ rotationaxis = Line::CreateUnbound(connToTo->Origin, connToTo->CoordinateSystem->BasisY);

				//	Rotate element around axis.
				ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, Math::PI);
			}
			else if ((angle != 0) && (angle != Math::PI))
			{	//	Create crossproduct and rotate element around it.
				//	Calculate crossproduct of two vectors.
				XYZ^ crossprod = basisZTo->CrossProduct(basisZFrom);

				//	Create rotation axis.
				Line^ rotationaxis = Line::CreateBound(connTo->Origin, gcnew XYZ(connTo->Origin->X + crossprod->X, connTo->Origin->Y + crossprod->Y, connTo->Origin->Z + crossprod->Z));

				//	Rotate element around axis.
				ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, 2*Math::PI - angle);
			}
			else
			{
				// Do nothing.
			}

			if (connTo->IsConnected == true)
			{
				connTo->DisconnectFrom(connToTo);
				connFrom->ConnectTo(connToTo);
			}
			uidoc->Document->Delete(elmto->Id);
			//TaskDialog::Show("Revit", "You have selected element: " + elmfrom->Id->ToString());			
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("!!! ", ex->Message->ToString());
			//return Autodesk::Revit::UI::Result::Failed;
		}
	}

	private: static void CreateAndConnect(UIApplication^ uiapp, elmstoreplace^ elms)
	{
		try
		{
			// Select some elements in Revit before invoking this command

			// Get the handle of current document.
			UIDocument^ uidoc = uiapp->ActiveUIDocument;
			Document^ doc = uidoc->Document;

			//	Elelements are stored in other header. They will be read from there.
			//	They are saved there by selecting in GUI.
			Element^ elmfrom = doc->GetElement(elmstoreplace::elmIdFrom);
			Element^ elmto = doc->GetElement(elmstoreplace::elmIdTo);

			//	Cast element to family instance then get the family symbol. 
			FamilySymbol^ fsymbol = ((FamilyInstance^)elmfrom)->Symbol;

			//	Create family instance.
			//	"(LocationPoint^)elmto->Location)->Point" casts location to locaiton point and gets insertion point.
			FamilyInstance^ faminstfrom = doc->Create->NewFamilyInstance(((LocationPoint^)elmto->Location)->Point, fsymbol, Autodesk::Revit::DB::Structure::StructuralType::NonStructural);
			//	We dont need selected element from GUI anymore.
			//	Cast newly created family instance to element.
			elmfrom = (Element^)faminstfrom;

			// 1. Cast Element to FamilyInstance
			FamilyInstance^ faminstto = (FamilyInstance^)elmto;
			//FamilyInstance^ faminstfrom = (FamilyInstance^)elmfrom;

			// 2. Get MEPModel Property
			MEPModel^ mepmodelfrom = faminstfrom->MEPModel;
			MEPModel^ mepmodelto = faminstto->MEPModel;

			// 3. Get connector set of MEPModel
			ConnectorSet^ connectorSetfrom = mepmodelfrom->ConnectorManager->Connectors;
			ConnectorSet^ connectorSetto = mepmodelto->ConnectorManager->Connectors;

			// Connector numbers to be aligned to each other are stored in other file.
			//	They saved there by selecting in GUI.
			Connector^ connFrom = nullptr;	// Connector will be aligned.
			Connector^ connTo = nullptr;	// Connector to be aligned to.
			Connector^ connToTo = nullptr;	// Connector to be aligned and connected to.

			// Get connector by iterating in connectorset. 
			for each (Connector ^ connector in connectorSetfrom)
			{
				if (connector->Id == elmstoreplace::connNoFrom)
				{
					connFrom = connector;
				}
			}

			// Get connector by iterating in connectorset.
			for each (Connector ^ connector in connectorSetto)
			{
				if (connector->Id == elmstoreplace::connNoTo)
				{
					connTo = connector;
					if (connector->AllRefs != nullptr)
					{
						connToTo = GetConnectedConnector(connector);
					}
				}
			}

			// Get the element current location
			LocationPoint^ elmfromLoc = (LocationPoint^)elmfrom->Location;

			// Create vector based on element location and connector location.
			XYZ^ diffvec1 = connFrom->Origin->Subtract(elmfromLoc->Point);
			// Subtract element location which will be moved.
			XYZ^ diffvec2 = connTo->Origin->Subtract(elmfromLoc->Point);

			XYZ^ movementvector = diffvec2->Add(diffvec1->Negate());

			if (movementvector->GetLength() > uiapp->Application->ShortCurveTolerance)
			{
				// Bring two connectors to same point
				ElementTransformUtils::MoveElement(doc, elmfrom->Id, movementvector);
			}

			//	Get BasisZ of connectors.
			XYZ^ basisZTo = connTo->CoordinateSystem->BasisZ;
			XYZ^ basisZFrom = connFrom->CoordinateSystem->BasisZ;

			//	Calculate angle between connectors.
			double angle = basisZTo->AngleTo(basisZFrom);

			if (angle == 0)
			{	
				//	Do nothing.
			}
			else if (angle == Math::PI)
			{	//	Rotate 180 degrees.
				//	Create rotation axis.
				Line^ rotationaxis = Line::CreateUnbound(connTo->Origin, connTo->CoordinateSystem->BasisY);

				//	Rotate element around axis.
				ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, Math::PI);
			}
			else if ((angle != 0) && (angle != Math::PI))
			{	//	Create crossproduct and rotate element around it.
				//	Calculate crossproduct of two vectors.
				XYZ^ crossprod = basisZTo->CrossProduct(basisZFrom);

				//	Create rotation axis.
				Line^ rotationaxis = Line::CreateBound(connTo->Origin, gcnew XYZ(connTo->Origin->X + crossprod->X, connTo->Origin->Y + crossprod->Y, connTo->Origin->Z + crossprod->Z));

				//	Rotate element around axis.
				ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, 2*Math::PI - angle);
			}
			else
			{
				// Do nothing.
			}

			if (connTo->IsConnected == true)
			{
				connTo->DisconnectFrom(connToTo);
				connFrom->ConnectTo(connToTo);
			}
			uidoc->Document->Delete(elmto->Id);
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("!!! ", ex->Message->ToString());
			//return Autodesk::Revit::UI::Result::Failed;
		}
	}

	private: static void CreateAndConnectAll(UIApplication^ uiapp, elmstoreplace^ elms)
	{
		try
		{
			// Select some elements in Revit before invoking this command

			// Get the handle of current document.
			UIDocument^ uidoc = uiapp->ActiveUIDocument;
			Document^ doc = uidoc->Document;

			//	Elelements are stored in other header. They will be read from there.
			//	They are saved there by selecting in GUI.
			Element^ elmfrom = doc->GetElement(elmstoreplace::elmIdFrom);
			Element^ elmto = doc->GetElement(elmstoreplace::elmIdTo);
			
			//	Cast to be created element to family instance then get the family symbol. 
			FamilySymbol^ fsymbol = ((FamilyInstance^)elmfrom)->Symbol;

			//============================================================
			//	Get all elements to be replaced and write them to IColleciton list.
			FilteredElementCollector^ elmToCollector = gcnew FilteredElementCollector(doc);
			elmToCollector = elmToCollector->OfClass(FamilySymbol::typeid);

			// Create a FamilyInstance filter with the FamilySymbol Id
			FamilyInstanceFilter^ elmToFilter = gcnew FamilyInstanceFilter(doc, elmto->GetTypeId());

			// Apply the filter to the elements in the active document
			elmToCollector = gcnew FilteredElementCollector(doc);
			System::Collections::Generic::ICollection<Element^>^ elmToCollection = elmToCollector->WherePasses(elmToFilter)->ToElements();
			
			//============================================================
			
			for each (Element^ elm in elmToCollection)
			{
				//	Create family instance.
				//	"(LocationPoint^)elmto->Location)->Point" casts location to locaiton point and gets insertion point.
				FamilyInstance^ faminstfrom = doc->Create->NewFamilyInstance(((LocationPoint^)elmto->Location)->Point, fsymbol, Autodesk::Revit::DB::Structure::StructuralType::NonStructural);
				//	We dont need selected element from GUI anymore.
				//	Cast newly created family instance to element.
				elmfrom = (Element^)faminstfrom;

				// 1. Cast Element to FamilyInstance
				FamilyInstance^ faminstto = (FamilyInstance^)elm;

				// 2. Get MEPModel Property
				MEPModel^ mepmodelfrom = faminstfrom->MEPModel;
				MEPModel^ mepmodelto = faminstto->MEPModel;

				// 3. Get connector set of MEPModel
				ConnectorSet^ connectorSetfrom = mepmodelfrom->ConnectorManager->Connectors;
				ConnectorSet^ connectorSetto = mepmodelto->ConnectorManager->Connectors;

				// Connector numbers to be aligned to each other are stored in other file.
				//	They saved there by selecting in GUI.
				Connector^ connFrom = nullptr;	// Connector will be aligned.
				Connector^ connTo = nullptr;	// Connector to be aligned to.
				Connector^ connToTo = nullptr;	// Connector to be aligned and connected to.

				// Get connector by iterating in connectorset. 
				for each (Connector ^ connector in connectorSetfrom)
				{
					if (connector->Id == elmstoreplace::connNoFrom)
					{

						connFrom = connector;
						String^ message = "Connector is owned by: " + connector->Owner->Name;

						//TaskDialog::Show("Revit", message);
					}

				}

				// Get connector by iterating in connectorset.
				for each (Connector ^ connector in connectorSetto)
				{
					if (connector->Id == elmstoreplace::connNoTo)
					{
						connTo = connector;
						if (connector->AllRefs != nullptr)
						{
							connToTo = GetConnectedConnector(connector);
						}
					}
				}

				// Get the element current location
				LocationPoint^ elmfromLoc = (LocationPoint^)elmfrom->Location;

				// Create vector based on element location and connector location.
				XYZ^ diffvec1 = connFrom->Origin->Subtract(elmfromLoc->Point);
				// Subtract element location which will be moved.
				XYZ^ diffvec2 = connTo->Origin->Subtract(elmfromLoc->Point);

				XYZ^ movementvector = diffvec2->Add(diffvec1->Negate());

				if (movementvector->GetLength() > uiapp->Application->ShortCurveTolerance)
				{
					// Bring two connectors to same point
					ElementTransformUtils::MoveElement(doc, elmfrom->Id, movementvector);
				}

				//	Get BasisZ of connectors.
				XYZ^ basisZTo = connTo->CoordinateSystem->BasisZ;
				XYZ^ basisZFrom = connFrom->CoordinateSystem->BasisZ;

				//	Calculate angle between connectors.
				double angle = basisZTo->AngleTo(basisZFrom);

				if (angle == 0)
				{	//	Rotate 180 degrees.
					//	Create rotation axis.
					Line^ rotationaxis = Line::CreateUnbound(connTo->Origin, connTo->CoordinateSystem->BasisY);

					//	Rotate element around axis.
					ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, Math::PI);
				}
				else if (angle == Math::PI)
				{
					//	Do nothing.
				}
				else if ((angle != 0) && (angle != Math::PI))
				{	//	Create crossproduct and rotate element around it.
					//	Calculate crossproduct of two vectors.
					XYZ^ crossprod = basisZTo->CrossProduct(basisZFrom);

					//	Create rotation axis.
					Line^ rotationaxis = Line::CreateBound(connTo->Origin, gcnew XYZ(connTo->Origin->X + crossprod->X, connTo->Origin->Y + crossprod->Y, connTo->Origin->Z + crossprod->Z));

					//	Rotate element around axis.
					ElementTransformUtils::RotateElement(doc, elmfrom->Id, rotationaxis, 2*Math::PI - angle);

					/*// This part draws rotation axis and swing path.
					// get handle to application from document
					Autodesk::Revit::ApplicationServices::Application^ application = doc->Application;

					// Create a geometry line in Revit application
					XYZ^ startPoint = connTo->Origin;
					XYZ^ endPoint = gcnew XYZ(connTo->Origin->X + crossprod->X,
						connTo->Origin->Y + crossprod->Y,
						connTo->Origin->Z + crossprod->Z);
					Line^ geomLine = Line::CreateBound(startPoint, endPoint);

					// Create a geometry plane in Revit application
					Plane^ linePlane = Plane::CreateByThreePoints(
						connTo->Origin,
						gcnew XYZ(connTo->Origin->X,
							connTo->Origin->Y,
							connTo->Origin->Z + connTo->CoordinateSystem->BasisZ->Z),
						gcnew XYZ(connTo->Origin->X + crossprod->X,
							connTo->Origin->Y + crossprod->Y,
							connTo->Origin->Z + crossprod->Z));
					Plane^ arcPlane = Plane::CreateByNormalAndOrigin(crossprod->Normalize(), connTo->Origin);
					Arc^ geomArc = Arc::Create(arcPlane, 0.5, 0, angle);

					// Create a sketch plane in current document
					SketchPlane^ linesketch = SketchPlane::Create(doc, linePlane);
					SketchPlane^ arcsketch = SketchPlane::Create(doc, arcPlane);

					// Create a ModelLine element using the created geometry line and sketch plane
					ModelLine^ line = (ModelLine^)doc->Create->NewModelCurve(geomLine, linesketch);

					// Create a ModelArc element using the created geometry arc and sketch plane
					ModelArc^ arc = (ModelArc^)doc->Create->NewModelCurve(geomArc, arcsketch);*/
				}
				else
				{
					// Do nothing.
				}

				if (connTo->IsConnected == true)
				{
					connTo->DisconnectFrom(connToTo);
					connFrom->ConnectTo(connToTo);
				}

				//TaskDialog::Show("Revit", "You have selected element: " + elmfrom->Id->ToString());
			}

			// Delete all the selected elements via the set of element ids.

			//System::Collections::Generic::ICollection<ElementId^>^ oCollection = gcnew List<ElementId^>();

			List<ElementId^>^ elidsToDelete = gcnew List<ElementId^>();
			List<ElementId^>^ supercompidsToDelete = gcnew List<ElementId^>();

			for each (Element ^ elm in elmToCollection)
			{
				//	If element is nested add get its host family.
				if (nullptr != ((FamilyInstance^)elm)->SuperComponent)
				{					
					supercompidsToDelete->Add(((FamilyInstance^)elm)->SuperComponent->Id);
				}
				else
				{
					elidsToDelete->Add(elm->Id);
				}
			}

			uidoc->Document->Delete(elidsToDelete);
			//	We dont delete host families. To delete them, uncomment following line.
			//uidoc->Document->Delete(supercompidsToDelete);
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("Create and replace all. ", ex->Message->ToString());
		}
	}

	/// <summary>
	/// Get the connected connector of one connector
	/// </summary>
	/// <param name="connector">The connector to be analyzed</param>
	/// <returns>The connected connector</returns>
	private: static Connector^ GetConnectedConnector(Connector^ connector)
	{
		Connector^ connectedConnector = nullptr;
		ConnectorSet^ allRefs = connector->AllRefs;
		for each(Connector^ c in allRefs)
		{
			// ignore non-EndConn connectors and connectors of the current element:
			if (ConnectorType::End != c->ConnectorType || c->Owner->Id->Equals(connector->Owner->Id))
			{
				continue;
			}
			connectedConnector = c;
			break;
		}
		return connectedConnector;
	}

};
}
