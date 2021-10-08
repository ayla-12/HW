#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueNode { // ť ��� ����ü ����
    element data; // ���� �����Ϳ�
    struct QueueNode* link; // ��ũ�� �̷�����ֽ��ϴ�.
}QueueNode;

typedef struct { 
    QueueNode* front, * rear; // front ���� rear ��带 �����մϴ�.
}LinkedQueueType;

void error(const char* message) { // ���� ����� ���ؼ� ���� �Լ��� ������ݴϴ�.
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(LinkedQueueType* q) { // ť�� �ʱ�ȭ �մϴ�.
    q->front = NULL;
    q->rear = NULL;
}
//is_full�� ���� �ʿ����� �ʾ� ���ݽ��ϴ�.
bool is_Empty(LinkedQueueType* q) { // ��ȣ�� ��ȣ��� �Ͽ� �Լ� �̸��� �ٲپ�����
    return (q->front == NULL); // front�� NULL�̸� ����ִٴ� ��!
}

void enqueue(LinkedQueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); // �� ��带 �����Ҵ�
    temp->data = item; // �����͸� ����
    temp->link = NULL; // ��ũ�� NULL
    if (is_Empty(q)) { // queue�� ��������� ���� �߰��� node�� front���� rear
        q->front = temp; // ���� q�� ����Ű�� front��
        q->rear = temp; // rear�� �Ѵ� temp�� �ٲ��ݴϴ�.
    }
    else {
        q->rear->link = temp; // ���� �߰��Ǵ°� �ƴ϶�� rear�� ����Ű�� ��ũ�� temp�� �ٲ��ְ�
        q->rear = temp; // ���� �߰��� node�� rear�� �ǰ� �մϴ�.
    }
}

element dequeue(LinkedQueueType* q) {
    if (is_Empty(q)) error("queue is empty");
    element data;
    QueueNode* temp = q->front; // ������ front�� ����Ű�� ��� ��ġ�� �����س���
    data = temp->data; // ������ front�� ����Ű�� ���� ��ȯ�ϱ� ���� ��� �����صӴϴ�.
    q->front = q->front->link; // ������ front�� ����Ű�� ���� ���ο� front�� �˴ϴ�.
    if (q->front == NULL) q->rear = NULL; // ��尡 �� �����ٸ� queue�� �������� ������ݴϴ�.
    free(temp); // ������ front ��忴�� ���� �޸𸮸� ��ȯ���ݴϴ� (�ʼ�!!!!)
    return data; // dequere �� ���� ��ȯ�մϴ�.
}

element peek(LinkedQueueType* q) { // ���� �������� �ʰ� ���⸸ �մϴ�.
    if (is_Empty(q)) error("queue is empty");
    return q->front->data; // front�� ����Ű�� �����͸� �����մϴ�.
}

void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
    printf("=====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 2071060\n");
    printf("�̸�: �谡��\n");
    printf("=====================\n\n");
    return;
}

int main() {
    my_name(); // �̸� ���

    int num=0; // ����ڷκ��� ���� �Է¹ޱ� ���� ���� ���� num�� �����մϴ�.
    element item;
    LinkedQueueType q; // ���Ḯ��Ʈ ��� �κ�
    init_queue(&q); // �ʱ�ȭ ���ݴϴ�.

    printf("Input a fibonicci location: ");
    scanf("%d", &num);

    for (int i = 0; i <= num ; i++) { // �ݺ����� ���� �Ǻ���ġ ������ ������ݴϴ�.
        if (i < 2) { // �ʱ��� 2��, 0�� 1�� �ٷ� enqueue �մϴ�.
            enqueue(&q, i);
            printf("%6d",i);
        }
        else { // �� ���� ����� ť�� ù��° ���� dequeue�ϰ�, �ι�° ���� peek�� �ؼ� ���ؼ� element ���� item�� �����մϴ�.
            item = dequeue(&q) + peek(&q);
            printf("%6d", item); // �׸��� �� item�� �ٷ� ������ݴϴ�.
            enqueue(&q, item); // enqueue�ؼ� queue�� �־��ݴϴ�.
        }
    } // �Է��� ���� num+1��ŭ �ݺ��մϴ�. (0�� F(0)���� ġ�Ƿ�)

    return 0;
}