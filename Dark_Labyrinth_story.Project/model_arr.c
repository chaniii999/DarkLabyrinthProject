#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#pragma warning(disable:4996)

// 맵을 구성하는 다차원 배열 함수를 만들자.
// 좌표를 정의하는 좌표 배열과 , 실질적인 위치에 해당하는 위치 배열을 만들자.
// 좌표배열은 int 로 위치 배열은 char 로 선언하자.

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define	SUBMIT 4 // 선택 (Enter 키)

void CursorView();

const char* specialChar()
{
	return "■";
}
const char* specialChar2()
{
	return "□";
}
const char* specialChar3()
{
	return "＆";
}
const char* specialChar4()
{
	return "┌";
}
const char* specialChar5()
{
	return "└";
}
const char* specialChar6()
{
	return "┘";
}
const char* specialChar7()
{
	return "┐";
}


void gotoxy(int x, int y);


// 초기 함수

int game = 1; // 타이틀은 0 게임시작은 1

// 메뉴함수
int titleDraw(); // 시작화면 함수.
int proLogueDraw(); //프롤로그 선택함수.
int menuDraw(); // 메뉴 선택지함수
int skillmenuDraw(); // 스킬 선택지 함수
int npc1draw();
int yesnodraw();
int blacksdraw();
void conversationprint();
void storeframe();
int weapondraw();
int buyornodraw();
int doordraw();
//int itemDraw();//아이템 선택함수

int select_num = 1; //전투상황 선택지 초기화

//맵 관련함수

int dengeon_level = 3;

int situation_num = 1; //시츄에이션 넘버

//강화관련
int ganghwa_sit = 0; //강화창

int cost_stab = 50;
int cost_rage = 150;
int cost_heal = 100;

swordon = 0;


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

void status(char name, int cnt_life, int max_life, int cnt_mana, int max_mana, int crono);


int t_1 = 10; // 맵 가로 길이
int g_1 = 10; // 맵 세로 길이
int t_2 = 15;
int g_2 = 15;
void monster1_move_system_1(char arr[][10], int a, int b); // 몬스터 무브 내장 함수 1층 몬스터1 



void move_player_1(char arr[][10], int x, int y); //플레이어 좌표
void move_player_2(char arr[][15], int x, int y);
void bef_move_player_1(char arr[][10], int x, int y); //플레이어 이전 좌표 초기화
void bef_move_player_2(char arr[][15], int x, int y);

void move_monster_1(char arr[][10], int x, int y); // 몬스터좌표
void move_monster_2(char arr[][15], int x, int y);
void bef_move_monster(int x, int y); //몬스터 이전 좌표 초기화


void creaTor_great_Wall_1(char arr[][10], int a, int b); //테두리 벽 제작 함수
void creaTor_great_Wall_2(char arr[][15], int a, int b); //4~5층 내장 벽

int Player = 1; //플레이어 고유값
int monster1 = 4; //몬스터1 고유값
int npc_1 = 5; // npc1고유값.
int enTrance = 3;
int black_s = 6;


int x_npc = 5;
int y_npc = 5;

int x_black = 5;
int y_black = 5;

int x_mon = 0; //몬스터 좌표값
int y_mon = 0;

int monster1_life = 0; // 몬스터가 살아있는지 여부
int npc1_life = 1;
int blacks_life = 1;




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


char* itembox[20]; // 문자열을 배열에 넣기위해 * 넣음.


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
	int mana;
	int max_mana;
	char* item[20];// 아이템칸. 만약 첫칸에 아이템이있다면? for문 사용하여 i++ 해서 재시도하여 장착
	int crono; //화폐
	int exp; // 경험치
	int level;
}oBject;

typedef struct item
{
	char* name; //장비이름
	int attack; //장비 공격력
	int life; //장비 추가생명력
	int critical;//치명타확률
	int evasion; //회피력
	int cost; //가격
	int onoff; //보유중인지 아닌지
}iteM;

char player_name[20] = "ricaus";


////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////


