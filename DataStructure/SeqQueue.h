#pragma once
#ifndef _SeqQueue_H_
#define _SeqQueue_H_

#define SQMaxSize 1000
template<class T>

class SeqQueue
{
public:
	int front;
	int rear;
	T data[SQMaxSize];

public:
	void Destroy();
	bool IsEmpty();
	bool enQueue(T e);
	bool deQueue(T& e);



public:
	SeqQueue();
	~SeqQueue();
};

#endif // !_SeqQueue_H_
