#pragma once

#include "AboutDialog.h"
#include "CodeDialog.h"
#include "SoundClass.h"
#include "MCode.h"
#include "char_test.h"

namespace MorseCode
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			mCode       = gcnew MCode();
			soundClass  = gcnew SoundClass();
			soundThread = nullptr;
			if (soundClass->controlClass != nullptr)
			{
				soundClass->controlClass->buttonPause = buttonPause;
				soundClass->controlClass->buttonStart = buttonStart;
				soundClass->controlClass->buttonStop  = buttonStop;
				soundClass->controlClass->richTextBoxMCode       = richTextBoxMCode;
				soundClass->controlClass->numericUpDownFrequency = numericUpDownFrequency;
				soundClass->controlClass->numericUpDownChannels  = numericUpDownChannels;
				soundClass->controlClass->trackBarSpeed          = trackBarSpeed;
			    soundClass->controlClass->trackBarVolume         = trackBarVolume;
				soundClass->controlClass->checkBoxLoop           = checkBoxLoop;

				soundClass->m_bLoop = checkBoxLoop->Checked;
				//soundClass->SetMessage(richTextBoxMCode->Text);
	            //soundClass->controlClass->InvokeSetRange(soundClass->controlClass->trackBarVolume, 0, 100, (int)soundClass->m_defaultVolume);
            }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if( components )
			{
			   soundClass->controlClass->buttonPause            = nullptr;
			   soundClass->controlClass->buttonStart            = nullptr;
			   soundClass->controlClass->buttonStop             = nullptr;
			   soundClass->controlClass->richTextBoxMCode       = nullptr;
			   soundClass->controlClass->numericUpDownFrequency = nullptr;
			   soundClass->controlClass->numericUpDownChannels  = nullptr;
			   soundClass->controlClass->trackBarSpeed          = nullptr;
			   soundClass->controlClass->trackBarVolume         = nullptr;
			   soundClass->controlClass->checkBoxLoop           = nullptr;
			   delete components;
			}
		}
	public: System::Threading::Thread^ soundThread;
	public: MCode^ mCode;
	public: SoundClass^ soundClass;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::StatusStrip^  statusStrip;

	protected: 

	protected: 

	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  buttonStop;
	private: System::Windows::Forms::Button^  buttonStart;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;


	private: System::Windows::Forms::TrackBar^  trackBarSpeed;
	private: System::Windows::Forms::CheckBox^  checkBoxLoop;
	private: System::Windows::Forms::Label^  Speed;


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^  codesToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::RichTextBox^  richTextBox;
	private: System::Windows::Forms::RichTextBox^  richTextBoxMCode;








	private: System::Windows::Forms::Button^  buttonPause;


	private: System::Windows::Forms::TrackBar^  trackBarVolume;

	private: System::Windows::Forms::Label^  label2;




	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownMorseCharacterIndex;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownFrequency;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownChannels;











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
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->codesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxMCode = (gcnew System::Windows::Forms::RichTextBox());
			this->numericUpDownChannels = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownFrequency = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownMorseCharacterIndex = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBarVolume = (gcnew System::Windows::Forms::TrackBar());
			this->buttonPause = (gcnew System::Windows::Forms::Button());
			this->Speed = (gcnew System::Windows::Forms::Label());
			this->trackBarSpeed = (gcnew System::Windows::Forms::TrackBar());
			this->checkBoxLoop = (gcnew System::Windows::Forms::CheckBox());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownChannels))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFrequency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMorseCharacterIndex))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarVolume))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpeed))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(498, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->codesToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// codesToolStripMenuItem
			// 
			this->codesToolStripMenuItem->Name = L"codesToolStripMenuItem";
			this->codesToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->codesToolStripMenuItem->Text = L"Codes";
			this->codesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::codesToolStripMenuItem_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->Location = System::Drawing::Point(0, 470);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(498, 22);
			this->statusStrip->TabIndex = 1;
			this->statusStrip->Text = L"statusStrip";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->numericUpDownChannels);
			this->splitContainer1->Panel2->Controls->Add(this->label4);
			this->splitContainer1->Panel2->Controls->Add(this->label1);
			this->splitContainer1->Panel2->Controls->Add(this->numericUpDownFrequency);
			this->splitContainer1->Panel2->Controls->Add(this->numericUpDownMorseCharacterIndex);
			this->splitContainer1->Panel2->Controls->Add(this->label3);
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Panel2->Controls->Add(this->trackBarVolume);
			this->splitContainer1->Panel2->Controls->Add(this->buttonPause);
			this->splitContainer1->Panel2->Controls->Add(this->Speed);
			this->splitContainer1->Panel2->Controls->Add(this->trackBarSpeed);
			this->splitContainer1->Panel2->Controls->Add(this->checkBoxLoop);
			this->splitContainer1->Panel2->Controls->Add(this->buttonStop);
			this->splitContainer1->Panel2->Controls->Add(this->buttonStart);
			this->splitContainer1->Size = System::Drawing::Size(498, 446);
			this->splitContainer1->SplitterDistance = 215;
			this->splitContainer1->SplitterWidth = 8;
			this->splitContainer1->TabIndex = 2;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->richTextBox);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->richTextBoxMCode);
			this->splitContainer2->Size = System::Drawing::Size(498, 215);
			this->splitContainer2->SplitterDistance = 92;
			this->splitContainer2->SplitterWidth = 8;
			this->splitContainer2->TabIndex = 0;
			// 
			// richTextBox
			// 
			this->richTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox->Location = System::Drawing::Point(0, 0);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->Size = System::Drawing::Size(498, 92);
			this->richTextBox->TabIndex = 1;
			this->richTextBox->Text = L"sos ";
			this->richTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox_TextChanged);
			this->richTextBox->Enter += gcnew System::EventHandler(this, &Form1::richTextBox_Enter);
			this->richTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::richTextBox_KeyUp);
			this->richTextBox->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &Form1::richTextBox_Layout);
			this->richTextBox->Move += gcnew System::EventHandler(this, &Form1::richTextBox_Move);
			// 
			// richTextBoxMCode
			// 
			this->richTextBoxMCode->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxMCode->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxMCode->Location = System::Drawing::Point(0, 0);
			this->richTextBoxMCode->Name = L"richTextBoxMCode";
			this->richTextBoxMCode->ReadOnly = true;
			this->richTextBoxMCode->Size = System::Drawing::Size(498, 115);
			this->richTextBoxMCode->TabIndex = 0;
			this->richTextBoxMCode->Text = L"";
			this->richTextBoxMCode->SelectionChanged += gcnew System::EventHandler(this, &Form1::richTextBoxMCode_SelectionChanged);
			this->richTextBoxMCode->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBoxMCode_TextChanged);
			this->richTextBoxMCode->Enter += gcnew System::EventHandler(this, &Form1::richTextBoxMCode_Enter);
			this->richTextBoxMCode->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::richTextBoxMCode_KeyPress);
			this->richTextBoxMCode->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::richTextBoxMCode_KeyUp);
			// 
			// numericUpDownChannels
			// 
			this->numericUpDownChannels->Enabled = false;
			this->numericUpDownChannels->Location = System::Drawing::Point(120, 103);
			this->numericUpDownChannels->Name = L"numericUpDownChannels";
			this->numericUpDownChannels->Size = System::Drawing::Size(68, 20);
			this->numericUpDownChannels->TabIndex = 23;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(65, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Channels";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 80);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Frequency";
			// 
			// numericUpDownFrequency
			// 
			this->numericUpDownFrequency->Enabled = false;
			this->numericUpDownFrequency->Location = System::Drawing::Point(119, 78);
			this->numericUpDownFrequency->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDownFrequency->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericUpDownFrequency->Name = L"numericUpDownFrequency";
			this->numericUpDownFrequency->Size = System::Drawing::Size(69, 20);
			this->numericUpDownFrequency->TabIndex = 20;
			this->numericUpDownFrequency->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownFrequency_ValueChanged);
			// 
			// numericUpDownMorseCharacterIndex
			// 
			this->numericUpDownMorseCharacterIndex->Location = System::Drawing::Point(119, 53);
			this->numericUpDownMorseCharacterIndex->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDownMorseCharacterIndex->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDownMorseCharacterIndex->Name = L"numericUpDownMorseCharacterIndex";
			this->numericUpDownMorseCharacterIndex->Size = System::Drawing::Size(69, 20);
			this->numericUpDownMorseCharacterIndex->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 55);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Morse Character Index";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(338, 24);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Volume";
			// 
			// trackBarVolume
			// 
			this->trackBarVolume->Location = System::Drawing::Point(391, 18);
			this->trackBarVolume->Maximum = 100;
			this->trackBarVolume->Name = L"trackBarVolume";
			this->trackBarVolume->Size = System::Drawing::Size(104, 45);
			this->trackBarVolume->TabIndex = 15;
			this->trackBarVolume->Value = 2;
			this->trackBarVolume->Scroll += gcnew System::EventHandler(this, &Form1::trackBarVolume_Scroll);
			// 
			// buttonPause
			// 
			this->buttonPause->Enabled = false;
			this->buttonPause->Location = System::Drawing::Point(84, 14);
			this->buttonPause->Name = L"buttonPause";
			this->buttonPause->Size = System::Drawing::Size(75, 23);
			this->buttonPause->TabIndex = 12;
			this->buttonPause->Text = L"Pause";
			this->buttonPause->UseVisualStyleBackColor = true;
			this->buttonPause->Click += gcnew System::EventHandler(this, &Form1::buttonPause_Click);
			// 
			// Speed
			// 
			this->Speed->AutoSize = true;
			this->Speed->Location = System::Drawing::Point(295, 73);
			this->Speed->Name = L"Speed";
			this->Speed->Size = System::Drawing::Size(85, 13);
			this->Speed->TabIndex = 4;
			this->Speed->Text = L"Playback Speed";
			this->Speed->Click += gcnew System::EventHandler(this, &Form1::Speed_Click);
			// 
			// trackBarSpeed
			// 
			this->trackBarSpeed->Location = System::Drawing::Point(391, 73);
			this->trackBarSpeed->Minimum = 1;
			this->trackBarSpeed->Name = L"trackBarSpeed";
			this->trackBarSpeed->Size = System::Drawing::Size(104, 45);
			this->trackBarSpeed->TabIndex = 3;
			this->trackBarSpeed->Value = 1;
			this->trackBarSpeed->Scroll += gcnew System::EventHandler(this, &Form1::trackBarSpeed_Scroll);
			this->trackBarSpeed->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBarSpeed_ValueChanged);
			// 
			// checkBoxLoop
			// 
			this->checkBoxLoop->AutoSize = true;
			this->checkBoxLoop->Checked = true;
			this->checkBoxLoop->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxLoop->Location = System::Drawing::Point(246, 18);
			this->checkBoxLoop->Name = L"checkBoxLoop";
			this->checkBoxLoop->Size = System::Drawing::Size(50, 17);
			this->checkBoxLoop->TabIndex = 2;
			this->checkBoxLoop->Text = L"Loop";
			this->checkBoxLoop->UseVisualStyleBackColor = true;
			this->checkBoxLoop->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxLoop_CheckedChanged);
			this->checkBoxLoop->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &Form1::checkBoxLoop_Layout);
			// 
			// buttonStop
			// 
			this->buttonStop->Enabled = false;
			this->buttonStop->Location = System::Drawing::Point(165, 14);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(75, 23);
			this->buttonStop->TabIndex = 1;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &Form1::buttonStop_Click);
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(3, 14);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(75, 23);
			this->buttonStart->TabIndex = 0;
			this->buttonStart->Text = L"Play";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &Form1::buttonStart_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Text Files|*.txt";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(498, 492);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Form1";
			this->Text = L"Morse Code Project";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownChannels))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFrequency))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMorseCharacterIndex))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarVolume))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpeed))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e)
		 {
		    try
			{
			  if (richTextBoxMCode != nullptr)
              {
				  if (richTextBoxMCode->Text != nullptr)
				  {
					  if (richTextBoxMCode->Text->Length == 0)
					  {
						  MessageBox::Show("No message to send.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					  }
					  else
					  {
						  if (soundThread != nullptr)
						  {
							  if (soundClass != nullptr)
							  {
								  soundClass->m_bQuitThread = true;
							  }
						  }

						  richTextBoxMCode->Select();
						  if (soundThread != nullptr)
						  {
							  while (soundThread->IsAlive)
							  {
								  soundClass->Resume();
								  soundClass->m_bQuitThread = true;
								  soundClass->m_bThreadLooping = false;
								  soundClass->Stop();
							  }
						  }

						  soundClass->SetMessage(richTextBoxMCode->Text);
						  soundClass->m_bQuitThread = false;
						  soundClass->m_bPaused = false;

						  soundClass->SetVolume((float)(trackBarVolume->Value / 100.0));

						  buttonStart->Enabled = false;
						  buttonPause->Enabled = true;
						  buttonStop->Enabled = true;

						  soundThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(soundClass, &SoundClass::ThreadProc));
						  if (soundThread != nullptr) 
						  {
							  soundThread->Start();
							  soundThread->IsBackground = true;
						  }
						  //MessageBox::Show("123", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);


						  //soundClass->SetVolume((float)(trackBarVolume->Value / 100.0));
					  }

				  }
			  }

			}
			catch( System::Exception^ e )
			{
			   MessageBox::Show( e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			   return;
			}
		 }
private: System::Void buttonStop_Click(System::Object^  sender, System::EventArgs^  e)
		 {
	        if(soundClass!=nullptr)
			{
				//if (soundClass->mutex != nullptr)
				//{
					//soundClass->mutex->WaitOne();
					//soundClass->Stop();
					soundClass->m_bQuitThread = true;
					//soundClass->mutex->ReleaseMutex();
				//}
			}
		 }
private: System::Void checkBoxLoop_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		 {
            if (soundClass != nullptr)
	        {
				soundClass->m_bLoop = checkBoxLoop->Checked;
            }
		 }
private: System::Void trackBarSpeed_Scroll( System::Object^  sender, System::EventArgs^ e )
		 {
			if (soundClass != nullptr)
			{
				float frequency = soundClass->m_defaultFrequency * (float)trackBarSpeed->Value;
				soundClass->SetFrequency( frequency );				
			}
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 AboutDialog^ ad = gcnew AboutDialog();
			 ad->ShowDialog();
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->Close();
		 }
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			try
			{
			   if( openFileDialog->ShowDialog() == ::DialogResult::OK )
			   {
			      richTextBox->LoadFile( openFileDialog->FileName, RichTextBoxStreamType::PlainText );
			      richTextBoxMCode->Text = mCode->ConvertToMorseCode( richTextBox->Text );
			   }
			}
			catch( System::Exception^ e )
			{
			   MessageBox::Show( e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			   return;
			}
		 }
private: System::Void codesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 CodeDialog^ cd = gcnew CodeDialog();
			 cd->ShowDialog();
		 }
private: System::Void richTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
	        if(mCode!=nullptr)
			{
				richTextBoxMCode->Text = mCode->ConvertToMorseCode(richTextBox->Text);
			}
		    
			if (soundClass != nullptr)
			{
			   soundClass->SetMessage( richTextBoxMCode->Text );
			}
		 }
