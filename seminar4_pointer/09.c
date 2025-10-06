#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used)
{
    char temp[26] = {0};
    int count = 0;
    
    for (; *str; str++) {
        if (isalpha(*str)) {
            char c = tolower(*str);
            if (!temp[c - 'a']) {
                temp[c - 'a'] = 1;
                count++;
            }
        }
    }
    
    char* p = used;
    for (char c = 'a'; c <= 'z'; c++) {
        if (temp[c - 'a']) {
            *p++ = c;
        }
    }
    *p = '\0';
}

int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "123!%@");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
}