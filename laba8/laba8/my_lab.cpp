#include "my_lab.h"
#include <cstring> 

void ltoao(long num, char s[]) {
    if (num == 0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    int i = 0;
    bool isNegative = (num < 0);

    if (isNegative) num = -num;  

    while (num > 0) {
        s[i++] = (num % 8) + '0'; 
        num /= 8;
    }

    if (isNegative) s[i++] = '-';  

    s[i] = '\0';


    int len = strlen(s);
    for (int j = 0; j < len / 2; j++) {
        char temp = s[j];
        s[j] = s[len - j - 1];
        s[len - j - 1] = temp;
    }

}

void sixt(long num, char s[]) {
    if (num == 0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    int i = 0;
    bool isNegative = (num < 0);

    if (isNegative) num = -num;

    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            s[i++] = remainder + '0';  
        }
        else {
            s[i++] = remainder - 10 + 'A';  
        }
        num /= 16;
    }

    if (isNegative) s[i++] = '-';

    s[i] = '\0';

    int len = strlen(s);
    for (int j = 0; j < len / 2; j++) {
        char temp = s[j];
        s[j] = s[len - j - 1];
        s[len - j - 1] = temp;
    }
}