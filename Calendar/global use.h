/*
#define���� ��ó����,��������,����ü ���� ���⿡ �ۼ�
*/

#pragma once
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================")

typedef struct A schedule;
typedef struct B user;

char temp_string[MAX_GET_STRING_SIZE];
user* user_start;


//���� ����ü
struct A
{
	int date[3];
	int time[2][2];
	char schedule_name[MAX_GET_STRING_SIZE];
	int repeat;
	schedule* next;
	schedule* prev;
};

//����� ����ü
struct B
{
	char user_name[USER_NAME_SIZE];
	user* next;
	user* prev;
	schedule* schedules;
};