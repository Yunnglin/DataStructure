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

bool Maze::Mazepath(int xi, int yi, int xe, int ye,int* mg,int M,int N) {//路径为从（xi,yi）->(xe,ye)
	Maze path[MaxSize];//定义对象的基本形式，定义时已分配内存，为内存栈
	//Maze *e 未分配内存
	//Maze *e=new Maze();//分配内存，且为堆内存，需手动释放
	int i, j, di, i1, j1, k;
	bool find;
	SqStack<Maze>* st = new SqStack<Maze>();
	Maze e(xi, yi, -1);//设置e为入口
	st->Push(e);
	mg[(xi - 1)*M + (yi - 1)] = -1;//将迷宫入口值设为-1

}