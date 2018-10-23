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

//��ջ��������Թ�����
//������������㷨
bool Maze::MazepathStack(int xi, int yi, int xe, int ye, int* mg, int M, int N) {//·��Ϊ�ӣ�xi,yi��->(xe,ye)
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
	SeqQueue<Maze>* qu = new SeqQueue<Maze>();
	e.i = xi;
	e.j = yi;
	e.pre = -1;
	qu->enQueue(e);//xi,yi����
	mg[xi*N + yi] = -1;//��ֵΪ-1�������ظ�����
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
			if (mg[i1*N + j1] == 0)//����һ�����ڿ��߷���
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
	cout << "һ���Թ�·������: " << endl;//�Զ�������·��
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