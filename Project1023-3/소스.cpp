#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Max;
	int Min;
	int Result1;
	int i;
	int j; 

	printf("�ִ������� �ּҰ������ ����� �� ������ �Է��ϼ���\n");
	scanf_s("%d %d", &Num1, &Num2);

	do // Num1 ������ Num2 ������ ���� �ʴ� ��� ����
	{
		if (Num1 > Num2) //Num1 ������ Num2 ���� ū ��� ����, ū������ �������� �� ����ؼ� ������ ����
			Num1 = Num1 - Num2;
		else
			Num2 = Num2 - Num1;
	} while(Num1 != Num2);

	Result1 = Num1;

	printf("�ִ����� : %d\n", Result1);

	Max = (Num1 > Num2) ? Num1 : Num2; // ū�� ��ġ
	Min = (Num1 < Num2) ? Num1 : Num2;// ������ ��ġ
	
	i = Max;
	j = Min;

	do
	{
		if (i % Min == 0 && i % Max == 0) // ū���� �������� ���������� �������� ū ������ �������� �������� 0�϶����� �����ϰ� �ּҰ������ ã������ �ؽ�Ʈ�� ����ϰ� ���� �ƴҽÿ��� i���� ���������� ���� ����
		{
			printf("�ּҰ���� : %d", i);
			break;
		}
		else
			i++;

	} while (j <= Max * Min);



	return 0;
}

