#include<stdio.h>

int main(void)
{
	int Num1; // ��������
	int Num2;
	double Result;


	Num1 = 0; //�����ʱ�ȭ
	Num2 = 0;
	Result = 0;


	printf("�ΰ��� ������ �Է����ּ��� (if��)\n");
	scanf_s("%d %d", &Num1, &Num2); //scanf_s �Լ��� 2���� ���� �Է¹ް� ������ ������ ���� 

	Result = Num1%Num2;//Num1������ ����� ���� Num2������ ����� ������ ���� ���������� Result ������ ����

	if (Result == 0) // Result�� ����� ��갪�� 0�� ��� �ش� ���� ���
	{
		printf("����� ���谡 �½��ϴ�.");
	}
	else // �̿��� ���� �ش� ������ ���
	{
		printf("����� ���谡 �ƴմϴ�.");
	}

	return 0;
}
