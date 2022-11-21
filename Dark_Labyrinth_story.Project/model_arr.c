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

void gotoxy(int x, int y);


// �ʱ� �Լ�

int game = 0; // Ÿ��Ʋ�� 0 ���ӽ����� 1

// �޴��Լ�
int titleDraw(); // ����ȭ�� �Լ�.
int proLogueDraw(); //���ѷα� �����Լ�.
int menuDraw(); // �޴� �������Լ�
int skillmenuDraw(); // ��ų ������ �Լ�
//int itemDraw();//������ �����Լ�

int select_num = 0; //������Ȳ ������ �ʱ�ȭ

//�� �����Լ�

int situation_num = 1; //�����̼� �ѹ�

char map_arr_loCation_level_1[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// ��ġ�Լ� ����.

void printQuestion(); // �� ���

int keyControl();

void move_player(int x, int y); //�÷��̾� ��ǥ
void bef_move_player(int x, int y); //�÷��̾� ���� ��ǥ �ʱ�ȭ

void move_monster(int x, int y); // ������ǥ
void bef_move_monster(int x, int y); //���� ���� ��ǥ �ʱ�ȭ


void creaTor_great_Wall(int a, int b); //�׵θ� �� ���� �Լ�

int Player = 1; //�÷��̾� ������
int monster1 = 4; //����1 ������

int x_mon = 0; //���� ��ǥ��
int y_mon = 0;

int monster1_life = 1; // ���Ͱ� ����ִ��� ����

int direct_monswer1 = -1; // ���� ���� ���� �ʱ�ȭ

//�����Լ�
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
	player.attack = 10;
	player.crono = 500;
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

	int cnt_monster1_life = monster1.life;
	int cnt_player_life = player.life;

	int key = 0; // �÷��̾� �̵� ���� 

	int a = 1; //�÷��̾� ���� ��ġ
	int b = 1; //�÷��̾� ���� ��ġ

	int t = 10; // �� ���� ����
	int g = 10; // �� ���� ����

	
	creaTor_great_Wall(t, g); 
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
			printf("\n\n\n  Welcome to my Labirinth. . .");
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

	while (map_arr_loCation_level_1[x_mon][y_mon] != 0) //  ���� ��ȯ ��ǥ ���� 0�϶����� and ĳ���� ���� �ƴҶ�����.
	{
		x_mon = rand() % (t - 2) + 1; // 1,2,3,4,5,6,7,8
		y_mon = rand() % (g - 2) + 1; // 1,2,3,4,5,6,7,8
	}



	while (game == 1)//���������� // ȭ�� ����.
	{

		if (situation_num == 1) //����
		{

			printQuestion();  //�� ǥ��

			move_player(a, b); // ĳ���� �� ��ǥ �Լ�.
			move_monster(y_mon, x_mon); // ���� �� ��ǥ.
			if (kbhit())
			{

				key = _getch();
				bef_move_player(a, b); // ���� �÷��̾��� ��ġ�� �ִ� 1�� ������. 
				switch (key)
				{
				case 72:
					if (map_arr_loCation_level_1[a - 1][b] == 0) //�������ϴ� �ڸ��� 0�϶��� ����.
						a--;
					break;
				case 75:
					if (map_arr_loCation_level_1[a][b - 1] == 0)
						b--;
					break;
				case 77:
					if (map_arr_loCation_level_1[a][b + 1] == 0)
						b++;
					break;
				case 80:
					if (map_arr_loCation_level_1[a + 1][b] == 0)
						a++;
					break;
				default:
					break;
				}

			}
			if (monster1_life == 1)
			{
				if (kbhit())
				{
					direct_monswer1 = rand() % 4; //
					switch (direct_monswer1) // ���� ����������
					{
					case 0:
						if (map_arr_loCation_level_1[y_mon - 1][x_mon] == 0) //�������ϴ� �ڸ��� 0�϶��� ����.
						{
							y_mon--;
							bef_move_monster(y_mon + 1, x_mon);
						}

						break;
					case 1:
						if (map_arr_loCation_level_1[y_mon][x_mon - 1] == 0)
						{
							x_mon--;
							bef_move_monster(y_mon, x_mon + 1);
						}
						break;
					case 2:
						if (map_arr_loCation_level_1[y_mon][x_mon + 1] == 0)
						{
							x_mon++;
							bef_move_monster(y_mon, x_mon - 1);
						}
						break;
					case 3:
						if (map_arr_loCation_level_1[y_mon + 1][x_mon] == 0)
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


			if (monster1_life == 1)
			{
				if (b == x_mon && a == y_mon + 1 ||
					b == x_mon + 1 && a == y_mon ||
					b == x_mon - 1 && a == y_mon ||
					b == x_mon && a == y_mon - 1)
				{
					situation_num = 2;
					Sleep(1000);
					printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
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
					printf("%s�� ���� ���Ͽ���...", a);
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
							monster1_life;
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

	void move_player(int x, int y)
{
	map_arr_loCation_level_1[x][y] = Player;
}
void bef_move_player(int x, int y)
{
	map_arr_loCation_level_1[x][y] = 0;
}

void printQuestion()//�� ���
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf(" %d ", map_arr_loCation_level_1[i][j]);


		}
		printf("\n");
	}

}

void creaTor_great_Wall(int a,int b) // �������
{
	for (int i = 0; i < a; i++)
	{
		map_arr_loCation_level_1[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_1[a-1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < b; j++)
	{
		map_arr_loCation_level_1[j][a-1] = 9;
		map_arr_loCation_level_1[j][0] = 9;
	}
}

void move_monster(int x, int y) // ���� ��ġ ����ȭ
{
	map_arr_loCation_level_1[y_mon][x_mon] = monster1;
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
		printf("-���� ���(Lv.1)-\n"); //[70 % �� ���ݷ����� 2~3�� ���.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-���� ���(Lv.1)-\n"); //[70 % �� ���ݷ����� 2~3�� ���.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-�ż��� ȸ��(Lv.1)-\n");//[���ݷ��� 70 % �� ��ġ�� ü���� ȸ���Ѵ�.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-�ż��� ȸ��(Lv.1)-\n");//[���ݷ��� 70 % �� ��ġ�� ü���� ȸ���Ѵ�.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // ���� �������̰ų� ��Ÿ���� �ȵ�������.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-����� �г�(Lv.1)-\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3�ϰ� ���ݷ��� 30 % �����Ѵ�.]
	{
		gotoxy(x, y + 2);
		printf("-����� �г�(Lv.1)-\n");
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
	int dem = temp * (a * 0.8);
	return dem;
}

int skill_holy_Heal(int x, int y) // ��� ü��,��� ���ݷ�
{
	int t = y * (0.8);
	x += t;
	return t;
}

int skill_rage(int x)// 3�� ���� ��� ���ݷ� ��Ÿ�� 6
{
	int t = x * (0.3); // t(�߰� ���ݷ�) = ���ݷ� * 0.3 �̴�.
	return t; // ���ݷ¿� t�� �߰��Ѵ�.
}