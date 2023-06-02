#ifndef PLAYER_H__
#define PLAYER_H__
#include<iostream>
class Player
{
public:
	std::pair<int, int> pos; //��ġ
	int extinguisher; //��ȭ�� ����
	bool has_fireplug; //��ȭ�� ����°�?
	int fireplug_get_time;//��ȭ�� ���� �ð�

	Player(std::pair<int, int>p);

	std::pair<int, int> playerMove(int dir);
	int playerExt();
	void updateExt(const char* name, int x_pos);
	void getItem(int sort);
	bool useExtinguisher();
	bool useFireplug();

	enum MOVEDIR { UP, DOWN, LEFT, RIGHT };
	enum EX { NONE, EXTINGUISHER, FIREPLUG }; //� ������ ���� �����ΰ�
};

#endif