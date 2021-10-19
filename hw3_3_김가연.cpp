#include <stdio.h>
#include <stdlib.h>

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}

typedef struct TreeNode { // 트리 노드 구조체 선언
	int data; // 데이터를 담는 공간과
	struct TreeNode* left, * right; // 왼쪽, 오른쪽 포인트 정보를 포함합니다.
}TreeNode;

void inorder(TreeNode* exp) { //inorder traversal을 통해 트리에 담긴 정보를 출력합니다.
	if (exp) {
		inorder(exp->left); // 왼쪽 서브트리 탐색
		printf(" [%d] ", exp->data);// 노드 방분
		inorder(exp->right); // 오른쪽 서브트리 탐색
	}
}

int get_node_count(TreeNode* exp) { // 노드 개수를 세는 함수
	if (exp == NULL) return 0; // 만약 exp가 NULL 이라면 0을 리턴합니다. (재귀함수의 종료조건)
	else
		return get_node_count(exp->left) + get_node_count(exp->right) + 1; // 아니라면 왼쪽 서브트리의 노드 개수 + 오른쪽 서브트리의 노드 개수 + 1을 리턴합니다.
}

int get_leaf_count(TreeNode* exp) { // 단말 노드 개수를 세는 함수
	if (exp == NULL) return 0; // 만약 exp가 NULL 이라면 0을 리턴합니다. (재귀함수의 종료조건)
	else {
		if (exp->left == NULL && exp->right == NULL) return 1; // exp가 NULL 이 아니고 단말노드라면 1을 리턴합니다.
		else return get_leaf_count(exp->left) + get_leaf_count(exp->right); // 비단말 노드라면 자식 노드의 리턴된 값을 더해서 리턴합니다.
	}
}

int get_height(TreeNode* exp) { // 높이를 구하는 함수
	if (exp == NULL) return 0; // exp가 NULL 이라면 0을 리턴합니다. (재귀함수의 종료조건)
	else {
		int l_height = get_height(exp->left); // 왼쪽 서브트리의 높이를 구해 지역변수에 저장합니다.
		int r_height = get_height(exp->right); // 오른쪽 서브트리의 높이를 구해 지역변수에 저장합니다.
		if (l_height >= r_height) return l_height + 1; // 만약 왼쪽이 오른쪽보다 높다면 왼쪽 서브트리의 높이 + 1을 리턴합니다.
		else return r_height + 1; //아니라면,즉 오른쪽이 왼쪽보다 높다면 오른쪽 서브트리의 높이 + 1을 리턴합니다.
	}
}

bool is_balanced(TreeNode* exp){ // balanced 트리인지를 판별하는 함수
	int l_height = get_height(exp->left); // 왼쪽 서브트리의 높이를 구해 지역변수에 저장합니다.
	int r_height = get_height(exp->right); // 오른쪽 서브트리의 높이를 구해 지역변수에 저장합니다.
	if (abs(l_height - r_height)<=1) return true; // 만약 왼쪽 서브트리와 오른쪽 서브트리의 차이(절대값을 활용)가 1 이하라면 true를 반환합니다.
	else return false; // 아니라면 false를 반환합니다.
}

void bigger_node(TreeNode* exp, int input) { // 입력 받은 값보다 큰 값을 출력하는 함수
	if (exp) { // 중위 탐색을 활용합니다.
		bigger_node(exp->left, input); 
		if (exp->data > input) printf(" %d", exp->data); // 만약 exp가 가리키는 데이터가 입력값보다 크다면 데이터를 출력해줍니다.
		bigger_node(exp->right, input);
	}
}
// 트리 구성
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { 15, &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL};
TreeNode n5 = { 25, NULL, NULL};
TreeNode n6 = { 7, &n4, &n5 };
TreeNode n7 = { 30, &n3, &n6};
TreeNode* exp = &n7;


int main() {
	int check_input; // 나중에 쓰일 지역변수를 선언합니다. 입력값을 저장하는 정수 변수입니다.
	my_name(); // 이름 출력

	inorder(exp); printf("\n"); // 중위 순회하며 트리에 있는 값을 출력합니다.
	printf("Number of nodes in tree: %d\n", get_node_count(exp));
	printf("Height of the tree: %d\n", get_height(exp));
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp));
	printf("Balanced tree? "); 
	if (is_balanced(exp)) printf("Yes\n"); else printf("No\n"); // 만약 is_balanced에서 받은 값이 true이면 Yes를 출력하고, false라면 No를 출력합니다.
	printf("Input a number to check: ");
	scanf("%d", &check_input); // check_input에 입력받은 값을 저장합니다.
	printf("numbers greater than %d: ", check_input); 
	bigger_node(exp,check_input); // 함수를 이용해 입력값보다 큰 값을 출력해줍니다.

	return 0;
}