#ifndef GAME_SCREEN_H__
#define GAME_SCREEN_H__
#include<iostream>

class GameScreen
{
public:
	//게임 관련 화면 출력
	virtual void printMapAll() = 0;//화면 전체 출력
	void print_time_and_extinguisher_info(int nowTime, int p1_cnt, int p2_cnt);

	//게임 선택 화면 출력
	static void map_sel_Draw(bool StageClear[4]);
};

#endif