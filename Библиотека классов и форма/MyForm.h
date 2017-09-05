#pragma once
#include"library\Draft.h"
#include"library\Manager.h"
#include<string>
//#include <msclr\marshal_cppstd.h>
namespace GraphEditorFileOpening {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	Draft dr;
	Manager manager;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(64, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->��������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->������������ToolStripMenuItem });
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->������������ToolStripMenuItem->Text = L"������� �����";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������ToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		// ������� ������ �������� �����
		openFileDialog1->ShowDialog();
		if (openFileDialog1->FileName == nullptr) return;
		// ������ ���������� �����:
		try
		{ // �������� ���������� StreamReader ��� ������ �� �����
			auto reader = gcnew
				IO::StreamReader(openFileDialog1->FileName,
					System::Text::Encoding::GetEncoding(1251));
			// - ����� ����� ������� �������� Win1251 ��� ������� ����
			//textBox1->Text = reader->ReadToEnd();
			reader->Close();

			String^ s = openFileDialog1->FileName;
			dr.openFile(s);
			pictureBox1->Refresh();
		}
		catch (IO::FileNotFoundException^ ��������)
		{
			MessageBox::Show(��������->Message + "\n��� ������ �����",
				"������", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
		catch (Exception^ ex)
		{
			// ����� � ������ �������
			MessageBox::Show(ex->Message, "������",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	saveFileDialog1->FileName = openFileDialog1->FileName;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		try
		{
			// �������� ���������� StreamWriter ��� ������ � ����:
			auto �������� = gcnew
				IO::StreamWriter(saveFileDialog1->FileName, false,
					System::Text::Encoding::GetEncoding(1251));
			// - ����� ����� ������� �������� Win1251 ��� ������� ����

			std::string st = dr.createVertexString();
			String^ st2 = gcnew String(st.c_str());
			��������->Write(st2);
			��������->Write("\r\n");
			st = dr.createLinesString();
			st2 = gcnew String(st.c_str());
			��������->Write(st2);
			��������->Close();
		}
		catch (Exception^ ��������)
		{
			// ����� ��� ���� ��������� �������
			MessageBox::Show(��������->Message, "������",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}
}
private: System::Void ������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	manager.isGoingOnLineCreation = true;
}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	dr.view(e);
}
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (manager.isGoingOnLineCreation == true)
	{
		if (dr.isMouseOnExistingVertex(e->X, e->Y))
		{
			dr.insertNewLineAndVertexInsteadOfClickedVertex();
			dr.setLastXYPosition(e->X, e->Y);
			manager.isGoingOnVertexMoving = true;
			//dr.setListOfConnectedLines();
		}
	}
	else if (dr.isMouseOnExistingVertex(e->X, e->Y))
	{
		//MessageBox::Show("\n������ �� �������", "!!!!!!!!!!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		dr.setLastXYPosition(e->X, e->Y);
		manager.isGoingOnVertexMoving = true;
		//Set connected lines
		//dr.setListOfConnectedLines();
	}
	else if (dr.isMouseOnExistingLine(e->X, e->Y))
	{
		dr.setLastXYPosition(e->X, e->Y);
		manager.isGoingOnLineMoving = true;
	}
}
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (manager.isGoingOnVertexMoving == true)
	{
		dr.moveCurrentVertex(e->X, e->Y);
		//dr.moveConnectedLines(e->X, e->Y);
		dr.setLastXYPosition(e->X, e->Y);
		pictureBox1->Refresh();
	}
	else if (manager.isGoingOnLineMoving == true)
	{
		dr.moveLine(e->X, e->Y);
		dr.setLastXYPosition(e->X, e->Y);
		pictureBox1->Refresh();
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (manager.isGoingOnLineCreation)
	{
		if (dr.isMouseOnExistingVertexExceptJustCreated(e->X, e->Y))
		{
			dr.replaceJustCreatedVertexByExisting();
		}
		manager.isGoingOnLineCreation = false;
		manager.isGoingOnVertexMoving = false;
	}
	if (manager.isGoingOnVertexMoving == true)
	{
		manager.isGoingOnVertexMoving = false;
	}
	else if (manager.isGoingOnLineMoving == true)
	{
		manager.isGoingOnLineMoving = false;
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	pictureBox1->Location = Drawing::Point(0, 30);
	pictureBox1->Width = 10000;
	pictureBox1->Height = 10000;
	pictureBox1->BackColor = System::Drawing::Color::White;
	openFileDialog1->FileName = "C:/Users/Agricola/Documents/Visual Studio 2015/Projects/2/Plexes/Plex 1.8 GraphEditorWithFileSaving/GraphEditorWithFileSaving/GraphEditorWithFileSaving/data.txt";
	//openFileDialog1->RestoreDirectory = "C://Users/Agricola/Documents/Visual Studio 2015/Projects/1/Train/Train 2.0.2 Text Editor/TextEditor/TextEditor/";
	openFileDialog1->Filter =
		"��������� ����� (*.txt)|*.txt|All files (*.*)|*.*";
	saveFileDialog1->Filter =
		"��������� ����� (*.txt)|*.txt|All files (*.*)|*.*";

}
};
}
