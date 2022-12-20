#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
// ���� �����ϴ� ������ �迭 �Լ��� ������.
// ��ǥ�� �����ϴ� ��ǥ �迭�� , �������� ��ġ�� �ش��ϴ� ��ġ �迭�� ������.
// ��ǥ�迭�� int �� ��ġ �迭�� char �� ��������.

//Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define	SUBMIT 4 // ���� (Enter Ű)

const char *specialChar()
{
	return "��";
}
const char* specialChar2()
{
	return "��";
}


void gotoxy(int x, int y);


// �ʱ� �Լ�

int game = 0; // Ÿ��Ʋ�� 0 ���ӽ����� 1

// �޴��Լ�
int titleDraw(); // ����ȭ�� �Լ�.
int proLogueDraw(); //���ѷα� �����Լ�.
int menuDraw(); // �޴� �������Լ�
int skillmenuDraw(); // ��ų ������ �Լ�
int npc1draw();
int yesnodraw();
//int itemDraw();//������ �����Լ�

int select_num = 0; //������Ȳ ������ �ʱ�ȭ

//�� �����Լ�

int dengeon_level = 1;

int situation_num = 1; //�����̼� �ѹ�

//��ȭ����
int ganghwa_sit = 0; //��ȭâ

int cost_stab = 50;
int cost_rage = 150;
int cost_heal = 100;




