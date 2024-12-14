#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(double* dArray, int* nSize, int* nOption) //범위 -100~ +100 범위를 지정하여 랜덤 정수 및 실수 출력
{
    if (*nOption == 1) // 정수 출력 옵션
    {
        for (int i = 0; i < *nSize; i++)
        {
            dArray[i] = (double)((rand() % 201) - 100);
        }
    }
    else if (*nOption == 2) // 실수 출력 옵션
    {
        for (int i = 0; i < *nSize; i++)
        {
            dArray[i] = ((rand() / (double)RAND_MAX) * 200.0) - 100.0; // 수식은 챗 지피티의 도움을 받았음
        }
    }
    else
    {
        printf("1 (정수) 혹은 2 (실수) 중에서 입력하여 옵션을 선택해주세요\n");
    }
}

void CalcInverseArray(double* dArray, int* nSize)// 랜덤 생성 수 역순 나열 함수
{
    printf("\n역순 계산 완료");
    for (int i = 0; i < *nSize / 2; i++) // 크기 상관없이 순서만 반대로 하여 나열
    {
        double temp = dArray[i];
        dArray[i] = dArray[*nSize - 1 - i];
        dArray[*nSize - 1 - i] = temp;
    }
}

void PrintfArray(double* dArray, int* nSize, int* pOption)
{
    if (*pOption == 1) // 정수 출력
    {
        for (int i = 0; i < *nSize; i++)
        {
            printf("%d\n", (int)dArray[i]); // 정수로 출력
        }
    }
    else if (*pOption == 2) // 실수 출력
    {
        for (int i = 0; i < *nSize; i++)
        {
            printf("%.2lf\n", dArray[i]); // 실수로 출력
        }
    }
    else
    {
        printf("1 혹은 2를 입력해주세요\n");
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

    printf("랜덤 시드 생성 역순 나열 프로그램\n");

    printf("\n<1 입력 : 정수로 출력>\t<2 입력 : 실수로 출력>\n\n");
    scanf_s("%d", pOption);






    // 랜덤 시드 함수 초기화
    srand((unsigned int)time(NULL));

    // 랜덤 숫자 생성
    GenRanNumber(pArray, pSize, pOption);

    printf("랜덤 생성 숫자 상태\n");
    PrintfArray(pArray, pSize, pOption);



    // 역순으로 배열 정렬
    CalcInverseArray(pArray, pSize);

    printf("\n");

    // 정렬된 숫자 출력
    PrintfArray(pArray, pSize, pOption);

    return 0;
}
