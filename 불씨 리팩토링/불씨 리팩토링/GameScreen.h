#ifndef GAME_SCREEN_H__
#define GAME_SCREEN_H__
#include<iostream>

class GameScreen
{
public:
	//���� ���� ȭ�� ���
	virtual void printMapAll() = 0;//ȭ�� ��ü ���
	void print_time_and_extinguisher_info(int nowTime, int p1_cnt, int p2_cnt);

	//���� ���� ȭ�� ���
	static void map_sel_Draw(bool StageClear[4]);
};

#endif