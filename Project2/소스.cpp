#include <stdio.h>

int main(void)
{
	int trianglelength =0 ;
	int trianglebreadth = 0;
	int triangleResult = 0;
	int tetargonlength = 0;
	int tetargonbreadth = 0;
	int tetargonResult = 0;
	double circle =0 ;
	double circleResult = 0;
	double nine = 0;
	double nineResult1 = 0;
	double nineResult2 = 0;


	printf("�ﰢ�� ���� ��꿡 �ʿ��� �غ��� ���̸� �Է��ϼ��� : \n");
	scanf_s("%d%d", &trianglelength, &trianglebreadth);
	triangleResult = trianglelength * trianglebreadth / 2;
	printf("�ﰢ���� ���̴� %d cm^2�Դϴ�.\n", triangleResult);

	printf("�簢�� ���� ��꿡 �ʿ��� ���ο� ���θ� �Է��ϼ��� : \n");
	scanf_s("%d%d", &tetargonlength, &tetargonbreadth);
	tetargonResult = tetargonlength * tetargonbreadth;
	printf("�簢���� ���̴� %d cm^2�Դϴ�.\n", tetargonResult);

	printf("���� ���� ��꿡 �ʿ��� ���������� �Է��ϼ��� : \n");
	scanf_s("%lf", &circle);
	circleResult = circle  * circle * 3.14;
	printf("���� ���̴� %.2lf cm^2�Դϴ�.\n", circleResult);

	printf("���� ǥ������ ü���� ����ϱ� ���� ���������� �Է��ϼ��� : \n");
	scanf_s("%lf", &nine);
	nineResult1 = 4 * nine * 3.14;
	nineResult2 = 4/3 * 3.14 * nine * nine * nine;
	printf("���� ǥ������ %.2lf cm^2�̰� ���� ü���� %.2lfcm^3 �Դϴ�. \n", nineResult1 , nineResult2);



	return 0;
}