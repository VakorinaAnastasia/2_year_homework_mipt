#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Error: Wrong number of arguments!\nUsage: %s <number> <operator> <number>\n", argv[0]);
        return 1;
    }

    char op = argv[2][0];
    if (argv[2][1] != '\0' || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')) {
        fprintf(stderr, "Error: Invalid operator!\n");
        return 1;
    }

    int num1, num2;
    if (sscanf(argv[1], "%d", &num1) != 1 || sscanf(argv[3], "%d", &num2) != 1) {
        fprintf(stderr, "Error: Operands should be integers!\n");
        return 1;
    }

    if ((op == '/' || op == '%') && num2 == 0) {
        fprintf(stderr, "Error: Division by zero!\n");
        return 1;
    }

    int result;
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        case '%': result = num1 % num2; break;
    }

    printf("%d\n", result);
}