/*
#define등의 전처리문,전역변수,구조체 등을 여기에 작성
*/

#pragma once
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================================================\n")

typedef struct A schedule;
typedef struct B user;

user* user_start;
int today[3]; //오늘을 저장한 변수

//일정 구조체
struct A
{
	int date[3];
	int time[2]; // {시작,종료} 예) {1530,1830} 시랑 분 입력시 한개로 합치려면 (시간*100)+분 하면 됨
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
	schedule* schedules;
};