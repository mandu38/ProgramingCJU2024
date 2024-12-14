#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592



// σavg
double StressAverage(double** Data)
{
    return Data[1][0] = (Data[0][0] + Data[0][1]) / 2;
}

// (σx - σy) / 2
double ConvertMinusXY(double** Data)
{
    return Data[1][1] = (Data[0][0] - Data[0][1]) / 2;
}

// Mohr 반지름 및 최대 전단력
double RadiusCircle(double** Data)
{
    return Data[1][2] = sqrt((Data[1][1] * Data[1][1]) + (Data[0][2] * Data[0][2]));
}



// 주응력 각도 계산
double PrincipalStressAngle(double** Data)
{

    // σx 와 σy가 동일할 시 대칭 상태
    if (Data[0][0] == Data[0][1])
    {
        if (Data[0][2] == 0)
        {
            // 순수한 축 대칭 상태, 주응력 방향은 모든 방향에서 동일
            return 0.0; 
        }

        else
        {
            // 분모는 0이지만 전단응력이 있는 경우 45도를 반환
            return 45.0;
        }
    }

    // 분모가 0이 아닌 경우 정상적으로 계산
    Data[0][5] = atan((2 * Data[0][2]) / (Data[0][0] - Data[0][1])) * (180 / PI);
    Data[1][3] = Data[0][5] / 2;

    // 응력 x의 값이 음수일경우 최대 주응력이 작용하는 각도 p1은 +90도로 더해짐
    if (Data[0][0] < 0)
    {
        Data[1][3] += 90;
    }

    
    // 결과값을 0 ~ 180도로 조정
    if (Data[1][3] < 0)
    {
        Data[1][3] += 180;
    }
    
    return Data[1][3];
}



// 주응력 계산 //sin cos은 라디안으로 인자를 받기 때문에 주의요망 
double PrincipalStress(double** Data)
{
    double Angle = Data[0][5] * (PI / 180); // 라디안값으로 변환

    //최대 주응력
    Data[2][4] = Data[1][0] + (Data[1][1] * cos(Angle)) + (Data[0][2] * sin(Angle));

    //최소 주응력
    Data[2][5] = Data[1][0] - (Data[1][1] * cos(Angle)) - (Data[0][2] * sin(Angle));

    return Data[2][4], Data[2][5];
}



// 좌표 계산
double CalculateCoordinates(double** Data)
{
    // 주어진 각도를 라디안으로 변환
    double dAngle = (Data[0][3] * 2 - Data[0][5]) * PI / 180; // Data[0][3]은 입력된 각도 (2θp)로 바꿔줌

    // 애초에 비율은 같기 때문에 인덱스로 곱해도 상관없다.
    // 인덱스는 전단응력 부호 판별값
    if (Data[0][4] == 0)
    {
        Data[2][0] = Data[1][0] + Data[1][2] * cos(dAngle); // D점  σx1 좌표
        Data[2][1] = -Data[1][2] * sin(dAngle);             // D점  τxy 좌표
        Data[2][2] = Data[1][0] - Data[1][2] * cos(dAngle); // D'점 σx1 좌표
        Data[2][3] = Data[1][2] * sin(dAngle);              // D'점 τxy 좌표
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
        //동적 할당 영역 반환하고 프로그램 종료
        printf("오류가 발생했습니다.");
        for (int i = 0; i < 3; i++)
        {
            free(Data[i]);
        }
        free(Data);
        return 1;
    }

    return 0; // 반환값은 필요 없으나 구조상 유지
}



// 전단응력 부호 판별 및 전단응력 각도 계산 함수
void CalculateShareStressAngle(double** Data)
{
    if (Data[0][2] > 0) //전단응력이 양수일때 0
    {
        Data[0][4] = 0; // D점 좌표에 사용할 인덱스 값은 전단응력이 양수 일시 0
        Data[1][5] = -((90 - Data[0][5]) / 2); // 전단응력이 양수 일시 전단력 각도는 음수값
    }
    else if (Data[0][2] < 0) // 전단응력이 음수일때 1
    {
        Data[0][4] = 1; // D점 좌표에 사용할 인덱스 값은 전단응력이 양수 일시 1
        Data[1][5] = (90 + Data[0][5]) / 2; // 전단응력이 음수 일시 전단력 각도는 양수값
    }
    else
    {
        printf("오류가 발생했습니다.\n");
        return;
    }
}
    



