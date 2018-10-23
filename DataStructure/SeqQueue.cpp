#include "pch.h"
#include "SeqQueue.h"
#ifndef _SeqQueue_Cpp_
#define _SeqQueue_Cpp_


template<class T>
SeqQueue<T>::SeqQueue()
{
	//顺序队的front和rear初始化为-1
	this->front = -1;
	this->rear = -1;
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
}

template<class T>
void SeqQueue<T>::Destroy() {
	delete this;
}
template<class T>
bool SeqQueue<T>::IsEmpty() {
	return (this->front == this->rear);
}

template<class T>
bool SeqQueue<T>::enQueue(T e) {
	if (this->rear == SQMaxSize - 1)
		return false;
	this->rear++;
	this->data[this->rear] = e;
	return true;
}

template<class T>
bool SeqQueue<T>::deQueue(T& e) {
	if (this->front == this->rear)
		return false;
	this->front++;
	e = this->data[this->front];
	return true;
}

#endif // !_SeqQueue_Cpp_