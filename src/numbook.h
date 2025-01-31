#pragma once
#define _CRT_SECURE_NO_WARNINGS // 스캔에프의 오류, 겟차 오류 무시 코드 
#include <stdio.h> // 표준입출력전처리기 
#include <string.h> // 문자열 관련 함수 처리 
#include <stdlib.h> // 문자열 관련 함수 처리 
#include <ctype.h>
#include <windows.h> // 화면 클리어에서 사용됨



struct base AddNumBook(struct base* nowbook, int * linecount); // 전화번호부 추가 함수
void PrintNumBook(struct base* nowbook, int linecount); // 전화번호부 출력 함수 
struct base * SearchNumBook(struct base* nowbook, int * linecount); // 전화번호부 검색&수정&삭제 함수 

struct base* SortName(struct base* nowbook, int linecount); // 전화번호부 정렬 함수(이름기준으로)

void  ScreenClear(void); // 메뉴가 끝날때마다 화면을 정리하는 함수 

int ReadFileLine(void); // 파일의 줄 수 (연락처의 개수) 를 읽는 함수 
void WriteOnFile(struct base* arr, int size); // 메뉴 종료를 선택할 시 , 파일에 저장시키는 함수 

int rightsize(char* arr, int size); // 입력한 문자열이 정해진 크기 안쪽인지 확인하는 함수 
int rightkey(int size); // 입력한 숫자가 정해진 메뉴 숫자 안쪽인지 확인하는 함수 
int IsNum(char* num); // 전화번호와 형식이 맞는지 확인 
int IsMail(char* mail); // 메일과 형식이 맞는지 확인 
int IsNoEnter(char* arr); // 엔터(공백) 이 입력되었는지 확인 
int IsNoSpaceBar(char* arr); // 스페이스바가 입력되었는지 확인 


int IsSameName(struct base* nowbook, char* name, int size); // 기존 연락처에 똑같은 이름이 있는지 검사 
int IsSameNum(struct base* nowbook, char* num, int size); // 기존 연락처에 똑같은 전화번호가 있는지 검사 
int IsSameMail(struct base* nowbook, char* mail, int size); // 기존 연락처에 똑같은 메일이 있는지 검사 



struct base {
	char name[40]; // 이름
	char num[12]; // 전화번호
	char relation[40]; // 관계 
	char mail[30]; // 메일
	char sos[2]; // 긴급연락처 여부 안내
};
