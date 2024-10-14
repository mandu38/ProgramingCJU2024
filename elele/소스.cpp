#include <stdio.h>

int main(void)
{


	double Amount;
	double Object;
	double Change;
	int Thousandnsand;
	int FiveHundred;
	int Hundred;

	Amount = 0;
	Object = 0;
	Change = 0;
	Thousandnsand = 0;
	FiveHundred = 0;
	Hundred = 0;

	Change = Object - Amount;
	Thousandnsand = Change / 1000;
	FiveHundred = Thousandnsand / 500;
	Hundred = FiveHundred / 100;

	printf("투입한 금액과 물건 값을 순서대로 입력해주세요.\n");
	scanf_s("%.1lf%.1lf", &Amount, &Object);
	printf("필요한 거스름돈 : %.1lf\n 천원 %.1lf장\n 오백원 %.1lf개\n 백원 %.1lf개\n", Change, Thousandnsand, FiveHundred, Hundred);


	return 0;

}