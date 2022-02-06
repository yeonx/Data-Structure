#pragma warning(disable:4996) //경고무시
#include <stdio.h> //stdio헤더 선언
#include <string.h> //string헤더 선언
#include <stdlib.h> //stdlib헤더 선언
void I(int *Queue, int k, int q) {
	int n;
	scanf("%d", &n);
	if (k == q) {
		Queue[0] = n;
	}
	else
		Queue[k] = n;
}
void D(int *Queue, int l) {
	Queue[l] = 0;
}
void P(int *Queue, int q) {
	int i;
	for (i = 0;i < q;i++) {
		printf(" %d", Queue[i]);
	}
	printf("\n");
}
int main() {
	int *Queue, q, n, i,front = 1, rear=1;
	char c;
	scanf("%d", &q);
	Queue = (int *)malloc(sizeof(int)*q);
	for (i = 0;i < q;i++)
		Queue[i] = 0;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'I') {
			if (rear == q)
				rear -= q;
			rear++;
			if (rear == front) {
				printf("overflow");
				P(Queue, q);
				return 0;
			}
			I(Queue, rear-1, q);
		}
		else if (c == 'D') {
			if (rear == front) {
				printf("underflow\n");
				return 0;
			}
			D(Queue, front);
			front++;
			if (front == q) {
				front -= q;
			}
		}
		else if (c == 'P') {
			P(Queue, q);
		}
	}
	return 0;
}
