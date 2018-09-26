#include "pch.h"
#include "SinglyLinkedList.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
}

SinglyLinkedList::~SinglyLinkedList()
{
}


void SinglyLinkedList::CreateListF(ElemType a[], int n) {//头插法
	Node* p = new Node();
	this->header = p;//头节点
	p->next = NULL;
	for (int i = 0; i < n; i++) {
		Node* q = new Node();
		q->data=a[i];
		q->next = p->next;
		p->next = q;
	}
}
void SinglyLinkedList::CreateListR(ElemType a[], int n) {//尾插法
	Node* p = new Node();
	Node* r;
	this->header = p;
	r = p;
	for (int i = 0; i < n; i++)
	{
		Node* q = new Node();
		q->data = a[i];
		r->next = q;
		r = q;
	}
	r->next = NULL;
}

void SinglyLinkedList::DestroyList() {
	Node* pre = this->header, *p=this->header->next;
	while (p!=NULL)
	{
		delete[] pre;
		pre = p;
		p = pre->next;
	}
	delete[] pre;
	this->header->next = NULL;
	delete[] this;
}

bool SinglyLinkedList::ListEmpty() {
	return (this->header->next == NULL);
}

int SinglyLinkedList::ListLength() {
	int n = 0;
	Node* p = this->header;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void SinglyLinkedList::DispList() {
	if (this== NULL)
		return;
	Node* p = this->header->next;
	while (p != NULL) {
		cout << p->data<<"  " ;
		p = p->next;
	}
	cout << endl;
}


bool SinglyLinkedList::GetElem(int i, ElemType& e) {
	int j = 0;
	Node* p = this->header;
	if (i <= 0)
		return false;
	while (j < i&&p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {
		e = p->data;
		return true;
	}
}

int SinglyLinkedList::LocateElem(ElemType e) {
	int i = 1;
	Node* p = this->header->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return 0;
	}
	else {
		return i;
	}
}

bool SinglyLinkedList::ListInsert(int i, ElemType e) {
	int j = 0;
	Node* p = this->header, *s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else {//找到第i-1个节点
		s = new Node();
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool SinglyLinkedList::ListDelete(int i, ElemType &e) {
	int j = 0;
	Node* p = this->header, *s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else {//找到第i-1个节点
		s = p->next;
		if (s == NULL)
			return false;
		e = s->data;
		p->next = s->next;
		return true;
	}
}