#include <stdio.h>
typedef struct Listdata {
	char name[30];
	int id;
	char phone[20];
	char province[30];
	float gpa;
} listData;

int main() {
    FILE *pstudent = fopen("student.txt" , "r");
    while (!feof(pstudent)) {
        listData data;
        fscanf(pstudent , "%s %d %s %s" , data.name , &data.id , data.phone , data.province);
        printf("%s %d %s %s" , data.name , data.id , data.phone , data.province);
    }
    
}