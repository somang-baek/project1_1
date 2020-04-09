#include "dormitory.h"

T_Dorm* students[MAX_STUDENTS];
int _count = 0;

int m_is_available() {
	int i;
	for( i = 0; i < MAX_STUDENTS; i++) {
		if (students[i] == NULL)
#ifdef DEBUG
		printf("[Debug] 추가할 수 있는 데이터 공간이 있음. m_is_available\n");
#endif
			return 1;
	}
#ifdef DEBUG
	printf("[Debug] 추가할 수 있는 데이터 공간이 없음. m_is_available\n");
#endif
	return 0;
}

int m_first_available() {
	int i;
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (students[i] == NULL)
#ifdef DEBUG
		printf("[Debug] found first available index. m_first_available\n");
#endif
			return i;
	}
	return -1;
}

int m_count () {
#ifdef DEBUG
	printf("[Debug] m_count\n");
#endif
	return _count;
}

void m_create(char* n, char* g, char* b, int sn, char* m) {
	int index = m_first_available();
	students[index] = (T_Dorm*)malloc(sizeof(T_Dorm));
	T_Dorm* p = students[index];
	strcpy(p->name, n);
	strcpy(p->gender, g);
	strcpy(p->building, b);
	p->studentNumber = sn;
	strcpy(p->major, m);
	_count ++;

#ifdef DEBUG
	printf("[Debug] %s m_create \n", n);
#endif
}

T_Dorm* m_search_by_name(char* n) {
	int i;
	for ( i = 0; i < MAX_STUDENTS; i++) {
		if( students[i] != NULL && strcmp(students[i] -> name, n) == 0)
		return students[i];
	}
#ifdef DEBUG
	printf("[Debug] didn't find same name with %s. m_search_by_name\n", n);
#endif
	return NULL;
}

char* m_to_string(T_Dorm* p) {
	static char str[80];
	sprintf(str, "%s / %s / %s / %d학번 / %s", p->name, p->gender, p->building, p->studentNumber, p->major);
#ifdef DEBUG
	printf("[Debug] m_to_string\n");
#endif
	return str;
}

void  m_get_all(T_Dorm* a[]) {
	int i , c = 0;
	for( i = 0; i <MAX_STUDENTS; i++) {
		if(students[i] != NULL) {
			a[c] = students[i];
			c++;
#ifdef DEBUG
			printf("[Debug] m_get_all\n");
#endif
		}
	}
}

char* m_getname(T_Dorm* p) {
	return p->name;
}

char* m_getgender(T_Dorm* p) {
	return p->gender;
}

char* m_getbuilding(T_Dorm* p) {
	return p->building;
}

int m_getstudentnumber(T_Dorm* p) {
	return p->studentNumber;
}

char* m_getmajor(T_Dorm* p) {
	return p->major;
}

int m_get_all_by_name(T_Dorm* a[], char* n) {
	int i , c = 0;
	for (i = 0; i <MAX_STUDENTS; i ++) {
		if(students[i] != NULL && strstr(students[i] -> name, n)) {
			a[c] = students[i];
			c++;
		}
	}
#ifdef DEBUG
	printf("[Debug] m_get_all_by_name\n");
#endif
	return c;
}

int m_get_all_by_gender(T_Dorm* a[], char* g) {
	int i, c = 0;
	for (i = 0; i <MAX_STUDENTS; i++) {
		if(students[i] != NULL && (strcmp(students[i] -> gender, g)==0)) {
			a[c] = students[i];
			c++;
		}
	}
	return c;
}

int m_get_all_by_building(T_Dorm* a[], char* b) {
	int i, c= 0;
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (students[i] != NULL && (strcmp(students[i] -> building, b) == 0)) {
			a[c] = students[i];
			c++;
		}
	}
	return c;
}

void m_init() {
	//모든 레코드 제거
	int i;
	for (i = 0; i <MAX_STUDENTS; i++) {
		if(students[i] != NULL) {
			free(students[i]);
		}
		students[i] = NULL;
	}
	_count = 0;
#ifdef DEBUG
	printf("[Debug] all records are removed. m_init\n");
#endif
}

char* m_to_string_save(T_Dorm* p) {
	static char str[80];
	sprintf(str, "%s %s %s %d %s", p->name, p->gender, p->building, p->studentNumber, p->major);
#ifdef DEBUG
	printf("[Debug] m_to_string_save\n");
#endif
	return str;
}
