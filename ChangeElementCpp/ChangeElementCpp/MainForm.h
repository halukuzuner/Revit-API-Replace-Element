#pragma once

#include "EventHandler.h"
#include "GlobalVariables.h"
#include"PickSelectionFilter.h"

namespace ChangeElementCpp
{
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Linq;
	using namespace System::Windows;
	using namespace System::Windows::Media; // WindowsBase
	using namespace System::Windows::Media::Imaging; // PresentationCore

	using namespace Autodesk::Revit;
	using namespace Autodesk::Revit::DB;
	using namespace Autodesk::Revit::UI;
	using namespace Autodesk::Revit::UI::Selection;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: ExternalCommandData^ extcmdata;
	private: UIApplication^ uiapp;
	private: UIDocument^ uidoc;
	private: Document^ doc;

	private: ExternalEvent^ m_ExEvent;
	private: iexeventhandler^ m_Handler;
		/// <summary>
		/// A reference to the external command data.
		/// </summary>
	private: ExternalCommandData^ m_commandData;
		   /// <summary>
		   /// The active document
		   /// </summary>
	public: Document^ m_document;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnSelect1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ lbl_familyinfo1;
	private: System::Windows::Forms::Label^ lbl_familyinfo2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ labelCreateFrom;
	private: System::Windows::Forms::Button^ btnSelect2;
	private: System::Windows::Forms::Button^ btnCreateAndConnect;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Domain;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1SystemType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1MEPSystem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Direction;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1IsConnected;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Shape;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1Radius;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid1ConnectedTo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Domain;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2SystemName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2MEPSystem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Direction;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2IsConnected;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Shape;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2Radius;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgrid2ConnectedTo;
	private: System::Windows::Forms::Label^ lblcountto;
	private: System::Windows::Forms::Label^ lblcountfrom;
    private: System::Windows::Forms::Button^ btnCreateAndConnectAll;
	private: System::Windows::Forms::ToolTip^ ttipbtnCreateAndConnectAll;

