// ������� �ҷ����� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100������ ������ ���ڸ� �����ϰ� ���

#define NUM_COUNT 10     // ������ ���� ����
#define NUM_MAXIMUM 100  // �ִ밪
#define NUM_MINIMUM 1    // �ּҰ�


// ���� �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// Ư�� ���� ������ ���� ���� ���� �Լ�
unsigned int GenRandNum(unsigned int nMax)
{
    return rand() % nMax  ;  // ������ �������� ������ ��ũ�η� ������ ���� ���� ���ڷ� ��ȯ
}

// ���� ��� �Լ�
unsigned int CalculateSum(unsigned int nSet[], unsigned int nCount)
{
    unsigned int nSum = 0;
    for (unsigned int i = 0; i < nCount; i++) // NUM_COUNT ��ŭ �ݺ�
    {
        nSum += nSet[i]; // �迭�� ������ �ټ��� ������ ���ʷ� ��� ���� nSum ������ ����
    }
    return nSum; // ��ȯ���� ���Ѱ��� ����� nSum ����
}

// ��� ��� �Լ�
double CalculateAverage(unsigned int nSum, unsigned int nCount) 
{
    return (double)nSum / nCount; // �Ѵ� ������ ����Ǿ��⿡ double �Լ��� �̿��� �Ǽ��� ��ȯ 
}

// �л� ��� �Լ�
double CalculateVariance(unsigned int nSet[], unsigned int nCount, double nAverage)
{
    double dVariance = 0.0;
    for (unsigned int i = 0; i < nCount; i++) // NUM_COUNT ��ŭ �ݺ�
    {
        dVariance += pow(nSet[i] - nAverage, 2); // �迭 �� �� ������ ����� �� ���� ������ ���� �� ���� ������ ������ ��� (pow�Լ��� �̿�) 
    }
    return dVariance / nCount; // NUM_COUNT ��ŭ ���� ���� ��ȯ 
}

// ǥ������ ��� �Լ�
double CalculateStanDev(double dVariance)
{
    return sqrt(dVariance); //sprt �Լ��� �̿��� ǥ�������� ���� 
}

int main(void)
{
    //�õ� �ʱ�ȭ
    GenRandSeed();

    printf("1~100������ ��������\n\n");

    // ������ ���� ���� �� �迭�� ����
    unsigned int nNumbers[NUM_COUNT]; //��ũ�η� ������ NUM_COUNT ����ŭ ������ ������
    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT��ŭ �ݺ�
    {
        nNumbers[i] = GenRandNum(NUM_MAXIMUM); //GenRandNum�Լ��� ���� �ּҰ��� �ִ밪 ������ ������ ������ ����
        printf("��������%d : %d\n", i + 1 , nNumbers[i]); // ������ ������ ������ ������ ���� ���ʷ� ���
    }

    printf("\n");

    // ���� 
    unsigned int nSum = CalculateSum(nNumbers, NUM_COUNT);
    printf("����: %d\n", nSum);

    // ���
    double dAverage = CalculateAverage(nSum, NUM_COUNT);
    printf("���: %.2lf\n", dAverage);

    // �л� 
    double dVariance = CalculateVariance(nNumbers, NUM_COUNT, dAverage);
    printf("�л�: %.2lf\n", dVariance);

    // ǥ������
    double dStd_dev = CalculateStanDev(dVariance);
    printf("ǥ������: %.2lf\n", dStd_dev);

    return 0;
}
