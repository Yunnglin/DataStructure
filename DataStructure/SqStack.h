#pragma once
#ifndef _SqStack_H_
#define _SqStack_H_

constexpr auto MaxSize = 100;

template<class ElemType>

class SqStack
{
public:
	ElemType data[MaxSize];//数据元素
	ElemType postexp[MaxSize];
	int top;//栈顶指针

public:
	void DestroyStack();//销毁栈
	bool StackEmpty();//栈是否为空
	bool Push(ElemType e);//入栈
	bool Pop(ElemType &e);//出栈
	bool GetTop(ElemType &e);//获得栈顶元素


public:
	void Trans(char *exp, char postexp[]);//将中缀表达式转化为后缀表达式
	double CompValue(char* postexp);//计算后缀表达式的值

public:
	SqStack();
	~SqStack();
};

#endif // !_SqStack_H_