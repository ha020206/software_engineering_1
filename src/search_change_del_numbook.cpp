#include "numbook.h"

struct base* SearchNumBook(struct base* nowBook, int* lineCount) {
    printf("%s", "======= 02. 검색 과 수정/삭제 ======= \n");

    char search[40] = { 0 };
    int* srarchAdress = 0; // 검색어와 일치하는 항목의 주소(배열번호) 를 담을 검색어주소배열 설정
    srarchAdress = (int*)malloc(sizeof(int) * (*lineCount)); // 검색어와 일치하는 항목은 최대 전체 항목 수와 같으므로 동적메모리 설정 
    int adressIndex = 0; // 검색어와 일치하는 항목의 배열번호의 순번을 담을 검색어주소배열순번 설정 
     // 검색 시작 
    printf("%s\n", "... 검색어?");

    do {
      
        strcpy(search, "\0");
        scanf("%[^\n]s", search);

        char check = 0;
        do{
            check = getchar();
        } while (check != '\n');

    } while ( rightsize(search, 40) == 1 || IsNoEnter(search) == 1); // 검색어가 20자 이내인지, 엔터나 스페이스바는 없는지 검사 
    
    for (int i = 0; i < *lineCount; i++) { // 검색어와 항목의 이름, 전화번호, 관계, 이메일을 부분 문자열 비교를 통해 일부라도 일치한다면 모두 출력함 
        if ((strstr(nowBook[i].name, search) != NULL) || (strstr(nowBook[i].num, search) != NULL) || (strstr(nowBook[i].relation, search) != NULL) || (strstr(nowBook[i].mail, search) != NULL)) {
            srarchAdress[adressIndex] = i; // 검색되는 항목의 배열 번호를 searchAdress 배열에 담음
            adressIndex++; // 한번 찾을때마다 adressIndex 의 번호를 증가시킴 따라서 adressIndex 는 검색된 총 항목의 갯수를 뜻함  
        }
    }

    printf("... 총 %d개의 목록 검색!\n", adressIndex); // 검색어와 일치하는 항목을 전체 출력함 

    if (adressIndex != 0) { // 만약 검색된 항목이 1개 이상이라면 .. 
        printf("========================================================================================================\n");
        printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "번호", "이름", "전화번호", "관계", "메일", "긴급연락처 등록 여부");
        printf("--------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < adressIndex; i++) {
            printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", i + 1, nowBook[srarchAdress[i]].name, nowBook[srarchAdress[i]].num, nowBook[srarchAdress[i]].relation, nowBook[srarchAdress[i]].mail, nowBook[srarchAdress[i]].sos);

        }
        printf("========================================================================================================\n");
        printf("%s", "======= 다음 작업 ======= \n"); //수정, 삭제, 검색종료에서 원하는 작업을 고름 
        printf("01. 수정\n02. 삭제\n03. 검색 종료\n");
        int key = 0; // 다음 작업의 메뉴 번호를 저장할 변수 선언 
        key = rightkey(3);

