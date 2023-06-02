#ifndef GAME_MANAGER_H__
#define GAME_MANAGER_H__

#include"GameScreen.h"
#include"GameMap.h"
#include"Player.h"
#include "util.h"

//singleton 목표!!
class GameManager
{
public:
	static int tempCnt;

	static int AllArr[4][19][25];
	GameScreen* now_map;
	Player* player[2];
	unsigned long long GameStartTime;
	enum MAPSORT
	{
		HAKJUNG, DAEYANG_AI, GWANGGAETO, DAEYANG_HALL
	};
	//키보드 관리
	enum KB { UP, DOWN, LEFT, RIGHT, EXT, SPACE };
	std::pair<int, int>KBInfo();
	static char nowKey;
	static bool KeyControl();

	void StartProgram();
	void InitGame(int Map_sort);
	bool RunGame();
	void ExitGame();

	//게임 클리어 관리
	int GameFinishFlag;
	void GameFinish();
	bool StageClear[4] = { 0 };
	enum GAMEFINISH { NONE, CLEAR, OVER };

	//맵과 플레이어 클래스 이어주기
	void GetItem(std::pair<int, int>& kb);
	bool ControlFire();
	int canSpread;

	//게임 선택창
	int SelStage();
};

#endif
