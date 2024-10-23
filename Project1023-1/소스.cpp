#include<stdio.h>

int main(void)

{
	int Num1; //변수선언
	int i;
	int j;
	int k;
	double Result;


	Num1 = 0; //변수값 초기화 
	i = 0;
	j = 0;
	k = 0;
	Result = 0;

	printf("출력할 단수를 입력하세요( 1 입력시 2 ~ 9단 한번에 출력)\n");
	scanf_s("%d", &Num1); //scanf_s 함수로 단 입력받기


	if (Num1 == 1) //만약 입력값이 1일경우 작동하는 영역
	{
		printf("2~9까지의 모든 출력결과\n");

		for (j = 2; j < 10; j++)  // 2~9단이므로 j변수를 2로 초기화하고 단수가 9까지 작동하도록 조건식을 작성, 증감연산을 통해 반복할수록 j값 증가
		{
			printf("%d단\n", j); // 반복될때마다 단수 구분을 위해 단수 출력

			for (k = 1; k < 10; k++) // k변수를 1로 초기화하고 조건식과 증감연산을 통해 1씩 증가하며 1~9까지 반복 
			{
				Result = j * k; // j값과 k값을 곱한값을 Result 변수에 저장
				printf("%d * %d = %.1lf\n", j , k ,Result); // 단수와 결과 출력
			}

		}


	}

	for (i = 1; i < 10; i++) // i 변수를 1로 초기화후 조건식과 증감연산으로 9번반복되게끔 코딩
	{
		Result = Num1 * i; //입력받은 Num1 변수값과 i를 곱하는걸 반복
		printf("%d * %d = %.1lf\n", Num1, i, Result); // 출력하려는 단수가 저장된 Num1값, 반복하며 증가되는 I,결과값 출력
	}



	return 0; //프로그램 종료

}