        // 수정 시작 
        while (key != 3) {
            if (key == 1) {
                struct base buffer = { 0 };

                if (adressIndex != 1) {
                    printf("%s\n", "... 수정을 원하는 목록의 번호?");
                    adressIndex = rightkey(adressIndex); // 수정을 원하는 번호를 입력받음 
                }
                printf("===============================================================================================================\n"); // 입력한 번호의 내용을 출력 
                printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "번호", "이름", "전화번호", "관계", "메일", "긴급연락처 등록 여부");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", 1, nowBook[srarchAdress[adressIndex - 1]].name, nowBook[srarchAdress[adressIndex - 1]].num, nowBook[srarchAdress[adressIndex - 1]].relation, nowBook[srarchAdress[adressIndex - 1]].mail, nowBook[srarchAdress[adressIndex - 1]].sos);
                printf("===============================================================================================================\n");
                printf("%s\n", "... 수정 할 항목?");
                printf("%s\n%s\n%s\n%s\n%s\n", "1. 이름", "2. 전화번호", "3. 관계", "4. 메일", "5. 긴급 연락처"); // 수정할 구조체 멤버를 입력받음 
                int memberKey = 0;

                memberKey = rightkey(5); // 무슨 멤버를 수정할지 입력받는 변수 
                if (memberKey == 1) { // 멤버를 수정하는 것은 입력과 비슷 
                    do {
                        printf("%s %s\n", "... 수정 할 내용? 현재 내용 : ", nowBook[srarchAdress[adressIndex - 1]].name); // 현재 작성된 내용을 보여줌 
                        scanf("%[^\n]s", buffer.name);
                        getchar();
                        if (IsSameName(nowBook, buffer.name, *lineCount) == 2 ) { // 수정한 내용이 이미 연락처에 존재하면 다시 입력시키거나 메뉴로 돌려보냄 
                            strcpy(buffer.name, nowBook[srarchAdress[adressIndex - 1]].name);
                        }
                    } while (IsNoEnter(buffer.name) != 0 || rightsize(buffer.name, 40) != 0);
                      strcpy(nowBook[srarchAdress[adressIndex - 1]].name, buffer.name);
                    
                }
                else if (memberKey == 2) {
                    int again = 0;
                    do {
                        again = 0;
                        printf("%s %s\n", "... 수정 할 내용? 현재 내용 : ", nowBook[srarchAdress[adressIndex - 1]].num);
                        scanf("%[^\n]s", buffer.num);
                        getchar();
                        int isSameNum = IsSameNum(nowBook, buffer.num, *lineCount);
                        if (isSameNum == 2) {
                            strcpy(buffer.num, nowBook[srarchAdress[adressIndex - 1]].num);
                        }
                        else if (isSameNum == 1) {
                            again = isSameNum;
                        }
                    } while (again == 1 || (IsNoEnter(buffer.num) != 0) || (IsNum(buffer.num) != 0) || rightsize(buffer.num, 12) != 0);
                    strcpy(nowBook[srarchAdress[adressIndex - 1]].num, buffer.num);

                }
                else if (memberKey == 3) {

                    do {
                        printf("%s %s\n", "... 수정 할 내용? 현재 내용 : ", nowBook[srarchAdress[adressIndex - 1]].relation);
                        scanf("%[^\n]s", buffer.relation);
                        getchar();

                    } while (IsNoSpaceBar(buffer.relation) != 0 || rightsize(buffer.relation, 40) != 0);

                    strcpy(nowBook[srarchAdress[adressIndex - 1]].relation, buffer.relation);

                    if (strlen(buffer.relation) == 0) {
                        strcpy(nowBook[srarchAdress[adressIndex - 1]].relation, "-");
                    }


                }
                else if (memberKey == 4) {
                    int again = 0;
                    do {
                        again = 0;
                        printf("%s %s\n", "... 수정 할 내용? 현재 내용 : ", nowBook[srarchAdress[adressIndex - 1]].mail);

                        scanf("%[^\n]s", buffer.mail);
                        getchar();
                        int isSameMail = IsSameMail(nowBook, buffer.mail, *lineCount);
                        if (isSameMail == 2) {
                            strcpy(buffer.mail, nowBook[srarchAdress[adressIndex - 1]].mail);
                        }
                        else if (isSameMail == 1) {
                            again = isSameMail;
                        }
                    } while (again == 1 || IsMail(buffer.mail) != 0 || IsNoSpaceBar(buffer.mail) != 0 || rightsize(buffer.mail, 30) != 0);
                    strcpy(nowBook[srarchAdress[adressIndex - 1]].mail, buffer.mail);
                    if (strlen(buffer.mail) == 0) {
                        strcpy(nowBook[srarchAdress[adressIndex - 1]].mail, "-");
                    }
                }
                else if (memberKey == 5) {
                    int again = 0;
                    do {
                        again = 0;
                        char answer = 0;
                        char check = 0;
                        if (strcmp(nowBook[srarchAdress[adressIndex - 1]].sos, "O") == 0) { // 이미 긴급 연락처로 등록되어있으면 해제할건지 물어봄 
                            printf("... 긴급 연락처에서 해제 하시겠습니까? \n[Y/N]\n");
                            scanf(" %c", &answer);
                            do {
                                check = getchar();
                            } while (check != '\n');
                            if (answer == 'Y' || answer == 'y') {
                                strcpy(nowBook[srarchAdress[adressIndex - 1]].sos, "-"); // 해제하면 - 값으로 바꿈 
                                
                            }
                            else if (answer == 'N' || answer == 'n') {
                                break;
                            }
                            else {
                                printf("\n... 올바른 문자를 입력 해 주세요.\n");
                                again = 1;
                            }

                        }
                        else {
                            printf("... 긴급 연락처로 등록 하시겠습니까? \n[Y/N]\n"); // 긴급 연락처로 등록 안되어있으면 등록할지 물어봄 
                            scanf(" %c", &answer);
                            do {
                                check = getchar();
                            } while (check != '\n');
                            if (answer == 'Y' || answer == 'y') {
                                strcpy(nowBook[srarchAdress[adressIndex - 1]].sos, "O"); // 등록하면 O 값으로 바꿈 
                                
                            }
                            else if (answer == 'N' || answer == 'n') {
                                break;
                            }
                            else {
                                printf("\n... 올바른 문자를 입력 해 주세요.\n");
                                again = 1;
                            }

                        }
                    } while (again == 1);               

                } 
                printf("%s\n", "...  작업을 저장합니다.");
                printf("===============================================================================================================\n");
                printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "번호", "이름", "전화번호", "관계", "메일", "긴급연락처 등록 여부");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", 1, nowBook[srarchAdress[adressIndex - 1]].name, nowBook[srarchAdress[adressIndex - 1]].num, nowBook[srarchAdress[adressIndex - 1]].relation, nowBook[srarchAdress[adressIndex - 1]].mail, nowBook[srarchAdress[adressIndex - 1]].sos);
                printf("===============================================================================================================\n");
               
                

