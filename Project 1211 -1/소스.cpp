#include <stdio.h>
#include <string.h>

// �ܾ ������ �Լ�
void Reverse(char *pFirst, char* pEnd)
{
    while (pFirst < pEnd)
    {
        char temp = *pFirst; // �ӽ� ������ ������ �迭�� ����
        *pFirst = *pEnd;
        *pEnd = temp; // ���۰��� ���� ���� 
        *pFirst++;
        pEnd--; // ó�� �Է¹��� ���� ����� �迭 �ּҿ� �������� ���� ����� �迭 �ּ� ������ �ݴ�� �Ͽ� ���ڸ� ���� ���� 
    }
}

int main(void) 
{
    // str�Լ� ����� ���� �迭 �ʱ�ȭ
    char cInput[100] = "clear";
    
    //���ڿ��� ���� �Է¹ޱ�
    printf("���ڿ��� �Է��ϼ��� (�ִ� 100��): ");
    fgets(cInput, sizeof(cInput), stdin);
    
   

    // strcspn �Լ��� �̿��� �ι��� ����
    cInput[strcspn(cInput, "\n")] = '\0';

    printf("\n�Է¹��� ���ڿ� : %s \n", cInput);
    //�迭�� �����ͷ� �ű�
    char* pFirst = cInput;
    char* pEnd = pFirst + strcspn(pFirst, " ");

    //�Է¹��� ���� �ִ� �迭�� ���� �� ��ŭ �ݺ�
    while (*pFirst)
    {
        char* pEnd = pFirst + strcspn(pFirst, " ");

        // �迭 ������
        Reverse(pFirst, pEnd - 1);

        // ���� �ǳʶٰ� ���� �ܾ�� �̵�
        pFirst = pEnd + strspn(pEnd, " ");
    }

    printf("������ ���ڿ�   : %s\n",cInput);

    return 0;
}