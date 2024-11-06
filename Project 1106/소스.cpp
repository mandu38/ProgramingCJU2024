#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define FRONT_BEHIND 2
#define FRONT 1
#define BEHIND 2
#define INISTATUS 4
#define END_COND 999

#define PLAYER_WIN 10
#define PLAYER_LOSE 11
#define DRAW 12

void GenRandSeed()
{
	// generating the random number using the time seed
	srand((unsigned int)(time(NULL)));
	return;
}

unsigned int GenRandNum(unsigned int nComRps)
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nComRps));
	return nRes;
}





int main(void)
{
	unsigned int nComCoin = INISTATUS;
	unsigned int nPlayerCoin = INISTATUS;

	while (1)
	{
		printf("동전을 던집니다. 면을 선택해주세요\n동전 확률 계산은 100 입력\n프로그램종료는 0 입력 \n");
		scanf_s("%d", &nPlayerCoin);

		if ((nPlayerCoin == END_COND) && (nPlayerCoin >= FRONT_BEHIND))
		{
			printf("end of the infinite while loop...\n");
			break;
		}
		else if (nPlayerCoin < 0)
		{
			printf("check your input condition \n");
			continue;



	}





	return 0;
}

