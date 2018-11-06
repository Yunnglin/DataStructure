#pragma once
#ifndef _BTNode_H
#define _BTNode_H_
#include "SeqQueue.h"
#include "SeqQueue.cpp"

template<class T>
class BTNode
{
public:
	T data;
	BTNode* lchild;
	BTNode* rchild;
	
	void CreateBTree(BTNode*&b,char* str);
	void DispBTree();
	void DestroyBTree();
	BTNode* FindNode(T x);
	BTNode* LchildNode();
	int BTHeight();

	void PreOrder();//�������
	void InOrder();//�������
	void PostOrder();//�������
	void LevelOrder();//��α���
public:
	BTNode();
	~BTNode();
};

#endif // !_BTNode_H