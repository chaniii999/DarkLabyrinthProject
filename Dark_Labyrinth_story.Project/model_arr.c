#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;


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

const char* specialChar8()
{
	return "◈";
}

const char* specialChar9()
{
	return "★";
}




void gotoxy(int x, int y);


// 초기 함수

int game = 1; // 타이틀은 0 게임시작은 1
int root = 0;

int dengeon_level = 2;
int situation_num = 1; //시츄에이션 넘버

int cho = 0;



// 메뉴함수
int titleDraw(); // 시작화면 함수.
int proLogueDraw(); //프롤로그 선택함수.
int menuDraw(); // 메뉴 선택지함수
int skillmenuDraw(); // 스킬 선택지 함수
int yesnodraw();
int blacksdraw();
void conversationprint();
void storeframe();
int weapondraw();
int buyornodraw();
int doordraw();
int itemdraw();

void monhpbar(int life, int maxlife);
//int itemDraw();//아이템 선택함수

int select_num = 1; //전투상황 선택지 초기화

//맵 오브젝트

// level 1

//map_arr_loCation_level_1[10][10]



//강화관련
int ganghwa_sit = 0; //강화창

int cost_stab = 50;
int cost_rage = 150;
int cost_heal = 100;

//무기
int swordon = 0;
int spearon = 0;
int daggaron = 0;
int caladon = 0;
int ironon = 0;
int cowardon = 0;
int backon = 0;
int admanon = 0;

//아이템
int potion1 = 0;
int potion2 = 0;
int potion3 = 0;
int skillpotion = 0;


//맵배열
char map_arr_loCation_level_1[10][10];
char map_arr_loCation_level_2[13][13];
char map_arr_loCation_level_3[7][13];
char map_arr_loCation_level_4[12][12];
char map_arr_loCation_level_5[12][8];
char map_arr_loCation_level_6[13][7];
char map_arr_loCation_level_7[15][15];
char map_arr_loCation_level_8[15][11];

//맵출력
void printQuestion_level_1(); 
void printQuestion_level_2(); 
void printQuestion_level_3();
void printQuestion_level_4();
void printQuestion_level_5();
void printQuestion_level_6();
void printQuestion_level_7();
void printQuestion_level_8();

//테두리 벽 생성
void creaTor_great_Wall_1(int y, int x); //테두리 벽 제작 함수
void creaTor_great_Wall_2(int y, int x); //4~5층 내장 벽
void creaTor_great_Wall_3(int y, int x);
void creaTor_great_Wall_4(int y, int x);
void creaTor_great_Wall_5(int y, int x);
void creaTor_great_Wall_6(int y, int x);
void creaTor_great_Wall_7(int y, int x);
void creaTor_great_Wall_8(int y, int x);

int keyControl();

//맵 길이 t = y, t = x
int t1 = 10; 
int g1 = 10;

int t2 = 13;
int g2 = 13;

int t3 = 7;
int g3 = 13;

int t4 = 12;
int g4 = 12;

int t5 = 12;
int g5 = 8;

int t6 = 13;
int g6 = 7;

int t7 = 15;
int g7 = 15; 

int t8 = 15;
int g8 = 11;










void monmove_system(int y,int x); //랜덤이동
void monmove_system2(int y,int x);
void monmove_system3(int y, int x);

void monmove_system_2_1(int y, int x);
void monmove_system_2_2(int y, int x);
void monmove_system_2_3(int y, int x);

void monmove_system_4_1(int y, int x);
void monmove_system_4_2(int y, int x);
void monmove_system_4_3(int y, int x);

void monmove_system_5_1(int y, int x);
void monmove_system_5_2(int y, int x);
void monmove_system_5_3(int y, int x);

void monmove_system_7_1(int y, int x);
void monmove_system_7_2(int y, int x);
void monmove_system_7_3(int y, int x);


void monxy(int y, int x); // 몬스터 위치 좌표 고정
void monxy2(int y, int x);
void monxy4(int y, int x);
void monxy5(int y, int x);
void monxy7(int y, int x);

void bfmonxy(int y, int x); //공용 좌표 지우개
void bfmonxy2(int y, int x);
void bfmonxy4(int y, int x);
void bfmonxy5(int y, int x);
void bfmonxy7(int y, int x);


int *monlife;

int *x_m;
int *y_m;

int monsterlife = 1;
int monsterlife2 = 1;
int monsterlife3 = 1;

int monspawn;
int cntspawn;







void move_player_1(int x, int y);
void move_player_2(int x, int y);
void move_player_3(int x, int y);
void move_player_4(int x, int y);
void move_player_5(int x, int y);
void move_player_6(int x, int y);
void move_player_7(int x, int y);
void move_player_8(int x, int y);

void bef_move_player_1(int x, int y);
void bef_move_player_2(int x, int y);
void bef_move_player_3(int x, int y);
void bef_move_player_4(int x, int y);
void bef_move_player_5(int x, int y);
void bef_move_player_6(int x, int y);
void bef_move_player_7(int x, int y);
void bef_move_player_8(int x, int y);

//고유값
int Player = 1; //플레이어 
int tem = 2; //체력물약
int enTrance = 3;
int mon = 4; //몬스터1 
int statue1 = 5; // 조각상 
int black_s = 6;

int star = 7;




//좌표값
int y_p = 8; //플레이어 시작 위치
int x_p = 5; //플레이어 시작 위치

int x_npc = 3;
int y_npc = 5;

int x_black = 6;
int y_black = 1;


int x_mon = 2; //몬스터 좌표값
int y_mon = 6;

int x_mon2 = 2;
int y_mon2 = 2;

int x_mon3 = 7;
int y_mon3 = 7;


int x_boss = 5;
int y_boss = 3;

int x_tem = 5;
int y_tem = 5;















//전투함수

int stab_lv = 1;
int rage_lv = 1;
int heal_lv = 1;
int skill_several_stab(int a);
int skill_holy_Heal(int x, int y);
int skill_rage(int x);
int cnt_attack = 0;
int rage = 0;

int turn = 0;
int cnt_turn_stab = -3;
int cnt_turn_rage = -5;
int cnt_turn_heal = -3;

int attack(int x, int y,int k);  // 공격 함수

int attacked_monster(int x, int y,int k); //피격 함수




