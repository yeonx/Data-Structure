#pragma warning(disable:4996) //경고무시
#include <stdio.h> //stdio헤더 선언
#include <string.h> //string헤더 선언
#include <stdlib.h> //stdlib헤더 선언
int top; //top을 전역 변수로 선언
void push(int *stack,int c) {//스택에 추가하는 함수
	top++; //탑 위치+1
	stack[top] = c; //입력받은 정수를 top에 넣음
}//괄호닫음
int pop(int *stack) { //스택의 top을 삭제하는 함수
	int re = stack[top]; //반환값에 스택의 top넣어줌
	top--; //탑 위치 -1
	return re; //반환값은 top에 있던 정수
}//괄호닫음
int main() { //메인함수 선언
	char in[101] = ""; //입력받을 문자열 선언
	int stack[100] = { 0 }; //스택 정수배열로 선언
	int N, i, j,num1, num2; //반복문과 산수를 위한 함수 선언
	scanf("%d", &N); // 몇 번 할지
	getchar(); //공백 입력
	for (i = 0;i < N;i++) { //N번 반복
		scanf("%s", in); //문자열 입력
		getchar(); //공백 받기 
		top = -1; // 탑의 위치 초기화
		for (j = 0;j < strlen(in);j++) { //문자열 만큼 반복
			if (in[j] >= '0'&&in[j] <= '9') { //문자가 숫자면
				push(stack, in[j]-'0'); //숫자를 스택에 추가
			} //괄호닫음
			else if (in[j] == '+') { //문자가 +이면
				num1 = pop(stack); //num1에 top에 있던 수 넣어주고
				num2 = pop(stack); //num2에 top 다음에 있던 수 넣어줌
				push(stack, num1 + num2); // 더한 수를 top에 저장
			}//괄호닫음
			else if (in[j] == '-') {
				num1 = pop(stack); //num1에 top에 있던 수 넣어주고
				num2 = pop(stack); //num2에 top 다음에 있던 수 넣어줌
				push(stack, num2 - num1); // 뺀 수를 top에 저장
			}//괄호닫음
			else if (in[j] == '*') {
				num1 = pop(stack); //num1에 top에 있던 수 넣어주고
				num2 = pop(stack); //num2에 top 다음에 있던 수 넣어줌
				push(stack, num1 * num2); //곱한 수를 top에 저장
			}//괄호닫음
			else if (in[j] == '/') {
				num1 = pop(stack); //num1에 top에 있던 수 넣어주고
				num2 = pop(stack); //num2에 top 다음에 있던 수 넣어줌
				push(stack, num2 / num1); //나눈 수를 top에 저장
			}//괄호닫음
		}//괄호닫음
		printf("%d\n", pop(stack)); //스택의 마지막에 남은 수를 출력
	}//괄호닫음
	return 0;//메인함수종료
} //괄호닫음
