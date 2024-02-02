int min(const int a, float b) {
	if (a < b)
		return a;
	else return b;
}

float withdraw(float balance, int amount, int smallestPaperValue) {
	int answer;
	int paperValue;					// �������
	int paperCounter = 0;			// ������� ���-�� �����
	int biggestPaperValue;			// ������� ������� ������
	int paperCounterExchange = 0;
	bool gotAnswer = false;
	bool variants = false;
	bool exchangeAllowed = false;	// ���������� �������

	sPaper buff[paperVariants];   // �������� ������� ��������
	for (int i = 0; i < paperVariants; i++) {
		buff[i].value = paper[i].value;
		buff[i].amount = paper[i].amount;
	}
	sPaper buff2[paperVariants];   // �������� ������� ��������
	for (int i = 0; i < paperVariants; i++) {
		buff2[i].value = paper[i].value;
		buff2[i].amount = paper[i].amount;
	}
	biggestPaperValue = biggestPaper(amount, buff); // ���������� ���������� ������
	if (biggestPaperValue == -1) {							// ���������� ���������� ������
		puts("������ ����������: � ��������� ������������ �����.");
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
			if (exchangeAllowed && variants) { //���� ������ �������� ������
				puts("1) ������ �������� ��������\n2) ������ � ��������\n3) �����");
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
						puts("������������ �����.");
						gotAnswer = false;
					}
				}
			}
		}
	}

	switch (paperCounter) { //��������� ��������
	case -1:
		puts("������ ����������: � ��������� ������������ �����.");
		break;
	case -2:
		puts("������ ����������: �������� ����� ���-�� ����� ��� �������� ������");
		break;
	default:
		for (int i = paperVariants - 1; i >= 0; i--) {
			if (buff[i].amount != paper[i].amount) {
				printf("������ %d ����� �� %d ������.\n", paper[i].amount - buff[i].amount, paper[i].value);
				paper[i].amount = buff[i].amount;
			}
		}
		puts("\n");
		balance -= amount;				// ���������� ������� ������������
		alreadyGiven += amount;			// ���������� ������ ������
	}
	return balance;
}

void withdrawMenu(int smallestPaperValue) {
	int biggestPaperValue;			//	���������� �������
	int amount = 0, i, j = 0;
	bool acceptableAmount = false;
	int limit;
	bool gotAnswer = false;
	sPaper buff[paperVariants];   // �������� ������� ��������
	for (int i = 0; i < paperVariants; i++) {
		buff[i].value = paper[i].value;
		buff[i].amount = paper[i].amount;
	}
	limit = min(oneTimeLimit, balance);
	printf("����������� ������ ������ - %d ������. ������������ - %d ������.\n", paper[smallestPaperValue].value, limit);
	biggestPaperValue = biggestPaper(balance, paper);
	puts("�������� ����� ������:\n");
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
	printf("%d) ������\n", ++j);
	printf("%d) �����\n", ++j);
	while (!gotAnswer) {								//��������� ������ ������������
		gotAnswer = true;
		cin >> amount;
		if (amount == j)					//�����
			break;
		else if (amount == j - 1) {			//���������������� �����
			i = smallestPaperValue;
			cout << "������� �����:\n";
			cin >> amount;
			while (i < biggestPaperValue + 1) {
				if (amount % paper[i].value == 0) {
					acceptableAmount = true;
				}
				i++;
			}
			if (!acceptableAmount)
				puts("���������� ������ ����� �� ������� �� ����� �� ��������� �����. ������� ������ �����.");
			else if (amount > balance)
				puts("�� ����� ����� ������������ ������� ��� ������ ���� �����. ������� ������ �����.");
			else if (amount > oneTimeLimit)
				puts("�������� ������� ����� ������. ������� ������ �����.");
			else if (amount + alreadyGiven > dayLimit)
				puts("����� �������� ������� ����� ������.  ������� ������ �����.");
			else if (amount < paper[smallestPaperValue].value)
				puts("���������� ����� ����� ������ ���������� ������, �������������� � ���������. ������� ������ �����.");
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
				puts("������������ �����\n");
				gotAnswer = false;
			}
		}
	}
}