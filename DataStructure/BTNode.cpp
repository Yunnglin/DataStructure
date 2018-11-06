#include "pch.h"
#include "BTNode.h"
#include <iostream>
using namespace std;
template<class T>
BTNode<T>::BTNode()
{
	this->lchild = this->rchild = NULL;
	this->data = NULL;
}

template<class T>
BTNode<T>::~BTNode()
{
}

template<class T>
void BTNode<T>::CreateBTree(BTNode*&b, char* str) {
	BTNode<T>* St[1000];
	BTNode<T>* p = new BTNode<T>();
	int top = -1;
	int k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch)
		{
		case '(':top++;
			St[top] = p;
			k = 1;
			break;
		case ')':top--;
			break;
		case',':k = 2;
			break;
		default:
			p = new BTNode<T>();
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;
					break;
				case 2:St[top]->rchild = p;

					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

//template<class T>
//void BTNode<T>::DispBTree(BTNode* b) {
//	if (b != NULL) {
//		cout << b->data;
//		if (b->lchild != NULL || b->rchild != NULL) {
//			cout << "(";
//			DispBTree(b->lchild);
//			if (b->rchild != NULL)
//				cout << ",";
//			DispBTree(b->rchild);
//			cout << ")";
//		}
//	}
//}

template<class T>
void BTNode<T>::DispBTree() {
	BTNode<T>* b = this;
	if (b != NULL) {
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL) {
			cout << "(";
			b->lchild->DispBTree();
			if (b->rchild != NULL)
				cout << ",";
			b->rchild->DispBTree();
			cout << ")";
		}
	}
}

template<class T>
void BTNode<T>::DestroyBTree() {
	if (this != NULL) {
		this->lchild->DestroyBTree();
		this->rchild->DestroyBTree();
		delete this;
	}
}

template<class T>
BTNode<T>* BTNode<T>::FindNode(T x) {
	BTNode<T>* p;
	if (this == NULL)
		return NULL;
	else if (this->data == x) {
		return this;
	}
	else {
		p = this->lchild->FindNode(x);
		if (p != NULL)
			return p;
		p = this->rchild->FindNode(x);
		return p;
	}
}

template<class T>
BTNode<T>* BTNode<T>::LchildNode() {
	return this->lchild;
}

template<class T>
int BTNode<T>::BTHeight() {
	int lchildh = 0;
	int rchildh = 0;
	if (this == NULL)
		return 0;
	else {
		lchildh = this->lchild->BTHeight();
		rchildh = this->rchild->BTHeight();
		return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
	}
}

template<class T>
void BTNode<T>::PreOrder() {
	if (this != NULL) {
		cout << this->data;
		this->lchild->PreOrder();
		this->rchild->PreOrder();
	}
}

template<class T>
void BTNode<T>::InOrder() {
	if (this != NULL) {

		this->lchild->InOrder();
		cout << this->data;
		this->rchild->InOrder();
	}

}

template<class T>
void BTNode<T>::PostOrder() {
	if (this != NULL) {

		this->lchild->PostOrder();
		this->rchild->PostOrder();
		cout << this->data;
	}
}

template<class T>
void BTNode<T>::LevelOrder() {
	BTNode<T>* p;
	SeqQueue<BTNode*>* qu=new SeqQueue<BTNode*>();
	qu->enQueue(this);
	while (qu->IsEmpty() != true) {
		qu->deQueue(p);
		cout << p->data;
		if (p->lchild != NULL) {
			qu->enQueue(p->lchild);
		}
		if (p->rchild != NULL) {
			qu->enQueue(p->rchild);
		}
	}
}