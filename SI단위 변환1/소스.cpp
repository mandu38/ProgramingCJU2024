#include <stdio.h>

int main(void)
{
	double fit;
	double inch;
	double fitResult;
	double inchResult;
	double slug;
	double KG;

	printf("Si단위계로 변환할 피트, 인치값을 입력하세요 \n");
	scanf_s("%lf %lf", &fit, &inch);
	fitResult = fit * 0.3048;
	inchResult = inch * 0.0254;
	printf("SI단위계 변환값 (미터값) (피트 : %.5lfm) (인치 : %.5lfm) \n", fitResult, inchResult);

	printf("Si단위계로 변환할 slug값을 입력하세요 \n");
	scanf_s("%lf", &slug);
	KG = slug * 14.593;
	printf("SI단위계 slug 변환값 = %.2lf KG \n", KG);




	return 0;




}