#include<stdio.h>

int main(void)
{
	int Num1;
	int Num2;
	int Result1;
	int Result2;
	int Temp1;
	int Temp2;
	int Temp3;

	Num1 = 0;
	Num2 = 0;
	Result1 = 0;
    Result2 = 0;
	Temp1 = 0;
	Temp2 = 0;
	Temp3 = 0;


	printf("�ִ������� �ּҰ������ ����� �� ������ �Է��ϼ��� do ~while ��\n");
	scanf_s("%d %d", &Num1, &Num2);

	Temp1 = Num1;
	Temp2 = Num2;

	do // �ݺ� ����
	{
		Temp3 = Num2; //�ӽú����� Num2 �� ����
		Num2 = Num1 % Num2; // Num1 �������� Num2 ���������� ���� ������ ���� �ٽ� Num2 �������� ����
		Num1 = Temp3; //Num2 ���� ������ �ӽú������� Num1�� �����ϸ� �ݺ�
	} while(Num2 != 0);

	Result1 = Num1;

	printf("�ִ����� : %d\n", Result1);

	Result2 = (Temp1 * Temp2) / Result1; //�Է¹��� ������ ���ϰ� �� ���� �ִ������� ���� �ּҰ������ ����.

	printf("�ּҰ���� : %d", Result2); // �ּҰ�������� ������ Result2 ������ �ؽ�Ʈ ���

	return 0;
}


