/* 헤더파일 포함 */
#include "preimplemented.h"


/* AVL 트리 노드 삽입 함수 */
AVLNode* insertAVLTree(AVLNode* node, int key) {
	/*
		INPUT:
			AVLNode* node: 삽입할 노드 (최초 호출 시 주로 root 노드)
			int key: 삽입할 키 값

		OUTPUT:
			AVLNode*: 삽입된 노드 (최초 호출 시 주로 root 노드)

		DESCRIPTION:
			AVL 트리에 노드를 삽입하는 함수.
			삽입할 위치를 재귀적으로 찾아 삽입하고,
			삽입 후 균형을 맞추기 위해 회전 연산을 수행한다.
			새로운 노드를 만들 때는 createNode 함수를 사용하고,
			balance factor 계산은 getBalanceFactor 함수를 사용한다.
			또한, 회전 연산은 rotateLL, rotateRR, rotateLR, rotateRL 함수를 사용한다.
	*/

	/* ==================== FILL YOUR CODE ==================== */
// 노드가 NULL인 경우 새로운 노드 생성
	if (node == NULL) return createNode(key);

	// 삽입할 키 값이 현재 노드의 키 값보다 작은 경우 왼쪽 서브트리에 삽입
	if (key < node->key)
		node->left = insertAVLTree(node->left, key);

	// 삽입할 키 값이 현재 노드의 키 값보다 큰 경우 오른쪽 서브트리에 삽입
	else if (key > node->key)
		node->right = insertAVLTree(node->right, key);

	// 삽입할 키 값이 현재 노드의 키 값과 같은 경우 삽입 실패 (중복 키)
	else
		return node;

	// 노드의 balance factor 계산
	int balance = getBalanceFactor(node);

	// LL 회전: 왼쪽에 삽입된 경우
	if (balance > 1 && key < node->left->key)
		return rotateLL(node);

	// RR 회전: 오른쪽에 삽입된 경우
	if (balance < -1 && key > node->right->key)
		return rotateRR(node);

	// LR 회전: 왼쪽-오른쪽에 삽입된 경우
	if (balance > 1 && key > node->left->key) {
		node->left = rotateRR(node->left);
		return rotateLL(node);
	}

	// RL 회전: 오른쪽-왼쪽에 삽입된 경우
	if (balance < -1 && key < node->right->key) {
		node->right = rotateLL(node->right);
		return rotateRR(node);
	}

	return node;
	/* ================= YOUR CODE ENDS HERE ================== */

	// 삽입된 노드 반환
	return node;
}


/* AVL 트리의 LL 회전 */
AVLNode* rotateLL(AVLNode* pNode) {
	/*
		INPUT:
			AVLNode* pnode: LL 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 LL 회전을 수행하는 함수.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	AVLNode* cNode = pNode->left;
	pNode->left = cNode->right;
	cNode->right = pNode;

	return cNode;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* AVL 트리의 RR 회전 */
AVLNode* rotateRR(AVLNode* pNode) {
	/*
		INPUT:
			AVLNode* pnode: RR 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 RR 회전을 수행하는 함수.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	AVLNode* cNode = pNode->right;
	pNode->right = cNode->left;
	cNode->left = pNode;

	return cNode;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* AVL 트리의 LR 회전 */
AVLNode* rotateLR(AVLNode* pNode) {
	/*
		INPUT:
			AVLNode* pnode: LR 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 LR 회전을 수행하는 함수. (위에서 구현한 LL, RR 회전 함수 사용)
	*/

	/* ==================== FILL YOUR CODE ==================== */
	pNode->left = rotateRR(pNode->left);
	return rotateLL(pNode);
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* AVL 트리의 RL 회전 */
AVLNode* rotateRL(AVLNode* pNode) {
	/*
		INPUT:
			AVLNode* pnode: RL 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 RL 회전을 수행하는 함수. (위에서 구현한 LL, RR 회전 함수 사용)
	*/

	/* ==================== FILL YOUR CODE ==================== */
	pNode->right = rotateLL(pNode->right);
	return rotateRR(pNode);
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* 노드의 balance factor 구하는 함수 */
int getBalanceFactor(AVLNode* node) {
	/*
		INPUT:
			AVLNode* node: balance factor를 구할 노드

		OUTPUT:
			int: 노드의 balance factor

		DESCRIPTION:
			AVL 노드의 balance factor를 구하는 함수.
			getHeight 함수를 사용하여 왼쪽 서브트리와 오른쪽 서브트리의 높이를 구하고,
			두 높이의 차이를 반환한다.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	if (node == NULL) return 0;
	// 왼쪽 서브트리의 높이 - 오른쪽 서브트리의 높이 반환
	return height(node->left) - height(node->right);
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* main 함수 */
int main() {
	/* AVL 트리 생성 및 출력 */
	AVLNode* AVLTree = buildAVLTreeFromFile("data.txt");
	printAVLTree(AVLTree, 0);
	return 0;
}
