#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Result1;
	int Result2;
	int Temp1;
	int Temp2;
	int Temp3;

	Num1 = 0;
	Num2 = 0;
	Result1 = 0;
    Result2 = 0;
	Temp1 = 0;
	Temp2 = 0;
	Temp3 = 0;


	printf("최대공약수와 최소공배수를 계산할 두 정수를 입력하세요 do ~while 문\n");
	scanf_s("%d %d", &Num1, &Num2);

	Temp1 = Num1;
	Temp2 = Num2;

	do // 반복 실행
	{
		Temp3 = Num2; //임시변수에 Num2 값 저장
		Num2 = Num1 % Num2; // Num1 변수값을 Num2 변수값으로 나눈 나머지 값을 다시 Num2 변수값에 저장
		Num1 = Temp3; //Num2 값을 저장한 임시변수값을 Num1에 저장하며 반복
	} while(Num2 != 0);

	Result1 = Num1;

	printf("최대공약수 : %d\n", Result1);

	Result2 = (Temp1 * Temp2) / Result1; //입력받은 정수를 곱하고 그 값을 최대공약수로 나눠 최소공배수를 구함.

	printf("최소공배수 : %d", Result2); // 최소공배수값을 저장한 Result2 변수와 텍스트 출력

	return 0;
}


