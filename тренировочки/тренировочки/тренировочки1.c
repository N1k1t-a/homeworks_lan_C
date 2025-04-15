#include <stdio.h>
#include <stdlib.h>

void slova(char *str,char *dinamicArr, int len,int i);

main() {
	char str[] = "Dynamic memory allocation in C is fun!";
	int i = 0;
	int len = 0;
	char *dinamicArr = NULL;

	while (str[i] != '\0') {
		while (str[i] != ' ' && str[i] != '\0') {
			len++;
			i++;
		}
		dinamicArr = malloc(sizeof(char) * (len+1));
		slova(str, dinamicArr, len, i);
		free(dinamicArr);
		len = 0;
		if (str[i] == ' ') i++;

	}

	return 0;
}

void slova(char* str, char* dinamicArr, int len, int i) {
	int size_word = i - len;
	for (int j = 0;  j < len; j++) {
		dinamicArr[j] = str[size_word + j];
	}

	dinamicArr[len] = '\0';

	printf("%s\n", dinamicArr);
}