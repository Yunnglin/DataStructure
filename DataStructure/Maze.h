#pragma once
#ifndef _Maze_H_
#define _Maze_H_
#define MazeMaxSize 1000
class Maze
{
public :
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//下一相邻可走方位的方位号
	int pre;//本路径中上一个方块在队列中的下标

public:
	bool MazepathStack(int xi, int yi, int xe, int ye,int* mg,int M,int N);

	bool MazepathQueue(int xi, int yi, int xe, int ye,int* mg, int M,int N);

public:

	Maze();

	Maze(int i, int j, int di);
	~Maze();
};

#endif // !_Maze_H_
