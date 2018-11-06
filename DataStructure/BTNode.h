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

	void PreOrder();//先序遍历
	void InOrder();//中序遍历
	void PostOrder();//后序遍历
	void LevelOrder();//层次遍历
public:
	BTNode();
	~BTNode();
};

#endif // !_BTNode_H