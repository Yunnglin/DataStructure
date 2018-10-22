#pragma once
#ifndef  _LinkedQueue_H_
#define _LinkedQueue_H_
#include "Node.h"
#include "Node.cpp"
template<class ElemType>
class LinkedQueue
{
public :
	Node<ElemType>* front;//指向队首结点
	Node<ElemType>* rear;//指向队尾结点

	void DestroyQueue();//销毁队列
	bool QueueEmpty();//判断队列是否为空
	void enQueue(ElemType e);//进队
	bool deQueue(ElemType &e);//出队
	void Display();//显示队列元素

public:
	LinkedQueue();
	~LinkedQueue();
};

#endif // ! _LinkedQueue_H_