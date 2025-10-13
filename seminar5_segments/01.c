#include <stdio.h>
#include <stdlib.h>

struct library {
    Book* books;
    int number_of_books;
};

typedef struct library Library;

struct book {
    char title[50];
    int pages;
    float price;
};

typedef struct book Book;

void library_create(Library* lib, int n) {
    lib->books = (Book*)malloc(n * sizeof(Book));
    lib->number_of_books = n;
}

void library_set(Library* lib, int index, const char* title, int pages, float price) {
    strcpy(lib->books[index].title, title);
    lib->books[index].pages = pages;
    lib->books[index].price = price;
}

void library_print(Library* lib, int index) {
    printf("%s %d %.1f\n", lib->books[index].title, lib->books[index].pages, lib->books[index].price);
}

void library_destroy(Library* lib) {
    free(lib->books);
}

int main() {
    Library lib;
    library_create(&lib, 3);
    library_set(&lib, 0, "Don Quixote", 1000, 75.0);
    library_set(&lib, 1, "Oblomov", 480, 25.0);
    library_set(&lib, 2, "The Odyssey", 500, 50.0);
    library_print(&lib, 0);
    library_destroy(&lib);
}