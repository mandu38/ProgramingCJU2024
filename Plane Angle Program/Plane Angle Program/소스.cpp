#include <stdio.h>
#include <math.h> 


int main(void)
{
		
	double PlaneAngle;
	double ConvertAngle;


	PlaneAngle = 0;
	ConvertAngle = 0;
	

	printf("변환할 실수형 자세값을 입력하세요 [deg]\n");
	scanf_s("%lf", &PlaneAngle);


	PlaneAngle = (PlaneAngle > 180) * (PlaneAngle - 360) + (PlaneAngle <= 180) * PlaneAngle;
	PlaneAngle = (PlaneAngle < -180) * (PlaneAngle + 360) + (PlaneAngle >= -180) * PlaneAngle;

	ConvertAngle = fmod(PlaneAngle,180);

	printf("변환된 자세값 : %.3lf 도", ConvertAngle);

	return 0;

}