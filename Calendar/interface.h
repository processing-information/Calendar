/*
interface.h
interface.c�� ���ǵ� �Լ����� ������ �ۼ�
*/
#pragma once
#include "global use.h"



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

void print_schedule_nl(schedule* src);