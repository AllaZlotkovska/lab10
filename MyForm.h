#pragma once

namespace lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 30);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 315);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"������� � ����� ����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(521, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 49);
			this->button2->TabIndex = 2;
			this->button2->Text = L"���������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(518, 208);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"���� �����, �������� 3";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(503, 312);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(220, 33);
			this->button3->TabIndex = 4;
			this->button3->Text = L"�������� � ����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(575, 248);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1106, 606);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = "numbers.txt";
		if (File::Exists(fname)) {
			StreamReader^ reader = File::OpenText(fname);
			textBox1->Clear();
			String^ fileContent = reader->ReadToEnd();
			array<String^>^ numbers = fileContent->Split(' ');
			for (int i = 0; i < numbers->Length; i++) {
				textBox1->AppendText(numbers[i] + Environment::NewLine); // ��������� �� ��� �������� ������
			}
			reader->Close();
		}
	}
	
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int sum = 0; // ����� ��� ���������� ���� �����, � �� �������
	for (int i = 0; i < textBox1->Lines->Length; i++) {
		int number;
		if (int::TryParse(textBox1->Lines[i], number)) {
			if (number % 3 == 0) {
				sum = sum + number; // ����� ��������� �� ���������� ����
			}
		}
	}
	label2->Text = Convert::ToString(sum); // ��������� ������ ����

}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fileName = "output.txt";
		if (File::Exists(fileName)) {
			MessageBox::Show("���� " + fileName + " ��� ����.");
		}
		else {
			StreamWriter^ writer = File::CreateText(fileName);
			int sum = 0; // ����� ��� ���������� ����
			for (int i = 0; i < textBox1->Lines->Length; i++) {
				int number;
				if (int::TryParse(textBox1->Lines[i], number)) {
					if (number % 3 == 0) {
						sum += number; // ��������� ����� �� ����
						writer->WriteLine(number);
					}
				}
			}
			writer->WriteLine("����: " + Convert::ToString(sum)); // ����� ���� � ����
			writer->Close();
			MessageBox::Show("�����, ������ 3, �� �� ���� ���� �������� � ���� " + fileName);
		}
	}
};
}
