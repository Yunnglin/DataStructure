#pragma once
#ifndef  _DuLinkedList_H_
#define _DuLinkedList_H_

template<class T>
class DNode {
public:
	DNode* next;
	DNode* prior;
	T data;
};

template<class T>
class DuLinkedList
{
public:
	DNode<T>* header;
	void CreateListF(T a[], int n);//头插法
	void CreateListR(T a[], int n);//尾插法
	void DispList();//输出双向链表

public:
	DuLinkedList();
	~DuLinkedList();
};

#endif // ! _DuLinkedList_H_