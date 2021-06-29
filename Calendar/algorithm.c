/*
algorithm.c
인터페이스를 제외한 함수들 구현 각 장면 
구현에 사용되는 함수들이 호출하는 함수를 이곳에 정의
*/
#include "algorithm.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

int get_week(int date[3])
{
	unsigned int result = 0;
	int preyear = date[0] - 1;
	int days = preyear * 365 + (preyear / 4 - preyear / 100 + preyear / 400);

	int day_table[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0)
		day_table[1] = 29;
	result = days;

	for (int i = 1; i < date[1]; i++)
	{
		result += day_table[i - 1];
	}
	result += date[2];
    
	return result % 7;
}

char get_single()
{
	char input = _getch();
	if (input >= 'A' && input <= 'Z')
		input += 20; //대문자를 소문자로 변환
	return input;
}

void get_string(char* print_string)
{
	printf("%s", print_string);
	gets_s(temp_string, MAX_STRING_SIZE); //전역변수 temp_string에 문자열 저장
}

int en_search(const char* src, const char* value)
{
	int same_size;
	const int value_size = strlen(value);
	const int source_size = strlen(src);

	for (int i = 0; i < source_size - value_size + 1; i++)
	{
		same_size = 0;
		for (int j = 0; j < value_size; j++)
		{
			if (src[i + j] == value[j])
			{
				same_size++;
			}
			if (same_size == value_size)
				return 1;
		}
	}
	return 0;
}

int kr_search(const char* src, const char* value)
{
	int same_size;
	const int value_size = strlen(value);
	const int source_size = strlen(src);

	for (int i = 0; i < source_size - value_size + 1; i += 2)
	{
		same_size = 0;
		for (int j = 0; j < value_size; j += 2)
		{
			if (src[i + j] == value[j] && src[i + j + 1] == value[j + 1])
			{
				same_size += 2;
			}
			if (same_size == value_size)
				return 1;
		}
	}
	return 0;
}