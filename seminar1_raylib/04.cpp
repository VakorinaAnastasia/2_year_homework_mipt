#include <raylib.h>
#include <math.h>

int main() {
    int sw = 600;
    int sh = 600;
    InitWindow(sw, sh, "");
    SetTargetFPS(60);

    float cx = sw / 2;
    float cy = sh / 2;
    float orbit = 130.0f;
    float smallR = 18.0f;
    float phi = 0.0f;
    float omega = 95.0f;

    while (!WindowShouldClose()) {
        phi = phi + omega * GetFrameTime() * DEG2RAD;
        float px = cx + orbit * cosf(phi);
        float py = cy + orbit * sinf(phi);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(px, py, smallR, PURPLE);
        EndDrawing();
    }
    CloseWindow();
}