typedef struct objecT
{
	char* name;// 개체명
	int attack;// 공격력
	int life;  // 생명력
	int max_life;// 최대 생명력
	int crono; //화폐
	int evasion; // 경험치
	int critical;
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


	//PlaySound(TEXT("C:\\darkrabyrinth\\bgm.wav"), NULL, SND_ASYNC | SND_LOOP);

	oBject player; //플레이어 정의
	player.name = player_name;
	player.attack = 13;
	player.crono = 300;
	player.max_life = 30;
	player.life = player.max_life;
	player.critical = 15;
	player.evasion = 10;



	oBject statue; // 5
	statue.name = "신성한 녹색 조각상";

	oBject blacks; //6
	blacks.name = "늙은 대장장이";

	oBject mon;
	mon.name;
	mon.attack;
	mon.life;
	mon.crono;
	mon.max_life;


	oBject bat; //박쥐 0
	bat.name = "박쥐";
	bat.attack = 4;
	bat.life = 20;
	bat.crono = rand() % 70 + 300;
	bat.max_life = 20;

	oBject moth; // 1
	moth.name = "나방";
	moth.attack = 3;
	moth.life = 20;
	moth.crono = rand() % 30 + 300;
	moth.max_life = 20;

	oBject spider; // 2
	spider.name = "거미";
	spider.attack = 4;
	spider.life = 20;
	spider.crono = rand() % 25 + 300;
	spider.max_life = 20;


	oBject kero; // 3       2층 마지막
	kero.name = "케르베로스";
	kero.attack = 13;
	kero.life = 60;
	kero.crono = rand() % 100 + 250;
	kero.max_life = 60;

	oBject kenta; // 4        4층 마지막
	kenta.name = "켄타로우스";  
	kenta.attack = 20;
	kenta.life = 90;
	kenta.crono = rand() % 100 + 400;
		

	oBject monster1; //       5 층 마지막
	monster1.name = "블랙-드래곤";
	monster1.attack = 25;
	monster1.life = 150;
	monster1.crono = rand() % 150 + 700;
	monster1.max_life = 130;

	oBject mino;  //7
	mino.name = "억압받은 자";
	mino.attack = 30;
	mino.life = 1000;
	mino.crono = rand() % 2000;
	mino.max_life = 400;
		





	int cnt_monster_life;
	int cnt_player_life = player.life;



	///////////////////////////////////////////


	iteM sword;
	sword.name = "어두운 검";
	sword.attack = 40;
	sword.critical = 20;
	sword.cost = 500;

	iteM spear;
	spear.name = "푸른 창";
	spear.attack = 30;
	spear.critical = 15;
	spear.cost = 300;


	iteM Excalibur;
	Excalibur.name = "Caladfwich";
	Excalibur.attack = 100;
	Excalibur.critical = 40;
	Excalibur.cost = 1000;

	iteM daggar;
	daggar.name = "예리한 단검";
	daggar.attack = 10;
	daggar.critical = 45;
	daggar.evasion = 10;
	daggar.cost = 200;

	iteM iron;
	iron.name = "철 갑옷";
	iron.life = 20;
	iron.evasion = 5;
	iron.cost = 200;

	iteM fast;
	fast.name = "백조의 갑옷";
	fast.life = 30;
	fast.evasion = 15;
	fast.cost = 600;

	iteM adaman;
	adaman.name = "아다만티움 갑옷";
	adaman.life = 60;
	adaman.evasion = 15;
	adaman.cost = 700;

	iteM coward;
	coward.name = "겁쟁이 갑옷";
	coward.life = 0;
	coward.evasion = 50;
	coward.cost = 100;






	int key = 0; // 플레이어 이동 변수 



	//내부벽

	map_arr_loCation_level_1[1][4] = 9;
	map_arr_loCation_level_1[2][4] = 9;
	map_arr_loCation_level_1[2][5] = 9;
	map_arr_loCation_level_1[2][6] = 9;
	map_arr_loCation_level_1[2][7] = 9;
	map_arr_loCation_level_1[3][7] = 9;
	map_arr_loCation_level_1[4][3] = 9;
	map_arr_loCation_level_1[4][7] = 9;
	map_arr_loCation_level_1[5][7] = 9;
	map_arr_loCation_level_1[5][3] = 9;
	map_arr_loCation_level_1[6][3] = 9;
	map_arr_loCation_level_1[7][3] = 9;
	map_arr_loCation_level_1[7][4] = 9;
	map_arr_loCation_level_1[7][5] = 9;
	map_arr_loCation_level_1[7][6] = 9;
	map_arr_loCation_level_1[8][6] = 9;

	map_arr_loCation_level_1[5][5] = 2;


	//2층	
	map_arr_loCation_level_2[2][5] = 9;
	map_arr_loCation_level_2[2][6] = 9;
	map_arr_loCation_level_2[2][7] = 9;
	map_arr_loCation_level_2[3][4] = 9;
	map_arr_loCation_level_2[3][8] = 9;
	map_arr_loCation_level_2[4][9] = 9;
	map_arr_loCation_level_2[4][3] = 9;
	map_arr_loCation_level_2[4][6] = 9;
	map_arr_loCation_level_2[5][6] = 9;
	map_arr_loCation_level_2[5][10] = 9;
	map_arr_loCation_level_2[6][1] = 9;
	map_arr_loCation_level_2[6][5] = 9;
	map_arr_loCation_level_2[6][6] = 9;
	map_arr_loCation_level_2[6][7] = 9;
	map_arr_loCation_level_2[7][6] = 9;
	map_arr_loCation_level_2[8][6] = 9;
	map_arr_loCation_level_2[6][11] = 9;
	map_arr_loCation_level_2[7][1] = 9;
	map_arr_loCation_level_2[7][2] = 9;
	map_arr_loCation_level_2[7][10] = 9;
	map_arr_loCation_level_2[7][11] = 9;
	map_arr_loCation_level_2[8][2] = 9;
	map_arr_loCation_level_2[8][3] = 9;
	map_arr_loCation_level_2[8][9] = 9;
	map_arr_loCation_level_2[8][10] = 9;
	map_arr_loCation_level_2[9][3] = 9;
	map_arr_loCation_level_2[9][4] = 9;
	map_arr_loCation_level_2[9][8] = 9;
	map_arr_loCation_level_2[9][9] = 9;

	map_arr_loCation_level_2[8][1] = 2;
	map_arr_loCation_level_2[8][11] = 2;


	//3층

	map_arr_loCation_level_3[2][2] = 9;
	map_arr_loCation_level_3[4][2] = 9;
	map_arr_loCation_level_3[2][4] = 9;
	map_arr_loCation_level_3[4][4] = 9;
	map_arr_loCation_level_3[2][8] = 9;
	map_arr_loCation_level_3[4][8] = 9;
	map_arr_loCation_level_3[2][10] = 9;
	map_arr_loCation_level_3[4][10] = 9;



	//4층
	map_arr_loCation_level_4[3][1] = 9;
	map_arr_loCation_level_4[1][3] = 9;
	map_arr_loCation_level_4[4][2] = 9;
	map_arr_loCation_level_4[2][4] = 9;
	map_arr_loCation_level_4[5][3] = 9;
	map_arr_loCation_level_4[3][6] = 9;
	map_arr_loCation_level_4[1][8] = 9;
	map_arr_loCation_level_4[3][10] = 9;
	map_arr_loCation_level_4[2][7] = 9;
	map_arr_loCation_level_4[4][9] = 9;
	map_arr_loCation_level_4[8][10] = 9;
	map_arr_loCation_level_4[10][8] = 9;
	map_arr_loCation_level_4[7][9] = 9;
	map_arr_loCation_level_4[9][7] = 9;
	map_arr_loCation_level_4[10][3] = 9;
	map_arr_loCation_level_4[8][1] = 9;
	map_arr_loCation_level_4[9][4] = 9;
	map_arr_loCation_level_4[7][2] = 9;
	map_arr_loCation_level_4[5][6] = 9;
	map_arr_loCation_level_4[6][5] = 9;
	map_arr_loCation_level_4[6][8] = 9;
	map_arr_loCation_level_4[8][5] = 9;

	//5층

	map_arr_loCation_level_5[10][2] = 9;
	map_arr_loCation_level_5[9][2] = 9;
	map_arr_loCation_level_5[8][2] = 9;
	map_arr_loCation_level_5[7][2] = 9;
	map_arr_loCation_level_5[6][2] = 9;
	map_arr_loCation_level_5[5][2] = 9;
	map_arr_loCation_level_5[4][2] = 9;
	map_arr_loCation_level_5[3][2] = 9;
	map_arr_loCation_level_5[2][2] = 9;
	map_arr_loCation_level_5[2][4] = 9;
	map_arr_loCation_level_5[3][5] = 9;
	map_arr_loCation_level_5[3][4] = 9;
	map_arr_loCation_level_5[3][6] = 9;
	map_arr_loCation_level_5[4][4] = 9;
	map_arr_loCation_level_5[5][4] = 9;
	map_arr_loCation_level_5[6][4] = 9;
	map_arr_loCation_level_5[7][4] = 9;
	map_arr_loCation_level_5[8][4] = 9;
	map_arr_loCation_level_5[9][4] = 9;



	//7층

	map_arr_loCation_level_7[1][1] = 7;











	map_arr_loCation_level_1[1][5] = enTrance;
	map_arr_loCation_level_2[2][11] = enTrance;
	map_arr_loCation_level_3[3][11] = enTrance;
	map_arr_loCation_level_4[1][10] = enTrance;
	map_arr_loCation_level_5[4][5] = enTrance;
	map_arr_loCation_level_6[1][3] = enTrance;
	map_arr_loCation_level_7[1][7] = enTrance;
	map_arr_loCation_level_8[1][5] = enTrance;








	//npc 배열정의

	//1층
	


	map_arr_loCation_level_3[1][6] = black_s; //대장장이

	map_arr_loCation_level_6[5][3] = statue1; // 조각상
	


	





	while (game == 0)
	{
		CursorView();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Sleep(500);

		switch (titleDraw())
		{
		case 0:
		{
			system("cls");
			printf("\n\n\n           Welcome to my Labyrinth. . .");
			Sleep(2500);
			system("cls");
			printf("\n\n\n\n\n\n              프롤로그를 보시겠습니까?");
			switch (proLogueDraw())
			{
			case 0:
			{
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(1500);
				printf("         아버지는 항상 말하셨다.\n");
				Sleep(1500);
				printf("         자유의지는 인간만이 갖고있는 것이라고\n");
				Sleep(1500);
				printf("         자유가 곧 우리의 생명이라고\n");
				Sleep(1500);
				printf("         나 또한 자유라는 단어가 좋다.\n");
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
			if (root >= 1)
			{
				system("cls");
				situation_num == 7;
			}
			else
			{
				system("cls");
			}
		}
		case 2:
			if (root == 2)
			{
				system("cls");
				situation_num == 9;
			}
			else
			{
				system("cls");
				break;
			}

		case 3:
			exit(0);




			break;
		} //sw_ed

	}

	if (dengeon_level == 2)
	{
		x_p = 6;
		y_p = 11;
		x_mon = 10; //kero
		y_mon = 3;
		x_mon2 = 7;
		y_mon2 = 5;
		x_mon3 = 1;
		y_mon3 = 1;
	}
	else if (dengeon_level == 3)
	{
		x_p = 1;
		y_p = 3;
	}
	else if (dengeon_level == 4)
	{
		x_p = 10;
		y_p = 10;
		x_mon = 1;
		y_mon = 1;
		x_mon2 = 1;
		y_mon2 = 1;
	}
	else if (dengeon_level == 5)
	{
		x_p = 6;
		y_p = 11;
		x_mon = 1;
		y_mon = 1;
		x_mon2 = 1;
		y_mon2 = 1;
	}
	else if (dengeon_level == 6)
	{
		x_p = 6;
		y_p = 11;
		x_mon = 1;
		y_mon = 1;
		x_mon2 = 1;
		y_mon2 = 1;
	}
	else if (dengeon_level == 7)
	{
		x_p = 6;
		y_p = 11;
		x_mon = 1;
		y_mon = 1;
		x_mon2 = 1;
		y_mon2 = 1;
	}
	else if (dengeon_level == 8)
	{
		x_p = 6;
		y_p = 11;
		x_mon = 1;
		y_mon = 1;
		x_mon2 = 1;
		y_mon2 = 1;
	}


	while (game == 1)//게임진행중 // 화면 지속.
	{

		if (situation_num == 1) //평상시
		{

			if (dengeon_level == 1)
			{
				creaTor_great_Wall_1(t1, g1);
				printQuestion_level_1();//맵 표시
				

				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);

				if (map_arr_loCation_level_1[1][5] == Player)
				{
					system("cls");
					situation_num = 12;
					monsterlife = 1;
					monsterlife2 = 1;
					monsterlife3 = 1;
				}
			}

			if (dengeon_level == 2)
			{
				
				creaTor_great_Wall_2(t2, g2);
				printQuestion_level_2();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_2[2][11] == Player)
				{
					dengeon_level = 3;
					x_p = 1;
					y_p = 3;
				}
			}

			if (dengeon_level == 3)
			{
				creaTor_great_Wall_3(t3, g3);
				printQuestion_level_3();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_3[3][11] == Player)
				{
					system("cls");
					situation_num = 14;
				}
			}
			if (dengeon_level == 4)
			{
				creaTor_great_Wall_4(t4, g4);
				printQuestion_level_4();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_4[1][10] == Player)
				{
					system("cls");
					situation_num = 15;
				}
			}

			if (dengeon_level == 5)
			{
				creaTor_great_Wall_5(t5, g5);
				printQuestion_level_5();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_5[4][5] == Player)
				{
					system("cls");
					situation_num = 16;

				}
			}

			if (dengeon_level==6)
			{
				creaTor_great_Wall_6(t6, g6);
				printQuestion_level_6();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_6[1][3] == Player)
				{
					system("cls");
					situation_num = 17;
				}
			}
			if (dengeon_level == 7)
			{
				creaTor_great_Wall_7(t7, g7);
				printQuestion_level_7();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
				if (map_arr_loCation_level_7[1][7] == Player)
				{
					system("cls");
					situation_num = 18;
				}
			}
			if (dengeon_level == 8)
			{
				creaTor_great_Wall_8(t8, g8);
				printQuestion_level_8();
				int qq = 33;
				int pp = 3;
				gotoxy(qq, pp);
				printf("%s", player.name);
				gotoxy(qq, pp + 1);
				printf("LIFE ( %d / %d )", player.life, player.max_life);
				gotoxy(qq, pp + 3);
				printf("CRONO : %d", player.crono);
				gotoxy(qq, pp + 5);
				printf("floor : %d ", dengeon_level);
			}




			if (dengeon_level == 1)
			{
				move_player_1(y_p, x_p); // 캐릭터 현 좌표 함수.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_1(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
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
					case 122:
					{

						if (x_p == x_tem && y_p == y_tem + 1 ||
							x_p == x_tem + 1 && y_p == y_tem ||
							x_p == x_tem - 1 && y_p == y_tem ||
							x_p == x_tem && y_p == y_tem - 1)
						{
							map_arr_loCation_level_1[5][5] = 0;
							system("cls");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							printf("   체력 물약을 획득했다!\n");
							Sleep(1000);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							potion1++;
						}
						break;
					}
					default:
						break;
					}
				}
				if (monsterlife == 1)   
				{

					monxy(y_mon, x_mon);
					monmove_system(y_mon,x_mon);

					if (x_p == x_mon && y_p == y_mon + 1 ||
						x_p == x_mon + 1 && y_p == y_mon ||
						x_p == x_mon - 1 && y_p == y_mon ||
						x_p == x_mon && y_p == y_mon - 1)
					{

						monlife = &monsterlife;

						if (cntspawn == 0)
						{
							monspawn = rand() % 3;
							cntspawn = monspawn;
						}
						else
						{
							while (monspawn || cntspawn)
							{
								monspawn = rand() % 3;
								cntspawn = monspawn;
							}
						}

						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy(y_mon, x_mon);
				


				if (monsterlife2 == 1)
				{
					monxy(y_mon2, x_mon2); //좌표고정
					monmove_system2(y_mon2, x_mon2);
					if (x_p == x_mon2 && y_p == y_mon2 + 1 ||
						x_p == x_mon2 + 1 && y_p == y_mon2 ||
						x_p == x_mon2 - 1 && y_p == y_mon2 ||
						x_p == x_mon2 && y_p == y_mon2 - 1)
					{
						monspawn = rand() % 3;



						monlife = &monsterlife2;
						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy(y_mon2, x_mon2);

				if (monsterlife3 == 1)
				{
					monxy(y_mon3, x_mon3); //좌표고정
					monmove_system3(y_mon3, x_mon3);
					if (x_p == x_mon3 && y_p == y_mon3 + 1 ||
						x_p == x_mon3 + 1 && y_p == y_mon3 ||
						x_p == x_mon3 - 1 && y_p == y_mon3 ||
						x_p == x_mon3 && y_p == y_mon3 - 1)
					{
						monspawn = rand() % 3;



						monlife = &monsterlife3;
						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy(y_mon3, x_mon3);

			}
			if (dengeon_level == 2)
			{

				move_player_2(y_p, x_p); // 캐릭터 현 좌표 함수.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_2(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
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
					case 122:
					{
						if (y_p == 9 && x_p == 1)
						{
							map_arr_loCation_level_2[8][1] = 0;
							system("cls");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							printf("  큰 체력 물약을 획득했다!\n");
							Sleep(1000);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							potion2++;
						}
						if (y_p ==9 && x_p == 11)
						{
							map_arr_loCation_level_2[8][11] = 0;
							system("cls");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							printf("  힘의 물약을 획득했다!\n");
							Sleep(1000);
							printf("   힘이 3 상승했다!");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							player.attack += 3;
						}
					}
					default:
						break;
					}

				}
				if (monsterlife == 1)
				{

					monxy2(y_mon, x_mon);
					monmove_system_2_1(y_mon, x_mon);

					if (x_p == x_mon && y_p == y_mon + 1 ||
						x_p == x_mon + 1 && y_p == y_mon ||
						x_p == x_mon - 1 && y_p == y_mon ||
						x_p == x_mon && y_p == y_mon - 1)
					{

						monlife = &monsterlife;

						if (cntspawn == 0)
						{
							monspawn = rand() % 1 +3; // 123
							cntspawn = monspawn;
						}
						else
						{
							while (monspawn || cntspawn)
							{
								monspawn = rand() % 3 + 1;
								cntspawn = monspawn;
							}
						}

						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy2(y_mon, x_mon);

				if (monsterlife2 == 1)
				{
					monxy2(y_mon2, x_mon2); //좌표고정
					monmove_system_2_2(y_mon2, x_mon2);
					if (x_p == x_mon2 && y_p == y_mon2 + 1 ||
						x_p == x_mon2 + 1 && y_p == y_mon2 ||
						x_p == x_mon2 - 1 && y_p == y_mon2 ||
						x_p == x_mon2 && y_p == y_mon2 - 1)
					{
						monspawn = rand() % 3;



						monlife = &monsterlife2;
						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy2(y_mon2, x_mon2);

				if (monsterlife3 == 1)
				{
					monxy2(y_mon3, x_mon3); //좌표고정
					monmove_system_2_3(y_mon3, x_mon3);
					if (x_p == x_mon3 && y_p == y_mon3 + 1 ||
						x_p == x_mon3 + 1 && y_p == y_mon3 ||
						x_p == x_mon3 - 1 && y_p == y_mon3 ||
						x_p == x_mon3 && y_p == y_mon3 - 1)
					{
						monspawn = rand() % 3;



						monlife = &monsterlife3;
						situation_num = 2;
						Sleep(1000);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					}

				}
				else
					bfmonxy2(y_mon3, x_mon3);

			}
			if (dengeon_level == 3)
			{
				move_player_3(y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_1(map_arr_loCation_level_3, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_3(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
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
					case 122:
					{
						if(x_p == x_black && y_p == y_black + 1 ||
							x_p == x_black + 1 && y_p == y_black ||
							x_p == x_black - 1 && y_p == y_black ||
							x_p == x_black && y_p == y_black - 1)
							situation_num = 6;
					}
					default:
						break;
					}
				}

			}
			if (dengeon_level == 4)
			{
				move_player_4(y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_2(map_arr_loCation_level_4, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_4(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
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
			if (dengeon_level == 5)
			{
				move_player_5(y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_1(map_arr_loCation_level_3, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_5(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_5[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_5[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_5[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_5[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_5[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_5[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_5[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_5[y_p + 1][x_p] == 3)
							y_p++;
						break;
					case 122:
					{
						break;
					}
					default:
						break;
					}
				}
			}
			if (dengeon_level == 6)
			{
				move_player_6(y_p, x_p); // 캐릭터 현 좌표 함수.
				//move_monster_1(map_arr_loCation_level_3, y_mon, x_mon); // 몬스터 현 좌표.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_6(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_6[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_6[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_6[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_6[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_6[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_6[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_6[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_6[y_p + 1][x_p] == 3)
							y_p++;
						break;
					case 122:
					{
						if (x_p == x_npc && y_p == y_npc + 1 ||
							x_p == x_npc + 1 && y_p == y_npc ||
							x_p == x_npc - 1 && y_p == y_npc ||
							x_p == x_npc && y_p == y_npc - 1)
						{
							situation_num = 4;
						}
						break;
					}
					default:
						break;
					}
				}
			}
			if (dengeon_level == 7)
			{
				move_player_7(y_p, x_p); // 캐릭터 현 좌표 함수.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_7(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_7[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_7[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_7[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_7[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_7[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_7[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_7[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_7[y_p + 1][x_p] == 3)
							y_p++;
						break;
					case 122:
					{
						break;
					}
					default:
						break;
					}
				}
			}
			if (dengeon_level == 8)
			{
				move_player_8(y_p, x_p); // 캐릭터 현 좌표 함수.
				if (kbhit())
				{

					key = _getch();
					bef_move_player_8(y_p, x_p); // 이전 플레이어의 위치에 있는 1을 지워줌. 
					switch (key)
					{
					case 72:
						if (map_arr_loCation_level_8[y_p - 1][x_p] == 0 ||
							map_arr_loCation_level_8[y_p - 1][x_p] == 3) //가고자하는 자리가 0일때만 가능.
							y_p--;
						break;
					case 75:
						if (map_arr_loCation_level_8[y_p][x_p - 1] == 0 ||
							map_arr_loCation_level_8[y_p][x_p - 1] == 3)
							x_p--;
						break;
					case 77:
						if (map_arr_loCation_level_8[y_p][x_p + 1] == 0 ||
							map_arr_loCation_level_8[y_p][x_p + 1] == 3)
							x_p++;
						break;
					case 80:
						if (map_arr_loCation_level_8[y_p + 1][x_p] == 0 ||
							map_arr_loCation_level_8[y_p + 1][x_p] == 3)
							y_p++;
						break;
					case 122:
					{
						break;
					}
					default:
						break;
					}
				}
			}


		}
		if (situation_num == 2) // 전투시작연출
		{
			switch (monspawn)
			{
			case 0:
			{
				mon.name = bat.name;
				mon.attack = bat.attack;
				mon.life = bat.life;
				mon.crono = bat.crono;
				mon.max_life = bat.max_life;
				break;
			}
			case 1:
			{
				mon.name = spider.name;
				mon.attack = spider.attack;
				mon.life = spider.life;
				mon.crono = spider.crono;
				mon.max_life = spider.max_life;
				break;
			}
			case 2:
			{
				mon.name = moth.name;
				mon.attack = moth.attack;
				mon.life = moth.life;
				mon.crono = moth.crono;
				mon.max_life = moth.max_life;
				break;
			}
			case 3:
			{
				mon.name = kero.name;
				mon.attack = kero.attack;
				mon.life = kero.life;
				mon.crono = kero.crono;
				mon.max_life = kero.max_life;
				break;
			}
			case 4:
			{
				mon.name = kenta.name;
				mon.attack = kenta.attack;
				mon.life = kenta.life;
				mon.crono = kenta.crono;
				break;
			}
			case 5:
			{
				mon.name = monster1.name;
				mon.attack = monster1.attack;
				mon.life = monster1.life;
				mon.crono = monster1.crono;
				break;
			}
			case 6:
			{
				mon.name = mino.name;
				mon.attack = mino.attack;
				mon.life = mino.life;
				mon.crono = mino.crono;
			}
			default:
				break;
			}



			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("                 %s가 나타났다!\n", mon.name);
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(800);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(100);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			Sleep(500);
			system("cls");
			situation_num = 3;




		}
		if (situation_num == 3) //대치중
		{
			switch (monspawn)
			{
			case 0:  //spider
				{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣤⡴⠶⠾⠿⠿⠿⠿⠶⠶⣦\n");
				wprintf(L"⠀⠀⠀   ⠀⠀⠀⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⣤⠀⠀⠀⣰⣿⣿⠢⢄⠀⠀⠀⠀⠀⠀⢀⠔\n");
				wprintf(L"  ⠀    ⠀⠀⠀⢀⣀⣀⣤⣤⣴⣦⠀⠀⠀⠀⢠⠈⠐⢄⣠⣤⣴⣏⠀⠈⢧⠀⢠⡿⠁⠸⡀⠀⠀⠠⢀⠀⠀⡰⠁⠀\n");
				wprintf(L"     ⢀⣠⣴⡾⠿⠛⠋⠉⡉⠿⡿⣷⣄⠀⠀⣼⠀⢰⣿⣿⣿⣿⢿⣷⡄⠈⡠⠋⠀⠀⠀⣇⠀⠀⠀⠀⠑⢤⡇⠀⠀\n");
				wprintf(L"     ⠟⠋⠀⠀⠀⠀⠀⡔⠁⠀⡇⠈⠙⠷⣄⣹⠀⢸⣧⣾⣿⡿⠞⣿⣿⣤⠁⠀⠀⠀⠀⠘⠀⠀⣠⠔⠒⠉⠁⠀⠀\n");
				wprintf(L"     ⠒⠢⠀⠀⠀⢀⠞⠀⠀⠀⢇⠀⠀⠀⠀⠛⣶⣿⣷⣄⣀⣠⣴⣿⣿⣿⣶⡆⠤⠤⡀⠀⡇⡔⠁\n");
				wprintf(L"⠀     ⠀⠀⠰⣠⠏⠀⠀⠀⠀⢸⡀⠀⠀⣠⢤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠑⠟⠀\n");
				wprintf(L"⠀     ⠀⠀⠀⠉⠉⠉⠉⠒⢤⡈⡇⡠⠊⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀\n");
				wprintf(L"⠀⠀     ⠀⠀⠀⠀⠀⠀ ⠀⠀⠘⠟⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀\n");
				wprintf(L"⠀  ⠀⠀   ⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⣿⣿⣿⢿⡏⠀\n");
				wprintf(L"⠀  ⠀⠀   ⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠣⠀⠀⠀⠁⠀⠀⠀\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
				break;
				}//
			case 1: //bat
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"\n⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⣠⣴⣶⣦⣄\n");
				wprintf(L"⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⣰⣧⠀⣀⣠⣾⣿⣿⣿⣿⣿⣧\n");
				wprintf(L"⠀⠀   ⠀⠀⠀⠀⠀⠀⣠⣤⣾⠋⠙⢷⣾⠋⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢀⣠⡶⣦⡀⠀\n");
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⣠⣾⣋⣏⣙⠻⠶⣤⣙⣿⡿⠉⣿⠟⠻⣿⣿⣿⣿⣿⣧⣴⠞⢋⣡⣤⢾⣿⣦⣀⠀⠀\n");
				wprintf(L"⠀   ⠀⠀⠀⠰⠿⢟⣽⠏⠉⠙⠛⠳⠾⣿⣿⣔⣠⣿⡀⠀⢹⣿⣿⣿⣿⣿⣷⣿⣯⣭⡀⠀⠙⣿⣟⠁⠀\n");
				wprintf(L"⠀   ⠀⠀⠀⣠⣴⣿⠃⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣟⠋⠉⠁⠀⠘⣿⣄⠀⠈⠻⣷⣤⡀\n");
				wprintf(L"⠀   ⠀⠀⠸⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠁⠈⣿⡀⠀⠀⠀⠀⠘⣿⣦⡀⠀⠀⠉⠀⠀⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀  ⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀⣿⣷⠀⠀⠀ ⠀⠀⠘⢿⣿⣄⠀⠀⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀     ⠀⠀⠀    ⠀⠀⠀⢻⣿⣇⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀     ⠀⠀⠀    ⠀⠀⠀⠀⠻⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
				break;
			}//
			case 2://moth
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"        ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⡀⠀\n");
				wprintf(L"         ⠀⠀⠀⡀⠀⠀⠀⠀⢸⣿⣷⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀\n");
				wprintf(L"        ⠀⠀⠀⠀⠐⡀⠀⢠⣴⣿⣿⣶⣤⣤⡀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋\n");
				wprintf(L"⠀         ⠀⠀⠀⠀⠑⢤⣿⢻⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀\n");
				wprintf(L"⠀         ⠀⠀⠀⠀⠰⣿⣿⡿⣛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀\n");
				wprintf(L"⠀         ⠀⠀⠀⠀⠀⢛⣿⡀⠉⢸⣿⣿⣿⣿⣿⣿⡿⠿⣿⣿⡿⠟⠉⠀⠀⠀⠀⠀\n");
				wprintf(L"⠀         ⠀⠀⠀⠀⢀⣀⣲⣿⣛⣚⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀\n");
				wprintf(L"⠀         ⠀⠀⠀⢐⣿⣿⣿⣿⣻⣿⣿⡿⣿⣿⣿⣿⣿⡀⠀⠀⠀\n");
				wprintf(L"⠀         ⠀⠀⠠⠿⠻⣿⣿⣿⣿⡿⠟⢠⣿⣿⣿⣿⡟⠀⠀⠀\n");
				wprintf(L"⠀         ⠀⠀⠀⠀⠀⠊⠉⠈⠁⠀⠰⠿⠿⠉⠛⠛⠀⠀\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
				break;
			}
			case 3: //kero
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"\n     ⠀⠀     ⠀⠀⠀⠀⠀⠀⠀⢀⣾⠋⠀⠀⠀⠀⠀⠀⣉⣿⣿⣿⣶⣦⣀⣀⠀\n");
				wprintf(L"⠀⠀     ⠀⠀⠀     ⠀⠀⠀⢀⣬⣾⣷⣄⡀⠀⠀⣀⡘⣟⣿⣿⣽⣿⣟⠟⡟⠀\n");
				wprintf(L"⠀     ⠀⠀⠀⠀⠀     ⠀⣠⣿⣿⣿⣻⣯⣿⡷⣾⣿⣶⣊⣿⣿⣿⣿⣏⠉⠁\n");
				wprintf(L"          ⠀⠀⠀⠀⠀⠀⣸⣿⣿⡿⢝⣿⣿⣿⣿⡿⡃⣴⣿⣕⢭⣜⣿⣿⣷⣶⣄⠀\n");
				wprintf(L"⠀⠀     ⠀     ⠀⠀⢠⣿⡿⠋⠉⠿⣿⣿⣿⣿⣣⣷⢟⠦⡾⣿⣧⣿⣿⣿⣿⣿⣶⣤⠀⠀\n");
				wprintf(L"⠀⠀     ⠀     ⠀⣰⡿⠟⠁⠀⠀⠀⠙⣏⣿⣿⣿⣿⣷⠿⠿⢿⠝⠉⠙⠻⣾⡋⠉⠁⠀\n");
				wprintf(L"⠀⠀     ⠀     ⣰⡟⠀⠀⠀⠀⠀⠀⠈⢹⣽⣏⠙⠓⢿⢷⣾⣸⡄⠀⠀⠀⠀⠁⠀\n");
				wprintf(L"⠀          ⠀⣴⢿⡃⠀⠀⠀⠀⠀⠀⠀⠈⢿⣟⣶⡀⠀⠉⠈⠻⣿⡄⠀⠀\n");
				wprintf(L"⠀          ⠈⠙⠚⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣅⣀⣀⠀⠀⠹⣷⣤⢤⡀\n");
				wprintf(L"⠀⠀⠀      ⠀     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⠼⠧⠛⠁⠀⠀⠉⠓⠚⠁⠀\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
				break;
			}
			case 4: //kenta
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢒⢢⣤⠆⠀\n");
				wprintf(L"   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠽⣿⣿⣏⡀⠀\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠔⣀⣵⣿⣷⣿⣿⣆\n");
				wprintf(L"⠀    ⠀⠀⠀⠀⠀ ⠀⠀⠀⠐⡄⠆⣾⡟⢛⠻⣿⣿⡆⠀\n");
				wprintf(L"⠀    ⠈⠒⡀⠄⡀⠀⠀⠀⢀⡣⣄⠀⣿⣿⣿⣿⣷⣿⣳⠠⠀\n");
				wprintf(L"⠀⠀    ⠀⠈⠈⢔⠡⢂⠄⡀⢁⢻⢄⡿⢻⡛⣻⣿⣿⠈⠀⠀\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠂⠪⣋⠤⣉⢠⢤⣬⡭⡟⠻⠓⠁⣀⡀\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠡⠀⡔⢼⢉⣀⠆⣾⣶⣶⣷⣿\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡝⠮⣄⣴⣿⣿⣿⣿⡿⠛\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⢻⣷⣾⣿⢻⣧⠀\n");
				wprintf(L"⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣾⣿⣿⣬⣿⣿⣴⣽⡦\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
			}
			case 5: //drago
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"⠀⠄⣀⠀⠀⠀⠀⠀⠀⢀⣠⢆⣠⠖⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⡤⠖⠂\n");
				wprintf(L"⠀⠀⠈⠛⠦⣤⡀⠀⣴⣿⣿⣿⣇⢀⠀⠀⠀⠀⢠⣴⣾⣿⡟⡃\n");
				wprintf(L"⠀⠀⠀⠀⠀⠘⣿⣾⣿⣟⣿⡿⣿⠁⠀⠀⠀⢠⣿⣿⣿⠿⠇⠑⠠⠀⢀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠠⠿⢿⣿⣷⣄⢺⣾⣷⣤⣠⣼⣿⣿⣿⠀⠀⠀⢀⣤⡶⣞\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠈⢋⣹⣿⣿⣿⣿⣿⡉⠙⠁⠀⠀⣠⣾⠏⠁⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠐⠚⠛⠛⣾⣿⣿⣿⣿⣶⣶⣶⣿⠟⠁⠀⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣹⣿⣿⣿⣿⣿⣿⡿⠋⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⢠⣀⡀⣠⣾⡿⠋⢘⣷⡟⠉⠁\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠘⠻⣿⡿⠋⠁⢲⣿⣿⡇⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠈⠻⠀\n");

				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
			}
			case 6://mino
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				wprintf(L"⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⢀⠤⠂⠀⠀⠀⠀⠀⠀⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⠠⢺⣿⠃⠀⠀⠀⣼⠁⠀⠀⠀⠀⡆⠀⠀⠀⠀⠀⠀⡠⠀\n");
				wprintf(L"⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠛⢶⢶⣄⣤⣠⠏⠀⠀⠀⠀⢠⡴⠀⠀⢠\n");
				wprintf(L"⠀⠀⠀⠀⠀⢠⣿⣿⠀⠀⢀⣠⣤⡌⠿⣿⣇⡀⠀⠀⠀⠀⠀⠆⠁⠀⠀⣻\n");
				wprintf(L"⠀⠀⠀⠀⠀⠘⣿⣿⣷⣓⣿⣿⣿⣿⣷⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠠⣿\n");
				wprintf(L"⠠⠀⠀⠀⠀⠀⣿⡿⣿⣿⠟⣙⢹⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⢠⢻\n");
				wprintf(L"⡆⠀⠀⠀⠀⠀⣹⡇⠈⠉⠀⣿⣿⣿⣿⣿⣷⢻⣿⣦⣀⠀⠀⠀⠀⠀⢸⣽\n");
				wprintf(L"⡇⡆⣤⣤⠤⣴⢿⣷⣀⢖⡾⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣾⣄⣤⠀⠀⣿⣿\n");
				wprintf(L"⣧⢨⡿⢿⡿⢻⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣷⡍⠛⠟⠟⠃⠀⣤⣿⣿\n");
				wprintf(L"⣿⣷⣀⠬⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢸⣿⣿⣿\n");
				wprintf(L"⣿⣿⣿⣷⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡾⠶⣆⠇⣸⣿⣿⣿\n");


				fflush(stdout);
				_setmode(_fileno(stdout), exMode);
				break;
			}
			default:
				break;
			}
			
	
			gotoxy(0, 11);
			printf("%s", specialChar4());
			gotoxy(48, 11);
			printf("%s", specialChar7());
			gotoxy(0, 17);
			printf("%s", specialChar5());
			gotoxy(48, 17);
			printf("%s", specialChar6());

			if (monspawn == 3)
			{
				gotoxy(6, 0);
			}
			else
				gotoxy(13, 0);
			printf("%s:", mon.name);
			gotoxy(18, 0);  
			monhpbar(mon.life, mon.max_life);

			gotoxy(14, 11);
			printf("hp:");
			monhpbar(player.life, player.max_life);
			printf("  %d/%d", player.life, player.max_life);
	




			//FRAME

			switch (menuDraw())//전투선택지
			{
			case 0: //공격
			{
				system("cls");
				turn++;
				cnt_monster_life = mon.life;
				cnt_player_life = player.life;
				mon.life -= attack(mon.life, player.attack,player.critical);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(1000);
				printf("   % s는 % s에게 검을 힘차게 휘둘렀다!\n\n", player.name, mon.name);
				Sleep(1000);
				printf("   %s에게 %d의 데미지를 주었다.\n\n", mon.name, cnt_monster_life - mon.life);  // 공격받기전 - 받은후 =데미지
				Sleep(1500);
				if (mon.life <= 0)
				{
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					system("cls");
					printf("\n\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(1000);
					printf("   %s를 쓰러트렸다!\n\n", mon.name);
					Sleep(1000);
					printf("   %d 크로노 를 얻었다!\n\n", mon.crono);
					player.crono += mon.crono;
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(2000);
					*monlife = 0;
					system("cls");
					situation_num = 1;

				}
				else if (mon.life > 0)
				{
					printf("   %s는 %s에게\n 달려들었다!\n\n", mon.name, player.name);
					Sleep(1000);
					player.life -= attacked_monster(player.life, mon.attack, player.evasion);

					Sleep(1000);
					if (cnt_player_life - player.life > 0)
						printf("   %s는 %d의\n 데미지를 받었다.\n\n", player.name, cnt_player_life - player.life);

					Sleep(1500);
					if (player.life <= 0)
					{
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("     ricaus는 힘을 다하였다...\n\n");
						Sleep(1000);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(300);
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("		                    GAME OVER\n");
						Sleep(1000);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						_getch();
						game = 0;
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
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				player.life -= 3*(attacked_monster(player.life, mon.attack,player.evasion)) / 5;
				printf("   %s는 방어태세에 들어갔다!\n\n", player.name);
				Sleep(1000);
				printf("   %s는 %s에게 달려들었다!\n\n", mon.name, player.name);
				Sleep(1500);
				printf("   %s는 %d의 데미지를 받았다.\n\n", player.name, cnt_player_life - player.life);
				Sleep(1000);
				if (player.life <= 0)
				{
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("   %s는 힘을 다하였다...\n", player.name);
					Sleep(1000);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(300);
					system("cls");
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
					Sleep(500);
					printf("		                    GAME OVER\n");
					Sleep(1000);
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf("   %s의 체력: %d\n\n", mon.name, mon.life);
				printf("   당신의 체력 :%d\n", player.life);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				switch (skillmenuDraw())
				{
				case 0: //연속찌르기
				{
					if (turn < cnt_turn_stab + 3)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("   아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_stab = turn;
						system("cls");
						cnt_player_life = player.life;
						cnt_monster_life = mon.life;
						mon.life -= skill_several_stab(player.attack);
						player.life -= attack(player.life, mon.attack,20);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						printf("   %s는 연속 찌르기를 사용했다!\n\n", player.name);
						Sleep(1000);
						printf("   %s는 %s에게 %d의 데미지를 주었다.\n\n", player.name, mon.name, skill_several_stab(player.attack));
						Sleep(2000);

						if (mon.life <= 0)
						{
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(300);
							system("cls");
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1000);
							printf("   %s를 쓰러트렸다!\n\n", mon.name);
							Sleep(1000);
							printf("   %d 크로노 를 얻었다!\n\n", mon.crono);
							player.crono += mon.crono;
							Sleep(500);
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(2000);

							*monlife = 0;
							system("cls");

							situation_num = 1;
							break;

						}
						else if (mon.life > 0)
						{
							printf("   %s는 %s에게 달려들었다!\n\n", mon.name, player.name);
							Sleep(1000);
							printf("   %s는 %d의 데미지를 받었다.\n\n", player.name, cnt_player_life - player.life);
							Sleep(1500);
							if (player.life <= 0)
							{
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("   ricaus는 힘을 다하였다...\n");
								Sleep(1000);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(300);
								system("cls");
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
								Sleep(500);
								printf("		   GAME OVER\n");
								Sleep(1000);
								printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("   아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_heal = turn;
						cnt_player_life = player.life;
						system("cls");//
						player.life += skill_holy_Heal(player.life, player.attack); //힐 시전
						if (player.life > player.max_life) // 시전 후 최대생명력보다 높아지게된다면
						{
							player.life = player.max_life;

							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1500);
							printf("   신께 기도를 드립니다...\n\n");
							Sleep(1500);
							printf("   ricaus는 %d의 체력을 회복했다!\n", player.max_life - cnt_player_life);
						}
						else
						{
							printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
							Sleep(1500);
							printf("   신께 기도를 드립니다...\n\n");
							Sleep(1500);
							printf("   ricaus는 %d의 체력을 회복했다!\n", player.life - cnt_player_life);
						}
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");;
						Sleep(1000);
						printf("   아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1500);
						situation_num = 3;
					}
					else if (rage == 1)
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
						printf("   아직 사용할 수 없습니다.\n");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
						printf("   ricaus는 울부짖었다.\n\n");
						Sleep(1500);
						printf("   \"우 오 오 오 ! ! !\"\n\n");
						player.attack += skill_rage(player.attack);
						Sleep(1500);
						printf("   용사의 공격력이 일시적으로 증가했다!\n\n");
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
				system("cls");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf("   %s의 체력: %d\n\n", mon.name, mon.life);
				printf("   당신의 체력 :%d\n", player.life);
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf("   사용할 아이템을 선택하세요. \n");
				switch (itemdraw())
				{
				case 0:
				{
					if (potion1 >= 1)
					{
						potion1--;
						player.life += 10;
						if (player.life > player.max_life)
							player.life = player.max_life;
						

						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   체력을 10 회복했다!\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					else
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   포션이 부족합니다.");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					break;
				}
				case 1:
				{
					if (potion2 >= 1)
					{
						potion2--;
						player.life += 20;
						if (player.life > player.max_life)
							player.life = player.max_life;
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   체력을 20 회복했다!\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					else
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   포션이 부족합니다.\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}

					break;
				}
				case 2:
				{
					if (potion3 >= 1)
					{
						potion3--;
						if (player.life > player.max_life * 0.5)
						{
							player.life = player.max_life;
						}
						else
							player.life += player.max_life * 0.5;
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   체력을 %d 회복했다!\n",player.max_life*0.5);
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					else
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   포션이 부족합니다.");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					break;
				}
				case 3:
				{
					if (skillpotion >= 1)
					{
						skillpotion--;
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						turn = 0;
						cnt_turn_stab = -3;
						cnt_turn_rage = -5;
						cnt_turn_heal = -3;
						printf("   모든 스킬의 쿨타임이 초기화됐다!\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					else
					{
						system("cls");
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(500);
						printf("   포션이 부족합니다.\n");
						Sleep(500);
						printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
						Sleep(1000);
					}
					break;
				}
				default:
					break;
				}
				//itemdraw();


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
			printf("   연속 찌르기 Lv.%d\n   신성한 회복 Lv.%d\n   용사의 분노 Lv.%d\n", stab_lv, heal_lv, rage_lv);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
			printf("   내 크로노 : %d", player.crono);
			switch (statuedraw())
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
				printf("[어두운 검]  %d Crono 보유한 Crono : %d\n",sword.cost, player.crono);
				printf(" 긴 리치에 비해 무게는 가볍다.\n");
				printf(" 바라보고 있으면 그 검은 도신에 \n 빨려들어갈 것 같다...");
			
				switch (buyornodraw())
				{
				case 0:
				{
					if (swordon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= sword.cost)
					{
						swordon = 1;
						player.crono -= sword.cost;
						player.attack += sword.attack;
						player.critical += sword.critical;
						system("cls");
						printf("\n\n   어두운 검을 구입했습니다.");
						_getch();
						break;
					}
					else
					{
						system("cls");
						printf("\n\n   보유한 크로노가 부족합니다.");
						_getch();
						break;
					}
					break;
				case 1:
				{
					system("cls");
					break;
				}
				}
				default:
					break;
				}

				break;
			}
			case 1: //검은 가시 창
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⠀⠤⠤⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀⠀⠈⠙⠲⣦⣀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠈⠳⢤⢄⢠⣤⣄⠀⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣷⣄⡀⠀⠀\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠉⠋⠛⠛⠫⢮⡿⣿⣷⣖⠂⡁⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢾⣻⣷⣶⡠⠄\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠘⡎⠙⡿⣯⣶⣦⡤⠀⢀⠀⠀⠀\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⠉⠛⠿⢾⣷⡂⠀⠀⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠈⠋⢟⢶⣖⡈⠁⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠂⠀\n");


				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[검은 가시 창]  %d Crono 보유한 Crono : %d\n",spear.cost, player.crono);
				printf(" 겉면에 가시가 나있다.\n");
				printf(" 묵직하여 들고만 있어도 \n 운동이 되는 느낌이다.");
				switch (buyornodraw())
				{
				case 0:
				{
					if (spearon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= spear.cost)
					{
						spearon = 1;
						player.crono -= spear.cost;
						player.attack += spear.attack;
						player.critical += spear.critical;
						system("cls");
						printf("\n\n\n[검은 가시 창]을 구입했습니다.");
						_getch();
						
						break;
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}
				break;
			}
			case 2:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⠀  ⠀⢤⣤⣤⣤⣀⡀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀  ⠀⠈⣿⣿⣿⣿⣿⣿⣦⣄⠀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀  ⠀⠀⠈⠉⠙⠿⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀  ⠀⠀⠀⠀⠀⠀⠙⠿⣿⣯⡛⠿⣷⣦⣀⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣦⡀⠙⢛⣿⣷⡤⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣆⠰⢿⣿⣇⡀⠀⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠿⠿⢿⣿⣿⣶⣄⡀⠀⠀\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣶⣄⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠙⣿⣿⡷⠄\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠓⠁\n");


				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[예리한 단검]  %d Crono 보유한 Crono : %d\n",daggar.cost, player.crono);
				printf(" 특이하게 생긴 단검이다.\n");
				printf(" 살짝만 스쳐도 상처가 \n 날것같이 날카롭다.");
				switch (buyornodraw())
				{
				case 0:
				{
					if (daggaron == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= daggar.cost)
					{
						daggaron = 1;
						player.crono -= daggar.cost;
						player.attack += daggar.attack;
						player.critical += daggar.critical;
						player.evasion += daggar.evasion;
						system("cls");
						printf("\n\n\n[예리한 단검]을 구입했습니다.");
						_getch();

						break;
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}
				break;
			
			case 3:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⣶⣦⣄⡀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⣿⣿⣿⣿⣷⣦⣄⣀⠀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀⠉⠛⠿⣿⣿⣿⣿⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⣿⣷⣤⣀⡀⠀⠀⠀⠀⠀⠀⣤⣤⡄\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⣷⢹⡇⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⡀⠶⣌⡙⢳⣦⡿⣸⠇⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠲⢬⣽⣭⣟⡶⣿⣄⠀⠀⠀\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⢹⡿⠿⣿⣷⣦⣄⡀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡶⢛⣵⠏⠀⠀⠀⠉⠛⠻⢿⣷⣤⣀⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠀\n");



				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[Caladfwish]  %d Crono 보유한 Crono : %d\n",Excalibur.cost, player.crono);
				printf(" 성스러운 기운이 느껴지는 검이다.\n");
				switch (buyornodraw())
				{
				case 0:
				{
					if (player.crono >= Excalibur.cost)
					{
						caladon = 1;
						player.crono -= Excalibur.cost;
						player.attack += Excalibur.attack;
						player.critical += Excalibur.critical;
						system("cls");
						printf("\n\n\n[Caladfwish]을 구입했습니다.");
						_getch();

						break;
					}
					else if (caladon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}
				break;
			}
			case 4:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"   ⠀   ⠀⠀⣶⢾⣟⣿⣦⣀⠀⣠⡞⣿⣶⣾⣿⣿⣿⠀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀      ⠀⠈⣿⣯⣻⣷⣆⡀⠙⡭⢿⣿⣿⣿⣿⣿⣿⡄⠀⠀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀      ⠀⠀⢸⣮⢿⣿⣿⢇⠴⠈⢽⣿⣿⣿⣿⣿⠟⠀⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"      ⠀⠀⠀⢸⢵⣫⡿⡝⡣⣰⣮⣷⣿⢿⡿⠿⠋⠀\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀      ⠀⠀⠀⢨⣾⡝⢼⣝⣶⣷⣿⢯⡃⢀⡆⠄⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀      ⠀⠀⠀⠀⣭⣽⣿⡟⣞⣿⢿⢯⣷⣾⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀      ⠀⠀⢰⣿⣉⣯⢿⣿⣿⣯⣿⣽⣿⣷\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀      ⠀⠀⢾⣿⣿⣿⣿⣽⣿⣿⣾⣿⡿⣿⣇⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀      ⠀⠀⠀⢿⣿⣿⣶⣿⣿⣿⣿⡿⠿⠃⠈⢿⠀⠀⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀   ⠀   ⠀⠀⠙⠛⠛⠛⠉⠉⠀⠀⠀⠀⠀\n");



				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[철갑옷]  %d Crono 보유한 Crono : %d\n", iron.cost, player.crono);
				printf(" 철로 만들어진 무거운 갑옷이다.\n");
				switch (buyornodraw())
				{
				case 0:
				{
					if (ironon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= iron.cost)
					{
						ironon = 1;
						player.crono -= iron.cost;
						player.life += iron.life;
						player.max_life += iron.life;
						if (player.life > player.max_life)
							player.life = player.max_life;
						player.evasion += iron.evasion;
						system("cls");
						printf("\n\n\n[철갑옷]을 구입했습니다.");
						_getch();
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
					break;
				}
				default:
					break;
				}
				break;
			}
			case 5:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢀⡀⡤⣦⣀⣤⣴⣶⣀⡀⣀⣀⠀⠀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣵⣿⣿⣿⣿⣾⡧⡿⡿⣿⣿⣿⡴⣿⣾⣿⣆⡀⠀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⣿⣿⣿⣷⡿⣿⣿⣷⣾⢟⣳⣖⣸⣕⣿⣿⣿⡾⠃\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣾⣺⣿⣿⣿⣿⣟⡿⣿⣿⡟⣿⠟⣯⣽⣿⡐⠀⠀\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡿⣿⡿⢿⣿⣿⡻⣽⣿⡷⣿⣿⣿⡟⣞⣿⣿⡇⠀⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⡇⠀⢱⣯⢳⣟⣏⡿⣽⡯⣳⢽⣿⣿⣿⡇⠀⠀⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠰⢟⣟⣿⡇⠀⠀⣷⣿⣿⣿⣯⣿⣿⣿⣭⣿⣿⣿⠇\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠀⠀⠀⢘⣼⣿⣿⣿⣾⣿⣷⣿⣿⠉⠁⠀⠀⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢿⣿⢿⣿⣿⣿⠿⣿⢟⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠽⢿⡿⡷⣻⣿⣿⣿⡛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 10);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠿⠿⠋⠀⠀\n");




				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[겁쟁이갑옷]  %d Crono 보유한 Crono : %d\n", coward.cost, player.crono);
				printf(" 비겁한 겁쟁이라구!");
				switch (buyornodraw())
				{
				case 0:

				{
					if (cowardon == 1)
					{
					system("cls");
					printf("\n\n이미 보유한 아이템입니다..");
					Sleep(500);
					_getch();
					}
					else if (player.crono >= coward.cost)
					{
						cowardon = 1;
						player.crono -= coward.cost;
						player.life += coward.life;
						player.max_life += coward.life;
						player.evasion += coward.evasion;
						if (player.life > player.max_life)
							player.life = player.max_life;
						system("cls");
						printf("\n\n\n[겁쟁이갑옷]을 구입했습니다.");
						_getch();
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
					break;
				}
				default:
					break;
				}
				break;
			}
			case 6:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⠀⠀⠀⠀⢀⣠⣤⣤⣤⣶⣦⣤⣀⣀⣠⣤⣴⣶⣤⣤⣤⣄⡀⠀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀⠀⠀⣴⣿⣋⣿⣽⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀⠀⣼⣿⣿⠿⣾⣿⣿⣿⣿⠖⠘⣿⣿⣿⣿⣿⣿⢿⣿⠿⣿⣿⣦⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀⠀⠉⠀⠀⣿⢹⣿⣿⣿⣶⣶⣿⣿⡿⢿⣿⣿⣜⡿⠀⠀⠉⠀⠀\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠙⢺⣿⣿⡟⢿⣿⣿⣿⣶⣿⣿⣿⡟⠋⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣾⣽⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠰⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠀\n");
				gotoxy(ix, iy + 10);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠘⠛⠿⠿⠋⠀⠀⠀\n");



				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[백조의 갑옷]  %d Crono 보유한 Crono : %d\n", fast.cost, player.crono);
				printf(" 흰 깃털이 가득한 갑옷이다. 깃털처럼 가볍다.");
				switch (buyornodraw())
				{
				case 0:
				{

					if (backon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= fast.cost)
					{
						backon = 1;
						player.crono -= fast.cost;
						player.life += fast.life;
						player.max_life += fast.life;
						player.evasion += fast.evasion;
						if (player.life > player.max_life)
							player.life = player.max_life;
						system("cls");
						printf("\n\n\n[백조의 갑옷]을 구입했습니다.");
						_getch();

						break;
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}
				break;
			}
			case 7:
			{
				int exMode = _setmode(_fileno(stdout), 0x00020000);
				_setmode(_fileno(stdout), 0x00020000);
				gotoxy(ix, iy);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣴⣶⣶⣶⣆⣄⠀⠀\n");
				gotoxy(ix, iy + 1);
				wprintf(L"⠀⠀⠀⠀⠀⣀⣴⡶⣿⣸⣿⣿⣿⣿⠿⠃⠳⡽⡠⣦⣤⣄\n");
				gotoxy(ix, iy + 2);
				wprintf(L"⠀⠀⠀⠀⣾⣿⣬⡧⣿⠙⠍⠙⠉⠝⢀⣀⠴⢜⡰⠁⠃⠀⢱⡄⠀\n");
				gotoxy(ix, iy + 3);
				wprintf(L"⠀⠀⠀⢸⣿⣾⣏⢰⣿⣿⠒⠲⠾⢷⣧⡧⠀⢮⠑⠀⠀⠈⠀⡇\n");
				gotoxy(ix, iy + 4);
				wprintf(L"⠀⠀⠀⣿⡯⣷⡷⡆⢸⡇⠀⠂⠀⢈⣿⣴⡄⠀⣀⡔⣠⠤⠒⣶⠀⠀\n");
				gotoxy(ix, iy + 5);
				wprintf(L"⠀⠀⠈⣿⣼⣿⣿⣆⣼⠀⠀⠂⠀⠠⡕⢯⢿⠴⣿⣷⣿⣂⠉⢳⡂⠀⠀\n");
				gotoxy(ix, iy + 6);
				wprintf(L"⠀⠀⠀⠿⣿⣿⢿⣿⣏⠀⢠⣀⠀⢄⣿⣷⣾⣯⠟⣿⣿⣿⣿⣿⠃⠀\n");
				gotoxy(ix, iy + 7);
				wprintf(L"⠀⠀⠀⠀⠀⠉⠈⣿⣿⣀⢎⣾⣤⣶⣾⣿⣿⣿⠀⠹⠛⠋⠛⠁⠀⠀\n");
				gotoxy(ix, iy + 8);
				wprintf(L"⠀⠀⠀⠀⠀⠀⣸⣿⣿⣴⣿⡿⣿⢟⣁⡿⣾⢿⣷⠀⠀\n");
				gotoxy(ix, iy + 9);
				wprintf(L"⠀⠀⠀⠀⠀⠰⣿⢻⣿⣿⣷⣿⣿⢿⡅⣠⣎⣀⠄⠀⠀⠀⠀\n");
				gotoxy(ix, iy + 10);
				wprintf(L"⠀⠀⠀⠀⠀⠀⠀⠙⠛⠿⠿⠿⠿⠽⠟⠛⠋⠁⠀⠀\n");



				fflush(stdout);
				_setmode(_fileno(stdout), exMode);

				gotoxy(qx, qy);
				printf("[아다만티움갑옷]  %d Crono 보유한 Crono : %d\n", adaman.cost, player.crono);
				printf(" 희귀한 금속으로 만들어진 갑옷이다.\n");
				switch (buyornodraw())
				{
				case 0:
				{
					if (admanon == 1)
					{
						system("cls");
						printf("\n\n이미 보유한 아이템입니다..");
						Sleep(500);
						_getch();
					}
					else if (player.crono >= adaman.cost)
					{
						admanon = 1;
						player.crono -= adaman.cost;
						player.life += adaman.life;
						player.max_life += adaman.life;
						player.evasion += adaman.evasion;
						if (player.life > player.max_life)
							player.life = player.max_life;
						system("cls");
						printf("\n\n\n[아다만티움갑옷]을 구입했습니다.");
						_getch();

						break;
					}
					else
					{
						system("cls");
						printf("\n\n보유한 크로노가 부족합니다.");
						Sleep(500);
						_getch();
					}
				}
				default:
					break;
				}
				break;
			}
			case 8:
			{
				situation_num = 1;
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
			printf("--------------------");
			printf("\n\n기분 좋은 하루다.\n\n");;
			_getch();
			Sleep(500);
			printf("언젠가 나도 저 하늘을 나는 새처럼 되고싶다고 했다.\n\n");
			_getch();
			Sleep(500);
			printf("아빠는 나를 보며 기특해하셨다.\n\n");
			_getch();
			Sleep(500);
			
			dengeon_level = 2;
			y_p = 11;
			x_p = 6;
			situation_num = 1;
		}

		if (situation_num == 14)
		{
			printf("온 세상이 빨갰다.\n");
			_getch();
			Sleep(500);
			printf("아빠는 내 손을 잡고 어딘가로 뛰어가고 있었다.\n");
			_getch();
			Sleep(500);
			printf("순간 커다란 붉은 눈동자가 이쪽을 보았다.\n");
			_getch();
			Sleep(500);
			printf("무서웠다\n");
			_getch();
			Sleep(500);
			printf("하지만 어딘가 친근했다.\n");
			_getch();
			Sleep(500);
			printf("나는  어째선지 생기는 이 감정을 무시하며 달렸다.\n");
			_getch();
			Sleep(500);
			printf("난 이 날에 매캐한 냄새를 잊지 못했다.\n");
			_getch();
			Sleep(500);

			dengeon_level = 4;
			y_p = 9;
			x_p = 10;
			situation_num = 1;
		}

		if(situation_num==15)
		{
			printf("어느날이었다.\n");
			_getch();
			Sleep(500);
			printf("할일을 끝내놓은 후 난 한가롭게 낮잠을 자고 있었다\n");
			_getch();
			Sleep(500);
			printf("바깥이 시끄러워졌다.\n");
			_getch();
			Sleep(500);
			printf("이내 아버지는 집에서 기다리라고 말씀하신 후\n 모르는 사람들과 함께 어딘가로 향하셨다\n");
			_getch();
			Sleep(500);
			printf("그 날 저녁 아버지는 돌아오지 않으셨다.\n");
			_getch();
			Sleep(500);

			dengeon_level = 5;
			y_p = 10;
			x_p = 1;
			situation_num = 1;
		}

		if (situation_num == 16)
		{
			printf("다음날 나는 동네를 돌아다녔다.\n");
			_getch();
			Sleep(500);
			printf("하지만 아무도 아버지가 어디에 가셨는지 알지못했다\n");
			_getch();
			Sleep(500);
			printf("숨이 차게 달렸다.\n");
			_getch();
			Sleep(500);
			printf("더 이상 서있을 힘이 없다고 생각했을 때\n");
			_getch();
			Sleep(500);
			printf("로브를 입은 괴상한 차림에 청년이 다가왔다.");
			_getch();
			Sleep(500);
			printf("\"너희 아버지는 미궁에 갇혔단다.\"");
			_getch();
			Sleep(500);
			printf("\"그것을 너가 무찌른다면 그곳에서 나올수있게 도와주마...\"");
			_getch();
			Sleep(500);

			dengeon_level = 6;
			y_p = 11;
			x_p = 3;
			situation_num = 1;
		}

		if (situation_num == 17)
		{
			printf("준비는 끝났다.\n");
			_getch();
			Sleep(500);
			printf("지난 몇십년동안 이 순간을 고대해왔다.\n\n");
			_getch();
			Sleep(500);
			printf("이 일이 끝나면 내 마음속에서 들끓는 증오도 평안을 되찾을까\n\n");
			_getch();
			Sleep(500);
			printf("인간은 자유를 원한다.\n\n");
			_getch();
			Sleep(500);

			dengeon_level = 7;
			y_p = 13;
			x_p = 7;
			situation_num = 1;
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

		if (situation_num == 18)
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

			dengeon_level = 8;
			x_p = 5;
			y_p = 13;
			situation_num = 1;
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

		Sleep(100);
		system("cls");

	}

	return 0;
}
////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////

void move_player_1(int x, int y)
{
	map_arr_loCation_level_1[x][y] = Player;
}
void move_player_2(int x, int y)
{
	map_arr_loCation_level_2[x][y] = Player;
}
void move_player_3(int x, int y)
{
	map_arr_loCation_level_3[x][y] = Player;
}
void move_player_4(int x, int y)
{
	map_arr_loCation_level_4[x][y] = Player;
}
void move_player_5(int x, int y)
{
	map_arr_loCation_level_5[x][y] = Player;
}
void move_player_6(int x, int y)
{
	map_arr_loCation_level_6[x][y] = Player;
}
void move_player_7(int x, int y)
{
	map_arr_loCation_level_7[x][y] = Player;
}
void move_player_8(int x, int y)
{
	map_arr_loCation_level_8[x][y] = Player;
}
//

void bef_move_player_1(int x, int y){
	map_arr_loCation_level_1[x][y] = 0;
}
void bef_move_player_2(int x, int y){
	map_arr_loCation_level_2[x][y] = 0;
}
void bef_move_player_3(int x, int y){
	map_arr_loCation_level_3[x][y] = 0;
}
void bef_move_player_4(int x, int y){
	map_arr_loCation_level_4[x][y] = 0;
}
void bef_move_player_5(int x, int y){
	map_arr_loCation_level_5[x][y] = 0;
}
void bef_move_player_6(int x, int y){
	map_arr_loCation_level_6[x][y] = 0;
}
void bef_move_player_7(int x, int y){
	map_arr_loCation_level_7[x][y] = 0;
}
void bef_move_player_8(int x, int y){
	map_arr_loCation_level_8[x][y] = 0;
}
//


void printQuestion_level_1()//맵 출력
{
	printf("\n\n\n");
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
			else if (map_arr_loCation_level_1[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_1[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_1[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_1[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_2()//맵 출력
{
	printf("\n");
	for (int i = 0; i < 13; i++)
	{
		printf("   ");
		for (int j = 0; j < 13; j++)
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
			else if (map_arr_loCation_level_2[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_2[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_2[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_2[i][j]);
		}
		printf("\n");
	}
	printf("monsterlife2 : %d", monsterlife2);
}//

void printQuestion_level_3()//맵 출력
{
	printf("\n\n\n\n");
	for (int i = 0; i < 7; i++)
	{
		printf(" ");
		for (int j = 0; j < 13; j++)
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
			else if (map_arr_loCation_level_3[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_3[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_3[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_3[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_4()//맵 출력
{
	printf("\n\n");
	for (int i = 0; i < 12; i++)
	{
		printf("   ");
		for (int j = 0; j < 12; j++)
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
			else if (map_arr_loCation_level_4[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_4[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_4[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_4[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_5()//맵 출력
{
	printf("\n\n");
	for (int i = 0; i < 12; i++)
	{
		printf("         ");
		for (int j = 0; j < 8; j++)
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
			else if (map_arr_loCation_level_5[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_5[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_5[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_5[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_6()//맵 출력
{
	for (int i = 0; i < 13; i++)
	{
		printf("          ");
		for (int j = 0; j < 7; j++)
		{
			if (map_arr_loCation_level_6[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_6[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_6[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_6[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_6[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_6[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_6[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_7()//맵 출력
{
	for (int i = 0; i < 15; i++)
	{
		
		for (int j = 0; j < 15; j++)
		{
			if (map_arr_loCation_level_7[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_7[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_7[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_7[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_7[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_7[i][j] = 7)
			{
				printf("%s", specialChar9());
			}
			else if (map_arr_loCation_level_7[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_7[i][j]);
		}
		printf("\n");
	}
}//

void printQuestion_level_8()//맵 출력
{
	for (int i = 0; i < 15; i++)
	{
		printf("      ");
		for (int j = 0; j < 11; j++)
		{
			if (map_arr_loCation_level_8[i][j] == 0) // 공백
			{
				printf("  ");
			}
			else if (map_arr_loCation_level_8[i][j] == 9) //테두리 벽
			{
				printf("%s", specialChar());
			}
			else if (map_arr_loCation_level_8[i][j] == 3) // 출구
			{
				printf("%s", specialChar2());
			}
			else if (map_arr_loCation_level_8[i][j] == 2)
			{
				printf(" ?");
			}
			else if (map_arr_loCation_level_8[i][j] == 1)
			{
				printf("%s", specialChar3());
			}
			else if (map_arr_loCation_level_8[i][j] = 4)
			{
				printf("%s", specialChar8());
			}
			else
				printf(" %d", map_arr_loCation_level_8[i][j]);
		}
		printf("\n");
	}
}//

void creaTor_great_Wall_1(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_1[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_1[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_1[j][x - 1] = 9;
		map_arr_loCation_level_1[j][0] = 9;
	}
}//

void creaTor_great_Wall_2(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_2[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_2[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_2[j][x - 1] = 9;
		map_arr_loCation_level_2[j][0] = 9;
	}
}//

void creaTor_great_Wall_3(int y, int x) // 벽만들기  y x
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_3[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_3[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_3[j][x - 1] = 9;
		map_arr_loCation_level_3[j][0] = 9;
	}
}//

void creaTor_great_Wall_4(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_4[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_4[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_4[j][x - 1] = 9;
		map_arr_loCation_level_4[j][0] = 9;
	}
}//

void creaTor_great_Wall_5(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++) //맨위 맨아래
	{
		map_arr_loCation_level_5[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_5[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_5[j][x - 1] = 9;
		map_arr_loCation_level_5[j][0] = 9;
	}
}//

void creaTor_great_Wall_6(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_6[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_6[y-1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_6[j][x - 1] = 9;
		map_arr_loCation_level_6[j][0] = 9;
	}
}//

void creaTor_great_Wall_7(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_7[0][i] = 9; // 0,0 0,1 .... 0,i
		map_arr_loCation_level_7[y - 1][i] = 9; // 5,0, 5,1... 5,i
	}
	for (int j = 1; j < y; j++)
	{
		map_arr_loCation_level_7[j][x - 1] = 9;
		map_arr_loCation_level_7[j][0] = 9;
	}
}//

void creaTor_great_Wall_8(int y, int x) // 벽만들기
{
	for (int i = 0; i < x; i++)
	{
		map_arr_loCation_level_8[0][i] = 9;
	}// 0,0 0,1 .... 0,i d 맨위에 막기
	for (int i = 3; i < 8; i++)
	{
		map_arr_loCation_level_8[y - 1][i] = 9; // 5,0, 5,1... 5,i 맨아래막기
	}
	for (int i = 1; i < 4; i++) //중간막기
	{
		map_arr_loCation_level_8[6][i] = 9;
	}
	for (int i = 7; i < 10; i++) //중간막기
	{
		map_arr_loCation_level_8[6][i] = 9;
	}
	for (int j = 1; j < y-8; j++)
	{
		map_arr_loCation_level_8[j][x - 1] = 9;  //왼쪽 막기
		map_arr_loCation_level_8[j][0] = 9;      //오른쪽막기
	}
	for (int j = 6; j < 14; j++)
	{
		map_arr_loCation_level_8[j][7] = 9;  //왼쪽 막기
		map_arr_loCation_level_8[j][3] = 9;      //오른쪽막기
	}

}//



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
	if (root >= 1) {
		printf("[갈림길]");
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("[???]");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	gotoxy(x, y + 2);
	if (root == 2)
	{
		printf("[그 다음길]");
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("[???]");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	gotoxy(x, y + 3);

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
			return y - 14;
			break;
		}


		}
	}
}

int proLogueDraw() {
	int x = 19;
	int y = 8;
	gotoxy(x, y);
	printf("-예");
	gotoxy(x, y + 1);
	printf("-아니오");

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


int menuDraw() {
	int x = 3;
	int y = 12;
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
			if (y > 12) {
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
			return y - 12;
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

int itemdraw() {
	int x = 3;
	int y = 12;
	gotoxy(x, y);
	printf("체력 물약 x %d",potion1); // 10
	gotoxy(x, y + 1);
	printf("큰 체력 물약 x %d",potion2); //20
	gotoxy(x, y + 2);
	printf("엘릭서 x %d",potion3); //체력 다 채워줌
	gotoxy(x, y + 3);
	printf("쿨타임초기화포션 x %d",skillpotion); // 
	gotoxy(x, y + 4);
	printf("돌아간다.");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
		{
			if (y > 12) {
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
			return y - 12;
			break;
		}


		}
	}
}

int statuedraw() {
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
	if (swordon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("어두운 검");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("어두운 검");
	gotoxy(x, y+1);
	if (spearon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("붉은 가시창");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("붉은 가시창");
	gotoxy(x, y+2);
	if (daggaron == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("예리한 단검");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("예리한 단검");
	gotoxy(x, y+3);
	if (caladon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("Caladfwich");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("Caladfwich");
	gotoxy(x, y+4);
	if (ironon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("철갑옷");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("철갑옷");
	gotoxy(x, y+5);
	if (cowardon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("겁쟁이갑옷");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("겁쟁이갑옷");
	gotoxy(x, y+6);
	if (backon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("백조의 갑옷");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("백조의 갑옷");
	gotoxy(x, y+7);
	if (admanon == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("아다만티움갑옷");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		printf("아다만티움갑옷");
	gotoxy(x, y + 8);
	printf("-돌아간다");
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



int skill_several_stab(int a)
{
	int temp = rand() % 2 + 2; //난수
	int dem;
	if (stab_lv == 1) {
		dem = temp * (a * 0.9);
	}
	else if (stab_lv == 2) {
		dem = temp * (a * 1.1);
	}
	else if (stab_lv == 3) {
		dem = temp * (a * 1.4);
	}
	else if (stab_lv == 4) {
		dem = temp * (a * 1.7);
	}
	else if (stab_lv == 5) {
		dem = temp * (a * 2.4);
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
		t = y * (0.9);
	}
	else if (heal_lv == 4) {
		t = y * (1.3);
	}
	else if (heal_lv == 5) {
		t = y * (1.8);
	}
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
		t = x * (0.7);
	}
	else if (rage_lv == 5) {
		t = x * (1);
	}
	return t; // 공격력에 t를 추가한다.
}

void monmove_system(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_1[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon--;
				bfmonxy(y_mon+1, x_mon);
			}
			break;
		case 1:
			if (map_arr_loCation_level_1[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bfmonxy(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_1[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bfmonxy(y_mon, x_mon-1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_1[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bfmonxy(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system2(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_1[y_mon2 - 1][x_mon2] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon2--;
				bfmonxy(y_mon2 + 1, x_mon2);
			}
			break;
		case 1:
			if (map_arr_loCation_level_1[y_mon2][x_mon2 - 1] == 0)
			{
				x_mon2--;
				bfmonxy(y_mon2, x_mon2 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_1[y_mon2][x_mon2 + 1] == 0)
			{
				x_mon2++;
				bfmonxy(y_mon2, x_mon2 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_1[y_mon2 + 1][x_mon2] == 0)
			{
				y_mon2++;
				bfmonxy(y_mon2 - 1, x_mon2);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system3(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_1[y_mon3 - 1][x_mon3] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon3--;
				bfmonxy(y_mon3 + 1, x_mon3);
			}
			break;
		case 1:
			if (map_arr_loCation_level_1[y_mon3][x_mon3 - 1] == 0)
			{
				x_mon3--;
				bfmonxy(y_mon3, x_mon3 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_1[y_mon3][x_mon3 + 1] == 0)
			{
				x_mon3++;
				bfmonxy(y_mon3, x_mon3 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_1[y_mon3 + 1][x_mon3] == 0)
			{
				y_mon3++;
				bfmonxy(y_mon3 - 1, x_mon3);
			}
			break;
		default:
			break;
		}
	}
}


void monmove_system_2_1(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_2[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon--;
				bfmonxy2(y_mon + 1, x_mon);
			}
			break;
		case 1:
			if (map_arr_loCation_level_2[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bfmonxy2(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_2[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bfmonxy2(y_mon, x_mon - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_2[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bfmonxy2(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_2_2(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_2[y_mon2 - 1][x_mon2] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon2--;
				bfmonxy2(y_mon2 + 1, x_mon2);
			}
			break;
		case 1:
			if (map_arr_loCation_level_2[y_mon2][x_mon2 - 1] == 0)
			{
				x_mon2--;
				bfmonxy2(y_mon2, x_mon2 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_2[y_mon2][x_mon2 + 1] == 0)
			{
				x_mon2++;
				bfmonxy2(y_mon2, x_mon2 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_2[y_mon2 + 1][x_mon2] == 0)
			{
				y_mon2++;
				bfmonxy2(y_mon2 - 1, x_mon2);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_2_3(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_2[y_mon3 - 1][x_mon3] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon3--;
				bfmonxy2(y_mon3 + 1, x_mon3);
			}
			break;
		case 1:
			if (map_arr_loCation_level_2[y_mon3][x_mon3 - 1] == 0)
			{
				x_mon3--;
				bfmonxy2(y_mon3, x_mon3 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_2[y_mon3][x_mon3+ 1] == 0)
			{
				x_mon3++;
				bfmonxy2(y_mon3, x_mon3 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_2[y_mon3 + 1][x_mon3] == 0)
			{
				y_mon3++;
				bfmonxy2(y_mon3 - 1, x_mon3);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_4_1(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_4[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon--;
				bfmonxy4(y_mon + 1, x_mon);
			}
			break;
		case 1:
			if (map_arr_loCation_level_4[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bfmonxy4(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_4[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bfmonxy4(y_mon, x_mon - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_4[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bfmonxy4(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_4_2(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_4[y_mon2 - 1][x_mon2] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon2--;
				bfmonxy4(y_mon2 + 1, x_mon2);
			}
			break;
		case 1:
			if (map_arr_loCation_level_4[y_mon2][x_mon2 - 1] == 0)
			{
				x_mon2--;
				bfmonxy4(y_mon2, x_mon2 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_4[y_mon2][x_mon2 + 1] == 0)
			{
				x_mon2++;
				bfmonxy4(y_mon2, x_mon2 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_4[y_mon2 + 1][x_mon2] == 0)
			{
				y_mon2++;
				bfmonxy4(y_mon2 - 1, x_mon2);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_4_3(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_4[y_mon3 - 1][x_mon3] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon3--;
				bfmonxy4(y_mon3 + 1, x_mon3);
			}
			break;
		case 1:
			if (map_arr_loCation_level_4[y_mon3][x_mon3 - 1] == 0)
			{
				x_mon3--;
				bfmonxy4(y_mon3, x_mon3 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_4[y_mon3][x_mon3 + 1] == 0)
			{
				x_mon3++;
				bfmonxy4(y_mon3, x_mon3 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_4[y_mon3 + 1][x_mon3] == 0)
			{
				y_mon3++;
				bfmonxy4(y_mon3 - 1, x_mon3);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_5_1(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_5[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon--;
				bfmonxy5(y_mon + 1, x_mon);
			}
			break;
		case 1:
			if (map_arr_loCation_level_5[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bfmonxy5(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_5[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bfmonxy5(y_mon, x_mon - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_5[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bfmonxy5(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_5_2(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_5[y_mon2 - 1][x_mon2] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon2--;
				bfmonxy5(y_mon2 + 1, x_mon2);
			}
			break;
		case 1:
			if (map_arr_loCation_level_5[y_mon2][x_mon2 - 1] == 0)
			{
				x_mon2--;
				bfmonxy5(y_mon2, x_mon2 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_5[y_mon2][x_mon2 + 1] == 0)
			{
				x_mon2++;
				bfmonxy5(y_mon2, x_mon2 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_5[y_mon2 + 1][x_mon2] == 0)
			{
				y_mon2++;
				bfmonxy5(y_mon2 - 1, x_mon2);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_5_3(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_5[y_mon3 - 1][x_mon3] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon3--;
				bfmonxy5(y_mon3 + 1, x_mon3);
			}
			break;
		case 1:
			if (map_arr_loCation_level_5[y_mon3][x_mon3 - 1] == 0)
			{
				x_mon3--;
				bfmonxy5(y_mon3, x_mon3 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_5[y_mon3][x_mon3 + 1] == 0)
			{
				x_mon3++;
				bfmonxy5(y_mon3, x_mon3 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_5[y_mon3 + 1][x_mon3] == 0)
			{
				y_mon3++;
				bfmonxy5(y_mon3 - 1, x_mon3);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_7_1(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_7[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon--;
				bfmonxy7(y_mon + 1, x_mon);
			}
			break;
		case 1:
			if (map_arr_loCation_level_7[y_mon][x_mon - 1] == 0)
			{
				x_mon--;
				bfmonxy7(y_mon, x_mon + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_7[y_mon][x_mon + 1] == 0)
			{
				x_mon++;
				bfmonxy7(y_mon, x_mon - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_7[y_mon + 1][x_mon] == 0)
			{
				y_mon++;
				bfmonxy7(y_mon - 1, x_mon);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_7_2(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_7[y_mon2 - 1][x_mon2] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon2--;
				bfmonxy7(y_mon2 + 1, x_mon2);
			}
			break;
		case 1:
			if (map_arr_loCation_level_7[y_mon2][x_mon2 - 1] == 0)
			{
				x_mon2--;
				bfmonxy7(y_mon2, x_mon2 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_7[y_mon2][x_mon2 + 1] == 0)
			{
				x_mon2++;
				bfmonxy7(y_mon2, x_mon2 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_7[y_mon2 + 1][x_mon2] == 0)
			{
				y_mon2++;
				bfmonxy7(y_mon2 - 1, x_mon2);
			}
			break;
		default:
			break;
		}
	}
}

void monmove_system_7_3(int y, int x) {
	if (kbhit())
	{
		int mkey = rand() % 4;
		switch (mkey) // 몬스터 비전투패턴
		{
		case 0:
			if (map_arr_loCation_level_7[y_mon3 - 1][x_mon3] == 0) //가고자하는 자리가 0일때만 가능.
			{
				y_mon3--;
				bfmonxy7(y_mon3 + 1, x_mon3);
			}
			break;
		case 1:
			if (map_arr_loCation_level_7[y_mon3][x_mon3 - 1] == 0)
			{
				x_mon3--;
				bfmonxy7(y_mon3, x_mon3 + 1);
			}
			break;
		case 2:
			if (map_arr_loCation_level_7[y_mon3][x_mon3 + 1] == 0)
			{
				x_mon3++;
				bfmonxy7(y_mon3, x_mon3 - 1);
			}
			break;
		case 3:
			if (map_arr_loCation_level_7[y_mon3 + 1][x_mon3] == 0)
			{
				y_mon3++;
				bfmonxy7(y_mon3 - 1, x_mon3);
			}
			break;
		default:
			break;
		}
	}
}


void monxy(int y, int x) // 몬스터 위치 동기화
{
	map_arr_loCation_level_1[y][x] = 4;
}
void monxy2(int y, int x) // 몬스터 위치 동기화
{
	map_arr_loCation_level_2[y][x] = 4;
}
void monxy4(int y, int x) // 몬스터 위치 동기화
{
	map_arr_loCation_level_4[y][x] = 4;
}
void monxy5(int y, int x) // 몬스터 위치 동기화
{
	map_arr_loCation_level_5[y][x] = 4;
}
void monxy7(int y, int x) // 몬스터 위치 동기화
{
	map_arr_loCation_level_7[y][x] = 4;
}




void bfmonxy(int y, int x)
{
	map_arr_loCation_level_1[y][x] = 0;
}
void bfmonxy2(int y, int x)
{
	map_arr_loCation_level_2[y][x] = 0;
}
void bfmonxy4(int y, int x)
{
	map_arr_loCation_level_4[y][x] = 0;
}
void bfmonxy5(int y, int x)
{
	map_arr_loCation_level_5[y][x] = 0;
}
void bfmonxy7(int y, int x)
{
	map_arr_loCation_level_7[y][x] = 0;
}





int attack(int x, int y,int k) // x = 몬스터 라이프 , y = 내 공격력/  몬스터에게 가한 피해량.
{
	int a = rand() % 100 + 1;

	int i = rand() % 5 - 1; //  9 10 11 12 13  
	int t = i + y; // 데미지 = 랜덤난수 + 플 레이어 공격력g
	if (a + k >= 100)
	{
		printf("\n\n      <<<<<< 크리티컬!!! >>>>>> \n\n\n");
		Sleep(1000);
		t += 0.3*t;
	}
	return t;
}

int attacked_monster(int x, int y,int k)
{
	int a = rand() % 100 + 1;
	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t = i + y; //데미지= 랜덤난수 + 몬스터 공격력
	if (a + k >= 100)
	{
		t = 0;
		printf("   <<<<<<ricaus는 피했다!!!>>>>>>\n\n");
	}
	return t;
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void monhpbar(int life,int maxlife)
{

	if (life <= maxlife*0.1)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.2 && life > maxlife*0.1)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.3 && life > maxlife * 0.2)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.4 && life > maxlife * 0.3)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.5 && life > maxlife * 0.4)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.6 && life > maxlife * 0.5)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.7 && life > maxlife * 0.6)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.8 && life > maxlife * 0.7)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar2(), specialChar2());
	}
	else if (life <= maxlife * 0.9 && life > maxlife * 0.8)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar2());
	}
	else if
		(life > maxlife *0.9)
	{
		printf("%s%s%s%s%s%s%s%s%s%s", specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar(), specialChar());
	}
}