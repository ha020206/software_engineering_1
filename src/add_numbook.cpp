#include "numbook.h"
// ��ȭ��ȣ�ο� ���ο� ����ó�� �����ϴ� �Լ� 
struct base AddNumBook(struct base* nowBook, int* lineCount) {
	int size = *lineCount; // �����͸� ���� ������� �ʵ���, �� ���� ���ο� ������ �Է� ���� 
	int again = 0;  // ������ ����� �̹� ��ȭ��ȣ�ο� ������ �� �ٽ� �Է¹ް� �ϴ� ���� ���� 
	struct base newRecord = { 0 }; // ���ο� ����ó�� �Է¹��� ����ü ���� ���� 
	printf("%s", "======= 01. �߰� ======= \n");
	// �̸� �߰� 
	do {
		strcpy(newRecord.name, "\0"); // ����ü�� �ʱ�ȭ 
		printf("%s", "�̸�?\n");
		scanf("%[^\n]s", newRecord.name);
		getchar();
		if (IsSameName(nowBook, newRecord.name, size) == 2) { // ������ ��Ͽ� �Է��� �̸��� ������ ��, ���ο� �̸��� �Է����� �ʰڴٰ� �����ϸ� �޴� ȭ������ ���� 
			return { 0 };
		}
	} while (IsNoEnter(newRecord.name) != 0 || rightsize(newRecord.name, 40) != 0);
	// �̸��� ������ ������, ũ�⿡ �°� �Է��ߴ��� �˻��ϰ� �ƴϸ� �ٽ� �Է��ϰ� �� 
	// ��ȭ��ȣ �߰� 
	do {
		again = 0;
		strcpy(newRecord.num, "\0");
		printf("%s", "��ȭ��ȣ? \n");
		scanf("%[^\n]s", newRecord.num);
		getchar();
		int isSameNum = IsSameNum(nowBook, newRecord.num, size); // ������ ��ϰ� ���� �Է¹��� ��ȭ��ȣ�� �˻��ϰ� ���� ���Ϲ��� 

		if (isSameNum == 2) { // ������ ��ȭ��ȣ�� ���� ����� �����Ͽ� ���ο� ��ȭ��ȣ�� �Է����� �ʰڴٰ� �����ϸ� �޴� ȭ������ ���� 
			return { 0 };
		}
		else if (isSameNum == 1) { // ������ ��ȭ��ȣ�� ���� ����� �����Ͽ� ���ο� ��ȭ��ȣ�� �Է��ϰڴٰ� �ϸ� ���� �Է��ϰ� �� 
			again = 1;
		}

	} while (again == 1 || (IsNoEnter(newRecord.num) != 0) || (IsNum(newRecord.num) != 0) || rightsize(newRecord.num, 12) != 0 );
	// ��ȭ��ȣ�� ������ �����ϴ���, ���ڷθ� �Է��ߴ���, ũ�⿡ �°� �Է��ߴ��� �˻��ϰ� �ƴϸ� �ٽ� �Է��ϰ� �� 
	// ���� �߰� 
	do {
		strcpy(newRecord.relation, "\0");
		printf("%s", "����? (������ ���� �� ���͸� ��������.)\n"); // ����� �ʼ������� �Է��� ���� �ʰ� ���͸� �Է��ϸ� '-' ���� ��ü��Ŵ 
		scanf("%[^\n]s", newRecord.relation);
		getchar();

	} while (IsNoSpaceBar(newRecord.relation) != 0 || rightsize(newRecord.relation, 40) != 0); // ' '���ڰ� �����ϰų� ũ�⿡ ���� �ʰ� �Է��ϸ� �ٽ� �Է��ϰ� �� 

	if (strlen(newRecord.relation) == 0) { // ���͸� �Է����� ��, '-' ���� ��ü�� 
		strcpy(newRecord.relation, "-");
	}
	// �̸��� �߰� 
	do {
		again = 0;
		strcpy(newRecord.mail, "\0");
		printf("%s", "����? (������ ���� �� ���͸� ��������.)\n"); // �̸����� �ʼ������� �Է��� ���� �ʰ� ���͸� ������ - ���� ��ü��Ŵ 
		scanf("%[^\n]s", newRecord.mail);
		getchar();
		int isSameMail = IsSameMail(nowBook, newRecord.mail, size); // ��Ͽ� �̹� ���� �̸����� �ִ��� �˻��ϰ� ���ϰ��� ������ 
		if (isSameMail == 2) { // ��Ͽ� ���� ������ �ְ� ���� �Է����� �ʴ´ٰ� �ϸ� �޴� ȭ������ ���� 
			return { 0 };
		}
		else if (isSameMail == 1) { // ��Ͽ� ���� ������ �ְ� ���� �Է��Ѵٰ� �ϸ� �ٽ� �Է��ϰ� �� 
			again = 1;

		}

	} while (IsMail(newRecord.mail) != 0 || IsNoSpaceBar(newRecord.mail) != 0 || rightsize(newRecord.mail, 30) != 0 || again == 1);
	// ������ ���Ŀ� ���߾� �Է� �ߴ���, ������ ������, ����� �°� �Է��ߴ��� �˻��� 

