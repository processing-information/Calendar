/*
algorithm.h
algorithm.c�� ���ǵ� �Լ����� ������ �ۼ�
*/

#pragma once
#include "preprocess.h"


char temp_string[MAX_STRING_SIZE];


// {��,��,��}�� ���ڷ� �ָ� 0~6����(��~��)�� ���� ��ȯ
int get_week(int date[3]); 

// �������� temp_string�� ���ڸ� ����
void get_string(char * print_string); 

//getch()�� ���� ���ڸ� ����, ���� ���ڰ� ���ĺ��̸� �ҹ��� ���ĺ����� ��ȯ��
char get_single();

//src ���ڿ��� value�� ���ԵǾ� �ִ��� �˻��� ���ԵǾ� ������ 1 ���ԵǾ� ���� ������ 0�� ��ȯ(��������)
int en_search(const char* src, const char* value);


int kr_search(const char* src, const char* value);