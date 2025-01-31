#include "numbook.h"

int sameName = 0;

int IsSameName(struct base* nowbook, char* name, int size) {
	int i = 0;
	for ( i = 0; i < size; i++) {
		if ( strcmp(nowbook[i].name ,name) == 0 ) {
			sameName = 1;
			break;
		}
	}
	if (i == size) {
		return 0;
	}

	while (sameName == 1) {
		char answer = 0;
		char check = 0;

		printf("... 전화번호부에 동일한 이름이 존재합니다. 그래도 저장 하시겠습니까? \n[Y/N]");

		scanf(" %c", &answer);

		do { check = getchar();
		} while (check != '\n');

		if (answer == 'y' || answer == 'Y') {
			printf("\n... [ %s ] 을/를 저장합니다. \n", name);
			sameName = 0;
			break;
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n...  메뉴로 돌아갑니다. \n");
			sameName = 0;
			return 2;
		}
		else {
			printf("\n... 올바른 문자를 입력 해 주세요.\n");
		}
	}
}
		
			
			


int IsSameNum(struct base* nowbook, char * num, int size) {
	int i = 0;
	int sameNum = 0;
	for (i = 0; i < size; i++) {
		if ( strcmp( nowbook[i].num ,num ) == 0) {
			sameNum = 1;

			break;
		}
		
	}
	if (i == size ) {
		return 0;
	}
	
	while (sameNum == 1) {
		char answer = 0;
		char check = 0;

		printf("... 전화번호부에 동일한 전화번호가 존재합니다. 다른 전화번호를 저장 하시겠습니까?  \n[Y/N]\n");
		scanf(" %c", &answer);
		while (check != '\n') {
			check = getchar();
		}



		if (answer == 'y' || answer == 'Y') {
			printf("\n... 저장을 원하는 전화번호를 다시 입력하세요.\n");
			sameNum = 0;
			return 1;
			
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n... 메뉴로 돌아갑니다. \n");
			sameNum = 0;
			return 2;
		}
		else {
			printf("\n... 올바른 문자를 입력 해 주세요.\n");

		}

	}

}


int sameMail = 0;
int IsSameMail(struct base* nowbook, char* mail, int size) {
	int i = 0;
	for (i = 0; i < size ; i++) {
		if (strcmp(nowbook[i].mail, mail) == 0 ) {
			sameMail = 1;
			break;

		}
	}
	if (i == size) {
		return 0;
	}
	if (sameMail == 1) {
		printf("... 전화번호부에 동일한 이메일이 존재합니다. 다른 이메일을 저장 하시겠습니까? \n[Y/N]");
	}
	while (sameMail == 1) {
		char answer = 0;
		char check = 0;

		scanf(" %c", &answer);
		do {
			check = getchar();
		} while (check != '\n');

		if (answer == 'y' || answer == 'Y') {
			printf("\n... 저장을 원하는 이메일을 다시 입력하세요.\n");
			sameMail = 0;
			return 1;
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n... 메뉴로 돌아갑니다. \n");
			sameMail = 0;
			return 2;
		}
		else {
			printf("\n... 올바른 문자를 입력 해 주세요.\n");
		}
	}
}
