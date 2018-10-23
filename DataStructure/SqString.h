#pragma once
#ifndef _SqString_H_
#define _SqString_H_
#define SStrMaxSize 1000

class SqString
{
public:
	char data[SStrMaxSize];
	int length;

public:
	void DispStr();
	void GetNext(SqString t, int next[]);
	int KMPIndex(SqString s, SqString t);

public:
	SqString();
	SqString(char cstr[]);
	~SqString();
};

#endif // !_SqString_H_