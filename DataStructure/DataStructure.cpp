// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"//必须放在最前面
#include "header.h"

using namespace std;

int main()
{
	/*PrimeCount* prime = new PrimeCount();
	prime->PrimeTime1(10000);*/
	typedef int ElemType;
	ElemType a[] = { 1,2,3,4,5 };
	ElemType e;
	SinglyLinkedList* L1=new SinglyLinkedList();
	L1->CreateListR(a, 5);
	L1->DispList();
	L1->ListDelete(1, e);
	L1->DispList();

	int b[] = { 1,2,3,4,5 };
	DuLinkedList<int>* L2 = new DuLinkedList<int>();
	L2->CreateListR(b, 5);
	L2->DispList();
	
}
