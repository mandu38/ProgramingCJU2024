#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592



// ��avg
double StressAverage(double** Data)
{
    return Data[1][0] = (Data[0][0] + Data[0][1]) / 2;
}

// (��x - ��y) / 2
double ConvertMinusXY(double** Data)
{
    return Data[1][1] = (Data[0][0] - Data[0][1]) / 2;
}

// Mohr ������ �� �ִ� ���ܷ�
double RadiusCircle(double** Data)
{
    return Data[1][2] = sqrt((Data[1][1] * Data[1][1]) + (Data[0][2] * Data[0][2]));
}



// ������ ���� ���
double PrincipalStressAngle(double** Data)
{

    // ��x �� ��y�� ������ �� ��Ī ����
    if (Data[0][0] == Data[0][1])
    {
        if (Data[0][2] == 0)
        {
            // ������ �� ��Ī ����, ������ ������ ��� ���⿡�� ����
            return 0.0; 
        }

        else
        {
            // �и�� 0������ ���������� �ִ� ��� 45���� ��ȯ
            return 45.0;
        }
    }

    // �и� 0�� �ƴ� ��� ���������� ���
    Data[0][5] = atan((2 * Data[0][2]) / (Data[0][0] - Data[0][1])) * (180 / PI);
    Data[1][3] = Data[0][5] / 2;

    // ���� x�� ���� �����ϰ�� �ִ� �������� �ۿ��ϴ� ���� p1�� +90���� ������
    if (Data[0][0] < 0)
    {
        Data[1][3] += 90;
    }

    
    // ������� 0 ~ 180���� ����
    if (Data[1][3] < 0)
    {
        Data[1][3] += 180;
    }
    
    return Data[1][3];
}



// ������ ��� //sin cos�� �������� ���ڸ� �ޱ� ������ ���ǿ�� 
double PrincipalStress(double** Data)
{
    double Angle = Data[0][5] * (PI / 180); // ���Ȱ����� ��ȯ

    //�ִ� ������
    Data[2][4] = Data[1][0] + (Data[1][1] * cos(Angle)) + (Data[0][2] * sin(Angle));

    //�ּ� ������
    Data[2][5] = Data[1][0] - (Data[1][1] * cos(Angle)) - (Data[0][2] * sin(Angle));

    return Data[2][4], Data[2][5];
}



// ��ǥ ���
double CalculateCoordinates(double** Data)
{
    // �־��� ������ �������� ��ȯ
    double dAngle = (Data[0][3] * 2 - Data[0][5]) * PI / 180; // Data[0][3]�� �Էµ� ���� (2��p)�� �ٲ���

    // ���ʿ� ������ ���� ������ �ε����� ���ص� �������.
    // �ε����� �������� ��ȣ �Ǻ���
    if (Data[0][4] == 0)
    {
        Data[2][0] = Data[1][0] + Data[1][2] * cos(dAngle); // D��  ��x1 ��ǥ
        Data[2][1] = -Data[1][2] * sin(dAngle);             // D��  ��xy ��ǥ
        Data[2][2] = Data[1][0] - Data[1][2] * cos(dAngle); // D'�� ��x1 ��ǥ
        Data[2][3] = Data[1][2] * sin(dAngle);              // D'�� ��xy ��ǥ
    }
    else if (Data[0][4] == 1)
    {
        Data[2][0] = Data[1][0] - Data[1][2] * cos(dAngle); 
        Data[2][1] = Data[1][2] * sin(dAngle);              
        Data[2][2] = Data[1][0] + Data[1][2] * cos(dAngle); 
        Data[2][3] = -Data[1][2] * sin(dAngle);             
    }
    else
    {
        //���� �Ҵ� ���� ��ȯ�ϰ� ���α׷� ����
        printf("������ �߻��߽��ϴ�.");
        for (int i = 0; i < 3; i++)
        {
            free(Data[i]);
        }
        free(Data);
        return 1;
    }

    return 0; // ��ȯ���� �ʿ� ������ ������ ����
}



// �������� ��ȣ �Ǻ� �� �������� ���� ��� �Լ�
void CalculateShareStressAngle(double** Data)
{
    if (Data[0][2] > 0) //���������� ����϶� 0
    {
        Data[0][4] = 0; // D�� ��ǥ�� ����� �ε��� ���� ���������� ��� �Ͻ� 0
        Data[1][5] = -((90 - Data[0][5]) / 2); // ���������� ��� �Ͻ� ���ܷ� ������ ������
    }
    else if (Data[0][2] < 0) // ���������� �����϶� 1
    {
        Data[0][4] = 1; // D�� ��ǥ�� ����� �ε��� ���� ���������� ��� �Ͻ� 1
        Data[1][5] = (90 + Data[0][5]) / 2; // ���������� ���� �Ͻ� ���ܷ� ������ �����
    }
    else
    {
        printf("������ �߻��߽��ϴ�.\n");
        return;
    }
}
    



