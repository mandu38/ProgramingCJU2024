// ������� �ҷ����� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100������ ������ ���ڸ� �����ϰ� ���

#define NUM_COUNT 10     
#define NUM_MAXIMUM 100



// ���� �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// Ư�� ���� ������ ���� ���� ���� �Լ�
unsigned int GenRandNum(unsigned int nMax)
{
    return rand() % nMax;  
}

int main(void)
{
    //�õ� �ʱ�ȭ
    GenRandSeed();

    unsigned int nPlayerNum = 0;
    

    printf("1~100������ ������ ������ �����Ǿ����ϴ�. \n������ �Է����ּ���\n");

    unsigned int nRandomNum = 0;
    nRandomNum = GenRandNum(NUM_MAXIMUM);

    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT��ŭ �ݺ�
    {
        
        scanf_s("%d", &nPlayerNum);

        if (nPlayerNum == nRandomNum)
        {
            printf("�����Դϴ�!");
            break;
        }
        else if ((nPlayerNum < 0) || (nPlayerNum > 100))
        {
            printf("0~100������ �������� �Է����ּ���\n");
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
            printf("������ �߻��߽��ϴ�. �ٽ� �������ּ���");
            break; 
        }

    }


    printf("������ %d �����ϴ�.", nRandomNum);

    return 0;
}