private: System::Void buttonPause_Click( System::Object^  sender, System::EventArgs^ e )
		 {
			if (soundClass!=nullptr)
			{
		       soundClass->Pause();
			   //soundClass->m_bPaused = true;
			}
		 }
private: System::Void richTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		 {
		    richTextBoxMCode->Text = mCode->ConvertToMorseCode( richTextBox->Text );
		 }
private: System::Void richTextBoxMCode_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		 {
		    richTextBox->Text = mCode->ConvertToAscii( richTextBoxMCode->Text );
		 }
private: System::Void richTextBoxMCode_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 wchar_t c = e->KeyChar;
			 if( !mCode->IsMorse( c ) )
			 {
				if( !c.IsControl( c ) )
				{
					System::Console::Beep();
					e->Handled = true;
				}
			 }
		 }
private: System::Void richTextBox_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
				richTextBox->ReadOnly = false;
				richTextBoxMCode->ReadOnly = true;
		 }
private: System::Void richTextBoxMCode_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
				richTextBox->ReadOnly = true;
				richTextBoxMCode->ReadOnly = false;
		 }
private: System::Void richTextBoxMCode_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 if( richTextBoxMCode->Text->Length > 0 )
			 {
				wchar_t c = richTextBoxMCode->Text[ richTextBoxMCode->Text->Length-1 ];
			    if( !mCode->IsMorse( c ) && !c.IsControl( c ) )
			    {
			       System::String^ text = gcnew System::String( "" );
			       text = richTextBoxMCode->Text;
			       richTextBoxMCode->Text = "";
			       richTextBoxMCode->Text += mCode->StripNonMorseCharacters( text );
			       richTextBox->Text = mCode->ConvertToAscii( richTextBoxMCode->Text );
			    }
			 }
		 }