char map_arr_loCation_level_1[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// ��ġ�Լ� ����.
char map_arr_loCation_level_2[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// ��ġ�Լ� ����.
char map_arr_loCation_level_3[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };
char map_arr_loCation_level_4[15][15];
char map_arr_loCation_level_5[15][15];

void printQuestion_level_1(); // �� ���
void printQuestion_level_2(); // 2�� ���
void printQuestion_level_3();
void printQuestion_level_4();
void printQuestion_level_5();

int keyControl();


int t_1 = 10; // �� ���� ����
int g_1 = 10; // �� ���� ����
int t_2 = 15;
int g_2 = 15;
void monster1_move_system_1(char arr[][10],int a, int b); // ���� ���� ���� �Լ� 1�� ����1 



void move_player_1(char arr[][10],int x, int y); //�÷��̾� ��ǥ
void move_player_2(char arr[][15],int x, int y);
void bef_move_player_1(char arr[][10],int x, int y); //�÷��̾� ���� ��ǥ �ʱ�ȭ
void bef_move_player_2(char arr[][15], int x, int y);

void move_monster_1(int x, int y); // ������ǥ
void move_monster_2(int x, int y);
void bef_move_monster(int x, int y); //���� ���� ��ǥ �ʱ�ȭ


void creaTor_great_Wall_1(char arr[][10], int a, int b); //�׵θ� �� ���� �Լ�
void creaTor_great_Wall_2(char arr[][15], int a, int b); //4~5�� ���� ��

int Player = 1; //�÷��̾� ������
int monster1 = 4; //����1 ������
int npc_1 = 5; // npc1������.
int enTrance = 3;

int stonColor[4] = { "���","������","�����" }; //��ų��ȭ ��,�������,����


int x_npc=5;
int y_npc=5;

int x_mon = 0; //���� ��ǥ��
int y_mon = 0;

int monster1_life = 1; // ���Ͱ� ����ִ��� ����
int npc1_life = 1;

//�����Լ�
int stab_lv = 1;
int rage_lv = 1;
int heal_lv = 1;

int turn = 0;
int cnt_turn_stab = -3;
int cnt_turn_rage = -5;
int cnt_turn_heal = -3;

int attack(int x, int y);  // ���� �Լ�

int attacked_monster(int x, int y); //�ǰ� �Լ�


char *item[20]; // ���ڿ��� �迭�� �ֱ����� * ����.


//��ų�Լ�
int skill_several_stab(int a);
int skill_holy_Heal(int x, int y);
int skill_rage(int x);
int cnt_attack = 0;
int rage = 0;

typedef struct objecT
{
	char* name;// ��ü��
	int attack;// ���ݷ�
	int life;  // �����
	int max_life;// �ִ� �����
	char* item[20];// ������ĭ. ���� ùĭ�� ���������ִٸ�? for�� ����Ͽ� i++ �ؼ� ��õ��Ͽ� ����
	int crono; //ȭ��
	int exp; // ����ġ
	int level;
}oBject;

////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////


int main(void)
{
	srand(time(NULL));
	system("mode con cols=30 lines=12");

	oBject player; //�÷��̾� ����
	player.name = "player";
	player.attack = 20;
	player.crono = 5000;
	player.level = 1;
	player.exp = 0;
	player.max_life = 50;
	player.life = player.max_life; 

	oBject monster1; //���� 1 ����.
	monster1.name = "Black-Dragon";
	monster1.attack = 8;
	monster1.life = 60;
	monster1.crono = rand() % 50 + 60;
	monster1.level = 50;
	monster1.exp = 500;

	oBject npc1;
	npc1.name = "kun_ha";
	npc1.attack = 3;
	npc1.life = 20;
	npc1.crono = 600;
	npc1.level = 3;
	npc1.exp = 4;
	


	int cnt_monster1_life = monster1.life;
	int cnt_player_life = player.life;

	int key = 0; // �÷��̾� �̵� ���� 

	int y_p = 1; //�÷��̾� ���� ��ġ
	int x_p = 1; //�÷��̾� ���� ��ġ



	map_arr_loCation_level_1[8][8] = enTrance;
	map_arr_loCation_level_2[8][8] = enTrance;
	map_arr_loCation_level_3[8][8] = enTrance;
	map_arr_loCation_level_4[12][12] = enTrance;
	map_arr_loCation_level_5[12][12] = enTrance;


	if (npc1_life == 1) {
		map_arr_loCation_level_2[5][5] = npc_1;
	}


	creaTor_great_Wall_1(map_arr_loCation_level_1,t_1, g_1);
	creaTor_great_Wall_1(map_arr_loCation_level_2,t_1, g_1);
	creaTor_great_Wall_1(map_arr_loCation_level_3,t_1, g_1);
	creaTor_great_Wall_2(map_arr_loCation_level_4, t_2, g_2);
	creaTor_great_Wall_2(map_arr_loCation_level_5, t_2, g_2);

	








	while (game == 0)
	{
		printf("\n\n\n.");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf("Loading");
		Sleep(3000);
		system("cls");


		printf("\n\n      [Dark Labyrinth]\n");
		switch (titleDraw())
		{
		case 0:
		{
			system("cls");
			printf("\n\n\n Welcome to my Labyrinth. . .");
			Sleep(2500);
			system("cls");
			printf("\n\n\n -���ѷα׸� ���ðڽ��ϱ�?-");
			switch (proLogueDraw())
			{
			case 0:
			{
				system("cls");
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(1500);
				printf("���õ� �߱��̴�..\n");
				Sleep(1500);
				printf("��ģ ���� �̲��� ������ ���Ѵ�...\n");
				Sleep(1500);
				printf("\"������  �����̴ϱ� ǫ ����..\"\n");
				Sleep(1500);
				printf("\"��?.. ����?... \"\n");
				Sleep(3000);
				game = 1;
			}
			case 1:
			{
				system("cls");
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(100);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(2000);
				system("cls");
				game = 1;


			}
			default:
				game = 1;
				break;
			}


			
			game = 1;
		}





		} //sw_ed
			
	}
	if (dengeon_level == 1) 
	{
		while (map_arr_loCation_level_1[x_mon][y_mon] != 0) //  ���� ��ȯ ��ǥ ���� 0�϶����� and ĳ���� ���� �ƴҶ�����.
		{
			x_mon = rand() % (t_1 - 3) + 2; // 2,3,4,5,6,7,8,9
			y_mon = rand() % (g_1 - 3) + 2; // 2,3,4,5,6,7,8,9
		}
	}



	while (game == 1)//���������� // ȭ�� ����.
	{

		if (situation_num == 1) //����
		{
			if (dengeon_level == 1)
			{
				printQuestion_level_1();//�� ǥ��
				if (map_arr_loCation_level_1[8][8] == Player)
				{
					dengeon_level = 2;
					x_p = 2;
					y_p = 2;
				}
			}
			
			if (dengeon_level == 2) 
			{
				printQuestion_level_2();
				if (map_arr_loCation_level_2[8][8] == Player)
				{
					dengeon_level = 3;
					x_p = 2;
					y_p = 2;
				}
			}

			if (dengeon_level == 3)
			{
				printQuestion_level_3();
				if (map_arr_loCation_level_3[8][8] == Player)
				{
					dengeon_level = 4;
					x_p = 2;
					y_p = 2;
				}
			}
			if (dengeon_level == 4)
			{
				printQuestion_level_4();
				if (map_arr_loCation_level_4[12][12] == Player)
				{
					dengeon_level = 5;
					x_p = 2;
					y_p = 2;
				}
			}

			if (dengeon_level == 5)
			{
				printQuestion_level_5();
				if (map_arr_loCation_level_5[12][12] == Player)
				{
					dengeon_level = 9;
					x_p = 2;
					y_p = 2;
				}
			}



			if (dengeon_level == 1) 
			{
				move_player_1(map_arr_loCation_level_1,y_p, x_p); // ĳ���� �� ��ǥ �Լ�.
				move_monster_1(map_arr_loCation_level_1, y_mon, x_mon); // ���� �� ��ǥ.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_1,y_p, x_p); // ���� �÷��̾��� ��ġ�� �ִ� 1�� ������. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_1[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_1[y_p - 1][x_p] == 3) //�������ϴ� �ڸ��� 0�϶��� ����.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_1[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_1[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_1[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_1[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_1[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_1[y_p + 1][x_p] == 3)
							y_p++;
						break;
					default:
						break;
					}

				}

				if (monster1_life == 1)
				{
					monster1_move_system_1(map_arr_loCation_level_1, y_mon, x_mon);
					if (x_p == x_mon && y_p == y_mon + 1 ||
						x_p == x_mon + 1 && y_p == y_mon ||
						x_p == x_mon - 1 && y_p == y_mon ||
						x_p == x_mon && y_p == y_mon - 1)
					{
						situation_num = 2;
						Sleep(1000);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					}

				}
				else
					bef_move_monster(y_mon, x_mon);
			}
			if(dengeon_level==2)
			{

				move_player_1(map_arr_loCation_level_2, y_p, x_p); // ĳ���� �� ��ǥ �Լ�.
				//move_monster_1(map_arr_loCation_level_2, y_mon, x_mon); // ���� �� ��ǥ.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_2, y_p, x_p); // ���� �÷��̾��� ��ġ�� �ִ� 1�� ������. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_2[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_2[y_p - 1][x_p] == 3) //�������ϴ� �ڸ��� 0�϶��� ����.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_2[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_2[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_2[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_2[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_2[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_2[y_p + 1][x_p] == 3)
							y_p++;
						break;
					default:
						break;
					}
				}
				if (x_p == x_npc && y_p == y_npc + 1 ||
					x_p == x_npc + 1 && y_p == y_npc ||
					x_p == x_npc - 1 && y_p == y_npc ||
					x_p == x_npc && y_p == y_npc - 1)
				{
					situation_num = 4;
				}
			}
			if (dengeon_level == 3)
			{
				move_player_1(map_arr_loCation_level_3, y_p, x_p); // ĳ���� �� ��ǥ �Լ�.
				//move_monster_1(map_arr_loCation_level_3, y_mon, x_mon); // ���� �� ��ǥ.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_3, y_p, x_p); // ���� �÷��̾��� ��ġ�� �ִ� 1�� ������. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_3[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_3[y_p - 1][x_p] == 3) //�������ϴ� �ڸ��� 0�϶��� ����.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_3[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_3[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_3[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_3[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_3[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_3[y_p + 1][x_p] == 3)
							y_p++;
						break;
					default:
						break;
					}
				}
			}
			if (dengeon_level == 4)
			{
				move_player_2(map_arr_loCation_level_4, y_p, x_p); // ĳ���� �� ��ǥ �Լ�.
				//move_monster_2(map_arr_loCation_level_4, y_mon, x_mon); // ���� �� ��ǥ.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_2(map_arr_loCation_level_4, y_p, x_p); // ���� �÷��̾��� ��ġ�� �ִ� 1�� ������. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_4[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_4[y_p - 1][x_p] == 3) //�������ϴ� �ڸ��� 0�϶��� ����.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_4[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_4[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_4[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_4[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_4[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_4[y_p + 1][x_p] == 3)
							y_p++;
						break;
					default:
						break;
					}
				}
			}



		}
		if (situation_num == 2) // �������ۿ���
		{

			Sleep(100);

			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf(" %s�� ��Ÿ����!\n", monster1.name);
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(800);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(100);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			Sleep(500);
			system("cls");
			situation_num = 3;




		}
		if (situation_num == 3) //��ġ��
		{

			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			printf(" %s�� ü��: %d\n\n", monster1.name, monster1.life);
			printf(" ����� ü�� :%d\n", player.life);
			printf("�ѤѤѤ����� ��:%d�ѤѤ�\n", turn);
			switch (menuDraw())//����������
			{
			case 0: //����
			{
				system("cls");
				turn++;
				cnt_monster1_life = monster1.life;
				cnt_player_life = player.life;
				monster1.life -= attack(monster1.life, player.attack);
				player.life -= attack(player.life, monster1.attack);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				Sleep(1000);
				printf("% s�� % s����\n ���� ������ �ֵѷ���!\n\n", player.name, monster1.name);
				Sleep(1000);
				printf("%s���� %d��\n �������� �־���.\n\n", monster1.name, cnt_monster1_life - monster1.life);  // ���ݹޱ��� - ������ =������
				Sleep(1500);
				if (monster1.life <= 0)
				{
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					system("cls");
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(1000);
					printf("%s�� ����Ʈ�ȴ�!\n", monster1.name);
					Sleep(1000);
					printf("%d ũ�γ� �� �����!\n", monster1.crono);
					player.crono += monster1.crono;
					Sleep(500);
					printf("%d ����ġ�� ȹ���ߴ�!", monster1.exp);
					player.exp += monster1.exp;
					Sleep(500);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(2000);
					y_mon = 15;
					x_mon = 15;
					bef_move_monster(y_mon, x_mon);
					monster1_life = 0;
					system("cls");
					situation_num = 1;

				}
				else if (monster1.life > 0)
				{
					printf("%s�� %s����\n �޷������!\n\n", monster1.name, player.name);
					Sleep(1000);
					printf("%s�� %d��\n �������� �޾���.\n\n", player.name, cnt_player_life - player.life);
					Sleep(1500);
					if (player.life <= 0)
					{
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(500);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(500);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(500);
						printf("���� ���� ���Ͽ���...");
						Sleep(1000);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(300);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(300);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(300);
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(500);
						printf("		   GAME OVER\n");
						Sleep(1000);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(500);
						_getch();
						break;
					}
					system("cls");
					situation_num = 3;
				}
				break;
			}
			case 1: //���
			{
				turn++;
				cnt_player_life = player.life;
				system("cls");
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				player.life -= (attack(player.life, monster1.attack)) / 3;
				printf("%s�� ����¼��� ����!\n", player.name);
				Sleep(1000);
				printf("%s�� %s����\n �޷������!\n\n", monster1.name, player.name);
				Sleep(1500);
				printf("%s�� %d��\n �������� �޾���.\n\n", player.name, cnt_player_life - player.life);
				Sleep(1000);
				if (player.life <= 0)
				{
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(500);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(500);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(500);
					printf("%s�� ���� ���Ͽ���...", player.name);
					Sleep(1000);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(300);
					system("cls");
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(500);
					printf("		   GAME OVER\n");
					Sleep(1000);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
					Sleep(500);
					_getch();
					break;
				}
				else
					system("cls");
				situation_num = 3;
				break;
			}
			case 2: //��ų
			{
				system("cls");
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				printf(" %s�� ü��: %d\n\n", monster1.name, monster1.life);
				printf(" ����� ü�� :%d\n", player.life);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				switch (skillmenuDraw())
				{
				case 0: //�������
				{
					if (turn < cnt_turn_stab + 3)
					{
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1000);
						printf("���� ����� �� �����ϴ�.\n");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_stab = turn;
						system("cls");
						cnt_player_life = player.life;
						cnt_monster1_life = monster1.life;
						monster1.life -= skill_several_stab(player.attack);
						player.life -= attack(player.life, monster1.attack);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1500);
						printf("%s�� ���� ��⸦ ����ߴ�!\n", player.name);
						Sleep(1000);
						printf("%s�� %s���� %d�� �������� �־���.\n", player.name, monster1.name, skill_several_stab(player.attack));
						Sleep(2000);

						if (monster1.life <= 0)
						{
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(300);
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(300);
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(300);
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(300);
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(300);
							system("cls");
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(1000);
							printf("%s�� ����Ʈ�ȴ�!\n", monster1.name);
							Sleep(1000);
							printf("%d ũ�γ� �� �����!\n", monster1.crono);
							player.crono += monster1.crono;
							Sleep(500);
							printf("%d ����ġ�� ȹ���ߴ�!\n", monster1.exp);
							player.exp += monster1.exp;
							Sleep(500);
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(2000);
							y_mon = 15;
							x_mon = 15;
							bef_move_monster(y_mon, x_mon);
							system("cls");
							monster1_life=0;
							situation_num = 1;
							break;

						}
						else if (monster1.life > 0)
						{
							printf("%s�� %s����\n �޷������!\n\n", monster1.name, player.name);
							Sleep(1000);
							printf("%s�� %d��\n �������� �޾���.\n\n", player.name, cnt_player_life - player.life);
							Sleep(1500);
							if (player.life <= 0)
							{
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(500);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(500);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(500);
								printf("���� ���� ���Ͽ���...\n");
								Sleep(1000);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(300);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(300);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(300);
								system("cls");
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(500);
								printf("		   GAME OVER\n");
								Sleep(1000);
								printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
								Sleep(500);
								_getch();
								break;
							}

							break;
						}
						else
							system("cls");
						situation_num = 1;
					}
					break;
				}
				case 1://ȸ��
				{
					if (turn < cnt_turn_heal + 3)
					{
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1000);
						printf("���� ����� �� �����ϴ�.\n");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_heal = turn;
						cnt_player_life = player.life;
						system("cls");
						player.life += skill_holy_Heal(player.life, player.attack); //�� ����
						if (player.life > cnt_player_life) // ���� �� �ִ����º��� �������Եȴٸ�
						{
							player.life = player.max_life;

							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(1500);
							printf("�Ų� �⵵�� �帳�ϴ�...\n\n");
							Sleep(1500);
							printf("���� %d�� ü���� ȸ���ߴ�!\n", player.max_life - cnt_player_life);
						}
						else
						{
							printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
							Sleep(1500);
							printf("�Ų� �⵵�� �帳�ϴ�...\n\n");
							Sleep(1500);
							printf("���� %d�� ü���� ȸ���ߴ�!\n", skill_holy_Heal(player.life, player.attack));
						}
						Sleep(500);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(2000);
						system("cls");
						break;
					}
				}
				case 2: //�г�
				{
					if (rage == 0 && turn < cnt_turn_rage + 5)
					{
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1000);
						printf("���� ����� �� �����ϴ�.\n");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1500);
						situation_num = 3;
					}
					else if (rage == 1)
					{
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1000);
						printf("���� ����� �� �����ϴ�.\n");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1500);
						situation_num = 3;
					}
					else if (rage == 0)
					{
						cnt_turn_rage = turn;
						turn++;
						rage = 1;
						cnt_attack = player.attack;
						system("cls");
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(1000);
						printf("���� ���¢����.\n\n���� ��%d  ����� ��%d\n", turn, cnt_turn_rage);
						Sleep(1500);
						printf(" \"�� �� �� �� ! ! !\"\n\n");
						player.attack += skill_rage(player.attack);
						Sleep(1500);
						printf("����� ���ݷ��� �Ͻ������� �����ߴ�!\n%d %d\n", player.attack, cnt_attack);
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
						Sleep(2000);
						system("cls");
						situation_num = 3;
						break;
					}
				}
				case 3: //���ư���
				{
					system("cls");
					situation_num = 3;
					break;
				}
				default:
					break;
				}//skilldraw
			default:
				break;
			} //case 2
			case 3: // ������
			{
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
				printf("����� �������� �����ϼ���. \n");
				/*for (int i = 0, i < item[10], i++)
				{
					printf("[%s] x %d",item_name,item_count)
				}*/
				break;
			}


			} //case select num 



		}

		if (situation_num == 4)
		{
			system("cls");
			Sleep(1000);
			printf("\n\n�ź��� ��� ���� ��� ������ ������ �տ� �ִ�...\n");
			Sleep(1500);
			printf("\n�����԰��� ���̴� ���ڰ� �ִ�.\n");
			Sleep(1000);
			printf("\nũ�γ븦 ��ġ�� ���� ���� �Ͼ �� ����.\n");
			Sleep(1500);
			system("cls");
			situation_num = 5;
		}

		if (situation_num == 5)
		{
			printf("     <�ż��� ��� ����>\n");
			printf("\n");
			Sleep(1000);
			printf("   ���� ��� Lv.%d\n   �ż��� ȸ�� Lv.%d\n   ����� �г� Lv.%d\n",stab_lv,heal_lv,rage_lv);
			printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
			printf("�� ũ�γ� : %d", player.crono);
			switch (npc1draw())
			{
			case 0:
			{
				system("cls");
				Sleep(1000);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
				Sleep(1500);
				printf("%dũ�γ밡 �ʿ��մϴ�.\n\n���� ��⸦ ��ȭ�Ͻðڽ��ϱ�?\n",cost_stab);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_stab)
					{
						player.crono -= cost_stab;

						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
						Sleep(1500);
						printf("\n\n\n  ���� ����� ������ ����߽��ϴ�.");
						Sleep(1500);
						if (stab_lv == 1) // 50.
						{
							stab_lv++;
							cost_stab = 200;
						}
						else if (stab_lv == 2) {
							cost_stab = 350;
							stab_lv++;
						}
						else if (stab_lv == 3)
						{
							cost_stab = 550;
							stab_lv++;
						}
						else if (stab_lv == 4)
						{
							cost_stab = 800;
							stab_lv++;
						}
						break;
					}
					else
					{
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
						Sleep(1000);
						printf("\n\nũ�γ밡 �����մϴ�.");
						Sleep(1000);
						break;
					}
				}
				case 1:
				{
					break;
				}
				}	
				break;
			}
			case 1:
			{
				system("cls");
				Sleep(1000);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
				Sleep(1500);
				printf("%dũ�γ밡 �ʿ��մϴ�.\n �ż��� ȸ���� ��ȭ�Ͻðڽ��ϱ�?\n",cost_heal);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_heal) {
						player.crono -= cost_heal;
						heal_lv++;
						printf("\n\n\n  �ż��� ȸ���� ������ ����߽��ϴ�.");
						if (heal_lv == 2) 
						{
							cost_heal = 250;
							heal_lv++;
						}
						else if (heal_lv == 3)
						{
							cost_heal = 300;
							heal_lv++;
						}
						else if (heal_lv == 4)
						{
							cost_heal = 300;
							heal_lv++;
						}
						break;

					}
					else {
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
						Sleep(1000);
						printf("\n\nũ�γ밡 �����մϴ�.");
						Sleep(1000);
						break;
					}
				}
				case 1:
				{
					break;
				}
				}
			}
			case 2:
			{
				system("cls");
				Sleep(1000);
				printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
				Sleep(1500);
				printf("%dũ�γ밡 �ʿ��մϴ�. ��ȭ�Ͻðڽ��ϱ�?", cost_rage);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_rage)
					{
						player.crono -= cost_rage;
						rage_lv++;
						printf("\n\n\n  ����� �г��� ������ ����߽��ϴ�.");
						if (rage_lv == 2) {
							cost_rage = 300;
							rage_lv++;
						}
						else if (rage_lv == 3) {
							cost_rage = 500;
							rage_lv++;
						}
						else if (rage_lv == 4) {
							cost_rage = 500;
							rage_lv++;
						}
						break;
					}
					else {
						printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
						Sleep(1000);
						printf("\n\nũ�γ밡 �����մϴ�.");
						Sleep(1000);
						break;
					}

				}
				case 1:
				{
					break;
				}
				}
			}
			case 3: // ���ư���.
			{
				situation_num = 1;
				break;
			}
			default:
			{
				situation_num = 1;
			}
			}//sw_ed
		}

		if (situation_num == 6)
		{

		}

		if (rage == 1)
		{
			if (turn == cnt_turn_rage + 3)
			{
				rage = 0;
				player.attack = cnt_attack; // ���ݷ��� ������ ���� �����س��� ���ݷ����� �ǵ���.

			}
		}

		Sleep(50);
		system("cls");

	}

	return 0;
}
////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////

