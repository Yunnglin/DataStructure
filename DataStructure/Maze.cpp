#include "pch.h"
#include "Maze.h"
#include "SqStack.h"

Maze::Maze(int i,int j ,int di)
{
	this->i = i;
	this->j = j;
	this->di = di;
}

Maze::Maze() {

}

Maze::~Maze()
{
}

bool Maze::Mazepath(int xi, int yi, int xe, int ye,int* mg,int M,int N) {//·��Ϊ�ӣ�xi,yi��->(xe,ye)
	Maze path[MaxSize];//�������Ļ�����ʽ������ʱ�ѷ����ڴ棬Ϊ�ڴ�ջ
	//Maze *e δ�����ڴ�
	//Maze *e=new Maze();//�����ڴ棬��Ϊ���ڴ棬���ֶ��ͷ�
	int i, j, di, i1, j1, k;
	bool find;
	SqStack<Maze>* st = new SqStack<Maze>();
	Maze e(xi, yi, -1);//����eΪ���
	st->Push(e);
	mg[(xi - 1)*M + (yi - 1)] = -1;//���Թ����ֵ��Ϊ-1

}