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
	
	printf("최대공약수와 최소공배수를 계산할 두개의 숫자를 입력하세요\n");
	scanf_s("%d %d", &Num1, &Num2);


	Temp1 = Num1; // 임시변수에 입력값을 저장
	Temp2 = Num2;

	while (Num2 != 0) //Num2에 저장된 변수값이 0이 아닐때까지 반복
	{
		Temp3 = Num2; //Num2 변수값을 임시변수에 저장 
		Num2 = Num1 % Num2; //Num2변수에 Num1 변수값을 Num2 변수값으로 나눈 나머지값을 다시 Num2 변수에 저장
		Num1 = Temp3;//임시변수에 저장했던 초기 Num2값을 Num1값에 저장, 이를 Num2값이 0이 될때까지 반복하여 최대공약수를 구함. 
	}

	Result1 = Num1; 

	printf("최대공약수 : %d\n", Result1); // 최대공약수값을 저장한 Result1 변수와 텍스트 출력

	Result2 =(Temp1 * Temp2)/Result1; //입력받은 정수를 곱하고 그 값을 최대공약수로 나눠 최소공배수를 구함.

	printf("최소공배수 : %d", Result2); // 최소공배수값을 저장한 Result2 변수와 텍스트 출력

	return 0;
}
