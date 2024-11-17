// 헤더파일 불러오기 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100까지의 무작위 숫자를 생성하고 계산

#define NUM_COUNT 10     
#define NUM_MAXIMUM 100



// 랜덤 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 특정 범위 내에서 랜덤 숫자 생성 함수
unsigned int GenRandNum(unsigned int nMax)
{
    return rand() % nMax;  
}

int main(void)
{
    //시드 초기화
    GenRandSeed();

    unsigned int nPlayerNum = 0;
    

    printf("1~100사이의 무작위 정수가 생성되었습니다. \n정수를 입력해주세요\n");

    unsigned int nRandomNum = 0;
    nRandomNum = GenRandNum(NUM_MAXIMUM);

    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT만큼 반복
    {
        
        scanf_s("%d", &nPlayerNum);

        if (nPlayerNum == nRandomNum)
        {
            printf("정답입니다!");
            break;
        }
        else if ((nPlayerNum < 0) || (nPlayerNum > 100))
        {
            printf("0~100사이의 정수값을 입력해주세요\n");
            continue;
        }
        else if (nPlayerNum < nRandomNum)
        {
            printf("UP\n\n");
            continue;
        }
        else if (nPlayerNum > nRandomNum)
        {
            printf("DOWN\n\n");
            continue;
        }
        else
        {
            printf("오류가 발생했습니다. 다시 실행해주세요");
            break; 
        }

    }


    printf("정답은 %d 였습니다.", nRandomNum);

    return 0;
}
