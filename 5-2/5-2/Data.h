#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

//Для хранения информации в программе использвуется односвязный список. 
//Реализован список с помошью двух шаблонных классов: Unit - единичный элемент списка, хранящий информацию, и List - хранит ключевую информацию для пользования списком и его методы

template <class T>
class Unit {					//Класс Unit - единичный элемент списка.
	T data;						//Поле, содержащее полезную информацию
	Unit* next;					//Указатель на следующий элемент списка
public:
	//конструктор по умолчанию, создает пустой элемент
	Unit() {
		this->data = 0;
		this->next = NULL;
	}
	//конструктор с параметром, создающий элемент сразу с определенным значением поля data 
	Unit(T value) {

		this->data = value;
		this->next = NULL;
	}

	~Unit() {

	}
	//геттеры
	T getData() { return data; };
	Unit* getNext() { return next; };
	//сеттеры
	void setNext(Unit* value) { this->next = value; }
	void setData(T value) { this->data = value; }
};

template <class T>
class List {					//Класс List - интерфейс списка составленного из элементов Unit
	Unit<T>* head;				//Указатель на голову списка
	Unit<T>* tail;				//Указатель на хвост списка
	int size;					//Кол-во элементов в списке
public:
	//Конструктор по умолчанию
	List() {
		this->head = NULL;
		this->tail = NULL;
		size = 0;
	}
	//Для правильного очищения задействованной дмнамической памяти деструктор списка вызывает метод clear() - последовательно уничтожает элементы списка
	~List() {
		clear();
	};
	
	//сеттеры
	void setHead(Unit<T>* value) { this->head = value; };
	
	//геттеры
	Unit<T>* getHead() { return head; }
	Unit<T>* getTail() { return tail; }
	int getSize() { return size; }
	
	//методы класса List
	bool is_empty() { return head == NULL;}				//Проверка на наличие элементов в списке	
	void push_back(T value);							//Метод добаления нового элемента в конец списка
	void pop_front();									//Метод удаления элемента из начала списка
	void pop_back();									//Метод удаления элемента из конца списка
	void clear();										//Метод очистки и удаления списка
	Unit<T>* searchID(string value);					//Метод поиска по полю id в списе. Реализован в шаблонном классе, но может использоваться
														//только при наличии соответствующего поля в структуре данных
};


											
class Car {												//Класс Car - структура хранения информации об автомобиле
	string id;											//Уникальный номер элемента в базе
	string title;										//Название модели
	string EngineVolume;								//Объем двигателя, л
	int EnginePower;									//Мощность, л/с
	string EngineType;									//Тип двигателя
	string transmission;								//Тип коробки
	string drive;										//Тип привода
	string color;										//Цвет
	int price;											//Цена, руб
public:
	//сеттеры
	void setID(string value) { this->id = value; };
	void setTitle(string value) { this->title = value; };
	void setEngineVolume(string value) { this->EngineVolume = value; };
	void setEnginePower(int value) { this->EnginePower = value; };
	void setEngineType(string value) { this->EngineType = value; };
	void setTransmission(string value) { this->transmission = value; };
	void setDrive(string value) { this->drive = value; };
	void setColor(string value) { this->color = value; };
	void setPrice(int value) { this->price = value; };
	//геттеры
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



class Manager {											//Класс Manager - структура хранения информации о менеджере
	string id;											//Уникальный номер в базе
	string name;										//Имя и фамилия
	string number;										//Номер телефона
	List<Unit<Car>*>* salesList;						//Список моделей с которыми работает менеджер
														//Список моделей хранится в виде списка указателей на элементы списка автомобилей
														//Что при гипотетическом удалении модели из списка автомобилей удалит ее так же из всех списков менеджеров
public:
	//сеттеры
	void setID(string value) { this->id = value; };
	void setName(string value) { this->name = value; };
	void setNumber(string value) { this->number = value; };
	void setSalesList(List<Unit<Car>*>* value) { this->salesList = value; };

	//геттеры
	string getName() { return this->name; };
	string getNumber() { return this->number; };
	string getID() { return this->id; }
	List<Unit<Car>*>* getSalesList() { return this->salesList; };
};

class Discount {										//Класс Discount - структура хранения информации об акции
	Unit<Car>* relatedCar;								//Указатель на модель в списке автомобилей, на которую действует акция
	int offAmount;										//Размер скидки, %
	string endDate;										//Дата окончания действия скидки
public:
	//сеттеры
	void setRelatedCar(Unit<Car>* value) { this->relatedCar = value; };
	void setOffAmount(int value) { this->offAmount = value; };
	void setEndDate(string value) { this->endDate = value; };

