#pragma warning(disable:4996)//경고무시
#include <stdio.h>//stdio헤더파일 선언
#include <stdlib.h>//stdlib헤더파일 선언
#include <string.h>//string 헤더파일 선언
void push(char *stack, int *top, char c) {//푸시함수 선언
	(*top)++;//위치에 +1
	stack[*top] = c;//탑에 문자 넣어줌
}
char pop(char *stack, int *top) {//팝함수 선언
	char re = stack[*top];//반환값이 탑에 있는값
	(*top)--;// 위치-1 (탑에 있는거 삭제)
	return re;//탑 값 반환
}
int main() {//메인 함수 선언
	char *stack, str[1000], re;//스택, 문자열, pop의 반환값을 받을 문자 선언
	int top = -1, i, count = 0, k = 1;//스택 위치 -1 로 초기화, 반복문위해, 괄호 수, 판단 위한 변수 선언
	gets(str);//공백을 포함한 문자열 입력 받기
	for (i = 0;i < strlen(str);i++) {//문자열 길이 만큼 반복
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[') || (str[i] == ')') || (str[i] == '}') || (str[i] == ']'))//괄호 일때
			count++;//count +1 해줌
	}
	stack = (char *)malloc(sizeof(char)*(strlen(str) + 1));//스택을 문자열 만큼 할당
	for (i = 0;i < strlen(str);i++) {//문자열 길이 만큼 반복
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')) {//여는 괄호일 때
			push(stack, &top, str[i]);//스택에 넣어준다
		}
		else if (str[i] == ')') {//닫는 괄호 )일때
			re = pop(stack, &top);//re에 탑값 넣어주고 탑에 있는거 삭제
			if (re != '(') {//'(' 괄호가 아니라면
				k = -1;//틀리다고 알려줌
				break;//더 이상 판단할 필요가 없으니 반복문 빠져나감
			}
		}
		else if (str[i] == '}') {//닫는 괄호 }일때
			re = pop(stack, &top);//re에 탑값 넣어주고 탑에 있는거 삭제;
			if (re != '{') {//'{' 괄호가 아니라면
				k = -1;//틀리다고 알려줌
				break;//더 이상 판단할 필요가 없으니 반복문 빠져나감
			}
		}
		else if (str[i] == ']') {//닫는 괄호 ]일때
			re = pop(stack, &top);//re에 탑값 넣어주고 탑에 있는거 삭제
			if (re != '[') {//'[' 괄호가 아니라면
				k = -1;//틀리다고 알려줌
				break;//더 이상 판단할 필요가 없으니 반복문 빠져나감
			}
		}
	}
	if (k == 1) {//틀렸다는 표시가 없었을때
		re = pop(stack, &top);//스택에 하나라도 남아있으면
		if ((re == '(') || (re == '{') || (re == '['))//스택에 괄호가 남아있으면 틀린 것임
			k = -1;//틀렸다고 표시
	}
	if (k == -1)// 틀렸다는 표시를 해줬을때
		printf("Wrong_%d", count);//틀렸다 출력
	else//안했을때
		printf("OK_%d", count);//맞았다 출력
	free(stack);//할당 해제
	return 0;//함수 종료
}
