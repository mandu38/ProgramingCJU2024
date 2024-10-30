#include <stdio.h>
#include <math.h>
#define PI 3.141592

double Con1(double Angle) // sin변환 함수
{
	double Result;
	Result = sin(Angle); //계산된 sin 값을 Result 변수에 저장
	Result = ((Result * 180) / PI); //라디안값으로 출력된 코사인값 디그리로 변환 
	return Result;
}

double Con2(double Angle) // cos 변환 함수
{
	double Result;
	Result = cos(Angle); //계산된 cos 값을 Result 변수에 저장
	Result = ((Result * 180) / PI);  //라디안값으로 출력된 코사인값 디그리로 변환 
	return Result; // 계산값 반환
}

int main(void)
{
	double Angle = 0, Result = 0, Result1 = 0, Result2 = 0;

	printf("각도값을 입력하세요 (deg)\n");
	scanf_s("%lf", &Angle);

	// 함수 실행
	Result1 = Con1(Angle);
	Result2 = Con2(Angle);

	
	// sin cos 계산값 0~ +180으로 범위지정
	Result1 = (Result1 > 180) * (Result1 - 180) + (Result1 <= 180) * Result1;
	Result1 = (Result1 < 0) * (Result1 + 180) + (Result1 >= 0) * Result1;
	Result2 = (Result2 > 180) * (Result2 - 180) + (Result2 <= 180) * Result2;
	Result2 = (Result2 < 0) * (Result2 + 180) + (Result2 >= 0) * Result2;

	printf("입력받은 각도값 %.1lf 도 \nSin 변환값 : %.1lf \nCos 변환값 : %.1lf", Angle, Result1, Result2); // 텍스트 출력

	return 0;
}


