#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 // 최대 스택 크기


// 수업시간에 배웠던 코드를 그대로 활용합니다.
typedef int element;
typedef struct StckType {
	element data[MAX_STACK_SIZE];  // 배열의 요소는 element 타입
	int top; // top 값을 멤버로 포함함 (리스트의 head와 비슷한...)
}StackType;

void init_stack(StackType* s) { // 인자로서 구조체 포인터를 전달받음
	s->top = -1; // 처음 top은 -1임
}

void error(const char X[]) { // 오류 메시지 출력
	fprintf(stderr, X);
}

bool is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1)); // top이 최대 스택 크기보다 -1일 때(배열은 0부터 시작하므로), top이 최대가 된다. 그러면 꽉 찼다는 뜻으로 true를 반환한다.
}

bool is_empty(StackType* s) {
	return (s->top == -1); // top이 -1이면, 즉 스택이 비어있으면 비어있다는 뜻으로 true를 반환한다.
}

element pop(StackType* s) {
	if (is_empty(s)) { //만약에 비어있으면,
		error("Stack empty"); // 비어있다는 에러문을 출력해줍니다.
		exit(1);
	}
	else return s->data[(s->top)--]; // 비어있지 않다면 top이 가리키는 원소값 반환 후 top 위치를 조정합니다.(top--)
}

void push(StackType* s, element item) {
	if (is_full(s)) { // 만약에 꽉차있으면,
		error("Overflow"); // 오버플로우 에러문을 출력해줍니다. 
		return;
	}
	else s->data[++(s->top)] = item; // 그렇지 않다면 top을 1 증가한 후 해당 위치에 원소값을 저장합니다.
}


void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}

void use_array(char str[]) { // 배열을 이용하는 함수를 만들어줍니다.
	int i = 0;
	while (1) {
		int num = strlen(str); // 문자열의 길이를 num 정수 변수에 저장합니다.
		if (str[i] != str[num-1-i]) { // 배열 칸은 0부터 시작하므로, i와 num-1-i를 비교하여 짝이 맞는지 아닌지 확인합니다.
			printf("비대칭<배열>\n"); // 만약 다르다면 그 즉시 비대칭이라고 출력하고
			return; // 함수를 종료합니다.
		}
		i++;  // 다르지 않다면 i에 1을 추가하여 검사를 계속합니다.
		if (i == num-1) break; // 만약 i가 num-1과 같아진다면, 즉 검사가 끝까지 진행되면 while을 빠져나옵니다.
	}
	printf("대칭<배열>\n"); // while을 정상적으로 빠져나왔다는 것은 대칭이라는 뜻이므로 대칭이라는 문장을 출력해줍니다.
}

void use_stack(char str[]) { // 스택을 이용하는 함수를 만들어줍니다.
	StackType s; // 구조체 선언
	init_stack(&s); // 구조체를 초기화 해줍니다.
	int num = strlen(str); // 정수 변수 num에 문자열의 길이를 저장합니다.
	for (int i = 0; i < num; i++) {		// 문자열의 길이만큼 for 반복문을 반복합니다.
		if (i < num / 2) // num/2를 통해 문자열의 반절보다 i가 작으면
			push(&s, str[i]);		// 선언했던 스택 구조체에 차례대로 쌓습니다.
		else { // 문자열의 반절보다 i가 크면, pop을 통해 스택에서 문자를 가져와 비교를 하기 시작합니다.
			if (i == num / 2 && num % 2 == 1)		// 만약 문자열의 길이가 홀수라면 가운데에 있는 수는 넘겨야하므로 홀수이고 num/2가 i와 같다면 continue해줍니다.
				continue;
			if (pop(&s) != str[i]) {		//pop을 토해 스택에서 문자를 가져오고, 문자열의 반절보다 큰 i를 배열 번호에 넣어 그 위치에 있는 문자를 가져와 비교합니다. 
				printf("비대칭<스택>\n"); // 만약 다르다면 그 즉시 비대칭이라고 출력하고
				return; // 함수를 종료합니다.
			}
		}
	}
	printf("대칭<스택>\n"); // for을 정상적으로 빠져나왔다는 것은 대칭이라는 뜻이므로 대칭이라는 문장을 출력해줍니다.
}

int main(void) {
	my_name(); //이름 출력
	char string[MAX_STACK_SIZE] = { 0 }; // 최대 스택 크기만큼 string 배열을 선언하고 초기화해줍니다.

	while (1) { // while을 통해 무한 반복문을 만들어줍니다.
		printf("\n알파벳으로 구성된 문자열 입력\n"); 
		scanf("%s", string);
		if (string[0] == '0' && strlen(string) == 1) break; // 만약 들어온 문자가 0이라면 그 즉시 while을 빠져나갑니다.
		else { // 0이 아니라면 아래의 코드를 통해 함수를 호출하여 검사를 진행합니다.
			use_array(string);
			use_stack(string);
		}

		// if를 저렇게 쓰면 0으로 시작하는 문자열이 들어왔을 경우 종료하게 되는 문제가 있지만 알파벳으로 구성된 문자열을 입력하기때문에 괜찮을 것 같습니다.
		// 만약 조금 더 보강한다면 if (string[0] == '0' && strlen(string) == 1) 이런식으로 문자열 길이가 1이고 0이 들어왔다고 하면 01210 이런 문자열을 입력한대도 종료되지 않습니다.
	}
	return 0;
}
