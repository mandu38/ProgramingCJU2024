#include <stdio.h>
#include <math.h>

int main(void)
{

	int Thousand; //�������� 
	int FiveHundred;
	int Hundred;
	double Amount;
	double Object;
	double Change;
	double ChangeRemainder;
	double FiveRemainder;

	Amount = 0;  //���� �ʱ�ȭ
	Object = 0;
	Change = 0;
	Thousand = 0;
	FiveHundred = 0;
	Hundred = 0;
	ChangeRemainder = 0;
	FiveRemainder = 0;


	printf("������ �ݾװ� ���ǰ��� ���ʴ�� �Է����ּ���.\n"); // �Է¹��� ���� ���� ���� ��� 
	scanf_s("%lf%lf", &Amount, &Object); // �� �Է¹ް� ������ ����

	Change = Amount - Object; // �ݾװ� ���ǰ��� �� Change ������ ����

	Change = ((Change > 0) * Amount) - ((Change > 0) * Object); //�Ž������� ������ �������� �����ų� �߸��ԷµǴ� ��Ȳ ����

	Thousand = Change / 1000; // �Ž������� 1000���� ������ õ���� ����� ���ϰ� Thousand ������ ���� 

	ChangeRemainder = fmod(Change, 1000); //fmod �Լ��� ���� �Ž������� 1000���� �������� ���������� ChangeRemainder�� ����

	FiveRemainder = fmod(ChangeRemainder,500); //fmod �Լ��� ����ChangeRemainder�� ����� ���� 500���� �������� ���������� FiveRemainder�� ����

	FiveHundred = ChangeRemainder / 500; //�Ž������� 1000���� ����  ChangeRemainder�� ����� ���� 500���� ������ 500���� ���� ����ϰ� FiveHundred�� ����

	Hundred = FiveRemainder / 100; // FiveRemainder�� ����� ���������� 100���� ������ 100���� ������ ����ϰ� ���

	printf("�ʿ��� �Ž����� : %.1lf\n õ�� %d��\n ����� %d��\n ��� %d��\n", Change, Thousand, FiveHundred, Hundred); //���� ���� �Ž�����,õ���� ���, ������� ����, ����� ���� ��� 

	return 0; //���α׷� ����

}