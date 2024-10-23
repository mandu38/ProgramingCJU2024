#include<stdio.h>

int main(void)
{
	int Num1; //변수선언

	Num1 = 0;

	printf("숫자를 입력해주세요\n");
	scanf_s("%d", &Num1); //scanf_s 함수로 값 입력받기

	Num1 = Num1 % 2; // 입력받은 Num1 변수의 값을 2로 나눴을때 나머지값을 Num1 변수에 저장

	if (Num1 == 0) // 입력받은 Num1 변수의 값을 2로 나눴을때 나머지값이 0인경우 짝수이므로 해당 문장 출력
	{
		printf("짝수입니다.");
	}
	else // 입력받은 Num1 변수의 값을 2로 나눴을때 나머지값이 0이 아닌 나머지 경우는 홀수이므로 해당 문장 출력
	{
		printf("홀수입니다.");
	}

	return 0;


}