#include "numbook.h"

int ReadFileLine() {

    int lineCount = 0;
    FILE* book = { 0 };
    book = fopen("book.txt", "a+"); //��ȭ��ȣ�� ���� ���� ���ٸ� �����

    char word = 0; // txt������ ���� 1������ �˻��ϴ� ���� 

    // txt ������ �� �� count
    while ((word = fgetc(book)) != EOF) // ������ ���� �� ������ �ѱ��ھ� �Է¹޾� �˻� 
    {
        if (word == '\n') {     // �ٹٲ� ���ڰ� �ִٸ� lineCount �� ������Ŵ 
            lineCount++;
        }
    }
    fclose(book); // ��ȭ��ȣ�� ���� �ݱ�

    return lineCount; // �� ���� ������ 
} 



