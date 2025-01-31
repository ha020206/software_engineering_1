#include "numbook.h"

struct base* SearchNumBook(struct base* nowBook, int* lineCount) {
    printf("%s", "======= 02. �˻� �� ����/���� ======= \n");

    char search[40] = { 0 };
    int* srarchAdress = 0; // �˻���� ��ġ�ϴ� �׸��� �ּ�(�迭��ȣ) �� ���� �˻����ּҹ迭 ����
    srarchAdress = (int*)malloc(sizeof(int) * (*lineCount)); // �˻���� ��ġ�ϴ� �׸��� �ִ� ��ü �׸� ���� �����Ƿ� �����޸� ���� 
    int adressIndex = 0; // �˻���� ��ġ�ϴ� �׸��� �迭��ȣ�� ������ ���� �˻����ּҹ迭���� ���� 
     // �˻� ���� 
    printf("%s\n", "... �˻���?");

    do {
      
        strcpy(search, "\0");
        scanf("%[^\n]s", search);

        char check = 0;
        do{
            check = getchar();
        } while (check != '\n');

    } while ( rightsize(search, 40) == 1 || IsNoEnter(search) == 1); // �˻�� 20�� �̳�����, ���ͳ� �����̽��ٴ� ������ �˻� 
    
    for (int i = 0; i < *lineCount; i++) { // �˻���� �׸��� �̸�, ��ȭ��ȣ, ����, �̸����� �κ� ���ڿ� �񱳸� ���� �Ϻζ� ��ġ�Ѵٸ� ��� ����� 
        if ((strstr(nowBook[i].name, search) != NULL) || (strstr(nowBook[i].num, search) != NULL) || (strstr(nowBook[i].relation, search) != NULL) || (strstr(nowBook[i].mail, search) != NULL)) {
            srarchAdress[adressIndex] = i; // �˻��Ǵ� �׸��� �迭 ��ȣ�� searchAdress �迭�� ����
            adressIndex++; // �ѹ� ã�������� adressIndex �� ��ȣ�� ������Ŵ ���� adressIndex �� �˻��� �� �׸��� ������ ����  
        }
    }

    printf("... �� %d���� ��� �˻�!\n", adressIndex); // �˻���� ��ġ�ϴ� �׸��� ��ü ����� 

    if (adressIndex != 0) { // ���� �˻��� �׸��� 1�� �̻��̶�� .. 
        printf("========================================================================================================\n");
        printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "��ȣ", "�̸�", "��ȭ��ȣ", "����", "����", "��޿���ó ��� ����");
        printf("--------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < adressIndex; i++) {
            printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", i + 1, nowBook[srarchAdress[i]].name, nowBook[srarchAdress[i]].num, nowBook[srarchAdress[i]].relation, nowBook[srarchAdress[i]].mail, nowBook[srarchAdress[i]].sos);

        }
        printf("========================================================================================================\n");
        printf("%s", "======= ���� �۾� ======= \n"); //����, ����, �˻����ῡ�� ���ϴ� �۾��� �� 
        printf("01. ����\n02. ����\n03. �˻� ����\n");
        int key = 0; // ���� �۾��� �޴� ��ȣ�� ������ ���� ���� 
        key = rightkey(3);

