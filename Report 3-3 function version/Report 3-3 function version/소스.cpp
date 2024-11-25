// ������� �ҷ����� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1~100������ ������ ���ڸ� �����ϰ� ���

#define NUM_COUNT 10 // �����ϰ��� �ϴ� Ƚ�� ��ũ�� ����

#define NUM_MAXIMUM 100 // 1~100������ ���� ������ ���� 100 ����� ����
#define NUM_UP 101 //100 �̳��� ������ ��ũ�θ� ������ ��� ���� �߻� ������ ���� 100�� �ʰ��� ������ ��ũ�� ����
#define NUM_DOWN 102
#define NUM_CORRECT 103
#define NUM_ERROR 104 

#define NUM_RESET 105 // ���� ���

#define END_COND 999 //�������� ��� ����



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


// �� �ٿ� �Ǻ� �Լ�
unsigned int UpDownJudge(unsigned int nPlayerNum , unsigned int nRandomNum)
{
    if (nPlayerNum == nRandomNum) // �÷��̾ ������ �� ��츦 ������ �Լ��� ��ȯ
        return NUM_CORRECT; 
        
    else if ((nPlayerNum < 0) || (nPlayerNum > 100)) // �÷��̾ �Է��� ���� 1���� �۰ų� 100���� Ŭ ��� ������ �����ϰ� ������ ����� ��ȯ
        return NUM_ERROR;
    else if (nPlayerNum < nRandomNum) //�÷��̾ �Է��� ���� ������ �������� ���� ��� ������ ����� ��ȯ
        return NUM_UP;
        
    else if (nPlayerNum > nRandomNum) //�÷��̾ �Է��� ���� ������ �������� ���� ��� ������ ����� ��ȯ
        return NUM_DOWN;
    else // �̿��� ���� ������ �����ϰ� ��ȯ
        return NUM_ERROR;
}



int main(void)
{
    //�õ� �ʱ�ȭ
    GenRandSeed();

    //���� �ʱ�ȭ
    unsigned int nPlayerNum = NUM_RESET; //�÷��̾����� �Է¹��� ���� �ʱ�ȭ
    unsigned int nUpDownJudge = NUM_RESET; // �Լ��� ������ ��츦 �Ǵ��� ���� �ʱ�ȭ

 
    printf("1~100������ ������ ������ �����Ǿ����ϴ�. (���α׷� ��������� 999 �Է�)  \n");

    unsigned int nRandomNum = NUM_RESET; // ������ ������ ������ ���� �ʱ�ȭ
    nRandomNum = GenRandNum(NUM_MAXIMUM); // ���� ���� ������ ������ �����ϰ� ������ ����

    for (unsigned int i = 0; i < NUM_COUNT; i++) // NUM_COUNT��ŭ �ݺ�
    {
        printf("������ �Է����ּ���  ");
        scanf_s("%d", &nPlayerNum); // ����ؼ� �ݺ��ϸ� �÷��̾�� ������ �Է¹���
        
        // �� �ٿ� �Ǻ� �Լ������Ͽ� ��츦 ������ ����� ��ȯ�Ͽ� �Ǵ�
        unsigned int nUpDownJudge = UpDownJudge(nPlayerNum, nRandomNum); 

        if (nPlayerNum == END_COND) // �÷��̾ �������� ����� �Է����� ��� �ݺ����� ��� ���α׷� ��������
        {
            printf("���α׷��� ���������մϴ�.\n");
            break;
        }
        else if (nUpDownJudge == NUM_CORRECT) //����ġ ���̽����� �̿��Ϸ������� ������ ���絵 for���� ����� ���ϰ� ����ؼ� ������ �Է¹ް��� �Ͽ� else if���� �̿��Ͽ���
        {
            printf("�����Դϴ�!\n");
            break;
        }
        switch (nUpDownJudge)
        {
        
        case NUM_UP: //���� �� ���� ������ ����� ��� ������ �ؽ�Ʈ�� ��� 
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
            printf("1~100 ������ ������ �Է����ּ���\n\n");
            continue;
        }
        default: // NUM_ERROR�� �ǴܵǴ� ��Ȳ �̿��� ��찡 �߻��Ͽ��� ��쵵 ������ ����
        {
            printf("�Է°��� Ȯ�����ּ���\n\n");
            continue;
        }

        }
         

    }
    

    printf("������ %d �����ϴ�.\n", nRandomNum);

    return 0;
}