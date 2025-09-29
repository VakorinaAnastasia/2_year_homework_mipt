#include <stdio.h>
#include <stdlib.h>

void encrypt_file(FILE *input, FILE *output, int key) {
    key = key % 26;
    if (key < 0) key += 26;
    
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + key) % 26;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + key) % 26;
        }
        fputc(ch, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    int key = atoi(argv[3]);
    
    if (!input || !output) {
        fprintf(stderr, "Error: Cannot open files\n");
        return 1;
    }
    
    encrypt_file(input, output, key);
    
}