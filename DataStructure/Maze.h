#pragma once
#ifndef _Maze_H_
#define _Maze_H_
#define MazeMaxSize 1000
class Maze
{
public :
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int di;//��һ���ڿ��߷�λ�ķ�λ��
	int pre;//��·������һ�������ڶ����е��±�

public:
	bool MazepathStack(int xi, int yi, int xe, int ye,int* mg,int M,int N);

	bool MazepathQueue(int xi, int yi, int xe, int ye,int* mg, int M,int N);

public:

	Maze();

	Maze(int i, int j, int di);
	~Maze();
};

#endif // !_Maze_H_
