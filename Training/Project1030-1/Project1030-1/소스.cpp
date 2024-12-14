#include<stdio.h>

double Con1(double Tem) // 함수 정의
{
    double Result1 = 0;
    Result1 = Tem * 1.8 + 32; // 섭씨 > 화씨 변환 공식
    return Result1; // 계산값 반환
}

double Con2(double Tem)
{
    double Result1 = 0;
    Result1 = (Tem - 32) / 1.8; // 화씨 > 섭씨 변환 공식
    return Result1;
}

int main(void)
{
    int Num1 = 0;
    double Tem = 0;
    double Result2 = 0;

    while (1) // 사용자가 원하는 변환값을 얻기 위해 단계를 지정하고 범위 내 값 입력까지 무한실행
    {
        printf("섭씨 > 화씨 변환은 1 입력 \n화씨 > 섭씨 변환은 2 입력\n");
        scanf_s("%d", &Num1);

        if (Num1 == 1)
        {
            break;
        }
        else if (Num1 == 2)
        {
            break;
        }
        else
        {
            printf("잘못된 입력입니다. 1또는 2를 입력하세요.\n");
        }
    }

    printf("변환할 온도를 입력해주세요\n");
    scanf_s("%lf", &Tem);

    switch (Num1)
    {
    case 1:// 첫번째 입력받은 값이 1일 경우 섭씨 > 화씨로 규정
        Result2 = Con1(Tem);
        printf("변환 결과 섭씨 %.1lf > 화씨 %.1lf ", Tem, Result2); // 섭씨 > 화씨 변환 함수 호출하여 계산하고 출력
        break;
    case 2:
        Result2 = Con2(Tem);
        printf("변환 결과 화씨 %.1lf > 섭씨 %.1lf ", Tem, Result2);  // 화씨 > 섭씨 변환 함수 호출하여 계산하고 출력
        break;

    default:
        printf("오류가 발생했습니다.");
    }

    return 0;
}