int main(void)
{
	srand(time(NULL));
	system("mode con cols=50 lines=19");
	CursorView(); //커서안보임

	oBject player; //플레이어 정의
	player.name = player_name;
	player.attack = 20;
	player.crono = 5000;
	player.max_life = 30;
	player.life = player.max_life;
	player.max_mana = 30;
	player.mana = player.max_mana;


	oBject npc1; // 5
	npc1.name = "신성한 녹색 조각상";

	oBject blacks; //6
	blacks.name = "늙은 대장장이";

	oBject bat; //박쥐 12
	bat.name = "박쥐";
	bat.attack = 3;
	bat.life = 10;
	bat.crono = rand() % 12 + 10;

	oBject moth; // 13
	moth.name = "나방";
	moth.attack = 2;
	moth.life = 7;
	moth.crono = rand() % 15 + 15;

	oBject spider; // 14
	spider.name = "거미";
	spider.attack = 4;
	spider.life = 6;
	spider.crono = rand() % 25 + 10;

	oBject kero; // 16
	kero.name = "케르베로스";
	kero.attack = 20;
	kero.life = 60;
	kero.crono = rand() % 100 + 250;

	oBject monster1; // 17
	monster1.name = "블랙-드래곤";
	monster1.attack = 17;
	monster1.life = 130;
	monster1.crono = rand() % 150 + 360;


	int cnt_monster1_life = monster1.life;
	int cnt_player_life = player.life;

	iteM sword;
	sword.name = "어두운 검";
	sword.attack = 20;
	sword.critical = 20;
	sword.evasion = 5;
	sword.cost = 400;
	sword.onoff = 0;

	iteM spear;
	spear.name = "푸른 창";
	spear.attack = 16;
	spear.critical = 15;
	spear.cost = 250;

	iteM axe;
	axe.name = "양날도끼";
	axe.attack = 12;
	axe.critical = 15;
	axe.cost = 180;

	iteM Excalibur;
	Excalibur.name = "Caladfwich";
	Excalibur.attack = 35;
	Excalibur.critical = 40;
	Excalibur.evasion = 15;
	Excalibur.cost = 1000;

	iteM daggar;
	daggar.name = "예리한 단검";
	daggar.attack = 10;
	daggar.critical = 45;
	daggar.evasion = 20;
	daggar.cost = 270;

	iteM iron;
	iron.name = "철 갑옷";
	iron.life = 25;
	iron.evasion = 5;
	iron.cost = 150;

	iteM fast;
	fast.name = "깃털 갑옷";
	fast.life = 15;
	fast.evasion = 40;
	fast.cost = 350;

	iteM adaman;
	adaman.name = "아다만티움 갑옷";
	adaman.life = 70;
	adaman.evasion = 15;
	adaman.cost = 700;

	iteM coward;
	coward.name = "겁쟁이 갑옷";
	coward.life = 10;
	coward.evasion = 50;
	coward.cost = 100;


	







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

	if (blacks_life == 1) {
		map_arr_loCation_level_3[5][5] = black_s;
	}



	creaTor_great_Wall_1(map_arr_loCation_level_1, t_1, g_1);
	creaTor_great_Wall_1(map_arr_loCation_level_2, t_1, g_1);
	creaTor_great_Wall_1(map_arr_loCation_level_3, t_1, g_1);
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

		int exMode = _setmode(_fileno(stdout), 0x00020000);
		_setmode(_fileno(stdout), 0x00020000);

		wprintf(L"\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣀⣀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣶⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		Sleep(300);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡏⠙⢳⡄⣠⠤⢤⡀⢠⣤⣀⣀⠀⣿⣠⡤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		Sleep(250);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⢸⡇⢑⣿⣸⡇⠘⣿⣭⣹⠀⣿⣬⣔⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		Sleep(220);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣧⡶⠟⠀⢾⣁⣼⣇⢠⣿⠈⠁⠀⣿⠆⢿⣀⡀⠀⠀\n");
		Sleep(200);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠉⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		Sleep(150);
		wprintf(L"⠀⠀⠀⠀⠀⠀⢀⣤⣠⣤⣤⣀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⢠⣄⠀⠀⠀\n");
		Sleep(100);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⢹⡝⠀⠈⣿⠀⣠⠤⣄⢀⠘⣿⠀⠀⠀⣀⠀⢀⣤⢠⣤⣀⣀⠄⣒⠁⣀⠀⠀⠀⢤⣾⡧⣤⠈⣿⢁⣀⠀⠀\n");
		Sleep(80);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⣾⡗⢶⣾⢋⠀⢓⣛⣸⡇⢰⣷⡛⠳⡔⣽⠀⢸⡇⠀⣿⢫⣹⠂⢿⡀⣽⡾⠛⣷⠀⢸⠇⠁⠀⣿⡟⠙⡇⠀⠀\n");
		Sleep(50);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⢾⡇⠀⢿⡽⠇⣿⣁⣽⣇⢸⡿⣤⣴⠇⠹⠧⠺⡇⢀⣧⠈⠁⠀⣼⡇⣿⡇⢰⣿⠀⢸⣜⣋⠗⣿⡅⢠⡇⠀\n");
		Sleep(20);
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠉⠀⠁⠀⠀⠀⠸⣙⣡⡇⠀⠁⠀⠀⠀⠉⠀⠈⠀⠈⠛⠀⠈⠈⠁⠀⠈⠀⠀⠛⠃⠀⠀\n");
		wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");


		fflush(stdout);
		_setmode(_fileno(stdout), exMode);

		Sleep(500);

		//printf("\n\n                 [Dark Labyrinth]\n");
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
			break;
		}
		case 1:
		{
			break;
		}
		case 2:
			exit(0);




			break;
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
				//status(player.name, player.life, player.max_life, player.mana, player.max_mana, player.crono);

				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 2);
				printf("MANA ( %d / %d )", player.mana, player.max_mana);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);

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
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 2);
				printf("MANA ( %d / %d )", player.mana, player.max_mana);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
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
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 2);
				printf("MANA ( %d / %d )", player.mana, player.max_mana);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
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
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 2);
				printf("MANA ( %d / %d )", player.mana, player.max_mana);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
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
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 2);
				printf("MANA ( %d / %d )", player.mana, player.max_mana);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_5[12][12] == Player)
				{
					dengeon_level = 9;
					x_p = 2;
					y_p = 2;
				}
			}



			if (dengeon_level == 1)
			{
				move_player_1(map_arr_loCation_level_1, y_p, x_p); // 캐릭터 현 좌표 함수.
				move_monster_1(map_arr_loCation_level_1, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(map_arr_loCation_level_1, y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
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
			if (dengeon_level == 2)
			{

				move_player_1(map_arr_loCation_level_2, y_p, x_p); // 캐릭터 현 좌표 함수.
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
					map_arr_loCation_level_2[5][5] = 0;
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
				if (x_p == x_black && y_p == y_black + 1 ||
					x_p == x_black + 1 && y_p == y_black ||
					x_p == x_black - 1 && y_p == y_black ||
					x_p == x_black && y_p == y_black - 1)
				{
					situation_num = 6;
					map_arr_loCation_level_3[5][5] = 0;
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
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(2000);
							y_mon = 15;
							x_mon = 15;
							bef_move_monster(y_mon, x_mon);
							system("cls");
							monster1_life = 0;
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
			if (npc1_life == 0)
			{
				situation_num = 1;
			}
			else
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
		}

		if (situation_num == 5)
		{
			printf("     <신성한 녹색 석상>\n");
			printf("\n");
			Sleep(1000);
			printf("   연속 찌르기 Lv.%d\n   신성한 회복 Lv.%d\n   용사의 분노 Lv.%d\n", stab_lv, heal_lv, rage_lv);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
			printf("   내 크로노 : %d", player.crono);
			switch (npc1draw())
			{
			case 0:
			{
				system("cls");
				Sleep(1000);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				Sleep(1500);
				printf("%d크로노가 필요합니다.\n\n연속 찌르기를 강화하시겠습니까?\n", cost_stab);
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
				printf("%d크로노가 필요합니다.\n\n신성한 회복을 강화하시겠습니까?\n", cost_heal);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_heal)
					{
						player.crono -= cost_heal;

						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1500);
						printf("\n\n\n  신성한 회복의 레벨이 상승했습니다.");
						Sleep(1500);
						if (heal_lv == 1) // 50.
						{
							heal_lv++;
							cost_heal = 200;
						}
						else if (heal_lv == 2) {
							cost_heal = 350;
							heal_lv++;
						}
						else if (heal_lv == 3)
						{
							cost_heal = 550;
							heal_lv++;
						}
						else if (heal_lv == 4)
						{
							cost_heal = 800;
							heal_lv++;
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
			case 2:
			{
				system("cls");
				Sleep(1000);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				Sleep(1500);
				printf("%d크로노가 필요합니다.\n\n용사의 분노를 강화하시겠습니까?\n", cost_rage);
				switch (yesnodraw())
				{
				case 0:
				{
					system("cls");
					if (player.crono >= cost_rage)
					{
						player.crono -= cost_rage;

						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
						Sleep(1500);
						printf("\n\n\n  용사의 분노의 레벨이 상승했습니다.");
						Sleep(1500);
						if (rage_lv == 1) // 50.
						{
							rage_lv++;
							cost_rage = 200;
						}
						else if (rage_lv == 2) {
							cost_rage = 350;
							rage_lv++;
						}
						else if (rage_lv == 3)
						{
							cost_rage = 550;
							rage_lv++;
						}
						else if (rage_lv == 4)
						{
							cost_rage = 800;
							rage_lv++;
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
			case 3: // 돌아간다.
			{
				map_arr_loCation_level_2[5][5] = 0;
				npc1_life = 0;
				situation_num = 1;
				break;
			}
			default:
			{
				map_arr_loCation_level_2[5][5] = 0;
				npc1_life = 0;
				situation_num = 1;
			}
			}//sw_ed
		}

		if (situation_num == 6)
		{
			system("cls");
			printf("깡... 깡.. 깡..\n\n");
			Sleep(1000);
			printf("철 두드리는 소리가 계속해서 울린다.\n\n");
			Sleep(1000);
			printf("흰머리가 난 늙은 할아버지가 검을 두드리고 있다.\n\n");
			Sleep(1000);
			system("cls");
			situation_num = 7;
		}

		if (situation_num == 7)
		{

			int exMode = _setmode(_fileno(stdout), 0x00020000);
			_setmode(_fileno(stdout), 0x00020000);
			wprintf(L"             ⣿⣛⣻⠁⠀⠀⠁⠀⠀⣿⣿⡿⠋⠉⠉⠙⣿⣿⣿⣿⣿⣿⣿⣿\n");
			wprintf(L"             ⣿⣿⠏⠠⣀⣀⣇⣀⣀⣿⣿⠁⡀⢀⠀⣴⠛⣿⣿⣿⣿⣿⣿⣿\n");
			wprintf(L"             ⣿⣿⠀⠀⠀⣸⣿⣿⣿⣿⣿⣦⡂⣠⣴⣿⡞⡿⠿⣿⣿⣿⣿⣿\n");
			wprintf(L"             ⣿⣿⣄⡤⠂⠀⠩⠋⠉⡏⢿⣿⣿⣿⣿⣿⡇⡇⠀⠀⠙⢿⣿⣿\n");
			wprintf(L"             ⣿⣿⣿⣷⣄⠀⠃⠀⢠⠀⢸⣿⣿⣿⣿⣿⠁⠇⠀⠀⡠⠒⢻⣿\n");
			wprintf(L"             ⣿⣿⣿⣿⣿⣾⣄⠀⠸⠀⠸⡀⠈⠛⠉⢸⠀⠘⣄⠎⠀⠀⠀⣿\n");
			wprintf(L"             ⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠈⠀⠀⠀⠁⠀⠀⢈⠦⠤⢄⢀⣿\n");
			wprintf(L"             ⣿⠛⠛⠛⠛⠛⠛⠛⠓⠒⢺⣿⣷⣶⣶⠁⠀⠀⢱⣶⣶⣶⣾⣿\n");
			wprintf(L"             ⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠰⠀⠢⣀⢀⡘⢀⡀⢴⣿⣿\n");
			wprintf(L"             ⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿\n");
			wprintf(L"             ⣿⣿⣿⣿⣧⣤⣤⣤⣤⣤⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣼⣿⣿\n");

			fflush(stdout);
			_setmode(_fileno(stdout), exMode);

			Sleep(500);
			conversationprint();
			switch (blacksdraw())
			{
			case 0:
			{
				situation_num = 8; //상점ui
				break;
			}
			case 1:
			{
				map_arr_loCation_level_3[5][5] = 0;
				blacks_life= 0;
				situation_num = 1;
				break;
			}
			}
		}

		if (situation_num == 8)
		{
			int ix = 16; //이미지 ~48 max= 32
			int iy = 2; // max 11
			int qx = 2; //~48
			int qy = 14; //~18
			system("cls");
			storeframe();
			switch (weapondraw())
			{
			case 0:
			{
			
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"   ⢀⣶⣀⠀\n");
				gotoxy(ix, iy+1);
				wprintf(L"   ⠀⠈⠛⠷⣤⣀⣤⢠⡀\n");
				gotoxy(ix, iy+2);
				wprintf(L"   ⠀⠀⠀⠀⢨⡿⠷⣼⣆⡀\n");
				gotoxy(ix, iy+3);
				wprintf(L"⠀   ⠀⠀⠠⠛⠓⠞⠛⢿⣿⣦⣄⠀\n");
				gotoxy(ix, iy+4);
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢿⣿⣦⡄\n");
				gotoxy(ix, iy+5);
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣿⣷⣤⡀\n");
				gotoxy(ix, iy+6);
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣷⣄⡀\n");
				gotoxy(ix, iy+7);
				wprintf(L"⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣶⣄\n");
				gotoxy(ix, iy+8);
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣆\n");
				gotoxy(ix, iy+9);
				wprintf(L"⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠑\n");
				

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf(" [ 어두운 검 ]  1000 Crono 보유한 Crono : %d\n", player.crono);
				printf(" 긴 리치에 비해 무게는 가볍다.\n");
				printf(" 바라보고 있으면 그 검은 도신에 \n 빨려들어갈 것 같다...");
			
				switch (buyornodraw())
				{
				case 0:
				{
					if (player.crono >= sword.cost)
					{
						swordon = 1;
						player.crono -= sword.cost;
						_getch();
						break;
						gotoxy(qx, qy);
						printf("어두운 검을 구입했습니다.");
					}
					else
					{
						gotoxy(qx, qy);
						printf("보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}

				
			}
			default:
				break;
			}

			//itemlistdraw();
		}



		if (situation_num == 12) // 찢어진 쪽지
		{
			printf("\n\n기분 좋은 하루다.\n\n");;
			printf("언젠가 나도 저 하늘을 나는 새처럼 되고싶다고 했다.\n");
			printf("아빠는 나를 보며 기특해하셨다.\n");
		}

		if (situation_num == 14)
		{
			printf("온 세상이 빨갰다.\n");
			printf("아빠는 내 손을 잡고 어딘가로 뛰어가고 있었다.\n");
			printf("순간 커다란 붉은 눈동자가 이쪽을 보았다.\n");
			printf("무서웠다\n");
			printf("하지만 어딘가 친근했다.\n");
			printf("나는  어째선지 생기는 이 감정을 무시하며 달렸다.\n");
			printf("난 이 날에 매캐한 냄새를 잊지 못했다.\n");
		}

		if(situation_num==15)
		{
			printf("어느날이었다.\n");
			printf("할일을 끝내놓은 후 난 한가롭게 낮잠을 자고 있었다\n");
			printf("바깥이 시끄러워졌다.\n");
			printf("이내 아버지는 집에서 기다리라고 말씀하신 후 모르는 사람들과 함께 어딘가로 향하셨다\n");
			printf("그 날 저녁 아버지는 돌아오지 않으셨다.\n");
		}

		if (situation_num == 16)
		{
			printf("다음날 나는 동네를 돌아다녔다.\n");
			printf("하지만 아무도 아버지가 어디에 가셨는지 알지못했다\n");
			printf("숨이 차게 달렸다.\n");
			printf("더 이상 서있을 힘이 없다고 생각했을 때\n");
			printf("로브를 입은 괴상한 차림에 청년이 다가왔다.");
			printf("\"너희 아버지는 미궁에 갇혔단다.\"");
			printf("\"그것을 너가 무찌른다면 그곳에서 나올수있게 도와주마...\"");
		}

		if (situation_num == 17)
		{
			printf("준비는 끝났다.\n");
			printf("지난 몇십년동안 이 순간을 고대해왔다.\n\n");
			printf("이 일이 끝나면 내 마음속에서 들끓는 증오도 평안을 되찾을까\n\n");
			printf("인간은 자유를 원한다.\n\n");
			printf("난 빼앗긴 자유를 원한다.\n\n");
		}

		if (situation_num == 171) //퍼즐
		{
			printf("석판이 보인다.");
		}

		if (situation_num == 172) //주검
		{
			printf("-노트에는 이렇게 써져있다.\n\n");
			printf("자유는 가려지는 것이 아니다.\n\n");
			printf("찾아라\n\n");
			printf("떠나라\n\n");
			printf("너의 의지를 실현시키는 것이야말로 자유다.\n\n");
		}

		if (situation_num == 173) //두갈래길
		{
			printf("가시가 엉켜져있는 형상을 한 거대한 문과 꺼림직해보이는 붉은 통로가 있다.\n\n");
			printf("출구로 보이는 가시문의 열쇠구멍에서 빛이 새어나오고있다.\n\n");
			printf("어디로 갈까?\n\n");
			switch (doordraw())
			{
			case 0: //가시문
			{
				printf("-열쇠를 넣고 돌렸다.\n\n");
				printf("지금껏 한번도 열리지않았던 문이 굉음을 내며 그 뒤를 보여주고 있었다.\n\n");
				printf(". . . 난 자유다.\n\n");
				printf("이 위험한 미궁을 답사한다는 것은 어리석은 일이었다.\n\n");
				printf("아버지의 마지막 모습도 확인했다.\n\n");
				printf("그리고 결국 난 살아남았다.\n\n");
				printf("END - 거짓된 자유");
			}
			case 1: //붉은 통로
			{
				printf("붉은 길이 구불구불하게 나있다.");
				printf("그때 맡았던 매캐한 냄새가 나는 것 같다.");
				printf("하염없이 걸었다.");
				printf("어디선가 비명소리가 들려오는 듯 했다.");
				Sleep(1000);
				printf("진실을 마주할 시간이다.");
				situation_num = 8;
			}
			case 2: //돌아간다
			{
				situation_num = 1;
				break;
			}
			default:
				break;
			}

			
		}

		if (situation_num == 181)
		{
			printf("-니 죄를 묻겠다.\n\n");
			Sleep(500);
			_getch();
			printf("베르닉스와 함께 작당모의를 했다는게 사실이더냐\n\n");
			Sleep(500);
			_getch();
			printf("-왕이시여 결단코 아닙니다.\n\n");
			Sleep(500);
			_getch();
			printf("저는 그저 자유를 꿈꾸는 도구를 만들었을뿐입니다.\n\n");
			Sleep(500);
			_getch();
			printf("-네 이놈 그게 이 나라에서 어떤 의미를 갖고있는지 알고있을터\n\n");
			Sleep(500);
			_getch();
			printf("그럼에도 불구하고 너는 신성불가침의 영역에 그 불경한 손을 뻗겠다는것이냐\n\n");
			Sleep(500);
			_getch();
			printf("-……저는 그러한 의도로 만들지않았습니다\n\n");
			Sleep(500);
			_getch();
			printf("-네놈의 발상이 네놈의 발목을 잡는구나\n\n");
			Sleep(500);
			_getch();
			printf("평생 너의 과오를 후회하며 발버둥쳐보아라\n\n");
			Sleep(500);
			_getch();
			printf("그게 짊어져야할 업이다.\n\n");
			Sleep(500);
			_getch();

		}

		if (situation_num == 91)
		{
			printf("격한 싸움이 마무리되어갈 때 쯤\n\n");
			Sleep(500);
			_getch();
			printf("그곳엔 피를 흝뜨리며 거칠게 숨을 몰아쉬고있는 연약한 생명체 밖에 없었다.\n\n");
			Sleep(500);
			_getch();
			printf("숨을 가다듬으며 물웅덩이에 비친 내 모습을 보았다.\n\n");
			Sleep(500);
			_getch();
			printf("그 눈동자다\n\n");
			Sleep(500);
			_getch();
			printf("잊혀지지않았던 그 눈동자\n\n");
			Sleep(500);
			_getch();
			printf("비로소 나는 깨달았다\n\n");
			Sleep(500);
			_getch();
			printf("내 앞에 그는 아무 움직임이 없었다\n\n");
			Sleep(500);
			_getch();
			printf("그저 그곳에 있을뿐이다\n\n");
			Sleep(500);
			_getch();
			printf("\"넌 자유야\"\n\n");
			Sleep(500);
			_getch();
			printf("그는 드디어 자유를 되찾았다.\n\n");
			Sleep(500);
			_getch();
			printf("나는 드디어 자유를 되찾았다.\n\n");
			Sleep(500);
			_getch();
			printf("END - 자유의 날개\n\n");
			Sleep(500);
			_getch();

		}

		if (situation_num == 92)
		{
			printf("격한 싸움이 마무리 되어갈 때 쯤\n\n");
			Sleep(500);
			_getch();
			printf("끝없는 증오는 계속해서 나를 잠식해온다.\n\n");
			Sleep(500);
			_getch();
			printf("그것의 숨통을 끊기위해 나는 마지막 손짓을 끝냈다.\n\n");
			Sleep(500);
			_getch();
			printf("그 순간 그것의 눈동자에 비친 내 눈동자를 바라보았다.\n\n");
			Sleep(500);
			_getch();
			printf("그 눈동자다.\n\n");
			Sleep(500);
			_getch();
			printf("증오스러운 추악한 그 눈동자.\n\n");
			Sleep(500);
			_getch();
			printf("나는 비로소 깨달았다.\n\n");
			Sleep(500);
			_getch();
			printf("내 앞에 그것은 아무 움직임이 없었다.\n\n");
			Sleep(500);
			_getch();
			printf("그저 그곳에 있을뿐이다.\n\n");
			Sleep(500);
			_getch();
			printf("\"넌 자유야\"\n\n");
			Sleep(500);
			_getch();
			printf("컴컴한 미궁속에 나만이 남겨져있었다.\n\n");
			Sleep(500);
			_getch();
			printf("컴컴한 미궁속에 그것만이 남아있었다.\n\n");
			Sleep(500);
			_getch();
			printf("END - 증오의 늪\n\n");
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

void move_player_1(char arr[][10], int x, int y)
{
	arr[x][y] = Player;
}

void move_player_2(char arr[][15], int x, int y)
{
	arr[x][y] = Player;
}


void bef_move_player_1(char arr[][10], int x, int y)
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
		printf("     ");
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_1[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_1[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_1[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_1[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else
				printf(" %d", map_arr_loCation_level_1[i][j]);
		}
		printf("\n");
	}
}

void printQuestion_level_2()//맵 출력
{
	for (int i = 0; i < 10; i++)
	{
		printf("     ");
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_2[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_2[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_2[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_2[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else
				printf(" %d", map_arr_loCation_level_2[i][j]);
		}
		printf("\n");
	}
}

void printQuestion_level_3()//맵 출력
{
	for (int i = 0; i < 10; i++)
	{
		printf("     ");
		for (int j = 0; j < 10; j++)
		{
			if (map_arr_loCation_level_3[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_3[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_3[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_3[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else
				printf(" %d", map_arr_loCation_level_3[i][j]);
		}
		printf("\n");
	}
}

void printQuestion_level_4()//맵 출력
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map_arr_loCation_level_4[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_4[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_4[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_4[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else
				printf(" %d", map_arr_loCation_level_4[i][j]);
		}
		printf("\n");
	}
}

void printQuestion_level_5()//맵 출력
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map_arr_loCation_level_5[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_5[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_5[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_5[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else
				printf(" %d", map_arr_loCation_level_5[i][j]);
		}
		printf("\n");
	}
}


void creaTor_great_Wall_1(char arr[][10], int a, int b) // 벽만들기
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

void creaTor_great_Wall_2(char arr[][15], int a, int b) // 벽만들기
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



void move_monster_1(char arr[][10], int x, int y) // 몬스터 위치 동기화
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

	if (key == 72)
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
	int x = 14;
	int y = 14;
	gotoxy(x, y);
	printf("[Open your eyes..]");
	gotoxy(x, y + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("*chaniii999's GitHub*");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x, y + 2);
	printf("[Exit]");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 16)
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
			return y - 14;
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

void status(char name, int cnt_life, int max_life, int cnt_mana, int max_mana, int crono) {
	int x = 30;
	int y = 5;
	gotoxy(x, y);
	printf("%s", name);
	gotoxy(x, y + 1);
	printf("LIFE ( %d / %d )", cnt_life, max_life);
	gotoxy(x, y + 2);
	printf("MANA ( %d / %d )", cnt_mana, max_mana);
	gotoxy(x, y + 3);
	printf("CRONO : %d", crono);
}

int menuDraw() {
	int x = 3;
	int y = 5;
	gotoxy(x, y);
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
		printf("-연속 찌르기(Lv.%d)-\n", stab_lv); //[70 % 의 공격력으로 2~3번 찌른다.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-연속 찌르기(Lv.%d)-\n", stab_lv); //[70/80/100 % 의 공격력으로 2~3번 찌른다.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-신성한 회복(Lv.%d)-\n", heal_lv);//[공격력의 40/60/80 % 의 수치로 체력을 회복한다.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-신성한 회복(Lv.%d)-\n", heal_lv);//[공격력의 70 % 의 수치로 체력을 회복한다.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // 현재 버프중이거나 쿨타임이 안돌았을떄.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-용사의 분노(Lv.%d)-\n", rage_lv);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3턴간 공격력이 30 % 증가한다.]
	{
		gotoxy(x, y + 2);
		printf("-용사의 분노(Lv.%d)-\n", rage_lv);
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
	gotoxy(x, y + 1);
	printf("신성한 회복 강화");
	gotoxy(x, y + 2);
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

void storeframe() //num 8
{
	int x = 0;
	int y = 1;

	gotoxy(x+17, y);
	printf("< 늙은 대장장이 >");
	gotoxy(x, y + 1);
	printf("%s", specialChar4());
	gotoxy(x + 14, y + 1);
	printf("%s", specialChar7());
	gotoxy(x, y + 11);
	printf("%s", specialChar5());
	gotoxy(x + 14, y + 11);
	printf("%s", specialChar6());
	
	gotoxy(x + 2, y + 1);
	printf("무기/방어구");





	//이미지
	gotoxy(x + 15, y+1);
	printf("%s", specialChar4());
	gotoxy(x + 48, y + 1);
	printf("%s", specialChar7());
	gotoxy(x + 15, y + 11);
	printf("%s", specialChar5());
	gotoxy(x + 48, y + 11);
	printf("%s", specialChar6());
	//설명
	gotoxy(x, y + 12);
	printf("%s", specialChar4());
	gotoxy(x + 48, y +12);
	printf("%s", specialChar7());
	gotoxy(x, y+17);
	printf("%s", specialChar5());
	gotoxy(x + 48, y+17);
	printf("%s", specialChar6());





}

int weapondraw()
{
	int x = 2;
	int y = 3;

	gotoxy(x, y);
	printf("어두운 검");
	gotoxy(x, y+1);
	printf("붉은 가시 창");
	gotoxy(x, y+2);
	printf("양날도끼");
	gotoxy(x, y+3);
	printf("Caladfwich");
	gotoxy(x, y+4);
	printf("예리한 단검");
	gotoxy(x, y+5);
	printf("철갑옷");
	gotoxy(x, y+6);
	printf("백조의 갑옷");
	gotoxy(x, y+7);
	printf("아다만티움갑옷");
	gotoxy(x, y+8);
	printf("겁쟁이갑옷");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 3) {
				gotoxy(x - 1, y);
				printf(" ");
				gotoxy(x - 1, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 11)
			{
				gotoxy(x - 1, y);
				printf(" ");
				gotoxy(x - 1, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
		{
			return y - 3;
			break;
		}


		}
	}
	

}

int buyornodraw() {
	int x = 38;
	int y = 16;
	gotoxy(x, y);
	printf("[산다]");
	gotoxy(x, y + 1);
	printf("[돌아간다.]");

	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 16) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 17)
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
			return y - 16;
			break;
		}


		}
	}
}

void conversationprint()
{
	int x = 0;
	int y = 18;

	gotoxy(x, y - 5);
	printf("%s", specialChar4());
	gotoxy(x + 48, y - 5);
	printf("%s", specialChar7());
	gotoxy(x, y);
	printf("%s", specialChar5());
	gotoxy(x + 48, y);
	printf("%s", specialChar6());



}


int blacksdraw() {
	int x = 5;
	int y = 14;
	gotoxy(x - 2, y - 2);
	printf("[ 늙은 대장장이 ]");
	gotoxy(x, y);
	printf("- 당신 대장장이군.");
	_getch();
	gotoxy(x, y);
	printf("- 무엇을 팔고 있지?");
	gotoxy(x, y + 1);
	printf("- 볼일 없다.");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 15)
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
			return y - 14;
			break;
		}


		}
	}
}

int doordraw() {
	int x = 30;
	int y = 9;
	gotoxy(x, y);
	printf("[가시 문]");
	gotoxy(x-1, y + 1);
	printf("[붉은 통로]");
	gotoxy(x-5, y + 2);
	printf("아직 할 일이 남았다.");

	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 9) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (y < 11)
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
			return y - 9;
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

int attack(int x, int y) // x = 몬스터 라이프 , y = 내 공격력/  몬스터에게 가한 피해량.
{

	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t = i + y; // 데미지 = 랜덤난수 + 플 레이어 공격력
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
	else if (heal_lv == 4) {
		t = y * (1);
	}
	else if (heal_lv == 5) {
		t = y * (1.3);
	}
	x += t;
	return t;
}

int skill_rage(int x)// 3턴 동안 용사 공격력 쿨타임 6
{
	int t;
	if (rage_lv == 1) {
		t = x * (0.2); // t(추가 공격력) = 공격력 * 0.3 이다.
	}
	else if (rage_lv == 2) {
		t = x * (0.3);
	}
	else if (rage_lv == 3) {
		t = x * (0.5);
	}
	else if (rage_lv == 4) {
		t = x * (0.8);
	}
	else if (rage_lv == 5) {
		t = x * (1.2);
	}
	return t; // 공격력에 t를 추가한다.
}

void monster1_move_system_1(char arr[][10], int y, int x) {
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


void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}