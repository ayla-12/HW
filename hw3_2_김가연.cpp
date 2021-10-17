#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// �����ð��� ��� �ڵ带 Ȱ���մϴ�.
typedef int element; 
typedef struct QueueType { // ť ����ü ����
	int front; // front ������
	int rear; // rear ����
	element data[MAX_QUEUE_SIZE]; // �׸��� ������ ������ �����ϰ� �ֽ��ϴ�.
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message); // ������ ����ϴ� �Լ�
}

void init_queue(QueueType* q) { // queue �ʱ�ȭ
	q->front = 0;
	q->rear = 0;
}

bool is_full(QueueType* q) { 
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // rear�� ������Ų ���� front�� ������ full
}

bool is_empty(QueueType* q) {
	return(q->front == q->rear); // front�� rear�� ������ empty
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) error("queue is full"); // ���� ť�� ��á�ٸ�, �� is_full�κ��� true�� ��ȯ�޾Ҵٸ� �������� ����մϴ�.
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ť�� ������ �ʾҴٸ� rear�� ������ŵ�ϴ�.
		q->data[q->rear] = item; // ������ rear ��ġ�� ���� �����մϴ�.
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("queue is empty"); // ���� ť�� ����ִٸ�, �� is_empty�κ��� true�� ��ȯ�޾Ҵٸ� �������� ����մϴ�.
		return NULL; 
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ť�� ������ �ʾҴٸ� front�� ������ŵ�ϴ�.
		return q->data[q->front]; // ������ front��ġ�� �ִ� ���� ��ȯ�մϴ�.
	}
}

void print_queue(QueueType* q) { // ť�� ����ϴ� �Լ�
	printf("Queue(front:%d, rear: %d) = ", q->front, q->rear); // front�� rear ��ġ�� ����մϴ�.
	if (!is_empty(q)) { // ť�� �����Ͱ� ������
		int i = q->front; // i�� ������ front���� �����ؼ�
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; // front+1���� ���(front�� ��������Ƿ�!)�մϴ�.
			printf("%3d |", q->data[i]);
			if (i == q->rear) break; // ������Ų ��ġ�� rear�� �����ϸ� ���� ����� ���̹Ƿ� �����մϴ�.
		} while (i != q->front); // �ִ� �ѹ����� ���Ƽ� front��ġ���� ���ƿ��� �����մϴ�.
	}
	printf("\n"); 
}

void print_count(QueueType* q) { // ����ť ���� ������ ������ ��ȯ�ϴ� �Լ�
	int count; // ���� ������ �����ϱ� ���� ���� ���� count�� �����մϴ�.
	if (q->front < q->rear) { // ���� front�� rear���� �۴ٸ�,
		count = (q->rear) - (q->front); // ����ִ� ������ rear���� front�� ����ŭ�Դϴ�.
	}
	else if(q->front > q->rear){ // ���� front�� rear���� ũ�ٸ�,
		count = (q->rear) - (q->front) + MAX_QUEUE_SIZE; // ����ִ� ������ rear���� front�� ����ŭ�� ť�� ũ�⸦ ���Ѹ�ŭ�Դϴ�.
	}
	else { // ���� front�� rear�� ���ٸ�,
		count = 0; // ť�� ����ִ� ���̹Ƿ� count�� 0�Դϴ�.
	}
	printf("���� ���� ������: %d\n", count); // ���� ������ ����Ʈ ���ݴϴ�.
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
	my_name();

	QueueType q; // ť ����ü ����
	init_queue(&q); // ť ����ü�� �ʱ�ȭ�մϴ�.
	char myInput; // �Է��� ���� ���� ������ �����մϴ�.

	while (1) { // break�� ������������ �ݺ��մϴ�.
		
		printf("\n���ϴ� �۾�<E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: "); 
		scanf("%c", &myInput);
		if (myInput == '0') break; // ���� �Է¹����� 0�̶�� while���� ���������ϴ�.
		else if (myInput == 'E' || myInput == 'e') { // E�� e��� enqueue�մϴ�.
			printf("�����Է�: ");
			int num;
			scanf("%d", &num);
			enqueue(&q, num);
		}
		else if (myInput == 'D' || myInput == 'd') { // D�� d��� dequeue�մϴ�.
			int dq = dequeue(&q); // dequeue�� ���� �����մϴ�.
			if (dq == NULL) {  // ���� ���ϵ� ���� null, �� ť�� ��������� ó������ ���ư��ϴ�.
				getchar(); // �Է��� ������ ������ �ް� ���ڵ� �ޱ⶧���� ���۸� �ʱ�ȭ�����ݴϴ�.
				continue;
			}
			else printf("%d\n",dq); // ���ϵ� ���� �������̶�� dequeue�� ���� ����մϴ�.
		}
		else if (myInput == 'P' || myInput == 'p') { // P�� p��� ť ���� ������ ����Ʈ�մϴ�.
			print_queue(&q);
		}
		else printf("Wrong Input\n"); // �̿��� �ٸ� ���� ������ �߸��� ���̶�� ������ ����մϴ�.

		getchar(); // �Է��� ������ ������ �ް� ���ڵ� �ޱ⶧���� ���۸� �ʱ�ȭ�����ݴϴ�.
	}

	print_count(&q); // while���� ���������� ���� �ִ� ������ ����մϴ�.
	print_queue(&q); // ���� ť�� ������ ����մϴ�.

	return 0; // �����մϴ�.
}