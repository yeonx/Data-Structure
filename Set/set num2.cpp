#pragma warning(disable:4996) //경고무시
#include <stdio.h> //stdio헤더파일 포함
#include <string.h> //string 헤더파일 포함
#include <stdlib.h> // stdlib 헤더파일 포함
typedef struct NODE {//NODE생성
	NODE *next;//NODE의 다음 NODE선언
	int num;//NODE의 정수형 num 선언
}NODE;//단일연결리스트 
void getNode(NODE **p) {//NODE할당함수선언
	(*p) = (NODE *)malloc(sizeof(NODE));//NODE할당
	(*p)->next = NULL;//할당한 NODE의 다음 NODE는 NULL
}//괄호닫음
void addNode(NODE *p) {//NODE더하는 함수선언
	NODE *tmp = NULL;//새로 생성할 NODE선언
	getNode(&tmp);//새로운 NODE에 할당
	scanf("%d", &(tmp->num));//num값 입력
	while (p->next != NULL)//위치찾아주는 반복문
		p = p->next;//다음이 NULL이 아니니 넘김
	p->next = tmp;//위치찾아서 새로운 NODE연결
}//괄호닫음
void CaddNode(NODE *p, int n) {//C에 추가해주는 함수
	NODE *tmp = NULL;//추가할 NODE선언
	getNode(&tmp);//NODE 할당
	tmp->num = n;//정수 넣어줌
	while (p->next != NULL)//자리찾아주는 반복문
		p = p->next;//다음이 NULL이 아니니까 넘김
	p->next = tmp;//위치찾아서 새로운 NODE연결
}//괄호닫음
NODE *Union(NODE *A, NODE *B) {//합집합 찾아주는 함수
	NODE *p = NULL, *q = NULL, *C = NULL;//반복문을 위한 p,q와 합집합반환을 위한 C NODE 선언
	getNode(&C);//NODE 할당
	for (p = A->next, q = B->next;p!=NULL||q!=NULL;) {//둘 다 NULL일 때 까지 반복 
		if (p== NULL) {//B에 아직 수가 남았다면
			CaddNode(C, q->num);//C NODE에 B의 수를 넣어줌
			q = q->next;//B를 다음을 넘김
		}//괄호닫음
		else if (q == NULL) {//A에 아직 수가 남았다면
			CaddNode(C, p->num);//C NODE에 A의 수를 넣어줌
			p = p->next;//A를 다음을 넘김
		}//괄호닫음
		else if (p->num < q->num) {//A집합의 수가 더 작을 때,
			CaddNode(C, p->num);//
			p = p->next;//A를 다음을 넘김
		}//괄호닫음
		else if (p->num > q->num) {//B집합의 수가 더 작을 때,
			CaddNode(C, q->num);//C NODE에 B의 수를 넣어줌
			q = q->next;//B를 다음을 넘김
		}//괄호닫음
		else if (p->num == q->num) {//같을 때
			CaddNode(C, p->num);//C NODE에 그 수를 넣어줌
			p = p->next;//A를 다음을 넘김
			q = q->next;//B를 다음을 넘김
		}//괄호닫음
	}//괄호닫음
	return C;//합집합 반환
}//괄호닫음
NODE *intersect(NODE *A, NODE *B) {//교집합 찾아주는 함수
	NODE *p = NULL, *q = NULL, *C = NULL;//반복문을 위한 p,q와 교집합 반환을 위한 C NODE 선언
	getNode(&C);//NODE 할당
	for (p = A->next;p != NULL;p = p->next) {//NODE A를 훑음
		for (q = B->next;q != NULL;q = q->next) {//NODE B를 훑음
			if (p->num == q->num) {// 두 수가 같으면
				CaddNode(C, p->num);//교집합에 넣어줌
				break;//반복문빠져나가기
			}//괄호닫음
		}//괄호닫음
	}//괄호닫음
	return C;//교집합 반환
}//괄호닫음
int main() {//메인함수 선언
	int nA, nB, i;//집합 A,B의 수와 반복문을 위한 i선언
	NODE *HA = NULL, *HB = NULL, *p = NULL;//집합 HA,HB 헤더와 반복문을 위한 p선언
	getNode(&HA);//HA에 할당
	getNode(&HB);//HB에 할당
	scanf("%d", &nA);//집합 A의 수 입력받기
	for (i = 0;i < nA;i++)//A의 수만큼
		addNode(HA);//함수 호출해서 집합에 넣어줌
	scanf("%d", &nB);//집합 B의 수 입력받기
	for (i = 0;i < nB;i++)//B의 수만큼
		addNode(HB);//함수 호출해서 집합에 넣어줌
	p = Union(HA, HB)->next;//p에 합집합 다음 NODE부터
	if (p == NULL)//아무것도 없으면
		printf(" 0");//0출력
	else {//있으면
		for (;p != NULL;p = p->next)//반복문으로
			printf(" %d", p->num);//수 출력
	}//괄호닫음
	printf("\n");//엔터
	p = intersect(HA, HB)->next;//p에 교집합 다음 NODE부터
	if (p == NULL)//아무것도 없으면
		printf(" 0\n");//0출력
	else {//있으면
		for (p = intersect(HA, HB)->next;p != NULL;p = p->next)//반복문으로
			printf(" %d", p->num);//수 출력
	}//괄호닫음
	return 0;//메인 함수 종료
}//괄호닫음
