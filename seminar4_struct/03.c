#include <stdio.h>
#include <string.h>

#define MAX_GAMES 100
#define MAX_TITLE 100

typedef struct {
    char title[MAX_TITLE];
    double avg;
} Game;

int main() {
    int n;
    scanf("%d\n", &n);
    Game games[MAX_GAMES];
    for (int i = 0; i < n; i++) {
        char temp;
        int k;
        double sum = 0;
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        games[i].avg = sum / k;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (games[i].avg < games[j].avg) {
                Game tmp = games[i];
                games[i] = games[j];
                games[j] = tmp;
            }
    for (int i = 0; i < n; i++)
        printf("%s, %.3f\n", games[i].title, games[i].avg);
}