private: System::Void trackBarVolume_Scroll(System::Object^  sender, System::EventArgs^  e)
		 {
	        if(soundClass!=nullptr)
	        {
				soundClass->SetVolume((float)(trackBarVolume->Value / 100.0));
			}
		 }
private: System::Void richTextBoxMCode_SelectionChanged(System::Object^  sender, System::EventArgs^  e)
		 {
	         if (numericUpDownMorseCharacterIndex != nullptr) 
	         {
				 numericUpDownMorseCharacterIndex->Value = richTextBoxMCode->SelectionStart;
	         }
		 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
		 {
			if (soundClass != nullptr)
			{
				soundClass->m_bQuitThread = true;
			}
		 }
private: System::Void numericUpDownFrequency_ValueChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			if (soundClass != nullptr)
			{
					soundClass->SetFrequency((float)numericUpDownFrequency->Value);
			}
		 }
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBarSpeed_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (soundClass != nullptr)
	{
		//soundClass->SetFrequency((float)numericUpDownFrequency->Value);
	}

}
private: System::Void Speed_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox_Move(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void richTextBox_Layout(System::Object^ sender, System::Windows::Forms::LayoutEventArgs^ e)
{
	if (mCode != nullptr)
	{
		richTextBoxMCode->Text = mCode->ConvertToMorseCode(richTextBox->Text);
	}

	if (soundClass != nullptr)
	{
		soundClass->SetMessage(richTextBoxMCode->Text);
	}
}
private: System::Void checkBoxLoop_Layout(System::Object^ sender, System::Windows::Forms::LayoutEventArgs^ e)
{
	if (soundClass != nullptr)
	{
		soundClass->m_bLoop = checkBoxLoop->Checked;
	}
}
};
}
