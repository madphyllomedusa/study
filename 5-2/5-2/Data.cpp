#include "Data.h"

int carList::inputFromFile(string path)							//Метод заполнения списка из файла
{	
	Car value;													//Данные, добавляемые в список
	ifstream fin;												//Объект fstream для считывания данных из файла
	string tempString;
	fin.open(path);												//Открытие файла по указаному пути
	if (!fin.is_open())											//Проверка открытия файла
		return 1;
	else {
		while (!fin.eof()) {									//Последовательное считывание всех данных из файла
			getline(fin, tempString);							//Строка из файла сохраняется в переменную tempString
			value.setID(tempString);							//Через которую данные переносятся в объект, хранящий данные о модели
			getline(fin, tempString);
			value.setTitle(tempString);
			getline(fin, tempString);
			value.setEngineVolume(tempString);
			getline(fin, tempString);
			value.setEnginePower(stoi(tempString));
			getline(fin, tempString);
			value.setEngineType(tempString);
			getline(fin, tempString);
			value.setTransmission(tempString);
			getline(fin, tempString);
			value.setDrive(tempString);
			getline(fin, tempString);
			value.setColor(tempString);
			getline(fin, tempString);
			value.setPrice(stoi(tempString));
			this->push_back(value);								//Когда все данные о модели были считаны в список добавляется элемент с соответствующими значениями
		}
	}
	fin.close();
	return 0;
}

int carList::consoleOutput()									//Печать списка на консоль
{
	Unit<Car>* ptr = this->getHead();							//Для каждого элемента списка начиная от головы вызывается метод печати элемента на консоль
	do {
		this->printElement(ptr);
		ptr = ptr->getNext();
	} while (ptr != NULL);
	return 0;
}


int carList::printElement(Unit<Car>* ptr)					//Печать элемента списка на консоль 						
{
	cout << "Наименование: " << ptr->getData().getTitile() << endl;
	cout << "Свойства двигателя:\n";
	cout << "\tОбъем:\t\t" << ptr->getData().getEngineVolume() << " л." << endl;
	cout << "\tМощность:\t" << ptr->getData().getEnginePower() << " л.с." << endl;
	cout << "\tТип:\t\t" << ptr->getData().getEngineType() << endl;
	cout << "Коробка: " << ptr->getData().getTransmission() << endl;
	cout << "Привод: " << ptr->getData().getDrive() << endl;
	cout << "Цвет: " << ptr->getData().getColor() << endl;
	cout << "Цена: " << ptr->getData().getPrice() << endl;
	cout << "-----------------------------------------------------------------\n\n";
	return 0;
}

