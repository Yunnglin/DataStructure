#pragma once
#ifndef _Maze_H_
#define _Maze_H_
#define MaxSize 100
class Maze
{
public :
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//下一相邻可走方位的方位号

public:
	bool Mazepath(int xi, int yi, int xe, int ye,int* mg,int M,int N);

public:
	Maze();
	Maze(int i, int j, int di);
	~Maze();
};

#endif // !_Maze_H_