int main(void)
{
    while (1)
    {
        double** Data; // �迭�� ���� ������ ����
        Data = (double**)malloc(3 * sizeof(double*));  // 3���� double*�� ���� �޸� �Ҵ�

        // ù ��° �Ҵ� üũ
        if (Data == NULL)   // malloc ȣ���� �������� ��
        {
            printf("\n�޸𸮰� �����մϴ�.\n");
            exit(1);
        }

        // �� double*�� ���� 6���� double�� ���� �޸� �Ҵ� �� 0���� �ʱ�ȭ
        for (int i = 0; i < 3; i++)
        {
            Data[i] = (double*)calloc(6, sizeof(double));  // �� �࿡ 6���� double �ʱ�ȭ
            if (Data[i] == NULL)  // �� �࿡ ���� �Ҵ� üũ
            {
                printf("\n�޸𸮰� �����մϴ�.\n");
                exit(1);
            }
        }

        printf("������� ���� ȸ����� ��� ���α׷�  (�������� : 1557 �Է�)\n");
        printf("��x, ��y, ��xy ,ȸ���� ����� �������� �Է����ּ��� (����: MPa)\n\n");


        while (1)
        {
            printf("�Է�: ");
            int dInputCount = scanf_s("%lf %lf %lf %lf", &Data[0][0], &Data[0][1], &Data[0][2], &Data[0][3]);
            if (dInputCount != 4) // �Է� ������ 4���� �ƴϸ�
            {
                printf("\n�Է��� �ùٸ��� �ʽ��ϴ�. ��x, ��y, ��xy, ȸ�� ������ ��Ȯ�� �Է����ּ���.\n");
                while (getchar() != '\n'); // �Է� ���� ����
                continue; // �ٽ� �Է� ��û
            }

            // ���� ���� ����
            if (Data[0][0] == 1557 || Data[0][1] == 1557 || Data[0][2] == 1557 || Data[0][3] == 1557)
            {
                printf("\n���α׷��� ���������մϴ�.\n");
                for (int i = 0; i < 3; i++)
                {
                    free(Data[i]);
                }
                free(Data);
                return 0;
            }

            break; // �Է��� �ùٸ��ٸ� �ݺ� ����
        }

        StressAverage(Data); // ��avg ��� �Լ�

        ConvertMinusXY(Data); // (��x - ��y) / 2

        RadiusCircle(Data); // Mohr �� ������ ��� �Լ�

        PrincipalStressAngle(Data); // ������ ���� ��� �Լ�

        CalculateShareStressAngle(Data); //�������� ��ȣ �Ǵ� ��, ������� �Լ�

        PrincipalStress(Data); //�ִ�,�ּ� ������ ��� 

        CalculateCoordinates(Data); // D�� ��ǥ ����Լ�

        // ��� ���
        printf("\n============ Mohr�� ��� ��� ============\n\n");
        printf("�� average = %.2lf MPa\n������ R  = %.2lf MPa\n", Data[1][0], Data[1][2]);
        printf("\n�ִ� ������ ��1  = %.2lf MPa\n�ּ� ������ ��2  =  %.2lf MPa\n������ ���� ��p1 = %.2lf��\n", Data[2][4], Data[2][5], Data[1][3]);
        printf("\n�ִ� ���ܷ� ��max = %.2lf MPa\n���ܷ� ���� ��s1  = %.2lf��\n", Data[1][2], Data[1][5]);
        printf("\n<D �� ��ǥ>\n�� x1   = %.2lf MPa \n�� x1y1 = %.2lf MPa\n\n<D'�� ��ǥ>\n�� x1   = %.2lf MPa\n�� x1y1 = %.2lf MPa\n\n", Data[2][0], Data[2][1], Data[2][2], Data[2][3]);

        //���� �Ҵ� ���� ��ȯ
        for (int i = 0; i < 3; i++)
        {
            free(Data[i]);
        }
        free(Data);

        

        while (1)
        {
            printf("����� �ѹ� �� ���� �ұ��? Y / N:  ");

            char YesOrNo;
            if (scanf_s(" %c", &YesOrNo, 1) != 1)  // �Է� ũ�⸦ �����Ͽ� �߸��� ���� �ʰ� �Է��� ����.
            {
                printf("\n�߸��� �Է��Դϴ�. 'Y' Ȥ�� 'N'�� �Է� �����մϴ�.\n");
                while (getchar() != '\n');  // �����ִ� �߸��� �Է°� ����
                continue;
            }

            if (YesOrNo == 'Y' || YesOrNo == 'y')
            {
                break;
            }
            else if (YesOrNo == 'N' || YesOrNo == 'n')
            {
                printf("\n���α׷��� �����մϴ�.\n");
                return 0;
            }
            else
            {
                printf("'Y' Ȥ�� 'N' �߿����� �Է��Ͽ� �������ּ���\n\n");
                while (getchar() != '\n');  // �����ִ� �Է��� ����
            }
        }
        printf("\n");

        
    
    }

    printf("\n���α׷��� �����մϴ�.\n");
    return 0;
}
