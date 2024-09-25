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


	printf("삼각형 넓이 계산에 필요한 밑변과 높이를 입력하세요 : \n");
	scanf_s("%d%d", &trianglelength, &trianglebreadth);
	triangleResult = trianglelength * trianglebreadth / 2;
	printf("삼각형의 넓이는 %d cm^2입니다.\n", triangleResult);

	printf("사각형 넓이 계산에 필요한 가로와 세로를 입력하세요 : \n");
	scanf_s("%d%d", &tetargonlength, &tetargonbreadth);
	tetargonResult = tetargonlength * tetargonbreadth;
	printf("사각형의 넓이는 %d cm^2입니다.\n", tetargonResult);

	printf("원의 넓이 계산에 필요한 반지름값을 입력하세요 : \n");
	scanf_s("%lf", &circle);
	circleResult = circle  * circle * 3.14;
	printf("원의 넓이는 %.2lf cm^2입니다.\n", circleResult);

	printf("구의 표면적과 체적을 계산하기 위한 반지름값을 입력하세요 : \n");
	scanf_s("%lf", &nine);
	nineResult1 = 4 * nine * 3.14;
	nineResult2 = 4/3 * 3.14 * nine * nine * nine;
	printf("구의 표면적은 %.2lf cm^2이고 구의 체적은 %.2lfcm^3 입니다. \n", nineResult1 , nineResult2);



	return 0;
}