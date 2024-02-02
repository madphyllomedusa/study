#include "Functions.h"

int carSearch(carList* carBase)										//Меня для поиска модели в базе автомобилей
{
	bool menuRunning;												//Флаг прекращения работы меню
	int menuChoice;													//Выбор пользователя из пунктов меню
	int searchResult;												//Флаг результата поиска по параметру. Значение =1 сигнелизирует о неудачном поиске
	string searchS;													//Переменные различного типа данных для записи параметра поиска
	float searchF;
	int searchI;
	menuRunning = true;				
	while (menuRunning) {
		cout << "Выберите параметр для поиска" << endl;				//Печать пунктов меню
		cout << " 1. Название модели" << endl;
		cout << " 2. Объем от, л" << endl;
		cout << " 3. Мощность от, л.с." << endl;
		cout << " 4. Тип двигателя" << endl;
		cout << " 5. Тип коробки" << endl;
		cout << " 6. Привод" << endl;
		cout << " 7. Цвет" << endl;
		cout << " 8. Цена от, руб" << endl;
		cout << " 9. Цена до, руб" << endl;
		cout << "10. Назад" << endl;
		do {														
			cin >> menuChoice;										//Считывание ответов пользователя пока не будет считан обрабатываемый ответ
		} while (menuChoice < 1 || menuChoice > 10);
		switch (menuChoice) {										//Обработка ответа пользователя
																	//Все варианты обрабатываются по одному и тому же алгоритму
		case 1:														
			cout << "Название модели ";
			cin >> searchS;											//Считывание параметра
			searchResult = carBase->Search_title(searchS);			//Поиск в списке по соответствующему полю
			if (searchResult == 1)									//Обработка отсутствия результата поиска
				cout << "Моделей, содержащих в названии " << searchS << " не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";					
			_getch();
			system("cls");
			break;
		case 2:
			cout << "Объем от, л ";
			cin >> searchF;
			searchResult = carBase->Search_engineVolume(searchF);
			if (searchResult == 1)
				cout << "Моделей, имеющих объем двигателя от  " << searchF << " л. не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 3:
			cout << "Мощность от, л.с. ";
			cin >> searchI;
			searchResult = carBase->Search_enginePower(searchI);
			if (searchResult == 1)
				cout << "Моделе, имеющих мощность двигателя от " << searchI << " л.с. не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 4:
			cout << "Тип двигателя ";
			cin >> searchS;
			searchResult = carBase->Search_engineType(searchS);
			if (searchResult == 1)
				cout << "Моделей с таким типом двигаетля не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 5:
			cout << "Тип коробки ";
			cin >> searchS;
			searchResult = carBase->Search_transmission(searchS);
			if (searchResult == 1)
				cout << "Моделей с таким типом коробки не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 6:
			cout << "Привод ";
			cin >> searchS;
			searchResult = carBase->Search_drive(searchS);
			if (searchResult == 1)
				cout << "Моделей с таким приводом не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 7:
			cout << "Цвет ";
			cin >> searchS;
			searchResult = carBase->Search_color(searchS);
			if (searchResult == 1)
				cout << "Моделей такого цвета не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 8:
			cout << "Цена от, руб ";
			cin >> searchI;
			searchResult = carBase->Search_priceFrom(searchI);
			if (searchResult == 1)
				cout << "Моделей с ценой от " << searchI << " рублей не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 9:
			cout << "Цена до, руб ";
			cin >> searchI;
			searchResult = carBase->Search_priceTo(searchI);
			if (searchResult == 1)
				cout << "Моделей с ценой до " << searchI << " рублей не найдено." << endl;
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 10:
			system("cls");
			menuRunning = false;
			break;
		}
	}
	return 0;
}

