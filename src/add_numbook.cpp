#include "numbook.h"
// 전화번호부에 새로운 연락처를 저장하는 함수 
struct base AddNumBook(struct base* nowBook, int* lineCount) {
	int size = *lineCount; // 포인터를 직접 사용하지 않도록, 줄 수를 새로운 변수에 입력 받음 
	int again = 0;  // 동일한 목록이 이미 전화번호부에 존재할 때 다시 입력받게 하는 변수 선언 
	struct base newRecord = { 0 }; // 새로운 연락처를 입력받을 구조체 변수 선언 
	printf("%s", "======= 01. 추가 ======= \n");
	// 이름 추가 
	do {
		strcpy(newRecord.name, "\0"); // 구조체를 초기화 
		printf("%s", "이름?\n");
		scanf("%[^\n]s", newRecord.name);
		getchar();
		if (IsSameName(nowBook, newRecord.name, size) == 2) { // 기존의 목록에 입력한 이름이 존재할 때, 새로운 이름을 입력하지 않겠다고 선택하면 메뉴 화면으로 보냄 
			return { 0 };
		}
	} while (IsNoEnter(newRecord.name) != 0 || rightsize(newRecord.name, 40) != 0);
	// 이름에 공백이 없는지, 크기에 맞게 입력했는지 검사하고 아니면 다시 입력하게 함 
	// 전화번호 추가 
	do {
		again = 0;
		strcpy(newRecord.num, "\0");
		printf("%s", "전화번호? \n");
		scanf("%[^\n]s", newRecord.num);
		getchar();
		int isSameNum = IsSameNum(nowBook, newRecord.num, size); // 기존의 목록과 새로 입력받은 전화번호를 검사하고 값을 리턴받음 

		if (isSameNum == 2) { // 기존의 전화번호와 같은 목록이 존재하여 새로운 전화번호를 입력하지 않겠다고 선택하면 메뉴 화면으로 보냄 
			return { 0 };
		}
		else if (isSameNum == 1) { // 기존의 전화번호와 같은 목록이 존재하여 새로운 전화번호를 입력하겠다고 하면 새로 입력하게 함 
			again = 1;
		}

	} while (again == 1 || (IsNoEnter(newRecord.num) != 0) || (IsNum(newRecord.num) != 0) || rightsize(newRecord.num, 12) != 0 );
	// 전화번호에 공백이 존재하는지, 숫자로만 입력했는지, 크기에 맞게 입력했는지 검사하고 아니면 다시 입력하게 함 
	// 관계 추가 
	do {
		strcpy(newRecord.relation, "\0");
		printf("%s", "관계? (생략을 원할 시 엔터를 누르세요.)\n"); // 관계는 필수적으로 입력을 받지 않고 엔터를 입력하면 '-' 으로 대체시킴 
		scanf("%[^\n]s", newRecord.relation);
		getchar();

	} while (IsNoSpaceBar(newRecord.relation) != 0 || rightsize(newRecord.relation, 40) != 0); // ' '문자가 존재하거나 크기에 맞지 않게 입력하면 다시 입력하게 함 

	if (strlen(newRecord.relation) == 0) { // 엔터를 입력했을 때, '-' 으로 대체함 
		strcpy(newRecord.relation, "-");
	}
	// 이메일 추가 
	do {
		again = 0;
		strcpy(newRecord.mail, "\0");
		printf("%s", "메일? (생략을 원할 시 엔터를 누르세요.)\n"); // 이메일은 필수적으로 입력을 받지 않고 엔터를 누르면 - 으로 대체시킴 
		scanf("%[^\n]s", newRecord.mail);
		getchar();
		int isSameMail = IsSameMail(nowBook, newRecord.mail, size); // 목록에 이미 같은 이메일이 있는지 검사하고 리턴값을 저장함 
		if (isSameMail == 2) { // 목록에 같은 메일이 있고 새로 입력하지 않는다고 하면 메뉴 화면으로 보냄 
			return { 0 };
		}
		else if (isSameMail == 1) { // 목록에 같은 메일이 있고 새로 입력한다고 하면 다시 입력하게 함 
			again = 1;

		}

	} while (IsMail(newRecord.mail) != 0 || IsNoSpaceBar(newRecord.mail) != 0 || rightsize(newRecord.mail, 30) != 0 || again == 1);
	// 메일의 형식에 맞추어 입력 했는지, 공백은 없는지, 사이즈를 맞게 입력했는지 검사함 

