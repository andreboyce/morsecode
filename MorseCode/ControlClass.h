#pragma once

using namespace System::Windows::Forms;

public ref class ControlClass
{

public:
	System::Windows::Forms::Button^        buttonStop;
	System::Windows::Forms::Button^        buttonStart;
	System::Windows::Forms::Button^        buttonPause;
	System::Windows::Forms::RichTextBox^   richTextBoxMCode;
	System::Windows::Forms::NumericUpDown^ numericUpDownFrequency;
	System::Windows::Forms::NumericUpDown^ numericUpDownChannels;
	System::Windows::Forms::TrackBar^      trackBarSpeed;
	System::Windows::Forms::TrackBar^      trackBarVolume;
    System::Windows::Forms::CheckBox^      checkBoxLoop;

	ControlClass()
	{
		buttonStop             = nullptr;
		buttonStart            = nullptr;
		buttonPause            = nullptr;
		richTextBoxMCode       = nullptr;
		numericUpDownFrequency = nullptr;
		numericUpDownChannels  = nullptr;
		trackBarSpeed          = nullptr;
		trackBarVolume         = nullptr;
		checkBoxLoop           = nullptr;
	}

	~ControlClass()
	{
	}

	void SetRange(TrackBar^ tb, int min, int max, int pos)
	{
		if (tb == nullptr)
		{
			HandleError("SetRange nllptr");
			return;
		}

		tb->Minimum = min;
		tb->Maximum = max;
		tb->Value   = pos;
	}

	void SetText(Control^ control, System::String^ text)
	{
		if (control == nullptr)
		{
			HandleError("SetText nllptr");
			return;
		}

		control->Text = text;
	}

	void SetNumericUpDownValue(NumericUpDown^ numericUpDown, int value)
	{
		if (numericUpDown == nullptr)
		{
			HandleError("SetNumericUpDownValue nllptr");
			return;
		}

		if( value <= numericUpDown->Maximum )
		{
			numericUpDown->Value = value;
		}
	}

	void SetCheckBoxValue( CheckBox^ checkBox, bool value)
	{
		if (checkBox == nullptr)
		{
			HandleError("SetCheckBoxValue nllptr");
			return;
		}
		checkBox->Checked = value;
	}

	void SelectControl(Control^ control)
	{
		if (control == nullptr)
		{
			HandleError("SelectControl nllptr");
			return;
		}

		control->Select();
	}

	void SelectText(TextBoxBase^ tbb, int start, int length)
	{
		if (tbb == nullptr)
		{
			HandleError("SelectText nllptr");
			return;
		}
		tbb->Select(start, length);
	}

	void EnableControl(Control^ control)
	{
		if (control == nullptr)
		{
			HandleError("EnableControl nllptr");
			return;
		}
		control->Enabled = true;
	}

	void DisableControl(Control^ control)
	{
		if (control == nullptr)
		{
			HandleError("DisableControl nllptr");
			return;
		}
		control->Enabled = false;
	}

	void HandleError(System::String^ str)
	{
		MessageBox::Show(str, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	delegate void SetTextDelegate(Control^ control, System::String^ text);
	delegate void SelectControlDelegate(Control^ control);
	delegate void EnableControlDelegate(Control^ control);
	delegate void DisableControlDelegate(Control^ control);
	delegate void SelectTextDelegate(TextBoxBase^ tbb, int start, int length);
	delegate void SetNumericUpDownValueDelegate(NumericUpDown^ numericUpDown, int value);
	delegate void SetCheckBoxValueDelegate( CheckBox^ checkBox, bool value);
	delegate void SetRangeDelegate(TrackBar^ tb, int min, int max, int pos);

	void InvokeSetRange(TrackBar^ tb, int min, int max, int pos)
	{
		try
		{
			if (tb == nullptr)
			{
				HandleError("InvokeSetRange nllptr");
				return;
			}

			if (tb->Created)
			{
				SetRangeDelegate^ setRange = gcnew SetRangeDelegate(this, &ControlClass::SetRange);
				tb->Invoke(setRange, tb, min, max, pos);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	void InvokeSetText(Control^ control, System::String^ text)
	{
		try
		{
			if (control == nullptr)
			{
				HandleError("InvokeSetText nllptr");
				return;
			}

			if (control->Created)
			{
				SetTextDelegate^ setText = gcnew SetTextDelegate(this, &ControlClass::SetText);
				control->Invoke(setText, control, text);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	void InvokeSetNumericUpDownValue(NumericUpDown^ numericUpDown, int value)
	{
		try
		{
			if (numericUpDown == nullptr)
			{
				HandleError("InvokeSetNumericUpDownValue nllptr");
				return;
			}

			if (numericUpDown->Created)
			{
				SetNumericUpDownValueDelegate^ setNumericUpDownValue = gcnew SetNumericUpDownValueDelegate(this, &ControlClass::SetNumericUpDownValue);
				numericUpDown->Invoke(setNumericUpDownValue, numericUpDown, value);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	//
	void InvokeSetCheckBoxValue( CheckBox ^checkBox, bool value )
	{
		try
		{
			if (checkBox == nullptr)
			{
				HandleError("InvokeSetCheckBoxValue nllptr");
				return;
			}

			if (checkBox->Created)
			{
				SetCheckBoxValueDelegate^ setCheckBoxValue = gcnew SetCheckBoxValueDelegate(this, &ControlClass::SetCheckBoxValue);
				checkBox->Invoke(setCheckBoxValue, checkBox, value);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}


	void InvokeSelect(Control^ control)
	{
		try
		{
			if (control == nullptr)
			{
				HandleError("InvokeSelect nllptr");
				return;
			}

			if (control->Created)
			{
				SelectControlDelegate^ selectControl = gcnew SelectControlDelegate(this, &ControlClass::SelectControl);
				//if( control->CanFocus )
				control->Invoke(selectControl, control);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	void InvokeSelectText(TextBoxBase^ tbb, int start, int length)
	{
		try
		{
			if (tbb == nullptr)
			{
				HandleError("InvokeSelectText nllptr");
				return;
			}

			if (tbb->Created)
			{
				SelectTextDelegate^ selectText = gcnew SelectTextDelegate(this, &ControlClass::SelectText);
				tbb->Invoke(selectText, tbb, start, length);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	void InvokeEnableControl(Control^ control)
	{
		try
		{
			if (control == nullptr)
			{
				HandleError("InvokeEnableControl nllptr");
				return;
			}

			if (control->Created)
			{
				EnableControlDelegate^ enableControl = gcnew EnableControlDelegate(this, &ControlClass::EnableControl);
				//if( control->CanFocus )
				control->Invoke(enableControl, control);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}

	void InvokeDisableControl(Control^ control)
	{
		try
		{
			if (control == nullptr)
			{
				HandleError("InvokeDisableControl nllptr");
				return;
			}

			if (control->Created)
			{
				DisableControlDelegate^ disableControl = gcnew DisableControlDelegate(this, &ControlClass::DisableControl);
				control->Invoke(disableControl, control);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}
};
