#include "Functions.h"
#define CARS "cars.txt"					//Пути к файлам с данными			
#define MANAGERS "managers.txt"
#define DISCOUNTS "discounts.txt"


int main() {
	SetConsoleCP(1251);											//Устанавливает кодировку ввода из консоли и из редактора код
	SetConsoleOutputCP(1251);									//Устанавливает кодировку вывода на консоль
	bool menuRunning;											//Флаг прекращения работы главного меню								
	int mainMenuChoice;											//Вводимый пользователем выбор
	carList* carBase = new carList;								//Выделение памяти под список автомобилей
	managerList* managerBase = new managerList;					//Выделение памяти под список менеджеров
	discountList* discountBase = new discountList;				//Выделение памяти под список скидок
	carBase->inputFromFile(CARS);								//Заполнение списка автомобилей данными из файла
	managerBase->inputFromFile(MANAGERS, carBase);				//Заполнение списка менеджеров данными из файла
	discountBase->inputFromFile(DISCOUNTS, carBase);			//Заполнение списка скидок данными из файла
	menuRunning = true;
	
	while (menuRunning) {											
		cout << "Выберите действие" << endl;					//Печать главного меню
		cout << "1. Посмотрать автомобили в продаже" << endl;
		cout << "2. Вывести список менеджеров" << endl;
		cout << "3. Показать действующие скидки" << endl;
		cout << "4. ВЫХОД" << endl;
		do {
			
			cin >> mainMenuChoice;								//Считывание ответа пользователя пока не будет получаен обрабатываемый ответ
		} while (mainMenuChoice < 1 || mainMenuChoice > 4);
		
		switch (mainMenuChoice) {								//Обработка выбора пользователя						
		case 1:													//1. Посмотрать автомобили в продаже
			system("cls");	
			carBaseMenu(carBase);								//Вызов меню для работы с базой автомобилей
			break;
		case 2:													//2. Вывести список менеджеров
			system("cls");
			managerBaseMenu(managerBase);						//Вызов меню для работы с базой менеджеров
			break;
		case 3:													//3. Показать действующие скидки
			system("cls");
			discountsMenu(discountBase, managerBase);			//Вызов меню для работы с базой скидок
			break;
		case 4:													//4. ВЫХОД
			menuRunning = false;								//Остановка работы меню
			break;
		default:
			break;
		}
	}

	return 0;
}