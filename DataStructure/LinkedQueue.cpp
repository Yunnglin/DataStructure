#include "pch.h"
#include "LinkedQueue.h"
using namespace std;

LinkedQueue::LinkedQueue()
{
	this->front = NULL;
	this->rear = NULL;
}


LinkedQueue::~LinkedQueue()
{
}

void LinkedQueue::DestroyQueue() {
	Node* pre = this->front, *p;
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

bool LinkedQueue::QueueEmpty() {
	return (this->rear == NULL);
}

void LinkedQueue::enQueue(ElemType e) {
	Node* p = new Node();
	p->data = e;
	p->next = NULL;
	if (this->rear == NULL) {
		this->front = this->rear = p;//����Ϊ�գ��½����Ƕ���Ҳ�Ƕ�β
	}
	else {
		this->rear->next = p;//���p������β����rearָ����
		this->rear = p;
	}
}

bool LinkedQueue::deQueue(ElemType &e) {
	Node* t;
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

void LinkedQueue::Display() {
	Node* pre = this->front;
	if (pre == NULL)
		return;
	while (pre != NULL) {
		cout << pre->data << endl;
		pre = pre->next;
	}
}