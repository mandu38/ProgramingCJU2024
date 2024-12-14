#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(double* dArray, int* nSize, int* nOption) //���� -100~ +100 ������ �����Ͽ� ���� ���� �� �Ǽ� ���
{
    if (*nOption == 1) // ���� ��� �ɼ�
    {
        for (int i = 0; i < *nSize; i++)
        {
            dArray[i] = (double)((rand() % 201) - 100);
        }
    }
    else if (*nOption == 2) // �Ǽ� ��� �ɼ�
    {
        for (int i = 0; i < *nSize; i++)
        {
            dArray[i] = ((rand() / (double)RAND_MAX) * 200.0) - 100.0; // ������ ê ����Ƽ�� ������ �޾���
        }
    }
    else
    {
        printf("1 (����) Ȥ�� 2 (�Ǽ�) �߿��� �Է��Ͽ� �ɼ��� �������ּ���\n");
    }
}

void CalcInverseArray(double* dArray, int* nSize)// ���� ���� �� ���� ���� �Լ�
{
    printf("\n���� ��� �Ϸ�");
    for (int i = 0; i < *nSize / 2; i++) // ũ�� ������� ������ �ݴ�� �Ͽ� ����
    {
        double temp = dArray[i];
        dArray[i] = dArray[*nSize - 1 - i];
        dArray[*nSize - 1 - i] = temp;
    }
}

void PrintfArray(double* dArray, int* nSize, int* pOption)
{
    if (*pOption == 1) // ���� ���
    {
        for (int i = 0; i < *nSize; i++)
        {
            printf("%d\n", (int)dArray[i]); // ������ ���
        }
    }
    else if (*pOption == 2) // �Ǽ� ���
    {
        for (int i = 0; i < *nSize; i++)
        {
            printf("%.2lf\n", dArray[i]); // �Ǽ��� ���
        }
    }
    else
    {
        printf("1 Ȥ�� 2�� �Է����ּ���\n");
    }
}

int main(void)
{
    int nOption = 0;
    int* pOption = &nOption;

    int nSize = 10;
    int* pSize = &nSize;

    double dArray[10];
    double* pArray = dArray;

    printf("���� �õ� ���� ���� ���� ���α׷�\n");

    printf("\n<1 �Է� : ������ ���>\t<2 �Է� : �Ǽ��� ���>\n\n");
    scanf_s("%d", pOption);






    // ���� �õ� �Լ� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // ���� ���� ����
    GenRanNumber(pArray, pSize, pOption);

    printf("���� ���� ���� ����\n");
    PrintfArray(pArray, pSize, pOption);



    // �������� �迭 ����
    CalcInverseArray(pArray, pSize);

    printf("\n");

    // ���ĵ� ���� ���
    PrintfArray(pArray, pSize, pOption);

    return 0;
}
