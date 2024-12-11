#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �Լ� ����
void Calculate(int* nArray, int nArraySize, double* pSum, double* pAvg, double* pVariance, double* pStdDev)
{
    *pSum = 0;
    for (int i = 0; i < nArraySize; i++)  // ����
    {
        *pSum += *(nArray + i); // �迭 ��ҿ� ������ ���� ���
    }
    *pAvg = *pSum / nArraySize; //���

    *pVariance = 0; // �л갪 �ʱ�ȭ 
    for (int i = 0; i < nArraySize; i++)
    {
        *pVariance += (*(nArray + i) - *pAvg) * (*(nArray + i) - *pAvg); // ������ �������� ��� ���� ���
    }
    *pVariance /= nArraySize; // �л� 

    *pStdDev = sqrt(*pVariance); // ǥ������
}


int main(void)
{
    int nArraySize, nAddArraySize;
    int* nArray; // ������ ����
    double dSum, dAvg, dVariance, dStdDev;

    // ������ ����
    int* pArraySize = &nArraySize;
    double* pSum = &dSum;
    double* pAvg = &dAvg;
    double* pVariance = &dVariance;
    double* pStdDev = &dStdDev;

    // �ʱ� �迭 ũ�� �Է�
    printf("�ʱ� �迭�� ũ�⸦ �Է����ּ��� : ");
    scanf_s("%d", pArraySize);

    // �޸� ���� �Ҵ�
    nArray = (int*)malloc(*pArraySize * sizeof(int));

    // �迭 �� ���� NULL�� ��츦 ����
    if (nArray == NULL)
    {
        printf("�޸� ���� �Ҵ翡 �����߽��ϴ�.\n");
        return 1; // ���α׷� ����
    }

    // �ʱ� �迭 �� �Է�
    printf("�ʱ� �迭�� ũ�� : %d \n\n", nArraySize);
    for (int i = 0; i < nArraySize; i++) 
    {
        printf("[%d] �ڸ��� ������ �Է����ּ��� :  ",i);
        scanf_s("%d", &nArray[i]);
    }

    // ��� ��� �� ���
    Calculate(nArray, *pArraySize, pSum, pAvg, pVariance, pStdDev);
    printf("�հ�: % .2lf\n��� : % .2lf\n�л� : % .2lf\nǥ������ : % .2lf\n\n",
        *pSum, *pAvg, *pVariance, *pStdDev);

    // �߰� �迭 ũ�� �Է�
    printf("�߰� �迭�� �Է����ּ���: ");
    scanf_s("%d", &nAddArraySize);

    // �߰� �޸� ���� ���Ҵ��̹Ƿ� malloc �Լ��� �ƴ� realloc �Լ� ���
    nArray = (int*)realloc(nArray, (nArraySize + nAddArraySize) * sizeof(int));
    if (nArray == NULL) // �޸� ���� ����
    {
        printf("�޸� ���� �Ҵ翡 �����߽��ϴ�.\n");
        return 1;
    }

    // ũ�� ������Ʈ
    nArraySize += nAddArraySize;

    // �߰� �迭 �� �Է�
    printf("�߰� �迭 ũ�� : %d \n\n", nAddArraySize);
    for (int i = nArraySize - nAddArraySize; i < nArraySize; i++) 
    {
        printf("[%d] �ڸ� ������ �Է����ּ��� :  ", i);
        scanf_s("%d", &nArray[i]);
    }

    // ������Ʈ�� �迭 ��� ��� �� ���
    Calculate(nArray, nArraySize, pSum, pAvg, pVariance, pStdDev);
    printf("�հ�: % .2lf\n��� : % .2lf\n�л� : % .2lf\nǥ������ : % .2lf\n",
        *pSum, *pAvg, *pVariance, *pStdDev);

    // �޸� ����
    free(nArray);
    return 0;
}

