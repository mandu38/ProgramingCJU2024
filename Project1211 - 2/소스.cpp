#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 함수 선언
void Calculate(int* nArray, int nArraySize, double* pSum, double* pAvg, double* pVariance, double* pStdDev)
{
    *pSum = 0;
    for (int i = 0; i < nArraySize; i++)  // 총합
    {
        *pSum += *(nArray + i); // 배열 요소에 포인터 연산 사용
    }
    *pAvg = *pSum / nArraySize; //평균

    *pVariance = 0; // 분산값 초기화 
    for (int i = 0; i < nArraySize; i++)
    {
        *pVariance += (*(nArray + i) - *pAvg) * (*(nArray + i) - *pAvg); // 포인터 연산으로 평균 차이 계산
    }
    *pVariance /= nArraySize; // 분산 

    *pStdDev = sqrt(*pVariance); // 표준편차
}


int main(void)
{
    int nArraySize, nAddArraySize;
    int* nArray; // 포인터 변수
    double dSum, dAvg, dVariance, dStdDev;

    // 포인터 선언
    int* pArraySize = &nArraySize;
    double* pSum = &dSum;
    double* pAvg = &dAvg;
    double* pVariance = &dVariance;
    double* pStdDev = &dStdDev;

    // 초기 배열 크기 입력
    printf("초기 배열의 크기를 입력해주세요 : ");
    scanf_s("%d", pArraySize);

    // 메모리 동적 할당
    nArray = (int*)malloc(*pArraySize * sizeof(int));

    // 배열 내 값이 NULL일 경우를 방지
    if (nArray == NULL)
    {
        printf("메모리 동적 할당에 실패했습니다.\n");
        return 1; // 프로그램 종료
    }

    // 초기 배열 값 입력
    printf("초기 배열의 크기 : %d \n\n", nArraySize);
    for (int i = 0; i < nArraySize; i++) 
    {
        printf("[%d] 자리의 정수를 입력해주세요 :  ",i);
        scanf_s("%d", &nArray[i]);
    }

    // 통계 계산 및 출력
    Calculate(nArray, *pArraySize, pSum, pAvg, pVariance, pStdDev);
    printf("합계: % .2lf\n평균 : % .2lf\n분산 : % .2lf\n표준편차 : % .2lf\n\n",
        *pSum, *pAvg, *pVariance, *pStdDev);

    // 추가 배열 크기 입력
    printf("추가 배열을 입력해주세요: ");
    scanf_s("%d", &nAddArraySize);

    // 추가 메모리 동적 재할당이므로 malloc 함수가 아닌 realloc 함수 사용
    nArray = (int*)realloc(nArray, (nArraySize + nAddArraySize) * sizeof(int));
    if (nArray == NULL) // 메모리 낭비 방지
    {
        printf("메모리 동적 할당에 실패했습니다.\n");
        return 1;
    }

    // 크기 업데이트
    nArraySize += nAddArraySize;

    // 추가 배열 값 입력
    printf("추가 배열 크기 : %d \n\n", nAddArraySize);
    for (int i = nArraySize - nAddArraySize; i < nArraySize; i++) 
    {
        printf("[%d] 자리 정수를 입력해주세요 :  ", i);
        scanf_s("%d", &nArray[i]);
    }

    // 업데이트된 배열 통계 계산 및 출력
    Calculate(nArray, nArraySize, pSum, pAvg, pVariance, pStdDev);
    printf("합계: % .2lf\n평균 : % .2lf\n분산 : % .2lf\n표준편차 : % .2lf\n",
        *pSum, *pAvg, *pVariance, *pStdDev);

    // 메모리 해제
    free(nArray);
    return 0;
}

