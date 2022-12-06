#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
// 裘擊 掘撩ж朝 棻離錳 寡翮 л熱蒂 虜菟濠.
// 謝ル蒂 薑曖ж朝 謝ル 寡翮婁 , 褒韓瞳檣 嬪纂縑 п渡ж朝 嬪纂 寡翮擊 虜菟濠.
// 謝ル寡翮擎 int 煎 嬪纂 寡翮擎 char 煎 摹樹ж濠.

//酈爾萄 高
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define	SUBMIT 4 // 摹鷗 (Enter 酈)

void gotoxy(int x, int y);


// 蟾晦 л熱

int game = 0; // 顫檜ぎ擎 0 啪歜衛濛擎 1

// 詭景л熱
int titleDraw(); // 衛濛�飛� л熱.
int proLogueDraw(); //Щ煤煎斜 摹鷗л熱.
int menuDraw(); // 詭景 摹鷗雖л熱
int skillmenuDraw(); // 蝶鑒 摹鷗雖 л熱
//int itemDraw();//嬴檜蠱 摹鷗л熱

int select_num = 0; //瞪癱鼻�� 摹鷗雖 蟾晦��

//裘 婦溼л熱

int dengeon_level = 1;

int situation_num = 1; //衛鏘縑檜暮 剩幗

