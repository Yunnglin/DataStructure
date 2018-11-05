#pragma once
#ifndef _BTree_H_
#define _BTree_H_
#include "Node.h"
#include "Node.cpp"
#define BTMaxSize 1000
template<class T>
class BTree
{
public:
	Node<T>* head;

public:
	BTree();
	BTree(char* str);
	~BTree();
};

#endif // !_BTree_H_
