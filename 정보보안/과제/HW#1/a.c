#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 암호화 함수: 메시지를 전치 암호화하고 결과를 파일에 저장
void encrypt(char *message, int key, FILE *output_file) {
    int len = strlen(message);
    int rows = (len + key - 1) / key; // 메시지를 key 열로 나눌 때 필요한 행 수

    // 2차원 배열 할당 (행: rows, 열: key)
    char transposed[rows][key];
    
    // 배열을 초기화하고 메시지를 채움
    int index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            if (index < len) {
                transposed[r][c] = message[index++];
            } else {
                transposed[r][c] = ' '; // 남는 공간을 공백으로 채움
            }
        }
    }

    // 열 단위로 암호화된 메시지를 출력하고 파일에 저장
    printf("Encrypted message: ");
    fprintf(output_file, "Encrypted message: ");
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            printf("%c", transposed[r][c]);
            fprintf(output_file, "%c", transposed[r][c]); // 파일에 저장
        }
    }
    printf("\n");
    fprintf(output_file, "\n"); // 파일에 개행 추가
}

// 복호화 함수: 암호화된 메시지를 원래 메시지로 복원
void decrypt(char *encrypted_message, int key, FILE *output_file) {
    int len = strlen(encrypted_message);
    int rows = (len + key - 1) / key; // 메시지를 key 열로 나눌 때의 행 수

    // 2차원 배열을 할당 (행: rows, 열: key)
    char transposed[rows][key];

    // 암호화된 메시지를 배열에 열 단위로 채움
    int index = 0;
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            if (index < len) {
                transposed[r][c] = encrypted_message[index++];
            } else {
                transposed[r][c] = ' '; // 남는 공간을 공백으로 채움
            }
        }
    }

    // 행 단위로 복호화된 메시지를 출력하고 파일에 저장
    printf("Decrypted message: ");
    fprintf(output_file, "Decrypted message: ");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            if (transposed[r][c] != ' ') {  // 공백 제외
                printf("%c", transposed[r][c]);
                fprintf(output_file, "%c", transposed[r][c]); // 파일에 저장
            }
        }
    }
    printf("\n");
    fprintf(output_file, "\n"); // 파일에 개행 추가
}

int main() {
    char input_filename[100], output_filename[100];
    FILE *input_file, *output_file;
    char *message;
    int key;
    long file_size;
    int choice;

    // 입력 파일 이름 입력받기
    printf("Enter the input filename: ");
    scanf("%s", input_filename);

    // 입력 파일 열기
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening file %s\n", input_filename);
        return 1;
    }

    // 파일 크기 구하기
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    // 파일 크기만큼 메모리 할당
    message = (char *)malloc(sizeof(char) * (file_size + 1));
    if (message == NULL) {
        printf("Memory error\n");
        fclose(input_file);
        return 1;
    }

    // 파일 내용을 메모리에 읽어오기
    fread(message, sizeof(char), file_size, input_file);
    message[file_size] = '\0'; // 문자열 종료

    // 입력 파일 닫기
    fclose(input_file);

    // 암호화 키 입력받기
    printf("Enter the key (number of columns): ");
    scanf("%d", &key);

    // 작업 선택 (암호화 또는 복호화)
    printf("Choose an operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    // 출력 파일 이름 입력받기
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    // 출력 파일 열기
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening file %s\n", output_filename);
        free(message);
        return 1;
    }

    // 선택에 따라 암호화 또는 복호화 수행
    if (choice == 1) {
        encrypt(message, key, output_file);
    } else if (choice == 2) {
        decrypt(message, key, output_file);
    } else {
        printf("Invalid choice\n");
    }

    // 출력 파일 닫기
    fclose(output_file);

    // 메모리 해제
    free(message);

    if (choice == 1) {
        printf("Encrypted message saved to %s\n", output_filename);
    } else if (choice == 2) {
        printf("Decrypted message saved to %s\n", output_filename);
    }

    return 0;
}

