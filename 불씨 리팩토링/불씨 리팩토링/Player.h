#ifndef PLAYER_H__
#define PLAYER_H__
#include<iostream>
class Player
{
public:
	std::pair<int, int> pos; //위치
	int extinguisher; //소화기 개수
	bool has_fireplug; //소화전 얻었는가?
	int fireplug_get_time;//소화전 얻은 시간

	Player(std::pair<int, int>p);

	std::pair<int, int> playerMove(int dir);
	int playerExt();
	void updateExt(const char* name, int x_pos);
	void getItem(int sort);
	bool useExtinguisher();
	bool useFireplug();

	enum MOVEDIR { UP, DOWN, LEFT, RIGHT };
	enum EX { NONE, EXTINGUISHER, FIREPLUG }; //어떤 종류로 불을 끌것인가
};

#endif