// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"//必须放在最前面
#include "header.h"

using namespace std;

int main()
{
	/*PrimeCount* prime = new PrimeCount();
	prime->PrimeTime1(10000);*/

	//单链表
	//int a[] = { 1,2,3,4,5 };
	//int e;
	//SinglyLinkedList<int>* L1=new SinglyLinkedList<int>();
	//L1->CreateListR(a, 5);
	//L1->DispList();
	//L1->DestroyList();
	//L1->ListDelete(1, e);
	//L1->DispList();

	//双链表
	//int b[] = { 1,2,3,4,5 };
	//DuLinkedList<int>* L2 = new DuLinkedList<int>();
	//L2->CreateListR(b, 5);
	//L2->DispList();
	//L2->ListInsert(2, 100);
	//L2->DispList();
	//int t;
	//L2->ListDelete(2, t);
	//L2->DispList();
	//L2->ListReverse();
	//L2->DispList();

	//四则运算
	//cout << "请输入要计算的表达式：" << endl;
	//char exp[100] = { '\0' };
	//cin >> exp;
	//SqStack<char>* s = new SqStack<char>();
	//s->Trans(exp, s->postexp);
	//cout << "中缀表达式："<< exp << endl;
	//cout << "后缀表达式："<<s->postexp << endl;
	//SqStack<double>*q = new SqStack<double>();
	//cout << "结果："<<q->CompValue(s->postexp) << endl;
	//s->DestroyStack();
	//q->DestroyStack();

	//LinkedQueue<int>* lq = new LinkedQueue<int>();
	//for (int i = 0; i < 10; i++)
	//{
	//	lq->enQueue(i);
	//}
	//lq->Display();

	//CirQueue<int>* cq =new CirQueue<int>();
	//for (int i = 0; i < 10; i++)
	//{
	//	cq->enQueue(i);
	//}

	//栈处理迷宫路径
	//const int M = 10, N = 10;
	//int mg[M][N] = {
	//{1,1,1,1,1,1,1,1,1,1},
	//{1,0,0,1,0,0,0,1,0,1},
	//{1,0,0,1,0,0,0,1,0,1},
	//{1,0,0,0,0,1,1,0,0,1},
	//{1,0,1,1,1,0,0,0,0,1},
	//{1,0,0,0,1,0,0,0,0,1},
	//{1,0,1,0,0,0,1,0,0,1},
	//{1,0,1,1,1,0,1,1,0,1},
	//{1,1,0,0,0,0,0,0,0,1},
	//{1,1,1,1,1,1,1,1,1,1}
	//};
	//Maze maze;
	////int* mg1 = (int*)mg;//指针强制转化，二维变一维
	//int mg1[M*N] = { 0 };
	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		mg1[i*M + j] = mg[i][j];
	//	}

	//}
	//if (!maze.MazepathStack(1, 1, M - 2, N - 2, mg1, M, N))
	//	cout << "无解" << endl;

	//if (!maze.MazepathQueue(1, 1, M-2, N-2, mg1, M, N))
	//	cout << "无解" << endl;

	//char i[10] = "123";
	//SqString* str = new SqString(i);
	//str->DispStr();

	//Hanoi* h = new Hanoi();
	//h->Hanoi1(10, 'x','y','z');

	//char a[10] = "aaaaaab";
	//char b[10] = "ab";
	//SqString str(a);
	//SqString t(b);

	//cout<<str.KMPIndex(t);

	char s[20] = "A(B(D(,G)),C(E,F))";

	BTNode<char>* b = new BTNode<char>();
	b->CreateBTree(b,s);
	b->DispBTree();
	cout << endl;
	b->PreOrder();
	cout << endl;
	b->InOrder();
	cout << endl;
	b->PostOrder();
	cout << endl;
	b->LevelOrder();
	return 0;
}
