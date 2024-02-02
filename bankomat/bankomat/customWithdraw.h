int customWithdraw(int withdrawSize, int paperValue, int paperCounter, sPaper buff[paperVariants]) { // ������ ��������
	int paperNum;				// ����������� ���-�� ����� ��� ������ �����
	int paperPos = 0;			// ������� ������	

	while (buff[paperPos].value != paperValue)	// ����� ������� ������
		paperPos++;

	paperNum = withdrawSize / paperValue;		// ����� ���-�� �����, ����������� ��� ������
	if (buff[paperPos].amount < paperNum)		// �������� ������� ������� ���-�� �����
		paperNum = buff[paperPos].amount;
	withdrawSize -= paperValue * paperNum;		// ���������� ����� ������
	paperCounter += paperNum;					// ���-�� �������� �����
	buff[paperPos].amount -= paperNum;

	if (paperCounter > oneTimePaperLimit)		// ���������� ������
		return -2;
	if (withdrawSize != 0) {					
		paperPos = biggestPaper(withdrawSize, buff);
		if (paperPos < 0)
			return -1;
		paperCounter = customWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
	}
	return paperCounter;
}

int exchangeWithdraw(int withdrawSize, int paperValue, int paperCounter, sPaper buff[paperVariants]) { // ������ � ��������
	int paperNum;                // ����������� ���-�� ����� ��� ������ �����
	int paperPos = 0;            // ������� ������
	int thatPaper;
	while (buff[paperPos].value != paperValue)        // ����� �������� ������
		paperPos++;
	thatPaper = paperPos;
	paperNum = (withdrawSize / paperValue) - 1;     // ����� ���-�� �����, ����������� ��� ������
	if (paperNum > buff[paperPos].amount)
		paperNum = buff[paperPos].amount;
	withdrawSize -= paperValue * paperNum;        // ���������� ����� ������
	paperCounter += paperNum;                    // ���-�� �������� �����
	buff[paperPos].amount -= paperNum;

	if (paperCounter > oneTimePaperLimit)                // ���������� ������
		return -2;
	if (withdrawSize != 0) {
		paperPos = biggestPaper(withdrawSize, buff);
		if (paperPos > 0) {
			if (paperPos == thatPaper)
				paperPos -= 1;    // ��������� �������� 
			while (buff[paperPos].amount == 0 && paperPos >= 0) //��������� �������� �� �����������
				paperPos -= 1;
		}

		if (paperPos < 0 && buff[thatPaper].amount > 0)        //���� ���� ������ �����, �� ���� ������ ���� ��������
			paperCounter = customWithdraw(withdrawSize, paper[thatPaper].value, paperCounter, buff);
		else if (paperPos < 0) //���� ����� ������ ���
			return -1;
		if (paperPos == 0)     //���� ������ ���������� � �������
			paperCounter = customWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
		else if (paperPos > 0) { //����������� ������� ������ ��������
			paperCounter = exchangeWithdraw(withdrawSize, paper[paperPos].value, paperCounter, buff);
			if (paperCounter < 0) { //��������� ������
				for (int i = 0; i < thatPaper; i++) { //����� �������� �����
					if (buff[i].amount != paper[i].amount) {
						buff[i].amount = paper[i].amount;
					}
				}
				paperCounter = customWithdraw(withdrawSize, paper[thatPaper].value, paperCounter, buff); //������� �������� ������� ���� ��������
			}
		}
	}
	return paperCounter;
}