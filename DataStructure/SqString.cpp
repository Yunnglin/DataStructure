#include "pch.h"
#include "SqString.h"
using namespace std;

SqString::SqString()
{
	memset(this->data, 0x0,  sizeof(this->data));
}


SqString::~SqString()
{
}

SqString::SqString(char cstr[]) {
	int i;
	memset(this->data, 0x0, sizeof(this->data));
	for (i = 0; cstr[i] != '\0'; i++)
	{
		this->data[i] = cstr[i];
	}
	this->length = i;
}

void SqString::DispStr() {
	int i = 0;
	if (this->length > 0) {
		for (i; i < this->length; i++) {
			cout << this->data[i] << endl;
		}
	}
}

void SqString::GetNext(SqString t, int next[]) {
	int j, k ;
	j = 0; k = -1;//扫描记录t[j]之前与t开头相同的字符隔宿个数
	next[0] = -1;
	while (j < t.length - 1) {
		if (k == -1 || t.data[j] == t.data[k]) {//k为-1或比较字符的相等
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int SqString::KMPIndex(SqString s, SqString t) {
	int next[SStrMaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length&&j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
		if (j >= t.length)
			return (i - t.length);
		else {
			return (-1);
		}
	}
}