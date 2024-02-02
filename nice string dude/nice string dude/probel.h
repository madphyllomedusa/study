#pragma once
 int probel(char *user_f) {
	 int i, k = 0;
	 for (i = 0; *(user_f + i) != 0; i++) {
		 if (*(user_f + i) == ' ')
		 {
			 k++;
		 }
		// cout << *user_f+i;
	 }
	 return k;
}