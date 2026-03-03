#include "../inc/number_convert.h"

int str_to_number(const char *str) /* FIX (wi str contain negative number?) */
{
	int number = 0, i = 0;
	char ch;
	ch = *str;
	while(ch != '\0') {	/* or something else (as terminated symbol) */
		ch = ch - 0x30;
		number = number*10 + ch;
		i++;
		ch = *(str+i);
	}
	return number;
}

void number_to_str(int number, char *str)
{
	int i = 0, j = 0;
	char tmp_str[max_number_length] = { 0 };
	char tmp;
	if(number == 0) {
		*str = 0x30;
		*(str + 1) = '\0';
		return;
	} else if(number < 0) {
		number = number*(-1);
		*(str) = '-';
		j++;
	}
	while(number != 0) {
		tmp = number % 10;
		number = number/10;
		tmp = tmp + 0x30;
		*(tmp_str + i) = tmp;
		i++;
	}
	if(j != 1)
		i--;
	while(j <= i) {
		*(str + j) = *(tmp_str + i - j);
		j++;
	}
	*(str + j) = '\0';
}
