#include <stdio.h>

// 내적 계산 함수
double DotProduct(const double* pVector1, const double* pVector2)
{
    return (*(pVector1)) * (*(pVector2)) +
        (*(pVector1 + 1)) * (*(pVector2 + 1)) +
        (*(pVector1 + 2)) * (*(pVector2 + 2));
}

// 외적 계산 함수
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

    printf("** 프로그램 종료를 원하면 1557을 입력하세요. **\n");

    while (1)
    {
        // 첫 번째 벡터 입력
        printf("\n첫 번째 벡터의 x, y, z 성분을 입력하세요: ");
        if (scanf_s("%lf %lf %lf", &Vector1[0], &Vector1[1], &Vector1[2]) != 3)
        {
            printf("입력이 올바르지 않습니다. 다시 시도하세요.\n");
            break;
        }
        if (Vector1[0] == 1557 || Vector1[1] == 1557 || Vector1[2] == 1557)
        {
            printf("프로그램을 강제 종료합니다.\n");
            break;
        }

        // 두 번째 벡터 입력
        printf("두 번째 벡터의 x, y, z 성분을 입력하세요: ");
        if (scanf_s("%lf %lf %lf", &Vector2[0], &Vector2[1], &Vector2[2]) != 3)
        {
            printf("입력이 올바르지 않습니다. 다시 시도하세요.\n");
            break;
        }
        if (Vector2[0] == 1557 || Vector2[1] == 1557 || Vector2[2] == 1557)
        {
            printf("프로그램을 강제 종료합니다.\n");
            break;
        }

        // 내적 계산
        DotResult = DotProduct(Vector1, Vector2);

        // 외적 계산
        CrossProduct(Vector1, Vector2, CrossResult);

        // 결과 출력
        printf("\n내적(dot product): %.2lf\n", DotResult);
        printf("외적(cross product): [%.2lf, %.2lf, %.2lf]\n",
            CrossResult[0], CrossResult[1], CrossResult[2]);
    }

    return 0;
}
