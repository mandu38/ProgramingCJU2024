#include<stdio.h>

int main(void)
{
	
	double Score; //��������
	int Convert; //switch case���� ������ ������ �����ϹǷ� ������ ������ ����

	Score = 0; //���� �ʱ�ȭ
	Convert = 0;

	printf("(������ȯ ���α׷� SC��)\n������ �Է��ϼ���\n");
	scanf_s("%lf", &Score);
	
	Convert = (Score >= 0 && Score <= 20) * 1 //�������� &&�� �̿��� ������ ������ Ȯ���ϰ� ������ ������ ������ ����
		+ (Score > 20 && Score <= 40) * 2
		+ (Score > 40 && Score <= 60) * 3
		+ (Score > 60 && Score <= 80) * 4
		+ (Score > 80 && Score <= 100) * 5;
	    
	switch (Convert) // �Է¹��� ������ ������ ������ Convert ������ switch case���� �̿��� Ư���������� �ٸ� ���� ���
	{
	case 1:
		printf("�л��� ����: %.1lf ��, F�����Դϴ�.", Score);
		break;
	case 2:
		printf("�л��� ����: %.1lf ��, D�����Դϴ�.", Score);
		break;
	case 3:
		printf("�л��� ����: %.1lf ��, C�����Դϴ�.", Score);
		break;
	case 4:
		printf("�л��� ����: %.1lf ��, B�����Դϴ�.", Score);
		break;
	case 5:
		printf("�л��� ����: %.1lf ��, A�����Դϴ�.", Score);
		break;
	default:
		printf("�����߻� 1~100������ ���ڸ� �Է����ּ���");
		break;
	}


	return 0;
}