void move_player_1(char arr[][10],int x, int y)
{
	arr[x][y] = Player;
}

void move_player_2(char arr[][15], int x, int y)
{
	arr[x][y] = Player;
}


void bef_move_player_1(char arr[][10],int x, int y)
{
	arr[x][y] = 0;
}

void bef_move_player_2(char arr[][15], int x, int y)
{
	arr[x][y] = 0;
}

void printQuestion_level_1()//�� ���
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_1[i][j] == 0)
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_1[i][j] == 9)
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_1[i][j] == 3)
			{
				printf("%s", specialChar2());
			}
			else
				printf(" %d", map_arr_loCation_level_1[i][j]);

		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}

void printQuestion_level_2()//�� ���
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_2[i][j] == 0)
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_2[i][j] == 9)
			{
				printf("%s", specialChar());
			}
			else
				printf(" %d", map_arr_loCation_level_2[i][j]);


		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}

void printQuestion_level_3()//�� ���
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_3[i][j] == 0)
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_3[i][j] == 9)
			{
				printf("%s", specialChar());
			}
			else
				printf(" %d", map_arr_loCation_level_3[i][j]);


		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}

void printQuestion_level_4()//�� ���
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map_arr_loCation_level_4[i][j] == 0)
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_4[i][j] == 9)
			{
				printf("%s", specialChar());
			}
			else
				printf(" %d", map_arr_loCation_level_4[i][j]);

		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}

