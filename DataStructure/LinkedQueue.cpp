#include "pch.h"
#include "LinkedQueue.h"
using namespace std;
template<class ElemType>
LinkedQueue<ElemType>::LinkedQueue()
{
	this->front = NULL;
	this->rear = NULL;
}

template<class ElemType>
LinkedQueue<ElemType>::~LinkedQueue()
{
}
template<class ElemType>
void LinkedQueue<ElemType>::DestroyQueue() {
	Node<ElemType>* pre = this->front, *p;
	if (pre != NULL) {
		p = pre->next;
		while (p != NULL) {
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
	delete this;
}
template<class ElemType>
bool LinkedQueue<ElemType>::QueueEmpty() {
	return (this->rear == NULL);
}
template<class ElemType>
void LinkedQueue<ElemType>::enQueue(ElemType e) {
	Node<ElemType>* p = new Node<ElemType>();
	p->data = e;
	p->next = NULL;
	if (this->rear == NULL) {
		this->front = this->rear = p;//链队为空，新结点既是队首也是队尾
	}
	else {
		this->rear->next = p;//结点p链到队尾并将rear指向它
		this->rear = p;
	}
}
template<class ElemType>
bool LinkedQueue<ElemType>::deQueue(ElemType &e) {
	Node<ElemType>* t;
	if (this->rear == NULL)
		return false;
	t = this->front;
	if (this->rear == this->front)
		this->rear = this->front = NULL;
	else
		this->front = this->front->next;
	e = t->data;
	delete t;
	return true;
}
template<class ElemType>
void LinkedQueue<ElemType>::Display() {
	Node<ElemType>* pre = this->front;
	if (pre == NULL)
		return;
	while (pre != NULL) {
		cout << pre->data << endl;
		pre = pre->next;
	}
}