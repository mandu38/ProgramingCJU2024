#include<stdio.h>

int main(void)
{
	double Score; // 실수형 변수 선언



	printf("(학점변환 프로그램)\n점수를 입력하세요\n");
	scanf_s("%lf", &Score); // scanf_s 함수로 점수 입력받기

	if ((Score >=0) && (Score <= 20)) // 입력받은 점수가 0이상 20이하 일 경우
	{
		printf("학생의 점수: %.1lf 점, F학점입니다." , Score);
	}
	else if ((Score > 20) && (Score <= 40)) // 입력받은 점수가 20 초과 40이하 일 경우
	{
		printf("학생의 점수: %.1lf 점, D학점입니다.", Score);
	}
	else if ((Score > 40) && (Score <= 60)) // 입력받은 점수가 40 초과 60이하 일 경우
	{
		printf("학생의 점수: %.1lf 점, C학점입니다.", Score);
	}
	else if ((Score > 60) && (Score <= 80)) // 입력받은 점수가 60 초과 80이하 일 경우
	{
		printf("학생의 점수: %.1lf 점, B학점입니다.", Score);
	}
	else if ((Score > 80) && (Score <= 100)) // 입력받은 점수가 80 초과 100이하 일 경우
	{
		printf("학생의 점수: %.1lf 점, A학점입니다.", Score);
	}
	else  //0~100범위를 벗어나는 값은 오류로 지정하고 문장 출력
	{
		printf("오류발생 1~100까지의 숫자만 입력해주세요");
	}


	return 0;
}

