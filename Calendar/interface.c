/*
interface.c
인터페이스구현을 위한 함수만 이곳에 정의(printf()가 3번이상 호출되는 함수)
*/

#include <stdio.h>
#include <string.h>
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

	/*switch (choice)
	{
	case '1': name_search(usr); break
	case '2': date_seatch(); break;
	case '3': return;
	default: break;
	}*/
}