		if (strlen(newRecord.mail) == 0) { // 만약에 엔터를 누르면 하이픈으로 대체시킴 
		strcpy(newRecord.mail, "-");
	}


// 긴급 연락처 등록 여부 
	do {
		again = 0;
		strcpy(newRecord.sos, "\0");
		printf("%s", "\n긴급 연락처로 등록 하시겠습니까? (생략을 원할 시 엔터를 누르세요) \n[Y/N]\n"); // 긴급 연락처 등록 여부를 물어봄
		char buffer[2] = { 0 }; // 등록 여부를 입력받을 문자열을 지정함 
		do {
			strcpy(buffer, "\0");
			scanf("%[^\n]s", buffer);
			getchar();
		} while ( rightsize(buffer, 2) != 0 ) ; // 너무 많은 문자를 입력하면 다시 입력하라고 안내함 

		if (strcmp(buffer, "Y") == 0 || strcmp(buffer, "y") == 0) { // 지정 한다고 하면 긴급 연락처 여부 항목에 O를 입력함 
			strcpy(newRecord.sos, "O");
		}
		else if (strcmp(buffer, "N") == 0 || strcmp(buffer, "n") == 0 || strlen(buffer) == 0 ){ // 지정 안한다고 하면 - 을 입력함 
			strcpy(newRecord.sos, "-");
		}
		else {
			printf("... 올바른 값을 입력하세요."); // y 와 n을 제와한 공백 스페이스바 등 다른 값을 입력하면 다시 입력하라고 출력 
			again = 1;
		}
	} while ( again == 1);
	printf("========================================================================================================\n");
	printf("%-20s %-20s %-20s %-20s %-20s\n", "이름", "전화번호", "관계", "메일", "긴급연락처 등록 여부");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%-20s %-20s %-20s %-20s %-20s\n", newRecord.name , newRecord.num , newRecord.relation , newRecord.mail , newRecord.sos);
	printf("========================================================================================================\n");
	printf("%s\n", "... 저장 완료!"); // 저장을 다 했으면, 저장을 완료했다고 출력함 
	*lineCount = (*lineCount) + 1; // 저장을 다 했으면, 파일의 줄 수(입력받은 전화번호의 개수) 를 증가시킴 

	return newRecord; // 입력받은 구조체를 돌려줌 

}

int IsNoEnter(char* arr) { // 공백을 입력했는지 검사하는 함수 
	if ( strlen(arr) == 0 || strstr(arr, " ")) {
		printf("...  공백을 입력할 수 없습니다.\n");


		return 1;
	}
	return 0;
}

int IsNoSpaceBar(char* arr) {
	if (strstr(arr, " ")) {
		printf("... 공백을 입력할 수 없습니다.\n");


		return 1;
	}
	return 0;
}

int IsNum(char* num) {

	for (int i = 0; num[i] != '\0'; i++) { // null 문자까지 확인
		if (num[i] & 0x80) { // 한글인 경우
			printf("... 숫자로만 입력하세요.\n");
			return 1; // 오류 코드 반환
		}
		else if ( isdigit(num[i]) == 0 ) { // 숫자가 아닐 경우(영어), 특수기호일 경우 
			printf("... 숫자로만 입력하세요. \n");

			return 1; // 오류 코드 반환
		}
	}
		return 0;
}

int IsMail(char* mail) {
	if (strlen(mail) != 0) {
		for (int i = 0; mail[i] != '\0'; i++) { // null 문자까지 확인
			if (!strstr(mail, "@") || !strstr(mail, ".") ) { // 골뱅이와 점을 가지고 있지 않을 경우
				printf("... 메일 형식으로 입력하세요.\n");
				*mail = 0;
				return 1; // 오류 코드 반환
			}
			else if(mail[i] & 0x80) { // 한글인 경우
				printf("... 한글은 입력할 수 없습니다.\n");
				*mail = 0;
				return 1; // 오류 코드 반환
			}
		}
	}
	return 0;
}