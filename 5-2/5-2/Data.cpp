#include "Data.h"

int carList::inputFromFile(string path)							//����� ���������� ������ �� �����
{	
	Car value;													//������, ����������� � ������
	ifstream fin;												//������ fstream ��� ���������� ������ �� �����
	string tempString;
	fin.open(path);												//�������� ����� �� ��������� ����
	if (!fin.is_open())											//�������� �������� �����
		return 1;
	else {
		while (!fin.eof()) {									//���������������� ���������� ���� ������ �� �����
			getline(fin, tempString);							//������ �� ����� ����������� � ���������� tempString
			value.setID(tempString);							//����� ������� ������ ����������� � ������, �������� ������ � ������
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
			this->push_back(value);								//����� ��� ������ � ������ ���� ������� � ������ ����������� ������� � ���������������� ����������
		}
	}
	fin.close();
	return 0;
}

int carList::consoleOutput()									//������ ������ �� �������
{
	Unit<Car>* ptr = this->getHead();							//��� ������� �������� ������ ������� �� ������ ���������� ����� ������ �������� �� �������
	do {
		this->printElement(ptr);
		ptr = ptr->getNext();
	} while (ptr != NULL);
	return 0;
}


int carList::printElement(Unit<Car>* ptr)					//������ �������� ������ �� ������� 						
{
	cout << "������������: " << ptr->getData().getTitile() << endl;
	cout << "�������� ���������:\n";
	cout << "\t�����:\t\t" << ptr->getData().getEngineVolume() << " �." << endl;
	cout << "\t��������:\t" << ptr->getData().getEnginePower() << " �.�." << endl;
	cout << "\t���:\t\t" << ptr->getData().getEngineType() << endl;
	cout << "�������: " << ptr->getData().getTransmission() << endl;
	cout << "������: " << ptr->getData().getDrive() << endl;
	cout << "����: " << ptr->getData().getColor() << endl;
	cout << "����: " << ptr->getData().getPrice() << endl;
	cout << "-----------------------------------------------------------------\n\n";
	return 0;
}

int carList::Search_title(string value)						//������ ���� ������� �� ������, � �������� ������� ������ �������� ������
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

int carList::Search_engineVolume(float value)				//������ ���� ������� �� ������, ������� ����� �������� ����� ���������
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

int carList::Search_enginePower(int value)				//������ ���� ������� �� ������, ������� ����� �������� �������� ���������
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

int carList::Search_engineType(string value)			//������ ���� ������� �� ������, ������� ����� �������� ��� ���������
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

int carList::Search_transmission(string value)			//������ ���� ������� �� ������, ������� ����� �������� ��� �������
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

int carList::Search_drive(string value)					//������ ���� ������� �� ������, ������� ����� �������� ��� �������
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

int carList::Search_color(string value)					//������ ���� ������� �� ������, ������� �������� ����
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

int carList::Search_priceFrom(int value)			//������ ���� ������� �� ������, ������� ���� ���� ��������
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

int carList::Search_priceTo(int value)				//������ ���� ������� �� ������, ������� ���� ���� ��������
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

int managerList::inputFromFile(string path, carList* carBase)			//���������� ������ ���������� ������� �� �����
{
	Manager value;														//������, ����������� � ������
	List<Unit<Car>*>* tempList;											//������ ���������� �� �������� ������ �����������
	Unit<Car>* carPtr;													//��������� �� ������� ������ �����������
	int pos;
	string tempString;
	string idList;														//������ � �������� ������� � �������� �������� ��������
	string fhalf;														//���������� ����� �� ������													
	ifstream fin;														//������ fstream ��� ���������� ������ �� �����
	fin.open(path);														//�������� �����
	if (!fin.is_open())													
		return 1;
	else {
		while (!fin.eof()) {
			tempList = new List<Unit<Car>*>;							//�������� ������ ������ ����������
			value.setSalesList(tempList);								
			getline(fin, tempString);									//���������������� ���������� ������ �� ����� � ��������������� ����������
			value.setID(tempString);									//����� ������� ������ ����������� � ������, �������� ������ � ��������� 
			getline(fin, tempString);
			value.setName(tempString);
			getline(fin, tempString);
			value.setNumber(tempString);
			getline(fin, idList);										
			do {														//��������� ������-������ ������� �������
				pos = idList.find(" ");									//����������� ������� ������� ������� � ������
				fhalf = idList.substr(0, pos);							//��������� ����� �� ������� �� ��������� ������
				idList = idList.substr(pos + 1, idList.length());		//��������� ����� �� ������� �� ��������� ������
				carPtr = carBase->searchID(fhalf);						//����� � ������ ������ � ��������� �������
				if (carPtr != NULL)										
					value.getSalesList()->push_back(carPtr);			//���������� �������� � ������ ����������
			} while (idList.find(" ") != -1);							//������� ����������� ���� � ������ �������� �������
			carPtr = carBase->searchID(idList);							//����� ��������� ���������� ������
			if (carPtr != NULL)
				value.getSalesList()->push_back(carPtr);				//���������� �������� � ������ ���������� 
			this->push_back(value);										//���������� �������� � ������ ����������
		}
	}
	fin.close();
	return 0;
}

int managerList::consoleOutput()					//������ ������ ���������� �� �������
{
	Unit<Manager>* ptr;
	//Unit<Unit<Car>*>* carPtr;
	ptr = this->getHead();
	do {
		this->printElement(ptr);					//��� ������� �������� ������� � ������ ���������� ����� ������ ��������
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


int managerList::printElement(Unit<Manager>* ptr)			//������ �������� ������ ���������� �� �������
{
	cout << ptr->getData().getName() << endl;
	cout << ptr->getData().getNumber() << endl;
	return 0;
}

Unit<Manager>* managerList::Search_name(string value)		//����� ��������� �� �����
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

int discountList::inputFromFile(string path, carList* carBase)		//���������� ������ ������ ������� �� �����.
{																	//������� ������ ��������� � ����������� ������� ������ �����������
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

int discountList::printElement(Unit<Discount>* ptr, int position)			//������ ���������� �� ����� �� �������
{
	float off;
	int price;
	cout << position << ".\t----------------------------------" << endl;
	cout << ptr->getData().getRelatedCar()->getData().getTitile() << endl;
	cout << "����: " << ptr->getData().getRelatedCar()->getData().getPrice() << " => ";
	price = ptr->getData().getRelatedCar()->getData().getPrice();
	off = ptr->getData().getOffAmount();
	off = off / 100;
	price = price - (price * off);
	cout << (price);
	cout << "  (" << ptr->getData().getOffAmount() << "% OFF!)" << endl;
	cout << "��������� �� " << ptr->getData().getEndDate() << "!" << endl;
	cout << "\t----------------------------------" << endl;
	return 0;
}
