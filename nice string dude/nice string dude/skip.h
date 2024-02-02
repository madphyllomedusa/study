#pragma once
void skip(char *user_f)
{	
	int last_probel = -1;		//hueta
	for (int i = last_probel + 1; i < limit; ++i) {			//hueta
		if (*(user_f + i) == ' ')
			last_probel = i;				
	}

}