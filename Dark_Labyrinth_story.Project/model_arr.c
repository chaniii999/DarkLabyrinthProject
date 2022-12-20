#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
// 맵을 구성하는 다차원 배열 함수를 만들자.
// 좌표를 정의하는 좌표 배열과 , 실질적인 위치에 해당하는 위치 배열을 만들자.
// 좌표배열은 int 로 위치 배열은 char 로 선언하자.

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define	SUBMIT 4 // 선택 (Enter 키)

const char *specialChar()
{
	return "■";
}
const char* specialChar2()
{
	return "□";
}


void gotoxy(int x, int y);


// 초기 함수

int game = 0; // 타이틀은 0 게임시작은 1

// 메뉴함수
int titleDraw(); // 시작화면 함수.
int proLogueDraw(); //프롤로그 선택함수.
int menuDraw(); // 메뉴 선택지함수
int skillmenuDraw(); // 스킬 선택지 함수
int npc1draw();
int yesnodraw();
//int itemDraw();//아이템 선택함수

int select_num = 0; //전투상황 선택지 초기화

//맵 관련함수

int dengeon_level = 1;

int situation_num = 1; //시츄에이션 넘버

//강화관련
int ganghwa_sit = 0; //강화창

int cost_stab = 50;
int cost_rage = 150;
int cost_heal = 100;




