/*
algorithm.c
�������̽��� ������ �Լ��� ���� �� ��� 
������ ���Ǵ� �Լ����� ȣ���ϴ� �Լ��� �̰��� ����
*/
#include "algorithm.h"
#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include <stdlib.h>


int get_week(int date[3])
{
	//date�� {��,��,��} �������� �Ǿ�����
	unsigned int result = 0;
	int preyear = date[0] - 1;
	int days = preyear * 365 + (preyear / 4 - preyear / 100 + preyear / 400);

	int day_table[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0) //�� 4�⸶�� 
		day_table[1] = 29;
	result = days;

	for (int i = 1; i < date[1]; i++)
	{
		result += day_table[i - 1];
	}
	result += date[2];
    
	return result % 7;
}

char get_choice(char range, ...)
{
	char input;
	va_list ap; //�������� Ž���� ���� ������
	va_start(ap, range);//ap�� 2��° ���� �ּ� �Ѱ���
	char* args = (char*)malloc(range);


	if (args == NULL)//�����Ҵ��� ������ ��츦 ���
		return -1;
	else if (range <= 1)//�����Ҵ�� ������ �Ѵ°��� ����
		return -2;

	for (int i = 0; i < range; i++)
		args[i] = va_arg(ap, char); //ap�� 1����Ʈ�� �ѱ�� args�� ����
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