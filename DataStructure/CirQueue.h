#pragma once
#ifndef _CirQueue_H_
#define _CirQueue_H_
# define MaxSize  100
template<class T>
class CirQueue
{
public :
	int front;
	int rear;
	T data[MaxSize];
public:
	void Destroy();
	bool IsEmpty();
	bool enQueue(T e);
	bool deQueue(T& e);


public:
	CirQueue();
	~CirQueue();
};

#endif // !_CirQueue_H_