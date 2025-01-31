#include "numbook.h"
// 소프트웨어공학 1차 과제 
// AI소프트웨어학과 202322371 하승연
// 작업환경 : visualstudio 2022

// 프로그램 시작 함수  
int main() {

   
    printf("... 전화번호부를 세팅합니다.\n");  

    printf("... 'book.txt' 파일에서 데이터를 읽는 중"); // 작업 저장중이라는 안내메세지 출력 


    int key = 0; // 메뉴의 번호를 입력받을 변수 선언
 
    int lineCount = 0; // 파일의 줄 수 를 셀 변수 선언
    lineCount = ReadFileLine();  // 파일의 줄 수 (전화번호부의 개수) 를 저장하는 변수 선언


    FILE* book = { 0 };
    book = fopen("book.txt", "a+"); // 덧붙이기 기능으로 열기 

    // txt 파일을 줄별로 구조체 배열에 저장
    struct base* nowBook = NULL;
    nowBook = (struct base*)malloc(sizeof(struct base) * lineCount); //동적메모리 설정

   
   
    for (int i = 0;i < lineCount;i++) {
        fscanf(book, "%s / %s / %s / %s / %s / \n", nowBook[i].name, nowBook[i].num, nowBook[i].relation, nowBook[i].mail, nowBook[i].sos);

    }

    for (int i = 0; i < 3; i++) {
        printf("%c", '.');
        Sleep(800); // 0.8초씩 3번 점을 출력하여 화면이 바로 지워지는것을 방지함 
    }

    printf("\n... 데이터 읽기 완료 !\n");

    fclose(book);

    printf("\n... 전화번호부를 실행하려면 아무 키나 눌러주세요.\n");
    getchar();
    system("cls"); // 화면을 깨끗하게 지우는 함수

    while (key != 4) {

        SortName( nowBook, lineCount); // 이름 정렬 함수
        
        printf("%s", "======= 메뉴 ======= \n");
        printf("%s\n%s\n%s\n%s\n", "01. 추가", "02. 검색 과 수정/삭제", "03. 출력", "04. 종료 및 저장");
   
        key = rightkey(4) ;
   
        if (key == 1) {           
            int lineCountBuffer = lineCount;
            nowBook = (struct base*) realloc( nowBook, sizeof(struct base) * (lineCount + 1) );
            nowBook[lineCountBuffer] = AddNumBook(nowBook, &lineCount);
            
            ScreenClear();
        }
        else if (key == 2) {
            nowBook = SearchNumBook(nowBook, &lineCount);
           
            ScreenClear();
        }
        else if (key == 3) {

            PrintNumBook(nowBook, lineCount);
            
            ScreenClear();
        }
        else if (key == 4) {
         
            printf("%s", "======= 04. 종료 및 저장 ======= \n");
            printf("%s", "... 데이터를 'book.txt' 파일에 저장합니다. \n");
            WriteOnFile(nowBook, lineCount);
            ScreenClear();

            free(nowBook);  // 동적메모리 해제
            nowBook = NULL;

        }

    }

}