#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000
#define COIN_FND_BWD 3
#define COIN_FND_STATUS 1
#define COIN_BND_STATUS 2

#define INISTATUS 100
#define END_COND 999

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        nRes = ((unsigned int)(nNum) % (nRange));
        if ((nRes == COIN_FND_STATUS) || (nRes == COIN_BND_STATUS))
        {
            break;
        }
            
    }
  return nRes;
}


  unsigned int CalCulateFlipCoin1(unsigned int nNumSumFwdFlip)
  {
      unsigned int nFndSum = 0;
      nFndSum = (nNumSumFwdFlip * 100) / NUM_FLIP;
      return nFndSum;
  }

  unsigned int CalCulateFlipCoin2(unsigned int nNumSumBwdFlip)
  {
      unsigned int nBndSum = 0;
      nFndSum = (nNumSumBwdFlip * 100) / NUM_FLIP;
      return nBndSum;
  }

int main (void)
{
    
    // assigning seed
    GenRandSeed();

    // initializing variables

    int nNumSumFwdFlip = 0; // �ո��� ���� ���� ���庯��
    int nNumSumBwdFlip = 0; // �޸��� ���� ���� ���庯��
    double dVarFwdFlip = 0.0; //�յ޸� ǥ������
    double dVarDwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevDwdFlip = 0.0;




    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        // �ø����ο� ���缭 �� 0 �ո� 1 �޸�

        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FND_BWD);

        if(nStatusFlipCoin == 0)
        {
            continue;
        }

        //���ձ���
        switch (nStatusFlipCoin)
        {
            case COIN_FND_STATUS:
            {
                nNumSumFwdFlip++;
                break;
            }
      
            case COIN_BND_STATUS:
            {
                nNumSumBwdFlip++;
                break;
            }
                
            default:
            {
                printf("����");
            }
            
        }

    }

    dStdevFwdFlip = CalCulateFlipCoin1(nNumSumFwdFlip);
    dStdevDwdFlip = CalCulateFlipCoin2(nNumSumBwdFlip);

    printf("%d,%d\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("�ո� Ȯ�� %.4lf %, �޸� Ȯ�� %.4lf %", dStdevFwdFlip, dStdevDwdFlip);


   
    return 0;
}

