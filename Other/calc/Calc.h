#ifndef CALC_H
#define CALC_H

typedef struct node
{
	char val;
	struct node * pnext;
} Node;

typedef struct node_int
{
	int val;
	struct node_int * pnext;
} Node_int;

Node_int* push(Node_int* phead, int v);

Node* push(Node* phead, char v);

Node* pop(Node* phead);

Node_int* pop(Node_int* phead);

int Isempty(Node* phead);

char* polish_entry(char *str, int *len);

float calc(char* str, int len);

#endif