        // ���� ���� 
        while (key != 3) {
            if (key == 1) {
                struct base buffer = { 0 };

                if (adressIndex != 1) {
                    printf("%s\n", "... ������ ���ϴ� ����� ��ȣ?");
                    adressIndex = rightkey(adressIndex); // ������ ���ϴ� ��ȣ�� �Է¹��� 
                }
                printf("===============================================================================================================\n"); // �Է��� ��ȣ�� ������ ��� 
                printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "��ȣ", "�̸�", "��ȭ��ȣ", "����", "����", "��޿���ó ��� ����");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", 1, nowBook[srarchAdress[adressIndex - 1]].name, nowBook[srarchAdress[adressIndex - 1]].num, nowBook[srarchAdress[adressIndex - 1]].relation, nowBook[srarchAdress[adressIndex - 1]].mail, nowBook[srarchAdress[adressIndex - 1]].sos);
                printf("===============================================================================================================\n");
                printf("%s\n", "... ���� �� �׸�?");
                printf("%s\n%s\n%s\n%s\n%s\n", "1. �̸�", "2. ��ȭ��ȣ", "3. ����", "4. ����", "5. ��� ����ó"); // ������ ����ü ����� �Է¹��� 
                int memberKey = 0;

                memberKey = rightkey(5); // ���� ����� �������� �Է¹޴� ���� 
                if (memberKey == 1) { // ����� �����ϴ� ���� �Է°� ��� 
                    do {
                        printf("%s %s\n", "... ���� �� ����? ���� ���� : ", nowBook[srarchAdress[adressIndex - 1]].name); // ���� �ۼ��� ������ ������ 
                        scanf("%[^\n]s", buffer.name);
                        getchar();
                        if (IsSameName(nowBook, buffer.name, *lineCount) == 2 ) { // ������ ������ �̹� ����ó�� �����ϸ� �ٽ� �Է½�Ű�ų� �޴��� �������� 
                            strcpy(buffer.name, nowBook[srarchAdress[adressIndex - 1]].name);
                        }
                    } while (IsNoEnter(buffer.name) != 0 || rightsize(buffer.name, 40) != 0);
                      strcpy(nowBook[srarchAdress[adressIndex - 1]].name, buffer.name);
                    
                }
                else if (memberKey == 2) {
                    int again = 0;
                    do {
                        again = 0;
                        printf("%s %s\n", "... ���� �� ����? ���� ���� : ", nowBook[srarchAdress[adressIndex - 1]].num);
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
                        printf("%s %s\n", "... ���� �� ����? ���� ���� : ", nowBook[srarchAdress[adressIndex - 1]].relation);
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
                        printf("%s %s\n", "... ���� �� ����? ���� ���� : ", nowBook[srarchAdress[adressIndex - 1]].mail);

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
                        if (strcmp(nowBook[srarchAdress[adressIndex - 1]].sos, "O") == 0) { // �̹� ��� ����ó�� ��ϵǾ������� �����Ұ��� ��� 
                            printf("... ��� ����ó���� ���� �Ͻðڽ��ϱ�? \n[Y/N]\n");
                            scanf(" %c", &answer);
                            do {
                                check = getchar();
                            } while (check != '\n');
                            if (answer == 'Y' || answer == 'y') {
                                strcpy(nowBook[srarchAdress[adressIndex - 1]].sos, "-"); // �����ϸ� - ������ �ٲ� 
                                
                            }
                            else if (answer == 'N' || answer == 'n') {
                                break;
                            }
                            else {
                                printf("\n... �ùٸ� ���ڸ� �Է� �� �ּ���.\n");
                                again = 1;
                            }

                        }
                        else {
                            printf("... ��� ����ó�� ��� �Ͻðڽ��ϱ�? \n[Y/N]\n"); // ��� ����ó�� ��� �ȵǾ������� ������� ��� 
                            scanf(" %c", &answer);
                            do {
                                check = getchar();
                            } while (check != '\n');
                            if (answer == 'Y' || answer == 'y') {
                                strcpy(nowBook[srarchAdress[adressIndex - 1]].sos, "O"); // ����ϸ� O ������ �ٲ� 
                                
                            }
                            else if (answer == 'N' || answer == 'n') {
                                break;
                            }
                            else {
                                printf("\n... �ùٸ� ���ڸ� �Է� �� �ּ���.\n");
                                again = 1;
                            }

                        }
                    } while (again == 1);               

                } 
                printf("%s\n", "...  �۾��� �����մϴ�.");
                printf("===============================================================================================================\n");
                printf("%-5s %-20s %-20s %-20s %-20s %-20s\n", "��ȣ", "�̸�", "��ȭ��ȣ", "����", "����", "��޿���ó ��� ����");
                printf("---------------------------------------------------------------------------------------------------------------\n");
                printf("%-5d %-20s %-20s %-20s %-20s %-20s\n", 1, nowBook[srarchAdress[adressIndex - 1]].name, nowBook[srarchAdress[adressIndex - 1]].num, nowBook[srarchAdress[adressIndex - 1]].relation, nowBook[srarchAdress[adressIndex - 1]].mail, nowBook[srarchAdress[adressIndex - 1]].sos);
                printf("===============================================================================================================\n");
               
                

                free(srarchAdress);  // �����޸� ����
                srarchAdress = NULL;
                  return nowBook;
            } 
            // ���� ���� 
            else if (key == 2) {

                if (adressIndex != 1) {
                    printf("%s\n", "... ������ ���ϴ� ����� ��ȣ?"); //�˻��� �׸��� 2�� �̻��̸� ������ �׸��� ��ȣ�� �Է¹��� 
                    adressIndex = rightkey(adressIndex);
                }

                for (int i = srarchAdress[adressIndex - 1] + 1 ; i < (*lineCount); i++) { // �׸��� ������ �����ϰ�, �׸��� ���ĸ� ��ĭ�� ��ܼ� ������ �׸��� �������� ���� 

                    strcpy(nowBook[i - 1].name, nowBook[i].name);
                    strcpy(nowBook[i - 1].num, nowBook[i].num);
                    strcpy(nowBook[i - 1].relation, nowBook[i].relation);
                    strcpy(nowBook[i - 1].mail, nowBook[i].mail);
                    strcpy(nowBook[i - 1].sos, nowBook[i].sos);

                }

                *lineCount = (*lineCount) - 1; // ������ �Ϸ��ϸ� �ټ��� ��ĭ ���� 

                printf("%s\n", "... ���� �Ϸ�! \n");
                free(srarchAdress);  // �����޸� ����
                srarchAdress = NULL;
                return nowBook;
                

            }
            else if (key == 3) { // �˻� ���� �׸��� ������ �޴� ȭ������ ���ư��� �� 

                printf("... �˻� ����\n");
                free(srarchAdress);  // �����޸� ����
                srarchAdress = NULL;
                return nowBook;
            }
        
            else {
                printf("%s", "\n�ٽ� �Է�!\n\n"); // �߸��� ���� �Է��ϸ� �ٽ� �Է��ϰ� �� 

            }
            free(srarchAdress);  // �����޸� ����
            srarchAdress = NULL;
            return nowBook;
            
         
        }
        free(srarchAdress);  // �ݺ��� ���� �� 
        srarchAdress = NULL;
        return nowBook;
    }
    else{ // �ƹ� ��ϵ� �˻����� �ʾ��� ��, �޴� ȭ������ �������� 
        
        free(srarchAdress);  // �����޸� ����
        srarchAdress = NULL;
        return nowBook; }

}
