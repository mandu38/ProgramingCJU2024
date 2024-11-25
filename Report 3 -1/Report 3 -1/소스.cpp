// ������� �ҷ�����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

// ��ũ�� ����
#define NUM_FLIP 10000
#define COIN_FND_STATUS 1
#define COIN_BND_STATUS 2
#define COIN_FND_BWD 3

#define INISTATUS 100
#define END_COND 999



// ���� �õ� ����
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// �ո�� �޸��� ���� 1�� 2�� �����ϰ� ���� ���� �Լ��� �̿��� ���� ������ �Լ� 
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        unsigned int nNum = rand();  // nNum�� rand()�� ���� �Ź� ������ ����
        nRes = nNum % nRange;  // nRange ���� ���� ���� nRes�� �Ҵ�

        if ((nRes == COIN_FND_STATUS) || (nRes == COIN_BND_STATUS)) // || �Ǵ� �����ڸ� ���� �� �� �ϳ��� ���� ������ Ż��
        {
            break;
        }
    }
    return nRes;
}


// �ո�Ȯ����� �Լ�
unsigned int FndCalCulateFlipCoin(unsigned int nNumSumFwdFlip)
{
    return (nNumSumFwdFlip * 100) / NUM_FLIP;
}

// �޸�Ȯ����� �Լ�
unsigned int BndCalCulateFlipCoin(unsigned int nNumSumBwdFlip)
{
    return (nNumSumBwdFlip * 100) / NUM_FLIP;
}

int main(void)
{
    // �õ��ʱ�ȭ
    GenRandSeed();

    // �����ʱ�ȭ
    int nNumSumFwdFlip = 0; // �ո� ����
    int nNumSumBwdFlip = 0; // �޸� ����

    // ������ ������ NUM_FLIP�� ���� ���� �ݺ�
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        //���ǵ� COIN_FND_BWD ��ũ�θ� ���� GenRandFlipCoin �Լ� ȣ��� �μ��� 3���� ������
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FND_BWD);

        // �ո�, �޸� ���
        switch (nStatusFlipCoin)
        {
        case COIN_FND_STATUS: //�ո��Ͻ� �ո� ���� ���� ������ +1�߰� 
            nNumSumFwdFlip++;
            break;

        case COIN_BND_STATUS: //�޸��Ͻ� �޸� ���� ���� ������ +1�߰� 
            nNumSumBwdFlip++;
            break;

        default:
            printf("����\n"); //�̿��� ��Ȳ�� ������ ����
        }
    }

    // // �Լ��� ȣ���ϰ� �ݺ��Ͽ� ����Ѱ��� �μ��� Ȯ���� ���
    double dStdevFwdFlip = FndCalCulateFlipCoin(nNumSumFwdFlip); 
    double dStdevDwdFlip = BndCalCulateFlipCoin(nNumSumBwdFlip);

    // ��� ���
    printf("�ո�: %dȸ, �޸�: %dȸ\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("�ո� Ȯ��: %.2lf%%, �޸� Ȯ��: %.2lf%%\n", dStdevFwdFlip, dStdevDwdFlip);

    return 0;
}
