#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 // �ִ� ���� ũ��


// �����ð��� ����� �ڵ带 �״�� Ȱ���մϴ�.
typedef int element;
typedef struct StackNode { // ���� ��� ����ü
	element data;
	struct StackNode* link; 
}StackNode;

typedef struct LinkedStackType {
	StackNode* top; // ���� top ����ּ�
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL; // �ʱ⿡�� �� ����
}

void error(const char X[]) { // ���� �޽��� ���
	fprintf(stderr, X);
}

bool is_full(LinkedStackType* s) {
	return 0; // full�� �� �� ����
}

bool is_empty(LinkedStackType* s) {
	return (s->top == NULL); // top�� NULL�̸�, ���� true�� ��ȯ
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) { //���࿡ ���������,
		error("Stack empty"); // ����ִٴ� �������� ������ݴϴ�.
		exit(1);
	}
	else {
		StackNode* temp = s->top; // ������ temp�� ������ ��带 ����Ŵ
		element data = temp->data; // ��ȯ�� ���� ����
		s->top = s->top->link; // top�� ����Ű�� ���Ұ� ����Ű�� link�� ���ο� top�� ��
		free(temp); // ������ ��尡 ����ϴ� �޸� ��ȯ
		return data; // top�� ������ ����Ű�� ���Ұ� ��ȯ
	}
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); // ���� �߰��� ��� ����
	temp->data = item; // ������ ����
	temp->link = s->top; // ���� ������ ����� link�� ������ top�� ����Ŵ
	s->top = temp; // ���� ������ ��尡 ���ο� top �� ��
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
	my_name(); // �̸� ��� �Լ��� ȣ���մϴ�.
	int myInput = 0; // �Է¹��� �������� �����ϴ� ���� ���� myInput�� �����մϴ�.

	LinkedStackType s; // ��� ����ü ����
	init(&s); // �ʱ�ȭ���ݴϴ�.

	while (1) {
		printf("������ �Է�<���� : 0 ���� �Է�>\n");
		scanf("%d", &myInput); 
		if (myInput == 0) break; // ���� �Էµ� ���� 0�̶�� ��� while���� �����մϴ�.
		else { // �Էµ� ���� 0�� �ƴ϶�� �Ʒ��� �ڵ带 �����մϴ�.
			while (myInput>1) {  // myInput�� 1���� Ŭ �� �Ʒ��� �ڵ带 �ݺ��մϴ�.
				push(&s,myInput % 2); // ���ο� ��带 �����Ͽ� 2�� ���� �������� push�մϴ�.
				myInput /= 2; // 2�� ���� ���� myInput�� �����մϴ�. ���� myInput�� 0�̳� 1�� ������ �� �ݺ����� ����˴ϴ�.
			}
			printf("������ ǥ��:"); 
			printf("%d", myInput); // ������ ���� push���� �ʾ����Ƿ� ����ϴ� �ڵ带 �־��ݴϴ�.
			while (!is_empty(&s)) { // ��尡 ���� �ʾ��� ������
				printf("%d",pop(&s)); // pop�ؼ� ����մϴ�.
			}
			printf("\n\n");
		}
	}

	return 0;
}