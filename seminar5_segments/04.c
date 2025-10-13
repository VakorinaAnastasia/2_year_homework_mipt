#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** a = malloc(4 * sizeof(char*));
    a[0] = strdup("Cat");
    a[1] = strdup("Elephant");
    a[2] = strdup("Mouse");
    a[3] = NULL;
    return a;
}

void print_strings(const char** a) {
    while (*a) printf("%s\n", *a++);
}

size_t* get_sizes(const char** a) {
    int n = 0;
    while (a[n]) n++;
    size_t* s = malloc(n * sizeof(size_t));
    for (int i = 0; i < n; i++) s[i] = strlen(a[i]);
    return s;
}

char** load_lines(const char* fname) {
    FILE* f = fopen(fname, "r");
    if (!f) return NULL;
    
    int n = 0;
    char buf[1000];
    while (fgets(buf, 1000, f)) n++;
    
    char** lines = malloc((n + 1) * sizeof(char*));
    fseek(f, 0, SEEK_SET);
    
    for (int i = 0; i < n; i++) {
        fgets(buf, 1000, f);
        buf[strcspn(buf, "\n")] = 0;
        lines[i] = strdup(buf);
    }
    lines[n] = NULL;
    
    fclose(f);
    return lines;
}

void destroy_strings(char*** a) {
    for (int i = 0; (*a)[i]; i++) free((*a)[i]);
    free(*a);
    *a = NULL;
}

void sort_strings(char** a) {
    int n = 0;
    while (a[n]) n++;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i], a[j]) > 0) {
                char* t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main(int argc, char** argv) {
    if (argc < 3) return 1;
    
    char** lines = load_lines(argv[1]);
    sort_strings(lines);
    
    FILE* out = fopen(argv[2], "w");
    for (int i = 0; lines[i]; i++) fprintf(out, "%s\n", lines[i]);
    fclose(out);
    
    destroy_strings(&lines);
}