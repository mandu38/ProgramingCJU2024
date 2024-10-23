#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Max;
	int Min;
	int Result1;
	int i;
	int j; 

	printf("최대공약수와 최소공배수를 계산할 두 정수를 입력하세요\n");
	scanf_s("%d %d", &Num1, &Num2);

	do // Num1 변수와 Num2 변수가 같지 않는 경우 실행
	{
		if (Num1 > Num2) //Num1 변수가 Num2 보다 큰 경우 실행, 큰값에서 작은값을 빼 계속해서 변수에 저장
			Num1 = Num1 - Num2;
		else
			Num2 = Num2 - Num1;
	} while(Num1 != Num2);

	Result1 = Num1;

	printf("최대공약수 : %d\n", Result1);

	Max = (Num1 > Num2) ? Num1 : Num2; // 큰수 배치
	Min = (Num1 < Num2) ? Num1 : Num2;// 작은수 배치
	
	i = Max;
	j = Min;

	do
	{
		if (i % Min == 0 && i % Max == 0) // 큰값을 작은값과 나눴을때와 작은값을 큰 값으로 나눴을때 나머지가 0일때까지 실행하고 최소공배수를 찾았으면 텍스트를 출력하고 종료 아닐시에는 i값을 증감연산을 통해 더함
		{
			printf("최소공배수 : %d", i);
			break;
		}
		else
			i++;

	} while (j <= Max * Min);



	return 0;
}

