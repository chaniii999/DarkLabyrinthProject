#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// 10������ ���� �ٸ� ���� (ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� > ���� �����̸� ī�� ������
//��� ���� ���� ã���� ��������.
// �� ���� Ƚ�� �˷��ֱ�

/*int arrayAnimal[4][5]; //ī�� �迭 ����
int checkAnimal[4][5]; // ���������� ���� Ȯ�� 
char* strAnimal[10]; //���� �̸� �迭 ����
void initAnimalArray(); //ī�� ���� �迭 �ʱ�ȭ �Լ� ����
void initAnimalName(); //���� �̸� �迭 �ʱ�ȭ �Լ� ����
void suffleAnimal(); //ī�� ���� �Լ� ���� 
int getEmptyPosition(); //�� ���� ã�� �Լ� ���� 
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();




int main_����(void)
{
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();

	suffleAnimal();

	int failCount = 0;//���� Ƚ��

	while (1) {
		int select1 = 0; //������ ù���� ��
		int select2 = 0; //������ �ι�° ��

		printAnimals();// ���� ��ġ ���
		printQuestion();// ���� ���( ī�� ���� )
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)//���� ī�� ���ý� ��ȿ
			continue;

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ Ȯ��.
		//
		// ���� ��ǥ�� x,y�� ��ȯ.
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		//���� ������ ���
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]
			== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n����! : %s �߰�!\n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else
		{
			printf("��~~~ Ʋ�Ⱦ��~!");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x] [firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;

		}
		// ��� ������ ã�Ҵ��� ����
		if (foundAllAnimals() == 1)
		{
			printf("\n\n �����մϴ�! ��� ������ ã�Ҿ�� \n");
			printf("���ݱ��� �� %d�� �Ǽ��߾��!\n", failCount);
			break;
		}
	}




	return 0;
}

void initAnimalName() {
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "��Ÿ";
	strAnimal[7] = "�⸰";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";

}

void suffleAnimal() { //ī�� ���� �Լ� ����
	for (int i = 0; i < 10; i++) { // ���� �̸� �� ��ŭ �ݺ�
		for (int j = 0; j < 2; j++) { //���� ���� 2�� �ݺ�
			int pos = getEmptyPosition(); // ī���������� �����ã�� �Լ� ȣ��
			int x = conv_pos_x(pos); // ī���ȣ�� x��ǥ�� ��ȯ
			int y = conv_pos_y(pos); // ī���ȣ�� y��ǥ�� ��ȯ
			arrayAnimal[x][y] = i;  //ī�� �迭�� ���� ��ȣ ����.
		}
	}
}


void initAnimalArray() // �Լ� ����
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1; //��ī�忡 �޸�(-1)����
		}
	}
}
int getEmptyPosition() { // �� ����(randPos) ã�Ƽ� x,y ��ǥ������ ��ȯ����) 19�� �̾Ҵٸ� > (3,4)���� ��ȯ.
	while (1) {
		int randPos = rand() % 20; //0~19 �߿� ���� ����
		int x = conv_pos_x(randPos); //randPos�� x������ ����
		int y = conv_pos_y(randPos); //randPos�� y������ ����
		if (arrayAnimal[x][y] == -1) {
			return randPos; //ã�� ������ ������� ī�� ��ȣ ��ȯ
		}
	}
	return 0;
}

int conv_pos_x(int x) {
	return x / 5;//5�� ������ 0,1,2,3,4 ������� ����.
}

int conv_pos_y(int y) {
	return y % 5; //y�� 5�� ���� ��������.
}

void printAnimals() //������ġ ���
{
	printf("\n=============�̰� ����̾�~~~~============\n\n");
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
void printQuestion()//���� ��� (ī�� ����)
{
	printf("\n\n(����)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//����� ������ ����ٸ� �����̸�
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else {
				printf("%8d", seq);
			}
			seq++;
			//�����̾ƴϸ� ���ڷ�.

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