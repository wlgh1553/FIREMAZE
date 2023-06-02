#include "GameScreen.h"
#include "util.h"

void GameScreen::print_time_and_extinguisher_info(int startTime, int p1_cnt, int p2_cnt)
{
	int nowTime = (GetTickCount64() - startTime) / 1000;
	gotoxy(17, 1); ColorSet(0, 7);
	printf("현재 시간 : %d초 / %d초", nowTime, 150);

	gotoxy(5, 23); ColorSet(0, 7);
	printf("p1의 소화기 개수 : %d/%d     p2의 소화기 개수 : %d/%d",
		p1_cnt, 5, p2_cnt, 5);
}

void GameScreen::map_sel_Draw(bool StageClear[4])
{
	ColorSet(0, 15);
	gotoxy(24 - 2, 12);
	printf("> 학술정보원");
	gotoxy(24, 13);
	printf("대양 AI 센터");
	gotoxy(24, 14);
	printf("광개토관");
	gotoxy(24, 15);
	printf("대양홀");
	ColorSet(0, 8); gotoxy(24, 16); printf("게임종료");
	ColorSet(0, 15);  //다시 원래 색으로
	for (int i = 0; i < 4; i++)
	{
		if (StageClear[i] == 1) {
			ColorSet(0, 11);
			gotoxy(40, 12 + i);
			printf("PASS");
			ColorSet(0, 7);
		}
	}
}