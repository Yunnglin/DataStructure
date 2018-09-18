#include "pch.h"
#include "PrimeCount.h"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

PrimeCount::PrimeCount()
{
	n = 0;
}


PrimeCount::~PrimeCount()
{
}

void PrimeCount::setCount(long n) {
	this->n=n;
}


bool PrimeCount::prime1(long n) {//方法1计算素数
	long i;
	for (i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void PrimeCount::PrimeTime1(long n) {
	clock_t t;
	int sum = 0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime1(i))
			sum++;
	t = clock() - t;
	cout << "funtion1" << endl;
	cout << "素数个数" << sum << "time: " << ((float)t) / CLOCKS_PER_SEC << endl;
}

bool PrimeCount::prime2(long n) {//方法2计算素数
	long i;
	for (i = 2; i <= (int)sqrt(n); i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void PrimeCount::PrimeTime2(long n) {
	clock_t t;
	int sum = 0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime2(i))
			sum++;
	t = clock() - t;
	cout << "funtion2" << endl;
	cout << "素数个数" << sum << "time: " << ((float)t) / CLOCKS_PER_SEC << endl;
}
