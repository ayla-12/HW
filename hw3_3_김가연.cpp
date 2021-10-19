#include <stdio.h>
#include <stdlib.h>

void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
	printf("=====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 2071060\n");
	printf("�̸�: �谡��\n");
	printf("=====================\n\n");
	return;
}

typedef struct TreeNode { // Ʈ�� ��� ����ü ����
	int data; // �����͸� ��� ������
	struct TreeNode* left, * right; // ����, ������ ����Ʈ ������ �����մϴ�.
}TreeNode;

void inorder(TreeNode* exp) { //inorder traversal�� ���� Ʈ���� ��� ������ ����մϴ�.
	if (exp) {
		inorder(exp->left); // ���� ����Ʈ�� Ž��
		printf(" [%d] ", exp->data);// ��� ���
		inorder(exp->right); // ������ ����Ʈ�� Ž��
	}
}

int get_node_count(TreeNode* exp) { // ��� ������ ���� �Լ�
	if (exp == NULL) return 0; // ���� exp�� NULL �̶�� 0�� �����մϴ�. (����Լ��� ��������)
	else
		return get_node_count(exp->left) + get_node_count(exp->right) + 1; // �ƴ϶�� ���� ����Ʈ���� ��� ���� + ������ ����Ʈ���� ��� ���� + 1�� �����մϴ�.
}

int get_leaf_count(TreeNode* exp) { // �ܸ� ��� ������ ���� �Լ�
	if (exp == NULL) return 0; // ���� exp�� NULL �̶�� 0�� �����մϴ�. (����Լ��� ��������)
	else {
		if (exp->left == NULL && exp->right == NULL) return 1; // exp�� NULL �� �ƴϰ� �ܸ������ 1�� �����մϴ�.
		else return get_leaf_count(exp->left) + get_leaf_count(exp->right); // ��ܸ� ����� �ڽ� ����� ���ϵ� ���� ���ؼ� �����մϴ�.
	}
}

int get_height(TreeNode* exp) { // ���̸� ���ϴ� �Լ�
	if (exp == NULL) return 0; // exp�� NULL �̶�� 0�� �����մϴ�. (����Լ��� ��������)
	else {
		int l_height = get_height(exp->left); // ���� ����Ʈ���� ���̸� ���� ���������� �����մϴ�.
		int r_height = get_height(exp->right); // ������ ����Ʈ���� ���̸� ���� ���������� �����մϴ�.
		if (l_height >= r_height) return l_height + 1; // ���� ������ �����ʺ��� ���ٸ� ���� ����Ʈ���� ���� + 1�� �����մϴ�.
		else return r_height + 1; //�ƴ϶��,�� �������� ���ʺ��� ���ٸ� ������ ����Ʈ���� ���� + 1�� �����մϴ�.
	}
}

bool is_balanced(TreeNode* exp){ // balanced Ʈ�������� �Ǻ��ϴ� �Լ�
	int l_height = get_height(exp->left); // ���� ����Ʈ���� ���̸� ���� ���������� �����մϴ�.
	int r_height = get_height(exp->right); // ������ ����Ʈ���� ���̸� ���� ���������� �����մϴ�.
	if (abs(l_height - r_height)<=1) return true; // ���� ���� ����Ʈ���� ������ ����Ʈ���� ����(���밪�� Ȱ��)�� 1 ���϶�� true�� ��ȯ�մϴ�.
	else return false; // �ƴ϶�� false�� ��ȯ�մϴ�.
}

void bigger_node(TreeNode* exp, int input) { // �Է� ���� ������ ū ���� ����ϴ� �Լ�
	if (exp) { // ���� Ž���� Ȱ���մϴ�.
		bigger_node(exp->left, input); 
		if (exp->data > input) printf(" %d", exp->data); // ���� exp�� ����Ű�� �����Ͱ� �Է°����� ũ�ٸ� �����͸� ������ݴϴ�.
		bigger_node(exp->right, input);
	}
}
// Ʈ�� ����
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL};
TreeNode n5 = { 25, NULL, NULL};
TreeNode n6 = { 7, &n4, &n5 };
TreeNode n7 = { 30, &n3, &n6};
TreeNode* exp = &n7;


int main() {
	int check_input; // ���߿� ���� ���������� �����մϴ�. �Է°��� �����ϴ� ���� �����Դϴ�.
	my_name(); // �̸� ���

	inorder(exp); printf("\n"); // ���� ��ȸ�ϸ� Ʈ���� �ִ� ���� ����մϴ�.
	printf("Number of nodes in tree: %d\n", get_node_count(exp));
	printf("Height of the tree: %d\n", get_height(exp));
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp));
	printf("Balanced tree? "); 
	if (is_balanced(exp)) printf("Yes\n"); else printf("No\n"); // ���� is_balanced���� ���� ���� true�̸� Yes�� ����ϰ�, false��� No�� ����մϴ�.
	printf("Input a number to check: ");
	scanf("%d", &check_input); // check_input�� �Է¹��� ���� �����մϴ�.
	printf("numbers greater than %d: ", check_input); 
	bigger_node(exp,check_input); // �Լ��� �̿��� �Է°����� ū ���� ������ݴϴ�.

	return 0;
}