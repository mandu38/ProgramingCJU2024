// 헤더파일 불러오기 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100까지의 무작위 숫자를 생성하고 계산

#define NUM_COUNT 10 // 실행하고자 하는 횟수 매크로 지정

#define NUM_MAXIMUM 100 // 1~100까지의 숫자 지정을 위해 100 상수로 지정
#define NUM_UP 101 //100 이내의 정수로 매크로를 지정할 경우 오류 발생 방지를 위해 100을 초과한 범위로 매크로 지정
#define NUM_DOWN 102
#define NUM_CORRECT 103
#define NUM_ERROR 104 

#define NUM_RESET 105 // 리셋 상수

#define END_COND 999 //강제종료 상수 지정



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


// 업 다운 판별 함수
unsigned int UpDownJudge(unsigned int nPlayerNum , unsigned int nRandomNum)
{
    if (nPlayerNum == nRandomNum) // 플레이어가 맞췄을 때 경우를 지정한 함수로 변환
        return NUM_CORRECT; 
        
    else if ((nPlayerNum < 0) || (nPlayerNum > 100)) // 플레이어가 입력한 값이 1보다 작거나 100보다 클 경우 오류로 지정하고 지정한 상수로 변환
        return NUM_ERROR;
    else if (nPlayerNum < nRandomNum) //플레이어가 입력한 값이 무작위 정수보다 낮을 경우 지정한 상수로 반환
        return NUM_UP;
        
    else if (nPlayerNum > nRandomNum) //플레이어가 입력한 값이 무작위 정수보다 높을 경우 지정한 상수로 반환
        return NUM_DOWN;
    else // 이외의 경우는 오류로 지정하고 반환
        return NUM_ERROR;
}



int main(void)
{
    //시드 초기화
    GenRandSeed();

    //변수 초기화
    unsigned int nPlayerNum = NUM_RESET; //플레이어한테 입력받을 변수 초기화
    unsigned int nUpDownJudge = NUM_RESET; // 함수를 선언해 경우를 판단할 변수 초기화

 
    printf("1~100사이의 무작위 정수가 생성되었습니다. (프로그램 강제종료는 999 입력)  \n");

    unsigned int nRandomNum = NUM_RESET; // 무작위 정수를 저장할 변수 초기화
    nRandomNum = GenRandNum(NUM_MAXIMUM); // 범위 내의 무작위 정수를 생성하고 변수에 저장

    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT만큼 반복
    {
        printf("정수를 입력해주세요  ");
        scanf_s("%d", &nPlayerNum); // 계속해서 반복하며 플레이어에게 정수를 입력받음
        
        // 업 다운 판별 함수선언하여 경우를 지정한 상수로 변환하여 판단
        unsigned int nUpDownJudge = UpDownJudge(nPlayerNum, nRandomNum); 

        if (nPlayerNum == END_COND) // 플레이어가 강제종료 상수를 입력했을 경우 반복문을 벗어나 프로그램 강제종료
        {
            printf("프로그램을 강제종료합니다.\n");
            break;
        }
        else if (nUpDownJudge == NUM_CORRECT) //스위치 케이스문을 이용하려했으나 문제를 맞춰도 for문을 벗어나지 못하고 계속해서 정수를 입력받고자 하여 else if문을 이용하였음
        {
            printf("정답입니다!\n");
            break;
        }
        switch (nUpDownJudge)
        {
        
        case NUM_UP: //변수 내 값이 지정한 상수일 경우 각각의 텍스트를 출력 
        {
            printf("UP\n\n");
            continue; 
        }
        case NUM_DOWN:
        {
            printf("DOWN\n\n");
            continue;
        }
        case NUM_ERROR:
        {
            printf("1~100 사이의 정수를 입력해주세요\n\n");
            continue;
        }
        default: // NUM_ERROR로 판단되는 상황 이외의 경우가 발생하였을 경우도 오류로 지정
        {
            printf("입력값을 확인해주세요\n\n");
            continue;
        }

        }
         

    }
    

    printf("정답은 %d 였습니다.\n", nRandomNum);

    return 0;
}