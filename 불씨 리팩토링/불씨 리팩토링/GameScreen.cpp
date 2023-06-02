#include "GameScreen.h"
#include "util.h"

void GameScreen::print_time_and_extinguisher_info(int startTime, int p1_cnt, int p2_cnt)
{
	int nowTime = (GetTickCount64() - startTime) / 1000;
	gotoxy(17, 1); ColorSet(0, 7);
	printf("���� �ð� : %d�� / %d��", nowTime, 150);

	gotoxy(5, 23); ColorSet(0, 7);
	printf("p1�� ��ȭ�� ���� : %d/%d     p2�� ��ȭ�� ���� : %d/%d",
		p1_cnt, 5, p2_cnt, 5);
}

void GameScreen::map_sel_Draw(bool StageClear[4])
{
	ColorSet(0, 15);
	gotoxy(24 - 2, 12);
	printf("> �м�������");
	gotoxy(24, 13);
	printf("��� AI ����");
	gotoxy(24, 14);
	printf("�������");
	gotoxy(24, 15);
	printf("���Ȧ");
	ColorSet(0, 8); gotoxy(24, 16); printf("��������");
	ColorSet(0, 15);  //�ٽ� ���� ������
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