/*
#define등의 전처리문,전역변수,구조체 등을 여기에 작성
*/

#pragma once
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================")

typedef struct A schedule;
typedef struct B user;

char temp_string[MAX_GET_STRING_SIZE];
user* user_start;


//일정 구조체
struct A
{
	int date[3];
	int time[2][2];
	char schedule_name[MAX_GET_STRING_SIZE];
	int repeat;
	schedule* next;
	schedule* prev;
};

//사용자 구조체
struct B
{
	char user_name[USER_NAME_SIZE];
	user* next;
	user* prev;
	schedule* schedules;
};