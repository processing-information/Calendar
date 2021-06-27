#pragma once
#include "preprocess.h"
#include <stdio.h>

char temp_string[MAX_STRING_SIZE];

int get_week(int date[3]);
char get_choice();
const char* get_string();
int str_seatch(const char* src, const char* value);