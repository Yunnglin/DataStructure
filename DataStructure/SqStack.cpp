#include "pch.h"
#include "SqStack.h"
using namespace std;
template<class ElemType>
SqStack<ElemType>::SqStack()
{
	this->top = -1;
	memset(this->data, 0x0, sizeof(this->data));
	memset(this->postexp, 0x0, sizeof(this->postexp));
}

template<class ElemType>
SqStack<ElemType>::~SqStack()
{
}
template<class ElemType>
void SqStack<ElemType>::DestroyStack() {
	delete[] this;
}

template<class ElemType>
bool SqStack<ElemType>::StackEmpty() {
	return (this->top == -1);
}

template<class ElemType>
bool SqStack<ElemType>::Push(ElemType e) {
	if (this->top == MaxSize - 1)
		return false;
	else {
		this->top++;
		this->data[this->top] = e;
		return true;
	}
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType &e) {
	if (this->top == -1)
		return false;
	else {
		e = this->data[this->top];
		this->top--;
		return true;
	}
}

template<class ElemType>
bool SqStack<ElemType>::GetTop(ElemType &e){
	if (this->top == -1)
		return false;
	else {
		e = this->data[this->top];
		return true;

	}
}

template<class ElemType>
void SqStack<ElemType>::Trans(char *exp, char postexp[]) {
	char e;
	SqStack<ElemType>* optr = this;
	int i = 0;//作为postexp 的下标
	while (*exp != '\0') {//表达式未扫描完成
		switch (*exp)
		{
		case '(':
			optr->Push('(');
			exp++;
			break;

		case ')':
			optr->Pop(e);//直接出栈并返回出栈元素
			while (e != '(') {
				postexp[i++] = e;
				optr->Pop(e);
			}
			exp++;
			break;

		case '+':
		case '-':
			while (!optr->StackEmpty()) {
				optr->GetTop(e);
				if (e != '(') {//栈顶是* /,出栈
					postexp[i++] = e;
					optr->Pop(e);
				}
				else {
					break;//直到栈顶运算符优先级小时跳出
				}
			}
			optr->Push(*exp);
			exp++;
			break;

		case '*':
		case '/':
			while (!optr->StackEmpty()) {
				optr->GetTop(e);
				if (e =='*'||e=='/') {//栈顶是* /,出栈
					postexp[i++] = e;
					optr->Pop(e);
				}
				else {
					break;//直到栈顶运算符优先级小时跳出
				}
			}
			optr->Push(*exp);
			exp++;
			break;


		default:
			while (*exp >= '0'&&*exp <= '9') {
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';
			break;
		}

	}

	while (!optr->StackEmpty()) {//扫描完成后依次出栈
		optr->Pop(e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';
	//optr->DestroyStack();
}

template<class ElemType>
double SqStack<ElemType>::CompValue(char* postexp) {
	double a, b, c, d, e;
	SqStack<ElemType>* opnd = this;//定义操作数栈
	while (*postexp != '\0') {
		switch (*postexp)
		{
		case '+':
			opnd->Pop(a);
			opnd->Pop(b);
			c = b + a;
			opnd->Push(c);
			break; 
		case '-':
				opnd->Pop(a);
				opnd->Pop(b);
				c = b - a;
				opnd->Push(c);
				break;
		case '*':
			opnd->Pop(a);
			opnd->Pop(b);
			c = b * a;
			opnd->Push(c);
			break;
		case '/':
			opnd->Pop(a);
			opnd->Pop(b);
			if (a != 0) {
				c = b / a;
				opnd->Push(c);
				break;
			}
			else {
				cout << "除零错误！！！" << endl;
				exit(0);
			}
			break;
			
		default://数字字符
			d = 0;
			while (*postexp >= '0'&&*postexp <= '9') {
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			opnd->Push(d);
			break;
		}
		postexp++;
	}
	opnd->GetTop(e);
	//opnd->DestroyStack();
	return e;
}