#include <stdio.h>
#include <math.h>

int main(void)
{

	int Thousand; //변수선언 
	int FiveHundred;
	int Hundred;
	double Amount;
	double Object;
	double Change;
	double ChangeRemainder;
	double FiveRemainder;

	Amount = 0;  //변수 초기화
	Object = 0;
	Change = 0;
	Thousand = 0;
	FiveHundred = 0;
	Hundred = 0;
	ChangeRemainder = 0;
	FiveRemainder = 0;


	printf("투입한 금액과 물건값을 차례대로 입력해주세요.\n"); // 입력받을 값에 대한 문장 출력 
	scanf_s("%lf%lf", &Amount, &Object); // 값 입력받고 변수에 저장

	Change = Amount - Object; // 금액과 물건값을 빼 Change 변수에 저장

	Change = ((Change > 0) * Amount) - ((Change > 0) * Object); //거스름돈이 역으로 음수값이 나오거나 잘못입력되는 상황 방지

	Thousand = Change / 1000; // 거스름돈을 1000으로 나누어 천원의 장수를 구하고 Thousand 변수에 저장 

	ChangeRemainder = fmod(Change, 1000); //fmod 함수를 통해 거스름돈을 1000으로 나눴을때 나머지값을 ChangeRemainder에 저장

	FiveRemainder = fmod(ChangeRemainder,500); //fmod 함수를 통해ChangeRemainder에 저장된 값을 500으로 나눴을때 나머지값을 FiveRemainder에 저장

	FiveHundred = ChangeRemainder / 500; //거스름돈을 1000으로 나눈  ChangeRemainder에 저장된 값을 500으로 나누어 500원의 갯수 계산하고 FiveHundred에 저장

	Hundred = FiveRemainder / 100; // FiveRemainder에 저장된 나머지값을 100으로 나누어 100원의 갯수를 계산하고 출력

	printf("필요한 거스름돈 : %.1lf\n 천원 %d장\n 오백원 %d개\n 백원 %d개\n", Change, Thousand, FiveHundred, Hundred); //각각 계산된 거스름돈,천원의 장수, 오백원의 갯수, 백원의 갯수 출력 

	return 0; //프로그램 종료

}