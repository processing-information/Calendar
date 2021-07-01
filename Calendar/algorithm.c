/*
algorithm.c
인터페이스를 제외한 함수들 구현 각 장면 
구현에 사용되는 함수들이 호출하는 함수를 이곳에 정의
*/
#include "algorithm.h"
#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int get_week(int date[3])
{
	return get_day(date) % 7;
}

char get_choice(char range, ...)
{
	char input;
	va_list ap; //가변인자 탐색을 위한 포인터
	va_start(ap, range);//ap에 2번째 인자 주소 넘겨줌
	char* args = (char*)malloc(range);


	if (args == NULL)//동적할당이 실패할 경우를 대비
		return -1;
	else if (range <= 1)//동적할당된 범위를 넘는것을 방지
		return -2;

	for (int i = 0; i < range; i++)
		args[i] = va_arg(ap, char); //ap를 1바이트씩 넘기며 args에 저장
	va_end(ap);

	while (1)
	{
		input = _getch();
		if (args[0] <= input && input <= args[1])
		{
			free(args);
			return input;
		}
		for (int i = 2; i < range; i++)
		{
			if (input == args[i])
			{
				free(args);
				return input;
			}
		}
	}
}

int d_day(const int *date_1, const int *date_2)
{
	int result = get_day(date_1) - get_day(date_2);
	if (result<0)
		return ~result + 1;
	else
		return result;
}

int get_day(const int *date)
{
	//date는 {년,월,일} 형식으로 되어있음
	unsigned int result = 0;
	int preyear = date[0] - 1;
	int days = preyear * 365 + (preyear / 4 - preyear / 100 + preyear / 400);

	int day_table[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0) //매 4년마다 
		day_table[1] = 29;
	result = days;

	for (int i = 1; i < date[1]; i++)
	{
		result += day_table[i - 1];
	}
	result += date[2];

	return result;
}

void set_today(int* date)
{
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	date[0] = tm.tm_year + 1900;
	date[1] = tm.tm_mon + 1;
	date[2] = tm.tm_mday;
}