#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

//��� �������� ���������� � ��������� ������������� ����������� ������. 
//���������� ������ � ������� ���� ��������� �������: Unit - ��������� ������� ������, �������� ����������, � List - ������ �������� ���������� ��� ����������� ������� � ��� ������

template <class T>
class Unit {					//����� Unit - ��������� ������� ������.
	T data;						//����, ���������� �������� ����������
	Unit* next;					//��������� �� ��������� ������� ������
public:
	//����������� �� ���������, ������� ������ �������
	Unit() {
		this->data = 0;
		this->next = NULL;
	}
	//����������� � ����������, ��������� ������� ����� � ������������ ��������� ���� data 
	Unit(T value) {

		this->data = value;
		this->next = NULL;
	}

	~Unit() {

	}
	//�������
	T getData() { return data; };
	Unit* getNext() { return next; };
	//�������
	void setNext(Unit* value) { this->next = value; }
	void setData(T value) { this->data = value; }
};

template <class T>
class List {					//����� List - ��������� ������ ������������� �� ��������� Unit
	Unit<T>* head;				//��������� �� ������ ������
	Unit<T>* tail;				//��������� �� ����� ������
	int size;					//���-�� ��������� � ������
public:
	//����������� �� ���������
	List() {
		this->head = NULL;
		this->tail = NULL;
		size = 0;
	}
	//��� ����������� �������� ��������������� ������������ ������ ���������� ������ �������� ����� clear() - ��������������� ���������� �������� ������
	~List() {
		clear();
	};
	
	//�������
	void setHead(Unit<T>* value) { this->head = value; };
	
	//�������
	Unit<T>* getHead() { return head; }
	Unit<T>* getTail() { return tail; }
	int getSize() { return size; }
	
	//������ ������ List
	bool is_empty() { return head == NULL;}				//�������� �� ������� ��������� � ������	
	void push_back(T value);							//����� ��������� ������ �������� � ����� ������
	void pop_front();									//����� �������� �������� �� ������ ������
	void pop_back();									//����� �������� �������� �� ����� ������
	void clear();										//����� ������� � �������� ������
	Unit<T>* searchID(string value);					//����� ������ �� ���� id � �����. ���������� � ��������� ������, �� ����� ��������������
														//������ ��� ������� ���������������� ���� � ��������� ������
};


											
class Car {												//����� Car - ��������� �������� ���������� �� ����������
	string id;											//���������� ����� �������� � ����
	string title;										//�������� ������
	string EngineVolume;								//����� ���������, �
	int EnginePower;									//��������, �/�
	string EngineType;									//��� ���������
	string transmission;								//��� �������
	string drive;										//��� �������
	string color;										//����
	int price;											//����, ���
public:
	//�������
	void setID(string value) { this->id = value; };
	void setTitle(string value) { this->title = value; };
	void setEngineVolume(string value) { this->EngineVolume = value; };
	void setEnginePower(int value) { this->EnginePower = value; };
	void setEngineType(string value) { this->EngineType = value; };
	void setTransmission(string value) { this->transmission = value; };
	void setDrive(string value) { this->drive = value; };
	void setColor(string value) { this->color = value; };
	void setPrice(int value) { this->price = value; };
	//�������
	string getTitile() { return this->title; };
	string getEngineVolume() { return this->EngineVolume; };
	int getEnginePower() { return this->EnginePower; };
	string getEngineType() { return this->EngineType; };
	string getTransmission() { return this->transmission; };
	string getDrive() { return this->drive; };
	string getColor() { return this->color; };
	int getPrice() { return this->price; };
	string getID() { return this->id; }
};



class Manager {											//����� Manager - ��������� �������� ���������� � ���������
	string id;											//���������� ����� � ����
	string name;										//��� � �������
	string number;										//����� ��������
	List<Unit<Car>*>* salesList;						//������ ������� � �������� �������� ��������
														//������ ������� �������� � ���� ������ ���������� �� �������� ������ �����������
														//��� ��� �������������� �������� ������ �� ������ ����������� ������ �� ��� �� �� ���� ������� ����������
public:
	//�������
	void setID(string value) { this->id = value; };
	void setName(string value) { this->name = value; };
	void setNumber(string value) { this->number = value; };
	void setSalesList(List<Unit<Car>*>* value) { this->salesList = value; };

	//�������
	string getName() { return this->name; };
	string getNumber() { return this->number; };
	string getID() { return this->id; }
	List<Unit<Car>*>* getSalesList() { return this->salesList; };
};

class Discount {										//����� Discount - ��������� �������� ���������� �� �����
	Unit<Car>* relatedCar;								//��������� �� ������ � ������ �����������, �� ������� ��������� �����
	int offAmount;										//������ ������, %
	string endDate;										//���� ��������� �������� ������
public:
	//�������
	void setRelatedCar(Unit<Car>* value) { this->relatedCar = value; };
	void setOffAmount(int value) { this->offAmount = value; };
	void setEndDate(string value) { this->endDate = value; };

