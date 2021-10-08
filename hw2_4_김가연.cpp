#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueNode { // 큐 노드 구조체 선언
    element data; // 노드는 데이터와
    struct QueueNode* link; // 링크로 이루어져있습니다.
}QueueNode;

typedef struct { 
    QueueNode* front, * rear; // front 노드와 rear 노드를 저장합니다.
}LinkedQueueType;

void error(const char* message) { // 에러 출력을 위해서 에러 함수를 만들어줍니다.
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(LinkedQueueType* q) { // 큐를 초기화 합니다.
    q->front = NULL;
    q->rear = NULL;
}
//is_full은 굳이 필요하지 않아 없앴습니다.
bool is_Empty(LinkedQueueType* q) { // 모호한 기호라고 하여 함수 이름을 바꾸어줬음
    return (q->front == NULL); // front가 NULL이면 비어있다는 뜻!
}

void enqueue(LinkedQueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); // 새 노드를 동적할당
    temp->data = item; // 데이터를 저장
    temp->link = NULL; // 링크는 NULL
    if (is_Empty(q)) { // queue가 비어있으면 새로 추가된 node가 front이자 rear
        q->front = temp; // 따라서 q가 가리키는 front와
        q->rear = temp; // rear을 둘다 temp로 바꿔줍니다.
    }
    else {
        q->rear->link = temp; // 새로 추가되는게 아니라면 rear가 가리키는 링크를 temp로 바꿔주고
        q->rear = temp; // 새로 추가된 node가 rear가 되게 합니다.
    }
}

element dequeue(LinkedQueueType* q) {
    if (is_Empty(q)) error("queue is empty");
    element data;
    QueueNode* temp = q->front; // 기존의 front가 가리키던 노드 위치를 저장해놓고
    data = temp->data; // 기존의 front가 가리키던 값을 반환하기 위해 잠깐 저장해둡니다.
    q->front = q->front->link; // 기존의 front가 가리키던 노드는 새로운 front가 됩니다.
    if (q->front == NULL) q->rear = NULL; // 노드가 한 개였다면 queue를 공백으로 만들어줍니다.
    free(temp); // 기존의 front 노드였던 것은 메모리를 반환해줍니다 (필수!!!!)
    return data; // dequere 된 값을 반환합니다.
}

element peek(LinkedQueueType* q) { // 값을 제거하지 않고 보기만 합니다.
    if (is_Empty(q)) error("queue is empty");
    return q->front->data; // front가 가리키는 데이터를 리턴합니다.
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
    my_name(); // 이름 출력

    int num=0; // 사용자로부터 값을 입력받기 위해 정수 변수 num을 선언합니다.
    element item;
    LinkedQueueType q; // 연결리스트 헤드 부분
    init_queue(&q); // 초기화 해줍니다.

    printf("Input a fibonicci location: ");
    scanf("%d", &num);

    for (int i = 0; i <= num ; i++) { // 반복문을 통해 피보나치 수열을 출력해줍니다.
        if (i < 2) { // 초기의 2개, 0과 1은 바로 enqueue 합니다.
            enqueue(&q, i);
            printf("%6d",i);
        }
        else { // 그 이후 수라면 큐의 첫번째 수는 dequeue하고, 두번째 수는 peek만 해서 더해서 element 변수 item에 저장합니다.
            item = dequeue(&q) + peek(&q);
            printf("%6d", item); // 그리고 그 item을 바로 출력해줍니다.
            enqueue(&q, item); // enqueue해서 queue에 넣어줍니다.
        }
    } // 입력한 수인 num+1만큼 반복합니다. (0은 F(0)으로 치므로)

    return 0;
}