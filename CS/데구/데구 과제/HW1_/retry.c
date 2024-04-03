#include <stdio.h>

typedef struct Listdata {
	char name[30];
	int id;
	char phone[20];
	char province[30];
	float gpa;
} listData;

int main() {
	listData data;
	FILE *pstudent = fopen("student.txt" , "r");
	FILE *pgpa = fopen("gpa.txt" , "r");

	while (!feof(pgpa)) {
		fscanf(pstudent , "%f" , &data.gpa);
		printf("%f" , data.gpa);
	}
}
