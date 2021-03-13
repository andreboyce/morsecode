#pragma once

#include "char_test.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MorseCode
{

	/// <summary>
	/// Summary for CodeDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CodeDialog : public System::Windows::Forms::Form
	{
	public:
		CodeDialog(void)
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
		~CodeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  buttonCharTest;

	protected: 


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CodeDialog::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonCharTest = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonCharTest);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 605);
			this->panel1->TabIndex = 0;
			// 
			// buttonCharTest
			// 
			this->buttonCharTest->Location = System::Drawing::Point(400, 12);
			this->buttonCharTest->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->buttonCharTest->Name = L"buttonCharTest";
			this->buttonCharTest->Size = System::Drawing::Size(64, 21);
			this->buttonCharTest->TabIndex = 3;
			this->buttonCharTest->Text = L"Char Test";
			this->buttonCharTest->UseVisualStyleBackColor = true;
			this->buttonCharTest->Click += gcnew System::EventHandler(this, &CodeDialog::buttonCharTest_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(23, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(356, 581);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// CodeDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(480, 605);
			this->Controls->Add(this->panel1);
			this->Name = L"CodeDialog";
			this->Text = L"CodeDialog";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonCharTest_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			    char_test^ ct = gcnew char_test();
			    ct->ShowDialog();
			 }
	};
}
