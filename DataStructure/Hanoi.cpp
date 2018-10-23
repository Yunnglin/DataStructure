#include "pch.h"
#include "Hanoi.h"
using namespace std;

Hanoi::Hanoi()
{
}


Hanoi::~Hanoi()
{
}

void Hanoi::Hanoi1(int n, char X, char Y, char Z) {//将问题递归分解
	if (n == 1)
		cout << "将第" << n << "个盘片从" << X << "移动到" << Z << endl;
	else {
		Hanoi1(n - 1, X, Z, Y);
		cout << "将第" << n << "个盘片从" << X << "移动到" << Z << endl;
		Hanoi1(n - 1, Y, X, Z);
	}
}
