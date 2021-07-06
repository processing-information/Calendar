/*
interface.h
interface.c에 정의된 함수들의 선언을 작성
*/
#pragma once
#include "global use.h"



int user_menu();

void del_user();

//메인화면에서 일정 검색하면 오는 함수
void cal_search(user* usr);

//이름으로 일정검색
void name_search(user* usr);

//날짜로 일정검색
void date_search(user* usr);

//해당 스케줄을 출력해주는 함수
void print_schedule(schedule* src);

//print_schedule을 호출전에 화면 상단에 레이블을 만들어 주는 함수
void print_schedule_base();

//메인화면 출력 함수
void cal_main();

//달력 출력 함수
void print_cal(date);

void cal_del(user* usr);

void cal_edit(user* usr);

void print_schedule_nl(schedule* src);