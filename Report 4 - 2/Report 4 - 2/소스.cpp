#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 랜덤 숫자 생성 함수
void GenRanNumber(int* pRandNumsCount, int* pSelecNumsCount, int* pSize, int* pMaxNum, int* pMinNum) 
{
    if (*pMaxNum < *pMinNum) { // 최소값이 최대값보다 클 경우의 상황을 대비
        int temp = *pMaxNum;
        *pMaxNum = *pMinNum;
        *pMinNum = temp;
    }

    // 100개의 랜덤한 숫자 생성
    for (int i = 0; i < 100; i++) 
    {
        *(pRandNumsCount + i) = (rand() % (*pMaxNum - *pMinNum + 1)) + *pMinNum;
    }

    // 랜덤한 숫자가 저장된 배열에서 10개의 숫자를 무작위로 선택
    for (int j = 0; j < *pSize; j++) 
    {
        int index = rand() % 100; // 0부터 99 사이의 인덱스로 범위 내에서 선택
        *(pSelecNumsCount + j) = *(pRandNumsCount + index);
    }
}

// 총합 계산 함수
int CalcSum(int* pSelecNumsCount, int* pSize, int* pSum) 
{
    *pSum = 0;
    for (int i = 0; i < *pSize; i++) 
    {
        *pSum += *(pSelecNumsCount + i);
    }
    return *pSum;
}

// 분산 계산 함수
double CalcVariance(int* pSelecNumsCount, int* pSize, double* pMean) 
{
    double temp = 0;
    for (int i = 0; i < *pSize; i++) 
    {
        temp += pow(*(pSelecNumsCount + i) - *pMean, 2);
    }
    return temp / *pSize;
}

// 표준편차 계산 함수
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

    int dLowRange = 0; //배열은 간접 참조 연산자가 필요없다. 배열명이 곧 주소를 의미하기 때문임
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
        
        printf("100개의 정수를 랜덤으로 생성하는 범위를 입력해주세요 (강제종료 : 1557 입력)\n최소값: ");
        if (scanf_s("%d", pLowRange) != 1  || *pLowRange == 1557) // 입력값이 정수가 아닌 경우 혹은 강제종료 코드 입력시 종료
        { 
            printf("프로그램을 강제 종료합니다. ");
            break;
        }

        printf("최대값: ");
        if (scanf_s("%d", pUpperRange) != 1 || *pLowRange == 1557)
        { 
            printf("프로그램을 강제 종료합니다.");
            break;
        }

        // 입력받은 값을 기반으로 랜덤 정수 생성
        GenRanNumber(pRandNumsCount, pSelecNumsCount, pSize, pUpperRange, pLowRange);

        // 총합 계산
        CalcSum(pSelecNumsCount, pSize, pSum);

        // 평균 계산
        double dMean = (double)*pSum / *pSize; // double로 형 변환 후 계산
        double* pMean = &dMean;

        // 분산 계산
        double dVariance = CalcVariance(pSelecNumsCount, pSize, pMean);
        double* pVariance = &dVariance;

        // 표준편차 계산
        double dStddev = CalcStddev(pVariance);

        // 결과출력
        printf("\n추출된 정수 10개:\n");
        for (int i = 0; i < *pSize; i++)
        {
            printf("  %d\n", *(pSelecNumsCount + i));
        }
        printf("\n총합: %d\n", *pSum);
        printf("평균: %.2lf\n", *pMean);
        printf("분산: %.2lf\n", *pVariance);
        printf("표준편차: %.2lf\n\n", dStddev);


    }
    

    return 0;
}
