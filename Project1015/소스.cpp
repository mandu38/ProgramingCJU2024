#include <stdio.h>

int main(void)
{

	char Operator;
	double Num1;
	double Num2;
	double Result;

	Num1 = 0;
	Num2 = 0;
	Result = 0;

	printf("사칙연산 입력(정수)\n");
	scanf_s("%lf%c%lf", &Num1, &Operator, sizeof(Operator), &Num2);

	switch (Operator)
	{

	case '+' :
		Result = Num1 + Num2;
		break;

	case '-' :
		Result = Num1 - Num2;
		break;

	case '*' :
		Result = Num1 * Num2;
		break;

	default:
		Result = Num1 / Num2;
		break;

	}


	printf("%.1lf %c %.1lf = %.1lf", Num1, Operator, Num2, Result);

	return 0;

}