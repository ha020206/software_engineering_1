#include "numbook.h"

int rightsize(char *arr, int size) {
	char check = 0;
	if ( strlen(arr) >= size ) {
		printf("... ������ ������ �ùٸ��� �ʽ��ϴ�. \n");
	
		return 1;
	}
	else if ( strstr(arr, " ") ) {
		printf("... ������ �Է��� �� �����ϴ�.\n");
		
		return 1;
	}

		return 0;
	
}

