#include <stdio.h>

void my_name() { //���� ����� ���� �̸� �Լ��Դϴ�.
	printf("=====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 2071060\n");
	printf("�̸�: �谡��\n");
	printf("=====================\n\n");
	return;
}

double func_recursive(double a) { //����Լ��� ����ϴ�.
	if (a == 1) return 1; //���� ���� 1�̸� 1�� return�մϴ�. (��͸� ���� ����)
	else return 1/a + func_recursive(a-1); //1���� ū �ڿ����� ������ ��� �ڽ��� �ٽ� ȣ���մϴ�.
}

double func_iterative(double a) { //�ݺ����� ���� �Լ��� ����ϴ�.
	double result = 0.0; //return�� ���� result�� double �ڷ������� ������ݴϴ�.
	for (double i = 1; i <= a; i++) { //i ���� �ڷ����� double�̾�� �������� ����� �ǹǷ�, i�� �ؼ� �Է¹��� ������ ���ų� �۾��������� �ݺ����� �����մϴ�.
		result += 1/i;
	}
	return result; //�ݺ����� ������ result�� return�մϴ�.
}


int main() {

	my_name();
	int n=0; //������ �Է¹ޱ� ���� ���� n�� �����մϴ�. ������ �޾Ƶ� �Լ��� ������ double�� ���Ƿ� ���� ����ȯ�� ������ �ʾƵ� �˴ϴ�.

	while (1) { // ���� ������ break�� ������ ������ ��� ������ �ݺ��մϴ�.

		printf("���� ���� �Է�: "); scanf("%d", &n);
		if (n <= 0) break; // n�� ���� ���� ���� 0 �����̸� �� ��� �ݺ����� �����մϴ�. 
		printf("Result from iterative: %.2f\n", func_iterative(n)); //�ݺ����� ����� �Լ��� ȣ���մϴ�. ��� ���� �Ҽ��� 2�ڸ����� �߸����� ���ݴϴ�.
		printf("Result from recursive: %.2f\n", func_recursive(n)); //����Լ��� ȣ���մϴ�. ���������� ��� ���� �Ҽ��� 2�ڸ����� �߸����� ���ݴϴ�.
	}
	return 0;
}