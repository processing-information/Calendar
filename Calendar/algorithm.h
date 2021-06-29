/*
algorithm.h
algorithm.c에 정의된 함수들의 선언을 작성
*/

#pragma once
#include "preprocess.h"


char temp_string[MAX_STRING_SIZE];


// {년,월,일}을 인자로 주면 0~6까지(일~토)의 값을 반환
int get_week(int date[3]); 

// 전역변수 temp_string에 문자를 저장
void get_string(char * print_string); 

//getch()를 통해 문자를 받음, 받은 문자가 알파벳이면 소문자 알파벳으로 반환함
char get_single();

//src 문자열중 value가 포함되어 있는지 검색후 포함되어 있으면 1 포함되어 있지 않으면 0을 반환(영어전용)
int en_search(const char* src, const char* value);


int kr_search(const char* src, const char* value);