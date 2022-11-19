#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// 10마리의 서로 다른 동물 (카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 > 같은 동물이면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임종료.
// 총 실패 횟수 알려주기

/*int arrayAnimal[4][5]; //카드 배열 선언
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인 
char* strAnimal[10]; //동물 이름 배열 선언
void initAnimalArray(); //카드 지도 배열 초기화 함수 선언
void initAnimalName(); //동물 이름 배열 초기화 함수 선언
void suffleAnimal(); //카드 섞기 함수 선언 
int getEmptyPosition(); //빈 공간 찾기 함수 선언 
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();




int main_참고(void)
{
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();

	suffleAnimal();

	int failCount = 0;//실패 횟수

	while (1) {
		int select1 = 0; //선택한 첫번쨰 수
		int select2 = 0; //선택한 두번째 수

		printAnimals();// 동물 위치 출력
		printQuestion();// 문제 출력( 카드 지도 )
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)//같은 카드 선택시 무효
			continue;

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 확인.
		//
		// 정수 좌표를 x,y로 변환.
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		//같은 동물일 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]
			== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n빙고! : %s 발견!\n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else
		{
			printf("땡~~~ 틀렸어요~!");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x] [firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;

		}
		// 모든 동물을 찾았는지 여부
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 축하합니다! 모든 동물을 찾았어요 \n");
			printf("지금까지 총 %d번 실수했어요!\n", failCount);
			break;
		}
	}




	return 0;
}

void initAnimalName() {
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "낙타";
	strAnimal[7] = "기린";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";

}

void suffleAnimal() { //카드 섞기 함수 정의
	for (int i = 0; i < 10; i++) { // 동물 이름 수 만큼 반복
		for (int j = 0; j < 2; j++) { //같은 동물 2번 반복
			int pos = getEmptyPosition(); // 카드지도에서 빈공간찾기 함수 호출
			int x = conv_pos_x(pos); // 카드번호를 x좌표로 변환
			int y = conv_pos_y(pos); // 카드번호를 y좌표로 변환
			arrayAnimal[x][y] = i;  //카드 배열에 동물 번호 저장.
		}
	}
}


void initAnimalArray() // 함수 정의
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1; //각카드에 뒷면(-1)설정
		}
	}
}
int getEmptyPosition() { // 빈 공간(randPos) 찾아서 x,y 좌표값으로 변환해줌) 19를 뽑았다면 > (3,4)으로 변환.
	while (1) {
		int randPos = rand() % 20; //0~19 중에 랜덤 추출
		int x = conv_pos_x(randPos); //randPos의 x값으로 선언
		int y = conv_pos_y(randPos); //randPos의 y값으로 선언
		if (arrayAnimal[x][y] == -1) {
			return randPos; //찾은 공간이 비었으면 카드 번호 반환
		}
	}
	return 0;
}

int conv_pos_x(int x) {
	return x / 5;//5로 나눠서 0,1,2,3,4 등등으로 만듬.
}

int conv_pos_y(int y) {
	return y % 5; //y를 5로 나눈 나머지값.
}

void printAnimals() //동물위치 출력
{
	printf("\n=============이건 비밀이야~~~~============\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n=========================================\n\n");

}
void printQuestion()//문제 출력 (카드 지도)
{
	printf("\n\n(문제)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//뒤집어서 정답을 맞췄다면 동물이름
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else {
				printf("%8d", seq);
			}
			seq++;
			//정답이아니면 숫자로.

		}
		printf("\n");
	}

}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
}*/