void printQuestion_level_5()//�� ���
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map_arr_loCation_level_5[i][j] == 0)
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_5[i][j] == 9)
			{
				printf("%s", specialChar());
			}
			else
				printf(" %d", map_arr_loCation_level_5[i][j]);


		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}


void creaTor_great_Wall_1(char arr[][10],int a,int b) // �������
{
	for (int i = 0; i < a; i++)
	{
		arr[0][i] = 9; // 0,0 0,1 .... 0,i
		arr[a-1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < b; j++)
	{
		arr[j][a-1] = 9;
		arr[j][0] = 9;
	}
}

void creaTor_great_Wall_2(char arr[][15],int a, int b) // �������
{
	for (int i = 0; i < a; i++)
	{
		arr[0][i] = 9; // 0,0 0,1 .... 0,i
		arr[a - 1][i] = 9; // 5,0, 5,1... 5,i
	} 
	for (int j = 1; j < b; j++)
	{
		arr[j][a - 1] = 9;
		arr[j][0] = 9;
	}
}



void move_monster_1(char arr[][10],int x, int y) // ���� ��ġ ����ȭ
{
	arr[x][y] = monster1;
}
 
void move_monster_2(char arr[][15], int x, int y) // ���� ��ġ ����ȭ
{
	arr[x][y] = monster1;
}

void bef_move_monster(int x, int y)
{
	map_arr_loCation_level_1[x][y] = 0;
}

int keyControl() //enter = 13
{
	char key = _getch();

	if (key == 72 )
		return UP;
	else if (key == 75)
		return LEFT;
	else if (key == 77)
		return RIGHT;
	else if (key == 80)
		return DOWN;
	else if (key == 13)
		return SUBMIT;
}

int titleDraw() {
	int x = 3;
	int y = 5;
	gotoxy(x, y);
	printf("[Open your eyes..]");
	gotoxy(x, y + 1);
	printf("[Load your memories..]");
	gotoxy(x, y + 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("*chaniii999's GitHub*");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x, y + 3);
	printf("[Exit]");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 5) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 8)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 5;
			break;
		}


		}
	}
}

