// 헤더파일 불러오기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

// 매크로 지정
#define NUM_FLIP 10000
#define COIN_FND_STATUS 1
#define COIN_BND_STATUS 2
#define COIN_FND_BWD 3

#define INISTATUS 100
#define END_COND 999



// 랜덤 시드 생성
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 앞면과 뒷면을 각각 1과 2로 설정하고 난수 지정 함수를 이용한 동전 던지기 함수 
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        unsigned int nNum = rand();  // nNum을 rand()를 통해 매번 난수로 설정
        nRes = nNum % nRange;  // nRange 범위 내의 값을 nRes에 할당

        if ((nRes == COIN_FND_STATUS) || (nRes == COIN_BND_STATUS)) // || 또는 연산자를 통해 둘 중 하나의 조건 만족시 탈출
        {
            break;
        }
    }
    return nRes;
}


// 앞면확률계산 함수
unsigned int FndCalCulateFlipCoin(unsigned int nNumSumFwdFlip)
{
    return (nNumSumFwdFlip * 100) / NUM_FLIP;
}

// 뒷면확률계산 함수
unsigned int BndCalCulateFlipCoin(unsigned int nNumSumBwdFlip)
{
    return (nNumSumBwdFlip * 100) / NUM_FLIP;
}

int main(void)
{
    // 시드초기화
    GenRandSeed();

    // 변수초기화
    int nNumSumFwdFlip = 0; // 앞면 개수
    int nNumSumBwdFlip = 0; // 뒷면 개수

    // 사전에 정의한 NUM_FLIP을 통해 만번 반복
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        //정의된 COIN_FND_BWD 매크로를 통해 GenRandFlipCoin 함수 호출시 인수를 3으로 전달함
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FND_BWD);

        // 앞면, 뒷면 계산
        switch (nStatusFlipCoin)
        {
        case COIN_FND_STATUS: //앞면일시 앞면 개수 저장 변수에 +1추가 
            nNumSumFwdFlip++;
            break;

        case COIN_BND_STATUS: //뒷면일시 뒷면 개수 저장 변수에 +1추가 
            nNumSumBwdFlip++;
            break;

        default:
            printf("에러\n"); //이외의 상황은 에러로 지정
        }
    }

    // // 함수를 호출하고 반복하여 계산한값을 인수로 확률을 계산
    double dStdevFwdFlip = FndCalCulateFlipCoin(nNumSumFwdFlip); 
    double dStdevDwdFlip = BndCalCulateFlipCoin(nNumSumBwdFlip);

    // 결과 출력
    printf("앞면: %d회, 뒷면: %d회\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("앞면 확률: %.2lf%%, 뒷면 확률: %.2lf%%\n", dStdevFwdFlip, dStdevDwdFlip);

    return 0;
}
