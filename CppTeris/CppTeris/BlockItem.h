#pragma once
#include<stdio.h>
#include <stdlib.h>  

#define ROWS 25
#define COLS 15
ref class BlockItem
{
public:
	BlockItem();
	bool ExportBlock();
private:
	int *block = NULL;
	int cur_left, cur_top;      
	int width_block, height_block; 
};

bool BlockItem::ExportBlock(){
	//输出方块
	{
		int sel;
		if (block)
		{
			delete(block);    //释放之前分配的内存
			block = NULL;
		}

		sel = rand() % 7;
		switch (sel)
		{
		case 0:     //水平条
			width_block = 4;
			height_block = 1;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //可以理解为*(block+0*width_block+0)=1，即第一行的第一个方格，下面同理
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+0*width_block+3)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 1:     //三角
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //可以理解为*(block+0*width_block+0)=0，即第一行的第一个方格，下面同理
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 1;       //*(block+1*width_block+0)=1，第二行开始
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 2:     //左横折
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //可以理解为*(block+0*width_block+0)=1，下面同理
			*(block + 1) = 0;       //*(block+0*width_block+1)=0
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 3:     //右横折
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //可以理解为*(block+0*width_block+0)=0，下面同理
			*(block + 1) = 0;       //*(block+0*width_block+1)=0
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 4:     //左闪电
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //可以理解为*(block+0*width_block+0)=1，下面同理
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 0;       //*(block+1*width_block+0)=0
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 5:     //右闪电
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //可以理解为*(block+0*width_block+0)=0，下面同理
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 0;       //*(block+1*width_block+2)=0

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 6:     //石头
			width_block = 2;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //可以理解为*(block+0*width_block+0)=1，下面同理
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 1;       //*(block+1*width_block+0)=1
			*(block + 3) = 1;       //*(block+1*width_block+1)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		}
		return block != NULL;
	}
}

