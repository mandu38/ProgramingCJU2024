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


	printf("������ �ݾװ� ���ǰ��� ���ʴ�� �Է����ּ���.\n");
	scanf_s("%lf%lf", &Amount, &Object);

	Change = Amount - Object;
	Change = ((Change > 0) * Amount) - ((Change > 0) * Object);
	Thousand = Change / 1000; 
	ChangeRemainder = fmod(Change, 1000);
	FiveRemainder = fmod(ChangeRemainder,500);
	FiveHundred = ChangeRemainder / 500;
	Hundred = FiveRemainder / 100;

	printf("�ʿ��� �Ž����� : %.1lf\n õ�� %d��\n ����� %d��\n ��� %d��\n", Change, Thousand, FiveHundred, Hundred);

	return 0;

}