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

		printf("... ��ȭ��ȣ�ο� ������ �̸��� �����մϴ�. �׷��� ���� �Ͻðڽ��ϱ�? \n[Y/N]");

		scanf(" %c", &answer);

		do { check = getchar();
		} while (check != '\n');

		if (answer == 'y' || answer == 'Y') {
			printf("\n... [ %s ] ��/�� �����մϴ�. \n", name);
			sameName = 0;
			break;
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n...  �޴��� ���ư��ϴ�. \n");
			sameName = 0;
			return 2;
		}
		else {
			printf("\n... �ùٸ� ���ڸ� �Է� �� �ּ���.\n");
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

		printf("... ��ȭ��ȣ�ο� ������ ��ȭ��ȣ�� �����մϴ�. �ٸ� ��ȭ��ȣ�� ���� �Ͻðڽ��ϱ�?  \n[Y/N]\n");
		scanf(" %c", &answer);
		while (check != '\n') {
			check = getchar();
		}



		if (answer == 'y' || answer == 'Y') {
			printf("\n... ������ ���ϴ� ��ȭ��ȣ�� �ٽ� �Է��ϼ���.\n");
			sameNum = 0;
			return 1;
			
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n... �޴��� ���ư��ϴ�. \n");
			sameNum = 0;
			return 2;
		}
		else {
			printf("\n... �ùٸ� ���ڸ� �Է� �� �ּ���.\n");

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
		printf("... ��ȭ��ȣ�ο� ������ �̸����� �����մϴ�. �ٸ� �̸����� ���� �Ͻðڽ��ϱ�? \n[Y/N]");
	}
	while (sameMail == 1) {
		char answer = 0;
		char check = 0;

		scanf(" %c", &answer);
		do {
			check = getchar();
		} while (check != '\n');

		if (answer == 'y' || answer == 'Y') {
			printf("\n... ������ ���ϴ� �̸����� �ٽ� �Է��ϼ���.\n");
			sameMail = 0;
			return 1;
		}
		else if (answer == 'n' || answer == 'N') {
			printf("\n... �޴��� ���ư��ϴ�. \n");
			sameMail = 0;
			return 2;
		}
		else {
			printf("\n... �ùٸ� ���ڸ� �Է� �� �ּ���.\n");
		}
	}
}
