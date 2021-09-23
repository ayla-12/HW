#include <stdio.h>
#define ROWS 4
#define COLS 3

void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
	printf("=====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 2071060\n");
	printf("�̸�: �谡��\n");
	printf("=====================\n\n");
	return;
}

void matrixInput(int Arr[ROWS][COLS]) { // 2���� �迭�� ���ڷ� �޾��ݴϴ�.
	for (int i = 0; i < ROWS; i++) { // ROWS�� COLS�� ���� ������ �ݺ��ϸ鼭 �� ĭ�� �Է¹޴� ���� �־��ݴϴ�.
		for (int j = 0; j < COLS; j++) {
			scanf("%d", &Arr[i][j]); //scanf�� �������� �� SDL ������ ���ݴϴ�. 
		}
	}
	return;
}

void matrixPrint(int Arr[ROWS][COLS]) { // 2���� �迭�� ���ڷ� �޾��ݴϴ�.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) { // ROW�� COLS�� ���� ������ �ݺ��ϸ鼭 �� ĭ�� �Էµ� ���� ������ݴϴ�.
			printf("%3d", Arr[i][j]); // ����� �� �� ĭ�� ���߱� ���� %3d�� �迭���� ������ ����ݴϴ�.
		}
		printf("\n"); // �� ���� ������ ���ͷ� ���� �ٲ��ݴϴ�.
	}
	printf("\n"); // �Ʒ� ���� ��¹��� �����ϱ� ���� ����� ���� �� ���ͷ� ���� ����ݴϴ�.
	return;
}

void matrixAdd(int Arr1[ROWS][COLS], int Arr2[ROWS][COLS], int Arr3[ROWS][COLS]) { // �� ���� 2���� �迭�� ���ڷ� �޽��ϴ�.
	for (int i = 0; i < ROWS; i++) { 
		for (int j = 0; j < COLS; j++) {// ROW�� COLS�� ���� ������ �ݺ��մϴ�.
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j];  // ���ڷ� ���� ù��° �ι�° �迭�� ����° �迭���ٰ� ���ؼ� �����մϴ�.
		}
	}
	return;
}

int main() {
	my_name(); // ���� ǥ��� �Լ��� ȣ���մϴ�. 
	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A); // ���ڷ� A�� �Ѱ����� A �迭 �ȿ� �Է��� ������ ����˴ϴ�.
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B); // B ���� ���������Դϴ�.
	puts("<A>"); // ū����ǥ ���� ������ ����մϴ�.
	matrixPrint(A); // ���ڷ� �ѱ� A �迭�� ������ݴϴ�.
	puts("<B>");
	matrixPrint(B);
	puts("<A+B>");
	matrixAdd(A,B,C); // A �迭�� B �迭�� ���� C �迭�� �����մϴ�.
	matrixPrint(C);
	return 0;
}