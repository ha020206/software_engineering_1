#include "numbook.h"

int rightsize(char *arr, int size) {
	char check = 0;
	if ( strlen(arr) >= size ) {
		printf("... 글자의 개수가 올바르지 않습니다. \n");
	
		return 1;
	}
	else if ( strstr(arr, " ") ) {
		printf("... 공백은 입력할 수 없습니다.\n");
		
		return 1;
	}

		return 0;
	
}

