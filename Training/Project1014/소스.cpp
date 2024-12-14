#include <stdio.h>

int main(void)
{
	
	char Operator;
	double NumberOne;
	double NumberTwo;
	double Result;

	NumberOne = 0;
	NumberTwo = 0;
	Result = 0;

	printf("사칙연산 입력(정수)\n");
	scanf_s("%lf%c%lf",&NumberOne,&Operator, sizeof(Operator), & NumberTwo);


	if (Operator== '+')
	{
		Result=NumberOne + NumberTwo;
	}
	else if (Operator== '-')
	{
		Result=NumberOne - NumberTwo;
	}
	else if (Operator== '*')
	{
		Result=NumberOne * NumberTwo;
	}
	else
	{
		Result=NumberOne / NumberTwo;
	}

	printf("%.1lf %c %.1lf = %.1lf" ,NumberOne,Operator,NumberTwo,Result);
		
	return 0;

}