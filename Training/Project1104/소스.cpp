#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK_PAPER_SCISSORS 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 0
#define END_COND 999

// generating the seed number using the time clock information
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL))); // ���������� ��� ���������� ������  
    return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange) // ���� ������ �ްڴ�
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main(void)
{

    GenRandSeed();

    unsigned int nComRps = INITSTATUS ;
    unsigned int nPlayerRps = INITSTATUS ;

    // ���ѷ���
    while (1)
    {


    }
    return 0;
}