/*	=================================================================
*	HW3: Binary Search Tree
*	Filename: implementation.h
*	Creator: Han-Jin Lee
*	Created: 04/11/2024
*	Purpose: implementation header file for DS_HW3
*	===============================================================*/


#pragma once
/*
strcmp를 이용하여 받은 data를 정렬시킨다
받은 문자열의 앞 문자부터 아스키 코드로 비교한다.
*/
/* 파일로부터 트리를 구성하는 함수 */
bool construct_tree_from_file(BST* Tree, char* filename) {
	/*
		INPUT:
			BST* Tree: 트리 구조체 포인터
			char* filename: 파일 이름

		OUTPUT:
			bool: 파일 열기 성공 여부
				true: 파일 열기 성공
				false: 파일 열기 실패

		DESCRIPTION:
			이 함수는 파일로부터 트리를 구성하는 함수입니다.
			파일을 열어서 학생 이름과 학번을 읽어서 트리에 추가합니다.
			파일 열기에 성공하면 true를 반환하고, 실패하면 false를 반환합니다.
	*/

	FILE* fp = fopen(filename, "r");
	if (!fp) return false;

	int std_num;
	char std_name[50];

	/* ==================== FILL YOUR CODE ==================== */
	while (fscanf(fp, "%d %49s", &std_num, &std_name) == 2) {
        insert_node(Tree, std_name, std_num);
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	fclose(fp);
	return true;
}


/* 노드 검색 함수 */
SearchResult search_node(BST* Tree, char* key) {	//	O
	/*
		INPUT:
			BST* Tree: 트리 구조체 포인터
			int key: 검색할 학번

		OUTPUT:
			SearchResult: 검색 결과를 저장하는 구조체
				bool found: 노드를 찾았는지 여부
				int level: 노드의 레벨
				TreePointer parent: 부모 노드
				TreePointer search_node: 검색된 노드

		DESCRIPTION:
			이 함수는 트리 Tree와 검색할 이름 key를 받아서 해당 노드를 검색하는 함수입니다.
			트리를 순회하면서 key와 일치하는 노드를 찾으면 SearchResult 구조체에 저장하여 반환합니다.
	*/

	SearchResult result;
	result.found = false;
	result.level = 1;
	result.parent = NULL;
	result.search_node = Tree->root;
	/* ==================== FILL YOUR CODE ==================== */
	while (result.search_node != NULL) {
        if (strcmp(key, result.search_node->std_name) < 0) {
            result.parent = result.search_node;
            result.search_node = result.search_node->left_child;
        } else if (strcmp(key, result.search_node->std_name) == 0) {
            result.found = true;
            return result;
        } else {
            result.parent = result.search_node;
            result.search_node = result.search_node->right_child;
        }
        result.level++;
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	//탐색 성공 여부 return
	return result;
}


/* BST에 노드를 추가하는 함수 */
bool insert_node(BST* Tree, char* std_name, int std_num) {	//	O
	/*
		INPUT:
			BST* Tree: 트리 구조체 포인터
			char* std_name: 추가할 학생 이름
			int std_num: 추가할 학생 학번

		OUTPUT:
			bool: 노드 추가 성공 여부
				true: 노드 추가 성공
				false: 이미 동일 노드가 존재하는 경우

		DESCRIPTION:
			이 함수는 트리 Tree에 새로운 노드를 추가하는 함수입니다.
			트리를 순회하면서 적절한 위치를 찾아서 노드를 추가합니다.
			노드 추가에 성공하면 true를 반환하고, 실패하면 false를 반환합니다.
	*/

	// 노드 생성 및 초기화
	TreePointer new_node = (TreePointer)malloc(sizeof(TreeNode));
	new_node->std_num = std_num;
	strcpy(new_node->std_name, std_name);
	new_node->left_child = new_node->right_child = NULL;

	// 구현에 사용하세요
	TreePointer parent = NULL , current = Tree->root;
	SearchResult result;
	/* ==================== FILL YOUR CODE ==================== */
    if (Tree->root == NULL) {
        Tree->root = new_node;
        Tree->count++;
        return true;
    }

    while (current != NULL) {
        parent = current;
        if (strcmp(std_name, current->std_name) < 0) {
            current = current->left_child;
        } 
		else if (strcmp(std_name , current -> std_name) == 0) {
			return false;
		}
		else {
            current = current->right_child;
        }
    }

    if (strcmp(std_name, parent->std_name) < 0) {
        parent->left_child = new_node;
    } else {
        parent->right_child = new_node;
    }

    Tree->count++;
	/* ================= YOUR CODE ENDS HERE ================== */
	return true;
}


/* BST에서 노드를 삭제하는 함수 */
bool delete_node(BST* Tree, char* key) {	//	O
	/*
		INPUT:
			BST* Tree: 트리 구조체 포인터
			char* key: 삭제할 학생 이름

		OUTPUT:
			bool: 노드 삭제 성공 여부
				true: 노드 삭제 성공
				false: 삭제할 노드가 존재하지 않는 경우

		DESCRIPTION:
			이 함수는 트리 Tree에서 이름이 key인 노드를 삭제하는 함수입니다.
			트리를 순회하면서 삭제할 노드를 찾아서 삭제합니다.
			노드 삭제에 성공하면 true를 반환하고, 실패하면 false를 반환합니다.
	*/

	// 구현에 사용하세요
	SearchResult result = search_node(Tree, key);
	if (!result.found) return false;
	TreePointer del_node = result.search_node;
	TreePointer del_parent = result.parent;
	/* ==================== FILL YOUR CODE ==================== */
	TreePointer data , overlap_p , overlap;
	if ((del_node->left_child == NULL) && (del_node->right_child == NULL)) {
        if (del_parent != NULL) {
            if (del_parent->left_child == del_node) {
                del_parent->left_child = NULL;
            } else {
                del_parent->right_child = NULL;
            }
        } else {
            Tree->root = NULL;
        }
    } else if ((del_node->left_child == NULL) || (del_node->right_child == NULL)) {
        if (del_node->left_child != NULL) data = del_node->left_child;
        else data = del_node->right_child;

        if (del_parent != NULL) {
            if (del_parent->left_child == del_node) del_parent->left_child = data;
            else del_parent->right_child = data;
        } else {
            Tree->root = data;
        }
    } else {
        overlap = del_node->left_child;
        overlap_p = del_node;

        while (overlap->right_child != NULL) {
            overlap_p = overlap;
            overlap = overlap->right_child;
        }

        if (overlap_p->left_child == overlap) {
            overlap_p->left_child = overlap->left_child;
        } else {
            overlap_p->right_child = overlap->left_child;
        }
        del_node->std_num = overlap->std_num;
        strcpy(del_node->std_name, overlap->std_name);
        del_node = overlap;
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	free(del_node);
	Tree->count--;
	return true;
}

/* 트리의 높이를 계산하는 함수 */
int get_height(TreePointer root) {
	/*
		INPUT:
			TreePointer root: 트리의 루트 노드

		OUTPUT:
			int: 트리의 높이

		DESCRIPTION:
			이 함수는 트리 Tree의 높이를 '재귀적으로' 계산하는 함수입니다.
			트리의 높이를 계산하여 반환합니다.
			MAX(a, b) 함수를 사용하면 두 값 중 큰 값을 반환할 수 있습니다.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	if (root == NULL) return 0;

	int depth_lf = get_height(root -> left_child);
	int depth_rt = get_height(root -> right_child);

	return MAX(depth_lf , depth_rt) + 1;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* leaf node 개수 계산 함수 */
int leafcount(TreePointer root) {	//	O
	/*
		INPUT:
			TreePointer root: 트리의 루트 노드

		OUTPUT:
			int: 리프 노드의 개수

		DESCRIPTION:
			이 함수는 트리의 리프 노드의 개수를 계산하는 함수입니다.
			트리를 '재귀적으로' 순회하면서 리프 노드의 개수를 계산하여 반환합니다.
	*/
	/* ==================== FILL YOUR CODE ==================== */
	if (root == NULL) {
		return 0;
	}
	else if ((root -> left_child == NULL) && (root -> right_child == NULL)) {
		return 1;
	}
	return leafcount(root -> left_child) + leafcount(root -> right_child);
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* preorder */
void preorder(TreePointer root) {	//	V -> L -> R		//	O
	/*
		INPUT:
			TreePointer root: 트리의 루트 노드

		DESCRIPTION:
			이 함수는 트리를 preorder로 순회하여 출력하는 함수입니다.
			visit 함수를 호출하여 노드를 출력합니다.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	if (root != NULL) {
		visit(root);
		preorder(root -> left_child);
		preorder(root -> right_child);
	}
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* postorder */
void postorder(TreePointer root) {	//	L -> R -> V		//	O
	/*
	INPUT:
		TreePointer root: 트리의 루트 노드
	DESCRIPTION:
		이 함수는 트리를 postorder로 순회하여 출력하는 함수입니다.
		visit 함수를 호출하여 노드를 출력합니다.
*/

	/* ==================== FILL YOUR CODE ==================== */
	if (root != NULL) {
		postorder(root -> left_child);
		postorder(root -> right_child);
		visit(root);
	}
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* inorder */
void inorder(TreePointer root) {	//	L -> V -> R		//	O
	/*
		INPUT:
			TreePointer root: 트리의 루트 노드

		DESCRIPTION:
			이 함수는 트리를 inorder로 순회하여 출력하는 함수입니다.
			visit 함수를 호출하여 노드를 출력합니다.
	*/

	/* ==================== FILL YOUR CODE ==================== */
	if (root != NULL) {
		inorder(root -> left_child);
		visit(root);
		inorder(root -> right_child);
	}
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* inorder_reverse */
void inorder_reverse(TreePointer root) {	//	R -> V -> L		//	O
	/*
		INPUT:
			TreePointer root: 트리의 루트 노드

		DESCRIPTION:
			이 함수는 트리를 inorder로 역순으로 순회하여 출력하는 함수입니다.
			visit 함수를 호출하여 노드를 출력합니다.
	*/
	/* ==================== FILL YOUR CODE ==================== */
	if (root != NULL) {
		inorder_reverse(root -> right_child);
		visit(root);
		inorder_reverse(root -> left_child);
	}
	/* ================= YOUR CODE ENDS HERE ================== */
}