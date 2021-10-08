#include <stdio.h>
#include <stdlib.h>

// �����ð��� ����� �ڵ带 Ȱ���մϴ�.
typedef int element;
typedef struct dListNode { // ���߿��� ��屸��
	element data;  // ��� �ȿ��� �����Ϳ�
	struct dListNode* Llink; // left link
	struct dListNode* Rlink; // Right link �� �ֽ��ϴ�.
}dListNode;

void init(dListNode* phead) { // ���߿��Ḯ��Ʈ head�� �ʱ�ȭ �մϴ�.
	phead->Rlink = phead;
	phead->Llink = phead;
}

void dinsert(dListNode* head, element val) { // ���ο� �����͸� ��������� �����ʿ� insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); // ���ο� ��� ����
	newnode->data = val; // val�� ���ο� ��尡 ����Ű�� ������ ������ ����
	head->Rlink->Llink = newnode; // ���� head�� ���� ����� Llink�� �ű� ��带 ����Ŵ
	newnode -> Llink = head; // �űԳ���� Llink�� head�� ����Ŵ
	newnode->Rlink = head->Rlink; // �űԳ���� Rlink�� ���� head�� Rlink�� ����Ű�� ��尡 ��
	head->Rlink = newnode; // head�� Rlink�� �ű� ��带 ����Ŵ
}

void ddelete(dListNode* head, dListNode* removed) {
	if (removed == head) return; // ���� ����� Ư�� ��尡 ����� �����մϴ�.
 	removed->Rlink->Llink = removed->Llink; // Ư�� ����� �����ʿ� �ִ� ��尡 ����Ű�� ���� ���, �� Ư�� ��带 ����Ű�� �ִ� ��θ� Ư������� �������� �ٲپ��ݴϴ�.
	removed->Llink->Rlink = removed->Rlink; // Ư�� ����� ���ʿ� �ִ� ��尡 ����Ű�� ������ ���, �� Ư�� ��带 ����Ű�� �ִ� ��θ� Ư������� ���������� �ٲپ��ݴϴ�.
	// ��<->��<->�� ���⼭ Ư�� ����� ���� �����ϰ� ��<-(>��<)->�� �̷������� ������شٴ� ��
	free(removed); // Ư�� ����� �޸� �Ҵ��� �������ݴϴ�.
}

dListNode* search_list(dListNode* head, element val) { // ���� ����Ʈ���� val�� ã���ϴ�. �̴� �ܼ� ���Ḯ��Ʈ�� ���������� ���������� �˻��ϴ� ���� ȿ�����Դϴ�.
	dListNode* p = NULL;
	p = head; // ��� ������ p�� �����մϴ�.
	do {
		if (p->Rlink->data == val) return p->Rlink; // ���� p�� ����Ű�� ����� ������ ����� �����Ͱ� ã�� val�� ���ٸ�, p�� ����Ű�� ������ �ּҸ� �����մϴ�.
		p = p->Rlink; // �ƴ϶�� ���������� �Űܰ��ϴ�.
	} while (p != head); // �� �ݺ����� �ѹ��� �������� ��ӵ˴ϴ�. 
	return NULL; // ã�� �������� NULL ���� �����մϴ�.
}

void print_dlist(dListNode* phead) { // ������Ʈ�� ����Ʈ�ϴ� �Լ��Դϴ�.
	dListNode* p = NULL;
	for (p = phead->Rlink; p != phead; p = p->Rlink) { //p�� phead�� �ƴҶ����� �ݺ��մϴ�.
		printf("%3d", p->data); // ��ĭ�� data�� �ҷ��� ������ݴϴ�.
	}
	printf("\n");
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

	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); // �����Ҵ��մϴ�.
	init(head); // �ʱ�ȭ �մϴ�.
	int num; // ���� ���� ������ ���� ���� num�� �����մϴ�.

	while (1) { // break�� ������������ ���� �ݺ��ϴ� while���Դϴ�.
		printf("Input an integer to add<0 to quit>: ");
		scanf("%d", &num);
		if (num == 0) break; // ���� num�� 0�� ������ while���� ���������ϴ�.

		dinsert(head, num); //�ƴ϶��, ���� ���� ���Ḯ��Ʈ�� ��带 ����ϴ�.
	}
	printf("<LIST>\n"); // while������ ���������� ����Ʈ�� ����մϴ�.
	print_dlist(head);
	printf("Input a number to search and delete: ");  // �Էµ� ����Ʈ���� ���� ã���ϴ�.
	scanf("%d", &num); // ���̻� ����Ʈ�� �Էµ� �ʿ䰡 ������ num ������ ��Ȱ���մϴ�.

	if (search_list(head, num) == NULL) { // ���࿡ null���� ��ȯ�ߴٸ� ã�� ���ߴٴ� ���̴�,
		printf("%d is not in the list\n", num); // ã�� ���ߴٴ� ������ ������ݴϴ�.
	}
	else {
		ddelete(head, search_list(head, num)); //�װ��� �ƴ϶�� ã�Ҵٴ� ���̴� ���ϵ� �ּҰ��� �ٷ� ddelete �Լ��� �־�
		printf("%d is found and deleted\n", num); // ���ϴ� ���� �����ݴϴ�.
	}
	printf("<LIST>\n"); // �׸��� ���������� ����Ʈ�� ����մϴ�.
	print_dlist(head);
}