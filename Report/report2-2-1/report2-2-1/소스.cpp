#include<stdio.h>

int main(void)
{
	int Num1; // 변수선언
	int Num2;
	double Result;


	Num1 = 0; //변수초기화
	Num2 = 0;
	Result = 0;


	printf("두개의 정수를 입력해주세요 (if문)\n");
	scanf_s("%d %d", &Num1, &Num2); //scanf_s 함수로 2개의 값을 입력받고 각각의 변수에 저장 

	Result = Num1%Num2;//Num1변수에 저장된 값을 Num2변수에 저장된 값으로 나눈 나머지값을 Result 변수에 저장

	if (Result == 0) // Result에 저장된 계산값이 0일 경우 해당 문장 출력
	{
		printf("배수의 관계가 맞습니다.");
	}
	else // 이외의 경우는 해당 문장을 출력
	{
		printf("배수의 관계가 아닙니다.");
	}

	return 0;
}