int proLogueDraw() {
	int x = 3;
	int y = 5;
	gotoxy(x, y);
	printf("-��-");
	gotoxy(x, y + 1);
	printf("-�ƴϿ�-");

	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 5) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 6)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 5;
			break;
		}


		}
	}
}

int menuDraw() {
	int x = 3;
	int y = 5;
	gotoxy(x , y);
	printf("����");
	gotoxy(x, y + 1);
	printf("���");
	gotoxy(x, y + 2);
	printf("��ų");
	gotoxy(x, y + 3);
	printf("������");
	while (1) 
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 5) {
				gotoxy(x - 2, y);
				printf(" "); 
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 8)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 5;
			break;
		}


		}
	}
}

int skillmenuDraw()
{
	int x = 3;
	int y = 5;
	if (turn < cnt_turn_stab + 3)
	{
		gotoxy(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-���� ���(Lv.%d)-\n",stab_lv); //[70 % �� ���ݷ����� 2~3�� ���.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-���� ���(Lv.%d)-\n",stab_lv); //[70/80/100 % �� ���ݷ����� 2~3�� ���.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-�ż��� ȸ��(Lv.%d)-\n",heal_lv);//[���ݷ��� 40/60/80 % �� ��ġ�� ü���� ȸ���Ѵ�.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-�ż��� ȸ��(Lv.%d)-\n",heal_lv);//[���ݷ��� 70 % �� ��ġ�� ü���� ȸ���Ѵ�.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // ���� �������̰ų� ��Ÿ���� �ȵ�������.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-����� �г�(Lv.%d)-\n",rage_lv);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3�ϰ� ���ݷ��� 30 % �����Ѵ�.]
	{
		gotoxy(x, y + 2);
		printf("-����� �г�(Lv.%d)-\n",rage_lv);
	}
	gotoxy(x, y + 3);
	printf("-���ư���-");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 5) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 8)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 5;
			break;
		}


		}
	}
}