int main(void)
{
    while (1)
    {
        double** Data; // 배열을 위한 포인터 선언
        Data = (double**)malloc(3 * sizeof(double*));  // 3개의 double*를 위한 메모리 할당

        // 첫 번째 할당 체크
        if (Data == NULL)   // malloc 호출이 실패했을 때
        {
            printf("\n메모리가 부족합니다.\n");
            exit(1);
        }

        // 각 double*에 대해 6개의 double을 위한 메모리 할당 및 0으로 초기화
        for (int i = 0; i < 3; i++)
        {
            Data[i] = (double*)calloc(6, sizeof(double));  // 각 행에 6개의 double 초기화
            if (Data[i] == NULL)  // 각 행에 대한 할당 체크
            {
                printf("\n메모리가 부족합니다.\n");
                exit(1);
            }
        }

        printf("평면응력 상태 회전요소 계산 프로그램  (강제종료 : 1557 입력)\n");
        printf("σx, σy, τxy ,회전한 요소의 각도값을 입력해주세요 (단위: MPa)\n\n");


        while (1)
        {
            printf("입력: ");
            int dInputCount = scanf_s("%lf %lf %lf %lf", &Data[0][0], &Data[0][1], &Data[0][2], &Data[0][3]);
            if (dInputCount != 4) // 입력 개수가 4개가 아니면
            {
                printf("\n입력이 올바르지 않습니다. σx, σy, τxy, 회전 각도를 정확히 입력해주세요.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
                continue; // 다시 입력 요청
            }

            // 강제 종료 조건
            if (Data[0][0] == 1557 || Data[0][1] == 1557 || Data[0][2] == 1557 || Data[0][3] == 1557)
            {
                printf("\n프로그램을 강제종료합니다.\n");
                for (int i = 0; i < 3; i++)
                {
                    free(Data[i]);
                }
                free(Data);
                return 0;
            }

            break; // 입력이 올바르다면 반복 종료
        }

        StressAverage(Data); // σavg 계산 함수

        ConvertMinusXY(Data); // (σx - σy) / 2

        RadiusCircle(Data); // Mohr 원 반지름 계산 함수

        PrincipalStressAngle(Data); // 주응력 각도 계산 함수

        CalculateShareStressAngle(Data); //전단응력 부호 판단 및, 각도계산 함수

        PrincipalStress(Data); //최대,최소 주응력 계산 

        CalculateCoordinates(Data); // D점 좌표 계산함수

        // 결과 출력
        printf("\n============ Mohr원 계산 결과 ============\n\n");
        printf("σ average = %.2lf MPa\n반지름 R  = %.2lf MPa\n", Data[1][0], Data[1][2]);
        printf("\n최대 주응력 σ1  = %.2lf MPa\n최소 주응력 σ2  =  %.2lf MPa\n주응력 각도 θp1 = %.2lf°\n", Data[2][4], Data[2][5], Data[1][3]);
        printf("\n최대 전단력 τmax = %.2lf MPa\n전단력 각도 θs1  = %.2lf°\n", Data[1][2], Data[1][5]);
        printf("\n<D 점 좌표>\nσ x1   = %.2lf MPa \nτ x1y1 = %.2lf MPa\n\n<D'점 좌표>\nσ x1   = %.2lf MPa\nτ x1y1 = %.2lf MPa\n\n", Data[2][0], Data[2][1], Data[2][2], Data[2][3]);

        //동적 할당 영역 반환
        for (int i = 0; i < 3; i++)
        {
            free(Data[i]);
        }
        free(Data);

        

        while (1)
        {
            printf("계산을 한번 더 진행 할까요? Y / N:  ");

            char YesOrNo;
            if (scanf_s(" %c", &YesOrNo, 1) != 1)  // 입력 크기를 지정하여 잘못된 버퍼 초과 입력을 방지.
            {
                printf("\n잘못된 입력입니다. 'Y' 혹은 'N'만 입력 가능합니다.\n");
                while (getchar() != '\n');  // 남아있는 잘못된 입력값 제거
                continue;
            }

            if (YesOrNo == 'Y' || YesOrNo == 'y')
            {
                break;
            }
            else if (YesOrNo == 'N' || YesOrNo == 'n')
            {
                printf("\n프로그램을 종료합니다.\n");
                return 0;
            }
            else
            {
                printf("'Y' 혹은 'N' 중에서만 입력하여 결정해주세요\n\n");
                while (getchar() != '\n');  // 남아있는 입력을 제거
            }
        }
        printf("\n");

        
    
    }

    printf("\n프로그램을 종료합니다.\n");
    return 0;
}
