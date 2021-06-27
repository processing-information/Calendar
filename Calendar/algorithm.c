#include "algorithm.h"

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

int str_search(const char* src, const char* value)
{
}