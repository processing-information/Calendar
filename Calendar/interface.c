/*
interface.c
인터페이스구현을 위한 함수만 이곳에 정의(printf()가 3번이상 호출되는 함수)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "algorithm.h"

void cal_main(void)
{
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	int year = tm.tm_year + 1900;
	int mon = tm.tm_mon + 1;
	int day = tm.tm_mday;
	int date[3] = { year, mon, 1 };

	printf("\t\t오늘 : %d년 %d월 %d일\n\n", year, mon, day);
	printf("%d년 %d월===========================================\n", year, mon);
	print_cal(date);
	printf("\n=====================================================");
	
	while (1)
	{
		printf("\n\n1. 사용자 선택\t2. 일정 추가\t3. 일정 수정\t4. 일정 검색\n\n5. 일정 삭제\tp. 사용자 관리\tx. 종료\n");
		char choice = get_choice(4, '1', '5', 'p', 'x');

		switch (choice)
		{
		case '1':
			system("cls");
			//user_choice();
			printf("user_choice()");
			break;
		case '2':
			system("cls");
			//cal_add();
			printf("cal_add()");
			break;
		case '3':
			system("cls");
			//cal_edit();
			printf("cal_edit()");
			break;
		case '4':
			system("cls");
			//cal_search();
			printf("cal_search()");
			break;
		case '5':
			system("cls");
			//cal_del();
			printf("cal_del()");
			break;
		case 'p':
			system("cls");
			//사용자 추가 삭제 ......
			printf("사용자 추가 삭제()");
			break;
		case 'x':
			system("cls");
			printf("프로그램을 종료합니다.");
			exit(0);
		}
	}
}

void print_cal(int date[3])
{
	printf("일\t월\t화\t수\t목\t금\t토\n");
	printf("=====================================================\n");
	int start = get_week(date);

	int mon = date[1];

	int day_table[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0)
		day_table[1] = 29;

	for (int i = 0; i < start; i++)
	{
		printf("\t");
	}
	for (int i = 1; i <= day_table[mon - 1]; i++)
	{
		if (start % 7 == 0)
			printf("\n");
		printf("%d\t", i);
		start++;
	}
}

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
#include "interface.h"
#include "algorithm.h"



	struct user {
		int year;
		int month;
		int day;
		char *name[10];
	};

	int user_menu()
	{
		struct user u;
	printf("년도 입력: ");
	printf("월 입력: ");
	printf("일 입력: ");
	printf("이름 입력: ");
	
	

	scanf_s("%d\n", &u.year);
	scanf_s("%d\n", &u.month);
	scanf_s("%d\n", &u.day);
	scanf_s("%d\n", &u.name);


	
}





void del_user()
{

}
