/*	=================================================================
*	HW3: Binary Search Tree
*	Filename: hw3.c
*	Creator: Han-Jin Lee
*	Created: 04/11/2024
*	Purpose: main function for DS_HW3
*	===============================================================*/


/* 헤더파일 포함 */
#include "preImplemented.h"
#include "implementation.h"


/* main 함수 */
void main() {
	// 0. 트리 선언 및 초기화
	BST Tree;
	initTree(&Tree);

	// 1. 파일로부터 트리 구성
	char filename[100];
	printf("트리 데이터 파일 이름 입력 : ");
	gets(filename);
	if (!construct_tree_from_file(&Tree, filename)) {
		printf("파일 열기 실패\n");
		exit(1);
	}

	// 2. 명령어 처리
	char input[100], command[100];
	char* token;

	SearchResult result;
	
	while (true) {
		printf(">>> ");
		gets(input);
		// 2-0. 입력 문자열을 토큰으로 분리
		token = strtok(input, " ");
		strcpy(command, token);
		// 2-1. 명령어 종류에 따른 처리
		if (strcmp(command, "search") == 0) {				// 2-1-1. search 명령어
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("이름 입력이 필요합니다.\n");
				continue;
			}
			result = search_node(&Tree, token);
			
			if (result.found)
				printf("이름: %s, 학번: %d, 레벨: %02d\n", result.search_node->std_name, result.search_node->std_num, result.level);
			else
				printf("찾을 수 없습니다.\n");

		}
		else if (strcmp(command, "insert") == 0) {			// 2-1-2. insert 명령어
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("이름 입력이 필요합니다.\n");
				continue;
			}
			char std_name[50];
			strcpy(std_name, token);

			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("학번 입력이 필요합니다.\n");
				continue;
			}
			int std_num = atoi(token);

			if (insert_node(&Tree, std_name, std_num))
				printf("삽입 성공\n");
			else
				printf("이미 존재하는 이름입니다.\n");
		}
		else if (strcmp(command, "delete") == 0) {			// 2-1-3. delete 명령어
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("이름 입력이 필요합니다.\n");
				continue;
			}
			if (delete_node(&Tree, token)) printf("삭제 성공\n");
			else printf("삭제 실패\n");
		}
		else if (strcmp(command, "treeinfo") == 0) {		// 2-1-4. treeinfo 명령어
			printf("트리의 높이: %d\n", get_height(Tree.root));
			printf("트리의 노드 개수: %d\n", Tree.count);
			printf("리프 노드 개수: %d\n", leafcount(Tree.root));
		}
		else if (strcmp(command, "preorder") == 0) {		// 2-1-5. preorder 명령어
			printf("Preorder 탐색 시작\n");
			preorder(Tree.root);
			printf("Preorder 탐색 종료\n");
		}
		else if (strcmp(command, "postorder") == 0) {		// 2-1-6. postorder 명령어
			printf("Postorder 탐색 시작\n");
			postorder(Tree.root);
			printf("Postorder 탐색 종료\n");
		}
		else if (strcmp(command, "print") == 0) {			// 2-1-7. print 명령어
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("오름차순/내림차순 입력이 필요합니다.\n");
				continue;
			}
			else if (strcmp(token, "asc") == 0) {
				printf("출력 시작\n");
				inorder(Tree.root);
				printf("출력 종료\n");
			}
			else if (strcmp(token, "desc") == 0) {
				printf("출력 시작\n");
				inorder_reverse(Tree.root);
				printf("출력 종료\n");
			}
			else {
				printf("잘못된 명령어\n");
				continue;
			}
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else printf("잘못된 명령어\n");
	}
}