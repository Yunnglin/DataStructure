#pragma once
#ifndef _Maze_H_
#define _Maze_H_
#define MaxSize 100
class Maze
{
public :
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int di;//��һ���ڿ��߷�λ�ķ�λ��

public:
	bool Mazepath(int xi, int yi, int xe, int ye,int* mg,int M,int N);

public:
	Maze();
	Maze(int i, int j, int di);
	~Maze();
};

#endif // !_Maze_H_
