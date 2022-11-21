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

void gotoxy(int x, int y);


// 초기 함수

int game = 0; // 타이틀은 0 게임시작은 1

// 메뉴함수
int titleDraw(); // 시작화면 함수.
int proLogueDraw(); //프롤로그 선택함수.
int menuDraw(); // 메뉴 선택지함수
int skillmenuDraw(); // 스킬 선택지 함수
//int itemDraw();//아이템 선택함수

int select_num = 0; //전투상황 선택지 초기화

//맵 관련함수

int situation_num = 1; //시츄에이션 넘버

char map_arr_loCation_level_1[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// 위치함수 선언.

void printQuestion(); // 맵 출력

int keyControl();

void move_player(int x, int y); //플레이어 좌표
void bef_move_player(int x, int y); //플레이어 이전 좌표 초기화

void move_monster(int x, int y); // 몬스터좌표
void bef_move_monster(int x, int y); //몬스터 이전 좌표 초기화


void creaTor_great_Wall(int a, int b); //테두리 벽 제작 함수

int Player = 1; //플레이어 고유값
int monster1 = 4; //몬스터1 고유값

int x_mon = 0; //몬스터 좌표값
int y_mon = 0;

int monster1_life = 1; // 몬스터가 살아있는지 여부

int direct_monswer1 = -1; // 몬스터 방향 난수 초기화

//전투함수
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
	player.attack = 10;
	player.crono = 500;
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

	int cnt_monster1_life = monster1.life;
	int cnt_player_life = player.life;

	int key = 0; // 플레이어 이동 변수 

	int a = 1; //플레이어 시작 위치
	int b = 1; //플레이어 시작 위치

	int t = 10; // 맵 가로 길이
	int g = 10; // 맵 세로 길이

	
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

	while (map_arr_loCation_level_1[x_mon][y_mon] != 0) //  몬스터 소환 좌표 설정 0일때까지 and 캐릭터 옆이 아닐때까지.
	{
		x_mon = rand() % (t - 2) + 1; // 1,2,3,4,5,6,7,8
		y_mon = rand() % (g - 2) + 1; // 1,2,3,4,5,6,7,8
	}



	while (game == 1)//게임진행중 // 화면 지속.
	{

		if (situation_num == 1) //평상시
		{

			printQuestion();  //맵 표시

			move_player(a, b); // 캐릭터 현 좌표 함수.
			move_monster(y_mon, x_mon); // 몬스터 현 좌표.
			if (kbhit())
			{

				key = _getch();
				bef_move_player(a, b); // 이전 플레이어의 위치에 있는 1을 지워줌. 
				switch (key)
				{
				case 72:
					if (map_arr_loCation_level_1[a - 1][b] == 0) //가고자하는 자리가 0일때만 가능.
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
					switch (direct_monswer1) // 몬스터 비전투패턴
					{
					case 0:
						if (map_arr_loCation_level_1[y_mon - 1][x_mon] == 0) //가고자하는 자리가 0일때만 가능.
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
					printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
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
					printf("%s는 힘을 다하였다...", a);
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
							monster1_life;
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

	void move_player(int x, int y)
{
	map_arr_loCation_level_1[x][y] = Player;
}
void bef_move_player(int x, int y)
{
	map_arr_loCation_level_1[x][y] = 0;
}

void printQuestion()//맵 출력
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

void creaTor_great_Wall(int a,int b) // 벽만들기
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

void move_monster(int x, int y) // 몬스터 위치 동기화
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
		printf("-연속 찌르기(Lv.1)-\n"); //[70 % 의 공격력으로 2~3번 찌른다.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-연속 찌르기(Lv.1)-\n"); //[70 % 의 공격력으로 2~3번 찌른다.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-신성한 회복(Lv.1)-\n");//[공격력의 70 % 의 수치로 체력을 회복한다.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-신성한 회복(Lv.1)-\n");//[공격력의 70 % 의 수치로 체력을 회복한다.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // 현재 버프중이거나 쿨타임이 안돌았을떄.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-용사의 분노(Lv.1)-\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3턴간 공격력이 30 % 증가한다.]
	{
		gotoxy(x, y + 2);
		printf("-용사의 분노(Lv.1)-\n");
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
	int dem = temp * (a * 0.8);
	return dem;
}

int skill_holy_Heal(int x, int y) // 용사 체력,용사 공격력
{
	int t = y * (0.8);
	x += t;
	return t;
}

int skill_rage(int x)// 3턴 동안 용사 공격력 쿨타임 6
{
	int t = x * (0.3); // t(추가 공격력) = 공격력 * 0.3 이다.
	return t; // 공격력에 t를 추가한다.
}