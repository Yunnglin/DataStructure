#include "pch.h"
#include "Maze.h"
#include "SqStack.h"
#include "SqStack.cpp"
#include "LinkedQueue.h"
#include "LinkedQueue.cpp"
using namespace std;

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

//��ջ��������Թ�����
//������������㷨
bool Maze::MazepathStack(int xi, int yi, int xe, int ye,int* mg,int M,int N) {//·��Ϊ�ӣ�xi,yi��->(xe,ye)
	Maze path[MazeMaxSize];//�������Ļ�����ʽ������ʱ�ѷ����ڴ棬Ϊ�ڴ�ջ
	//Maze *e δ�����ڴ�
	//Maze *e=new Maze();//�����ڴ棬��Ϊ���ڴ棬���ֶ��ͷ�
	int i, j, di, i1, j1, k;
	bool find;
	SqStack<Maze>* st = new SqStack<Maze>();
	Maze e(xi, yi, -1);//����eΪ���
	st->Push(e);
	mg[xi*N + (yi)] = -1;//���Թ����ֵ��Ϊ-1
	while (!st->StackEmpty()) {
		st->GetTop(e);
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye) {
			cout << "һ���Թ�·�����£�" << endl;
			k = 0;
			while (!st->StackEmpty()) {
				st->Pop(e);
				path[k++] = e;
			}
			while (k >= 1) {
				k--;
				cout << "(" << path[k].i  << "," <<  path[k].j << ")  ";
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
			if (mg[i1*N + j1] == 0)//����һ�����ڿ��߷���
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


//�ö��з���
//��������㷨
bool Maze::MazepathQueue(int xi, int yi, int xe, int ye, int* mg, int M, int N) {
	Maze e;
	int i, j, di, i1, j1;
}