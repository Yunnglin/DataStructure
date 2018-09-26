#pragma once
#ifndef _Node_H_
#define _Node_H_ 

typedef int ElemType;


class Node {
public:
	ElemType data;
	Node * next;
	Node();
	~Node();
};

#endif // _Node_H_