int carBaseMenu(carList* carBase)									//Меню для взаимодействия с базой автомобилей
{
	bool menuRunning;												//Флаг прекращения работы меню
	int menuChoice;													//Выбор пользователя из пунктов меню
	menuRunning = true;
	while (menuRunning) {
		cout << "Выберите действие" << endl;						//Печать пунктов меню
		cout << "1. Вывести все модели в продаже" << endl;
		cout << "2. Поиск по критерию" << endl;
		cout << "3. Назад" << endl;
		do {
			cin >> menuChoice;										//Считывание ответа пока не будет получени обрабатываемый ответ
		} while (menuChoice < 1 || menuChoice > 3);
		
		switch (menuChoice) {										//Обработка выбора пользователя
		case 1:														//1. Вывести все модели в продаже
			carBase->consoleOutput();								//Печать всех моделей на консоль
			cout << "Нажмите пробел чтобы вернуться.";
			_getch();
			system("cls");
			break;
		case 2:														//2. Поиск по критерию
			carSearch(carBase);										//Вызов меню для поиска модели по параметру
			break;
		case 3:														//3. Назад
			system("cls");
			menuRunning = false;									//Прекращение работы меню
			break;
		}
	}
	return 0;
}

int managerBaseMenu(managerList* managerBase)						//Меню для работы с базой менеджеров
{
	bool menuRunning;												//Флаг прекращения работы меню
	string menuChoice;												//Выбор пользователя из пунктов меню
	string managerChoice;											//ФИ менеджера для поиска
	Unit<Manager>* ptr;												//Указатель на элемент списка менеджеров
	Unit<Unit<Car>*>* carPtr;										//Указатель на вложенный список моделей с которыми работает менеджер
	menuRunning = true;
	while (menuRunning) {											
		managerBase->consoleOutput();								//Печать списка менеджеров на консоль
		do {
			cout << "Показать сделки проводимые менеджером?   Да/Нет" << endl;
			cin >> menuChoice;										//Считывание данных пока не будет получени обрабатываемый ответ
			if (menuChoice == "Да") {								//Обработка ответа пользователя - вывод информации о сделках менеджера
				cout << "Введите фамилию и имя выбранного менеджера: ";
				//cin >> managerChoice;
				_flushall();										
				getline(cin, managerChoice);
				getline(cin, managerChoice);						//Считывание ответа пользователя
				ptr = managerBase->Search_name(managerChoice);		//Поиск менеджера по имени
				if (ptr == NULL) {									//Обработка поиска не давшего результата
					cout << "Менеджер не найден." << endl;			
					menuChoice = "  ";								//Вывод меню на еще один цикл
				}
				else {												//Случай результативного поиска
					system("cls");										
					managerBase->printElement(ptr);					
					carPtr = ptr->getData().getSalesList()->getHead(); //Установка указателя на начала вложенного списка сделок
					do {												//Последовательная печать всех элементов вложенного списка
						cout << "Наименование: " << carPtr->getData()->getData().getTitile() << endl;
						cout << "Свойства двигателя:\n";
						cout << "\tОбъем:\t\t" << carPtr->getData()->getData().getEngineVolume() << " л." << endl;
						cout << "\tМощность:\t" << carPtr->getData()->getData().getEnginePower() << " л.с." << endl;
						cout << "\tТип:\t\t" << carPtr->getData()->getData().getEngineType() << endl;
						cout << "Коробка: " << carPtr->getData()->getData().getTransmission() << endl;
						cout << "Привод: " << carPtr->getData()->getData().getDrive() << endl;
						cout << "Цвет: " << carPtr->getData()->getData().getColor() << endl;
						cout << "Цена: " << carPtr->getData()->getData().getPrice() << endl;
						cout << "-----------------------------------------------------------------\n\n";
						carPtr = carPtr->getNext();
					} while (carPtr != NULL);
					cout << "Нажмите пробел чтобы вернуться.";
					_getch();
					system("cls");
				}
			}
			else if (menuChoice == "Нет") {
				menuRunning = false;								//Перекращение работы меню
				cout << "Нажмите пробел чтобы вернуться в главное меню.";
				_getch();
				system("cls");
			}
		} while (menuChoice != "Да" && menuChoice != "Нет");
	}
	return 0;
}

