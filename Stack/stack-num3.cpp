#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	NODE *next;
	char data;
	int num;
}NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->next = NULL;
}
int order(char b,int a) {
	if (b == '!'|| a==1)
		return 6;
	else if (b == '*' || b == '/')
		return 5;
	else if (b == '+' || b == '-')
		return 4;
	else if (b == '>' || b == '<')
		return 3;
	else if (b == '&')
		return 2;
	else if (b == '|')
		return 1;
	else
		return 0;
}
void push(NODE **top,char c,int a) {
	NODE *p;
	getNode(&p);
	if(*top!=NULL)
		p->next = *top;
	*top = p;
	p->data = c;
	p->num = order(c,a);
}
char pop(NODE **top) {
	char c = (*top)->data;
	NODE *p = (*top);
	if (p->next != NULL)
		*top = p->next;
	else
		*top = NULL;
	free(p);
	return c;
}
int main() {
	int n, i, j, k, a;
	char s;
	NODE *top = NULL;
	scanf("%d", &n);
	getchar();
	for (i = 0;i < n;i++) {
		char in[101] = "", out[101] = "";
		k = 0;
		scanf("%s", in);
		getchar();
		for (j = 0;j < strlen(in);j++) {
			a = 0;
			if (in[j] == '+' || in[j] == '-') {
				if (j == 0)
					a = 1;
				else if (in[j - 1] == '!' || in[j - 1] == '+' || in[j - 1] == '-' || in[j - 1] == '*' || in[j - 1] == '/' || in[j - 1] == '>' || in[j - 1] == '<' || in[j - 1] == '|' || in[j - 1] == '&')
					a = 1;
			}
			if (in[j] >= 'A'&&in[j] <= 'Z')
				out[k++] = in[j];
			else if (top == NULL)
				push(&top, in[j],a);
			else if (in[j] == '(')
				push(&top, '(',a);
			else if (in[j] == ')') {
				while (1) {
					s = pop(&top);
					if (s == '(')
						break;
					out[k++] = s;
					if (s == '|' || s == '&')
						out[k++] = s;
				}
			}
			else {
				while (top!=NULL) {
					if (top->num >= order(in[j],a)) {
						out[k++] = pop(&top);
						if (out[k - 1] == '|')
							out[k++] = '|';
						else if (out[k - 1] == '&')
							out[k++] = '&';
					}
					else
						break;
				}
				push(&top, in[j],a);
			}
			if (in[j] == '|' || in[j] == '&')
				j++;
		}
		while (top!=NULL){
			out[k++] = pop(&top);
			if (out[k - 1] == '|')
				out[k++] = '|';
			else if (out[k - 1] == '&')
				out[k++] = '&';
		}
		printf("%s\n", out);
	}
	return 0;
}
