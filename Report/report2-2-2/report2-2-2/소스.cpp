#include<stdio.h>

int main(void)
{
	int Num1; // ��������
	int Num2;
	int Result;

	Num1 = 0; // ���� �ʱ�ȭ 
	Num2 = 0;
	Result = 0;

	printf("�� ���� ������ �Է��ϼ���(switch case��)\n");
	scanf_s("%d %d", &Num1, &Num2); //scanf_s �Լ��� ���� �Է¹ް� ������ ������ ����

	Result = Num1 % Num2; // Num1 ������ ����� ���� Num2 ������ ����� ������ ���� ���������� Result ������ ����

	switch (Result)
	{
	case 0: // Result ������ ����� ���� 0�� ��� �ش� ���� ���
		printf("����� ���谡 �½��ϴ�.");
		break;
		
	default:// Result ������ ����� ���� 0�� �ƴ� ������ ���� �ش� ���� ���
		printf("����� ���谡 �ƴմϴ�.");
		break;
	}

	return 0; //���α׷� ����
}
