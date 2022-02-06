#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	NODE *next;
	int coef;
	int exp;
}NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->next = NULL;
}
void addNode(NODE *a,int c,int e) {
	NODE *p, *tmp = NULL;
	getNode(&tmp);
	tmp->coef = c;
	tmp->exp = e;
	for (p = a;p->next != NULL;p = p->next);
	p->next = tmp;
}
void addtwo(NODE *a, NODE *b, NODE *c) {
	NODE *p=a->next, *q=b->next;
	while (1) {
		if (p == NULL && q == NULL)
			break;
		else if (p == NULL && q != NULL) {
			addNode(c, q->coef, q->exp);
			q = q->next;
		}
		else if (p != NULL && q == NULL) {
			addNode(c, p->coef, p->exp);
			p = p->next;
		}
		else {
			if (p->exp > q->exp) {
				addNode(c, p->coef, p->exp);
				p = p->next;
			}
			else if (p->exp < q->exp) {
				addNode(c, q->coef, q->exp);
				q = q->next;
			}
			else {
				if (p->coef + q->coef != 0) 
					addNode(c, p->coef + q->coef, p->exp);
				p = p->next;
				q = q->next;
			}
		}
	}
}
void print(NODE *q) {
	NODE *p;
	for (p = q->next;p != NULL;p = p->next)
		printf(" %d %d", p->coef, p->exp);
	printf("\n");
}
int main() {
	NODE *a, *b, *c;
	getNode(&a);
	getNode(&b);
	getNode(&c);
	int n, i, d1, d2;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d %d", &d1, &d2);
		addNode(a,d1,d2);
	}
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d %d", &d1, &d2);
		addNode(b, d1, d2);
	}
	addtwo(a, b, c);
	print(c);
	return 0;
}
