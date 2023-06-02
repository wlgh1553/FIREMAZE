#include "Player.h"

Player::Player(std::pair<int, int>p)
{
	pos = p; extinguisher = 0; has_fireplug = false;
	fireplug_get_time = 0;
}

//플레이어가 움직일 좌표 요청
std::pair<int, int> Player::playerMove(int dir)
{
	int filter[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	int I = pos.first + filter[dir][0];
	int J = pos.second + filter[dir][1];

	return { I,J };
}
//플레이어는 소화를 할 수 있는가, 할 수 있다면 어떤 종류로 할 것인가
int Player::playerExt()
{
	if (has_fireplug)
		return EX::FIREPLUG;
	else if (extinguisher > 0)
		return EX::EXTINGUISHER;
	return EX::NONE;
}

#include"util.h"
void Player::getItem(int sort)
{
	switch (sort)
	{
	case EX::EXTINGUISHER:
	{
		if (extinguisher < 5)
			extinguisher++;
		return;
	}
	case EX::FIREPLUG:
	{
		has_fireplug = true;
		fireplug_get_time = GetTickCount64();
		return;
	}
	}
}

//소화전 시간 초기화
void Player::updateExt(const char* name, int x_pos)
{
	if (has_fireplug)
	{
		if (GetTickCount64() - fireplug_get_time > 10500) {  //10초동안 사용 가능하게 만들어줌
			gotoxy(x_pos, 25);
			printf("                     ");
			gotoxy(x_pos, 27);
			printf("                                       ");
			has_fireplug = false;
		}
		else {
			gotoxy(x_pos, 25);
			printf("%s소화전 사용가능", name);
			gotoxy(x_pos, 27);
			printf("사용가능 시간 : %d초/10초", (GetTickCount64() - fireplug_get_time) / 1000);
		}
	}
}

bool Player::useExtinguisher()
{
	if (extinguisher == 0)return false;
	extinguisher--;
	return true;
}
bool Player::useFireplug()
{
	if (has_fireplug) return true;
	return false;
}