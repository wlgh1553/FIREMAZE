#include<iostream>
#include"GameManager.h"

int main()
{
	GameManager& game = GameManager::getInstance();
	game.StartProgram();

	return 0;
}