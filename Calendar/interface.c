/*
interface.c
�������̽������� ���� �Լ��� �̰��� ����(printf()�� 3���̻� ȣ��Ǵ� �Լ�)
*/

#include <stdio.h>
#include <string.h>
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

	/*switch (choice)
	{
	case '1': name_search(usr); break
	case '2': date_seatch(); break;
	case '3': return;
	default: break;
	}*/
}