#include <stdio.h>

enum shape { ROCK, PAPER, SCISSORS };
enum result { LOSS, DRAW, WIN };

void print_shape(enum shape s) {
    if (s == ROCK) printf("Rock");
    if (s == PAPER) printf("Paper");
    if (s == SCISSORS) printf("Scissors");
}

void print_result(enum result r) {
    if (r == LOSS) printf("Loss");
    if (r == DRAW) printf("Draw");
    if (r == WIN) printf("Win");
}

enum result get_result(enum shape a, enum shape b) {
    if (a == b) return DRAW;
    if (a == ROCK && b == SCISSORS) return WIN;
    if (a == PAPER && b == ROCK) return WIN;
    if (a == SCISSORS && b == PAPER) return WIN;
    return LOSS;
}

enum shape get_strength(enum shape s) {
    if (s == ROCK) return SCISSORS;
    if (s == PAPER) return ROCK;
    if (s == SCISSORS) return PAPER;
    return ROCK;
}

int main() {
    char input1[10], input2[10];
    enum shape shape1, shape2;
    
    scanf("%s %s", input1, input2);
    
    if (input1[0] == 'R') shape1 = ROCK;
    else if (input1[0] == 'P') shape1 = PAPER;
    else if (input1[0] == 'S') shape1 = SCISSORS;
    
    if (input2[0] == 'R') shape2 = ROCK;
    else if (input2[0] == 'P') shape2 = PAPER;
    else if (input2[0] == 'S') shape2 = SCISSORS;
    
    enum result res = get_result(shape1, shape2);
    print_result(res);
}