#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define _CRT_SECURE_NO_WARNINGS

//listdata 구조체 형성
//student.txt && gpa.txt의 data 값 불러올 장소
typedef struct Listdata {
    char name[30];
    int id;
    char phone[20];
    char province[30];
    float gpa;
} listData;

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
    listData data;
    struct ListNode* link;
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
    listNode* head;
    int length;
} linkedList;

//list의 형성
linkedList* initList() {
    linkedList* L;
    L = (linkedList*)malloc(sizeof(linkedList));
    L->head = NULL;     //    head에 아무것도 넣지 않음
    L->length = 0;      //    data가 없으므로 길이는 0
    return L;           //    list 반환
}
//list의 길이
int getLength(linkedList* L) {
	// Fill your code O
	return L->length;
}
//data 넣기
void insert(linkedList* L, listNode* pre, listData x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    if (L->head == NULL) {
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
    L->length++;
}
//새로운 node 맨 앞에 넣기
void insertFirst(linkedList* L, listData x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code //O
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;
	L->length++;
}

//새로운 node 맨 뒤에 넣기
void insertLast(linkedList* L, listData x) {
	listNode *newNode, *temp;			//	현재 지칭 node를 temp로 표현
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code // O
	newNode->data = x;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp -> link = newNode;
	}
	L -> length++;
}

//node 삭제하기
int delete(linkedList* L, listNode* p) {
	listNode *pre;		//
	if (L -> head == NULL) {
		return FALSE;
	}
	if (p == NULL) {
		return FALSE;
	}
	if (L -> head == p) {
		L -> head = p -> link;
		free(p);
	}
	else {
		pre = L -> head;
		while (pre -> link != p) {
			pre = pre -> link;
			if (pre == NULL) {
				return FALSE;
			}
		}
		pre -> link = p -> link;
		free(p);
	}
	L -> length--;
	return TRUE;
}

//특정 node 찾기
listNode* search(linkedList* L, int x) {
	listNode *temp = L -> head;		//		head값에서 시작
	while (temp != NULL) {
		if (temp->data.id == x) {		//	temp값이 찾던 x값인 경우
			return temp;
		}
		else {
			temp = temp -> link;	//	맞지 않는 경우 다음 값으로 넘어감
		}
	}
	return temp;
}

//특정 node 나타내기
void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("[%s %d %s %s %f]", p->data.name, p->data.id, p->data.phone, p->data.province, p->data.gpa);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void reverse(linkedList* L) {
	listNode *p;
	listNode *q;
	listNode *r;

	p = L->head;
	q = NULL;
	r = NULL;
	
	while(p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

int main() {
    linkedList* L;
    listNode* p;

    // 공백 리스트 생성
    L = initList();

    // 파일에서 데이터 읽어와 리스트에 삽입
    FILE* pstudent = fopen("student.txt", "r");
    FILE* pgpa = fopen("gpa.txt", "r");

    if (pstudent == NULL || pgpa == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (!feof(pstudent) && !feof(pgpa)) {
        listData data;
        fscanf(pstudent, "%d %s %s %s", &data.id, data.name, data.phone, data.province);
        fscanf(pgpa, "%f", &data.gpa);
        insertLast(L, data);
    }

    fclose(pstudent);
    fclose(pgpa);

    // 이하 코드는 동일합니다.
    // displayList, search, insertFirst, insertLast, delete, reverse 등의 함수가 호출됩니다.
    	//pstudent의 내용을 ListData struct에 넣기
	while (1) {
		char buf[500];
		char* input_id1;
		char* input_id2;
		char* input_name1;
		char* input_phone1;
		char* input_province1;
		char* input_gpa;
		int int_id;
		int int_id1;
		float float_gpa;
		listData data;

		printf("명령어를 입력하세요: ");

		//불필요한 오류가 계속 발생해서 gets_s를 fgets로 변경하였습니다. !! C99
		fgets(buf, sizeof(buf) , stdin);
		char* ptr = strtok(buf, " ");

		switch (ptr[0]) {
			case 'p':
				displayList(L);
				break;
			case 's':
				input_id1 = strtok(NULL, " ");
				int_id = atoi(input_id1);

				p = search(L, int_id);
				if (p == NULL)
					printf("찾는 데이터가 없습니다.\n");
				else {
					printf("%d 노드를 찾았습니다. 이름: %s \n", p->data.id, p->data.name);
				}
				break;
			case 'i':
				input_id1 = strtok(NULL, " ");
				int_id = atoi(input_id1);
				p = search(L, int_id);
				if (p == NULL)
					printf("찾는 데이터가 없습니다.\n");
				else {
					printf("%d 노드를 찾았습니다. 이름: %s \n", p->data.id, p->data.name);
					input_id2 = strtok(NULL, " ");
					int_id1 = atoi(input_id2);
					input_name1 = strtok(NULL, " ");
					input_phone1 = strtok(NULL, " ");
					input_province1 = strtok(NULL, " ");
					input_gpa = strtok(NULL, " ");
					float_gpa = atof(input_gpa);

					data.id = int_id1;
					strcpy(data.name, input_name1);
					strcpy(data.phone, input_phone1);
					strcpy(data.province, input_province1);
					data.gpa = float_gpa;

					insert(L, p, data);
				}
				displayList(L);
				break;
			case 'd':
				input_id1 = strtok(NULL, " ");
				int_id = atoi(input_id1);
				p = search(L, int_id);
				if (p == NULL)
					printf("찾는 데이터가 없습니다.\n");
				else {
					printf("%d 노드를 찾았습니다. 이름: %s \n", p->data.id, p->data.name);
					delete(L, p);
					printf("성공적으로 삭제하였습니다.\n");
				}
				displayList(L);
				break;

			case 'r':
					reverse(L);
					displayList(L);
					break;
			case 'g':
				printf("리스트에 저장된 데이터 개수: %d\n", L->length);
				break;
			case 'e':
				return 0;
				break;
			}
		}
	}

