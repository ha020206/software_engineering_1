#include "numbook.h"

void WriteOnFile(struct base* arr, int size) { // ��ȭ��ȣ�� ����� ���Ͽ� ����� ����ó�� ���� �޸𸮿� ������ 

	FILE* book = { 0 };
	book = fopen("book.txt", "w+"); //��ȭ��ȣ�� ������ ����� ���� ���� W �̿�  

	for (int i = 0; i < size; i++) {
		fprintf(book, "%s / %s / %s / %s / %s / \n", arr[i].name, arr[i].num, arr[i].relation, arr[i].mail, arr[i].sos); // ��ȭ��ȣ�� �迭�� '/' ������ ��� ���Ͽ� ���پ� ���� 
	}

	fclose(book);

}

