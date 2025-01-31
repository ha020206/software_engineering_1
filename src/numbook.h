#pragma once
#define _CRT_SECURE_NO_WARNINGS // ��ĵ������ ����, ���� ���� ���� �ڵ� 
#include <stdio.h> // ǥ���������ó���� 
#include <string.h> // ���ڿ� ���� �Լ� ó�� 
#include <stdlib.h> // ���ڿ� ���� �Լ� ó�� 
#include <ctype.h>
#include <windows.h> // ȭ�� Ŭ����� ����



struct base AddNumBook(struct base* nowbook, int * linecount); // ��ȭ��ȣ�� �߰� �Լ�
void PrintNumBook(struct base* nowbook, int linecount); // ��ȭ��ȣ�� ��� �Լ� 
struct base * SearchNumBook(struct base* nowbook, int * linecount); // ��ȭ��ȣ�� �˻�&����&���� �Լ� 

struct base* SortName(struct base* nowbook, int linecount); // ��ȭ��ȣ�� ���� �Լ�(�̸���������)

void  ScreenClear(void); // �޴��� ���������� ȭ���� �����ϴ� �Լ� 

int ReadFileLine(void); // ������ �� �� (����ó�� ����) �� �д� �Լ� 
void WriteOnFile(struct base* arr, int size); // �޴� ���Ḧ ������ �� , ���Ͽ� �����Ű�� �Լ� 

int rightsize(char* arr, int size); // �Է��� ���ڿ��� ������ ũ�� �������� Ȯ���ϴ� �Լ� 
int rightkey(int size); // �Է��� ���ڰ� ������ �޴� ���� �������� Ȯ���ϴ� �Լ� 
int IsNum(char* num); // ��ȭ��ȣ�� ������ �´��� Ȯ�� 
int IsMail(char* mail); // ���ϰ� ������ �´��� Ȯ�� 
int IsNoEnter(char* arr); // ����(����) �� �ԷµǾ����� Ȯ�� 
int IsNoSpaceBar(char* arr); // �����̽��ٰ� �ԷµǾ����� Ȯ�� 


int IsSameName(struct base* nowbook, char* name, int size); // ���� ����ó�� �Ȱ��� �̸��� �ִ��� �˻� 
int IsSameNum(struct base* nowbook, char* num, int size); // ���� ����ó�� �Ȱ��� ��ȭ��ȣ�� �ִ��� �˻� 
int IsSameMail(struct base* nowbook, char* mail, int size); // ���� ����ó�� �Ȱ��� ������ �ִ��� �˻� 



struct base {
	char name[40]; // �̸�
	char num[12]; // ��ȭ��ȣ
	char relation[40]; // ���� 
	char mail[30]; // ����
	char sos[2]; // ��޿���ó ���� �ȳ�
};
