#include "numbook.h"

void WriteOnFile(struct base* arr, int size) { // 전화번호부 종료시 파일에 저장된 연락처를 적어 메모리에 저장함 

	FILE* book = { 0 };
	book = fopen("book.txt", "w+"); //전화번호부 내용을 지우고 새로 쓰는 W 이용  

	for (int i = 0; i < size; i++) {
		fprintf(book, "%s / %s / %s / %s / %s / \n", arr[i].name, arr[i].num, arr[i].relation, arr[i].mail, arr[i].sos); // 전화번호부 배열을 '/' 단위로 끊어서 파일에 한줄씩 적음 
	}

	fclose(book);

}

