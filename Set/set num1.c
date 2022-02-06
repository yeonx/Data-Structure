#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	struct node *next;
	int num;
};
typedef struct node NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->next = NULL;
}
void addFNode(NODE **A) {
	NODE *tmp;
	getNode(&tmp);
	scanf("%d", &(tmp->num));
	*A = tmp;
}
void addNode(NODE **A) {
	NODE *tmp, *p;
	getNode(&tmp);
	scanf("%d", &(tmp->num));
	if ((*A)->num > tmp->num) {
		tmp->next = *A;
		*A = tmp;
	}
	else {
		for (p = A;p->next != NULL;p = p->next) {
			if (tmp->num < p->next->num)
				break;
		}
		tmp->next = p->next;
		p->next = tmp;
	}
}
void P(NODE *A) {
	NODE *p;
	for (p = A;p != NULL;p = p->next)
		printf("%d ", p->num);
	printf("\n");
}
void AB(NODE *A, NODE *B) {
	NODE *p, *q;
	int k, l = 0;
	for (p = A;p != NULL;p = p->next) {
		k = 0;
		for (q = B;q != NULL;q = q->next) {
			if (p->num == q->num) {
				k = 1;
				break;
			}
		}
		if (k == 0) {
			printf("%d", p->num);
			l = 1;
			break;
		}
	}
	if (l == 0)
		printf("0\n");
}
int main() {
	NODE *A = NULL, *B = NULL;
	int na, nb, i;
	scanf("%d", &na);
	for (i = 0;i < na;i++) {
		if (i == 0)
			addFNode(&A);
		else
			addNode(&A);
	}
	scanf("%d", &nb);
	for (i = 0;i < nb;i++) {
		if (i == 0)
			addFNode(&B);
		else
			addNode(&B);
	}
	AB(A, B);
	return 0;
}
