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
	int i;//当前方块的行号
	int j;//当前方块的列号
	int pre;//本路径中上一个方块在队列中的下标
	int di;//下一相邻可走方位的方位号
	

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
