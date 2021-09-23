#include <stdio.h>

void my_name() { //정보 출력을 위한 이름 함수입니다.
	printf("=====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 2071060\n");
	printf("이름: 김가연\n");
	printf("=====================\n\n");
	return;
}

double func_recursive(double a) { //재귀함수를 만듭니다.
	if (a == 1) return 1; //들어온 값이 1이면 1을 return합니다. (재귀를 끝낼 조건)
	else return 1/a + func_recursive(a-1); //1보다 큰 자연수가 들어왔을 경우 자신을 다시 호출합니다.
}

double func_iterative(double a) { //반복문을 쓰는 함수를 만듭니다.
	double result = 0.0; //return할 변수 result를 double 자료형으로 만들어줍니다.
	for (double i = 1; i <= a; i++) { //i 또한 자료형이 double이어야 정상적인 계산이 되므로, i로 해서 입력받은 수보다 같거나 작아질때까지 반복문을 진행합니다.
		result += 1/i;
	}
	return result; //반복문이 끝나면 result를 return합니다.
}


int main() {

	my_name();
	int n=0; //정수를 입력받기 위한 변수 n을 선언합니다. 정수로 받아도 함수에 들어갈때는 double로 들어가므로 굳이 형변환을 해주지 않아도 됩니다.

	while (1) { // 무한 루프로 break를 만나기 전까지 계속 구문을 반복합니다.

		printf("양의 정수 입력: "); scanf("%d", &n);
		if (n <= 0) break; // n에 들어온 수를 보고 0 이하이면 그 즉시 반복문을 종료합니다. 
		printf("Result from iterative: %.2f\n", func_iterative(n)); //반복문을 사용한 함수를 호출합니다. 출력 값이 소수점 2자리에서 잘리도록 해줍니다.
		printf("Result from recursive: %.2f\n", func_recursive(n)); //재귀함수를 호출합니다. 마찬가지로 출력 값이 소수점 2자리에서 잘리도록 해줍니다.
	}
	return 0;
}