                free(srarchAdress);  // 동적메모리 해제
                srarchAdress = NULL;
                  return nowBook;
            } 
            // 삭제 시작 
            else if (key == 2) {

                if (adressIndex != 1) {
                    printf("%s\n", "... 삭제를 원하는 목록의 번호?"); //검색된 항목이 2개 이상이면 삭제할 항목의 번호를 입력받음 
                    adressIndex = rightkey(adressIndex);
                }

                for (int i = srarchAdress[adressIndex - 1] + 1 ; i < (*lineCount); i++) { // 항목의 이전은 유지하고, 항목의 이후를 한칸식 당겨서 선택한 항목을 없어지게 만듬 

                    strcpy(nowBook[i - 1].name, nowBook[i].name);
                    strcpy(nowBook[i - 1].num, nowBook[i].num);
                    strcpy(nowBook[i - 1].relation, nowBook[i].relation);
                    strcpy(nowBook[i - 1].mail, nowBook[i].mail);
                    strcpy(nowBook[i - 1].sos, nowBook[i].sos);

                }

                *lineCount = (*lineCount) - 1; // 삭제를 완료하면 줄수를 한칸 줄임 

                printf("%s\n", "... 삭제 완료! \n");
                free(srarchAdress);  // 동적메모리 해제
                srarchAdress = NULL;
                return nowBook;
                

            }
            else if (key == 3) { // 검색 종료 항목을 누르면 메뉴 화면으로 돌아가게 함 

                printf("... 검색 종료\n");
                free(srarchAdress);  // 동적메모리 해제
                srarchAdress = NULL;
                return nowBook;
            }
        
            else {
                printf("%s", "\n다시 입력!\n\n"); // 잘못된 값을 입력하면 다시 입력하게 함 

            }
            free(srarchAdress);  // 동적메모리 해제
            srarchAdress = NULL;
            return nowBook;
            
         
        }
        free(srarchAdress);  // 반복문 종료 시 
        srarchAdress = NULL;
        return nowBook;
    }
    else{ // 아무 목록도 검색되지 않았을 때, 메뉴 화면으로 돌려보냄 
        
        free(srarchAdress);  // 동적메모리 해제
        srarchAdress = NULL;
        return nowBook; }

}
