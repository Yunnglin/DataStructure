#include "pch.h"
#include "BTree.h"
#ifndef _BTree_Cpp_
#define _BTree_Cpp_
template<class T>
BTree<T>::BTree()
{
	head == NULL;
}

template<class T>
BTree<T>::~BTree()
{
}

template<class T>
BTree<T>::BTree(char * str)
{
	Node<T>* St[BTMaxSize];
	Node<T>* p=new Node<T>();
	int top = -1;
	int k, j = 0;
	char ch;
	this->head = NULL;
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
			p->data = ch;
			if (this->head == NULL)
			{
				this->head = p;
			}
			else
			{
			switch(k)
				{
		case 1:
			St[top]->lchild = p;
			break;
		case 2:
			St[top]->rchild = p;
			break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}


#endif