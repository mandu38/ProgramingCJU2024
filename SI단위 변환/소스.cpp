#include <stdio.h>

int main(void)
{
	double fit;
	double inch;
	double fitResult;
	double inchResult;
	double slug;
	double KG;

	printf("Si������� ��ȯ�� ��Ʈ, ��ġ���� �Է��ϼ��� \n");
	scanf_s("%lf %lf", &fit, &inch);
	fitResult = fit * 0.3048;
	inchResult = inch * 0.0254;
	printf("SI������ ��ȯ�� (���Ͱ�) (��Ʈ : %.5lfm) (��ġ : %.5lfm) \n", fitResult, inchResult);

	printf("Si������� ��ȯ�� slug���� �Է��ϼ��� \n");
	scanf_s("%lf", &slug);
	KG = slug * 14.593;
	printf("SI������ slug ��ȯ�� = %.2lf KG \n", KG);




	return 0;




}