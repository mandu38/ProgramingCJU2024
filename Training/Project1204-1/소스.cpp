#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(double* dArray, int* nSize, int* nOption)
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
            dArray[i] = ((rand() / (double)RAND_MAX) * 200.0) - 100.0;
        }
    }
    else
    {
        printf("1 (����) Ȥ�� 2 (�Ǽ�) �߿��� �Է��Ͽ� �ɼ��� �������ּ���\n");
    }
}

void CalSortArray(double* dArray, int* nSize, int* nAscending) 
{
    for (int i = 0; i < *nSize - 1; i++)
    {
        for (int j = 0; j < *nSize - i - 1; j++)
        {
            if (((*nAscending == 1) && dArray[j] > dArray[j + 1]) || // 1�� �ɼ��̸鼭 dArray j���� ��ġ�� ���� +1 �� ��ġ���� Ŭ ��� Ȥ�� 2�� �ɼ��ε� j����dArray j���� ��ġ�� ���� +1 �� ��ġ���� ���� ��� ���� ����
                (( * nAscending == 2) && dArray[j] < dArray[j + 1]))
            {
                double temp = dArray[j]; //�ӽ� ������ ���� �����ϰ� �ű�� ���� �ݺ�
                dArray[j] = dArray[j + 1];
                dArray[j + 1] = temp;
            }
        }
    }
}

void PrintfArray(double* dArray, int* nSize)
{
    for (int i = 0; i < *nSize; i++)
    {
        printf("%.2f\n", dArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int nOption = 0;
    int* pOption = &nOption;

    int nSize = 10;
    int* pSize = &nSize;

    double dArray[10];
    double* pArray = dArray;

    printf("<1 �Է� : ������ ���>\t<2 �Է� : �Ǽ��� ���>\n");
    scanf_s("%d", pOption);

    // ���� �õ� �Լ� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // ���� ���� ����
    GenRanNumber(pArray, pSize, pOption);

    printf("<1 �Է� : ������������ ���>\t<2 �Է� : ������������ ���>\n");
    scanf_s("%d", pOption);

    if (*pOption == 1)
    {
        CalSortArray(pArray, pSize, pOption);
        printf("�������� ���ĵ� ����:\n");
    }
    else if (*pOption == 2)
    {
        CalSortArray(pArray, pSize, pOption);
        printf("�������� ���ĵ� ����:\n");
    }
    else
    {
        printf("1 Ȥ�� 2�� �Է��Ͽ� �ּ���\n");
        return 1;
    }

    // ���ĵ� ���� ���
    PrintfArray(pArray, pSize);

    return 0;
}

