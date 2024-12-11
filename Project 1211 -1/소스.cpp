#include <stdio.h>
#include <string.h>

// 단어를 뒤집는 함수
void Reverse(char *pFirst, char* pEnd)
{
    while (pFirst < pEnd)
    {
        char temp = *pFirst; // 임시 변수에 포인터 배열값 저장
        *pFirst = *pEnd;
        *pEnd = temp; // 시작값과 끝값 스왑 
        *pFirst++;
        pEnd--; // 처음 입력받은 값이 저장된 배열 주소와 뒤집히는 값이 저장된 배열 주소 순서를 반대로 하여 문자를 각각 스왑 
    }
}

int main(void) 
{
    // str함수 사용을 위해 배열 초기화
    char cInput[100] = "clear";
    
    //문자열에 문자 입력받기
    printf("문자열을 입력하세요 (최대 100자): ");
    fgets(cInput, sizeof(cInput), stdin);
    
   

    // strcspn 함수를 이용해 널문자 제거
    cInput[strcspn(cInput, "\n")] = '\0';

    printf("\n입력받은 문자열 : %s \n", cInput);
    //배열을 포인터로 옮김
    char* pFirst = cInput;
    char* pEnd = pFirst + strcspn(pFirst, " ");

    //입력받은 값이 있는 배열의 문자 수 만큼 반복
    while (*pFirst)
    {
        char* pEnd = pFirst + strcspn(pFirst, " ");

        // 배열 뒤집기
        Reverse(pFirst, pEnd - 1);

        // 공백 건너뛰고 다음 단어로 이동
        pFirst = pEnd + strspn(pEnd, " ");
    }

    printf("뒤집힌 문자열   : %s\n",cInput);

    return 0;
}