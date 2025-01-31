#include "numbook.h"
// ����Ʈ������� 1�� ���� 
// AI����Ʈ�����а� 202322371 �Ͻ¿�
// �۾�ȯ�� : visualstudio 2022

// ���α׷� ���� �Լ�  
int main() {

   
    printf("... ��ȭ��ȣ�θ� �����մϴ�.\n");  

    printf("... 'book.txt' ���Ͽ��� �����͸� �д� ��"); // �۾� �������̶�� �ȳ��޼��� ��� 


    int key = 0; // �޴��� ��ȣ�� �Է¹��� ���� ����
 
    int lineCount = 0; // ������ �� �� �� �� ���� ����
    lineCount = ReadFileLine();  // ������ �� �� (��ȭ��ȣ���� ����) �� �����ϴ� ���� ����


    FILE* book = { 0 };
    book = fopen("book.txt", "a+"); // �����̱� ������� ���� 

    // txt ������ �ٺ��� ����ü �迭�� ����
    struct base* nowBook = NULL;
    nowBook = (struct base*)malloc(sizeof(struct base) * lineCount); //�����޸� ����

   
   
    for (int i = 0;i < lineCount;i++) {
        fscanf(book, "%s / %s / %s / %s / %s / \n", nowBook[i].name, nowBook[i].num, nowBook[i].relation, nowBook[i].mail, nowBook[i].sos);

    }

    for (int i = 0; i < 3; i++) {
        printf("%c", '.');
        Sleep(800); // 0.8�ʾ� 3�� ���� ����Ͽ� ȭ���� �ٷ� �������°��� ������ 
    }

    printf("\n... ������ �б� �Ϸ� !\n");

    fclose(book);

    printf("\n... ��ȭ��ȣ�θ� �����Ϸ��� �ƹ� Ű�� �����ּ���.\n");
    getchar();
    system("cls"); // ȭ���� �����ϰ� ����� �Լ�

    while (key != 4) {

        SortName( nowBook, lineCount); // �̸� ���� �Լ�
        
        printf("%s", "======= �޴� ======= \n");
        printf("%s\n%s\n%s\n%s\n", "01. �߰�", "02. �˻� �� ����/����", "03. ���", "04. ���� �� ����");
   
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
         
            printf("%s", "======= 04. ���� �� ���� ======= \n");
            printf("%s", "... �����͸� 'book.txt' ���Ͽ� �����մϴ�. \n");
            WriteOnFile(nowBook, lineCount);
            ScreenClear();

            free(nowBook);  // �����޸� ����
            nowBook = NULL;

        }

    }

}