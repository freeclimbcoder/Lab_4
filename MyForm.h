#pragma once
#include "BT.cpp"
namespace GF4 {
	using namespace BT1;
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
	private: System::Windows::Forms::Button^  buttonSearch;
	protected:
	private: System::Windows::Forms::Button^  buttonBT;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxAtom;



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
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->buttonBT = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxAtom = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonSearch
			// 
			this->buttonSearch->Location = System::Drawing::Point(736, 56);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(146, 36);
			this->buttonSearch->TabIndex = 1;
			this->buttonSearch->Text = L"Поиск";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &MyForm::buttonSearch_Click);
			// 
			// buttonBT
			// 
			this->buttonBT->Location = System::Drawing::Point(736, 98);
			this->buttonBT->Name = L"buttonBT";
			this->buttonBT->Size = System::Drawing::Size(146, 36);
			this->buttonBT->TabIndex = 1;
			this->buttonBT->Text = L"Построить дерево";
			this->buttonBT->UseVisualStyleBackColor = true;
			this->buttonBT->Click += gcnew System::EventHandler(this, &MyForm::buttonBT_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(715, 297);
			this->panel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(733, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите искомый элемент";
			// 
			// textBoxAtom
			// 
			this->textBoxAtom->Location = System::Drawing::Point(736, 30);
			this->textBoxAtom->MaxLength = 1;
			this->textBoxAtom->Name = L"textBoxAtom";
			this->textBoxAtom->Size = System::Drawing::Size(146, 20);
			this->textBoxAtom->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 321);
			this->Controls->Add(this->textBoxAtom);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonBT);
			this->Controls->Add(this->buttonSearch);
			this->Name = L"MyForm";
			this->Text = L"Строитель бинарных деревьев";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		inline void displayBT(binTree b, int theX, int theY, int n, int theX1, int theY1)
		{	// n - уровень узла
			/*ofstream out;
			out.open("output.txt");*/
			Graphics ^panelGraphics = panel1->CreateGraphics();
			if (b != NULL)
			{
				Label^ label = gcnew Label();
				label->Font = gcnew System::Drawing::Font("verdana", 11);
				label->Width = 20;
				label->BackColor = Color::Aqua;
				label->Location = Point(theX1, theY1);
				label->Text = Convert::ToString((wchar_t)RootBT(b));
				panel1->Controls->Add(label);

				if (theX != theX1 && theY != theY1){
					// Draw line to screen.
					panelGraphics->DrawLine(gcnew Pen(Color::Chocolate, 2), Point(theX + 10, theY + 10), Point(theX1 + 10, theY1 + 10));
				}
				n++;
				if (!isNull(Right1(b)))
				{
					displayBT(Right1(b), theX1, theY1, n, theX1 + 150 / n, theY1 + 50);
				}

				if (!isNull(Left1(b)))
				{
					displayBT(Left1(b), theX1, theY1, n, theX1 - 150 / n, theY1 + 50);
				}
			}

		}


	private: System::Void buttonSearch_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ifstream in("input.txt");
		binTree b;
		b = enterBT(in);
		bool f = false;
		if (textBoxAtom->Text->Length != 0)
		{
			base x = Convert::ToChar(textBoxAtom->Text);
			if (search(x, b, f) == true)
				MessageBox::Show("Элемент найден");
			else MessageBox::Show("Элемент не найден");
		}
		else
			MessageBox::Show("Введите элемент для поиска!");


	}
private: System::Void buttonBT_Click(System::Object^  sender, System::EventArgs^  e)
{
	ifstream in("input.txt");
	long file_size;
	in.seekg(0, ios::end);
	file_size = in.tellg();
	if (file_size == 0)
	{
		MessageBox::Show("Файл пуст");
	}
	else{
		ifstream in("input.txt");
		binTree b;
		b = enterBT(in);
		if (b != NULL)
		{

			displayBT(b, 400, 20, 0, 400, 20);
			destroy(b);
		}
	}
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	
}
};
}
