#include "pch.h"
#include "CirQueue.h"

template<class T>
CirQueue<T>::CirQueue()
{
	this->front = 0;
	this->rear = 0;
}

template<class T>
CirQueue<T>::~CirQueue()
{
}

template<class T>
void CirQueue<T>::Destroy() {
	delete this;
}

template<class T>
bool CirQueue<T>::IsEmpty() {
	return (this->front == this->rear);
}

template<class T>
bool CirQueue<T>::deQueue(T &e) {
	if (this->front == this->rear)
		return false;
	this->front = (this->front + 1) % CirMaxSize;
	e = this->data[this->front];
	return true;
}

template<class T>
bool CirQueue<T>::enQueue(T e) {
	if ((this->rear+1)%CirMaxSize==this->front)
		return false;
	this->rear=(this->rear+1)%CirMaxSize;
	this->data[this->rear] = e;
	return true;
}