#include<stdio.h>

double Con1(double Tem) // �Լ� ����
{
    double Result1 = 0;
    Result1 = Tem * 1.8 + 32; // ���� > ȭ�� ��ȯ ����
    return Result1; // ��갪 ��ȯ
}

double Con2(double Tem)
{
    double Result1 = 0;
    Result1 = (Tem - 32) / 1.8; // ȭ�� > ���� ��ȯ ����
    return Result1;
}

int main(void)
{
    int Num1 = 0;
    double Tem = 0;
    double Result2 = 0;

    while (1) // ����ڰ� ���ϴ� ��ȯ���� ��� ���� �ܰ踦 �����ϰ� ���� �� �� �Է±��� ���ѽ���
    {
        printf("���� > ȭ�� ��ȯ�� 1 �Է� \nȭ�� > ���� ��ȯ�� 2 �Է�\n");
        scanf_s("%d", &Num1);

        if (Num1 == 1)
        {
            break;
        }
        else if (Num1 == 2)
        {
            break;
        }
        else
        {
            printf("�߸��� �Է��Դϴ�. 1�Ǵ� 2�� �Է��ϼ���.\n");
        }
    }

    printf("��ȯ�� �µ��� �Է����ּ���\n");
    scanf_s("%lf", &Tem);

    switch (Num1)
    {
    case 1:// ù��° �Է¹��� ���� 1�� ��� ���� > ȭ���� ����
        Result2 = Con1(Tem);
        printf("��ȯ ��� ���� %.1lf > ȭ�� %.1lf ", Tem, Result2); // ���� > ȭ�� ��ȯ �Լ� ȣ���Ͽ� ����ϰ� ���
        break;
    case 2:
        Result2 = Con2(Tem);
        printf("��ȯ ��� ȭ�� %.1lf > ���� %.1lf ", Tem, Result2);  // ȭ�� > ���� ��ȯ �Լ� ȣ���Ͽ� ����ϰ� ���
        break;

    default:
        printf("������ �߻��߽��ϴ�.");
    }

    return 0;
}