	public:
		MainForm(ExternalCommandData^ ExtCmd, ExternalEvent^ exEvent, iexeventhandler^ handler)
		{
			InitializeComponent();
			extcmdata = ExtCmd;
			uiapp = extcmdata->Application;
			uidoc = uiapp->ActiveUIDocument;
			doc = uidoc->Document;
			m_ExEvent = exEvent;
			m_Handler = handler;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::Button^ btnReplaceSelected;
protected:

protected:

protected:

	private: System::Windows::Forms::Label^ labelReplaceTo;

	protected:


	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnReplaceSelected = (gcnew System::Windows::Forms::Button());
			this->labelReplaceTo = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnSelect1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dgrid1Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1Domain = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1SystemType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1MEPSystem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1Direction = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1IsConnected = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1Shape = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1Radius = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid1ConnectedTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbl_familyinfo1 = (gcnew System::Windows::Forms::Label());
			this->lbl_familyinfo2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dgrid2Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2Domain = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2SystemName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2MEPSystem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2Direction = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2IsConnected = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2Shape = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2Radius = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgrid2ConnectedTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelCreateFrom = (gcnew System::Windows::Forms::Label());
			this->btnSelect2 = (gcnew System::Windows::Forms::Button());
			this->btnCreateAndConnect = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblcountto = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblcountfrom = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnCreateAndConnectAll = (gcnew System::Windows::Forms::Button());
			this->ttipbtnCreateAndConnectAll = (gcnew System::Windows::Forms::ToolTip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnReplaceSelected
			// 
			this->btnReplaceSelected->Location = System::Drawing::Point(94, 373);
			this->btnReplaceSelected->Name = L"btnReplaceSelected";
			this->btnReplaceSelected->Size = System::Drawing::Size(88, 37);
			this->btnReplaceSelected->TabIndex = 0;
			this->btnReplaceSelected->Text = L"Replace Selected";
			this->btnReplaceSelected->UseVisualStyleBackColor = true;
			this->btnReplaceSelected->Click += gcnew System::EventHandler(this, &MainForm::btnReplaceSelected_Click);
			// 
			// labelReplaceTo
			// 
			this->labelReplaceTo->AutoSize = true;
			this->labelReplaceTo->ForeColor = System::Drawing::Color::Red;
			this->labelReplaceTo->Location = System::Drawing::Point(9, 3);
			this->labelReplaceTo->Name = L"labelReplaceTo";
			this->labelReplaceTo->Size = System::Drawing::Size(63, 13);
			this->labelReplaceTo->TabIndex = 1;
			this->labelReplaceTo->Text = L"Connect To";
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(653, 383);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(68, 27);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// btnSelect1
			// 
			this->btnSelect1->Location = System::Drawing::Point(4, 150);
			this->btnSelect1->Name = L"btnSelect1";
			this->btnSelect1->Size = System::Drawing::Size(84, 26);
			this->btnSelect1->TabIndex = 5;
			this->btnSelect1->Text = L"Select";
			this->btnSelect1->UseVisualStyleBackColor = true;
			this->btnSelect1->Click += gcnew System::EventHandler(this, &MainForm::btnSelect_Click1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->dgrid1Id,
					this->dgrid1Domain, this->dgrid1SystemType, this->dgrid1MEPSystem, this->dgrid1Type, this->dgrid1Direction, this->dgrid1IsConnected,
					this->dgrid1Shape, this->dgrid1Radius, this->dgrid1ConnectedTo
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.471698F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Enabled = false;
			this->dataGridView1->Location = System::Drawing::Point(94, 20);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.471698F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->NullValue = L"*";
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersWidth = 22;
			this->dataGridView1->Size = System::Drawing::Size(647, 155);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellClick);
			this->dataGridView1->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellEnter);
			this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_RowEnter);
			this->dataGridView1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::dataGridView1_MouseClick);
			// 
			// dgrid1Id
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Format = L"N0";
			dataGridViewCellStyle1->NullValue = L"-1";
			this->dgrid1Id->DefaultCellStyle = dataGridViewCellStyle1;
			this->dgrid1Id->Frozen = true;
			this->dgrid1Id->HeaderText = L"Id";
			this->dgrid1Id->MinimumWidth = 15;
			this->dgrid1Id->Name = L"dgrid1Id";
			this->dgrid1Id->ReadOnly = true;
			this->dgrid1Id->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dgrid1Id->Width = 20;
			// 
			// dgrid1Domain
			// 
			this->dgrid1Domain->HeaderText = L"Domain";
			this->dgrid1Domain->MinimumWidth = 6;
			this->dgrid1Domain->Name = L"dgrid1Domain";
			this->dgrid1Domain->ReadOnly = true;
			this->dgrid1Domain->Width = 88;
			// 
			// dgrid1SystemType
			// 
			this->dgrid1SystemType->HeaderText = L"System Type";
			this->dgrid1SystemType->MinimumWidth = 15;
			this->dgrid1SystemType->Name = L"dgrid1SystemType";
			this->dgrid1SystemType->ReadOnly = true;
			this->dgrid1SystemType->Width = 110;
			// 
			// dgrid1MEPSystem
			// 
			this->dgrid1MEPSystem->HeaderText = L"MEP System";
			this->dgrid1MEPSystem->MinimumWidth = 6;
			this->dgrid1MEPSystem->Name = L"dgrid1MEPSystem";
			this->dgrid1MEPSystem->ReadOnly = true;
			this->dgrid1MEPSystem->Width = 110;
			// 
			// dgrid1Type
			// 
			this->dgrid1Type->HeaderText = L"Type";
			this->dgrid1Type->MinimumWidth = 10;
			this->dgrid1Type->Name = L"dgrid1Type";
			this->dgrid1Type->ReadOnly = true;
			this->dgrid1Type->Width = 40;
			// 
			// dgrid1Direction
			// 
			this->dgrid1Direction->HeaderText = L"Direction";
			this->dgrid1Direction->MinimumWidth = 6;
			this->dgrid1Direction->Name = L"dgrid1Direction";
			this->dgrid1Direction->ReadOnly = true;
			this->dgrid1Direction->Width = 65;
			// 
			// dgrid1IsConnected
			// 
			this->dgrid1IsConnected->HeaderText = L"Is Connected";
			this->dgrid1IsConnected->MinimumWidth = 10;
			this->dgrid1IsConnected->Name = L"dgrid1IsConnected";
			this->dgrid1IsConnected->ReadOnly = true;
			this->dgrid1IsConnected->Width = 50;
			// 
			// dgrid1Shape
			// 
			this->dgrid1Shape->HeaderText = L"Shape";
			this->dgrid1Shape->MinimumWidth = 10;
			this->dgrid1Shape->Name = L"dgrid1Shape";
			this->dgrid1Shape->ReadOnly = true;
			this->dgrid1Shape->Width = 50;
			// 
			// dgrid1Radius
			// 
			this->dgrid1Radius->HeaderText = L"Radius";
			this->dgrid1Radius->MinimumWidth = 6;
			this->dgrid1Radius->Name = L"dgrid1Radius";
			this->dgrid1Radius->ReadOnly = true;
			this->dgrid1Radius->Width = 50;
			// 
			// dgrid1ConnectedTo
			// 
			this->dgrid1ConnectedTo->HeaderText = L"Connected To";
			this->dgrid1ConnectedTo->MinimumWidth = 6;
			this->dgrid1ConnectedTo->Name = L"dgrid1ConnectedTo";
			this->dgrid1ConnectedTo->ReadOnly = true;
			this->dgrid1ConnectedTo->Width = 300;
			// 
			// lbl_familyinfo1
			// 
			this->lbl_familyinfo1->AutoSize = true;
			this->lbl_familyinfo1->Location = System::Drawing::Point(94, 3);
			this->lbl_familyinfo1->Name = L"lbl_familyinfo1";
			this->lbl_familyinfo1->Size = System::Drawing::Size(57, 13);
			this->lbl_familyinfo1->TabIndex = 8;
			this->lbl_familyinfo1->Text = L"Family Info";
			// 
			// lbl_familyinfo2
			// 
			this->lbl_familyinfo2->AutoSize = true;
			this->lbl_familyinfo2->Location = System::Drawing::Point(94, 3);
			this->lbl_familyinfo2->Name = L"lbl_familyinfo2";
			this->lbl_familyinfo2->Size = System::Drawing::Size(57, 13);
			this->lbl_familyinfo2->TabIndex = 13;
			this->lbl_familyinfo2->Text = L"Family Info";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->dgrid2Id,
					this->dgrid2Domain, this->dgrid2SystemName, this->dgrid2MEPSystem, this->dgrid2Type, this->dgrid2Direction, this->dgrid2IsConnected,
					this->dgrid2Shape, this->dgrid2Radius, this->dgrid2ConnectedTo
			});
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.471698F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView2->Enabled = false;
			this->dataGridView2->Location = System::Drawing::Point(94, 21);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.471698F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->NullValue = L"*";
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->RowHeadersWidth = 22;
			this->dataGridView2->Size = System::Drawing::Size(646, 155);
			this->dataGridView2->TabIndex = 11;
			this->dataGridView2->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_RowEnter);
			this->dataGridView2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::dataGridView2_MouseClick);
			// 
			// dgrid2Id
			// 
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle4->Format = L"N0";
			dataGridViewCellStyle4->NullValue = L"-1";
			this->dgrid2Id->DefaultCellStyle = dataGridViewCellStyle4;
			this->dgrid2Id->Frozen = true;
			this->dgrid2Id->HeaderText = L"Id";
			this->dgrid2Id->MaxInputLength = 4294;
			this->dgrid2Id->MinimumWidth = 15;
			this->dgrid2Id->Name = L"dgrid2Id";
			this->dgrid2Id->ReadOnly = true;
			this->dgrid2Id->Width = 20;
			// 
			// dgrid2Domain
			// 
			this->dgrid2Domain->HeaderText = L"Domain";
			this->dgrid2Domain->MinimumWidth = 6;
			this->dgrid2Domain->Name = L"dgrid2Domain";
			this->dgrid2Domain->ReadOnly = true;
			this->dgrid2Domain->Width = 88;
			// 
			// dgrid2SystemName
			// 
			this->dgrid2SystemName->HeaderText = L"System Type";
			this->dgrid2SystemName->MinimumWidth = 15;
			this->dgrid2SystemName->Name = L"dgrid2SystemName";
			this->dgrid2SystemName->ReadOnly = true;
			this->dgrid2SystemName->Width = 110;
			// 
			// dgrid2MEPSystem
			// 
			this->dgrid2MEPSystem->HeaderText = L"MEP System";
			this->dgrid2MEPSystem->MinimumWidth = 6;
			this->dgrid2MEPSystem->Name = L"dgrid2MEPSystem";
			this->dgrid2MEPSystem->ReadOnly = true;
			this->dgrid2MEPSystem->Width = 110;
			// 
			// dgrid2Type
			// 
			this->dgrid2Type->HeaderText = L"Type";
			this->dgrid2Type->MinimumWidth = 10;
			this->dgrid2Type->Name = L"dgrid2Type";
			this->dgrid2Type->ReadOnly = true;
			this->dgrid2Type->Width = 40;
			// 
			// dgrid2Direction
			// 
			this->dgrid2Direction->HeaderText = L"Direction";
			this->dgrid2Direction->MinimumWidth = 6;
			this->dgrid2Direction->Name = L"dgrid2Direction";
			this->dgrid2Direction->ReadOnly = true;
			this->dgrid2Direction->Width = 65;
			// 
			// dgrid2IsConnected
			// 
			this->dgrid2IsConnected->HeaderText = L"Is Connected";
			this->dgrid2IsConnected->MinimumWidth = 10;
			this->dgrid2IsConnected->Name = L"dgrid2IsConnected";
			this->dgrid2IsConnected->ReadOnly = true;
			this->dgrid2IsConnected->Width = 50;
			// 
			// dgrid2Shape
			// 
			this->dgrid2Shape->HeaderText = L"Shape";
			this->dgrid2Shape->MinimumWidth = 10;
			this->dgrid2Shape->Name = L"dgrid2Shape";
			this->dgrid2Shape->ReadOnly = true;
			this->dgrid2Shape->Width = 50;
			// 
			// dgrid2Radius
			// 
			this->dgrid2Radius->HeaderText = L"Radius";
			this->dgrid2Radius->MinimumWidth = 6;
			this->dgrid2Radius->Name = L"dgrid2Radius";
			this->dgrid2Radius->ReadOnly = true;
			this->dgrid2Radius->Width = 50;
			// 
			// dgrid2ConnectedTo
			// 
			this->dgrid2ConnectedTo->HeaderText = L"Connected To";
			this->dgrid2ConnectedTo->MinimumWidth = 6;
			this->dgrid2ConnectedTo->Name = L"dgrid2ConnectedTo";
			this->dgrid2ConnectedTo->ReadOnly = true;
			this->dgrid2ConnectedTo->Width = 300;
			// 
			// labelCreateFrom
			// 
			this->labelCreateFrom->AutoSize = true;
			this->labelCreateFrom->ForeColor = System::Drawing::Color::Red;
			this->labelCreateFrom->Location = System::Drawing::Point(9, 4);
			this->labelCreateFrom->Name = L"labelCreateFrom";
			this->labelCreateFrom->Size = System::Drawing::Size(64, 13);
			this->labelCreateFrom->TabIndex = 10;
			this->labelCreateFrom->Text = L"Create From";
			// 
			// btnSelect2
			// 
			this->btnSelect2->Location = System::Drawing::Point(4, 149);
			this->btnSelect2->Name = L"btnSelect2";
			this->btnSelect2->Size = System::Drawing::Size(84, 26);
			this->btnSelect2->TabIndex = 5;
			this->btnSelect2->Text = L"Select";
			this->btnSelect2->UseVisualStyleBackColor = true;
			this->btnSelect2->Click += gcnew System::EventHandler(this, &MainForm::btnSelect_Click2);
			// 
			// btnCreateAndConnect
			// 
			this->btnCreateAndConnect->Location = System::Drawing::Point(188, 373);
			this->btnCreateAndConnect->Location = System::Drawing::Point(188, 373);
			this->btnCreateAndConnect->Name = L"btnCreateAndConnect";
			this->btnCreateAndConnect->Size = System::Drawing::Size(75, 37);
			this->btnCreateAndConnect->TabIndex = 14;
			this->btnCreateAndConnect->Text = L"Create And Connect";
			this->btnCreateAndConnect->UseVisualStyleBackColor = true;
			this->btnCreateAndConnect->Click += gcnew System::EventHandler(this, &MainForm::btnCreateAndConnect_Click);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(628, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 12);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Column:     Row:   ";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(6, 64);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 80);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(6, 63);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(80, 80);
			this->pictureBox2->TabIndex = 17;
			this->pictureBox2->TabStop = false;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(628, 142);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 12);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Column:     Row:   ";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(217, 866);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox1->TabIndex = 20;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->lblcountto);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->lbl_familyinfo1);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->btnSelect1);
			this->panel1->Controls->Add(this->labelReplaceTo);
			this->panel1->Location = System::Drawing::Point(3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(745, 180);
			this->panel1->TabIndex = 22;
			// 
			// lblcountto
			// 
			this->lblcountto->AutoSize = true;
			this->lblcountto->Location = System::Drawing::Point(9, 48);
			this->lblcountto->Name = L"lblcountto";
			this->lblcountto->Size = System::Drawing::Size(38, 13);
			this->lblcountto->TabIndex = 18;
			this->lblcountto->Text = L"Count:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->lblcountfrom);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->lbl_familyinfo2);
			this->panel2->Controls->Add(this->labelCreateFrom);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->btnSelect2);
			this->panel2->Controls->Add(this->dataGridView2);
			this->panel2->Location = System::Drawing::Point(3, 190);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(745, 180);
			this->panel2->TabIndex = 23;
			// 
			// lblcountfrom
			// 
			this->lblcountfrom->AutoSize = true;
			this->lblcountfrom->Location = System::Drawing::Point(9, 47);
			this->lblcountfrom->Name = L"lblcountfrom";
			this->lblcountfrom->Size = System::Drawing::Size(38, 13);
			this->lblcountfrom->TabIndex = 18;
			this->lblcountfrom->Text = L"Count:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(3, 416);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(372, 100);
			this->richTextBox1->TabIndex = 24;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::Menu;
			this->richTextBox2->Location = System::Drawing::Point(376, 416);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(372, 100);
			this->richTextBox2->TabIndex = 24;
			this->richTextBox2->Text = L"";
			// 
			// btnCreateAndConnectAll
			// 
			this->btnCreateAndConnectAll->Location = System::Drawing::Point(269, 373);
			this->btnCreateAndConnectAll->Name = L"btnCreateAndConnectAll";
			this->btnCreateAndConnectAll->Size = System::Drawing::Size(75, 37);
			this->btnCreateAndConnectAll->TabIndex = 14;
			this->btnCreateAndConnectAll->Text = L"Create And Connect All";
			this->btnCreateAndConnectAll->UseVisualStyleBackColor = true;
			this->btnCreateAndConnectAll->Click += gcnew System::EventHandler(this, &MainForm::btnCreateAndConnectAll_Click);
			// 
			// ttipbtnCreateAndConnectAll
			// 
			this->ttipbtnCreateAndConnectAll->AutoPopDelay = 5000;
			this->ttipbtnCreateAndConnectAll->InitialDelay = 1000;
			this->ttipbtnCreateAndConnectAll->ReshowDelay = 500;
			this->ttipbtnCreateAndConnectAll->ShowAlways = true;
			this->ttipbtnCreateAndConnectAll->SetToolTip(this->btnCreateAndConnectAll, "Doesn^t delete nested elements.");

			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 519);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->btnCreateAndConnectAll);
			this->Controls->Add(this->btnCreateAndConnect);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnReplaceSelected);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(100, 500);
			this->Name = L"MainForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Select Element";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/// <summary>
		///   A private helper method to make a request
		///   and put the dialog to sleep at the same time.
		/// </summary>
		/// <remarks>
		///   It is expected that the process which executes the request 
		///   (the Idling helper in this particular case) will also
		///   wake the dialog up after finishing the execution.
		/// </remarks>
		///
	private: void MakeRequest(RequestId request)
	{
		m_Handler->request->Make(request);
		m_ExEvent->Raise();
	}

	   /// <summary>
	   /// Get the connected connector of one connector
	   /// </summary>
	   /// <param name="connector"> : The connector to be analyzed</param>
	   /// <returns>The connected connector</returns>
	private: Connector^ GetConnectedConnector(Connector^ connector)
	{
		Connector^ connectedConnector = nullptr;
		ConnectorSet^ allRefs = connector->AllRefs;
		for each (Connector ^ c in allRefs)
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

	private: System::Void btnReplaceSelected_Click(System::Object^ sender, System::EventArgs^ e)
	{	
		MakeRequest(RequestId::ReplaceSelected);
	}

	private: System::Void btnCreateAndConnect_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MakeRequest(RequestId::CreateAndConnect);
	}

	private: System::Void btnCreateAndConnectAll_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MakeRequest(RequestId::CreateAndConnectAll);
	}

	private: System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		// We own both the event and the handler
		// We should dispose it before we are closed
		// this didn't work. m_ExEvent->Dispose();
		m_ExEvent = nullptr;
		m_Handler = nullptr;

		// do not forget to call the base class
		//	I also couldnt fint equivalent in c++/cli base.OnFormClosed(e);
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	private: System::Void btnSelect_Click1(System::Object^ sender, System::EventArgs^ e)
	{	
		//	Disable datagrid events.
		this->dataGridView1->RowEnter -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_RowEnter);
		this->dataGridView1->CellEnter -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellEnter);

		btnSelect1->Enabled = false;	//	Prevent second click.
		Reference^ pickedRef = nullptr;
		Element^ pickedEl = nullptr;
		ElementId^ symbolId = nullptr;
		FamilyInstance^ famInst = nullptr;
		try
		{	//	Catch if commnad aborted.
			Autodesk::Revit::UI::Selection::Selection^ choices = uidoc->Selection;
			// Pick one object from Revit.
			ISelectionFilter^ selectionfilter = gcnew pickSelectionFilter();
			pickedRef = choices->PickObject(ObjectType::Element, selectionfilter, "Select a pipe accesory");
			pickedEl =  doc->GetElement(pickedRef);
			//uidoc->ShowElements(pickedEl);
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("!!! ", "Nothing selected.");
		}

		if (nullptr != pickedEl)
		{	//	If any element selected.
			famInst = (FamilyInstance^)pickedEl;
			symbolId = pickedEl->GetTypeId();

			//	Get all elements and write them to Global list.
			FilteredElementCollector^ collector = gcnew FilteredElementCollector(doc);
			collector = collector->OfClass(FamilySymbol::typeid);

			// Create a FamilyInstance filter with the FamilySymbol Id
			FamilyInstanceFilter^ filter = gcnew FamilyInstanceFilter(doc, symbolId);

			// Apply the filter to the elements in the active document
			collector = gcnew FilteredElementCollector(doc);
			globalObjects::finsto = collector->WherePasses(filter)->ToElements();
			lblcountto->Text ="Count: " + globalObjects::finsto->Count.ToString();

			ElementType^ type = (ElementType^)doc->GetElement(symbolId);

			System::Drawing::Size imgSize = System::Drawing::Size(80, 80);

			Bitmap^ image = type->GetPreviewImage(imgSize);

			pictureBox1->Image = image;

			lbl_familyinfo1->Text = " Element Id: " + pickedEl->Id->ToString() + " >> Family Name : " +  famInst->Symbol->FamilyName + " >> Type Name: " + famInst->Name + " >> SymbolId: " + pickedEl->GetTypeId()->ToString();
		
			filldatagrid(dataGridView1, pickedEl);
			dataGridView1->Enabled = true;
			elmstoreplace::elmIdTo = pickedEl->Id;
		
			//	If element has connector and connector is cell is not empty.
			if (dataGridView1->RowCount > 0 && String::Empty != dataGridView1->CurrentRow->Cells[0]->Value->ToString())
			{
				int::TryParse(dataGridView1->CurrentRow->Cells[0]->Value->ToString(), elmstoreplace::connNoTo);
				dataGridView1->Rows[0]->Selected = true;
			}
		}
		//	Enable datagrid events.
		this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_RowEnter);
		this->dataGridView1->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellEnter);
		btnSelect1->Enabled = true;	//Release button.
	}

	private: System::Void btnSelect_Click2(System::Object^ sender, System::EventArgs^ e)
	{	
		//	Disable datagrid events.
		this->dataGridView2->RowEnter -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_RowEnter);
		this->dataGridView2->CellEnter -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_CellEnter);

		btnSelect2->Enabled = false;	//	Prevent second click.
		Reference^ pickedRef = nullptr;
		Element^ pickedEl = nullptr;
		ElementId^ symbolId = nullptr;
		FamilyInstance^ famInst = nullptr;
		try
		{	//	Catch if commnad aborted.
			Autodesk::Revit::UI::Selection::Selection^ choices = uidoc->Selection;

			// Pick one object from Revit.
			ISelectionFilter^ selectionfilter = gcnew pickSelectionFilter();
			pickedRef = choices->PickObject(ObjectType::Element, selectionfilter, "Select a pipe accesory");
			pickedEl = doc->GetElement(pickedRef);
			//uidoc->ShowElements(pickedEl);
		}
		catch (Exception^ ex)
		{
			TaskDialog::Show("!!! ", "Nothing selected.");
		}

		if (nullptr != pickedEl)
		{	//	If any element selected.
			famInst = (FamilyInstance^)pickedEl;
			symbolId = pickedEl->GetTypeId();

			//	Get all elements and write them to Global list.
			FilteredElementCollector^ collector = gcnew FilteredElementCollector(doc);
			collector = collector->OfClass(FamilySymbol::typeid);

			// Create a FamilyInstance filter with the FamilySymbol Id
			FamilyInstanceFilter^ filter = gcnew FamilyInstanceFilter(doc, symbolId);

			// Apply the filter to the elements in the active document
			collector = gcnew FilteredElementCollector(doc);
			globalObjects::finsfrom = collector->WherePasses(filter)->ToElements();
			lblcountfrom->Text = "Count: " + globalObjects::finsfrom->Count.ToString();

			ElementType^ type = (ElementType^)doc->GetElement(symbolId);

			System::Drawing::Size imgSize = System::Drawing::Size(80, 80);

			Bitmap^ image = type->GetPreviewImage(imgSize);

			pictureBox2->Image = image;

			lbl_familyinfo2->Text = " Element Id: " + pickedEl->Id->ToString() + " >> Family Name : " + famInst->Symbol->FamilyName + " >> Type Name: " + famInst->Name + " >> SymbolId: " + pickedEl->GetTypeId()->ToString();

			filldatagrid(dataGridView2, pickedEl);
			dataGridView2->Enabled = true;
			elmstoreplace::elmIdFrom = pickedEl->Id;

			//	If element has connector and connector no cell is not empty.
			if (dataGridView2->RowCount > 0 && String::Empty != dataGridView2->CurrentRow->Cells[0]->Value->ToString())
			{
				int::TryParse(dataGridView2->CurrentRow->Cells[0]->Value->ToString(), elmstoreplace::connNoFrom);
				dataGridView2->Rows[0]->Selected = true;
			}
		}
		//	Enable datagrid events.
		this->dataGridView2->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_RowEnter);
		this->dataGridView2->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_CellEnter);
		btnSelect2->Enabled = true;	//Release button.
	}

	private: void filldatagrid(DataGridView^ datagrid, Element^ pickedEl)
	{
		datagrid->Rows->Clear();
		// Pick an element
		//int id32 = 0;
		//int id = int::TryParse(checkedListBox1->SelectedItem->ToString(), id32);
		//Element^ element = doc->GetElement(gcnew ElementId(id32));
		
		Element^ element =pickedEl;
		MEPCurve^ mepcurve = nullptr;
		FamilyInstance^ faminst = nullptr;
		MEPModel^ mepmodel = nullptr;
		ConnectorSet^ connectorSet = nullptr;
		Element^ connectedelement = nullptr;
		int rowcounter = 0;

		try
		{
			if (nullptr != (FamilyInstance^)element)
			{
				// 1. Cast Element to FamilyInstance
				faminst = (FamilyInstance^)element;

				// 2. Get MEPModel Property
				mepmodel = faminst->MEPModel;

				// 3. Get connector set of MEPModel
				connectorSet = mepmodel->ConnectorManager->Connectors;

				for each (Connector ^ connector in connectorSet)
				{
					datagrid->Rows->Add();
					datagrid->Rows[rowcounter]->Cells[0]->Value = connector->Id.ToString();
					datagrid->Rows[rowcounter]->Cells[1]->Value = connector->Domain;					
					if (connector->Domain == Domain::DomainPiping)
					{
						datagrid->Rows[rowcounter]->Cells[8]->Value = UnitUtils::ConvertFromInternalUnits(connector->Radius, UnitTypeId::Millimeters).ToString();
						//	This also worked.
						//datagrid->Rows[rowcounter]->Cells[6]->Value = 					UnitUtils::Convert(connector->Radius, UnitTypeId::Feet, UnitTypeId::Millimeters).ToString();
						datagrid->Rows[rowcounter]->Cells[2]->Value = connector->PipeSystemType.ToString();
					}
					else
					{
						datagrid->Rows[rowcounter]->Cells[7]->Value = "Non Pipe";
					}

					if (connector->IsConnected == false)
					{
						if (connector->MEPSystem == nullptr)
						{
							datagrid->Rows[rowcounter]->Cells[3]->Value = "Undefined";
						}
						else
						{
							datagrid->Rows[rowcounter]->Cells[3]->Value = connector->MEPSystem->Name;
						}
						datagrid->Rows[rowcounter]->Cells[4]->Value = connector->ConnectorType;
						datagrid->Rows[rowcounter]->Cells[5]->Value = connector->Direction;
						datagrid->Rows[rowcounter]->Cells[6]->Value = connector->IsConnected;
						datagrid->Rows[rowcounter]->Cells[7]->Value = connector->Shape;
						datagrid->Rows[rowcounter]->Cells[9]->Value = "Not Connected";
					}
					else
					{
						//	To get connected connector.
						Connector^ connectedConnector = GetConnectedConnector(connector);

						//	Get connected element
						connectedelement = connectedConnector->Owner;

						//	Find connected family name.
						Element^ eInstance = connectedConnector->Owner;

						if (connector->MEPSystem == nullptr)
						{
							datagrid->Rows[rowcounter]->Cells[3]->Value = "Undefined";
						}
						else
						{
							datagrid->Rows[rowcounter]->Cells[3]->Value = connector->MEPSystem->Name;
						}
						datagrid->Rows[rowcounter]->Cells[4]->Value = connector->ConnectorType;
						datagrid->Rows[rowcounter]->Cells[5]->Value = connector->Direction;
						datagrid->Rows[rowcounter]->Cells[6]->Value = connector->IsConnected;
						datagrid->Rows[rowcounter]->Cells[7]->Value = connector->Shape;
						datagrid->Rows[rowcounter]->Cells[9]->Value = connectedelement->Id->ToString() + " -> " + connectedelement->Name + " -> " + connectedelement->Category->Name;
					}
					rowcounter++;
				}
			}
		}
		catch (Exception^ ex)
		{

		}
	}

	private: System::Void dataGridView1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		int::TryParse(dataGridView1->CurrentRow->Cells[0]->Value->ToString(), elmstoreplace::connNoTo);

		Element^ elmto = doc->GetElement(elmstoreplace::elmIdTo);
		// 1. Cast Element to FamilyInstance
		FamilyInstance^ faminstto = (FamilyInstance^)elmto;

		// 2. Get MEPModel Property
		MEPModel^ mepmodelto = faminstto->MEPModel;

		// 3. Get connector set of MEPModel
		ConnectorSet^ connectorSetto = mepmodelto->ConnectorManager->Connectors;

		Connector^ connTo = nullptr;

		for each (Connector ^ connector in connectorSetto)
		{
			if (connector->Id == elmstoreplace::connNoTo)
			{
				connTo = connector;
			}
		}
	}
	private: System::Void dataGridView2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		int::TryParse(dataGridView2->CurrentRow->Cells[0]->Value->ToString(), elmstoreplace::connNoFrom);

		Element^ elmfrom = doc->GetElement(elmstoreplace::elmIdFrom);
		// 1. Cast Element to FamilyInstance
		FamilyInstance^ faminstfrom = (FamilyInstance^)elmfrom;

		// 2. Get MEPModel Property
		MEPModel^ mepmodelfrom = faminstfrom->MEPModel;

		// 3. Get connector set of MEPModel
		ConnectorSet^ connectorSetfrom = mepmodelfrom->ConnectorManager->Connectors;

		Connector^ connFrom = nullptr;
		
		for each (Connector ^ connector in connectorSetfrom)
		{
			if (connector->Id == elmstoreplace::connNoFrom)
			{
				connFrom = connector;
			}
		}
	}
	private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	//	For now, nothing.
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		//	For now, nothing.
	}

	private: System::Void dataGridView1_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (dataGridView1->RowCount > 0)
		{
			for (int i = 0; i < dataGridView1->RowCount; i++)
			{
				for (int j = 0; j < dataGridView1->ColumnCount; j++)
				{
					dataGridView1[j, i]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Regular);
					dataGridView1[j, i]->Style->ForeColor = System::Drawing::Color::Black;
					dataGridView1[j, i]->Style->BackColor = System::Drawing::Color::Empty;
				}
			}
		}
		if (dataGridView2->Enabled && dataGridView2->RowCount > 0)
		{
			for (int i = 0; i < dataGridView2->RowCount; i++)
			{
				for (int j = 0; j < dataGridView2->ColumnCount; j++)
				{
					dataGridView2[j, i]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Regular);
					dataGridView2[j, i]->Style->ForeColor = System::Drawing::Color::Black;
					dataGridView2[j, i]->Style->BackColor = System::Drawing::Color::Empty;
					dataGridView2[j, dataGridView2->CurrentRow->Index]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Bold);
					dataGridView2[j, dataGridView2->CurrentRow->Index]->Style->BackColor = System::Drawing::Color::Beige;
				}
			}
		}

		for (int i = 0; i < dataGridView1->ColumnCount; i++)
		{
			dataGridView1[i, e->RowIndex]->Style->BackColor = System::Drawing::Color::Beige;
			dataGridView1[i, e->RowIndex]->Style->ForeColor = System::Drawing::Color::Black;
			dataGridView1[i, e->RowIndex]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Bold);
		}

		try
		{
			if (dataGridView1->RowCount > 0 && dataGridView2->RowCount > 0)
			{
				for (int i = 1; i < dataGridView1->Rows[e->RowIndex]->Cells->Count; i++)
				{
					if (dataGridView1->Rows[e->RowIndex]->Cells[i]->Value->ToString() != dataGridView2->CurrentRow->Cells[i]->Value->ToString())
					{
					dataGridView1[i, e->RowIndex]->Style->ForeColor = System::Drawing::Color::Red;
					dataGridView2->CurrentRow->Cells[i]->Style->ForeColor = System::Drawing::Color::Red;
					}
				}
			}
		}
		catch (const Exception^ ex)
		{
			TaskDialog::Show("!!!", "Second element hasn't been selected or it doesn't have any connector.");
		}
	}

	private: System::Void dataGridView1_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (dataGridView1->RowCount > 0 && dataGridView2->RowCount > 0)
		{
			if (dataGridView1->CurrentCell->Value->ToString() == dataGridView2->CurrentRow->Cells[e->ColumnIndex]->Value->ToString())
			{
				dataGridView1->CurrentCell->Style->SelectionForeColor = System::Drawing::Color::Black;
			}
			else
			{
				dataGridView1->CurrentCell->Style->SelectionForeColor = System::Drawing::Color::Red;
			}
		}
		label4->Text = "Row: " + e->RowIndex.ToString() + " , Clolumn: " + e->ColumnIndex.ToString();
	}

	private: System::Void dataGridView2_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (dataGridView2->RowCount > 0)
		{
			for (int i = 0; i < dataGridView2->RowCount; i++)
			{
				for (int j = 0; j < dataGridView2->ColumnCount; j++)
				{
					dataGridView2[j, i]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Regular);
					dataGridView2[j, i]->Style->ForeColor = System::Drawing::Color::Black;
					dataGridView2[j, i]->Style->BackColor = System::Drawing::Color::Empty;
				}
			}
		}
		if (dataGridView1 ->Enabled && dataGridView1->RowCount > 0)
		{
			for (int i = 0; i < dataGridView1->RowCount; i++)
			{
				for (int j = 0; j < dataGridView1->ColumnCount; j++)
				{
					dataGridView1[j, i]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Regular);
					dataGridView1[j, i]->Style->ForeColor = System::Drawing::Color::Black;
					dataGridView1[j, i]->Style->BackColor = System::Drawing::Color::Empty;
					dataGridView1[j, dataGridView1->CurrentRow->Index]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Bold);
					dataGridView1[j, dataGridView1->CurrentRow->Index]->Style->BackColor = System::Drawing::Color::Beige;
				}
			}
		}

		for (int i = 0; i < dataGridView2->ColumnCount; i++)
		{
			dataGridView2[i, e->RowIndex]->Style->BackColor = System::Drawing::Color::Beige;
			dataGridView2[i, e->RowIndex]->Style->ForeColor = System::Drawing::Color::Black;
			dataGridView2[i, e->RowIndex]->Style->Font = gcnew System::Drawing::Font(this->Font, System::Drawing::FontStyle::Bold);
		}

		try
		{
			if (dataGridView2->RowCount > 0 && dataGridView1->RowCount > 0)
			{
				for (int i = 1; i < dataGridView2->Rows[e->RowIndex]->Cells->Count; i++)
				{
					if (dataGridView2->Rows[e->RowIndex]->Cells[i]->Value->ToString() != dataGridView1->CurrentRow->Cells[i]->Value->ToString())
					{
						dataGridView2[i, e->RowIndex]->Style->ForeColor = System::Drawing::Color::Red;
						dataGridView1->CurrentRow->Cells[i]->Style->ForeColor = System::Drawing::Color::Red;
					}
				}
				/*if (dataGridView1->CurrentRow->Cells[8]->Value->ToString() == dataGridView2->CurrentRow->Cells[8]->Value->ToString())
				{
					btnReplaceSelected->Enabled = true;
					btnCreateAndConnect->Enabled = true;
				}
				else
				{
					btnReplaceSelected->Enabled = false;
					btnCreateAndConnect->Enabled = false;
				}*/
			}
		}
		catch (const Exception^ ex)
		{
			TaskDialog::Show("!!!", "Second element hasn't been selected or it doesn't have any connector.");
		}
	}

	private: System::Void dataGridView2_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (dataGridView2->RowCount > 0 && dataGridView1->RowCount > 0)
		{
			if (dataGridView2->CurrentCell->Value->ToString() == dataGridView1->CurrentRow->Cells[e->ColumnIndex]->Value->ToString())
			{
				dataGridView2->CurrentCell->Style->SelectionForeColor = System::Drawing::Color::Black;
			}
			else
			{
				dataGridView2->CurrentCell->Style->SelectionForeColor = System::Drawing::Color::Red;
			}
		}
		label5->Text = "Row: " + e->RowIndex.ToString() + " , Clolumn: " + e->ColumnIndex.ToString();
	}
};
}