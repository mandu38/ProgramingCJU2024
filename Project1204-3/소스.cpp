#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(int* dArray, int* nSize)
{
    for (int i = 0; i < *nSize; i++)
    {
        dArray[i] = (rand() % 100); // 0~99 범위의 정수 생성
    }
}

void CalcEvenOddArray(int* dArray, int* nSize, int* pEvenArray, int* pOddArray, int* dEvenCount, int* dOddCount)
{
    *dEvenCount = 0;
    *dOddCount = 0;

    for (int i = 0; i < *nSize; i++)
    {
        if (dArray[i] % 2 == 0) // 짝수인 경우
        {
            pEvenArray[*dEvenCount] = dArray[i];
            (*dEvenCount)++;
        }
        else // 홀수인 경우
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
        int temp = dArray[i]; // 임시 변수에 i 값 저장
        dArray[i] = dArray[*nSize - 1 - i];
        dArray[*nSize - 1 - i] = temp;
    }
}

void PrintfArray(int* dArray, int nSize) // 홀수 짝수 개수만큼 반복되게끔 연동하여 함수 재사용
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

    // 랜덤 시드 함수 초기화
    srand((unsigned int)time(NULL));

    // 랜덤 숫자 생성
    GenRanNumber(pArray, pSize);

    printf("랜덤 정수 생성 상태:\n");
    PrintfArray(pArray, *pSize);

    // 역순 계산
    CalcInverseArray(pArray, pSize);

    printf("역순 배열 출력:\n");
    PrintfArray(pArray, *pSize);

    // 짝수와 홀수 배열 분리 함수 호출
    CalcEvenOddArray(pArray, pSize, pEvenArray, pOddArray, &dEvenCount, &dOddCount); //&연산자를 통해 함수 바깥에서도 값이 저장되게끔 하였음

    printf("\n짝수 배열:\n");
    PrintfArray(pEvenArray, dEvenCount);

    printf("홀수 배열:\n");
    PrintfArray(pOddArray, dOddCount);

    return 0;
}


