int min(const int a, float b) {
	if (a < b)
		return a;
	else return b;
}

float withdraw(float balance, int amount, int smallestPaperValue) {
	int answer;
	int paperValue;					// Номинал
	int paperCounter = 0;			// Счётчик кол-ва купюр
	int biggestPaperValue;			// Номинал старшей купюры
	int paperCounterExchange = 0;
	bool gotAnswer = false;
	bool variants = false;
	bool exchangeAllowed = false;	// Разрешение размена

	sPaper buff[paperVariants];   // Создание массива структур
	for (int i = 0; i < paperVariants; i++) {
		buff[i].value = paper[i].value;
		buff[i].amount = paper[i].amount;
	}
	sPaper buff2[paperVariants];   // Создание массива структур
	for (int i = 0; i < paperVariants; i++) {
		buff2[i].value = paper[i].value;
		buff2[i].amount = paper[i].amount;
	}
	biggestPaperValue = biggestPaper(amount, buff); // Нахождение наибольшей купюры
	if (biggestPaperValue == -1) {							// Нахождение наибольшей купюры
		puts("Выдача невозможна: в банкомате недостаточно купюр.");
		return balance;
	}
	if (amount == paper[smallestPaperValue].value) {
		paperCounter = customWithdraw(amount, paper[smallestPaperValue].value, paperCounter, buff);
	}
	else {
		paperCounter = customWithdraw(amount, paper[biggestPaperValue].value, paperCounter, buff);
		if (paperCounter > 0) {
			paperCounterExchange = exchangeWithdraw(amount, paper[biggestPaperValue].value, paperCounterExchange, buff2);
			if (paperCounterExchange >= 0)
				exchangeAllowed = true;
			if (exchangeAllowed) {
				for (int i = 0; i < paperVariants; i++) {
					if (buff[i].amount != buff2[i].amount) {
						variants = true;
						break;
					}
				}
			}
			if (exchangeAllowed && variants) { //меню выбора варианта выдачи
				puts("1) Выдача крупными купюрами\n2) Выдача с разменом\n3) Выход");
				while (!gotAnswer) {
					gotAnswer = true;
					cin >> answer;
					switch (answer) {
					case 1:
						break;
					case 2:
						paperCounter = paperCounterExchange;
						for (int i = 0; i < paperVariants; i++)
							buff[i].amount = buff2[i].amount;
						break;
					case 3:
						return balance;
					default:
						puts("Неприемлимый ответ.");
						gotAnswer = false;
					}
				}
			}
		}
	}

	switch (paperCounter) { //результат выдачачи
	case -1:
		puts("Выдача невозможна: в банкомате недостаточно купюр.");
		break;
	case -2:
		puts("Выдача невозможна: привышен лимит кол-ва купюр для разового снятия");
		break;
	default:
		for (int i = paperVariants - 1; i >= 0; i--) {
			if (buff[i].amount != paper[i].amount) {
				printf("Выдано %d купюр по %d рублей.\n", paper[i].amount - buff[i].amount, paper[i].value);
				paper[i].amount = buff[i].amount;
			}
		}
		puts("\n");
		balance -= amount;				// Уменьшение баланса пользователя
		alreadyGiven += amount;			// Уменьшение лимита снятия
	}
	return balance;
}

void withdrawMenu(int smallestPaperValue) {
	int biggestPaperValue;			//	Наибольший номинал
	int amount = 0, i, j = 0;
	bool acceptableAmount = false;
	int limit;
	bool gotAnswer = false;
	sPaper buff[paperVariants];   // Создание массива структур
	for (int i = 0; i < paperVariants; i++) {
		buff[i].value = paper[i].value;
		buff[i].amount = paper[i].amount;
	}
	limit = min(oneTimeLimit, balance);
	printf("Минимальный размер снятия - %d рублей. Максимальный - %d рублей.\n", paper[smallestPaperValue].value, limit);
	biggestPaperValue = biggestPaper(balance, paper);
	puts("Выберите сумму снятия:\n");
	for (i = 0; i < defaultSumsAmount; i++) {
		amount = 0;
		amount = customWithdraw(defaultSums[i].value, paper[biggestPaperValue].value, amount, buff);
		if (amount > 0) {
			printf("%d) %d\n", j + 1, defaultSums[i].value);
			defaultSums[i].pos = j + 1;
			j++;
		}
		else defaultSums[i].pos = -1;
		for (int i = 0; i < paperVariants; i++) {
			buff[i].value = paper[i].value;
			buff[i].amount = paper[i].amount;
		}
	}
	printf("%d) Другая\n", ++j);
	printf("%d) Выход\n", ++j);
	while (!gotAnswer) {								//получение ответа пользователя
		gotAnswer = true;
		cin >> amount;
		if (amount == j)					//выход
			break;
		else if (amount == j - 1) {			//пользовательская сумма
			i = smallestPaperValue;
			cout << "Введите сумму:\n";
			cin >> amount;
			while (i < biggestPaperValue + 1) {
				if (amount % paper[i].value == 0) {
					acceptableAmount = true;
				}
				i++;
			}
			if (!acceptableAmount)
				puts("Невозможно выдать сумму не кратную ни одной из имеющихся купюр. Введите другую сумму.");
			else if (amount > balance)
				puts("На Вашем счету недостаточно средств для снятия этой суммы. Введите другую сумму.");
			else if (amount > oneTimeLimit)
				puts("Превышен разовый лимит снятия. Введите другую сумму.");
			else if (amount + alreadyGiven > dayLimit)
				puts("Будет превышен дневной лимит выдачи.  Введите другую сумму.");
			else if (amount < paper[smallestPaperValue].value)
				puts("Невозможно снять сумму меньше наименьшей купюры, представленной в банкомате. Введите другую сумму.");
			else balance = withdraw(balance, amount, smallestPaperValue);
		}
		else {
			for (i = 0; i < j - 2; i++) {
				if (amount == defaultSums[i].pos) {
					balance = withdraw(balance, defaultSums[i].value, smallestPaperValue);
					break;
				}
			}
			if (i == j - 2) {
				puts("Неприемлимый ответ\n");
				gotAnswer = false;
			}
		}
	}
}