#pragma once
#ifndef _SinglyLinkedList_H_
#define _SinglyLinkedList_H_
#include "Node.h"
typedef int ElemType;

class SinglyLinkedList//����ͷָ�뼰���ֲ�������
{
public:
	Node* header;
	void CreateListF(ElemType a[], int n);//ͷ�巨
	void CreateListR( ElemType a[], int n);//β�巨
	void DestroyList();//��������
	bool ListEmpty();//�жϱ��Ƿ�Ϊ��
	int ListLength();//����������
	void DispList();//�������
	bool GetElem(int i, ElemType& e);//��ȡĳһԪ�ص�ֵ
	int LocateElem(ElemType e);//��Ԫ�ز���
	bool ListInsert(int i, ElemType e);//����Ԫ��
	bool ListDelete(int i, ElemType &e);//ɾ��Ԫ��

public:
	SinglyLinkedList();
	~SinglyLinkedList();

};
#endif // !_SinglyLinkedList_H_