int customWithdraw(int withdrawSize, int paperValue, int paperCounter, sPaper buff[paperVariants]) { // Выдача крупными
	int paperNum;				// Необходимое кол-во купюр для выдачи суммы
	int paperPos = 0;			// Позиция купюры	

	while (buff[paperPos].value != paperValue)	// Поиск позиции купюры
		paperPos++;

	paperNum = withdrawSize / paperValue;		// Поиск кол-ва купюр, необходимых для выдачи
	if (buff[paperPos].amount < paperNum)		// Проверка наличия нужного кол-ва купюр
		paperNum = buff[paperPos].amount;
	withdrawSize -= paperValue * paperNum;		// Уменьшение суммы выдачи
	paperCounter += paperNum;					// Кол-во выданных купюр
	buff[paperPos].amount -= paperNum;

	if (paperCounter > oneTimePaperLimit)		// Превышение лимита
		return -2;
	if (withdrawSize != 0) {					
		paperPos = biggestPaper(withdrawSize, buff);
		if (paperPos < 0)
			return -1;
		paperCounter = customWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
	}
	return paperCounter;
}

int exchangeWithdraw(int withdrawSize, int paperValue, int paperCounter, sPaper buff[paperVariants]) { // Выдача с разменом
	int paperNum;                // Необходимое кол-во купюр для выдачи суммы
	int paperPos = 0;            // Позиция купюры
	int thatPaper;
	while (buff[paperPos].value != paperValue)        // Поиск позициии купюры
		paperPos++;
	thatPaper = paperPos;
	paperNum = (withdrawSize / paperValue) - 1;     // Поиск кол-ва купюр, необходимых для выдачи
	if (paperNum > buff[paperPos].amount)
		paperNum = buff[paperPos].amount;
	withdrawSize -= paperValue * paperNum;        // Уменьшение суммы выдачи
	paperCounter += paperNum;                    // Кол-во выданных купюр
	buff[paperPos].amount -= paperNum;

	if (paperCounter > oneTimePaperLimit)                // Превышение лимита
		return -2;
	if (withdrawSize != 0) {
		paperPos = biggestPaper(withdrawSize, buff);
		if (paperPos > 0) {
			if (paperPos == thatPaper)
				paperPos -= 1;    // Понижение номинала 
			while (buff[paperPos].amount == 0 && paperPos >= 0) //Понижение номинала до допустимого
				paperPos -= 1;
		}

		if (paperPos < 0 && buff[thatPaper].amount > 0)        //Если нету других купюр, но есть купюры этой итерации
			paperCounter = customWithdraw(withdrawSize, paper[thatPaper].value, paperCounter, buff);
		else if (paperPos < 0) //если купюр больше нет
			return -1;
		if (paperPos == 0)     //если купюра наименьшая в массиве
			paperCounter = customWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
		else if (paperPos > 0) { //Продолжение размена новыми купюрами
			paperCounter = exchangeWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
			if (paperCounter < 0) { //Неудачный размен
				for (int i = 0; i < thatPaper; i++) { //Откат выданных купюр
					if (buff[i].amount != paper[i].amount) {
						buff[i].amount = paper[i].amount;
					}
				}
				paperCounter = customWithdraw(withdrawSize, paper[thatPaper].value, paperCounter, buff); //Попытка довыдачи купюрой этой итерации
			}
		}
	}
	return paperCounter;
}