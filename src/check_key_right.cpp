#include "numbook.h"

int rightkey(int size) {
	int i = 0;
	while (1) {
		char check = 0;
		int key = 0;

		scanf(" %d", &key); // ���������� �ѱ��ڸ� �Է¹��� 
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
			printf("... �޴��� �´� ���ڸ� �Է��ϼ���.\n");
		
		}
	}
}
