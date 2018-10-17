#pragma once
#ifndef _SqStack_H_
#define _SqStack_H_

constexpr auto MaxSize = 100;

template<class ElemType>

class SqStack
{
public:
	ElemType data[MaxSize];//����Ԫ��
	ElemType postexp[MaxSize];
	int top;//ջ��ָ��

public:
	void DestroyStack();//����ջ
	bool StackEmpty();//ջ�Ƿ�Ϊ��
	bool Push(ElemType e);//��ջ
	bool Pop(ElemType &e);//��ջ
	bool GetTop(ElemType &e);//���ջ��Ԫ��


public:
	void Trans(char *exp, char postexp[]);//����׺���ʽת��Ϊ��׺���ʽ
	double CompValue(char* postexp);//�����׺���ʽ��ֵ

public:
	SqStack();
	~SqStack();
};

#endif // !_SqStack_H_