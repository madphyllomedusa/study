#include "Functions.h"

int carSearch(carList* carBase)										//���� ��� ������ ������ � ���� �����������
{
	bool menuRunning;												//���� ����������� ������ ����
	int menuChoice;													//����� ������������ �� ������� ����
	int searchResult;												//���� ���������� ������ �� ���������. �������� =1 ������������� � ��������� ������
	string searchS;													//���������� ���������� ���� ������ ��� ������ ��������� ������
	float searchF;
	int searchI;
	menuRunning = true;				
	while (menuRunning) {
		cout << "�������� �������� ��� ������" << endl;				//������ ������� ����
		cout << " 1. �������� ������" << endl;
		cout << " 2. ����� ��, �" << endl;
		cout << " 3. �������� ��, �.�." << endl;
		cout << " 4. ��� ���������" << endl;
		cout << " 5. ��� �������" << endl;
		cout << " 6. ������" << endl;
		cout << " 7. ����" << endl;
		cout << " 8. ���� ��, ���" << endl;
		cout << " 9. ���� ��, ���" << endl;
		cout << "10. �����" << endl;
		do {														
			cin >> menuChoice;										//���������� ������� ������������ ���� �� ����� ������ �������������� �����
		} while (menuChoice < 1 || menuChoice > 10);
		switch (menuChoice) {										//��������� ������ ������������
																	//��� �������� �������������� �� ������ � ���� �� ���������
		case 1:														
			cout << "�������� ������ ";
			cin >> searchS;											//���������� ���������
			searchResult = carBase->Search_title(searchS);			//����� � ������ �� ���������������� ����
			if (searchResult == 1)									//��������� ���������� ���������� ������
				cout << "�������, ���������� � �������� " << searchS << " �� �������." << endl;
			cout << "������� ������ ����� ���������.";					
			_getch();
			system("cls");
			break;
		case 2:
			cout << "����� ��, � ";
			cin >> searchF;
			searchResult = carBase->Search_engineVolume(searchF);
			if (searchResult == 1)
				cout << "�������, ������� ����� ��������� ��  " << searchF << " �. �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 3:
			cout << "�������� ��, �.�. ";
			cin >> searchI;
			searchResult = carBase->Search_enginePower(searchI);
			if (searchResult == 1)
				cout << "������, ������� �������� ��������� �� " << searchI << " �.�. �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 4:
			cout << "��� ��������� ";
			cin >> searchS;
			searchResult = carBase->Search_engineType(searchS);
			if (searchResult == 1)
				cout << "������� � ����� ����� ��������� �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 5:
			cout << "��� ������� ";
			cin >> searchS;
			searchResult = carBase->Search_transmission(searchS);
			if (searchResult == 1)
				cout << "������� � ����� ����� ������� �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 6:
			cout << "������ ";
			cin >> searchS;
			searchResult = carBase->Search_drive(searchS);
			if (searchResult == 1)
				cout << "������� � ����� �������� �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 7:
			cout << "���� ";
			cin >> searchS;
			searchResult = carBase->Search_color(searchS);
			if (searchResult == 1)
				cout << "������� ������ ����� �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 8:
			cout << "���� ��, ��� ";
			cin >> searchI;
			searchResult = carBase->Search_priceFrom(searchI);
			if (searchResult == 1)
				cout << "������� � ����� �� " << searchI << " ������ �� �������." << endl;
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 9:
			cout << "���� ��, ��� ";
			cin >> searchI;
			searchResult = carBase->Search_priceTo(searchI);
			if (searchResult == 1)
				cout << "������� � ����� �� " << searchI << " ������ �� �������." << endl;
			cout << "������� ������ ����� ���������.";
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

int carBaseMenu(carList* carBase)									//���� ��� �������������� � ����� �����������
{
	bool menuRunning;												//���� ����������� ������ ����
	int menuChoice;													//����� ������������ �� ������� ����
	menuRunning = true;
	while (menuRunning) {
		cout << "�������� ��������" << endl;						//������ ������� ����
		cout << "1. ������� ��� ������ � �������" << endl;
		cout << "2. ����� �� ��������" << endl;
		cout << "3. �����" << endl;
		do {
			cin >> menuChoice;										//���������� ������ ���� �� ����� �������� �������������� �����
		} while (menuChoice < 1 || menuChoice > 3);
		
		switch (menuChoice) {										//��������� ������ ������������
		case 1:														//1. ������� ��� ������ � �������
			carBase->consoleOutput();								//������ ���� ������� �� �������
			cout << "������� ������ ����� ���������.";
			_getch();
			system("cls");
			break;
		case 2:														//2. ����� �� ��������
			carSearch(carBase);										//����� ���� ��� ������ ������ �� ���������
			break;
		case 3:														//3. �����
			system("cls");
			menuRunning = false;									//����������� ������ ����
			break;
		}
	}
	return 0;
}

int managerBaseMenu(managerList* managerBase)						//���� ��� ������ � ����� ����������
{
	bool menuRunning;												//���� ����������� ������ ����
	string menuChoice;												//����� ������������ �� ������� ����
	string managerChoice;											//�� ��������� ��� ������
	Unit<Manager>* ptr;												//��������� �� ������� ������ ����������
	Unit<Unit<Car>*>* carPtr;										//��������� �� ��������� ������ ������� � �������� �������� ��������
	menuRunning = true;
	while (menuRunning) {											
		managerBase->consoleOutput();								//������ ������ ���������� �� �������
		do {
			cout << "�������� ������ ���������� ����������?   ��/���" << endl;
			cin >> menuChoice;										//���������� ������ ���� �� ����� �������� �������������� �����
			if (menuChoice == "��") {								//��������� ������ ������������ - ����� ���������� � ������� ���������
				cout << "������� ������� � ��� ���������� ���������: ";
				//cin >> managerChoice;
				_flushall();										
				getline(cin, managerChoice);
				getline(cin, managerChoice);						//���������� ������ ������������
				ptr = managerBase->Search_name(managerChoice);		//����� ��������� �� �����
				if (ptr == NULL) {									//��������� ������ �� ������� ����������
					cout << "�������� �� ������." << endl;			
					menuChoice = "  ";								//����� ���� �� ��� ���� ����
				}
				else {												//������ ��������������� ������
					system("cls");										
					managerBase->printElement(ptr);					
					carPtr = ptr->getData().getSalesList()->getHead(); //��������� ��������� �� ������ ���������� ������ ������
					do {												//���������������� ������ ���� ��������� ���������� ������
						cout << "������������: " << carPtr->getData()->getData().getTitile() << endl;
						cout << "�������� ���������:\n";
						cout << "\t�����:\t\t" << carPtr->getData()->getData().getEngineVolume() << " �." << endl;
						cout << "\t��������:\t" << carPtr->getData()->getData().getEnginePower() << " �.�." << endl;
						cout << "\t���:\t\t" << carPtr->getData()->getData().getEngineType() << endl;
						cout << "�������: " << carPtr->getData()->getData().getTransmission() << endl;
						cout << "������: " << carPtr->getData()->getData().getDrive() << endl;
						cout << "����: " << carPtr->getData()->getData().getColor() << endl;
						cout << "����: " << carPtr->getData()->getData().getPrice() << endl;
						cout << "-----------------------------------------------------------------\n\n";
						carPtr = carPtr->getNext();
					} while (carPtr != NULL);
					cout << "������� ������ ����� ���������.";
					_getch();
					system("cls");
				}
			}
			else if (menuChoice == "���") {
				menuRunning = false;								//������������ ������ ����
				cout << "������� ������ ����� ��������� � ������� ����.";
				_getch();
				system("cls");
			}
		} while (menuChoice != "��" && menuChoice != "���");
	}
	return 0;
}

int discountsMenu(discountList* discountBase, managerList* managerBase)		//���� ��� ������ �� ������� �����
{
	
	Unit<Discount>* ptr;											//��������� �� ������� ������ �����
	Unit<Car>* carPtr;												//��������� �� ������� ������ �����������
	Unit<Manager>* managerPtr;										//��������� �� ������� ������ ����������
	Unit<Unit<Car>*>* carListPtr;									//��������� �� ������� ���������� ������ �������
	int counter;													//������� �����
	int choice;														//��������� ����� �����
	string menuChoice;												//����� ������ ����
	bool menuRunning = true;	
	bool stop;
	int newPrice;													//���� � ������ ������
	int price;														//������� ����
	float off;														//������
	cout << "\t\t\t\t����������� �����" << "\n\n\n";
	while (menuRunning) {
		counter = 1;
		ptr = discountBase->getHead();
		do {														//������ ���� ����� � ������ �� ����������� ������ � ��������� ����
			discountBase->printElement(ptr, counter);				
			cout << endl;
			ptr = ptr->getNext();
			counter++;
		} while (ptr != NULL);
		cout << "������ �������� ��������� ���������� �� �����?    ��/���" << endl;
		do {
			cin >> menuChoice;										//���������� ������ ������������
			if (menuChoice == "��") {								//��������� ������
				cout << "������� ����� �����: ";
				do {
					cin >> choice;									//���������� ������ ���� �� ����� �������� �������������� �����
				} while (choice < 1 || choice > counter);
				ptr = discountBase->getHead();						//��������� �� ������� ������ ����� ���������� ��������� �� ������ ������
				for (int i = 0; i < choice - 1; i++)				
					ptr = ptr->getNext();							//��������� ��������� �� ������ ���� �� ������ �� ��������, ���������� ����� �������� ��������� � ��������� ������������� �������
				if (ptr != NULL) {									//�������������� �������� ������� ���������� ������
					carPtr = ptr->getData().getRelatedCar();		//������ ���������� �� ����� � ��������������� ������ ����������
					price = carPtr->getData().getPrice();
					off = ptr->getData().getOffAmount();
					off = off / 100;
					cout << "������: " << endl;
					cout << "������������: " << carPtr->getData().getTitile() << endl;
					cout << "�������� ���������:\n";
					cout << "\t�����:\t\t" << carPtr->getData().getEngineVolume() << " �." << endl;
					cout << "\t��������:\t" << carPtr->getData().getEnginePower() << " �.�." << endl;
					cout << "\t���:\t\t" << carPtr->getData().getEngineType() << endl;
					cout << "�������: " << carPtr->getData().getTransmission() << endl;
					cout << "������: " << carPtr->getData().getDrive() << endl;
					cout << "����: " << carPtr->getData().getColor() << endl;
					cout << "����: " << price;
					price = price - (price * off);
					cout << " => " << price;
					cout << "  (" << ptr->getData().getOffAmount() << "% OFF!)" << endl;
					cout << "��������� �� " << ptr->getData().getEndDate() << "!" << endl << endl;
					cout << "���������, ���������� � ���� �������:\n";
					managerPtr = managerBase->getHead();
					do {																		//����� ���� ���������� ���������� � ������ �������
						carListPtr = managerPtr->getData().getSalesList()->getHead();			//��������� �� ������ ���������� ������ ����������
						stop = false;
						do {																	//�������� ������� �������� ���������� ������
							if (carListPtr->getData() == ptr->getData().getRelatedCar()) {		//���� ��������� �� ������� ������ ���������� � ������
								managerBase->printElement(managerPtr);							//������ ������ � ��������� �� �������
								stop = true;													//��������� ������ � ������
							}
							carListPtr = carListPtr->getNext();
						} while (carListPtr != NULL && !stop);
						managerPtr = managerPtr->getNext();										//������� � ���������� ��������� � ������
					} while (managerPtr != NULL);
				}
				else cout << "�������� �������������� ��������. ��������� ������� �����.\n";	//��������� ���������� ������ ����� �� ������, ��� �������� �������������� ����������� ���������, ��� ��� �������� ������ ������������ ������������ ��� �� ������ �����
				cout << "������� ������ ����� ���������.";
				_getch();
				system("cls");
			}
			else if (menuChoice == "���") {
				menuRunning = false;															//����������� ������ ����
				cout << "������� ������ ����� ��������� � ������� ����.";
				_getch();
				system("cls");
			}
		} while (menuChoice != "��" && menuChoice != "���");
	}
	return 0;
}
