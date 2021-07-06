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