	//геттеры
	Unit<Car>* getRelatedCar() { return this->relatedCar; };
	int getOffAmount() { return this->offAmount; };
	string getEndDate() { return this->endDate; };
};

class carList : public List<Car> {						//Класс carList - список для хранения информации о представленных автомобилях
														//Наследует интерфейс контейнера List и добавляет новые методы работы с типом данных Car
public:
	//Реализация методов вынесена в файл Data.cpp
	int inputFromFile(string path);						//Метод заполнения списка информацией из файла по указанному пути
	int consoleOutput();								//Метод вывода списка на консоль, форматирует данные в таблицу
	//int outputToFile(string path);					
	//int outputToConfigFile(string path);
	int printElement(Unit<Car>* ptr);					//Метод вывода на консоль элемента по переданному указателю
	
	//Методы поиска эллемента по определенной переменной, Search_названиеПеременной
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

class managerList : public List<Manager> {				//Класс managerList - список для хранения информации о менеджерах
														//Наследует интерфейс контейнера List и добавляет новые методы работы с типом данных Manager
public:
	//Реализация методов вынесена в файл Data.cpp
	int inputFromFile(string path, carList* carBase);	//Метод заполнения списка информацией из файла по указанному пути
	int consoleOutput();								//Метод вывода списка на консоль, форматирует данные в таблицу
	//int outputToFile(string path);
	//int outputToConfigFile(string path);
	int printElement(Unit<Manager>* ptr);				//Метод вывода на консоль элемента по переданному указателю
	
	//Методы поиска эллемента по определенной переменной, Search_названиеПеременной
	Unit<Manager>* Search_name(string value);
};

class discountList : public List<Discount> {			//Класс discountList - список для хранения информации о действующих скидках
														//Наследует интерфейс контейнера List и добавляет новые методы работы с типом данных Discount
public:
	//Реализация методов вынесена в файл Data.cpp
	int inputFromFile(string path, carList* carBase);	//Метод заполнения списка информацией из файла по указанному пути
	int printElement(Unit<Discount>* ptr, int position);//Метод вывода на консоль элемента по переданному указателю. Как параметр так же передается место акции в меню акции
};

template<class T>
void List<T>::push_back(T value)						//Реализация шаблонного метода push_back - добавление нового элемента в конец списка
{
	Unit<T>* newUnit = new Unit<T>(value);				//Создание нового элемента списка с заданными данными
	//Установка связей между элементами 
	if (is_empty())										
		this->head = this->tail = newUnit;
	else {
			this->tail->setNext(newUnit);
			this->tail = newUnit;
	}
	this->size++;
}

template<class T>
void List<T>::pop_front()								//Реализация шаблонного метода pop_front - удаление элемента из начала списка
{
	if (is_empty())
		cout << "list is empty\n";
	else {
		Unit<T>* temp;									
		temp = this->head;								//Сохраняется указатель на голову списка
		this->head = this->head->getNext();				//Голова смещается на следующий элемента
		delete temp;									//Бывашя голова удаляется по сохраненному указателю
		temp = nullptr;
		size--;
	}
}

template<class T>
void List<T>::pop_back()								//Реализация шаблонного метода pop_back - удаление элемента с конца списка
{
	if (is_empty())
		cout << "list is empty\n";
	else {
		Unit<T>* temp;									
		temp = this->head;
		while (temp->getNext() != tail)					//Так как список является односвязным, невозможно получить доступ от последнего элемента к предыдущему
			temp = temp->getNext();						//Указатель смещается по списку пока не дойдет до предпоследнего
		this->tail = temp;								//Хвост списка семщается на предпомследний элемент
		temp = temp->getNext();							
		tail->setNext(NULL);							//Разрывается связь между последним и предпосленим элементом списка
		delete temp;									//Последний элемент списка удаляется
		temp = nullptr;
		size--;
	}
}

template<class T>
void List<T>::clear()									//Реализация шаблонного метода clear - последовательное удаление всех элементов списка начиная с первого
{														//Используется в деструкторе класс List	
	while (!this->is_empty())
		this->pop_front();
}

template<class T>
Unit<T>* List<T>::searchID(string value)				//Метод поиска в списке по полю id. 			
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