int carList::Search_title(string value)						//Печать всех моделей из списка, в название которых входит заданная строка
{
	bool result;											
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getTitile().find(value) != -1) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_engineVolume(float value)				//Печать всех моделей из списка, которые имеют заданный объем двигателя
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (atof(ptr->getData().getEngineVolume().c_str()) >= value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_enginePower(int value)				//Печать всех моделей из списка, которые имеют заданную мощность двигателя
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getEnginePower() >= value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_engineType(string value)			//Печать всех моделей из списка, которые имеют заданный тип двигателя
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getEngineType() == value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_transmission(string value)			//Печать всех моделей из списка, которые имеют заданный тип коробки
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getTransmission() == value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_drive(string value)					//Печать всех моделей из списка, которые имеют заданный тип привода
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getDrive() == value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_color(string value)					//Печать всех моделей из списка, имеющих заданный цвет
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getColor() == value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_priceFrom(int value)			//Печать всех моделей из списка, имеющих цену выше заданной
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getPrice() >= value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int carList::Search_priceTo(int value)				//Печать всех моделей из списка, имеющих цену ниже заданной
{
	bool result;
	Unit<Car>* ptr;
	ptr = this->getHead();
	result = false;
	do {
		if (ptr->getData().getPrice() <= value) {
			result = true;
			this->printElement(ptr);
		}
		ptr = ptr->getNext();
	} while (ptr != NULL);
	if (!result)
		return 1;
	return 0;
}

int managerList::inputFromFile(string path, carList* carBase)			//Заполнение списка менеджеров данными из файла
{
	Manager value;														//Данные, добавляемые в список
	List<Unit<Car>*>* tempList;											//Список указателей на элементы списка автомобилей
	Unit<Car>* carPtr;													//Указатель на элемент списка автомобилей
	int pos;
	string tempString;
	string idList;														//Строка с номерами моделей с которыми работает менеджер
	string fhalf;														//Отделяемый номер из строки													
	ifstream fin;														//Объект fstream для считывания данных из файла
	fin.open(path);														//Открытие файла
	if (!fin.is_open())													
		return 1;
	else {
		while (!fin.eof()) {
			tempList = new List<Unit<Car>*>;							//Создание нового списка указателей
			value.setSalesList(tempList);								
			getline(fin, tempString);									//Последовательное считывание данных из файла в вспомогательную переменную
			value.setID(tempString);									//Через которые данные переносятся в объект, хранящий данные о менеджере 
			getline(fin, tempString);
			value.setName(tempString);
			getline(fin, tempString);
			value.setNumber(tempString);
			getline(fin, idList);										
			do {														//Обработка строки-списка номеров моделей
				pos = idList.find(" ");									//Определение позиции первого пробела в строке
				fhalf = idList.substr(0, pos);							//Отделение числа до пробела от остальной строки
				idList = idList.substr(pos + 1, idList.length());		//Отделение числа до пробела от остальной строки
				carPtr = carBase->searchID(fhalf);						//Поиск в списке модели с указанным номером
				if (carPtr != NULL)										
					value.getSalesList()->push_back(carPtr);			//Добавление элемента в список указателей
			} while (idList.find(" ") != -1);							//Процесс повторяется пока в строке остаются пробелы
			carPtr = carBase->searchID(idList);							//Поиск последней оставшейся модели
			if (carPtr != NULL)
				value.getSalesList()->push_back(carPtr);				//Добавление элемента в список указателей 
			this->push_back(value);										//Добавление элемента в список менеджеров
		}
	}
	fin.close();
	return 0;
}

int managerList::consoleOutput()					//Печать списка менеджеров на консоль
{
	Unit<Manager>* ptr;
	//Unit<Unit<Car>*>* carPtr;
	ptr = this->getHead();
	do {
		this->printElement(ptr);					//Для каждого элемента начиная с головы вызывается метод печати элемента
		//carPtr = ptr->getData().getSalesList()->getHead();
		/*do {
			cout << carPtr->getData()->getData().getID() << "\t";
			carPtr = carPtr->getNext();
		} while (carPtr != NULL);*/
		cout << endl;
		ptr = ptr->getNext();
	} while (ptr != NULL);
	return 0;
}


int managerList::printElement(Unit<Manager>* ptr)			//Печать элемента списка менеджеров на консоль
{
	cout << ptr->getData().getName() << endl;
	cout << ptr->getData().getNumber() << endl;
	return 0;
}

Unit<Manager>* managerList::Search_name(string value)		//Поиск менеджера по имени
{
	Unit<Manager>* ptr;
	ptr = this->getHead();
	
	do {
		if (ptr->getData().getName() == value)
			return ptr;
		ptr = ptr->getNext();
	} while (ptr != NULL);
	return ptr;
	
}

int discountList::inputFromFile(string path, carList* carBase)		//Заполнение списка скидок данными из файла.
{																	//Принцип работы совпадает с одноименным методом списка автомобилей
	Discount value;
	ifstream fin;
	string temp;
	fin.open(path);
	if (!fin.is_open())
		return 1;
	while (!fin.eof()) {
		getline(fin, temp);
		value.setRelatedCar(carBase->searchID(temp));
		getline(fin, temp);
		value.setOffAmount(stoi(temp));
		getline(fin, temp);
		value.setEndDate(temp);
		this->push_back(value);
	}
	return 0;
}

int discountList::printElement(Unit<Discount>* ptr, int position)			//Печать информации об акции на консоль
{
	float off;
	int price;
	cout << position << ".\t----------------------------------" << endl;
	cout << ptr->getData().getRelatedCar()->getData().getTitile() << endl;
	cout << "Цена: " << ptr->getData().getRelatedCar()->getData().getPrice() << " => ";
	price = ptr->getData().getRelatedCar()->getData().getPrice();
	off = ptr->getData().getOffAmount();
	off = off / 100;
	price = price - (price * off);
	cout << (price);
	cout << "  (" << ptr->getData().getOffAmount() << "% OFF!)" << endl;
	cout << "ДЕЙСТВУЕТ ДО " << ptr->getData().getEndDate() << "!" << endl;
	cout << "\t----------------------------------" << endl;
	return 0;
}
