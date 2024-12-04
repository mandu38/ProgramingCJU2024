#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(int* dArray, int* nSize)
{
    for (int i = 0; i < *nSize; i++)
    {
        dArray[i] = (rand() % 100); // 0~99 ������ ���� ����
    }
}

void CalcEvenOddArray(int* dArray, int* nSize, int* pEvenArray, int* pOddArray, int* dEvenCount, int* dOddCount)
{
    *dEvenCount = 0;
    *dOddCount = 0;

    for (int i = 0; i < *nSize; i++)
    {
        if (dArray[i] % 2 == 0) // ¦���� ���
        {
            pEvenArray[*dEvenCount] = dArray[i];
            (*dEvenCount)++;
        }
        else // Ȧ���� ���
        {
            pOddArray[*dOddCount] = dArray[i];
            (*dOddCount)++;
        }
    }
}

void CalcInverseArray(int* dArray, int* nSize)
{
    for (int i = 0; i < *nSize / 2; i++)
    {
        int temp = dArray[i]; // �ӽ� ������ i �� ����
        dArray[i] = dArray[*nSize - 1 - i];
        dArray[*nSize - 1 - i] = temp;
    }
}

void PrintfArray(int* dArray, int nSize) // Ȧ�� ¦�� ������ŭ �ݺ��ǰԲ� �����Ͽ� �Լ� ����
{
    for (int i = 0; i < nSize; i++)
    {
        printf("%d\n", dArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int nSize = 10;
    int* pSize = &nSize;

    int dArray[10];
    int* pArray = dArray;

    int dEvenArray[10];
    int* pEvenArray = dEvenArray;

    int dOddArray[10];
    int* pOddArray = dOddArray;

    int dEvenCount = 0, dOddCount = 0;

    // ���� �õ� �Լ� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // ���� ���� ����
    GenRanNumber(pArray, pSize);

    printf("���� ���� ���� ����:\n");
    PrintfArray(pArray, *pSize);

    // ���� ���
    CalcInverseArray(pArray, pSize);

    printf("���� �迭 ���:\n");
    PrintfArray(pArray, *pSize);

    // ¦���� Ȧ�� �迭 �и� �Լ� ȣ��
    CalcEvenOddArray(pArray, pSize, pEvenArray, pOddArray, &dEvenCount, &dOddCount); //&�����ڸ� ���� �Լ� �ٱ������� ���� ����ǰԲ� �Ͽ���

    printf("\n¦�� �迭:\n");
    PrintfArray(pEvenArray, dEvenCount);

    printf("Ȧ�� �迭:\n");
    PrintfArray(pOddArray, dOddCount);

    return 0;
}


