#include "numbook.h"

int ReadFileLine() {

    int lineCount = 0;
    FILE* book = { 0 };
    book = fopen("book.txt", "a+"); //전화번호부 파일 열기 없다면 만들기

    char word = 0; // txt파일을 문자 1개별로 검사하는 변수 

    // txt 파일의 줄 수 count
    while ((word = fgetc(book)) != EOF) // 파일의 끝에 올 때까지 한글자씩 입력받아 검사 
    {
        if (word == '\n') {     // 줄바꿈 문자가 있다면 lineCount 를 증가시킴 
            lineCount++;
        }
    }
    fclose(book); // 전화번호부 파일 닫기

    return lineCount; // 줄 수를 리턴함 
} 



