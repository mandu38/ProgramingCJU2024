#include <stdio.h>
#include <math.h> 


int main(void)
{
		
	double PlaneAngle;
	double ConvertAngle;


	PlaneAngle = 0;
	ConvertAngle = 0;
	

	printf("��ȯ�� �Ǽ��� �ڼ����� �Է��ϼ��� [deg]\n");
	scanf_s("%lf", &PlaneAngle);


	PlaneAngle = (PlaneAngle > 180) * (PlaneAngle - 360) + (PlaneAngle <= 180) * PlaneAngle;
	PlaneAngle = (PlaneAngle < -180) * (PlaneAngle + 360) + (PlaneAngle >= -180) * PlaneAngle;

	ConvertAngle = fmod(PlaneAngle,180);

	printf("��ȯ�� �ڼ��� : %.3lf ��", ConvertAngle);

	return 0;

}