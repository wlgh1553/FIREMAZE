#include<iostream>
#include"GameManager.h"

int main()
{
	GameManager& game = GameManager::getIncetance();
	game.StartProgram();

	return 0;
}