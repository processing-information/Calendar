/*
interface.h
interface.c�� ���ǵ� �Լ����� ������ �ۼ�
*/
#pragma once
#include "global use.h"

typedef struct
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

#define MAXDATE 150
#define MAXNAME 100


void cal_addrepeat();

void everyday();

void monthly();
void everyyear();
void cal_add();

int user_menu();

void del_user();

//����ȭ�鿡�� ���� �˻��ϸ� ���� �Լ�
void cal_search(user* usr);

//�̸����� �����˻�
void name_search(user* usr);

//��¥�� �����˻�
void date_search(user* usr);

//�ش� �������� ������ִ� �Լ�
void print_schedule(schedule* src);

//print_schedule�� ȣ������ ȭ�� ��ܿ� ���̺��� ����� �ִ� �Լ�
void print_schedule_base();

//����ȭ�� ��� �Լ�
void cal_main();

//�޷� ��� �Լ�
void print_cal(date);

void cal_del(user* usr);

void cal_edit(user* usr);