int npc1draw() {
	int x = 3;
	int y = 7;
	gotoxy(x, y);
	printf("���� ��� ��ȭ");
	gotoxy(x, y+1);
	printf("�ż��� ȸ�� ��ȭ");
	gotoxy(x, y+2);
	printf("����� �г� ��ȭ");
	gotoxy(x, y + 3);
	printf("���ư���.");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 7) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 10)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 7;
			break;
		}


		}
	}
}

int yesnodraw() {
	int x = 3;
	int y = 8;
	gotoxy(x, y);
	printf("��ȭ�Ѵ�.");
	gotoxy(x, y + 1);
	printf("���� �ʴ´�.");

	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 8) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 9)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 8;
			break;
		}


		}
	}
}



void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int attack(int x,int y) // x = ���� ������ , y = �� ���ݷ�/  ���Ϳ��� ���� ���ط�.
{

	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t =  i + y; // ������ = �������� + �� ���̾� ���ݷ�
	return t;
}

int attacked_monster(int x, int y)
{
	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t = i + y; //������= �������� + �÷��̾� ���ݷ�
	return t;
}

int skill_several_stab(int a)
{
	int temp = rand() % 2 + 2; //����
	int dem;
	if (stab_lv == 1) {
		dem = temp * (a * 0.8);
	}
	else if (stab_lv == 2) {
		dem = temp * (a * 1);
	}
	else if (stab_lv == 3) {
		dem = temp * (a * 1.2);
	}
	else if (stab_lv == 4) {
		dem = temp * (a * 1.5);
	}
	else if (stab_lv == 5) {
		dem = temp * (a * 2.2);
	}
	return dem;
}

