#include <raylib.h>

int main() {
    const int screenWidth = 00;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "");
    SetTargetFPS(60);

    float radius = 30.0f;
    float x = radius;
    float y = screenHeight / 2.0f;
    float speed = 200.0f;

    while (!WindowShouldClose()) {
        x += speed * GetFrameTime();
        if (x > screenWidth + radius) x = -radius;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV({x, y}, radius, RED);
        EndDrawing();
    }
    CloseWindow();
}