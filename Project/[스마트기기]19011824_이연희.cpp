#pragma warning(disable:4996)//경고무시
#include <stdio.h>//stdio헤더파일 포함
#include <string.h>//string 헤더파일 포함
#include <stdlib.h>//stdlib 헤더파일 포함
typedef struct rides {//놀이기구관련 구조체선언
	char *name; //놀이기구 이름
	char place[10];//놀이기구 영역
	int max_num;//놀이기구 가능탑승인원
	int time;//놀이기구 운행 시간
	int human;//현재 놀이기구를 기다리는 사람의 수
	int wait;//놀이기구를 기다려야하는 예상시간
	rides *prev;//연결리스트 연결 앞부분
	rides *next;//연결리스트 연결 뒷부분
}rides;//놀이기구 관련 이중 링크드리스트
rides *GO_Ride(rides **p) {//주소를 주는 함수선언
	(*p) = (rides *)malloc(sizeof(rides));//구조체 할당해줌
	(*p)->next = NULL;//기구 뒤에 NULL
	(*p)->prev = NULL;//기구 앞에 NULL
	return (*p);//주소값을 반환
}//괄호 닫음
double WAIT(int human, int max_num, int time) {//기다리는 시간을 자동으로 계산해주는 함수 선언
	double wait;//기다리는 시간 넣을 double형 변수 선언
	wait = (double)(human / max_num)*(time + 2);// time에 2분을 더한 것은 손님이 놀이기구를 내리고 타는데 걸리는 시간
	return wait;//기다리는 시간을 반환받음
}//괄호 닫음
void add(rides *r, int what) {//놀이기구를 추가해주는 함수 선언
	rides *p = GO_Ride(&p), *q;//놀이기구 추가해주는 rides형 선언
	char str[50];//기구 이름을 입력받을 char배열변수 선언
	if (what == 1)//what에 1이 입력되었을때
		strcpy(p->place, "European");//놀이기구 위치영역에 "European"넣기
	else if (what == 2)//what에 2이 입력되었을때
		strcpy(p->place, "American");//놀이기구 위치영역에  "American"넣기
	else if (what == 3)//what에 3이 입력되었을때
		strcpy(p->place, "MagicLand");//놀이기구 위치영역에 "MagicLand"넣기
	else//what에 4이 입력되었을때
		strcpy(p->place, "Zootopia");//놀이기구 위치영역에 "Zootopia"넣기
	printf("\n놀이기구 이름을 입력해주세요\n>>>");//추가할 놀이기구 이름 입력하라고 출력
	gets_s(str);//입력받기
	p->name = (char*)malloc((strlen(str) + 1) * sizeof(char));//p->name에 입력받은 놀이기구문자열+1 만큼 할당해줌
	strcpy(p->name, str);//p->name에 입력받은 문자열 카피
	printf("\n놀이기구 탑승가능인원, 운행 시간, 현재 기다리는 인원 수를 space바로 나누어 세가지를 순서대로 입력해주세요\n>>>");// 탑승인원,운행시간,현재인원수 입력하라고 출력
	scanf("%d %d %d", &(p->max_num), &(p->time), &(p->human));//각 숫자를 입력받기
	p->wait = WAIT(p->human, p->max_num, p->time);//WAIT함수를 호출해 자동으로 기다려야할 시간 계산
	printf("현재 기다려야하는 시간은 %d분 입니다.\n\n\n", p->wait);//기다려야할 시간 출력
	p->prev = r;//새로운 구조체의 앞부분에 알맞은 영역연결
	p->next = r->next;//새로운 구조체의 뒷부분에 영역연결
	r->next->prev = p;//영역의 앞에 새로운 구조체 연결
	r->next = p;//영역의 뒤에 새로운 구조체 연결
}//괄호닫음
void No_Ride(rides *r, char str[]) {//쉬는 놀이기구 연결을 끊어주는 함수 선언
	rides *p;//구조체 포인터 선언
	int o = 0;//이름이 있는지 확인하는 변수
	for (p = r->next;p->next != NULL;p = p->next) {//놀이기구 구조체를 쭈욱 훑어봄
		if (strcmp(str, p->name) == 0) {//이름과 일치하는 놀이기구가 있는 경우
			p->prev->next = p->next;//쉬는 놀이기구의 앞부분의 뒤를 쉬는 놀이기구의 뒤에 연결
			p->next->prev = p->prev;//쉬는 놀이기구의 뒷부분의 앞을 쉬는 놀이기구의 앞에 연결
			free(p);//연결 해지
			o = 1;//일치하는 놀이기구 있음
			printf("정상적으로 처리되었습니다.\n");//입력된 놀이기구가 정상적으로 쉼처리 되었음을 알림
			break;//반복문 종료
		}//괄호닫음
	}//괄호닫음
	if (o == 0)//이름이랑 일치하는 것이 없을때
		printf("등록되지 않은 놀이기구입니다\n");//등록되지않았다고 출력
}//괄호닫음
void print_ride(rides *r, char str[]) {//입력된 놀이기구 정보를 알려주는 함수
	rides *p;//구조체 포인터 선언
	int o = 0;//입력된 놀이기구가 운행하는지 판별하기위한 변수
	for (p = r->next;p->next != NULL;p = p->next) {//놀이기구 구조체를 쭈욱 훑어봄
		if (strcmp(str, p->name) == 0) {//입력된 이름과 일치하는 놀이기구가 운행하는 경우
			o = 1;//입력된 놀이기구가 운행함을 알림
			printf("놀이기구 이름 : %s\n놀이기구 영역 : %s\n최대 탑승인원 : %d\n예상대기시간 : %d분\n\n", p->name, p->place, p->max_num, p->wait);//놀이기구의 여러가지 정보를 출력
			break;//반복문 종료
		}//괄호닫음
	}//괄호닫음
	if (o == 0) {//입력된 놀이기구가 없을때
		printf("입력하신 놀이기구는 오늘 운행하지 않습니다. 죄송합니다.\n\n");//운행하지 않음을 알림
	}//괄호닫음
}//괄호닫음
void print_name(rides *r) {//오늘 운행하는 놀이기구 영역과 이름을 출력하는 함수
	rides *p;//놀이기구 구조체 포인터 선언
	printf("\n");//가독성을 위한 줄바꿈
	for (p = r->next;p->next != NULL;p = p->next) //놀이기구 구조체를 쭈욱 훑어봄
		printf("%s영역 %s\n", p->place, p->name);//어느영역 어느 놀이기구가 운행하는지 출력해줌
}//괄호닫음
void print_place(rides *r) {//현재 내위치에서 대기시간이 가장 짧은 놀이기구를 알려주는 함수
	rides *p, *q;//놀이기구 구조체 포인터 선언
	int o = 0, min;// 영역에 운행하는 놀이기구의 유무와 시간 변수를 선언
	printf("\n");//가독성을 위한 줄바꿈
	for (p = r->next, min = r->next->wait, q = r->next;p->next != NULL;p = p->next) {//놀이기구 구조체를 쭈욱 훑어봄
		if (min > p->wait) {//만약 min이 보다 짧은 분이 발견되면
			min = p->wait;//min에 대입
		}//괄호닫기
		o = 1;//운행하는 놀이기구가 있음을 알리는 변수
	}//괄호닫음
	for (p = r->next;p->next != NULL;p = p->next) {//놀이기구 구조체를 쭈욱 훑어봄
		if (min == p->wait)//만약 대기시간이 가장 짧을때
			printf("현재 %s영역에서 대기 시간이 가장 짧은 놀이기구는 %s로 약 %d분 기다릴 것으로 예상됩니다.\n", q->place, q->name, q->wait);//알림을 출력
	}//괄호닫음
	if (o == 0)//영역에 운행하는 놀이기구가 없을때,
		printf("현재 영역에서 운행하는 놀이기구가 없습니다.");//운행하는 놀이기구가 없음을 알림
}//괄호닫음
void add_VR(rides *r);//미리 VR놀이기구정보 입력해두는 함수 원형 선언
void add_Double_Rock_Spin(rides *r);//미리Double Rock Spin놀이기구정보 입력해두는 함수 원형 선언
void add_Lets_Twist(rides *r);//미리 Let's Twist놀이기구정보 입력해두는 함수 원형 선언
void add_Thunder_Falls(rides *r);//미리 Thunder Falls놀이기구정보 입력해두는 함수 원형 선언
void add_Panda_World(rides *r);//미리 Panda World놀이기구정보 입력해두는 함수 원형 선언
int main() {//메인함수 선언
	rides *H[4], *T[4];//그룹핑을 하기위해 헤드배열과 테일배열 선언
	char str[50];//문자열을 입력받는 배열
	int  identity;//에버랜드 손님인지 직원인지 알기위한 변수.
	int what;//손님이나 직원이 어떤 것을 실행할지를 받는 변수.
	int i;//정수형 변수 
	for (i = 0;i < 4;i++) {//헤드와 테일 배열 반복문으로 훑기
		GO_Ride(&H[i]);//할당해줌
		GO_Ride(&T[i]);//할당해줌
		H[i]->next = T[i];//헤드의 뒷부분을 테일에 연결
		T[i]->prev = H[i];//테일의 앞부분을 헤드에 연결
	}//괄호닫음
	add_VR(H[0]);//그룹핑한 H[0]을 European영역이라고 하고 미리 넣어둔 코드인 VR함수 호출
	add_Double_Rock_Spin(H[1]);//그룹핑한 H[1]을 American영역이라고 하고 미리 넣어둔 코드인 Double Rock Spin함수 호출
	add_Lets_Twist(H[1]);//그룹핑한 H[1]을 American영역이라고 하고 미리 넣어둔 코드인 Let's twist함수 호출
	add_Thunder_Falls(H[2]);//그룹핑한 H[2]을 MagicLand영역이라고 하고 미리 넣어둔 코드인 Thunder Falls함수 호출
	add_Panda_World(H[3]);//그룹핑한 H[3]을 Zootopia영역이라고 하고 미리 넣어둔 코드인 Panda World함수 호출
	while (1) {//break가 걸릴때 까지 반복함
		printf("\n***환상의 나라 에버랜드에 오신 것을 환영합니다***\n");//프로그램 처음 UI
		printf("손님이세요, 직원이세요?\n (직원이시면 0 을 손님이시면 1를 입력해주세요.)\n>>> ");//신분을 입력받는 코드
		scanf("%d", &identity);//신분에 1이나 0를 입력받음.
		if (identity == 0) {//만약 신분이 직원이면
			printf("\n 1.놀이기구 등록\n 2.놀이기구 휴무\n 3.프로그램 종료\n>>> ");//셋 중 하나를 고름
			scanf("%d", &what);//셋 중 하나를 입력
			if (what == 1) {//놀이기구 등록을 선택한 경우
				printf("\n어느영역의 놀이기구를 등록하시겠습니까?\n1.European\n2.American\n3.MagicLand\n4.Zootopia\n>>>");//영역 선택
				scanf("%d", &what);//영역선택
				getchar();//엔터받아줌
				add(H[what - 1], what);//영역의 그룹으로 놀이기구를 등록해주는 add함수 호출
				printf("\n프로그램을 종료하시겠습니까?\n 1. 예\n 2.아니요\n>>>");//프로그램 종료여부는 묻는 문구 출력
				scanf("%d", &what);//입력받음
				if (what == 1)//종료한다고 하면
					break;//반복문을 빠져나옴
			}//괄호닫음
			else if (what == 2) {//놀이기구 휴무를 선택한 경우
				printf("\n쉬는 놀이기구 영역 번호와 이름을 입력해주세요.\n1.European\n2.American\n3.MagicLand\n4.Zootopia\n>>> ");//영역선택
				scanf("%d", &what);//영역선택
				getchar();//엔터받아줌
				gets_s(str);//str문자열에 놀이기구 이름을 입력받음
				No_Ride(H[what - 1], str);//연결을 해제해주는 함수 호출
				printf("\n프로그램을 종료하시겠습니까?\n 1. 예\n 2.아니요\n>>>");//프로그램 종료여부는 묻는 문구 출력
				scanf("%d", &what);//입력받음
				if (what == 1)//종료한다고 하면
					break;//반복문을 빠져나옴
			}//괄호닫음
			else {//프로그램 종료를 입력한 경우
				printf("오늘도 수고하세요!\n");//종료를 알리는 문구 출력
				break;//반복문을 빠져나옴
			}//괄호닫음
		}//괄호닫음
		if (identity == 1) {//만약 신분이 손님이라면
			printf("\n에버랜드를 이용해주셔서 감사합니다.^^\n손님! 무엇을 도와드릴까요?\n");//손님에게 무엇이 궁금한지 질문
			printf(" 1.놀이기구에 대해 궁금해요!\n 2.오늘은 어떤 놀이기구가 운행하나요?\n 3.내 현재 영역에서 대기시간이 가장 짧은 놀이기구 추천해주세요!\n 4.아니요! 괜찮습니다.\n>>> ");//넷 중하나를 고름
			scanf("%d", &what);//넷 중 하나를 입력
			if (what == 1) {//놀이기구 한가지에 대해 궁금하다고 1을 누른경우
				printf("\n어느영역의 번호와 이름을 순서대로 입력해주세요.\n1.European\n2.American\n3.MagicLand\n4.Zootopia\n>>>");//영역묻기
				scanf("%d", &what);//현재 영역 입력받음
				getchar();//엔터받기
				gets_s(str);//문자열받기(놀이기구 이름)
				print_ride(H[what - 1], str);//놀이기구의 정보를 불러오는 함수 호출
				printf("\n프로그램을 종료하시겠습니까?\n 1. 예\n 2.아니요\n>>>");//프로그램 종료여부는 묻는 문구 출력
				scanf("%d", &what);//입력받음
				if (what == 1)//종료한다고 하면
					break;//반복문을 빠져나옴
			}//괄호닫음
			else if (what == 2) {//오늘 운행하는 놀이기구가 궁금하다고 2를 누른경우
				for (i = 0;i < 4;i++)//그룹핑 배열 훑기
					print_name(H[i]);//이름과 영역을 출력해주는 함수 호출
				printf("\n위와 같은 놀이기구가 운영됩니다.\n");//호출된 놀이기구가 운행된다고 출력
				printf("\n프로그램을 종료하시겠습니까?\n 1. 예\n 2.아니요\n>>>");//프로그램 종료여부는 묻는 문구 출력
				scanf("%d", &what);//입력받음
				if (what == 1)//종료한다고 하면
					break;//반복문을 빠져나옴
			}//괄호닫음
			else if (what == 3) {//현재 자신의 영역에서 대기시간이 가장짧은 놀이기구를 추천받고자 할때,
				printf("\n어느 영역에 있으세요?\n1.European\n2.American\n3.MagicLand\n4.Zootopia\n>>>");//영역을 입력받기
				scanf("%d", &what);//영역을 입력받음
				print_place(H[what - 1]);//추천해주는 함수를 호출
				printf("\n프로그램을 종료하시겠습니까?\n 1. 예\n 2.아니요\n>>>");//프로그램 종료여부는 묻는 문구 출력
				scanf("%d", &what);//입력받음
				if (what == 1)//종료한다고 하면
					break;//반복문을 빠져나옴
			}//괄호닫음
			else if (what == 4) {//프로그램 종료한다고 입력하면
				printf("\n이용해주셔서 감사합니다. 도움이 필요하시면 언제든지 불러주세요.\n행복한 하루 되세요^^\n");//프로그램을 종료하는 문구
				break;//반복문을 빠져나옴
			}//괄호닫음
		}//괄호닫음
	}//괄호닫음
	return 0;//0반환
}//괄호닫음
void add_VR(rides *r) {//VR을 추가해 주는 함수
	rides *p = GO_Ride(&p);//놀이기구를 할당해주는 함수 호출
	p->name = (char*)malloc(sizeof(char)*(strlen("VR") + 1));//놀이기구 이름문자열 +1 만큼 할당
	strcpy(p->name, "VR");//VR을 이름에 넣기
	strcpy(p->place, "European");//European을 영역에 넣기
	p->max_num = 36;//최대인원에 36명 넣기
	p->time = 5;//탑승 시간에 5분 넣기
	p->human = 400;//현재 기다리는 인원에 400명 넣기
	p->wait = WAIT(p->human, p->max_num, p->time);//자동으로 기다리는시간 부여
	p->prev = r;//만들어진 구조체의 앞부분에 영역에 알맞는 부분 연결
	p->next = r->next;//만들어진 구조체의 뒷부분에 영역에 알맞는 부분 연결
	r->next->prev = p;//영역의 원래 다음의 앞부분을 만들어진 구조체 연결
	r->next = p;//영역의 원래다음부분을 만들어진 구조체에 연결
}//괄호닫음
void add_Double_Rock_Spin(rides *r) {//Double Rock Spin 놀이기구를 추가해 주는 함수
	rides *p = GO_Ride(&p);//놀이기구를 할당해주는 함수 호출
	p->name = (char*)malloc(sizeof(char)*(strlen("Double Rock Spin") + 1));//놀이기구 이름 문자열 +1만큼 할당
	strcpy(p->name, "Double Rock Spin");//Double Rock Spin을 이름에 넣기
	strcpy(p->place, "American");//American을 영역에 넣기
	p->max_num = 38;//최대인원에 38명 넣기
	p->time = 2;//탑승 시간에 2분 넣기
	p->human = 400;//현재 기다리는 인원에 400명 넣기
	p->wait = WAIT(p->human, p->max_num, p->time);//자동으로 기다리는시간 부여
	p->prev = r;//만들어진 구조체의 앞부분에 영역에 알맞는 부분 연결
	p->next = r->next;//만들어진 구조체의 뒷부분에 영역에 알맞는 부분 연결
	r->next->prev = p;//영역의 원래 다음의 앞부분을 만들어진 구조체 연결
	r->next = p;//영역의 원래다음부분을 만들어진 구조체에 연결
}//괄호닫음
void add_Lets_Twist(rides *r) {//Let's Twist 놀이기구를 추가해 주는 함수
	rides *p = GO_Ride(&p);//놀이기구를 할당해주는 함수 호출
	p->name = (char*)malloc(sizeof(char)*(strlen("Let's Twist") + 1));//놀이기구 이름문자열+1만큼 할당
	strcpy(p->name, "Let's Twist");//Let's Twist을 이름에 넣기
	strcpy(p->place, "American");//American을 영역에 넣기
	p->max_num = 30;//최대인원에 30명 넣기
	p->time = 3;//탑승시간에 3분 넣기
	p->human = 500;//현재 기다리는 인원에 500명 넣기
	p->wait = WAIT(p->human, p->max_num, p->time);//자동으로 기다리는시간 부여
	p->prev = r;//만들어진 구조체의 앞부분에 영역에 알맞는 부분 연결
	p->next = r->next;//만들어진 구조체의 뒷부분에 영역에 알맞는 부분 연결
	r->next->prev = p;//영역의 원래 다음의 앞부분을 만들어진 구조체 연결
	r->next = p;//영역의 원래다음부분을 만들어진 구조체에 연결
}//괄호닫음
void add_Thunder_Falls(rides *r) {//Thunder Falls 놀이기구를 추가해 주는 함수
	rides *p = GO_Ride(&p);//놀이기구를 할당해주는 함수 호출
	p->name = (char*)malloc(sizeof(char)*(strlen("Thunder Falls") + 1));//놀이기구 이름문자열+1만큼 할당
	strcpy(p->name, "Thunder Falls");//Thunder Falls을 이름에 넣기
	strcpy(p->place, "MagicLand");//Magic Land을 영역에 넣기
	p->max_num = 8;//최대인원에 8명 넣기
	p->time = 2;//탑승시간에 2분 넣기
	p->human = 200;//현재 기다리는 인원에 200명 넣기
	p->wait = WAIT(p->human, p->max_num, p->time);//자동으로 기다리는시간 부여
	p->prev = r;//만들어진 구조체의 앞부분에 영역에 알맞는 부분 연결
	p->next = r->next;//만들어진 구조체의 뒷부분에 영역에 알맞는 부분 연결
	r->next->prev = p;//영역의 원래 다음의 앞부분을 만들어진 구조체 연결
	r->next = p;//영역의 원래다음부분을 만들어진 구조체에 연결
}//괄호닫음
void add_Panda_World(rides *r) {//Panda World 놀이기구를 추가해 주는 함수
	rides *p = GO_Ride(&p);//놀이기구를 할당해주는 함수 호출
	p->name = (char*)malloc(sizeof(char)*(strlen("Panda World") + 1));//놀이기구 이름문자열+1만큼 할당
	strcpy(p->name, "Panda World");//Panda World을 이름에 넣기
	strcpy(p->place, "Zootopia");//Zootopia을 영역에 넣기
	p->max_num = 100;//최대인원에 100명 넣기
	p->time = 10;//탑승시간에 10분 넣기
	p->human = 600;//현재 기다리는 인원에 600명 넣기
	p->wait = WAIT(p->human, p->max_num, p->time);//자동으로 기다리는시간 부여
	p->prev = r;//만들어진 구조체의 앞부분에 영역에 알맞는 부분 연결
	p->next = r->next;//만들어진 구조체의 뒷부분에 영역에 알맞는 부분 연결
	r->next->prev = p;//영역의 원래 다음의 앞부분을 만들어진 구조체 연결
	r->next = p;//영역의 원래다음부분을 만들어진 구조체에 연결
}//괄호닫음