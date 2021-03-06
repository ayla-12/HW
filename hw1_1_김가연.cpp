#include <stdio.h>

void my_name() { //정보 출력을 위한 이름 함수입니다.
    printf("=====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 2071060\n");
    printf("이름: 김가연\n");
    printf("=====================\n\n");
    return;
}

int main()
{
    my_name();
    int x=0, y=0, temp = 0; // 입력받을 정수 x, 배열의 위치를 지정해주는 y, 임시 저장소 temp 변수를 선언하고 초기화 해줍니다.
    int binary[20] = { 0, }; // 이진수를 출력할 배열을 정의해줍니다. 20칸 정도면 될 것 같습니다.

    printf("양의 정수 입력:"); scanf("%d", &x); // 양의 정수 입력을 받습니다. 입력을 받아 변수 x에 저장합니다.

    temp = x; // 나중에 무슨 정수를 입력받았는지 출력하기 위해 임시 저장소 temp 변수에 입력받았던 값을 복사해둡니다.

    while (1) // while 반복문에 1을 넣어 무한으로 돌아가도록 만들고, 조건을 만족했을 때 종료되는 반복문 탈출을 활용합니다.
    {
        binary[y] = x % 2;    // 2로 나누었을때 나머지를 저장하여 십진수를 이진수로 바꾸는 연산을 해줍니다.
        x = x / 2;             // 2로 나눈 몫을 저장하여 다음 연산 준비를 합니다.

        y++;    // 자릿수 변경을 위해 y에 1을 추가하여 배열 다음칸에 다음 나머지를 저장하도록 합니다.

        if (x == 0)    // 몫이 0이 되면 반복을 끝내는 break를 찍어줍니다.
            break;
    }

    printf("십진수 %d의 이진표현:", temp); // 몫을 계산하는데 쓰였던 x가 아닌 저장해뒀던 temp를 출력해줍니다.

    // 계산 순서대로 들어가있던 나머지를 반대로 출력합니다. y를 이용해서 반복문을 돌립니다.
    for (int i = y - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    printf("\n");
    return 0;
}