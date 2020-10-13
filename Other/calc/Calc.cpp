#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "Calc.h"

Node* push(Node* phead, char v) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = v;
	p->pnext = phead;
	return p;
}

Node_int* push(Node_int* phead, int v) {
	Node_int *p = (Node_int*)malloc(sizeof(Node_int));
	p->val = v;
	p->pnext = phead;
	return p;
}


Node* pop(Node* phead) {
	Node *p = phead->pnext;
	free(phead);
	return p;
}

Node_int* pop(Node_int* phead) {
	Node_int *p = phead->pnext;
	free(phead);
	return p;
}

Node* read(Node* phead) {
	Node *p = phead->pnext;
	return p;
}

int Isempty(Node* phead) {
	if (phead) {
		return 0;
	}
	return 1;
}

char* polish_entry(char *str, int *len) {
	Node *buf = 0;
	char *rez = (char*)malloc(100 * sizeof(char));;
	int len_r = 0;
	buf = push(buf, str[0]);
	for (int i = 1; i < *len; i++) {
		if (str[i] != '-' && str[i] != '+' &&  str[i] != '*' && str[i] != '/' && str[i] != '-' && str[i] != '!' && str[i] != '(' && str[i] != ')') {
			rez[len_r] = str[i];
			len_r++;
		}
		else if (str[i] == '(' || (str[i] == '/' || str[i] == '*') && (buf->val == '!' || buf->val == '+' || buf->val == '-' || buf->val == '(')
			|| (str[i] == '+' || str[i] == '-') && (buf->val == '!' || buf->val == '(')) {
			buf = push(buf, str[i]);
		}
		else if ((str[i] == '/' || str[i] == '*') && (buf->val == '*' || buf->val == '/')
			|| (str[i] == '+' || str[i] == '-' || str[i] == '!' || str[i] == ')') && (buf->val == '+' || buf->val == '-' || buf->val == '*' || buf->val == '/')) {
			while (buf->val != '!') {
				if (buf->val != '(') {
					rez[len_r] = buf->val;
					len_r++;
				}
				else if (str[i] == ')' && buf->val == '(') {
					buf = pop(buf);
					break;
				}
				else {
					break;
				}
				buf = pop(buf);
			}
			if (str[i] != ')') {
				buf = push(buf, str[i]);
			}
		}
	}
	rez[len_r] = '\0';
	*len = len_r;
	return rez;
}
/*Переменные*/
float calc(char* str, int len) {
	node_int *calc = 0;
	int x, a, b;
	printf("Only integer\n");
	for (int i = 0; i < len; i++) {
		if (str[i] != '-' && str[i] != '+' &&  str[i] != '*' && str[i] != '/' && str[i] != '-') {
			printf("Vvedite znachenie %c\n", str[i]);
			scanf("%d", &x);
			calc = push(calc, x);
		}
		else {
			b = calc->val;
			calc = pop(calc);
			a = calc->val;
			calc = pop(calc);
			if (str[i] == '+') {
				calc = push(calc, a + b);
			}
			else if (str[i] == '-') {
				calc = push(calc, a - b);
			}
			else if (str[i] == '*') {
				calc = push(calc, a * b);
			}
			else {
				if (b != 0) {
					calc = push(calc, a / b);
				}
				else {
					printf("Division by zero\n");
					return 0;
				}
			}
		}
	}
	return (calc->val);

}