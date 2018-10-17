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
	void CreateListF(T a[], int n);//ͷ�巨
	void CreateListR(T a[], int n);//β�巨
	void DispList();//���˫������
	bool ListInsert(int i, T e);//������
	bool ListDelete(int i, T &e);//ɾ�����
	bool ListReverse();//����ת
	void DestroyList();//��������

public:
	DuLinkedList();
	~DuLinkedList();
};

#endif // ! _DuLinkedList_H_