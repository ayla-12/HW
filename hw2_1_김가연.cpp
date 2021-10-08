#include <stdio.h>
#include <malloc.h>

// 수업시간에 배웠던 코드를 그대로 활용합니다.
typedef int element; 
typedef struct ListNode { // 구조체 정의
	element data;  // 노드 안에는 데이터와
	struct ListNode* link; // 가리킬 링크가 있습니다.
};

ListNode* insert_first(ListNode* head, element val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
	p->data = val;
	p->link = head; // 새로운 노드가 기존의 head를 가리킴
	head = p; // 새로운 노드가 새로운 head가 됨
	return head; // 새로운 head 반환
}

ListNode* insert(ListNode* head, ListNode* pre, element val) { // pre 뒤에 새로운 노드 insert
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->link = pre->link; // 새로운 노드가 기존의 pre가 가리키던 노드를 가리킴
	pre->link = p; // 기존의 pre는 새로운 노드를 가리킴
	return head; // head 반환
}

void print_list(ListNode* head) { // head부터 링크로 연결된 노드의 data를 계속 출력
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%3d ->", p->data); // 반복문을 돌면서 형식에 맞춰 예쁘게 찍어줍니다.
	}
	printf(" NULL\n");
}

ListNode* insert_sort(ListNode* head, int num) {
	
	//num과 이미 리스트에 들어있는 data를 비교하여 조건문을 활용해 함수를 만듭니다.
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	for (p = head; p != NULL; p = p->link) { // p가 가리키는게 없을 때, 다음 리스트가 없을 때, 즉 리스트의 끝까지 반복합니다.
		// 리스트의 끝까지 와서 더이상 다음 값을 비교할 수가 없을 때 아래의 코드가 적용됩니다.
		if (num <= p->data && p->link == NULL) {	// 마지막 값이 num보다 작으면,
			head = insert_first(head, num);		// 마지막 값의 앞에 끼워넣습니다.
			break;
		}
		else if (num >= p->data && p->link == NULL) {	// 반대로 마지막 값이 num보다 크면,
			head = insert(head, p, num); // num을 마지막 값 다음에 끼워넣습니다.
			break;
		}
		// 코드 끝까지 가지 않고 중간에 끼워지는 경우에는 아래의 코드가 적용됩니다.
		else if (num >= p->data && num <= p->link->data) { //넘겨받은 num 값이 p의 데이터보다 크고 p의 다음 리스트의 데이터 보다 작을 때,
			head = insert(head, p, num); // num의 값을 중간에 끼워넣어줍니다.
			break; // 끼워 넣었으니 리스트 끝까지 갈 필요가 없으므로 break를 통해 반복문을 빠져나와줍니다.
		}
	}

	return head;
}

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}


int main(void) {
	my_name(); //이름 출력

	ListNode* head = NULL; // 노드 생성을 위해 헤드 포인터를 선언해줍니다.
	int num; // 입력값을 받을 변수인 정수 num을 선언해줍니다.
	
	printf("Input data to insert to linkedlist<0 to quit>\n");
	// 첫 노드 생성을 위해 값을 받아 insert_first 함수로 노드를 만들어줍니다.
	scanf("%d", &num);
	head = insert_first(head, num);
	print_list(head); // 첫 노드 생성 후 리스트 출력하기

	while (1) { // break를 만나기 전까지 무한으로 반복하는 반복문을 만들어줍니다.
		scanf("%d", &num); //입력값을 num에 저장해줍니다.
		if (num == 0) { // 만약에 num이 0이라면,
			print_list(head);  break; // 현재 리스트를 모두 출력하고 반복문을 종료합니다.
		}
		head = insert_sort(head, num); // num이 0이 아니면 받은 값을 insert_sort의 인자로 넘겨 리스트를 생성합니다.
		print_list(head); // sort가 끝난 리스트를 출력합니다.
	}
	printf("Program finished.");

	return 0;
}