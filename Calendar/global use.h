/*
#define���� ��ó����,��������,����ü ���� ���⿡ �ۼ�
*/

#pragma once
#define DATAMAX	10
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================================================\n")
#define MAXDATE 150 //add_cal struct ���
#define MAXNAME 100 //add_cal struct ���

typedef struct A schedule;
typedef struct B user;

user* user_start;
int today[3]; //������ ������ ����

//���� ����ü
struct A
{
	int date[3];
	int time[2]; // {����,����} ��) {1530,1830} �ö� �� �Է½� �Ѱ��� ��ġ���� (�ð�*100)+�� �ϸ� ��
	char schedule_name[MAX_GET_STRING_SIZE];
	int repeat;
	schedule* next;
};

//����� ����ü
struct B
{
	char user_name[USER_NAME_SIZE];
	user* next;
	schedule* schedules;
};

//user->next�� ���� user ����ü�� ����Ű�� ������ ��
//����ü ���鋚 malloc(sizeof(user))�� �����

typedef struct// cal_add ����ü 
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