#include <iostream>
#include <string.h>

using namespace std;

float balance = 500046.67;			// Баланс 
int alreadyGiven = 0;				// Выданная сумма

typedef struct paper {
	int value;						// Номинал 
	int amount;						// Кол-во купюр
}sPaper;
typedef struct Sums {
	int value;						// Номинал 
	int pos;						// Кол-во купюр
}sSums;
const int paperVariants = 7;		// Кол-во различных номиналов и их кол-во
const int defaultSumsAmount = 5;	//Кол-во стандартных сумм
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

sSums defaultSums[defaultSumsAmount] = {	// Cтандартные суммы
	500, -1,
	1000, -1,
	2000, -1,
	3000, -1,
	5000, -1
};

const int dayLimit = 200000;			// Дневной лимит снятия
const int oneTimeLimit = 100000;		// Лимит снятия
const int oneTimePaperLimit = 50;		// Лимит купюр за одну выдачу

#include "biggestPaper.h"
#include "customWithdraw.h"
#include "withdraw.h"
 
int main() {
	setlocale(LC_ALL, "RUS");

	int answer;
	int amount = 0;						// Сумма, вводимая пользователем
	int smallestPaperValue;				// Самая маленькая купюра
	int menuPos;						// Варианты  доступные пользователю
	bool finish = false;
	bool withdrawAllowed = false;
	bool gotAnswer;

	do {

		smallestPaperValue = smallestPaper();
		menuPos = 3;
		puts("1) Проверить баланс");
		puts("2) Внести наличные");
		if (smallestPaperValue != -1)
			if ((balance >= paper[smallestPaperValue].value) && (dayLimit != alreadyGiven)) {
				printf("%d) Снять наличные\n", menuPos);
				menuPos++;
				withdrawAllowed = true;
			}
		printf("%d) Завершить работу\n", menuPos);
		gotAnswer = false;
		while (!gotAnswer) {
			gotAnswer = true;
			cin >> answer;
			switch (answer) {
			case 1:					// Проверка баланса
				printf("На Вашем счету%10.2f рублей.\n\n", balance);
				break;
			case 2:					// Внесение наличных
				puts("Данная операция недоступна, обратитесь к сотруднику банка.");
				break;
			case 3:					// Снятие наличных
				if (withdrawAllowed) {
					withdrawMenu(smallestPaperValue);
					break;
				}
				else {
					finish = true;
					break;
				}
			case 4:					// Завершение работы
				if (withdrawAllowed) {
					finish = true;
					break;
				}
			default:
				puts("Неприемлимый ответ.");
				gotAnswer = false;
			}
		}
	} while (!finish);
	puts("Заберите карту в течение 50 секунд.");

}