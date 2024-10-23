#include<stdio.h>

int main(void)
{
	int Num1; // 변수선언
	int Num2;
	int Result;

	Num1 = 0; // 변수 초기화 
	Num2 = 0;
	Result = 0;

	printf("두 개의 정수를 입력하세요(switch case문)\n");
	scanf_s("%d %d", &Num1, &Num2); //scanf_s 함수로 값을 입력받고 각각의 변수에 저장

	Result = Num1 % Num2; // Num1 변수에 저장된 값을 Num2 변수에 저장된 값으로 나눈 나머지값을 Result 변수에 저장

	switch (Result)
	{
	case 0: // Result 변수에 저장된 값이 0일 경우 해당 문장 출력
		printf("배수의 관계가 맞습니다.");
		break;
		
	default:// Result 변수에 저장된 값이 0이 아닌 나머지 경우는 해당 문장 출력
		printf("배수의 관계가 아닙니다.");
		break;
	}

	return 0; //프로그램 종료
}
