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
	// 노드가 NULL인 경우 새로운 노드 생성 (createNode 함수 사용)
	if (node == NULL) return createNode(key);
	// if 삽입할 키 값이 현재 노드의 키 값보다 작은 경우 왼쪽 서브트리에 삽입 (재귀 호출)
	// else if 삽입할 키 값이 현재 노드의 키 값보다 큰 경우 오른쪽 서브트리에 삽입 (재귀 호출)
	// else 삽입할 키 값이 현재 노드의 키 값과 같은 경우 삽입 실패 메시지 출력
	if (node -> key > key) insertAVLTree(node -> left , key);
	else if (node -> key < key) insertAVLTree(node -> right , key);
	else return "삽입 실패";
	// 노드의 balance factor 계산
	int balance_F = getBalanceFactor(node);
	// balanceFactor 값에 따른 LL/RR/LR/RL 회전 수행
	if (balance_F > 1 && key < node -> left -> key) {
		return rotateLL(node);
	} if (balance_F < -1 && key > node -> right -> key) {
		return rotateRR(node);
	} if (balance_F > 1 && key > node -> left -> key) {
		return rotateLR(node);
	} if (balance_F < -1 && key < node -> right -> key) {
		return rotateRL(node);
	}
	/* ================= YOUR CODE ENDS HERE ================== */

	// 삽입된 노드 반환
	return node;
}


/* AVL 트리의 LL 회전 */
AVLNode* rotateLL(AVLNode* pNode) {	//	O
	/*
		INPUT:
			AVLNode* pnode: LL 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 LL 회전을 수행하는 함수.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	AVLNode* cNode = pNode->right;
	AVLNode* cRNode = cNode -> right;

	cNode -> left = pNode;
	pNode -> right = cRNode;

	return pNode;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* AVL 트리의 RR 회전 */
AVLNode* rotateRR(AVLNode* pNode) {	//	O
	/*
		INPUT:
			AVLNode* pnode: RR 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 RR 회전을 수행하는 함수.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	AVLNode* cNode = pNode -> left;
	AVLNode* cLNode = cNode -> left;

	cNode -> right = pNode;
	pNode ->left = cLNode;

	return pNode;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* AVL 트리의 LR 회전 */
AVLNode* rotateLR(AVLNode* pNode) {	//	O
	/*
		INPUT:
			AVLNode* pnode: LR 회전을 수행할 노드

		OUTPUT:
			AVLNode*: 회전된 노드

		DESCRIPTION:
			AVL 트리의 LR 회전을 수행하는 함수. (위에서 구현한 LL, RR 회전 함수 사용)
	*/

	/* ==================== FILL YOUR CODE ==================== */
	AVLNode* bNode = pNode -> left;
	AVLNode* cNode = bNode -> right;

	rotateRR(bNode);
	pNode -> left = cNode;
	rotateLL(pNode);

	return pNode;
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
	AVLNode* bNode = pNode -> right;
	AVLNode* cNode = bNode -> left;

	rotateLL(bNode);
	pNode -> right = cNode;
	rotateRR(pNode);

	return pNode;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* 노드의 height 구하는 함수 */
int getHeight(AVLNode* node) {
	/*
		INPUT:
			AVLNode* node: 높이를 구할 노드

		OUTPUT:
			int: 노드의 높이

		DESCRIPTION:
			AVL 노드의 높이를 재귀적으로 구하는 함수.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	// 노드가 NULL인 경우 0 반환
	if (node->key == NULL) return 0; 
	// 왼쪽 서브트리의 높이와 오른쪽 서브트리의 높이 중 큰 값에 1을 더한 값 반환 (재귀 호출)
	int L_Height = getHeight(node -> left) + 1;
	int R_Height = getHeight(node -> right) + 1;

	return (L_Height > R_Height) ? L_Height : R_Height;
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
	// 노드가 NULL인 경우 0 반환
	if (node->key == NULL) return 0;
	// 왼쪽 서브트리의 높이 - 오른쪽 서브트리의 높이 반환
	return getHeight(node->left) - getHeight(node->right);
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* main 함수 */
int main() {
	/* AVL 트리 생성 및 출력 */
	AVLNode* AVLTree = buildAVLTreeFromFile("data.txt");
	printAVLTree(AVLTree, 0);
	return 0;
}