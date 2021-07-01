/*
interface.c
인터페이스구현을 위한 함수만 이곳에 정의(printf()가 3번이상 호출되는 함수)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "algorithm.h"

void cal_search(user * usr)
{
	printf("검색할 항목 선택\n");
	PRINT_DASH;
	PRINT_DASH;
	printf("[1] 일정 이름으로 검색");
	printf("[2] 날짜로 검색");
	printf("[3] 돌아가기");
	PRINT_DASH;

	char choice = get_choice(2, '1', '3');

	switch (choice)
	{
	case '1': name_search(usr); break;
	case '2': date_search(usr); break;
	case '3': return;
	default: break;
	}
}

void name_search(user* usr)
{
	printf("검색할 일정 이름 입력\n");
	PRINT_DASH;
	char input[MAX_GET_STRING_SIZE];
	gets_s(input, MAX_GET_STRING_SIZE);
	schedule* ptr = usr->schedules;
	schedule* result[10] = { 0 };
	int i;

	while (1)
	{
		i = 0;
		while (1)
		{
			if (i >= 10 && ptr->next == NULL)
				break;
			else if (strstr(ptr->schedule_name, input))
				result[i++] = ptr;
		}

		system("cls");

		printf("검색결과\n");
		PRINT_DASH;

		if (result[0] == NULL)
			printf("일치하는 결과가 없습니다!");
		else
		{
			print_schedule_base();

			for (int i = 0; result[i] != NULL; i++)
				print_schedule(result[i]);
		}
		if (i == 10)
		{
			PRINT_DASH;
			printf("[1] 다음일정 검색\t[2]메인화면으로\n");
			switch (get_choice(2,'1','2'))
			{
			case '2': return;
			default:
				break;
			}
		}
		else
		{
			PRINT_DASH;
			printf("[1]메인화면으로\n");
			if (get_choice(2, '1', '1') == '1')
				return;
		}
	}
}

void print_schedule(schedule* src)
{
	char repeat[8];

	switch (src->repeat)
	{
	case 0: strcpy_s(repeat, 8, "없음"); break;
	case 1: strcpy_s(repeat, 8, "매일"); break;
	case 2: strcpy_s(repeat, 8, "매주"); break;
	case 3: strcpy_s(repeat, 8, "매월"); break;
	case 4: strcpy_s(repeat, 8, "매년"); break;

	default:
		break;
	}
	printf("%d-%d-%d\t%d\t%d\t\t%d\t\t%s\t\t%s\n", src->date[0], src->date[1], src->date[2],
		d_day(today, src->date), src->time[0], src->time[1], repeat, src->schedule_name);
}

void print_schedule_base()
{
	printf("날짜\t\tD-day\t시작시간\t종료시간\t반복여부\t일정 이름\n");
	PRINT_DASH;
}

void date_search(user* usr)
{
	int date[3];
	schedule* ptr = usr->schedules;
	schedule* result[10] = { 0 };
	int i;
	printf("검색할 일정의 날짜 입력\n");
	PRINT_DASH;
	printf("년 : ");
	scanf_s("%d", &date[0]);
	printf("월 : ");
	scanf_s("%d", &date[1]);
	printf("일 : ");
	scanf_s("%d", &date[2]);

	system("cls");

	while (1)
	{
		i = 0;
		while (1)
		{
			if (i >= 10 && ptr->next == NULL)
				break;
			else if (	ptr->date[0] == date[0] &&
						ptr->date[1] == date[1] &&
						ptr->date[2] == date[2]		)
			{
				result[i++] = ptr;
			}		
		}

		system("cls");

		printf("검색결과\n");
		PRINT_DASH;

		if (result[0] == NULL)
			printf("일치하는 결과가 없습니다!");
		else
		{
			print_schedule_base();

			for (int i = 0; result[i] != NULL; i++)
				print_schedule(result[i]);
		}
		if (i == 10)
		{
			PRINT_DASH;
			printf("[1] 다음일정 검색\t[2]메인화면으로\n");
			switch (get_choice(2, '1', '2'))
			{
			case '2': return;
			default:
				break;
			}
		}
		else
		{
			PRINT_DASH;
			printf("[1]메인화면으로\n");
			if (get_choice(2, '1', '1') == '1')
				return;
		}
	}

}