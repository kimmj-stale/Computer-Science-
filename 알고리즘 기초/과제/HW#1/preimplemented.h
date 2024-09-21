#pragma once


/* scanf 및 fscanf 사용을 위한 보안 경고 무시 */
#define _CRT_SECURE_NO_WARNINGS


/* 라이브러리 및 헤더파일 포함 */
#include <stdio.h>
#include <stdlib.h>


/* AVL 트리 노드 구조체 */
typedef struct AVLNode {
	int key;				// 노드의 키 값

	struct AVLNode* left;   // 왼쪽 자식 노드
	struct AVLNode* right;  // 오른쪽 자식 노드
} AVLNode;


/* 함수 프로토타입 선언 (구현해야 하는 함수들입니다.) */
AVLNode* insertAVLTree(AVLNode* node, int key);
AVLNode* rotateLL(AVLNode* pNode);
AVLNode* rotateRR(AVLNode* pNode);
AVLNode* rotateLR(AVLNode* pNode);
AVLNode* rotateRL(AVLNode* pNode);
int getHeight(AVLNode* node);
int getBalanceFactor(AVLNode* node);


/* AVL 트리 노드 생성 함수 */
AVLNode* createNode(int key) {
	/*
		INPUT:
			int std_num: 학번
			const char* std_name: 이름

		OUTPUT:
			AVLNode*: 생성된 노드

		DESCRIPTION:
			학번과 이름을 입력받아 AVL 노드를 생성하는 함수.
	*/

	// 노드 동적 할당
	AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
	if (newNode == NULL) {
		printf("Failed to allocate memory\n");
		exit(1);
	}

	// 노드 초기화
	newNode->key = key;

	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}


/* AVL 트리 노드 출력 함수 */
void printAVLTree(AVLNode* node, int level) {
	/*
		INPUT:
			AVLNode* node: 출력할 노드
			int level: 노드의 레벨

		DESCRIPTION:
			AVL 트리를 레벨 순서대로 출력하는 함수.
	*/

	// 노드가 NULL인 경우 반환
	if (node == NULL) return;

	// 오른쪽 서브트리 출력
	printAVLTree(node->right, level + 1);

	// 현재 노드 출력
	for (int i = 0; i < level; i++) {
		printf("    ");
	}
	printf("%d\n", node->key);

	// 왼쪽 서브트리 출력
	printAVLTree(node->left, level + 1);
}


/* 파일로부터 AVL 트리 구축하는 함수 */
AVLNode* buildAVLTreeFromFile(const char* filename) {
	/*
		INPUT:
			const char* filename: AVL 트리를 구축할 파일 이름

		OUTPUT:
			AVLNode*: 구축된 AVL 트리

		DESCRIPTION:
			파일로부터 AVL 트리를 구축하는 함수.
	*/

	// 파일 포인터 선언
	FILE* fp;

	// AVL 트리 루트 노드 선언
	AVLNode* root = NULL;

	// 파일 열기
	//VS에서 fopen_s로 고쳐서 컴파일하기
	if (fopen_s(&fp , filename , "r") != 0) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	// 파일로부터 학번을 읽어 AVL 트리에 삽입
	int key;
	while (fscanf(fp, "%d", &key) != EOF) {
		root = insertAVLTree(root, key);
		printAVLTree(root, 0);
		printf("==========================================\n");
	}

	// 파일 닫기
	fclose(fp);

	// AVL 트리 루트 노드 반환
	return root;
}