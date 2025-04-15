#ifndef MY_LAB_H
#define MY_LAB_H

void pathsplit(char* path, char* split[]);
char* normalize_path(const char* path);
void print_tree(const char* disk, const char* folder_path, const char* filename, const char* ext);

#endif
