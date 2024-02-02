//#pragma once
//int paperCheck(int withdrawSize, int paperValue, int paperCounter) {
//	int paperNum;
//	int paperPos = 0;
//
//
//	while (paper[0][paperPos] != paperValue)
//		paperPos++;
//	paperNum = withdrawSize / paperValue;
//
//	if (paperNum > paper[1][paperPos]) {
//		withdrawSize -= paperValue * paper[1][paperPos];
//		paperCounter += paper[1][paperPos];
//	}
//	else {
//		withdrawSize -= paperValue * paperNum;
//		paperCounter += paperNum;
//	}
//	if (paperCounter > 1000)
//		return -2;
//	if (withdrawSize != 0) {
//		if (paperPos == 0)
//			return -1;
//		else {
//			paperPos = biggestPaper(withdrawSize);
//			paperCounter = paperCheck(withdrawSize, paper[0][paperPos], paperCounter);
//		}
//	}
//	return paperCounter;
//}