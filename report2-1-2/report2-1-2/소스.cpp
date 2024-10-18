#include<stdio.h>

int main(void)
{
	int Num1; //변수선언

	Num1 = 0;

	printf("숫자를 입력하세요(스위치케이스)\n"); 
	scanf_s("%d", &Num1); // scanf_s 함수로 값 입력받기

	Num1 = Num1 % 2; // 입력받은 값이 저장된 Num1의 값을 2로 나눈 나머지값을 Num1 변수에 저장

	switch (Num1)
	{
	case 1: //Num1에 저장된 나머지값이 1인 경우 홀수이므로 해당 문장 출력
		printf("홀수입니다.");
		break;

	case 0://Num1에 저장된 나머지값이 0인 경우 짝수이므로 해당 문장 출력
		printf("짝수입니다.");
		break;

	default:// 오류 방지를 위해 이외의 경우는 해당 문장이 출력되게끔 코딩
		printf("오류가 발생했습니다.");
		break;
	}

	return 0;
}