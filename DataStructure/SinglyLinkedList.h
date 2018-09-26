#pragma once
#ifndef _SinglyLinkedList_H_
#define _SinglyLinkedList_H_
#include "Node.h"
typedef int ElemType;

class SinglyLinkedList//定义头指针及各种操作函数
{
public:
	Node* header;
	void CreateListF(ElemType a[], int n);//头插法
	void CreateListR( ElemType a[], int n);//尾插法
	void DestroyList();//销毁链表
	bool ListEmpty();//判断表是否为空
	int ListLength();//返回链表长度
	void DispList();//输出链表
	bool GetElem(int i, ElemType& e);//获取某一元素的值
	int LocateElem(ElemType e);//按元素查找
	bool ListInsert(int i, ElemType e);//插入元素
	bool ListDelete(int i, ElemType &e);//删除元素

public:
	SinglyLinkedList();
	~SinglyLinkedList();

};
#endif // !_SinglyLinkedList_H_