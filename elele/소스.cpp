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

	printf("������ �ݾװ� ���� ���� ������� �Է����ּ���.\n");
	scanf_s("%.1lf%.1lf", &Amount, &Object);
	printf("�ʿ��� �Ž����� : %.1lf\n õ�� %.1lf��\n ����� %.1lf��\n ��� %.1lf��\n", Change, Thousandnsand, FiveHundred, Hundred);


	return 0;

}