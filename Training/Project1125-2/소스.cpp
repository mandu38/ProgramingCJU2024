#include <stdio.h>

int main(void)
{
    int i = 0;
    int dCount = 0;
    char cText[30] = "apple";

    printf("문자를 입력하세요 : ");

    //공백 포함 문자열도 인식할수 있도록 %[^\n] 수식을 사용 (챗지피티의 도움을 받음)
    scanf_s("%[^\n]", cText, sizeof(cText));  //사용자에게 문장을 입력받는다. 문자열이므로 sizeof 사용

    printf("입력받은 문장 대문자 > 소문자 변환 결과: \n");

    // A~Z까지는 65~90, 소문자 a~z까지는 97~122

    for (i = 0; cText[i] != '\0'; i++)  //  널 문자(\0)가 아니어야 반복을 계속하겠다는 의미
    {
        if (cText[i] >= 'A' && cText[i] <= 'Z')  // 문자의 아스키 코드를 이용 대문자일 경우
        {
            cText[i] += ('a' - 'A');  // a의 아스키코드를 A만큼 뺴서 소문자로 변환 
            dCount++; //변환된 문자수를 저장하는 변수에 +1
        }
    }

    printf("%s\n", cText);  // 변환된 결과 출력
    printf("바뀐 문자 수: %d\n", dCount);  // 변환된 문자 수 출력

    return 0; //프로그램 종료 
}
