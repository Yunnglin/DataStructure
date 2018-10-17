#pragma once
#ifndef  _LinkedQueue_H_
#define _LinkedQueue_H_
#include "Node.h"

class LinkedQueue
{
public :
	Node* front;//ָ����׽��
	Node* rear;//ָ���β���

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