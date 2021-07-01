/*
interface.c
�������̽������� ���� �Լ��� �̰��� ����(printf()�� 3���̻� ȣ��Ǵ� �Լ�)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "algorithm.h"

void cal_search(user * usr)
{
	printf("�˻��� �׸� ����\n");
	PRINT_DASH;
	PRINT_DASH;
	printf("[1] ���� �̸����� �˻�");
	printf("[2] ��¥�� �˻�");
	printf("[3] ���ư���");
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
			if (i >= 10 && ptr->next == NULL)
				break;
			else if (strstr(ptr->schedule_name, input))
				result[i++] = ptr;
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