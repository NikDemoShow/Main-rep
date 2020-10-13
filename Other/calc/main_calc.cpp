#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "Calc.h"

/*Представление выражения в виде польской записи и подсчёт значения*/

int main() {
	char ch, *str = (char*)malloc(100 * sizeof(char));
	int len = 1, *p_l = &len;
	str[0] = '!';
	ch = getchar();
	if (ch == '\n') {
		ch = getchar();
	}
	while (ch != '\n')
	{
		str[len] = ch;
		len++;
		ch = getchar();
	}
	str[len] = '!';
	len++;
	str = polish_entry(str, p_l);
	printf("%s\n", str);
	printf("%f", calc(str, *p_l));

	return 0;
}