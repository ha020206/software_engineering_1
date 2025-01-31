#include "numbook.h"

void ScreenClear( void ) {

	printf("... 아무 키나 눌러주세요.\n");  // 메뉴를 완수했을 때, 메뉴가 끝났음을 알리기 위한 화면 클리어 함수 
	getchar(); // 키를 누르게 하여 화면이 바로 지워지는것을 방지함 

	printf("작업 저장중"); // 작업 저장중이라는 안내메세지 출력 

	for (int i = 0 ; i < 3; i++) {
		printf("%c", '.');
		Sleep(800); // 0.8초씩 3번 점을 출력하여 화면이 바로 지워지는것을 방지함 
	}		

	system("cls"); // 화면을 깨끗하게 지우는 함수 
}