#include "pch.h"
#include "Maze.h"
#include "SqStack.h"
#include "SqStack.cpp"

using namespace std;

Maze::Maze(int i, int j, int di)
{
	this->i = i;
	this->j = j;
	this->di = di;
}

Maze::Maze() {
	this->i = 0;
	this->j = 0;
	this->di = 0;
	this->pre = -1;
}

Maze::~Maze()
{
}

//用栈方法求解迷宫问题
//深度优先搜索算法
bool Maze::MazepathStack(int xi, int yi, int xe, int ye, int* mg, int M, int N) {//路径为从（xi,yi）->(xe,ye)
	Maze path[MazeMaxSize];//定义对象的基本形式，定义时已分配内存，为内存栈
	//Maze *e 未分配内存
	//Maze *e=new Maze();//分配内存，且为堆内存，需手动释放
	int i, j, di, i1, j1, k;
	bool find;
	SqStack<Maze>* st = new SqStack<Maze>();
	Maze e(xi, yi, -1);//设置e为入口
	st->Push(e);
	mg[xi*N + (yi)] = -1;//将迷宫入口值设为-1
	while (!st->StackEmpty()) {
		st->GetTop(e);
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye) {
			cout << "一条迷宫路径如下：" << endl;
			k = 0;
			while (!st->StackEmpty()) {
				st->Pop(e);
				path[k++] = e;
			}
			while (k >= 1) {
				k--;
				cout << "(" << path[k].i << "," << path[k].j << ")  ";
				if ((k + 2) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			st->DestroyStack();
			return true;
		}
		find = false;
		while (di < 4 && !find) {
			di++;
			switch (di) {
			case 0:	i1 = i - 1; j1 = j; break;
			case 1: i1 = i; j1 = j + 1; break;
			case 2: i1 = i + 1; j1 = j; break;
			case 3: i1 = i; j1 = j - 1; break;
			}
			if (mg[i1*N + j1] == 0)//找下一个相邻可走方块
				find = true;
		}
		if (find) {
			st->data[st->top].di = di;
			e.i = i1; e.j = j1; e.di = -1;
			st->Push(e);
			mg[i1*N + j1] = -1;
		}
		else {
			st->Pop(e);
			mg[e.i*N + e.j] = 0;
		}
	}
	st->DestroyStack();
	return false;
}


//用队列方法
//广度优先算法
bool Maze::MazepathQueue(int xi, int yi, int xe, int ye, int* mg, int M, int N) {
	Maze e;
	int i, j, di, i1, j1;
	SeqQueue<Maze>* qu = new SeqQueue<Maze>();
	e.i = xi;
	e.j = yi;
	e.pre = -1;
	qu->enQueue(e);//xi,yi进队
	mg[xi*N + yi] = -1;//赋值为-1，避免重复搜索
	while (!qu->IsEmpty())
	{
		qu->deQueue(e);
		i = e.i;
		j = e.j;
		if (i == xe && j == ye) {
			print(qu, qu->front,xe,ye);
			qu->Destroy();
			return true;
		}
		for (di = 0; di < 4; di++) {
			switch (di) {
			case 0:	i1 = i - 1; j1 = j; break;
			case 1: i1 = i; j1 = j + 1; break;
			case 2: i1 = i + 1; j1 = j; break;
			case 3: i1 = i; j1 = j - 1; break;
			}
			if (mg[i1*N + j1] == 0)//找下一个相邻可走方块
			{
				e.i = i1;
				e.j = j1;
				e.pre = qu->front;
				qu->enQueue(e);
				mg[i1*N + j1] = -1;
			}

		}

	}
	qu->Destroy();
	return false;

}

void Maze::print(SeqQueue<Maze>* qu, int front,int xe,int ye) {
	int k = front, j, ns = 0;
	cout << endl;
	do {
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1;
	} while (k != 0);
	cout << "一条迷宫路径如下: " << endl;//自动输出最短路径
	k = 0;
	while (k < SQMaxSize) {
		if (qu->data[k].pre == -1) {
			ns++;
			cout << "(" << qu->data[k].i << " , " << qu->data[k].j << ")";
			if (qu->data[k].i == xe && qu->data[k].j == ye)
				break;
			if (ns % 5 == 0)
				cout << endl;
		}
		k++;
	}
	cout << endl;

}