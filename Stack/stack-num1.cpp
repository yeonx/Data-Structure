#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N, top = -1;
void push(char *stack,char c) {
	if ((top+1) == N)
		printf("Stack FULL\n");
	else {
		top++;
		stack[top] = c;
	}
}
char pop(char *stack) {
	if (top == -1) {
		printf("Stack Empty\n");
		return 0;
	}
	char c = stack[top];
	top--;
	return c;
}
void peek(char *stack) {
	printf("%c\n", stack[top]);
}
void duplicate(char *stack) {
	char c = pop(stack);
	push(stack, c);
	push(stack, c);
}
void upRotate(char *stack,int ro) {
	int i;
	char c;
	if (top+1 < ro)
		return;
	else {
		c = stack[top];
		for (i = top;i > top - ro+1;i--)
			stack[i] = stack[i - 1];
		stack[top - ro + 1] = c;
	}

}
void downRotate(char *stack,int ro) {
	int i;
	char c;
	if (top+1 < ro)
		return;
	else{
		c = stack[top-ro+1];
		for (i = top - ro + 1;i <= top;i++)
			stack[i] = stack[i + 1];
		stack[top] = c;

	}
}
void print(char *stack) {
	int i;
	for (i = top;i >= 0;i--)
		printf("%c", stack[i]);
	printf("\n");
}
int main() {
	scanf("%d", &N);
	int num, i, ro;
	char str[6] = "", c, *stack = (char *)malloc(sizeof(char)*N);
	scanf("%d", &num);
	getchar();
	for (i = 0;i < num;i++) {
		scanf("%s", str);
		getchar();
		if (strcmp(str, "PUSH") == 0) {
			scanf("%c", &c);
			getchar();
			push(stack, c);
		}
		else if (strcmp(str, "POP") == 0) {
			pop(stack);
		}
		else if (strcmp(str, "PEEK") == 0) {
			peek(stack);
		}
		else if (strcmp(str, "DUP") == 0) {
			duplicate(stack);
		}
		else if (strcmp(str, "UpR") == 0) {
			scanf("%d", &ro);
			upRotate(stack, ro);
		}
		else if (strcmp(str, "DownR") == 0) {
			scanf("%d", &ro);
			downRotate(stack, ro);
		}
		else if (strcmp(str, "PRINT") == 0) {
			print(stack);
		}
	}
	return 0;
}
