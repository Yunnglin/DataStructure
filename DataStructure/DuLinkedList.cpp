#include "pch.h"
#include "DuLinkedList.h"


using namespace std;

template<class T>
DuLinkedList<T>::DuLinkedList()
{
}

template<class T>
DuLinkedList<T>::~DuLinkedList()
{
}

template<class T>
void DuLinkedList<T>::CreateListF(T a[], int n) {
	DNode<T>* s=new DNode<T>();
	this->header = s;
	s->next = s->prior = NULL;
	for (int i = 0; i < n; i++) {
		DNode<T>* p = new DNode<T>();
		p->data = a[i];
		p->next = s->next;
		if (s->next != NULL) {
			s->next->prior = p;
		}
		s->next = p;
		p->prior = s;
	}
}

template<class T>
void DuLinkedList<T>::CreateListR(T a[], int n) {
	DNode<T>* p = new DNode<T>();
	DNode<T>* r;
	this->header = p;
	p->next = p->prior = NULL;
	r = p;
	for (int i = 0; i < n; i++)
	{
		DNode<T>* q = new DNode<T>();
		q->data = a[i];
		r->next = q;
		q->prior = r;
		r = q;
	}
	r->next = NULL;
}

template<class T>
void DuLinkedList<T>::DispList() {
	if (this == NULL)
		return;
	DNode<T>* p = this->header->next;
	while (p != NULL) {
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}

template<class T>
bool DuLinkedList<T>::ListInsert(int i, T e){
	int j = 0;
	DNode<T>* h = this->header;
	DNode<T>* p;
	if (i <= 0) return false;
	while (j < i-1&&h != NULL) {
		h = h->next;
		j++;
	}
	if (h == NULL)
		return false;
	else {
		p = new DNode<T>();
		p->data = e;
		p->next = h->next;
		if(h->next!=NULL)
			h->next->prior = p;
		h->next = p;
		p->prior = h;
		return true;
	}
}

template<class T>
bool DuLinkedList<T>::ListDelete(int i, T &e) {
	int j = 0;
	DNode<T>* h = this->header;
	DNode<T>* p;
	if (i <= 0) return false;
	while (j < i - 1 && h != NULL) {
		h = h->next;
		j++;
	}
	if (h == NULL)
		return false;
	else {
		p = h->next;
		if (p == NULL)
			return false;
		e = p->data;
		h->next = p->next;
		if (p->next != NULL) {
			p->next->prior = h;
		}
		delete[] p;
		return true;

	}
}

template<class T>
bool DuLinkedList<T>::ListReverse() {
	DNode<T>* h = this->header;
	DNode<T>* p = h->next, * q;
	h->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = h->next;
		if(h->next!=NULL)
			h->next->prior = p;
		h->next = p;
		p->prior = h;
		p = q;
	}
	return true;
}