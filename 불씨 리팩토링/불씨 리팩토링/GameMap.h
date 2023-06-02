#ifndef GAME_MAP_H__
#define GAME_MAP_H__
#include "GameScreen.h"

#include<vector>
#include<queue>
class GameMap : public GameScreen
{
public:
	//맵 정보 저장
	int frameArr[19][25];
	int finish_way;

	//목적지
	std::vector<std::pair<std::pair<int, int>, int>>dest;

	//불 위치 기록
	struct FireInfo
	{
		int i, j, sort;
	};
	std::queue<FireInfo>FirePos;

	//생성자
	GameMap(int arr[19][25]);

	//맵출력
	virtual void printMapAll();
	enum ITEM
	{
		BLANK, WALL, P1, DEST1,
		//공백:0, 벽 :1, 플레이어1(왼쪽시작) : 2, 목적지1 (P1의 목적지)
		EXTINGUISHER, FIRE, EV, P2 = 8,
		//소화기 : 4, 불 : 5, 엘리베이터 : 6, 플레이어2(오른쪽시작) : 8    //7없다 조심해라!!
		PLUG, DEST2, DEST0,
		//소화전 : 9, 목적지2 (P2의 목적지) : 10, 공통목적지 : 11
		STAR
		//소화전 기능 발생시 나타나는 별 : 12
	};
	enum ITEMCOLOR
	{
		CP1 = 10, CP2 = 13, CDEST = 6
	};

	//맵 업데이트
	bool Map_MovePlayer(int player_sort, std::pair<int, int> from, std::pair<int, int> to);
	void doExt(std::pair<int, int>p);
	void doPlug(std::pair<int, int>p);
	void fireSpread();
};

#endif