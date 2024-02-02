#pragma once
#include "Data.h"
int carSearch(carList* carBase);			//Меню для поиска автомобиля по параметрам
int carBaseMenu(carList* carBase);			//Меню для работы с базой автомобилей
int managerBaseMenu(managerList* managerBase);		//Меню для работы с базой менеджеров					
int discountsMenu(discountList* discountBase, managerList* managerBase); //Меню для работы с базой скидок 