	//�������
	Unit<Car>* getRelatedCar() { return this->relatedCar; };
	int getOffAmount() { return this->offAmount; };
	string getEndDate() { return this->endDate; };
};

class carList : public List<Car> {						//����� carList - ������ ��� �������� ���������� � �������������� �����������
														//��������� ��������� ���������� List � ��������� ����� ������ ������ � ����� ������ Car
public:
	//���������� ������� �������� � ���� Data.cpp
	int inputFromFile(string path);						//����� ���������� ������ ����������� �� ����� �� ���������� ����
	int consoleOutput();								//����� ������ ������ �� �������, ����������� ������ � �������
	//int outputToFile(string path);					
	//int outputToConfigFile(string path);
	int printElement(Unit<Car>* ptr);					//����� ������ �� ������� �������� �� ����������� ���������
	
	//������ ������ ��������� �� ������������ ����������, Search_������������������
	int Search_title(string value);					
	int Search_engineVolume(float value);
	int Search_enginePower(int value);
	int Search_engineType(string value);
	int Search_transmission(string value);
	int Search_drive(string value);
	int Search_color(string value);
	int Search_priceFrom(int value);
	int Search_priceTo(int value);
};

class managerList : public List<Manager> {				//����� managerList - ������ ��� �������� ���������� � ����������
														//��������� ��������� ���������� List � ��������� ����� ������ ������ � ����� ������ Manager
public:
	//���������� ������� �������� � ���� Data.cpp
	int inputFromFile(string path, carList* carBase);	//����� ���������� ������ ����������� �� ����� �� ���������� ����
	int consoleOutput();								//����� ������ ������ �� �������, ����������� ������ � �������
	//int outputToFile(string path);
	//int outputToConfigFile(string path);
	int printElement(Unit<Manager>* ptr);				//����� ������ �� ������� �������� �� ����������� ���������
	
	//������ ������ ��������� �� ������������ ����������, Search_������������������
	Unit<Manager>* Search_name(string value);
};

class discountList : public List<Discount> {			//����� discountList - ������ ��� �������� ���������� � ����������� �������
														//��������� ��������� ���������� List � ��������� ����� ������ ������ � ����� ������ Discount
public:
	//���������� ������� �������� � ���� Data.cpp
	int inputFromFile(string path, carList* carBase);	//����� ���������� ������ ����������� �� ����� �� ���������� ����
	int printElement(Unit<Discount>* ptr, int position);//����� ������ �� ������� �������� �� ����������� ���������. ��� �������� ��� �� ���������� ����� ����� � ���� �����
};

template<class T>
void List<T>::push_back(T value)						//���������� ���������� ������ push_back - ���������� ������ �������� � ����� ������
{
	Unit<T>* newUnit = new Unit<T>(value);				//�������� ������ �������� ������ � ��������� �������
	//��������� ������ ����� ���������� 
	if (is_empty())										
		this->head = this->tail = newUnit;
	else {
			this->tail->setNext(newUnit);
			this->tail = newUnit;
	}
	this->size++;
}

template<class T>
void List<T>::pop_front()								//���������� ���������� ������ pop_front - �������� �������� �� ������ ������
{
	if (is_empty())
		cout << "list is empty\n";
	else {
		Unit<T>* temp;									
		temp = this->head;								//����������� ��������� �� ������ ������
		this->head = this->head->getNext();				//������ ��������� �� ��������� ��������
		delete temp;									//������ ������ ��������� �� ������������ ���������
		temp = nullptr;
		size--;
	}
}

template<class T>
void List<T>::pop_back()								//���������� ���������� ������ pop_back - �������� �������� � ����� ������
{
	if (is_empty())
		cout << "list is empty\n";
	else {
		Unit<T>* temp;									
		temp = this->head;
		while (temp->getNext() != tail)					//��� ��� ������ �������� �����������, ���������� �������� ������ �� ���������� �������� � �����������
			temp = temp->getNext();						//��������� ��������� �� ������ ���� �� ������ �� ��������������
		this->tail = temp;								//����� ������ ��������� �� �������������� �������
		temp = temp->getNext();							
		tail->setNext(NULL);							//����������� ����� ����� ��������� � ������������ ��������� ������
		delete temp;									//��������� ������� ������ ���������
		temp = nullptr;
		size--;
	}
}

template<class T>
void List<T>::clear()									//���������� ���������� ������ clear - ���������������� �������� ���� ��������� ������ ������� � �������
{														//������������ � ����������� ����� List	
	while (!this->is_empty())
		this->pop_front();
}

template<class T>
Unit<T>* List<T>::searchID(string value)				//����� ������ � ������ �� ���� id. 			
{
	Unit<T>* ptr;
	ptr = head;
	while (ptr->getData().getID() != value && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	if (ptr->getData().getID() != value && ptr->getNext() == NULL) {
		cout << "search of " << value << " element failed. Check corresponding database file.\n";
			return NULL;
	}
	else return ptr;
}
