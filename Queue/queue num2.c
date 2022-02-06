#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	struct node *prev;
	struct node *next;
	int num;
};
typedef struct node NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->prev = NULL;
	(*p)->next = NULL;
}
void AF(NODE **front, NODE **rear) {
	NODE *p = NULL; getNode(&p);
	scanf("%d", &(p->num));
	if (*front == NULL) {
		*front = p;
		*rear = p;
	}
	else {
		p->next = *front;
		(*front)->prev = p;
		*front = p;
	}

}
void AR(NODE **front, NODE **rear) {
	NODE *p = NULL; getNode(&p);
	scanf("%d", &(p->num));
	if (*rear == NULL) {
		*front = p;
		*rear = p;
	}
	else {
		p->prev = *rear;
		(*rear)->next = p;
		*rear = p;
	}
}
void DF(NODE **front,NODE **rear) {
	NODE *p;
	p = *front;
	if (*front == *rear) {
		*front= NULL;
		*rear= NULL;
	}
	else {
		*front = p->next;
		(*front)->prev = NULL;
	}
	free(p);
}
void DR(NODE **front,NODE **rear) {
	NODE *p;
	p = *rear;
	if (*front == *rear) {
		*front= NULL;
		*rear=NULL;
	}
	else {
		*rear = p->prev;
		(*rear)->next = NULL;
	}
	free(p);
}
void P(NODE **front, NODE **rear) {
	NODE *p;
	for (p = *front;p != NULL;p = p->next)
		printf("%d ", p->num);
	printf("\n");
}
int main() {
	NODE *front = NULL, *rear = NULL;
	int n, i;
	char str[3] = "";
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%s", str);
		if (strcmp(str, "AF") == 0)
			AF(&front, &rear);
		else if (strcmp(str, "AR") == 0)
			AR(&front, &rear);
		else if (strcmp(str, "DF") == 0) {
			if (front == NULL) {
				printf("underflow\n");
				break;
			}
			DF(&front,&rear);
		}
		else if (strcmp(str, "DR") == 0) {
			if (rear == NULL) {
				printf("underflow\n");
				break;
			}
			DR(&front,&rear);
		}
		else if (strcmp(str, "P") == 0)
			P(&front, &rear);
	}
	return 0;
}
