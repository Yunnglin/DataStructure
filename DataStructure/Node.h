#pragma once
#ifndef _Node_H_
#define _Node_H_ 

template<class ElemType>

class Node {
public:
	ElemType data;
	Node* next;
	Node();
	~Node();
};

#endif // _Node_H_