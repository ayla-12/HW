#include <stdio.h>
#include <malloc.h>

// �����ð��� ����� �ڵ带 �״�� Ȱ���մϴ�.
typedef int element; 
typedef struct ListNode { // ����ü ����
	element data;  // ��� �ȿ��� �����Ϳ�
	struct ListNode* link; // ����ų ��ũ�� �ֽ��ϴ�.
};

ListNode* insert_first(ListNode* head, element val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ��� ����
	p->data = val;
	p->link = head; // ���ο� ��尡 ������ head�� ����Ŵ
	head = p; // ���ο� ��尡 ���ο� head�� ��
	return head; // ���ο� head ��ȯ
}

ListNode* insert(ListNode* head, ListNode* pre, element val) { // pre �ڿ� ���ο� ��� insert
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->link = pre->link; // ���ο� ��尡 ������ pre�� ����Ű�� ��带 ����Ŵ
	pre->link = p; // ������ pre�� ���ο� ��带 ����Ŵ
	return head; // head ��ȯ
}

void print_list(ListNode* head) { // head���� ��ũ�� ����� ����� data�� ��� ���
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%3d ->", p->data); // �ݺ����� ���鼭 ���Ŀ� ���� ���ڰ� ����ݴϴ�.
	}
	printf(" NULL\n");
}

ListNode* insert_sort(ListNode* head, int num) {
	
	//num�� �̹� ����Ʈ�� ����ִ� data�� ���Ͽ� ���ǹ��� Ȱ���� �Լ��� ����ϴ�.
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	for (p = head; p != NULL; p = p->link) { // p�� ����Ű�°� ���� ��, ���� ����Ʈ�� ���� ��, �� ����Ʈ�� ������ �ݺ��մϴ�.
		// ����Ʈ�� ������ �ͼ� ���̻� ���� ���� ���� ���� ���� �� �Ʒ��� �ڵ尡 ����˴ϴ�.
		if (num <= p->data && p->link == NULL) {	// ������ ���� num���� ������,
			head = insert_first(head, num);		// ������ ���� �տ� �����ֽ��ϴ�.
			break;
		}
		else if (num >= p->data && p->link == NULL) {	// �ݴ�� ������ ���� num���� ũ��,
			head = insert(head, p, num); // num�� ������ �� ������ �����ֽ��ϴ�.
			break;
		}
		// �ڵ� ������ ���� �ʰ� �߰��� �������� ��쿡�� �Ʒ��� �ڵ尡 ����˴ϴ�.
		else if (num >= p->data && num <= p->link->data) { //�Ѱܹ��� num ���� p�� �����ͺ��� ũ�� p�� ���� ����Ʈ�� ������ ���� ���� ��,
			head = insert(head, p, num); // num�� ���� �߰��� �����־��ݴϴ�.
			break; // ���� �־����� ����Ʈ ������ �� �ʿ䰡 �����Ƿ� break�� ���� �ݺ����� ���������ݴϴ�.
		}
	}

	return head;
}

void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
	printf("=====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 2071060\n");
	printf("�̸�: �谡��\n");
	printf("=====================\n\n");
	return;
}


int main(void) {
	my_name(); //�̸� ���

	ListNode* head = NULL; // ��� ������ ���� ��� �����͸� �������ݴϴ�.
	int num; // �Է°��� ���� ������ ���� num�� �������ݴϴ�.
	
	printf("Input data to insert to linkedlist<0 to quit>\n");
	// ù ��� ������ ���� ���� �޾� insert_first �Լ��� ��带 ������ݴϴ�.
	scanf("%d", &num);
	head = insert_first(head, num);
	print_list(head); // ù ��� ���� �� ����Ʈ ����ϱ�

	while (1) { // break�� ������ ������ �������� �ݺ��ϴ� �ݺ����� ������ݴϴ�.
		scanf("%d", &num); //�Է°��� num�� �������ݴϴ�.
		if (num == 0) { // ���࿡ num�� 0�̶��,
			print_list(head);  break; // ���� ����Ʈ�� ��� ����ϰ� �ݺ����� �����մϴ�.
		}
		head = insert_sort(head, num); // num�� 0�� �ƴϸ� ���� ���� insert_sort�� ���ڷ� �Ѱ� ����Ʈ�� �����մϴ�.
		print_list(head); // sort�� ���� ����Ʈ�� ����մϴ�.
	}
	printf("Program finished.");

	return 0;
}