		if (strlen(newRecord.mail) == 0) { // ���࿡ ���͸� ������ ���������� ��ü��Ŵ 
		strcpy(newRecord.mail, "-");
	}


// ��� ����ó ��� ���� 
	do {
		again = 0;
		strcpy(newRecord.sos, "\0");
		printf("%s", "\n��� ����ó�� ��� �Ͻðڽ��ϱ�? (������ ���� �� ���͸� ��������) \n[Y/N]\n"); // ��� ����ó ��� ���θ� ���
		char buffer[2] = { 0 }; // ��� ���θ� �Է¹��� ���ڿ��� ������ 
		do {
			strcpy(buffer, "\0");
			scanf("%[^\n]s", buffer);
			getchar();
		} while ( rightsize(buffer, 2) != 0 ) ; // �ʹ� ���� ���ڸ� �Է��ϸ� �ٽ� �Է��϶�� �ȳ��� 

		if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0) { // ���� �Ѵٰ� �ϸ� ��� ����ó ���� �׸� O�� �Է��� 
			strcpy(newRecord.sos, "O");
		}
		else if (strcmp(buffer, "N") == 0 || strcmp(buffer, "n") == 0 || strlen(buffer) == 0 ){ // ���� ���Ѵٰ� �ϸ� - �� �Է��� 
			strcpy(newRecord.sos, "-");
		}
		else {
			printf("... �ùٸ� ���� �Է��ϼ���."); // y �� n�� ������ ���� �����̽��� �� �ٸ� ���� �Է��ϸ� �ٽ� �Է��϶�� ��� 
			again = 1;
		}
	} while ( again == 1);
	printf("========================================================================================================\n");
	printf("%-20s %-20s %-20s %-20s %-20s\n", "�̸�", "��ȭ��ȣ", "����", "����", "��޿���ó ��� ����");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%-20s %-20s %-20s %-20s %-20s\n", newRecord.name , newRecord.num , newRecord.relation , newRecord.mail , newRecord.sos);
	printf("========================================================================================================\n");
	printf("%s\n", "... ���� �Ϸ�!"); // ������ �� ������, ������ �Ϸ��ߴٰ� ����� 
	*lineCount = (*lineCount) + 1; // ������ �� ������, ������ �� ��(�Է¹��� ��ȭ��ȣ�� ����) �� ������Ŵ 

	return newRecord; // �Է¹��� ����ü�� ������ 

}

int IsNoEnter(char* arr) { // ������ �Է��ߴ��� �˻��ϴ� �Լ� 
	if ( strlen(arr) == 0 || strstr(arr, " ")) {
		printf("...  ������ �Է��� �� �����ϴ�.\n");


		return 1;
	}
	return 0;
}

int IsNoSpaceBar(char* arr) {
	if (strstr(arr, " ")) {
		printf("... ������ �Է��� �� �����ϴ�.\n");


		return 1;
	}
	return 0;
}

int IsNum(char* num) {

	for (int i = 0; num[i] != '\0'; i++) { // null ���ڱ��� Ȯ��
		if (num[i] & 0x80) { // �ѱ��� ���
			printf("... ���ڷθ� �Է��ϼ���.\n");
			return 1; // ���� �ڵ� ��ȯ
		}
		else if ( isdigit(num[i]) == 0 ) { // ���ڰ� �ƴ� ���(����), Ư����ȣ�� ��� 
			printf("... ���ڷθ� �Է��ϼ���. \n");

			return 1; // ���� �ڵ� ��ȯ
		}
	}
		return 0;
}

int IsMail(char* mail) {
	if (strlen(mail) != 0) {
		for (int i = 0; mail[i] != '\0'; i++) { // null ���ڱ��� Ȯ��
			if (!strstr(mail, "@") || !strstr(mail, ".") ) { // ����̿� ���� ������ ���� ���� ���
				printf("... ���� �������� �Է��ϼ���.\n");
				*mail = 0;
				return 1; // ���� �ڵ� ��ȯ
			}
			else if(mail[i] & 0x80) { // �ѱ��� ���
				printf("... �ѱ��� �Է��� �� �����ϴ�.\n");
				*mail = 0;
				return 1; // ���� �ڵ� ��ȯ
			}
		}
	}
	return 0;
}