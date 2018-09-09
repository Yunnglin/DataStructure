// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

void addTime1(int n);
void addTime2(int n);

bool prime1(long n) {//方法1计算素数
	long i;
	for (i = 2; i < n; i++) {
		if (n%i== 0)
			return false;
	}
	return true;
}

void PrimeTime1(long n) {
	clock_t t;
	int sum=0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime1(i))
			sum++;
	t = clock() - t;
	cout << "funtion1" << endl;
	cout <<"素数个数"<< sum<<"time: " << ((float)t) / CLOCKS_PER_SEC << endl;
}

bool prime2(long n) {//方法2计算素数
	long i;
	for (i = 2; i <= (int)sqrt(n); i++) {
		if (n%i== 0)
			return false;
	}
	return true;
}

void PrimeTime2(long n) {
	clock_t t;
	int sum=0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime2(i))
			sum++;
	t = clock() - t;
	cout << "funtion2" << endl;
	cout << "素数个数" << sum<< "time: " << ((float)t) / CLOCKS_PER_SEC << endl;
}

//连续整数阶乘的和 复杂度为O(n)
long sum(int n) {
	long sum = 0, fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= i;
		sum += fact;
	}
	return sum;
}

int main()
{
	PrimeTime1(23456);
	PrimeTime2(23456);
	//addTime1(10000);
	//addTime2(1000000);
}

int add1(int n) {
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
          sum += j;
		}	
	}
	return sum;
}

void addTime1(int n) {
	clock_t t;
	int sum;
	t = clock();
	sum = add1(n);
	t = clock() - t;
	cout << "funtion1" << endl;
	cout << "time: " << ((float)t) / CLOCKS_PER_SEC<<endl;
}

int add2(int n) {
	return n * (n + 1) / 2;
}
void addTime2(int n) {
	clock_t t;
	int sum;
	t = clock();
	sum = add2(n);
	t = clock() - t;
	cout << "funtion2" << endl;
	cout << "time: " << ((float)t) / CLOCKS_PER_SEC<<endl;
}