#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
const int userlimit = 1024;
const int limit = 100;
#include "skip.h"
#include "probel.h"


int main()
{
	SetConsoleCP(1251);		// разрешить русский текст в потоке ввода
	SetConsoleOutputCP(1251);		// разрешить русский текст в потоке вывода
	cout << "text suda vvedi v kotorom menshe 1024 simvolov \n";
	int empt_symb = 0;
	char last_symb = '.';
	char user[1025]{};
	char* user_f = &user[0];
	char buff[100]{};
	bool stop = false;
	
	gets_s(user);








	//while (stop == false)
	//{
	//	gets_s(buff);
	//	for (int i = 0; buff[i] != 0; i++)
	//	{
	//		user[empt_symb] = buff[i];
	//		empt_symb++;
	//		if (buff[i] == last_symb && buff[i + 1] == 0)
	//		{
	//			stop = true;
	//		}
	//	}
	//	user[empt_symb] = 10;
	//	empt_symb++;
	//}
	//cout << user[empt_symb - 2] << endl;
	int k = probel(user_f);
	cout << k<< endl;
	cout << endl << user << '\n';
	return 0;
}
