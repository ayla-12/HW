#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 // �ִ� ���� ũ��


// �����ð��� ����� �ڵ带 �״�� Ȱ���մϴ�.
typedef int element;
typedef struct StckType {
	element data[MAX_STACK_SIZE];  // �迭�� ��Ҵ� element Ÿ��
	int top; // top ���� ����� ������ (����Ʈ�� head�� �����...)
}StackType;

void init_stack(StackType* s) { // ���ڷμ� ����ü �����͸� ���޹���
	s->top = -1; // ó�� top�� -1��
}

void error(const char X[]) { // ���� �޽��� ���
	fprintf(stderr, X);
}

bool is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1)); // top�� �ִ� ���� ũ�⺸�� -1�� ��(�迭�� 0���� �����ϹǷ�), top�� �ִ밡 �ȴ�. �׷��� �� á�ٴ� ������ true�� ��ȯ�Ѵ�.
}

bool is_empty(StackType* s) {
	return (s->top == -1); // top�� -1�̸�, �� ������ ��������� ����ִٴ� ������ true�� ��ȯ�Ѵ�.
}

element pop(StackType* s) {
	if (is_empty(s)) { //���࿡ ���������,
		error("Stack empty"); // ����ִٴ� �������� ������ݴϴ�.
		exit(1);
	}
	else return s->data[(s->top)--]; // ������� �ʴٸ� top�� ����Ű�� ���Ұ� ��ȯ �� top ��ġ�� �����մϴ�.(top--)
}

void push(StackType* s, element item) {
	if (is_full(s)) { // ���࿡ ����������,
		error("Overflow"); // �����÷ο� �������� ������ݴϴ�. 
		return;
	}
	else s->data[++(s->top)] = item; // �׷��� �ʴٸ� top�� 1 ������ �� �ش� ��ġ�� ���Ұ��� �����մϴ�.
}


void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
	printf("=====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 2071060\n");
	printf("�̸�: �谡��\n");
	printf("=====================\n\n");
	return;
}

void use_array(char str[]) { // �迭�� �̿��ϴ� �Լ��� ������ݴϴ�.
	int i = 0;
	while (1) {
		int num = strlen(str); // ���ڿ��� ���̸� num ���� ������ �����մϴ�.
		if (str[i] != str[num-1-i]) { // �迭 ĭ�� 0���� �����ϹǷ�, i�� num-1-i�� ���Ͽ� ¦�� �´��� �ƴ��� Ȯ���մϴ�.
			printf("���Ī<�迭>\n"); // ���� �ٸ��ٸ� �� ��� ���Ī�̶�� ����ϰ�
			return; // �Լ��� �����մϴ�.
		}
		i++;  // �ٸ��� �ʴٸ� i�� 1�� �߰��Ͽ� �˻縦 ����մϴ�.
		if (i == num-1) break; // ���� i�� num-1�� �������ٸ�, �� �˻簡 ������ ����Ǹ� while�� �������ɴϴ�.
	}
	printf("��Ī<�迭>\n"); // while�� ���������� �������Դٴ� ���� ��Ī�̶�� ���̹Ƿ� ��Ī�̶�� ������ ������ݴϴ�.
}

void use_stack(char str[]) { // ������ �̿��ϴ� �Լ��� ������ݴϴ�.
	StackType s; // ����ü ����
	init_stack(&s); // ����ü�� �ʱ�ȭ ���ݴϴ�.
	int num = strlen(str); // ���� ���� num�� ���ڿ��� ���̸� �����մϴ�.
	for (int i = 0; i < num; i++) {		// ���ڿ��� ���̸�ŭ for �ݺ����� �ݺ��մϴ�.
		if (i < num / 2) // num/2�� ���� ���ڿ��� �������� i�� ������
			push(&s, str[i]);		// �����ߴ� ���� ����ü�� ���ʴ�� �׽��ϴ�.
		else { // ���ڿ��� �������� i�� ũ��, pop�� ���� ���ÿ��� ���ڸ� ������ �񱳸� �ϱ� �����մϴ�.
			if (i == num / 2 && num % 2 == 1)		// ���� ���ڿ��� ���̰� Ȧ����� ����� �ִ� ���� �Ѱܾ��ϹǷ� Ȧ���̰� num/2�� i�� ���ٸ� continue���ݴϴ�.
				continue;
			if (pop(&s) != str[i]) {		//pop�� ���� ���ÿ��� ���ڸ� ��������, ���ڿ��� �������� ū i�� �迭 ��ȣ�� �־� �� ��ġ�� �ִ� ���ڸ� ������ ���մϴ�. 
				printf("���Ī<����>\n"); // ���� �ٸ��ٸ� �� ��� ���Ī�̶�� ����ϰ�
				return; // �Լ��� �����մϴ�.
			}
		}
	}
	printf("��Ī<����>\n"); // for�� ���������� �������Դٴ� ���� ��Ī�̶�� ���̹Ƿ� ��Ī�̶�� ������ ������ݴϴ�.
}

int main(void) {
	my_name(); //�̸� ���
	char string[MAX_STACK_SIZE] = { 0 }; // �ִ� ���� ũ�⸸ŭ string �迭�� �����ϰ� �ʱ�ȭ���ݴϴ�.

	while (1) { // while�� ���� ���� �ݺ����� ������ݴϴ�.
		printf("\n���ĺ����� ������ ���ڿ� �Է�\n"); 
		scanf("%s", string);
		if (string[0] == '0' && strlen(string) == 1) break; // ���� ���� ���ڰ� 0�̶�� �� ��� while�� ���������ϴ�.
		else { // 0�� �ƴ϶�� �Ʒ��� �ڵ带 ���� �Լ��� ȣ���Ͽ� �˻縦 �����մϴ�.
			use_array(string);
			use_stack(string);
		}

		// if�� ������ ���� 0���� �����ϴ� ���ڿ��� ������ ��� �����ϰ� �Ǵ� ������ ������ ���ĺ����� ������ ���ڿ��� �Է��ϱ⶧���� ������ �� �����ϴ�.
		// ���� ���� �� �����Ѵٸ� if (string[0] == '0' && strlen(string) == 1) �̷������� ���ڿ� ���̰� 1�̰� 0�� ���Դٰ� �ϸ� 01210 �̷� ���ڿ��� �Է��Ѵ뵵 ������� �ʽ��ϴ�.
	}
	return 0;
}
