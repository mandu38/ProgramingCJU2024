#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ���� ���� ���� �Լ�
void GenRanNumber(int* pRandNumsCount, int* pSelecNumsCount, int* pSize, int* pMaxNum, int* pMinNum) 
{
    if (*pMaxNum < *pMinNum) { // �ּҰ��� �ִ밪���� Ŭ ����� ��Ȳ�� ���
        int temp = *pMaxNum;
        *pMaxNum = *pMinNum;
        *pMinNum = temp;
    }

    // 100���� ������ ���� ����
    for (int i = 0; i < 100; i++) 
    {
        *(pRandNumsCount + i) = (rand() % (*pMaxNum - *pMinNum + 1)) + *pMinNum;
    }

    // ������ ���ڰ� ����� �迭���� 10���� ���ڸ� �������� ����
    for (int j = 0; j < *pSize; j++) 
    {
        int index = rand() % 100; // 0���� 99 ������ �ε����� ���� ������ ����
        *(pSelecNumsCount + j) = *(pRandNumsCount + index);
    }
}

// ���� ��� �Լ�
int CalcSum(int* pSelecNumsCount, int* pSize, int* pSum) 
{
    *pSum = 0;
    for (int i = 0; i < *pSize; i++) 
    {
        *pSum += *(pSelecNumsCount + i);
    }
    return *pSum;
}

// �л� ��� �Լ�
double CalcVariance(int* pSelecNumsCount, int* pSize, double* pMean) 
{
    double temp = 0;
    for (int i = 0; i < *pSize; i++) 
    {
        temp += pow(*(pSelecNumsCount + i) - *pMean, 2);
    }
    return temp / *pSize;
}

// ǥ������ ��� �Լ�
double CalcStddev(double* pVariance)
{
    return sqrt(*pVariance);
}

int main(void) 
{
    int dRandNumsCount[100];
    int* pRandNumsCount = dRandNumsCount;

    int dSelecNumsCount[10];
    int* pSelecNumsCount = dSelecNumsCount;

    int dLowRange = 0; //�迭�� ���� ���� �����ڰ� �ʿ����. �迭���� �� �ּҸ� �ǹ��ϱ� ������
    int* pLowRange = &dLowRange;

    int dUpperRange = 0;
    int* pUpperRange = &dUpperRange;

    int dSize = 10;
    int* pSize = &dSize;

    int dSum = 0;
    int* pSum = &dSum;

    srand((unsigned int)time(NULL));

    while (1)
    {
        
        printf("100���� ������ �������� �����ϴ� ������ �Է����ּ��� (�������� : 1557 �Է�)\n�ּҰ�: ");
        if (scanf_s("%d", pLowRange) != 1  || *pLowRange == 1557) // �Է°��� ������ �ƴ� ��� Ȥ�� �������� �ڵ� �Է½� ����
        { 
            printf("���α׷��� ���� �����մϴ�. ");
            break;
        }

        printf("�ִ밪: ");
        if (scanf_s("%d", pUpperRange) != 1 || *pLowRange == 1557)
        { 
            printf("���α׷��� ���� �����մϴ�.");
            break;
        }

        // �Է¹��� ���� ������� ���� ���� ����
        GenRanNumber(pRandNumsCount, pSelecNumsCount, pSize, pUpperRange, pLowRange);

        // ���� ���
        CalcSum(pSelecNumsCount, pSize, pSum);

        // ��� ���
        double dMean = (double)*pSum / *pSize; // double�� �� ��ȯ �� ���
        double* pMean = &dMean;

        // �л� ���
        double dVariance = CalcVariance(pSelecNumsCount, pSize, pMean);
        double* pVariance = &dVariance;

        // ǥ������ ���
        double dStddev = CalcStddev(pVariance);

        // ������
        printf("\n����� ���� 10��:\n");
        for (int i = 0; i < *pSize; i++)
        {
            printf("  %d\n", *(pSelecNumsCount + i));
        }
        printf("\n����: %d\n", *pSum);
        printf("���: %.2lf\n", *pMean);
        printf("�л�: %.2lf\n", *pVariance);
        printf("ǥ������: %.2lf\n\n", dStddev);


    }
    

    return 0;
}
