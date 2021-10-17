#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 // 최대 스택 크기


// 수업시간에 배웠던 코드를 그대로 활용합니다.
typedef int element;
typedef struct StackNode { // 스택 노드 구조체
	element data;
	struct StackNode* link; 
}StackNode;

typedef struct LinkedStackType {
	StackNode* top; // 스택 top 노드주소
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL; // 초기에는 빈 스택
}

void error(const char X[]) { // 오류 메시지 출력
	fprintf(stderr, X);
}

bool is_full(LinkedStackType* s) {
	return 0; // full이 될 수 없음
}

bool is_empty(LinkedStackType* s) {
	return (s->top == NULL); // top이 NULL이면, 빈스택 true를 반환
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) { //만약에 비어있으면,
		error("Stack empty"); // 비어있다는 에러문을 출력해줍니다.
		exit(1);
	}
	else {
		StackNode* temp = s->top; // 포인터 temp가 삭제할 노드를 가리킴
		element data = temp->data; // 반환할 값을 저장
		s->top = s->top->link; // top이 가리키던 원소가 가리키는 link가 새로운 top이 됨
		free(temp); // 삭제된 노드가 사용하던 메모리 반환
		return data; // top이 기존에 가리키던 원소값 반환
	}
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); // 새로 추가할 노드 생성
	temp->data = item; // 데이터 저장
	temp->link = s->top; // 새로 생성된 노드의 link가 기존의 top을 가리킴
	s->top = temp; // 새로 생성된 노드가 새로운 top 이 됨
}

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}


int main() {
	my_name(); // 이름 출력 함수를 호출합니다.
	int myInput = 0; // 입력받은 십진수를 저장하는 정수 변수 myInput을 선언합니다.

	LinkedStackType s; // 노드 구조체 선언
	init(&s); // 초기화해줍니다.

	while (1) {
		printf("십진수 입력<종료 : 0 이하 입력>\n");
		scanf("%d", &myInput); 
		if (myInput == 0) break; // 만약 입력된 수가 0이라면 즉시 while문을 종료합니다.
		else { // 입력된 수가 0이 아니라면 아래의 코드를 실행합니다.
			while (myInput>1) {  // myInput이 1보다 클 때 아래의 코드를 반복합니다.
				push(&s,myInput % 2); // 새로운 노드를 생성하여 2로 나눈 나머지를 push합니다.
				myInput /= 2; // 2로 나눈 몫을 myInput에 저장합니다. 만약 myInput이 0이나 1이 나오면 이 반복문은 종료됩니다.
			}
			printf("이진수 표현:"); 
			printf("%d", myInput); // 마지막 몫은 push되지 않았으므로 출력하는 코드를 넣어줍니다.
			while (!is_empty(&s)) { // 노드가 비지 않았을 때까지
				printf("%d",pop(&s)); // pop해서 출력합니다.
			}
			printf("\n\n");
		}
	}

	return 0;
}