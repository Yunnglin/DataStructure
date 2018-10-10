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
	int i = 0;//��Ϊpostexp ���±�
	while (*exp != '\0') {//���ʽδɨ�����
		switch (*exp)
		{
		case '(':
			optr->Push('(');
			exp++;
			break;

		case ')':
			optr->Pop(e);//ֱ�ӳ�ջ�����س�ջԪ��
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
				if (e != '(') {//ջ����* /,��ջ
					postexp[i++] = e;
					optr->Pop(e);
				}
				else {
					break;//ֱ��ջ����������ȼ�Сʱ����
				}
			}
			optr->Push(*exp);
			exp++;
			break;

		case '*':
		case '/':
			while (!optr->StackEmpty()) {
				optr->GetTop(e);
				if (e =='*'||e=='/') {//ջ����* /,��ջ
					postexp[i++] = e;
					optr->Pop(e);
				}
				else {
					break;//ֱ��ջ����������ȼ�Сʱ����
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

	while (!optr->StackEmpty()) {//ɨ����ɺ����γ�ջ
		optr->Pop(e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';
	//optr->DestroyStack();
}

template<class ElemType>
double SqStack<ElemType>::CompValue(char* postexp) {
	double a, b, c, d, e;
	SqStack<ElemType>* opnd = this;//���������ջ
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
				cout << "������󣡣���" << endl;
				exit(0);
			}
			break;
			
		default://�����ַ�
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