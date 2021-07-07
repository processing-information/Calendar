/*
#define등의 전처리문,전역변수,구조체 등을 여기에 작성
*/

#pragma once
#define DATAMAX	10
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================================================\n")
#define MAXDATE 150 //add_cal struct 사용
#define MAXNAME 100 //add_cal struct 사용

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
};

//사용자 구조체
struct B
{
	char user_name[USER_NAME_SIZE];
	user* next;
	schedule* schedules;
};

//user->next가 다음 user 구조체를 가르키고 있으면 되
//구조체 만들떄 malloc(sizeof(user))로 만들고

typedef struct// cal_add 구조체 
{
	int addy;
	int addm;
	int addd;
	int firsttime;
	int lasttime;
	char cal_date[MAXDATE];
	char cal_name[MAXNAME];
	char repeat[3];
}g_add;