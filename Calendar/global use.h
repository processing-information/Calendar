/*
#define���� ��ó����,��������,����ü ���� ���⿡ �ۼ�
*/

#pragma once
#define MAX_GET_STRING_SIZE 20
#define USER_NAME_SIZE 15
#define PRINT_DASH printf("========================================================================================\n")

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
	schedule* prev;
};

//����� ����ü
struct B
{
	char user_name[USER_NAME_SIZE];
	user* next;
	schedule* schedules;
};