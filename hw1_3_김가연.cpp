#include <stdio.h>

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}

void func_recursive(char* a) {

	if (*a == 0) return; // 포인터가 가리키고 있는게 null, 즉 0이면 함수를 빠져나갑니다.
	else {
		func_recursive(a + 1); //0이 아니면 위치에 1을 더해서 다시 재귀함수를 호출해줍니다.
		printf("%c", *a); //현재 위치의 문자를 출력해줍니다.
		return;
	}
	// 문자열 끝을 만날때까지 func_recursive가 계속 호출되다가, null을 만나면 함수가 끝이나고 밖에 있던 printf문이 그제서야 실행됩니다.
	// 그러면 제일 끝에 문자부터 출력되고, 출력됨과 동시에 함수가 끝나므로 다음 밖에 있는 printf문이 실행되면서 뒤에서 두번째에 있는 글자가 출력되고...
	// 이런식으로 함수가 진행되어서 재귀함수로 문자열을 역순으로 출력할 수 있습니다.
}

int main() {
	my_name();
	char X[100]; // 사용할 배열을 선언해줍니다.
	printf("Input string\n");
	gets_s(X); // 배열 X에 문자열을 저장해줍니다.
	puts("변경전");
	puts(X); // 저장된 문자열 X를 불러와 출력해줍니다.
	puts("변경후");
	func_recursive(X); // 재귀함수를 호출하여 결과를 출력합니다.
	return 0;
}