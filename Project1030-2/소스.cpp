#include <stdio.h>
#include <math.h>
#define PI 3.141592

double Con1(double Angle) // sin��ȯ �Լ�
{
	double Result;
	Result = sin(Angle); //���� sin ���� Result ������ ����
	Result = ((Result * 180) / PI); //���Ȱ����� ��µ� �ڻ��ΰ� ��׸��� ��ȯ 
	return Result;
}

double Con2(double Angle) // cos ��ȯ �Լ�
{
	double Result;
	Result = cos(Angle); //���� cos ���� Result ������ ����
	Result = ((Result * 180) / PI);  //���Ȱ����� ��µ� �ڻ��ΰ� ��׸��� ��ȯ 
	return Result; // ��갪 ��ȯ
}

int main(void)
{
	double Angle = 0, Result = 0, Result1 = 0, Result2 = 0;

	printf("�������� �Է��ϼ��� (deg)\n");
	scanf_s("%lf", &Angle);

	// �Լ� ����
	Result1 = Con1(Angle);
	Result2 = Con2(Angle);

	
	// sin cos ��갪 0~ +180���� ��������
	Result1 = (Result1 > 180) * (Result1 - 180) + (Result1 <= 180) * Result1;
	Result1 = (Result1 < 0) * (Result1 + 180) + (Result1 >= 0) * Result1;
	Result2 = (Result2 > 180) * (Result2 - 180) + (Result2 <= 180) * Result2;
	Result2 = (Result2 < 0) * (Result2 + 180) + (Result2 >= 0) * Result2;

	printf("�Է¹��� ������ %.1lf �� \nSin ��ȯ�� : %.1lf \nCos ��ȯ�� : %.1lf", Angle, Result1, Result2); // �ؽ�Ʈ ���

	return 0;
}


