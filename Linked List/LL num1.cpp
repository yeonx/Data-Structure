#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	char ch;
	NODE *prev;
	NODE *next;
}NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->next = NULL;
	(*p)->prev = NULL;
}
void addNode(NODE *H) {
	NODE *tmp = NULL, *p = NULL;
	int n, i, num = 0;
	char ch;
	scanf("%d %c", &n,&ch);
	for (p = H->next;p->next != NULL;p = p->next) {
		num++;
	}
	if (num + 1 < n)
		printf("invalid position\n");
	else {
		getNode(&tmp);
		for (p = H, i = 1;i < n;i++, p = p->next);
		tmp->ch = ch;
		tmp->prev = p;
		tmp->next = p->next;
		p->next->prev = tmp;
		p->next = tmp;
	}
}
void delNode(NODE *H) {
	NODE *p = NULL;
	int n, i, num = 0;
	scanf("%d", &n);
	for (p = H->next;p->next != NULL;p = p->next) {
		num++;
	}
	if (n <= num) {
		for (p = H, i = 1;i <= n;i++, p = p->next);
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
	}
	else
		printf("invalid position\n");
}
void oneNode(NODE *H) {
	NODE *p = NULL;
	int n, i, num=0;
	scanf("%d", &n);
	for (p = H->next;p->next != NULL;p = p->next) {
		num++;
	}
	if (n <= num) {
		for (p = H, i = 1;i <= n;i++, p = p->next);
		printf("%c\n", p->ch);
	}
	else
		printf("invalid position\n");
}
void printNode(NODE *H) {
	NODE *p = NULL;
	for (p = H->next;p->next != NULL;p = p->next) {
		printf("%c", p->ch);
	}
	printf("\n");
}
int main() {
	NODE *H = NULL, *T = NULL;
	char what;
	int n, i;
	getNode(&H);
	getNode(&T);
	H->next = T;
	T->prev = H;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		getchar();
		scanf("%c", &what);
		if (what == 'A')
			addNode(H);
		else if (what == 'D')
			delNode(H);
		else if (what == 'G')
			oneNode(H);
		else if (what == 'P')
			printNode(H);
	}

	return 0;
}
