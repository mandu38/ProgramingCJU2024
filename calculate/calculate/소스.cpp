#include <stdio.h>
#include <math.h>

int main(void)
{

	int Thousand;
	int FiveHundred;
	int Hundred;
	double Amount;
	double Object;
	double Change;
	double ChangeRemainder;
	double FiveRemainder;

	Amount = 0;
	Object = 0;
	Change = 0;
	Thousand = 0;
	FiveHundred = 0;
	Hundred = 0;
	ChangeRemainder = 0;
	FiveRemainder = 0;


	printf("투입한 금액과 물건값을 차례대로 입력해주세요.\n");
	scanf_s("%lf%lf", &Amount, &Object);

	Change = Amount - Object;
	Change = ((Change > 0) * Amount) - ((Change > 0) * Object);
	Thousand = Change / 1000; 
	ChangeRemainder = fmod(Change, 1000);
	FiveRemainder = fmod(ChangeRemainder,500);
	FiveHundred = ChangeRemainder / 500;
	Hundred = FiveRemainder / 100;

	printf("필요한 거스름돈 : %.1lf\n 천원 %d장\n 오백원 %d개\n 백원 %d개\n", Change, Thousand, FiveHundred, Hundred);

	return 0;

}