#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *message, int key, FILE *output_file) {
    int len = strlen(message);
    int rows = (len + key - 1) / key;
    char transposed[key][rows]; 

    int index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            if (index < len)
                transposed[c][r] = message[index++];
            else
                transposed[c][r] = ' ';
        }
    }




    fprintf(output_file , "");
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            printf("%c" , transposed[c][r]);
            fprintf(output_file, "%c", transposed[c][r]);
        }
    }
    printf("\n");
    fprintf(output_file, "\n");
}

void decrypt(char *encrypted_message, int key, FILE *output_file) {
    int len = strlen(encrypted_message);
    int rows = (len + key - 1) / key; 

    char transposed[key][rows]; 

    int index = 0;
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            if (len > index) transposed[c][r] = encrypted_message[index++];
        }
    }


    fprintf(output_file, "");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            if (transposed[c][r] != ' ') { 
                printf("%c", transposed[c][r]);
                fprintf(output_file, "%c", transposed[c][r]);
            }
        }
    }
    printf("\n");
    fprintf(output_file, "\n"); 
}

int main() {
    char input_filename[100], output_filename[100];
    FILE *input_file, *output_file;
    char *message;
    int key;
    long file_size;
    int choice;

    printf("파일 이름을 입력하세요 : ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("파일 이름을 잘못 입력하셨습니다. 다시 입력해주세요. %s\n", input_filename);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);
    message = (char *)malloc(sizeof(char) * (file_size + 1));
    if (message == NULL) {
        printf("파일 내용이 잘못되었습니다. 입력 파일을 확인해주세요\n");
        fclose(input_file);

        return 1;
    }

    fread(message, sizeof(char), file_size, input_file);
    message[file_size] = '\0';
    fclose(input_file);

    printf("Key값을 입력해주세요: ");
    scanf("%d", &key);

    printf("파일 처리 방식을 입력해주세요 :\n");
    printf("1. 암호화\n");
    printf("2. 복호화\n");
    scanf("%d", &choice);

    printf("작성할 파일 이름을 입력해주세요: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("파일 이름이 잘못되었습니다. %s\n", output_filename);
        free(message);
        return 1;
    }

    if (choice == 1) encrypt(message, key, output_file);
    else if (choice == 2) decrypt(message, key, output_file);
    else printf("잘못된 선택 방식 입니다.\n");

    fclose(output_file);
    free(message);

    if (choice == 1) printf("암호화 된 내용이 %s에 저장되었습니다.\n", output_filename);
    else if (choice == 2) printf("복호화 된 내용이 %s에 저장되었습니다.\n", output_filename);
    return 0;
}
