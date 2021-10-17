#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// 수업시간에 배운 코드를 활용합니다.
typedef int element; 
typedef struct QueueType { // 큐 구조체 선언
	int front; // front 정보와
	int rear; // rear 정보
	element data[MAX_QUEUE_SIZE]; // 그리고 데이터 정보를 포함하고 있습니다.
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message); // 에러를 출력하는 함수
}

void init_queue(QueueType* q) { // queue 초기화
	q->front = 0;
	q->rear = 0;
}

bool is_full(QueueType* q) { 
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // rear를 증가시킨 값이 front와 같으면 full
}

bool is_empty(QueueType* q) {
	return(q->front == q->rear); // front와 rear가 같으면 empty
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) error("queue is full"); // 만약 큐가 꽉찼다면, 즉 is_full로부터 true를 반환받았다면 오류문을 출력합니다.
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 큐가 꽉차지 않았다면 rear를 증가시킵니다.
		q->data[q->rear] = item; // 증가된 rear 위치에 값을 대입합니다.
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("queue is empty"); // 만약 큐가 비어있다면, 즉 is_empty로부터 true를 반환받았다면 오류문을 출력합니다.
		return NULL; 
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 큐가 꽉차지 않았다면 front를 증가시킵니다.
		return q->data[q->front]; // 증가된 front위치에 있는 값을 반환합니다.
	}
}

void print_queue(QueueType* q) { // 큐를 출력하는 함수
	printf("Queue(front:%d, rear: %d) = ", q->front, q->rear); // front오 rear 위치를 출력합니다.
	if (!is_empty(q)) { // 큐에 데이터가 있으면
		int i = q->front; // i는 현재의 front부터 시작해서
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; // front+1부터 출력(front는 비어있으므로!)합니다.
			printf("%3d |", q->data[i]);
			if (i == q->rear) break; // 증가시킨 위치가 rear과 동일하면 전부 출력한 것이므로 종료합니다.
		} while (i != q->front); // 최대 한바퀴를 돌아서 front위치까지 돌아오면 종료합니다.
	}
	printf("\n"); 
}

void print_count(QueueType* q) { // 원형큐 내의 원소의 개수를 반환하는 함수
	int count; // 개수 정보를 저장하기 위한 정수 변수 count를 선언합니다.
	if (q->front < q->rear) { // 만약 front가 rear보다 작다면,
		count = (q->rear) - (q->front); // 들어있는 갯수는 rear에서 front를 뺀만큼입니다.
	}
	else if(q->front > q->rear){ // 만약 front가 rear보다 크다면,
		count = (q->rear) - (q->front) + MAX_QUEUE_SIZE; // 들어있는 갯수는 rear에서 front를 뺀만큼에 큐의 크기를 더한만큼입니다.
	}
	else { // 만약 front가 rear과 같다면,
		count = 0; // 큐가 비어있는 것이므로 count는 0입니다.
	}
	printf("현재 원소 갯수는: %d\n", count); // 원소 갯수를 프린트 해줍니다.
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
	my_name();

	QueueType q; // 큐 구조체 생성
	init_queue(&q); // 큐 구조체를 초기화합니다.
	char myInput; // 입력을 받을 문자 변수를 선언합니다.

	while (1) { // break을 만나기전까지 반복합니다.
		
		printf("\n원하는 작업<E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: "); 
		scanf("%c", &myInput);
		if (myInput == '0') break; // 만약 입력받은게 0이라면 while문을 빠져나갑니다.
		else if (myInput == 'E' || myInput == 'e') { // E나 e라면 enqueue합니다.
			printf("정수입력: ");
			int num;
			scanf("%d", &num);
			enqueue(&q, num);
		}
		else if (myInput == 'D' || myInput == 'd') { // D나 d라면 dequeue합니다.
			int dq = dequeue(&q); // dequeue한 값을 저장합니다.
			if (dq == NULL) {  // 만약 리턴된 값이 null, 즉 큐가 비어있으면 처음으로 돌아갑니다.
				getchar(); // 입력을 받을때 정수도 받고 문자도 받기때문에 버퍼를 초기화시켜줍니다.
				continue;
			}
			else printf("%d\n",dq); // 리턴된 값이 정상적이라면 dequeue한 값을 출력합니다.
		}
		else if (myInput == 'P' || myInput == 'p') { // P나 p라면 큐 안의 정보를 프린트합니다.
			print_queue(&q);
		}
		else printf("Wrong Input\n"); // 이외의 다른 값이 들어오면 잘못된 값이라는 오류를 출력합니다.

		getchar(); // 입력을 받을때 정수도 받고 문자도 받기때문에 버퍼를 초기화시켜줍니다.
	}

	print_count(&q); // while문을 빠져나오면 현재 있는 갯수를 출력합니다.
	print_queue(&q); // 현재 큐의 정보를 출력합니다.

	return 0; // 종료합니다.
}