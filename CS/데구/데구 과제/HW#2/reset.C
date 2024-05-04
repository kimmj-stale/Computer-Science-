#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 16
#define MAX_ROW 16
#define MAX_COL 16

typedef struct {
    short row;
    short column;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_stack_empty(StackType* s) {
    return (s->top == -1);
}

void push(StackType* s, element item) {
    if (s->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_stack_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType* S) {
    if (is_stack_empty(S)) {
        element empty = {-1, -1};
        return empty;
    }
    else return S->data[S->top];
}

int maze[MAZE_SIZE][MAZE_SIZE];
int backtrack_count = 0;
int path_length = 0;

void read_maze_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fclose(fp);
}

// 이동한 좌표를 저장할 배열
element moved_path[MAX_STACK_SIZE];
void print_moved_path(StackType* s) {
    printf("이동한 경로 좌표:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("[%d, %d]", s->data[i].row, s->data[i].column);
        // 이동한 좌표를 배열에 저장
        moved_path[i] = s->data[i];
    }
    printf("\n");
}

// 상, 하, 좌, 우 이동 방향
int dr[] = {0 , 0 , 1 , -1};
int dc[] = {1 , -1 , 0 , 0};

int path(element start, element goal) {
    int visited[MAX_ROW][MAX_COL] = {0};
    StackType s;
    init_stack(&s);
    push(&s, start);
    visited[start.row][start.column] = 1;

    while (!is_stack_empty(&s)) {
        element here = peek(&s);
        int row = here.row;
        int col = here.column;

        if (row == goal.row && col == goal.column && maze[row][col] == 0) {
            print_moved_path(&s);
            return 1;
        }

        if (row == goal.row && col == goal.column || maze[row][col] == 2) {
            print_moved_path(&s);
            return 3;
        }

        int possible_moves = 0; // 이동한 횟수 , 백트래킹의 판별용으로 사용
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < MAZE_SIZE && nc >= 0 && nc < MAZE_SIZE && maze[nr][nc] == 0 && visited[nr][nc] != 1 || maze[nr][nc] == 2) {
                element next = {nr, nc};
                push(&s, next);
                visited[nr][nc] = 1;
                possible_moves++;
                break;
            }
        }

        // 가능한 이동이 없는 경우 백트래킹
        if (possible_moves == 0) {
            backtrack_count++;
            if (!is_stack_empty(&s)) {
                path_length--;
                pop(&s);
            }
        }
        //아닌 경우 경로길이 ++
        else {
            path_length++;
        }
    }

    return 0;
}

int check_element(element tmp) {
    if (maze[tmp.row][tmp.column] == 0 || maze[tmp.row][tmp.column] == 2) return 1;
    else return 0;
}

int main() {
    int starty, startx, endy, endx;
    printf("출발점(sy,sx)과 목표 지점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
    while (scanf("%d %d %d %d", &starty, &startx, &endy, &endx) == 4) {
        element start = { starty, startx };
        element goal = { endy, endx };

        // 파일에서 미로 읽기
        read_maze_from_file("maze_data.txt");

        int start_point = check_element(start);
        int end_point = check_element(goal);
        if (start_point == 0 || end_point == 0 || end_point == 2) {
            printf("입력 오류: 출발점이나 목표점이 막힌 셀입니다."); 
        }
        else {
            int result = path(start, goal);
            if (result == 1) {
                printf("목표 지점에 도착했습니다!\n");
                printf("백트래킹 횟수: %d\n", backtrack_count);
                printf("경로까지의 길이: %d\n", path_length + 1);
            }
            else if (result == 2) {
                printf("경로까지 도달할 수 있는 경우가 없습니다.\n");
                printf("백트래킹 횟수: %d\n", backtrack_count);
                printf("경로까지의 길이: %d\n", path_length + 1);
            }
            else {
                printf("장애물 발견으로 중단되었습니다.\n");
                printf("백트래킹 횟수: %d\n", backtrack_count);
                printf("경로까지의 길이: %d\n", path_length + 1);
            }
        }
        printf("\n출발점(sy,sx)과 목표 지점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
        backtrack_count = 0;
        path_length = 0;
    }

    printf("프로그램을 종료합니다.\n");
    return 0;
}
