#include <stdio.h>

int main(void)
{
	int A[3] = { 1, 2, 3 }; // 배열 선언 및 초기화
	int B[10];
	int i; //for 문에 쓸 i값 변수 선언


	for (i = 0; i < 10; i++) // B 배열의 개수만큼 반복
	{
		B[i] = A[i % 3]; //나머지 연산자를 이용해 A배열의 값이 0~2가 반복되게끔하는 수식
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\t", B[i]); //B 배열 개수만큼 텍스트 출력
	}

	return 0;
}