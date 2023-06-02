#include "GameMap.h"
#include "util.h"
GameMap::GameMap(int arr[19][25])
{
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 25; j++)
        {
            frameArr[i][j] = arr[i][j];
            if (arr[i][j] == ITEM::DEST1)
                dest.push_back({ {i,j},0 });
            else if (arr[i][j] == ITEM::DEST2)
                dest.push_back({ {i,j},1 });
            else  if (arr[i][j] == ITEM::DEST0)
                dest.push_back({ {i,j},2 });
            else if (arr[i][j] == ITEM::FIRE)
                FirePos.push({ i,j,0 });
        }
    std::cout << "firepos size: " << FirePos.size();
    finish_way = dest.size();
}

bool GameMap::Map_MovePlayer(int player_sort, std::pair<int, int> from, std::pair<int, int> to)
{
    int next = frameArr[to.first][to.second];
    int who;
    if (player_sort == 1) who = ITEM::P1;
    else who = ITEM::P2;

    if (next == ITEM::WALL || next == ITEM::P1 || next == ITEM::P2)
        return false;

    int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ

    //�� ������Ʈ
    frameArr[from.first][from.second] = ITEM::BLANK;
    frameArr[to.first][to.second] = who;

    //ȭ�� ���
    //���⿡ �������� ������ �ʴ� ��� �ֱ�!!
    gotoxy(x + from.second * 2, y + from.first);
    int d_type = -1;
    for (int i = 0; i < finish_way; i++)
        if (from == dest[i].first)
            d_type = dest[i].second;
    switch (d_type)
    {
    case -1: {printf("  "); break; }
    case 0: {ColorSet(0, ITEMCOLOR::CP1); printf("��"); break; }
    case 1: {ColorSet(0, ITEMCOLOR::CP2); printf("��"); break; }
    case 2: {ColorSet(0, ITEMCOLOR::CDEST); printf("��"); break; }
    }

    gotoxy(x + to.second * 2, y + to.first);
    if (player_sort == 1)ColorSet(0, ITEMCOLOR::CP1);
    else ColorSet(0, ITEMCOLOR::CP2);
    printf("��");

    return true; //�̵�����
}
void GameMap::printMapAll()
{
    int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 25; j++) {
            gotoxy(x + j * 2, y + i);

            if (frameArr[i][j] == ITEM::P1) {   //�÷��̾�1
                ColorSet(0, 10);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::P2) {   //�÷��̾�2
                ColorSet(0, 13);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::DEST1) {   //��������
                ColorSet(0, 10);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::DEST2) {   //��������
                ColorSet(0, 13);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::DEST0) {   //��������
                ColorSet(0, 6);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::WALL) {   //��
                ColorSet(0, 7);
                printf("��");
            }

            else if (frameArr[i][j] == ITEM::EXTINGUISHER) {   //��ȭ��
                ColorSet(0, 11);
                printf("��");
            }

            else if (frameArr[i][j] == ITEM::FIRE) {   //��
                ColorSet(0, 12);
                printf("��");
            }

            else if (frameArr[i][j] == ITEM::EV) {   //����
                ColorSet(0, 14);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::PLUG) {   //��ȭ��
                ColorSet(0, 11);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::STAR) {   //��ȭ��
                ColorSet(0, 14);
                printf("��");
            }
            else if (frameArr[i][j] == ITEM::BLANK)   //����
                printf("  ");
        }
    }

    const char* back = "�ڷ� ���� : B";
    ColorSet(0, 8);
    gotoxy(23, 28);
    printf("%s", back);
    ColorSet(0, 7);
}

void GameMap::doExt(std::pair<int, int>p)
{
    int filter[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

    for (int i = 0; i < 4; i++)
    {
        int I = p.first + filter[i][0];
        int J = p.second + filter[i][1];

        if (frameArr[I][J] == ITEM::FIRE)
        {
            int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ
            //�� ������Ʈ
            frameArr[I][J] = ITEM::BLANK;

            //ȭ�� ���
            gotoxy(x + J * 2, y + I);
            printf("  ");
        }
    }
}
void GameMap::doPlug(std::pair<int, int>p)
{
    int filter[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

    std::vector<std::pair<int, int>>stars;

    for (int j = 1; j <= 2; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            int I = p.first + filter[i][0] * j;
            int J = p.second + filter[i][1] * j;

            if (I < 0 || J < 0 || I>18 || J>24) continue;

            if (frameArr[I][J] == ITEM::FIRE ||
                frameArr[I][J] == ITEM::BLANK)
            {
                int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ
                //�� ������Ʈ
                frameArr[I][J] = ITEM::STAR;

                //ȭ�� ���
                gotoxy(x + J * 2, y + I);
                ColorSet(0, 14);
                printf("*");

                stars.push_back({ I, J });
            }
        }
    }

    Sleep(100);
    for (auto e : stars)
    {
        int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ
        //�� ������Ʈ
        frameArr[e.first][e.second] = ITEM::BLANK;

        //ȭ�� ���
        gotoxy(x + e.second * 2, y + e.first);
        printf("  ");
    }

}

void GameMap::fireSpread()
{
    if (FirePos.empty())
        return;

    int filter[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    std::queue<FireInfo>rem;

    FireInfo fireX = FirePos.front();
    int firenum = fireX.sort;
    //bfs
    while (firenum == fireX.sort)
    {
        FirePos.pop();

        if (frameArr[fireX.i][fireX.j] == ITEM::FIRE)
        {
            for (int k = 0; k < 4; k++)
            {
                int I = fireX.i + filter[k][0];
                int J = fireX.j + filter[k][1];

                if (I < 0 || J < 0 || I > 18 || J > 24) continue;
                if (frameArr[I][J] != ITEM::BLANK) continue;
                FirePos.push({ I, J, fireX.sort + 1 });
                rem.push({ I,J,fireX.sort + 1 });
            }
        }

        fireX = FirePos.front();
    }

    //�� ������Ʈ, ȭ�� ���
    while (!rem.empty())
    {
        FireInfo remX = rem.front();
        rem.pop();

        //�� ������Ʈ
        frameArr[remX.i][remX.j] = ITEM::FIRE;

        int x = 5, y = 3;   //���� �����ϴ� ���� ���� �� ������ ��ǥ
        //ȭ�� ���
        gotoxy(x + remX.j * 2, y + remX.i);
        ColorSet(0, 12);
        printf("��");
    }
}