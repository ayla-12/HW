#include <stdio.h>
#define ROWS 4
#define COLS 3

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}

void matrixInput(int Arr[ROWS][COLS]) { // 2차원 배열을 인자로 받아줍니다.
	for (int i = 0; i < ROWS; i++) { // ROWS와 COLS에 따라서 구문을 반복하면서 각 칸에 입력받는 값을 넣어줍니다.
		for (int j = 0; j < COLS; j++) {
			scanf("%d", &Arr[i][j]); //scanf를 쓰기전에 꼭 SDL 해제를 해줍니다. 
		}
	}
	return;
}

void matrixPrint(int Arr[ROWS][COLS]) { // 2차원 배열을 인자로 받아줍니다.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) { // ROW와 COLS에 따라서 구문을 반복하면서 각 칸에 입력된 값을 출력해줍니다.
			printf("%3d", Arr[i][j]); // 출력을 할 때 칸을 맞추기 위해 %3d로 배열안의 정수를 찍어줍니다.
		}
		printf("\n"); // 한 행이 끝나면 엔터로 줄을 바꿔줍니다.
	}
	printf("\n"); // 아래 나올 출력문과 구분하기 위해 출력이 끝난 후 엔터로 줄을 띄워줍니다.
	return;
}

void matrixAdd(int Arr1[ROWS][COLS], int Arr2[ROWS][COLS], int Arr3[ROWS][COLS]) { // 세 개의 2차원 배열을 인자로 받습니다.
	for (int i = 0; i < ROWS; i++) { 
		for (int j = 0; j < COLS; j++) {// ROW와 COLS에 따라서 구문을 반복합니다.
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j];  // 인자로 받은 첫번째 두번째 배열을 세번째 배열에다가 더해서 저장합니다.
		}
	}
	return;
}

int main() {
	my_name(); // 정보 표기용 함수를 호출합니다. 
	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A); // 인자로 A를 넘겼으니 A 배열 안에 입력한 수들이 저장됩니다.
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B); // B 또한 마찬가지입니다.
	puts("<A>"); // 큰따옴표 안의 내용을 출력합니다.
	matrixPrint(A); // 인자로 넘긴 A 배열을 출력해줍니다.
	puts("<B>");
	matrixPrint(B);
	puts("<A+B>");
	matrixAdd(A,B,C); // A 배열과 B 배열의 합을 C 배열에 저장합니다.
	matrixPrint(C);
	return 0;
}