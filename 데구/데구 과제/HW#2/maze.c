#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 14
#define p 14
#define Max_dir 4
//
typedef struct Aoff {
    short int vert;
    short int horiz;
} offsets;
//스택에 저장할 데이터
typedef struct St_element {
    short int row;
    short int col;
    short int dir;
} ty_element;

//연결 스택 노드
typedef struct ListNode* listPointer;
typedef struct ListNode {
    ty_element data;
    listPointer link;
} listNode;

typedef struct Stack {
    ty_element stack[m];
    int top;
}maze_stack;


void creat(maze_stack* S) {
    S->top = -1;
    return;
}

//isFull 연산
int isFull(maze_stack *S){
    return S->top == m - 1;
}
//isEmpt 연산
int isEmpty(maze_stack *S){
    return S->top == -1;;
}

ty_element push(maze_stack* S, ty_element x) {
    if (isFull(S)) {
        printf("Stack is Full");
        ty_element Err = {-1, -1, 0};
        return Err;
    }
    else {
        S->top++;
        S->stack[S->top] = x;
    }
}


ty_element pop(maze_stack* S) {
    if (isEmpty(S)) {
        printf("Stack is Empty");
        ty_element Err = {-1 , -1 , 0};
        return Err;
    }
    else {
        ty_element Q = S -> stack[S -> top];
        S -> top--;
        return Q;
    }
}

ty_element peek(maze_stack* S) {
    if (isEmpty(S)) {
        printf("Stack is Empty");
        ty_element Err = {-1 , -1 , 0};
        return Err;
    }
    else {
        return S -> stack[S -> top];
    }
}

offsets move[Max_dir] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};

int maze[m + 2][p + 2];
int mark[m + 2][p + 2];
int backtrack_count = 0;
int to_path_length = 0;

int path(int sy, int sx, int dy, int dx) {
    listPointer link_top = NULL;
    int row, col, nextRow, nextCol, dir , basex , basey , ocount;
    int find_obstacle_found;
    ty_element position;

    if (maze[sy][sx] == 1 || maze[dy][dx] == 1) {
        printf("입력 오류: 출발점이나 목표점이 막힌 셀입니다.\n");
        return 0;
    }
    //빈 스택에 초기화 데이터를 입력한다 = 초기화
    position.row = sy;
    position.col = sx;
    position.dir = 0;   //  스택 위치 선정
    push(&link_top, position);

    //mark 초기화
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < p + 2; j++) {
            mark[i + 1][j + 1] = 0;
        }
    }

    

    mark[sy][sx] = 1;
    for (int i = 0; i < Max_dir; i++) {
        ty_element here;
        int tmp_row = here.row;
        int tmp_col = here.col;
    }
    
}

void read_maze_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < p + 2; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fclose(fp);
}




int main() {
    int starty, startx, endy, endx, res;

    printf("출발점(sy,sx)과 목표 지점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
    while ((res = scanf("%d %d %d %d", &starty, &startx, &endy, &endx)) != EOF) {
        if (getchar() == '^D') {
            break;
        }
        else if (res != 4) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            // 입력 버퍼 비우기
            while (getchar() != '\n');
            continue;
        }

        // 파일에서 미로 읽기
        read_maze_from_file("maze_data.txt");

        if (path(starty , startx , endy , endx)) {
            printf("목표 지점에 도착했습니다!\n");
            printf("백트래킹 횟수: %d\n", backtrack_count);
            printf("경로까지의 길이: %d\n", to_path_length);
        }
        else {
            printf("목표 지점에 도착할 수 없습니다.\n");
            printf("백트래킹 횟수: %d\n", backtrack_count);
            printf("경로까지의 길이: %d\n", to_path_length);
        }

        printf("\n출발점(sy,sx)과 도착점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
    }
    return 0;
}



