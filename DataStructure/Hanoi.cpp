#include "pch.h"
#include "Hanoi.h"
using namespace std;

Hanoi::Hanoi()
{
}


Hanoi::~Hanoi()
{
}

void Hanoi::Hanoi1(int n, char X, char Y, char Z) {//������ݹ�ֽ�
	if (n == 1)
		cout << "����" << n << "����Ƭ��" << X << "�ƶ���" << Z << endl;
	else {
		Hanoi1(n - 1, X, Z, Y);
		cout << "����" << n << "����Ƭ��" << X << "�ƶ���" << Z << endl;
		Hanoi1(n - 1, Y, X, Z);
	}
}
