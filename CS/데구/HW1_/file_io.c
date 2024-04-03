#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Listdata {
	char name[30];
	int id;
	char phone[20];
	char province[30];
} listData;

int main() {
	FILE* pStudentFile = NULL;

	errno_t err = fopen_s(&pStudentFile, "student.txt", "r");

	if (err ==  0) {
		while (!feof(pStudentFile)) {
			listData data;

			fscanf(&pStudentFile, "%s %d %s %s", data.name, sizeof(data.name), &(data.id), data.phone, sizeof(data.phone), data.province, sizeof(data.province));
			printf("%s %d %s %s\n", data.name, data.id, data.phone, data.province);
		}

		fclose(pStudentFile);
	}
	else {
		printf("student.txt\n");
	}

	return 0;
}