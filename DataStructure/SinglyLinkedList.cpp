#include "pch.h"
#include "SinglyLinkedList.h"
using namespace std;
template<class ElemType>
SinglyLinkedList<ElemType>::SinglyLinkedList()
{
}
template<class ElemType>
SinglyLinkedList<ElemType>::~SinglyLinkedList()
{
}

template<class ElemType>
void SinglyLinkedList<ElemType>::CreateListF(ElemType a[], int n) {//头插法
	Node<ElemType>* p = new Node<ElemType>();
	this->header = p;//头节点
	p->next = NULL;
	for (int i = 0; i < n; i++) {
		Node<ElemType>* q = new Node<ElemType>();
		q->data=a[i];
		q->next = p->next;
		p->next = q;
	}
}

template<class ElemType>
void SinglyLinkedList<ElemType>::CreateListR(ElemType a[], int n) {//尾插法
	Node<ElemType>* p = new Node<ElemType>();
	Node<ElemType>* r;
	this->header = p;
	r = p;
	for (int i = 0; i < n; i++)
	{
		Node<ElemType>* q = new Node<ElemType>();
		q->data = a[i];
		r->next = q;
		r = q;
	}
	r->next = NULL;
}

template<class ElemType>
void SinglyLinkedList<ElemType>::DestroyList() {
	Node<ElemType>* pre = this->header, *p=this->header->next;
	while (p!=NULL)
	{
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
	this->header->next = NULL;
}

template<class ElemType>
bool SinglyLinkedList<ElemType>::ListEmpty() {
	return (this->header->next == NULL);
}

template<class ElemType>
int SinglyLinkedList<ElemType>::ListLength() {
	int n = 0;
	Node<ElemType>* p = this->header;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

template<class ElemType>
void SinglyLinkedList<ElemType>::DispList() {
	if (this== NULL)
		return;
	Node<ElemType>* p = this->header->next;
	while (p != NULL) {
		cout << p->data<<"  " ;
		p = p->next;
	}
	cout << endl;
}

template<class ElemType>
bool SinglyLinkedList<ElemType>::GetElem(int i, ElemType& e) {
	int j = 0;
	Node<ElemType>* p = this->header;
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

template<class ElemType>
int SinglyLinkedList<ElemType>::LocateElem(ElemType e) {
	int i = 1;
	Node<ElemType>* p = this->header->next;
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

template<class ElemType>
bool SinglyLinkedList<ElemType>::ListInsert(int i, ElemType e) {
	int j = 0;
	Node<ElemType>* p = this->header, *s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else {//找到第i-1个节点
		s = new Node<ElemType>();
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

template<class ElemType>
bool SinglyLinkedList<ElemType>::ListDelete(int i, ElemType &e) {
	int j = 0;
	Node<ElemType>* p = this->header, *s;
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