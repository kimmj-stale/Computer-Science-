#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 16

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

char maze[MAZE_SIZE][MAZE_SIZE];
int backtrack_count = 0;
int path_length = 0;

void read_maze_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    for (int i = 0; i < MAZE_SIZE; i++) {
        if (fgets(maze[i], MAZE_SIZE + 2, fp) == NULL) {
            fprintf(stderr, "파일 형식이 잘못되었습니다.\n");
            exit(1);
        }
        // 개행 문자 제거
        maze[i][MAZE_SIZE] = '\0';
        maze[i][strcspn(maze[i], "\n")] = '\0';
    }
    fclose(fp);
}

void maze_print() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("%s\n", maze[i]);
    }
}

// 상, 하, 좌, 우 이동 방향
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int path(element start, element goal) {
    int visited[MAZE_SIZE][MAZE_SIZE] = {0};
    StackType s;
    init_stack(&s);
    push(&s, start);
    visited[start.row][start.column] = 1;

	printf("찾은 경로 (row , column) : ");
    while (!is_stack_empty(&s)) {
        element here = pop(&s);
        int row = here.row;
        int col = here.column;
        printf(" [ %d, %d ] ", row, col);

        if (row == goal.row && col == goal.column) {
            return 1;
        }

        int possible_moves = 0; // 가능한 이동 횟수
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < MAZE_SIZE && nc >= 0 && nc < MAZE_SIZE &&
                maze[nr][nc] != '1' && !visited[nr][nc]) {
                element next = {nr, nc};
                push(&s, next);
                visited[nr][nc] = 1;
                possible_moves++;
            }
        }

        // 가능한 이동이 없는 경우 백트래킹
        if (possible_moves == 0) {
            backtrack_count++;
            if (!is_stack_empty(&s)) {
                path_length--;
            }
        } else {
            path_length++;
        }
    }
    return 0;
}

int main() {
    int starty, startx, endy, endx, res;

    printf("출발점(sy,sx)과 목표 지점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
    while ((res = scanf("%d %d %d %d", &starty, &startx, &endy, &endx)) != EOF) {
        if (res != 4) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            // 입력 버퍼 비우기
            while (getchar() != '\n');
            continue;
        }

        element start = {starty, startx};
        element goal = {endy, endx};

        // 파일에서 미로 읽기
        read_maze_from_file("maze_data.txt");

        if (path(start, goal)) {
            printf("목표 지점에 도착했습니다!\n");
            printf("백트래킹 횟수: %d\n", backtrack_count);
            printf("경로까지의 길이: %d\n", path_length);
        } else {
            printf("장애물 발견으로 중단되었습니다.\n");
        }

        printf("\n출발점(sy,sx)과 도착점(dy,dx)을 입력하세요 (종료: Ctrl+D): ");
        backtrack_count = 0;
        path_length = 0;
    }
    return 0;
}