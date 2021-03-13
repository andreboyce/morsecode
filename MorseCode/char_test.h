#pragma once

#include "MCode.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MorseCode
{

	/// <summary>
	/// Summary for char_test
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class char_test : public System::Windows::Forms::Form
	{
	public:
		char_test(void)
		{
			InitializeComponent();
			mCode = gcnew MCode();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~char_test()
		{
			if (components)
			{
				delete components;
			}
		}
	public: MCode^ mCode;
	private: System::Windows::Forms::TextBox^  textBoxMorseCode;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxCharacter;

	private: System::Windows::Forms::Label^  label2;

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
			this->textBoxMorseCode = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxCharacter = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxMorseCode
			// 
			this->textBoxMorseCode->Location = System::Drawing::Point(78, 12);
			this->textBoxMorseCode->Name = L"textBoxMorseCode";
			this->textBoxMorseCode->Size = System::Drawing::Size(211, 20);
			this->textBoxMorseCode->TabIndex = 0;
			this->textBoxMorseCode->TextChanged += gcnew System::EventHandler(this, &char_test::textBoxMorseCode_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Morse Code";
			// 
			// textBoxCharacter
			// 
			this->textBoxCharacter->Location = System::Drawing::Point(78, 57);
			this->textBoxCharacter->Name = L"textBoxCharacter";
			this->textBoxCharacter->ReadOnly = true;
			this->textBoxCharacter->Size = System::Drawing::Size(211, 20);
			this->textBoxCharacter->TabIndex = 2;
			this->textBoxCharacter->TextChanged += gcnew System::EventHandler(this, &char_test::textBoxCharacter_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Character";
			// 
			// char_test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 94);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxCharacter);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxMorseCode);
			this->Name = L"char_test";
			this->Text = L"char_test";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxMorseCode_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		        if (textBoxCharacter!=nullptr)
				{
					if (textBoxMorseCode != nullptr)
					{
						if (mCode != nullptr)
						{
							System::String^ morsecode = mCode->ConvertToMorseCode(textBoxMorseCode->Text);							
							textBoxCharacter->Text = morsecode;
						}
					}
				}
			 }
private: System::Void textBoxCharacter_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
