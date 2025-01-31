#include "numbook.h"

int rightkey(int size) {
	int i = 0;
	while (1) {
		char check = 0;
		int key = 0;

		scanf(" %d", &key); // 정수형으로 한글자를 입력받음 
		while (check != '\n') {
			check = getchar();
		}
		for (i = 1; i <= size;i++) {
			if (key == i ){

				return i;
				break;
			}
		}

		if (i == size + 1) {
			printf("... 메뉴와 맞는 숫자를 입력하세요.\n");
		
		}
	}
}
