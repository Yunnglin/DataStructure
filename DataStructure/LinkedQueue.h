#pragma once
#ifndef  _LinkedQueue_H_
#define _LinkedQueue_H_
#include "Node.h"
#include "Node.cpp"

#define LQMaxSize 1000
template<class ElemType>
class LinkedQueue
{
public :
	Node<ElemType>* front;//ָ����׽��
	Node<ElemType>* rear;//ָ���β���
	ElemType data[LQMaxSize];


	void DestroyQueue();//���ٶ���
	bool QueueEmpty();//�ж϶����Ƿ�Ϊ��
	void enQueue(ElemType e);//����
	bool deQueue(ElemType &e);//����
	void Display();//��ʾ����Ԫ��

public:
	LinkedQueue();
	~LinkedQueue();
};

#endif // ! _LinkedQueue_H_