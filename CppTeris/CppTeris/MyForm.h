#pragma once
#include<array>
#include<iostream>
#define CELL 20
#define ROWS 25
#define COLS 15
namespace CppTeris {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private:Bitmap^ bitmap;
	private:Pen^ pen = gcnew Pen(Color::Gray, 1);
	private:SolidBrush^ solidBrush = gcnew SolidBrush(Color::Red);
	private:Graphics^ g;
	private:System::Drawing::Brush^ brush;
	private: System::Windows::Forms::PictureBox^  drawMap;
	private: array<int,2>^ H = gcnew array<int, 2>(ROWS+1, COLS+1);;
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
			this->drawMap = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->drawMap))->BeginInit();
			this->SuspendLayout();
			// 
			// drawMap
			// 
			this->drawMap->BackColor = System::Drawing::SystemColors::Control;
			this->drawMap->Location = System::Drawing::Point(0, 0);
			this->drawMap->Name = L"drawMap";
			this->drawMap->Size = System::Drawing::Size(362, 537);
			this->drawMap->TabIndex = 0;
			this->drawMap->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 557);
			this->Controls->Add(this->drawMap);
			this->Enabled = false;
			this->Name = L"MyForm";
			this->Text = L"Tetris";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->drawMap))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		bitmap = gcnew Bitmap(drawMap->Width, drawMap->Height);
		drawMap->Image = bitmap;
		g = Graphics::FromImage(bitmap);
		for (int k = 0; k < ROWS; k++) {
		//	H[k] = gcnew array < int >(COLS+2) ;
			for (int l = 0; l < COLS ; l++)
				H[k,l] = 0;

		}
		for (int y = 0; y<ROWS; y++)
		{
			for (int x = 0; x<COLS; x++)
			{
				g->DrawRectangle(pen, x*CELL + 2, y*CELL + 2, CELL - 4, CELL - 4);
			///	g->FillRectangle(solidBrush, x*CELL + 2, y*CELL + 2, CELL - 4, CELL - 4);
			}
		}
	//	for (int r = 0; r < H->Length; r++) std::cout << H[0] <<std:: endl;
		
		
	}
	
	};
}
