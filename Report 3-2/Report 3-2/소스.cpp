// 헤더파일 불러오기 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100까지의 무작위 숫자를 생성하고 계산

#define NUM_COUNT 10     // 생성할 숫자 개수
#define NUM_MAXIMUM 100  // 최대값
#define NUM_MINIMUM 1    // 최소값


// 랜덤 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 특정 범위 내에서 랜덤 숫자 생성 함수
unsigned int GenRandNum(unsigned int nMax)
{
    return rand() % nMax  ;  // 생성한 무작위의 정수를 매크로로 지정한 범위 내의 숫자로 변환
}

// 총합 계산 함수
unsigned int CalculateSum(unsigned int nSet[], unsigned int nCount)
{
    unsigned int nSum = 0;
    for (unsigned int i = 0; i < nCount; i++) // NUM_COUNT 만큼 반복
    {
        nSum += nSet[i]; // 배열로 저장한 다수의 정수를 차례로 모두 더해 nSum 변수에 저장
    }
    return nSum; // 반환값은 더한값이 저장된 nSum 변수
}

// 평균 계산 함수
double CalculateAverage(unsigned int nSum, unsigned int nCount) 
{
    return (double)nSum / nCount; // 둘다 정수로 선언되었기에 double 함수를 이용해 실수로 변환 
}

// 분산 계산 함수
double CalculateVariance(unsigned int nSet[], unsigned int nCount, double nAverage)
{
    double dVariance = 0.0;
    for (unsigned int i = 0; i < nCount; i++) // NUM_COUNT 만큼 반복
    {
        dVariance += pow(nSet[i] - nAverage, 2); // 배열 내 각 값에서 평균을 뺀 값의 제곱을 더한 후 값의 개수로 나누어 계산 (pow함수를 이용) 
    }
    return dVariance / nCount; // NUM_COUNT 만큼 나눈 값을 반환 
}

// 표준편차 계산 함수
double CalculateStanDev(double dVariance)
{
    return sqrt(dVariance); //sprt 함수를 이용해 표준편차를 구함 
}

int main(void)
{
    //시드 초기화
    GenRandSeed();

    printf("1~100까지의 랜덤정수\n\n");

    // 무작위 정수 생성 및 배열에 저장
    unsigned int nNumbers[NUM_COUNT]; //매크로로 지정한 NUM_COUNT 수만큼 변수를 저장함
    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT만큼 반복
    {
        nNumbers[i] = GenRandNum(NUM_MAXIMUM); //GenRandNum함수를 통해 최소값과 최대값 사이의 무작위 정수를 생성
        printf("랜덤정수%d : %d\n", i + 1 , nNumbers[i]); // 생성한 정수의 순서와 정수의 값을 차례로 출력
    }

    printf("\n");

    // 총합 
    unsigned int nSum = CalculateSum(nNumbers, NUM_COUNT);
    printf("총합: %d\n", nSum);

    // 평균
    double dAverage = CalculateAverage(nSum, NUM_COUNT);
    printf("평균: %.2lf\n", dAverage);

    // 분산 
    double dVariance = CalculateVariance(nNumbers, NUM_COUNT, dAverage);
    printf("분산: %.2lf\n", dVariance);

    // 표준편차
    double dStd_dev = CalculateStanDev(dVariance);
    printf("표준편차: %.2lf\n", dStd_dev);

    return 0;
}
