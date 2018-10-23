#pragma once
#ifndef _Maze_H_
#define _Maze_H_
#define MazeMaxSize 1000
#include "SeqQueue.h"
#include "SeqQueue.cpp"
//template<class T>
class Maze
{
public :
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int pre;//��·������һ�������ڶ����е��±�
	int di;//��һ���ڿ��߷�λ�ķ�λ��
	

public:
	bool MazepathStack(int xi, int yi, int xe, int ye,int* mg,int M,int N);

	bool MazepathQueue(int xi, int yi, int xe, int ye,int* mg, int M,int N);

	void print(SeqQueue<Maze>* qu, int front,int xe,int ye);

public:

	Maze();

	Maze(int i, int j, int di);
	~Maze();
};

#endif // !_Maze_H_
