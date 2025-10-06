#include <stdio.h>
#include <stddef.h>

struct cat { char x; size_t y; };
struct dog { size_t y; char x; };
struct mouse { char x; char y; size_t z; };
struct rat { char x; size_t z; char y; };
struct fox { char x; struct mouse y; };

int main() {
    printf("char: size=%zu align=%zu\n", sizeof(char), _Alignof(char));
    printf("int: size=%zu align=%zu\n", sizeof(int), _Alignof(int));
    printf("size_t: size=%zu align=%zu\n", sizeof(size_t), _Alignof(size_t));
    printf("int[10]: size=%zu align=%zu\n", sizeof(int[10]), _Alignof(int[10]));
    printf("int*: size=%zu align=%zu\n", sizeof(int*), _Alignof(int*));
    printf("struct cat: size=%zu align=%zu\n", sizeof(struct cat), _Alignof(struct cat));
    printf("struct dog: size=%zu align=%zu\n", sizeof(struct dog), _Alignof(struct dog));
    printf("struct mouse: size=%zu align=%zu\n", sizeof(struct mouse), _Alignof(struct mouse));
    printf("struct rat: size=%zu align=%zu\n", sizeof(struct rat), _Alignof(struct rat));
    printf("struct fox: size=%zu align=%zu\n", sizeof(struct fox), _Alignof(struct fox));
}
