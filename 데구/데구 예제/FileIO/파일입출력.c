//파일 입출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct Listdata {
	char name[30];
	int id;
	char phone[20];
	char province[30];
	float gpa;
} listData;

int main(void) {
    FILE *pgpa = fopen("gpa.txt" , "r");
    FILE* pStudentFile = fopen("student.txt", "r");
    /*
    if (pgpa == NULL) {
        printf("해당 파일을 찾을 수 없습니다.\n");
        return -1;
    }
    else {
        printf("파일이 정상적으로 입력되었습니다.");
    }
*/
    while (!feof(pgpa))
    {
        listData data;
        fscanf(pgpa , "%f" , &data.gpa);
        printf("%.2f" , data.gpa);
        printf(" ");
    }return 0;
    
    /*
    FILE *pstudent = NULL;
    errno_t err = fopen_s(&pStudentFile, "student.txt", "r");
    if (err == 0) {
        while (!feof(pstudent)) {
            listData data;
            fscanf_s(pstudent , "%s %d %s %s" , data.name , sizeof(data.name) , &(data.id) , data.phone , sizeof(data.phone) , data.province , sizeof(data.province));
            printf("%s %d %s %s\n", data.name, data.id, data.phone, data.province);
        }
    }*/
}