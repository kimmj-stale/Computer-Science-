/*	=================================================================
*	HW3: Binary Search Tree
*	Filename: preImplemented.h
*	Creator: Han-Jin Lee
*	Created: 04/11/2024
*	Purpose: pre-implemented header file for DS_HW3
*	===============================================================*/


#pragma once


/* scanf 및 fscanf 사용을 위한 보안 경고 무시 */
#define _CRT_SECURE_NO_WARNINGS


/* 라이브러리 및 헤더파일 포함 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/* 간단한 max 함수 */
#define MAX(a, b) (a) > (b) ? (a) : (b)


/* 트리의 노드를 표현하기 위한 구조체 선언 */
typedef struct Node* TreePointer;
typedef struct Node {
	char std_name[50];						// 이름
	int std_num;							// 학번
	TreePointer left_child, right_child;	// 왼쪽 자식 노드, 오른쪽 자식 노드
} TreeNode;


/* BST 구조체 선언 */
typedef struct {
	TreePointer root;	// 루트 노드
	int count;			// 노드의 개수
} BST;


/* search 함수의 반환값 구조체 */
typedef struct {
	bool found;					// 노드를 찾았는지 여부
	int level;					// 노드의 레벨
	TreePointer parent;			// 부모 노드
	TreePointer search_node;	// 검색된 노드
} SearchResult;


/* 트리 초기화 함수 */
void initTree(BST* tree) {
	/* 이 함수는 트리 포인터 tree를 받아서 트리를 초기화 하는 함수입니다. */
	tree->root = NULL;	// 루트 노드를 NULL로 초기화
	tree->count = 0;	// 노드의 개수를 0으로 초기화
}


/* 노드 방문 함수 */
void visit(TreePointer node) {
	/* 이 함수는 트리의 노드를 방문하는 함수입니다. */
	printf("%s(%d)\n", node->std_name, node->std_num);
}


/* 함수 프로토타입 선언 (구현해야 하는 함수들입니다.) */
bool construct_tree_from_file(BST* Tree, char* filename);	// 1. 파일로부터 트리 구성
SearchResult search_node(BST* Tree, char* key);				// 2-1-1. 노드 검색
bool insert_node(BST* Tree, char* std_name, int std_num);	// 2-1-2. 노드 추가
bool delete_node(BST* Tree, char* key);						// 2-1-3. 노드 삭제
int get_height(TreePointer root);							// 2-1-4-a. 트리의 높이 계산 (재귀)
int leafcount(TreePointer root);							// 2-1-4-b. 리프 노드 개수 계산 (재귀)
void preorder(TreePointer root);							// 2-1-5. preorder 출력 (재귀)
void postorder(TreePointer root);							// 2-1-6. postorder 출력 (재귀)
void inorder(TreePointer root);								// 2-1-7-a. inorder 출력 (재귀)
void inorder_reverse(TreePointer root);						// 2-1-7-b. inorder 역순 출력 (재귀)