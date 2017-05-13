#pragma once
#include<array>
#include<iostream>
#include<time.h>
#include "BlockItem.h"
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
	private:SolidBrush^ solidBrush = gcnew SolidBrush(Color::Brown);
	private:Graphics^ g;
	private:System::Drawing::Brush^ brush;
	private: System::Windows::Forms::PictureBox^  drawMap;
	private: array<int,2>^ H = gcnew array<int, 2>(ROWS+1, COLS+1);
	private: BlockItem* blockItem;
	private:int Cur_Row;
	private:int Cur_Col;
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
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->drawMap))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Cur_Row = 0;
		for (int k = 0; k < ROWS; k++) {
			//	H[k] = gcnew array < int >(COLS+2) ;
			for (int l = 0; l < COLS; l++)
				H[k, l] = 0;

		}
		blockItem = new BlockItem();
		blockItem->ExportBlock();
		for (int i = 0; i < blockItem->getHeight_block(); i++){
			for (int j = 0; j < blockItem->getWidth_block(); j++)
			{
				if (*(blockItem->getBlock() + i*blockItem->getWidth_block() + j)) H[i, blockItem->getCur_left() + j] = 1;
			}
		}
		bitmap = gcnew Bitmap(drawMap->Width, drawMap->Height);
		drawMap->Image = bitmap;
		g = Graphics::FromImage(bitmap);
		for (int y = 0; y<ROWS; y++)
		{
			for (int x = 0; x < COLS; x++)
			{
				g->DrawRectangle(pen, x*CELL + 2, y*CELL + 2, CELL - 4, CELL - 4);
			}
					
		}
		
	
	}
	private: void rePaint(){
		bitmap = gcnew Bitmap(drawMap->Width, drawMap->Height);
		drawMap->Image = bitmap;
		g = Graphics::FromImage(bitmap);
		for (int y = 0; y<ROWS; y++)
		{
			for (int x = 0; x<COLS; x++)
			{
				if (H[y, x]) g->FillRectangle(solidBrush, x*CELL + 2, y*CELL + 2, CELL - 4, CELL - 4);
				else
					g->DrawRectangle(pen, x*CELL + 2, y*CELL + 2, CELL - 4, CELL - 4);
			}

		}
	     
	}
	private: void ShiftDown(){
		int temp= blockItem->getHeight_block();
		
		
			for (int j = 0; j < COLS; j++){
				int k = temp;
				while (k >=0){
					H[Cur_Row + temp + k, j] = H[Cur_Row + k, j];
					H[Cur_Row + k, j] = 0;
					k--;
				}
				
			}
			
			Cur_Row = Cur_Row + temp;
		}
		
		
	
	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		ShiftDown();
		rePaint();
	}
};
}
