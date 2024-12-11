#include <stdio.h>

// ���� ��� �Լ�
double DotProduct(const double* pVector1, const double* pVector2)
{
    return (*(pVector1)) * (*(pVector2)) +
        (*(pVector1 + 1)) * (*(pVector2 + 1)) +
        (*(pVector1 + 2)) * (*(pVector2 + 2));
}

// ���� ��� �Լ�
void CrossProduct(const double* pVector1, const double* pVector2, double* pCrossResult)
{
    *(pCrossResult) = (*(pVector1 + 1)) * (*(pVector2 + 2)) - (*(pVector1 + 2)) * (*(pVector2 + 1)); // X
    *(pCrossResult + 1) = (*(pVector1 + 2)) * (*(pVector2)) - (*(pVector1)) * (*(pVector2 + 2));     // Y
    *(pCrossResult + 2) = (*(pVector1)) * (*(pVector2 + 1)) - (*(pVector1 + 1)) * (*(pVector2));     // Z
}

int main(void)
{
    double Vector1[3], Vector2[3];
    double CrossResult[3];
    double DotResult;

    printf("** ���α׷� ���Ḧ ���ϸ� 1557�� �Է��ϼ���. **\n");

    while (1)
    {
        // ù ��° ���� �Է�
        printf("\nù ��° ������ x, y, z ������ �Է��ϼ���: ");
        if (scanf_s("%lf %lf %lf", &Vector1[0], &Vector1[1], &Vector1[2]) != 3)
        {
            printf("�Է��� �ùٸ��� �ʽ��ϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
        if (Vector1[0] == 1557 || Vector1[1] == 1557 || Vector1[2] == 1557)
        {
            printf("���α׷��� ���� �����մϴ�.\n");
            break;
        }

        // �� ��° ���� �Է�
        printf("�� ��° ������ x, y, z ������ �Է��ϼ���: ");
        if (scanf_s("%lf %lf %lf", &Vector2[0], &Vector2[1], &Vector2[2]) != 3)
        {
            printf("�Է��� �ùٸ��� �ʽ��ϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
        if (Vector2[0] == 1557 || Vector2[1] == 1557 || Vector2[2] == 1557)
        {
            printf("���α׷��� ���� �����մϴ�.\n");
            break;
        }

        // ���� ���
        DotResult = DotProduct(Vector1, Vector2);

        // ���� ���
        CrossProduct(Vector1, Vector2, CrossResult);

        // ��� ���
        printf("\n����(dot product): %.2lf\n", DotResult);
        printf("����(cross product): [%.2lf, %.2lf, %.2lf]\n",
            CrossResult[0], CrossResult[1], CrossResult[2]);
    }

    return 0;
}
