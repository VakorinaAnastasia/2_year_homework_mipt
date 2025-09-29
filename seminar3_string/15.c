#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Error: Wrong number of arguments!\nUsage: %s <input_file> <output_file> <lines>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        fprintf(stderr, "Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    char *spec = argv[3];
    int start, end;
    char *colon = strchr(spec, ':');
    
    if (colon) {
        *colon = '\0';
        if (!*spec || !*(colon+1) || !isdigit(*spec) || !isdigit(*(colon+1))) {
            fprintf(stderr, "Error: Wrong lines format!\n");
            fclose(input);
            return 1;
        }
        start = atoi(spec);
        end = atoi(colon+1);
        *colon = ':';
        if (start >= end) {
            fprintf(stderr, "Error: Wrong lines format!\n");
            fclose(input);
            return 1;
        }
    } else {
        for (char *p = spec; *p; p++) {
            if (!isdigit(*p)) {
                fprintf(stderr, "Error: Wrong lines format!\n");
                fclose(input);
                return 1;
            }
        }
        start = atoi(spec);
        end = start + 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        fprintf(stderr, "Error: Cannot create output file!\n");
        fclose(input);
        return 1;
    }

    char line[1024];
    for (int i = 1; fgets(line, sizeof(line), input) && i < end; i++) {
        if (i >= start) fputs(line, output);
    }

    fclose(input);
    fclose(output);
}