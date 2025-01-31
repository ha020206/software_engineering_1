#include "numbook.h"

struct base * SortName(struct base * nowBook , int lineCount) {
	struct base buffer = { 0 };
	for (int i = 0; i < lineCount; i++) {
		for (int j = 0; j < i; j++){
			if ( strcmp(nowBook[i].name , nowBook[j].name) < 0 ) {    // ���������� �̸� ���ڿ��� �˻��ϴ� strcmp �Լ� �̿� , ���࿡ ���� ������ �������� �ƴϴ�
				strcpy(buffer.name, nowBook[i].name);
				strcpy(buffer.num, nowBook[i].num);
				strcpy(buffer.relation, nowBook[i].relation);
				strcpy(buffer.mail, nowBook[i].mail);
				strcpy(buffer.sos, nowBook[i].sos);

				strcpy(nowBook[i].name, nowBook[j].name);
				strcpy(nowBook[i].num, nowBook[j].num);
				strcpy(nowBook[i].relation, nowBook[j].relation);
				strcpy(nowBook[i].mail, nowBook[j].mail);
				strcpy(nowBook[i].sos, nowBook[j].sos);

				strcpy(nowBook[j].name, buffer.name);
				strcpy(nowBook[j].num, buffer.num);
				strcpy(nowBook[j].relation, buffer.relation);
				strcpy(nowBook[j].mail, buffer.mail);
				strcpy(nowBook[j].sos, buffer.sos);
				buffer = { 0 };
			}
		}
	}
	return nowBook;

}

