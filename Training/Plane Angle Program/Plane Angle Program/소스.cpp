#include <stdio.h>
#include <math.h> 


int main(void) 
{
		
	double PlaneAngle; //���� ����
	double ConvertAngle;


	PlaneAngle = 0; //���� �ʱ�ȭ
	ConvertAngle = 0;
	

	printf("��ȯ�� �Ǽ��� �ڼ����� �Է��ϼ��� [deg]\n"); 
	scanf_s("%lf", &PlaneAngle); //�ڼ��� �Է¹ޱ�


	PlaneAngle = (PlaneAngle > 180) * (PlaneAngle - 360) + (PlaneAngle <= 180) * PlaneAngle; //�Է°��� 180 �ʰ��Ұ�� 360�� ��. �ƴҽ� �״�� ���
	PlaneAngle = (PlaneAngle < -180) * (PlaneAngle + 360) + (PlaneAngle >= -180) * PlaneAngle; //�Է°��� 180 �̸��ϰ�� 360�� ��. �ƴҽ� �״�� ���

	ConvertAngle = fmod(PlaneAngle,180); //fmod�Լ��� ���� �Ǽ��� ������ PlanAngle�� �������� ���ϰ� 180���� ���� ���������� ConvertAngle ������ ����

	printf("��ȯ�� �ڼ��� : %.3lf ��", ConvertAngle); //���� ���� ���

	return 0; //���α׷� ����

}