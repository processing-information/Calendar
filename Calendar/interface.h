/*
interface.h
interface.c�� ���ǵ� �Լ����� ������ �ۼ�
*/
#pragma once
#include "global use.h"

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