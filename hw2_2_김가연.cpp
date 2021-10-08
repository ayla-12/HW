#include <stdio.h>
#include <stdlib.h>

// 수업시간에 배웠던 코드를 활용합니다.
typedef int element;
typedef struct dListNode { // 이중연결 노드구조
	element data;  // 노드 안에는 데이터와
	struct dListNode* Llink; // left link
	struct dListNode* Rlink; // Right link 가 있습니다.
}dListNode;

void init(dListNode* phead) { // 이중연결리스트 head를 초기화 합니다.
	phead->Rlink = phead;
	phead->Llink = phead;
}

void dinsert(dListNode* head, element val) { // 새로운 데이터를 기존노드의 오른쪽에 insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); // 새로운 노드 생성
	newnode->data = val; // val을 새로운 노드가 가리키는 데이터 영역에 복사
	head->Rlink->Llink = newnode; // 기존 head의 우측 노드의 Llink는 신규 노드를 가리킴
	newnode -> Llink = head; // 신규노드의 Llink가 head를 가리킴
	newnode->Rlink = head->Rlink; // 신규노드이 Rlink가 기존 head의 Rlink가 가리키던 노드가 됨
	head->Rlink = newnode; // head의 Rlink는 신규 노드를 가리킴
}

void ddelete(dListNode* head, dListNode* removed) {
	if (removed == head) return; // 만약 지우는 특정 노드가 헤드라면 리턴합니다.
 	removed->Rlink->Llink = removed->Llink; // 특정 노드의 오른쪽에 있는 노드가 가리키는 왼쪽 노드, 즉 특정 노드를 가리키고 있는 경로를 특정노드의 왼쪽으로 바꾸어줍니다.
	removed->Llink->Rlink = removed->Rlink; // 특정 노드의 왼쪽에 있는 노드가 가리키는 오른쪽 노드, 즉 특정 노드를 가리키고 있는 경로를 특정노드의 오른쪽으로 바꾸어줍니다.
	// ㅁ<->☆<->ㅁ 여기서 특정 노드인 ☆을 제외하고 ㅁ<-(>☆<)->ㅁ 이런식으로 만들어준다는 뜻
	free(removed); // 특정 노드의 메모리 할당을 해제해줍니다.
}

dListNode* search_list(dListNode* head, element val) { // 연결 리스트에서 val을 찾습니다. 이는 단순 연결리스트와 마찬가지로 순차적으로 검사하는 것이 효율적입니다.
	dListNode* p = NULL;
	p = head; // 헤드 정보를 p에 저장합니다.
	do {
		if (p->Rlink->data == val) return p->Rlink; // 만약 p가 가리키는 노드의 오른쪽 노드의 데이터가 찾는 val과 같다면, p가 가리키는 오른쪽 주소를 리턴합니다.
		p = p->Rlink; // 아니라면 오른쪽으로 옮겨갑니다.
	} while (p != head); // 이 반복문은 한바퀴 돌때까지 계속됩니다. 
	return NULL; // 찾지 못했으면 NULL 값을 리턴합니다.
}

void print_dlist(dListNode* phead) { // 더블리스트를 프린트하는 함수입니다.
	dListNode* p = NULL;
	for (p = phead->Rlink; p != phead; p = p->Rlink) { //p가 phead가 아닐때까지 반복합니다.
		printf("%3d", p->data); // 세칸씩 data를 불러와 출력해줍니다.
	}
	printf("\n");
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
	my_name();

	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); // 동적할당합니다.
	init(head); // 초기화 합니다.
	int num; // 값을 받을 변수인 정수 변수 num을 선언합니다.

	while (1) { // break을 만나기전까지 무한 반복하는 while문입니다.
		printf("Input an integer to add<0 to quit>: ");
		scanf("%d", &num);
		if (num == 0) break; // 만약 num에 0이 들어오면 while문을 빠져나갑니다.

		dinsert(head, num); //아니라면, 이중 원형 연결리스트에 노드를 만듭니다.
	}
	printf("<LIST>\n"); // while문에서 빠져나오면 리스트를 출력합니다.
	print_dlist(head);
	printf("Input a number to search and delete: ");  // 입력된 리스트에서 값을 찾습니다.
	scanf("%d", &num); // 더이상 리스트에 입력될 필요가 없으니 num 변수를 재활용합니다.

	if (search_list(head, num) == NULL) { // 만약에 null값을 반환했다면 찾지 못했다는 뜻이니,
		printf("%d is not in the list\n", num); // 찾지 못했다는 문장을 출력해줍니다.
	}
	else {
		ddelete(head, search_list(head, num)); //그것이 아니라면 찾았다는 뜻이니 리턴된 주소값을 바로 ddelete 함수에 넣어
		printf("%d is found and deleted\n", num); // 원하는 값을 지워줍니다.
	}
	printf("<LIST>\n"); // 그리고 마지막으로 리스트를 출력합니다.
	print_dlist(head);
}