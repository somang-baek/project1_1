#include "dormitory.h"
// #define DEBUG

// 애플리케이션용 함수 원형
void create_record();
void read_record();
void list_record();
void search_name();
void search_gender();
void search_building();
void load_file();
void save_file();

int main() {
	int menu;
	while(1) {
		printf("\nMenu : 1.Create 2.Read 3. Update 4.Delete 5.List 6.Search(name) 7.Search(gender) 8. Search(building) 9. Load 10. Save 0. Quit > ");
		scanf("%d", &menu);
		printf("\n");
		switch(menu) {
			case 1:
				create_record();
				break;
			case 2:
				read_record();
				break;
			case 5:
				list_record();
				break;
			case 6:
				search_name();
				break;
			case 7:
				search_gender();
				break;
			case 8:
				search_building();
				break;
			case 9:
				load_file();
				break;
			case 10:
				save_file();
				break;
			case 0:
			default:
				return 0;
		}
	}
	return 0;
}

void create_record() {
	if(!m_is_available()) {
		printf("There is no space!\n");
		return;
	}
	char name[20], gender[20], building[20], major[20];
	int studentnumber;
	printf("Enter a new student's info.\n");
	printf("Name > ");
	scanf("%s", name);
	if(m_search_by_name(name)) {
		printf("Duplicated name!\n");
		return;
	}
	printf("Gender(남 or 여) > ");
	scanf("%s", gender);
	printf("Building(OO관) > ");
	scanf("%s", building);
	printf("Student Number(ex. 17, 18, 19) > ");
	scanf("%d", &studentnumber);
	printf("Major > ");
	scanf("%s", major);
	m_create(name, gender, building, studentnumber, major);
}

void read_record() {
	char name[20];
	printf("Enter a name > ");
	scanf("%s", name);

	T_Dorm* p = m_search_by_name(name);
	if(p) {
		printf("Student info.\n");
		printf("Name : %s\n", m_getname(p));
		printf("Gender: %s\n", m_getgender(p));
		printf("Dormitory Building : %s\n", m_getbuilding(p));
		printf("Student Number : %d\n", m_getstudentnumber(p));
		printf("Major : %s\n", m_getmajor(p));
	}
	else {
		printf("No such student!\n");
	}
}

void list_record() {
	printf("All records.\n");
	int size = m_count();
	T_Dorm* students[MAX_STUDENTS];
	m_get_all(students);
	for (int i = 0; i < size; i++) {
		T_Dorm* p = students[i];
		printf("%d. %s\n", i+1, m_to_string(p));
	}
}

void search_name() {
	char name[20];
	printf("Enter a name > ");
	scanf("%s", name);

	T_Dorm* students[MAX_STUDENTS];
	int size = m_get_all_by_name(students, name);
	printf("%d records found.\n", size);
	for(int i = 0; i < size; i++) {
		T_Dorm* p = students[i];
		printf("%d. %s\n", i + 1, m_to_string(p));
	}
}

void search_gender() {
	char gender[20];
	printf("Enter gender (남 or 여) > ");
	scanf("%s", gender);

	T_Dorm* students[MAX_STUDENTS];
	int size = m_get_all_by_gender(students, gender);
	printf("%d records found.\n", size);
	for (int i = 0; i < size; i++) {
		T_Dorm* p = students[i];
		printf("%d. %s\n", i + 1, m_to_string(p));
	}
}

void search_building() {
	char building[20];
	printf("Enter a dormitory building(OO관) > ");
	scanf("%s", building);

	T_Dorm* students[MAX_STUDENTS];
	int size = m_get_all_by_building(students, building);
	printf("%d records found.\n", size);
	for ( int i = 0; i < size; i++) {
		T_Dorm* p = students[i];
		printf("%d. %s\n", i + 1, m_to_string(p));
	}
}
	

void load_file() {
	// 데이터 파일 읽기
	printf("All data will be deleted and new records will be reloaded.\n");
	printf("1.Yes 0.No > ");
	int yesno;
	scanf("%d", &yesno);
	if (yesno == 0)	return;
	m_init();	// 레코드 모두 제거
	
	FILE* f = fopen("dormitory.txt", "r");
	char name[20], gender[20], building[20], major[20];
	int studentnumber;
	while(!feof(f)) {
		if(!m_is_available()) {
			printf("[Load] There is no space!\n");
			break;
		}
		int n = fscanf(f, "%s %s %s %d %s", name, gender, building, &studentnumber, major);
		if (n < 5) break;
		if (m_search_by_name(name)) {
			printf("[Load] Duplicated name(%s)! loading.\n", name);
			continue;
		}
		m_create(name, gender, building, studentnumber, major);
	}
	printf("%d records are read from file!\n", m_count());
	fclose(f);
}

void save_file() {
	// 데이터파일 저장
	FILE* f = fopen("dormitory.txt", "w");
	printf("All records.\n");
	int size = m_count();
	T_Dorm* students[MAX_STUDENTS];
	m_get_all(students);
	for (int i = 0; i < size; i++) {
		T_Dorm* p = students[i];
		fprintf(f, "%s\n", m_to_string_save(p));
	}
	fclose(f);
}
