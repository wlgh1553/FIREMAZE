#ifndef GAME_MANAGER_H__
#define GAME_MANAGER_H__

#include"GameScreen.h"
#include"GameMap.h"
#include"Player.h"
#include "util.h"

class GameManager
{
//signleton
private:
	GameManager() {}
	GameManager(const GameManager& ref) {}
	GameManager& operator=(const GameManager& ref) {}
	~GameManager() {}
public:
	static GameManager& getInstance();

	static int AllArr[4][19][25];
	GameScreen* now_map;
	Player* player[2];
	unsigned long long GameStartTime;
	enum MAPSORT
	{
		HAKJUNG, DAEYANG_AI, GWANGGAETO, DAEYANG_HALL
	};
	//Ű���� ����
	enum KB { UP, DOWN, LEFT, RIGHT, EXT, SPACE };
	std::pair<int, int>KBInfo();
	static char nowKey;
	static bool KeyControl();

	//���� �帧 ����
	void StartProgram();
	void InitGame(int Map_sort);
	bool RunGame();
	void ExitGame();

	//���� Ŭ���� ����
	int GameFinishFlag;
	void GameFinish();
	bool StageClear[4] = { 0 };
	enum GAMEFINISH { NONE, CLEAR, OVER };

	//�ʰ� �÷��̾� Ŭ���� �̾��ֱ�
	void GetItem(std::pair<int, int>& kb);
	bool ControlFire();
	int canSpread;

	//���� ����â
	int SelStage();
};

#endif