int discountsMenu(discountList* discountBase, managerList* managerBase)		//Меню для работы со списком акций
{
	
	Unit<Discount>* ptr;											//Указатель на элемент списка акций
	Unit<Car>* carPtr;												//Указатель на элемент списка автомобилей
	Unit<Manager>* managerPtr;										//Указатель на элемент списка менеджеров
	Unit<Unit<Car>*>* carListPtr;									//Указатель на элемент вложенного списка моделей
	int counter;													//Счетчик акицй
	int choice;														//Выбранный номер акций
	string menuChoice;												//Выбор пункта меню
	bool menuRunning = true;	
	bool stop;
	int newPrice;													//Цена с учетом скидки
	int price;														//Базовая цена
	float off;														//Скидка
	cout << "\t\t\t\tДЕЙСТВУЮЩИЕ АКЦИИ" << "\n\n\n";
	while (menuRunning) {
		counter = 1;
		ptr = discountBase->getHead();
		do {														//Печать всех акций с учетом их порядкового номера в выводимом меню
			discountBase->printElement(ptr, counter);				
			cout << endl;
			ptr = ptr->getNext();
			counter++;
		} while (ptr != NULL);
		cout << "Хотите получить подробную информацию об акции?    Да/Нет" << endl;
		do {
			cin >> menuChoice;										//Считывание ответа пользователя
			if (menuChoice == "Да") {								//Обработка ответа
				cout << "Введите номер акции: ";
				do {
					cin >> choice;									//Считывания ответа пока не будет получени обрабатываемый ответ
				} while (choice < 1 || choice > counter);
				ptr = discountBase->getHead();						//Указатель на элемент списка акций изначально указывает на голову списка
				for (int i = 0; i < choice - 1; i++)				
					ptr = ptr->getNext();							//Указатель смещается по списку пока не дойдет до элемента, порядковый номер которого совпадает с выбранным пользователем номером
				if (ptr != NULL) {									//Дополнительная проверка наличия результата поиска
					carPtr = ptr->getData().getRelatedCar();		//Печать информации об акции и соответствующей модели автомобиля
					price = carPtr->getData().getPrice();
					off = ptr->getData().getOffAmount();
					off = off / 100;
					cout << "Модель: " << endl;
					cout << "Наименование: " << carPtr->getData().getTitile() << endl;
					cout << "Свойства двигателя:\n";
					cout << "\tОбъем:\t\t" << carPtr->getData().getEngineVolume() << " л." << endl;
					cout << "\tМощность:\t" << carPtr->getData().getEnginePower() << " л.с." << endl;
					cout << "\tТип:\t\t" << carPtr->getData().getEngineType() << endl;
					cout << "Коробка: " << carPtr->getData().getTransmission() << endl;
					cout << "Привод: " << carPtr->getData().getDrive() << endl;
					cout << "Цвет: " << carPtr->getData().getColor() << endl;
					cout << "Цена: " << price;
					price = price - (price * off);
					cout << " => " << price;
					cout << "  (" << ptr->getData().getOffAmount() << "% OFF!)" << endl;
					cout << "ДЕЙСТВУЕТ ДО " << ptr->getData().getEndDate() << "!" << endl << endl;
					cout << "Менеджеры, работающие с этой моделью:\n";
					managerPtr = managerBase->getHead();
					do {																		//Вывод всех менеджеров работающих с данной моделью
						carListPtr = managerPtr->getData().getSalesList()->getHead();			//Указатель на голову вложенного списка указателей
						stop = false;
						do {																	//Проверка каждого элемента вложенного списка
							if (carListPtr->getData() == ptr->getData().getRelatedCar()) {		//Если указатель на искомую модель содержится в списке
								managerBase->printElement(managerPtr);							//Печать данных о менеджере на консоль
								stop = true;													//Остановка поиска в списке
							}
							carListPtr = carListPtr->getNext();
						} while (carListPtr != NULL && !stop);
						managerPtr = managerPtr->getNext();										//Переход к следующему менеджеру в списке
					} while (managerPtr != NULL);
				}
				else cout << "Возникла непредвиденная проблема. Повторите попытку позже.\n";	//Обработка неудачного поиска акции по номеру, что является алгоритмически невозможным сценарием, так как проверка выбора пользователя производится еще на стадии ввода
				cout << "Нажмите пробел чтобы вернуться.";
				_getch();
				system("cls");
			}
			else if (menuChoice == "Нет") {
				menuRunning = false;															//Прекращение работы меню
				cout << "Нажмите пробел чтобы вернуться в главное меню.";
				_getch();
				system("cls");
			}
		} while (menuChoice != "Да" && menuChoice != "Нет");
	}
	return 0;
}
