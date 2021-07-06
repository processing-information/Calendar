/*
interface.c
�������̽������� ���� �Լ��� �̰��� ����(printf()�� 3���̻� ȣ��Ǵ� �Լ�)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "algorithm.h"
#define TEMP_CR_USR 100

void cal_main(user * usr)
{
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	int year = tm.tm_year + 1900;
	int mon = tm.tm_mon + 1;
	int day = tm.tm_mday;
	int date[3] = { year, mon, 1 };

	
	
	while (1)
	{
		printf("\t\t���� : %d�� %d�� %d��\n\n", year, mon, day);
		printf("%d�� %d��===========================================\n", year, mon);
		print_cal(date);
		printf("\n=====================================================");
		printf("\n\n1. ����� ����\t2. ���� �߰�\t3. ���� ����\t4. ���� �˻�\n\n5. ���� ����\tp. ����� ����\tx. ����\n");
		char choice = get_choice(4, '1', '5', 'p', 'x');
		system("cls");
		switch (choice)
		{
		case '1':
			
			//user_choice();
			printf("user_choice()");
			break;
		case '2':
			//cal_add();
			printf("cal_add()");
			break;
		case '3':
			//cal_edit();
			printf("cal_edit()");
			break;
		case '4':
			cal_search(usr);
			break;
		case '5':
			//cal_del();
			printf("cal_del()");
			break;
		case 'p':
			//����� �߰� ���� ......
			printf("����� �߰� ����()");
			break;
		case 'x':
			printf("���α׷��� �����մϴ�.");
			return;
		}

		system("cls");
	}
}

void print_cal(int date[3])
{
	printf("��\t��\tȭ\t��\t��\t��\t��\n");
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
	printf("�˻��� �׸� ����\n");
	PRINT_DASH;
	PRINT_DASH;
	printf("[1] ���� �̸����� �˻�\n");
	printf("[2] ��¥�� �˻�\n");
	printf("[3] ���ư���\n");
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
	printf("�˻��� ���� �̸� �Է�\n");
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
			if (!(ptr == NULL) && strstr(ptr->schedule_name, input))
			{
				result[i++] = ptr;
				ptr = ptr->next;
				if (i >= 10 || ptr == NULL)
					break;
			}
		}

		system("cls");

		printf("�˻����\n");
		PRINT_DASH;

		if (result[0] == NULL)
			printf("��ġ�ϴ� ����� �����ϴ�!");
		else
		{
			print_schedule_base();

			for (int i = 0; result[i] != NULL; i++)
				print_schedule(result[i]);
		}
		if (i == 10)
		{
			PRINT_DASH;
			printf("[1] �������� �˻�\t[2]����ȭ������\n");
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
			printf("[1]����ȭ������\n");
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
	case 0: strcpy_s(repeat, 8, "����"); break;
	case 1: strcpy_s(repeat, 8, "����"); break;
	case 2: strcpy_s(repeat, 8, "����"); break;
	case 3: strcpy_s(repeat, 8, "�ſ�"); break;
	case 4: strcpy_s(repeat, 8, "�ų�"); break;

	default:
		break;
	}
	printf("%d-%d-%d\t%d\t%d\t\t%d\t\t%s\t\t%s\n", src->date[0], src->date[1], src->date[2],
		d_day(today, src->date), src->time[0], src->time[1], repeat, src->schedule_name);
}

void print_schedule_base()
{
	printf("��¥\t\tD-day\t���۽ð�\t����ð�\t�ݺ�����\t���� �̸�\n");
	PRINT_DASH;
}

void date_search(user* usr)
{
	int date[3];
	schedule* ptr = usr->schedules;
	schedule* result[10] = { 0 };
	int i;
	printf("�˻��� ������ ��¥ �Է�\n");
	PRINT_DASH;
	printf("�� : ");
	scanf_s("%d", &date[0]);
	printf("�� : ");
	scanf_s("%d", &date[1]);
	printf("�� : ");
	scanf_s("%d", &date[2]);

	system("cls");

	while (1)
	{
		i = 0;
		while (1)
		{
			if (	!(ptr == NULL) && 
					ptr->date[0] == date[0] &&
					ptr->date[1] == date[1] &&
					ptr->date[2] == date[2]		)
			{
				result[i++] = ptr;
				ptr = ptr->next;
				if (i >= 10 || ptr == NULL)
					break;
			}	
		}

		system("cls");

		printf("�˻����\n");
		PRINT_DASH;

		if (result[0] == NULL)
			printf("��ġ�ϴ� ����� �����ϴ�!");
		else
		{
			print_schedule_base();

			for (int i = 0; result[i] != NULL; i++)
				print_schedule(result[i]);
		}
		if (i == 10)
		{
			PRINT_DASH;
			printf("[1] �������� �˻�\t[2]����ȭ������\n");
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
			printf("[1]����ȭ������\n");
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
printf("�⵵ �Է�: ");
printf("�� �Է�: ");
printf("�� �Է�: ");
printf("�̸� �Է�: ");
	
	

scanf_s("%d\n", &u.year);
scanf_s("%d\n", &u.month);
scanf_s("%d\n", &u.day);
scanf_s("%d\n", &u.name);


	
}





void del_user()
{

}