int skill_holy_Heal(int x, int y) // ��� ü��,��� ���ݷ�
{
	int t;
	if (heal_lv == 1) {
		t = y * (0.4);
	}
	else if (heal_lv == 2) {
		t = y * (0.6);
	}
	else if (heal_lv == 3) {
		t = y * (0.8);
	}
	x += t;
	return t;
}

int skill_rage(int x)// 3�� ���� ��� ���ݷ� ��Ÿ�� 6
{
	int t;
	if (rage_lv==1) {
		t = x * (0.3); // t(�߰� ���ݷ�) = ���ݷ� * 0.3 �̴�.
	}
	if (rage_lv==2) {
		t = x * (0.5); 
	}	
	if (rage_lv==3) {
		t = x * (0.7); 
	}
	return t; // ���ݷ¿� t�� �߰��Ѵ�.
}

void monster1_move_system_1(char arr[][10],int y, int x) {
	if (kbhit())
	{
		int dirM1 = rand() % 4;
		switch (dirM1) // ���� ����������
		{
		case 0:
			if (arr[y_mon - 1][x_mon] == 0) //�������ϴ� �ڸ��� 0�϶��� ����.
			{
				y_mon--;
				bef_move_monster(y_mon + 1, x_mon);
			}

			break;
		case 1:
			if (arr[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bef_move_monster(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (arr[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bef_move_monster(y_mon, x_mon - 1);
			}
			break;
		case 3:
			if (arr[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bef_move_monster(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}