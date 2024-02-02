#include <iostream>
#include <string.h>

using namespace std;

float balance = 500046.67;			// ������ 
int alreadyGiven = 0;				// �������� �����

typedef struct paper {
	int value;						// ������� 
	int amount;						// ���-�� �����
}sPaper;
typedef struct Sums {
	int value;						// ������� 
	int pos;						// ���-�� �����
}sSums;
const int paperVariants = 7;		// ���-�� ��������� ��������� � �� ���-��
const int defaultSumsAmount = 5;	//���-�� ����������� ����
sPaper paper[paperVariants] =
{
	50, 1000,
	100, 1000,
	200, 1000,
	500, 1000,
	1000, 100,
	2000, 100,
	5000, 100
};

sSums defaultSums[defaultSumsAmount] = {	// C���������� �����
	500, -1,
	1000, -1,
	2000, -1,
	3000, -1,
	5000, -1
};

const int dayLimit = 200000;			// ������� ����� ������
const int oneTimeLimit = 100000;		// ����� ������
const int oneTimePaperLimit = 50;		// ����� ����� �� ���� ������

#include "biggestPaper.h"
#include "customWithdraw.h"
#include "withdraw.h"
 
int main() {
	setlocale(LC_ALL, "RUS");

	int answer;
	int amount = 0;						// �����, �������� �������������
	int smallestPaperValue;				// ����� ��������� ������
	int menuPos;						// ��������  ��������� ������������
	bool finish = false;
	bool withdrawAllowed = false;
	bool gotAnswer;

	do {

		smallestPaperValue = smallestPaper();
		menuPos = 3;
		puts("1) ��������� ������");
		puts("2) ������ ��������");
		if (smallestPaperValue != -1)
			if ((balance >= paper[smallestPaperValue].value) && (dayLimit != alreadyGiven)) {
				printf("%d) ����� ��������\n", menuPos);
				menuPos++;
				withdrawAllowed = true;
			}
		printf("%d) ��������� ������\n", menuPos);
		gotAnswer = false;
		while (!gotAnswer) {
			gotAnswer = true;
			cin >> answer;
			switch (answer) {
			case 1:					// �������� �������
				printf("�� ����� �����%10.2f ������.\n\n", balance);
				break;
			case 2:					// �������� ��������
				puts("������ �������� ����������, ���������� � ���������� �����.");
				break;
			case 3:					// ������ ��������
				if (withdrawAllowed) {
					withdrawMenu(smallestPaperValue);
					break;
				}
				else {
					finish = true;
					break;
				}
			case 4:					// ���������� ������
				if (withdrawAllowed) {
					finish = true;
					break;
				}
			default:
				puts("������������ �����.");
				gotAnswer = false;
			}
		}
	} while (!finish);
	puts("�������� ����� � ������� 50 ������.");

}