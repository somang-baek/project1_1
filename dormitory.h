#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef struct st_dorm{
	char name[20];
	char gender[20];
	char building[20];
	int studentNumber;
	char major[20];
} T_Dorm;

int m_is_available();
int m_first_available();
int m_count();

void m_create(char* n, char* g, char* b, int sn, char* m);
T_Dorm* m_search_by_name(char* n);


void m_get_all(T_Dorm* a[]); // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기

char* m_to_string(T_Dorm* p);

char* m_getname(T_Dorm* p);
char* m_getgender(T_Dorm* p);
char* m_getbuilding(T_Dorm* p);
int m_getstudentnumber(T_Dorm* p);
char* m_getmajor(T_Dorm* p);

int m_get_all_by_name(T_Dorm* a[], char* n);
int m_get_all_by_gender(T_Dorm* a[], char* g);
int m_get_all_by_building(T_Dorm* a[], char* b);

void m_init();	// 모든 레코드 제거
char* m_to_string_save(T_Dorm* p);	// 특정 회원 레코드의 내용을 파일저장용 문자열로 가져오기