char map_arr_loCation_level_1[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// 嬪纂л熱 摹樹.
char map_arr_loCation_level_2[10][10] = { {0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0 } };// 嬪纂л熱 摹樹.

void printQuestion_level_1(); // 裘 轎溘
void printQuestion_level_2(); // 2類 轎溘

int keyControl();
void monster1_move_system(int arr[][10], int a, int b); // 跨蝶攪 鼠粽 頂濰 л熱



void move_player(int x, int y); //Ы溯檜橫 謝ル
void bef_move_player(int x, int y); //Ы溯檜橫 檜瞪 謝ル 蟾晦��

void move_monster(int x, int y); // 跨蝶攪謝ル
void bef_move_monster(int x, int y); //跨蝶攪 檜瞪 謝ル 蟾晦��


void creaTor_great_Wall(int a, int b); //纔舒葬 漁 薯濛 л熱

int Player = 1; //Ы溯檜橫 堅嶸高
int monster1 = 4; //跨蝶攪1 堅嶸高
int npc1 = 5; // npc1堅嶸高.
int enTrance = 3;





int x_mon = 0; //跨蝶攪 謝ル高
int y_mon = 0;

int monster1_life = 1; // 跨蝶攪陛 髦嬴氈朝雖 罹睡


//瞪癱л熱
int turn = 0;
int cnt_turn_stab = -3;
int cnt_turn_rage = -5;
int cnt_turn_heal = -3;

int attack(int x, int y);  // 奢問 л熱

int attacked_monster(int x, int y); //Я問 л熱


char *item[20]; // 僥濠翮擊 寡翮縑 厥晦嬪п * 厥擠.


//蝶鑒л熱
int skill_several_stab(int a);
int skill_holy_Heal(int x, int y);
int skill_rage(int x);
int cnt_attack = 0;
int rage = 0;

typedef struct objecT
{
	char* name;// 偃羹貲
	int attack;// 奢問溘
	int life;  // 儅貲溘
	int max_life;// 譆渠 儅貲溘
	char* item[20];// 嬴檜蠱蘊. 虜擒 羅蘊縑 嬴檜蠱檜氈棻賊? for僥 餌辨ж罹 i++ п憮 營衛紫ж罹 濰雜
	int crono; //�倖�
	int exp; // 唳я纂
	int level;
}oBject;

////////////////////////////////////                             ///////////////////////////////////////////////////////                        ///////////////////////


int main(void)
{
	srand(time(NULL));
	system("mode con cols=30 lines=12");

	oBject player; //Ы溯檜橫 薑曖
	player.name = "player";
	player.attack = 10;
	player.crono = 500;
	player.level = 1;
	player.exp = 0;
	player.max_life = 50;
	player.life = player.max_life; 

	oBject monster1; //跨蝶攪 1 薑曖.
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

	int key = 0; // Ы溯檜橫 檜翕 滲熱 

	int a = 1; //Ы溯檜橫 衛濛 嬪纂
	int b = 1; //Ы溯檜橫 衛濛 嬪纂

	int t = 10; // 裘 陛煎 望檜
	int g = 10; // 裘 撮煎 望檜

	map_arr_loCation_level_1[8][8] = enTrance;


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
			printf("\n\n\n  Welcome to my Labyrinth. . .");
			Sleep(2500);
			system("cls");
			printf("\n\n\n -Щ煤煎斜蒂 爾衛啊蝗棲梱?-");
			switch (proLogueDraw())
			{
			case 0:
			{
				system("cls");
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(1500);
				printf("螃棺紫 撿斬檜棻..\n");
				Sleep(1500);
				printf("雖耀 跺擊 檜莊堅 餵戲煎 щи棻...\n");
				Sleep(1500);
				printf("\"頂橾擎  �瓿狨抴炱� ヱ 蓮濠..\"\n");
				Sleep(1500);
				printf("\"橫?.. 罹曹?... \"\n");
				Sleep(3000);
				game = 1;
			}
			case 1:
			{
				system("cls");
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(100);
				printf("天天天天天天天天天天天天天天天\n");
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
		while (map_arr_loCation_level_1[x_mon][y_mon] != 0) //  跨蝶攪 模�� 謝ル 撲薑 0橾陽梱雖 and 議葛攪 蕙檜 嬴棍陽梱雖.
		{
			x_mon = rand() % (t - 3) + 2; // 2,3,4,5,6,7,8,9
			y_mon = rand() % (g - 3) + 2; // 2,3,4,5,6,7,8,9
		}
	}



	while (game == 1)//啪歜霞ч醞 // �飛� 雖樓.
	{

		if (situation_num == 1) //ゎ鼻衛
		{
			if (dengeon_level == 1)
			{
				printQuestion_level_1();//裘 ル衛
				if (map_arr_loCation_level_1[8][8] == Player)
				{
					dengeon_level = 2;
				}
			}
			
			if (dengeon_level == 2) 
			{
				printQuestion_level_2();
			}
			move_player(a, b); // 議葛攪 ⑷ 謝ル л熱.
			move_monster(y_mon, x_mon); // 跨蝶攪 ⑷ 謝ル.
			if (kbhit())
			{

				key = _getch();
				bef_move_player(a, b); // 檜瞪 Ы溯檜橫曖 嬪纂縑 氈朝 1擊 雖錶邀. 
				switch (key)
				{
				case 72:
					if (map_arr_loCation_level_1[a - 1][b] == 0 ||
						map_arr_loCation_level_1[a - 1][b] == 3 ) //陛堅濠ж朝 濠葬陛 0橾陽虜 陛棟.
						a--;
					break;
				case 75:
					if (map_arr_loCation_level_1[a][b - 1] == 0 ||
						map_arr_loCation_level_1[a][b - 1] == 3 )
						b--;
					break;
				case 77:
					if (map_arr_loCation_level_1[a][b + 1] == 0 ||
						map_arr_loCation_level_1[a][b + 1] == 3 )
						b++;
					break;
				case 80:
					if (map_arr_loCation_level_1[a + 1][b] == 0 ||
						map_arr_loCation_level_1[a + 1][b] == 3 )
						a++;
					break;
				default:
					break;
				}

			}
			if (monster1_life == 1)
			{
				monster1_move_system(map_arr_loCation_level_1,y_mon,x_mon);
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
					printf("天天天天天天天天天天天天天天天\n");
				}

			}

		}
		if (situation_num == 2) // 瞪癱衛濛翱轎
		{

			Sleep(100);

			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf(" %s陛 釭顫陬棻!\n", monster1.name);
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(800);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(100);
			printf("天天天天天天天天天天天天天天天\n");
			Sleep(500);
			system("cls");
			situation_num = 3;




		}
		if (situation_num == 3) //渠纂醞
		{

			printf("天天天天天天天天天天天天天天天\n");
			printf(" %s曖 羹溘: %d\n\n", monster1.name, monster1.life);
			printf(" 渡褐曖 羹溘 :%d\n", player.life);
			printf("天天天天⑷營 欐:%d天天天\n", turn);
			switch (menuDraw())//瞪癱摹鷗雖
			{
			case 0: //奢問
			{
				system("cls");
				turn++;
				cnt_monster1_life = monster1.life;
				cnt_player_life = player.life;
				monster1.life -= attack(monster1.life, player.attack);
				player.life -= attack(player.life, monster1.attack);
				printf("天天天天天天天天天天天天天天天\n");
				Sleep(1000);
				printf("% s朝 % s縑啪\n 匐擊 ��離啪 �硉挶韌�!\n\n", player.name, monster1.name);
				Sleep(1000);
				printf("%s縑啪 %d曖\n 等嘐雖蒂 輿歷棻.\n\n", monster1.name, cnt_monster1_life - monster1.life);  // 奢問嫡晦瞪 - 嫡擎�� =等嘐雖
				Sleep(1500);
				if (monster1.life <= 0)
				{
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					system("cls");
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(1000);
					printf("%s蒂 噙楝お溜棻!\n", monster1.name);
					Sleep(1000);
					printf("%d 觼煎喻 蒂 橢歷棻!\n", monster1.crono);
					player.crono += monster1.crono;
					Sleep(500);
					printf("%d 唳я纂蒂 �僱磈葧�!", monster1.exp);
					player.exp += monster1.exp;
					Sleep(500);
					printf("天天天天天天天天天天天天天天天\n");
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
					printf("%s朝 %s縑啪\n 殖溥菟歷棻!\n\n", monster1.name, player.name);
					Sleep(1000);
					printf("%s朝 %d曖\n 等嘐雖蒂 嫡歷棻.\n\n", player.name, cnt_player_life - player.life);
					Sleep(1500);
					if (player.life <= 0)
					{
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(500);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(500);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(500);
						printf("辨餌朝 ��擊 棻ж艘棻...");
						Sleep(1000);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(300);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(300);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(300);
						system("cls");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(500);
						printf("		   GAME OVER\n");
						Sleep(1000);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(500);
						_getch();
						break;
					}
					system("cls");
					situation_num = 3;
				}
				break;
			}
			case 1: //寞橫
			{
				turn++;
				cnt_player_life = player.life;
				system("cls");
				printf("天天天天天天天天天天天天天天天\n");
				player.life -= (attack(player.life, monster1.attack)) / 3;
				printf("%s朝 寞橫鷓撮縑 菟橫鬲棻!\n", player.name);
				Sleep(1000);
				printf("%s朝 %s縑啪\n 殖溥菟歷棻!\n\n", monster1.name, player.name);
				Sleep(1500);
				printf("%s朝 %d曖\n 等嘐雖蒂 嫡歷棻.\n\n", player.name, cnt_player_life - player.life);
				Sleep(1000);
				if (player.life <= 0)
				{
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(500);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(500);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(500);
					printf("%s朝 ��擊 棻ж艘棻...", a);
					Sleep(1000);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(300);
					system("cls");
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(500);
					printf("		   GAME OVER\n");
					Sleep(1000);
					printf("天天天天天天天天天天天天天天天\n");
					Sleep(500);
					_getch();
					break;
				}
				else
					system("cls");
				situation_num = 3;
				break;
			}
			case 2: //蝶鑒
			{
				system("cls");
				printf("天天天天天天天天天天天天天天天\n");
				printf(" %s曖 羹溘: %d\n\n", monster1.name, monster1.life);
				printf(" 渡褐曖 羹溘 :%d\n", player.life);
				printf("天天天天天天天天天天天天天天天\n");
				switch (skillmenuDraw())
				{
				case 0: //翱樓鎬腦晦
				{
					if (turn < cnt_turn_stab + 3)
					{
						system("cls");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1000);
						printf("嬴霜 餌辨й 熱 橈蝗棲棻.\n");
						printf("天天天天天天天天天天天天天天天\n");
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
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1500);
						printf("%s朝 翱樓 鎬腦晦蒂 餌辨ц棻!\n", player.name);
						Sleep(1000);
						printf("%s朝 %s縑啪 %d曖 等嘐雖蒂 輿歷棻.\n", player.name, monster1.name, skill_several_stab(player.attack));
						Sleep(2000);

						if (monster1.life <= 0)
						{
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(300);
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(300);
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(300);
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(300);
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(300);
							system("cls");
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(1000);
							printf("%s蒂 噙楝お溜棻!\n", monster1.name);
							Sleep(1000);
							printf("%d 觼煎喻 蒂 橢歷棻!\n", monster1.crono);
							player.crono += monster1.crono;
							Sleep(500);
							printf("%d 唳я纂蒂 �僱磈葧�!\n", monster1.exp);
							player.exp += monster1.exp;
							Sleep(500);
							printf("天天天天天天天天天天天天天天天\n");
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
							printf("%s朝 %s縑啪\n 殖溥菟歷棻!\n\n", monster1.name, player.name);
							Sleep(1000);
							printf("%s朝 %d曖\n 等嘐雖蒂 嫡歷棻.\n\n", player.name, cnt_player_life - player.life);
							Sleep(1500);
							if (player.life <= 0)
							{
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(500);
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(500);
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(500);
								printf("辨餌朝 ��擊 棻ж艘棻...\n");
								Sleep(1000);
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(300);
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(300);
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(300);
								system("cls");
								printf("天天天天天天天天天天天天天天天\n");
								Sleep(500);
								printf("		   GAME OVER\n");
								Sleep(1000);
								printf("天天天天天天天天天天天天天天天\n");
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
				case 1://�蛹�
				{
					if (turn < cnt_turn_heal + 3)
					{
						system("cls");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1000);
						printf("嬴霜 餌辨й 熱 橈蝗棲棻.\n");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1500);
						situation_num = 3;
					}
					else
					{
						turn++;
						cnt_turn_heal = turn;
						cnt_player_life = player.life;
						system("cls");
						player.life += skill_holy_Heal(player.life, player.attack); //�� 衛瞪
						if (player.life > cnt_player_life) // 衛瞪 �� 譆渠儅貲溘爾棻 堪嬴雖啪脹棻賊
						{
							player.life = player.max_life;

							printf("天天天天天天天天天天天天天天天\n");
							Sleep(1500);
							printf("褐眷 晦紫蒂 萄董棲棻...\n\n");
							Sleep(1500);
							printf("辨餌朝 %d曖 羹溘擊 �蛹嘎葧�!\n", player.max_life - cnt_player_life);
						}
						else
						{
							printf("天天天天天天天天天天天天天天天\n");
							Sleep(1500);
							printf("褐眷 晦紫蒂 萄董棲棻...\n\n");
							Sleep(1500);
							printf("辨餌朝 %d曖 羹溘擊 �蛹嘎葧�!\n", skill_holy_Heal(player.life, player.attack));
						}
						Sleep(500);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(2000);
						system("cls");
						break;
					}
				}
				case 2: //碟喻
				{
					if (rage == 0 && turn < cnt_turn_rage + 5)
					{
						system("cls");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1000);
						printf("嬴霜 餌辨й 熱 橈蝗棲棻.\n");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1500);
						situation_num = 3;
					}
					else if (rage == 1)
					{
						system("cls");
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1000);
						printf("嬴霜 餌辨й 熱 橈蝗棲棻.\n");
						printf("天天天天天天天天天天天天天天天\n");
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
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(1000);
						printf("辨餌朝 選睡瞽歷棻.\n\n⑷營 欐%d  盪濰脹 欐%d\n", turn, cnt_turn_rage);
						Sleep(1500);
						printf(" \"辦 螃 螃 螃 ! ! !\"\n\n");
						player.attack += skill_rage(player.attack);
						Sleep(1500);
						printf("辨餌曖 奢問溘檜 橾衛瞳戲煎 隸陛ц棻!\n%d %d\n", player.attack, cnt_attack);
						printf("天天天天天天天天天天天天天天天\n");
						Sleep(2000);
						system("cls");
						situation_num = 3;
						break;
					}
				}
				case 3: //給嬴除棻
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
			case 3: // 嬴檜蠱
			{
				printf("天天天天天天天天天天天天天天天\n");
				printf("餌辨й 嬴檜蠱擊 摹鷗ж撮蹂. \n");
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
				player.attack = cnt_attack; // 奢問溘擊 溯檜雖 瞪縑 瞳辨п堡湍 奢問溘戲煎 腎給葡.

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

void printQuestion_level_1()//裘 轎溘
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf(" %d ", map_arr_loCation_level_1[i][j]);


		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}

void printQuestion_level_2()//裘 轎溘
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf(" %d ", map_arr_loCation_level_2[i][j]);


		}
		printf("\n");
	}
	printf("dengeon_level=%d", dengeon_level);
}


void creaTor_great_Wall(int a,int b) // 漁虜菟晦
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

void move_monster(int x, int y) // 跨蝶攪 嬪纂 翕晦��
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
	printf("-蕨-");
	gotoxy(x, y + 1);
	printf("-嬴棲螃-");

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
	printf("奢問");
	gotoxy(x, y + 1);
	printf("寞橫");
	gotoxy(x, y + 2);
	printf("蝶鑒");
	gotoxy(x, y + 3);
	printf("嬴檜蠱");
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
		printf("-翱樓 鎬腦晦(Lv.1)-\n"); //[70 % 曖 奢問溘戲煎 2~3廓 鎬艇棻.\n]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y);
		printf("-翱樓 鎬腦晦(Lv.1)-\n"); //[70 % 曖 奢問溘戲煎 2~3廓 鎬艇棻.\n]
	}
	if (turn < cnt_turn_heal + 3)
	{
		gotoxy(x, y + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-褐撩и �蛹�(Lv.1)-\n");//[奢問溘曖 70 % 曖 熱纂煎 羹溘擊 �蛹嘎挬�.]
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		gotoxy(x, y + 1);
		printf("-褐撩и �蛹�(Lv.1)-\n");//[奢問溘曖 70 % 曖 熱纂煎 羹溘擊 �蛹嘎挬�.]
	}
	if (rage == 1 || (rage == 0 && turn < cnt_turn_rage + 5)) // ⑷營 幗Щ醞檜剪釭 籐顫歜檜 寰給懊擊��.
	{
		gotoxy(x, y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("-辨餌曖 碟喻(Lv.1)-\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (rage == 0) //[3欐除 奢問溘檜 30 % 隸陛и棻.]
	{
		gotoxy(x, y + 2);
		printf("-辨餌曖 碟喻(Lv.1)-\n");
	}
	gotoxy(x, y + 3);
	printf("-給嬴除棻-");
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

int attack(int x,int y) // x = 跨蝶攪 塭檜Щ , y = 頂 奢問溘/  跨蝶攪縑啪 陛и Яп榆.
{

	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t =  i + y; // 等嘐雖 = 楠渾陪熱 + Ы 溯檜橫 奢問溘
	return t;
}

int attacked_monster(int x, int y)
{
	int i = rand() % 5 - 1; //  9 10 11 12 13 
	int t = i + y; //等嘐雖= 楠渾陪熱 + Ы溯檜橫 奢問溘
	return t;
}

int skill_several_stab(int a)
{
	int temp = rand() % 2 + 2; //陪熱
	int dem = temp * (a * 0.8);
	return dem;
}

int skill_holy_Heal(int x, int y) // 辨餌 羹溘,辨餌 奢問溘
{
	int t = y * (0.8);
	x += t;
	return t;
}

int skill_rage(int x)// 3欐 翕寰 辨餌 奢問溘 籐顫歜 6
{
	int t = x * (0.3); // t(蹺陛 奢問溘) = 奢問溘 * 0.3 檜棻.
	return t; // 奢問溘縑 t蒂 蹺陛и棻.
}

void monster1_move_system(int arr[][10], int y, int x) {
	if (kbhit())
	{
		int dirM1 = rand() % 4;
		switch (dirM1) // 跨蝶攪 綠瞪癱ぬ欐
		{
		case 0:
			if (map_arr_loCation_level_1[y_mon - 1][x_mon] == 0) //陛堅濠ж朝 濠葬陛 0橾陽虜 陛棟.
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