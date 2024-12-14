#include<stdio.h>

int main(void)
{
	
	double Score; //변수선언
	int Convert; //switch case문은 정수형 변수만 가능하므로 정수형 변수로 선언

	Score = 0; //변수 초기화
	Convert = 0;

	printf("(학점변환 프로그램 SC문)\n점수를 입력하세요\n");
	scanf_s("%lf", &Score);
	
	Convert = (Score >= 0 && Score <= 20) * 1 //논리연산자 &&를 이용해 변수의 범위를 확인하고 각각의 범위를 정수로 지정
		+ (Score > 20 && Score <= 40) * 2
		+ (Score > 40 && Score <= 60) * 3
		+ (Score > 60 && Score <= 80) * 4
		+ (Score > 80 && Score <= 100) * 5;
	    
	switch (Convert) // 입력받은 변수의 범위를 지정한 Convert 변수를 switch case문을 이용해 특정범위마다 다른 문장 출력
	{
	case 1:
		printf("학생의 점수: %.1lf 점, F학점입니다.", Score);
		break;
	case 2:
		printf("학생의 점수: %.1lf 점, D학점입니다.", Score);
		break;
	case 3:
		printf("학생의 점수: %.1lf 점, C학점입니다.", Score);
		break;
	case 4:
		printf("학생의 점수: %.1lf 점, B학점입니다.", Score);
		break;
	case 5:
		printf("학생의 점수: %.1lf 점, A학점입니다.", Score);
		break;
	default:
		printf("오류발생 1~100까지의 숫자를 입력해주세요");
		break;
	}


	return 0;
}

