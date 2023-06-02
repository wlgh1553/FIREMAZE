#ifndef GAME_MAP_H__
#define GAME_MAP_H__
#include "GameScreen.h"

#include<vector>
#include<queue>
class GameMap : public GameScreen
{
public:
	//�� ���� ����
	int frameArr[19][25];
	int finish_way;

	//������
	std::vector<std::pair<std::pair<int, int>, int>>dest;

	//�� ��ġ ���
	struct FireInfo
	{
		int i, j, sort;
	};
	std::queue<FireInfo>FirePos;

	//������
	GameMap(int arr[19][25]);

	//�����
	virtual void printMapAll();
	enum ITEM
	{
		BLANK, WALL, P1, DEST1,
		//����:0, �� :1, �÷��̾�1(���ʽ���) : 2, ������1 (P1�� ������)
		EXTINGUISHER, FIRE, EV, P2 = 8,
		//��ȭ�� : 4, �� : 5, ���������� : 6, �÷��̾�2(�����ʽ���) : 8    //7���� �����ض�!!
		PLUG, DEST2, DEST0,
		//��ȭ�� : 9, ������2 (P2�� ������) : 10, ��������� : 11
		STAR
		//��ȭ�� ��� �߻��� ��Ÿ���� �� : 12
	};
	enum ITEMCOLOR
	{
		CP1 = 10, CP2 = 13, CDEST = 6
	};

	//�� ������Ʈ
	bool Map_MovePlayer(int player_sort, std::pair<int, int> from, std::pair<int, int> to);
	void doExt(std::pair<int, int>p);
	void doPlug(std::pair<int, int>p);
	void fireSpread();
};

#endif