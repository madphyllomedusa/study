#pragma once
int biggestPaper(int amount, sPaper buff[paperVariants]) { // ���������� ������� ������
	int i = 0;
	while (i < paperVariants - 1) {
		if (amount >= buff[i + 1].value) {
			i++;

		}
		else break;
	}
	while (i >= 0) {						// �������� ������� ������� ������
		if (buff[i].amount == 0)
			i--;
		else break;
	}
	return i;
}

int smallestPaper() {   // ���������� ������� ������
	int i = 0;
	bool paperExists = true;
	while (i < paperVariants) {
		if (paper[i].amount == 0)
			i++;
		else {
			paperExists = true;
			break;
		}
	}
	if (paperExists)			// �������� ������������� ������
		return i;
	else return -1;
}