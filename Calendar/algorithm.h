/*
algorithm.h
algorithm.c에 정의된 함수들의 선언을 작성
*/

#pragma once
#include "global use.h"


// {년,월,일}을 인자로 주면 0~6까지(일~토)의 값을 반환
int get_week(int date[3]); 

/*
호출시 지정한 문자가 나올때까지 입력을 받는 함수
인자는 (들어갈 인자의 개수 - 1,범위 시작(문자로), 범위 끝(문자로), 범위내의 숫자 외에 따로 입력받을 문자들) 이다.
예) 1부터 7의 숫자를 입력받고 그 외에 g,q,e를 받고 싶은경우
char user_choice = get_choice(5,'1','7','g','q','e'); 로 호출할수 있다.
==============================================================
주의 : 정수값 기준 양수만 반환합니다.
반환값이 -1 인경우 : 메모리 동적할당 실패
반환값이 -2 인경우 : 첫번째 인자를 잘못 전달함
*/
char get_choice(char range, ...);

//날짜 2개를 주면 디데이를 반환해주는 함수
int d_day(const int* date_1, const int* date_2);

//d_day()와 get_week()를 위한 함수
int get_day(const int* date);

//int date[3]를 인자로 받아 오늘로 바꿔줌
void set_today(int* date);