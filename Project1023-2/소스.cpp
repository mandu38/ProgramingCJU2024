#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Result1;
	int Result2;
	int Max;
	int Min;
	int i;
	int j;
	
	Num1 = 0;
	Num2 = 0;
	Result1 = 0;
	Result2 = 0;
	Max = 0;
	Min = 0;
	i = 0;
	j = 0;
	
	printf("�ִ������� �ּҰ������ ����� �ΰ��� ���ڸ� �Է��ϼ���\n");
	scanf_s("%d %d", &Num1, &Num2);

	Max = (Num1 > Num2) ? Num1 : Num2; // �� ���߿��� �� ū ���� ����.
	Min = (Num1 < Num2) ? Num1 : Num2; // �� ���߿��� ���� ���� ����.

	i = Max;
	j = Min;

	while (Num1 != Num2) // Num1 ������ Num2 ������ ���� �ʴ� ��� ����
	{
		if (Num1 > Num2) //Num1 ������ Num2 ���� ū ��� ����, ū������ �������� �� ����ؼ� ������ ����
			Num1 = Num1 - Num2;
		else
			Num2 = Num2 - Num1;
	}
	Result1 = Num1; 

	printf("�ִ����� : %d\n", Result1);
	
	while (j <= Max * Min) //���� �� ���� Ŭ������ ����
	{
		if (i % Min == 0 && i % Max == 0) // ū���� �������� ���������� �������� ū ������ �������� �������� 0�϶����� �����ϰ� �ּҰ������ ã������ �ؽ�Ʈ�� ����ϰ� ���� �ƴҽÿ��� i���� ���������� ���� ����
		{
			printf("�ּҰ���� : %d", i);
			break;
		}
		else 
		    i++;
	}
	

	return 0;
}

