#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Result1;
	int Result2;
	int Max;
	int Min;
	int i;
	int j;
	
	Num1 = 0;
	Num2 = 0;
	Result1 = 0;
	Result2 = 0;
	Max = 0;
	Min = 0;
	i = 0;
	j = 0;
	
	printf("최대공약수와 최소공배수를 계산할 두개의 숫자를 입력하세요\n");
	scanf_s("%d %d", &Num1, &Num2);

	Max = (Num1 > Num2) ? Num1 : Num2; // 두 수중에서 더 큰 수를 고른다.
	Min = (Num1 < Num2) ? Num1 : Num2; // 두 수중에서 작은 수를 고른다.

	i = Max;
	j = Min;

	while (Num1 != Num2) // Num1 변수와 Num2 변수가 같지 않는 경우 실행
	{
		if (Num1 > Num2) //Num1 변수가 Num2 보다 큰 경우 실행, 큰값에서 작은값을 빼 계속해서 변수에 저장
			Num1 = Num1 - Num2;
		else
			Num2 = Num2 - Num1;
	}
	Result1 = Num1; 

	printf("최대공약수 : %d\n", Result1);
	
	while (j <= Max * Min) //작은 수 보다 클때까지 실행
	{
		if (i % Min == 0 && i % Max == 0) // 큰값을 작은값과 나눴을때와 작은값을 큰 값으로 나눴을때 나머지가 0일때까지 실행하고 최소공배수를 찾았으면 텍스트를 출력하고 종료 아닐시에는 i값을 증감연산을 통해 더함
		{
			printf("최소공배수 : %d", i);
			break;
		}
		else 
		    i++;
	}
	

	return 0;
}

