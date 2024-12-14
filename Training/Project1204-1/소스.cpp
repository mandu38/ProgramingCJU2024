#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRanNumber(double* dArray, int* nSize, int* nOption)
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
            dArray[i] = ((rand() / (double)RAND_MAX) * 200.0) - 100.0;
        }
    }
    else
    {
        printf("1 (정수) 혹은 2 (실수) 중에서 입력하여 옵션을 선택해주세요\n");
    }
}

void CalSortArray(double* dArray, int* nSize, int* nAscending) 
{
    for (int i = 0; i < *nSize - 1; i++)
    {
        for (int j = 0; j < *nSize - i - 1; j++)
        {
            if (((*nAscending == 1) && dArray[j] > dArray[j + 1]) || // 1번 옵션이면서 dArray j값의 위치한 값이 +1 한 위치보다 클 경우 혹은 2번 옵션인데 j값의dArray j값의 위치한 값이 +1 한 위치보다 작을 경우 수식 전개
                (( * nAscending == 2) && dArray[j] < dArray[j + 1]))
            {
                double temp = dArray[j]; //임시 변수에 값을 저장하고 옮기는 것을 반복
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

    printf("<1 입력 : 정수로 출력>\t<2 입력 : 실수로 출력>\n");
    scanf_s("%d", pOption);

    // 랜덤 시드 함수 초기화
    srand((unsigned int)time(NULL));

    // 랜덤 숫자 생성
    GenRanNumber(pArray, pSize, pOption);

    printf("<1 입력 : 내림차순으로 출력>\t<2 입력 : 오름차순으로 출력>\n");
    scanf_s("%d", pOption);

    if (*pOption == 1)
    {
        CalSortArray(pArray, pSize, pOption);
        printf("내림차순 정렬된 숫자:\n");
    }
    else if (*pOption == 2)
    {
        CalSortArray(pArray, pSize, pOption);
        printf("오름차순 정렬된 숫자:\n");
    }
    else
    {
        printf("1 혹은 2를 입력하여 주세요\n");
        return 1;
    }

    // 정렬된 숫자 출력
    PrintfArray(pArray, pSize);

    return 0;
}

