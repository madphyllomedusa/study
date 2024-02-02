#include "Functions.h"
#define CARS "cars.txt"					//���� � ������ � �������			
#define MANAGERS "managers.txt"
#define DISCOUNTS "discounts.txt"


int main() {
	SetConsoleCP(1251);											//������������� ��������� ����� �� ������� � �� ��������� ���
	SetConsoleOutputCP(1251);									//������������� ��������� ������ �� �������
	bool menuRunning;											//���� ����������� ������ �������� ����								
	int mainMenuChoice;											//�������� ������������� �����
	carList* carBase = new carList;								//��������� ������ ��� ������ �����������
	managerList* managerBase = new managerList;					//��������� ������ ��� ������ ����������
	discountList* discountBase = new discountList;				//��������� ������ ��� ������ ������
	carBase->inputFromFile(CARS);								//���������� ������ ����������� ������� �� �����
	managerBase->inputFromFile(MANAGERS, carBase);				//���������� ������ ���������� ������� �� �����
	discountBase->inputFromFile(DISCOUNTS, carBase);			//���������� ������ ������ ������� �� �����
	menuRunning = true;
	
	while (menuRunning) {											
		cout << "�������� ��������" << endl;					//������ �������� ����
		cout << "1. ���������� ���������� � �������" << endl;
		cout << "2. ������� ������ ����������" << endl;
		cout << "3. �������� ����������� ������" << endl;
		cout << "4. �����" << endl;
		do {
			
			cin >> mainMenuChoice;								//���������� ������ ������������ ���� �� ����� �������� �������������� �����
		} while (mainMenuChoice < 1 || mainMenuChoice > 4);
		
		switch (mainMenuChoice) {								//��������� ������ ������������						
		case 1:													//1. ���������� ���������� � �������
			system("cls");	
			carBaseMenu(carBase);								//����� ���� ��� ������ � ����� �����������
			break;
		case 2:													//2. ������� ������ ����������
			system("cls");
			managerBaseMenu(managerBase);						//����� ���� ��� ������ � ����� ����������
			break;
		case 3:													//3. �������� ����������� ������
			system("cls");
			discountsMenu(discountBase, managerBase);			//����� ���� ��� ������ � ����� ������
			break;
		case 4:													//4. �����
			menuRunning = false;								//��������� ������ ����
			break;
		default:
			break;
		}
	}

	return 0;
}