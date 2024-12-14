#include <stdio.h>
#include <math.h> 


int main(void) 
{
		
	double PlaneAngle; //변수 선언
	double ConvertAngle;


	PlaneAngle = 0; //변수 초기화
	ConvertAngle = 0;
	

	printf("변환할 실수형 자세값을 입력하세요 [deg]\n"); 
	scanf_s("%lf", &PlaneAngle); //자세값 입력받기


	PlaneAngle = (PlaneAngle > 180) * (PlaneAngle - 360) + (PlaneAngle <= 180) * PlaneAngle; //입력값이 180 초과할경우 360을 뺌. 아닐시 그대로 출력
	PlaneAngle = (PlaneAngle < -180) * (PlaneAngle + 360) + (PlaneAngle >= -180) * PlaneAngle; //입력값이 180 미만일경우 360을 뺌. 아닐시 그대로 출력

	ConvertAngle = fmod(PlaneAngle,180); //fmod함수를 통해 실수형 변수인 PlanAngle의 나머지를 구하고 180으로 나눈 나머지값을 ConvertAngle 변수에 저장

	printf("변환된 자세값 : %.3lf 도", ConvertAngle); //계산된 값을 출력

	return 0; //프로그램 종료

}