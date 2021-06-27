#pragma once
#include "preprocess.h"
#include <stdio.h>

char temp_string[MAX_STRING_SIZE];

int get_week(int date[3]); // {년,월,일}을 인자로 주면 0~6까지(일~토)의 값을 반환
char get_choice();
const char* get_string();
int str_seatch(const char* src, const char* value);