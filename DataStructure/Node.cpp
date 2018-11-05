#include "pch.h"
#include "Node.h"
#ifndef _Node_Cpp_
#define _Node_Cpp_


template<class ElemType>
Node<ElemType>::Node() {
	next = NULL;
	data = NULL;
	lchild = NULL;
	rchild = NULL;
}

template<class ElemType>
Node<ElemType>::~Node()
{
}
#endif // !_Node_Cpp_