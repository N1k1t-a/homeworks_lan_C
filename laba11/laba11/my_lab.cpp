#include "my_lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_operations(FILE* file, FILE* output_file) {

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);


    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    int add_count = 0, sub_count = 0, mul_count = 0, div_count = 0;
    int assign_count = 0, compare_count = 0;
    char* ptr = buffer;
    int in_multiline_comment = 0;  

    while (*ptr) {

        if (*ptr == '/' && *(ptr + 1) == '/') {
            fprintf(output_file, "//");
            ptr += 2;
            while (*ptr && *ptr != '\n') {
                fputc(*ptr, output_file);  
                ptr++;
            }
            fputc('\n', output_file);  
        }

        else if (*ptr == '/' && *(ptr + 1) == '*') {
            fprintf(output_file, "/*");
            ptr += 2;
            in_multiline_comment = 1;
            while (*ptr) {
                if (*ptr == '*' && *(ptr + 1) == '/') {
                    fprintf(output_file, "*/\n");
                    ptr += 2;
                    in_multiline_comment = 0;
                    break;
                }
                else {
                    fputc(*ptr, output_file);
                    ptr++;
                }
            }
        }

        else if (in_multiline_comment) {
            fputc(*ptr, output_file);
        }
        else if (*ptr == '+') add_count++;
        else if (*ptr == '-') sub_count++;
        else if (*ptr == '*') mul_count++;
        else if (*ptr == '/') div_count++;
        else if (*ptr == '=' && *(ptr + 1) == '=') { compare_count++; ptr++; }
        else if (*ptr == '!' && *(ptr + 1) == '=') { compare_count++; ptr++; }
        else if (*ptr == '<' && *(ptr + 1) == '=') { compare_count++; ptr++; }
        else if (*ptr == '>' && *(ptr + 1) == '=') { compare_count++; ptr++; }
        else if (*ptr == '=' && *(ptr + 1) != '=') assign_count++;

        ptr++;
    }

    printf("Частота операций:\n");
    printf("Сложение (+): %d\n", add_count);
    printf("Вычитание (-): %d\n", sub_count);
    printf("Умножение (*): %d\n", mul_count);
    printf("Деление (/): %d\n", div_count);
    printf("Присваивание (=): %d\n", assign_count);
    printf("Сравнения (==, !=, <=, >=): %d\n", compare_count);

    free(buffer);
}
