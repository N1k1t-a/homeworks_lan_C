#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "");

	char str[100];
	char c;
	int i = 0;
	int kolvo_sim;
	int counter = 0;
	int rez = 0;

	printf("Input a string: \n");
	while ((c = getchar()) != '\n' && i < 99) {
		str[i] = c;
		i++;
	}
	str[i] = '\0';

	printf("Введите количество символов в слове: ");
	scanf("%d", &kolvo_sim);

	char word[100];
	int word_index = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && str[i] != '\0') {
			word[word_index] = str[i];
			word_index++;
			counter++;
		}
		else {
			if (counter == kolvo_sim) {
				rez++;
				word[word_index] = '\0';
				printf("%s\n", word);
			}
			word_index = 0;
			counter = 0;
		}
	}

	if (counter == kolvo_sim) {
		rez++;
		word[word_index] = '\0';
		printf("%s\n", word);
	}

	printf("Количество слов в строке с длиной %d символов: %d\n", kolvo_sim, rez);

	return 0;
}