char map_arr_loCation_level_1[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// 위치함수 선언.
char map_arr_loCation_level_2[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// 위치함수 선언.
char map_arr_loCation_level_3[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };
char map_arr_loCation_level_4[15][15];
char map_arr_loCation_level_5[15][15];

void printQuestion_level_1(); // 맵 출력
void printQuestion_level_2(); // 2층 출력
void printQuestion_level_3();
void printQuestion_level_4();
void printQuestion_level_5();

int keyControl();


int t_1 = 10; // 맵 가로 길이
int g_1 = 10; // 맵 세로 길이
int t_2 = 15;
int g_2 = 15;
void monster1_move_system_1(char arr[][10],int a, int b); // 몬스터 무브 내장 함수 1층 몬스터1 



void move_player_1(char arr[][10],int x, int y); //플레이어 좌표
void move_player_2(char arr[][15],int x, int y);
void bef_move_player_1(char arr[][10],int x, int y); //플레이어 이전 좌표 초기화
void bef_move_player_2(char arr[][15], int x, int y);

void move_monster_1(int x, int y); // 몬스터좌표
void move_monster_2(int x, int y);
void bef_move_monster(int x, int y); //몬스터 이전 좌표 초기화


void creaTor_great_Wall_1(char arr[][10], int a, int b); //테두리 벽 제작 함수
void creaTor_great_Wall_2(char arr[][15], int a, int b); //4~5층 내장 벽

int Player = 1; //플레이어 고유값
int monster1 = 4; //몬스터1 고유값
int npc_1 = 5; // npc1고유값.
int enTrance = 3;

int stonColor[4] = { "녹색","빨강색","노란색" }; //스킬강화 힐,연속찌르기,버프


int x_npc=5;
int y_npc=5;

int x_mon = 0; //몬스터 좌표값
int y_mon = 0;

int monster1_life = 1; // 몬스터가 살아있는지 여부
int npc1_life = 1;

//전투함수
int stab_lv = 1;
int rage_lv = 1;
int heal_lv = 1;

int turn = 0;
int cnt_turn_stab = -3;
int cnt_turn_rage = -5;
int cnt_turn_heal = -3;

int attack(int x, int y);  // 공격 함수

int attacked_monster(int x, int y); //피격 함수


char *item[20]; // 문자열을 배열에 넣기위해 * 넣음.


//스킬함수
int skill_several_stab(int a);
int skill_holy_Heal(int x, int y);
int skill_rage(int x);
int cnt_attack = 0;
int rage = 0;

typedef struct objecT
{
	char* name;// 개체명
	int attack;// 공격력
	int life;  // 생명력
	int max_life;// 최대 생명력
	char* item[20];// 아이템칸. 만약 첫칸에 아이템이있다면? for문 사용하여 i++ 해서 재시도하여 장착
	int crono; //화폐
	int exp; // 경험치
	int level;
}oBject;

////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////


int main(void)
{
	srand(time(NULL));
	system("mode con cols=30 lines=12");

	oBject player; //플레이어 정의
	player.name = "player";
	player.attack = 20;
	player.crono = 5000;
	player.level = 1;
	player.exp = 0;
	player.max_life = 50;
	player.life = player.max_life; 

	oBject monster1; //몬스터 1 정의.
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

	int key = 0; // 플레이어 이동 변수 

	int y_p = 1; //플레이어 시작 위치
	int x_p = 1; //플레이어 시작 위치



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
			printf("\n\n\n -프롤로그를 보시겠습니까?-");
			switch (proLogueDraw())
			{
			case 0:
			{
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(1500);
				printf("오늘도 야근이다..\n");
				Sleep(1500);
				printf("지친 몸을 이끌고 집으로 향한다...\n");
				Sleep(1500);
				printf("\"내일은  휴일이니까 푹 쉬자..\"\n");
				Sleep(1500);
				printf("\"어?.. 여긴?... \"\n");
				Sleep(3000);
				game = 1;
			}
			case 1:
			{
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(100);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
		while (map_arr_loCation_level_1[x_mon][y_mon] != 0) //  몬스터 소환 좌표 설정 0일때까지 and 캐릭터 옆이 아닐때까지.
		{
			x_mon = rand() % (t_1 - 3) + 2; // 2,3,4,5,6,7,8,9
			y_mon = rand() % (g_1 - 3) + 2; // 2,3,4,5,6,7,8,9
		}
	}



	while (game == 1)//게임진행중 // 화면 지속.
	{

		if (situation_num == 1) //평상시
		{
			if (dengeon_level == 1)
			{
				printQuestion_level_1();//맵 표시
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
				move_player_1(map_arr_loCation_level_1,y_p, x_p); // 캐릭터 현 좌표 함수.
				move_monster_1(map_arr_loCation_level_1, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_1,y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_1[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_1[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bef_move_monster(y_mon, x_mon);
			}
			if(dengeon_level==2)
			{

				move_player_1(map_arr_loCation_level_2, y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_1(map_arr_loCation_level_2, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_2, y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_2[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_2[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
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
				move_player_1(map_arr_loCation_level_3, y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_1(map_arr_loCation_level_3, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_3, y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_3[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_3[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
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
				move_player_2(map_arr_loCation_level_4, y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_2(map_arr_loCation_level_4, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_2(map_arr_loCation_level_4, y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_4[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_4[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
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
		if (situation_num == 2) // 전투시작연출
		{

			Sleep(100);

			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf(" %s가 나타났다!\n", monster1.name);
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(800);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(500);
			system("cls");
			situation_num = 3;




		}
		if (situation_num == 3) //대치중
		{

			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			printf(" %s의 체력: %d\n\n", monster1.name, monster1.life);
			printf(" 당신의 체력 :%d\n", player.life);
			printf("ㅡㅡㅡㅡ현재 턴:%dㅡㅡㅡ\n", turn);
			switch (menuDraw())//전투선택지
			{
			case 0: //공격
			{
				system("cls");
				turn++;
				cnt_monster1_life = monster1.life;
				cnt_player_life = player.life;
				monster1.life -= attack(monster1.life, player.attack);
				player.life -= attack(player.life, monster1.attack);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(1000);
				printf("% s는 % s에게\n 검을 힘차게 휘둘렀다!\n\n", player.name, monster1.name);
				Sleep(1000);
				printf("%s에게 %d의\n 데미지를 주었다.\n\n", monster1.name, cnt_monster1_life - monster1.life);  // 공격받기전 - 받은후 =데미지
				Sleep(1500);
				if (monster1.life <= 0)
				{
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					system("cls");
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(1000);
					printf("%s를 쓰러트렸다!\n", monster1.name);
					Sleep(1000);
					printf("%d 크로노 를 얻었다!\n", monster1.crono);
					player.crono += monster1.crono;
					Sleep(500);
					printf("%d 경험치를 획득했다!", monster1.exp);
					player.exp += monster1.exp;
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
					printf("%s는 %s에게\n 달려들었다!\n\n", monster1.name, player.name);
					Sleep(1000);
					printf("%s는 %d의\n 데미지를 받었다.\n\n", player.name, cnt_player_life - player.life);
					Sleep(1500);
					if (player.life <= 0)
					{
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("용사는 힘을 다하였다...");
						Sleep(1000);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("		   GAME OVER\n");
						Sleep(1000);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						_getch();
						break;
					}
					system("cls");
					situation_num = 3;
				}
				break;
			}
			case 1: //방어
			{
				turn++;
				cnt_player_life = player.life;
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				player.life -= (attack(player.life, monster1.attack)) / 3;
				printf("%s는 방어태세에 들어갔다!\n", player.name);
				Sleep(1000);
				printf("%s는 %s에게\n 달려들었다!\n\n", monster1.name, player.name);
				Sleep(1500);
				printf("%s는 %d의\n 데미지를 받었다.\n\n", player.name, cnt_player_life - player.life);
				Sleep(1000);
				if (player.life <= 0)
				{
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("%s는 힘을 다하였다...", player.name);
					Sleep(1000);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					system("cls");
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("		   GAME OVER\n");
					Sleep(1000);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					_getch();
					break;
				}
				else
					system("cls");
				situation_num = 3;
				break;
			}
			case 2: //스킬
			{
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf(" %s의 체력: %d\n\n", monster1.name, monster1.life);
				printf(" 당신의 체력 :%d\n", player.life);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				switch (skillmenuDraw())
				{
				case 0: //연속찌르기
				{
					if (turn < cnt_turn_stab + 3)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						printf("%s는 연속 찌르기를 사용했다!\n", player.name);
						Sleep(1000);
						printf("%s는 %s에게 %d의 데미지를 주었다.\n", player.name, monster1.name, skill_several_stab(player.attack));
						Sleep(2000);

						if (monster1.life <= 0)
						{
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							system("cls");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							printf("%s를 쓰러트렸다!\n", monster1.name);
							Sleep(1000);
							printf("%d 크로노 를 얻었다!\n", monster1.crono);
							player.crono += monster1.crono;
							Sleep(500);
							printf("%d 경험치를 획득했다!\n", monster1.exp);
							player.exp += monster1.exp;
							Sleep(500);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
							printf("%s는 %s에게\n 달려들었다!\n\n", monster1.name, player.name);
							Sleep(1000);
							printf("%s는 %d의\n 데미지를 받었다.\n\n", player.name, cnt_player_life - player.life);
							Sleep(1500);
							if (player.life <= 0)
							{
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("용사는 힘을 다하였다...\n");
								Sleep(1000);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								system("cls");
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("		   GAME OVER\n");
								Sleep(1000);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
				case 1://회복
				{
					if (turn < cnt_turn_heal + 3)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_heal = turn;
						cnt_player_life = player.life;
						system("cls");
						player.life += skill_holy_Heal(player.life, player.attack); //힐 시전
						if (player.life > cnt_player_life) // 시전 후 최대생명력보다 높아지게된다면
						{
							player.life = player.max_life;

							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1500);
							printf("신께 기도를 드립니다...\n\n");
							Sleep(1500);
							printf("용사는 %d의 체력을 회복했다!\n", player.max_life - cnt_player_life);
						}
						else
						{
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1500);
							printf("신께 기도를 드립니다...\n\n");
							Sleep(1500);
							printf("용사는 %d의 체력을 회복했다!\n", skill_holy_Heal(player.life, player.attack));
						}
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(2000);
						system("cls");
						break;
					}
				}
				case 2: //분노
				{
					if (rage == 0 && turn < cnt_turn_rage + 5)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						situation_num = 3;
					}
					else if (rage == 1)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("용사는 울부짖었다.\n\n현재 턴%d  저장된 턴%d\n", turn, cnt_turn_rage);
						Sleep(1500);
						printf(" \"우 오 오 오 ! ! !\"\n\n");
						player.attack += skill_rage(player.attack);
						Sleep(1500);
						printf("용사의 공격력이 일시적으로 증가했다!\n%d %d\n", player.attack, cnt_attack);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(2000);
						system("cls");
						situation_num = 3;
						break;
					}
				}
				case 3: //돌아간다
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
			case 3: // 아이템
			{
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf("사용할 아이템을 선택하세요. \n");
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
			printf("\n\n신비한 녹색 빛을 띄는 오래된 석상이 앞에 있다...\n");
			Sleep(1500);
			printf("\n공물함같이 보이는 상자가 있다.\n");
			Sleep(1000);
			printf("\n크로노를 바치면 무슨 일이 일어날 것 같다.\n");
			Sleep(1500);
			system("cls");
			situation_num = 5;
		}

		if (situation_num == 5)
		{
			printf("     <신성한 녹색 석상>\n");
			printf("\n");
			Sleep(1000);
			printf("   연속 찌르기 Lv.%d\n   신성한 회복 Lv.%d\n   용사의 분노 Lv.%d\n",stab_lv,heal_lv,rage_lv);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
			printf("내 크로노 : %d", player.crono);
			switch (npc1draw())
			{
			case 0:
			{
				system("cls");
				Sleep(1000);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				Sleep(1500);
				printf("%d크로노가 필요합니다.\n\n연속 찌르기를 강화하시겠습니까?\n",cost_stab);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_stab)
					{
						player.crono -= cost_stab;

						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1500);
						printf("\n\n\n  연속 찌르기의 레벨이 상승했습니다.");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1000);
						printf("\n\n크로노가 부족합니다.");
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
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				Sleep(1500);
				printf("%d크로노가 필요합니다.\n 신성한 회복을 강화하시겠습니까?\n",cost_heal);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_heal) {
						player.crono -= cost_heal;
						heal_lv++;
						printf("\n\n\n  신성한 회복의 레벨이 상승했습니다.");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1000);
						printf("\n\n크로노가 부족합니다.");
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
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				Sleep(1500);
				printf("%d크로노가 필요합니다. 강화하시겠습니까?", cost_rage);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_rage)
					{
						player.crono -= cost_rage;
						rage_lv++;
						printf("\n\n\n  용사의 분노의 레벨이 상승했습니다.");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1000);
						printf("\n\n크로노가 부족합니다.");
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
			case 3: // 돌아간다.
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
				player.attack = cnt_attack; // 공격력을 레이지 전에 적용해놨던 공격력으로 되돌림.

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

void printQuestion_level_1()//맵 출력
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

void printQuestion_level_2()//맵 출력
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

void printQuestion_level_3()//맵 출력
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

void printQuestion_level_4()//맵 출력
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

void printQuestion_level_5()//맵 출력
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


void creaTor_great_Wall_1(char arr[][10],int a,int b) // 벽만들기
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

void creaTor_great_Wall_2(char arr[][15],int a, int b) // 벽만들기
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



void move_monster_1(char arr[][10],int x, int y) // 몬스터 위치 동기화
{
	arr[x][y] = monster1;
}
 
void move_monster_2(char arr[][15], int x, int y) // 몬스터 위치 동기화
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
	printf("-예-");
	gotoxy(x, y + 1);
	printf("-아니오-");

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
	printf("공격");
	gotoxy(x, y + 1);
	printf("방어");
	gotoxy(x, y + 2);
	printf("스킬");
	gotoxy(x, y + 3);
	printf("아이템");
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
		printf("-연속 찌르기(Lv.%d)-\n",stab_lv); //[70 % 의 공격력으로 2~3번 찌른다.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-연속 찌르기(Lv.%d)-\n",stab_lv); //[70/80/100 % 의 공격력으로 2~3번 찌른다.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-신성한 회복(Lv.%d)-\n",heal_lv);//[공격력의 40/60/80 % 의 수치로 체력을 회복한다.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-신성한 회복(Lv.%d)-\n",heal_lv);//[공격력의 70 % 의 수치로 체력을 회복한다.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // 현재 버프중이거나 쿨타임이 안돌았을떄.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-용사의 분노(Lv.%d)-\n",rage_lv);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3턴간 공격력이 30 % 증가한다.]
	{
		gotoxy(x, y + 2);
		printf("-용사의 분노(Lv.%d)-\n",rage_lv);
	}
	gotoxy(x, y + 3);
	printf("-돌아간다-");
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
	printf("연속 찌르기 강화");
	gotoxy(x, y+1);
	printf("신성한 회복 강화");
	gotoxy(x, y+2);
	printf("용사의 분노 강화");
	gotoxy(x, y + 3);
	printf("돌아간다.");
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
	printf("강화한다.");
	gotoxy(x, y + 1);
	printf("하지 않는다.");

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

int attack(int x,int y) // x = 몬스터 라이프 , y = 내 공격력/  몬스터에게 가한 피해량.
{

	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t =  i + y; // 데미지 = 랜덤난수 + 플 레이어 공격력
	return t;
}

int attacked_monster(int x, int y)
{
	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t = i + y; //데미지= 랜덤난수 + 플레이어 공격력
	return t;
}

int skill_several_stab(int a)
{
	int temp = rand() % 2 + 2; //난수
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

int skill_holy_Heal(int x, int y) // 용사 체력,용사 공격력
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

int skill_rage(int x)// 3턴 동안 용사 공격력 쿨타임 6
{
	int t;
	if (rage_lv==1) {
		t = x * (0.3); // t(추가 공격력) = 공격력 * 0.3 이다.
	}
	if (rage_lv==2) {
		t = x * (0.5); 
	}	
	if (rage_lv==3) {
		t = x * (0.7); 
	}
	return t; // 공격력에 t를 추가한다.
}

void monster1_move_system_1(char arr[][10],int y, int x) {
	if (kbhit())
	{
		int dirM1 = rand() % 4;
		switch (dirM1) // 몬스터 비전투패턴
		{
		case 0:
			if (arr[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
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