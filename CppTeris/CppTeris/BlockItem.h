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
	//�������
	{
		int sel;
		if (block)
		{
			delete(block);    //�ͷ�֮ǰ������ڴ�
			block = NULL;
		}

		sel = rand() % 7;
		switch (sel)
		{
		case 0:     //ˮƽ��
			width_block = 4;
			height_block = 1;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //�������Ϊ*(block+0*width_block+0)=1������һ�еĵ�һ����������ͬ��
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+0*width_block+3)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 1:     //����
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //�������Ϊ*(block+0*width_block+0)=0������һ�еĵ�һ����������ͬ��
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 1;       //*(block+1*width_block+0)=1���ڶ��п�ʼ
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 2:     //�����
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //�������Ϊ*(block+0*width_block+0)=1������ͬ��
			*(block + 1) = 0;       //*(block+0*width_block+1)=0
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 3:     //�Һ���
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //�������Ϊ*(block+0*width_block+0)=0������ͬ��
			*(block + 1) = 0;       //*(block+0*width_block+1)=0
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 4:     //������
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //�������Ϊ*(block+0*width_block+0)=1������ͬ��
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 0;       //*(block+0*width_block+2)=0
			*(block + 3) = 0;       //*(block+1*width_block+0)=0
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 1;       //*(block+1*width_block+2)=1

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 5:     //������
			width_block = 3;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 0;       //�������Ϊ*(block+0*width_block+0)=0������ͬ��
			*(block + 1) = 1;       //*(block+0*width_block+1)=1
			*(block + 2) = 1;       //*(block+0*width_block+2)=1
			*(block + 3) = 1;       //*(block+1*width_block+0)=1
			*(block + 4) = 1;       //*(block+1*width_block+1)=1
			*(block + 5) = 0;       //*(block+1*width_block+2)=0

			cur_top = 0 - height_block;
			cur_left = (COLS - width_block) / 2;
			break;
		case 6:     //ʯͷ
			width_block = 2;
			height_block = 2;
			block = (int *)malloc(sizeof(int) *width_block*height_block);
			*(block + 0) = 1;       //�������Ϊ*(block+0*width_block+0)=1������ͬ��
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

