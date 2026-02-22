#include <raylib.h>

int main() {
    int width = 600;
    int height = 600;
    InitWindow(width, height, "");
    SetTargetFPS(60);

    Rectangle box = { 220, 220, 160, 160 };

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        Color currentColor = GREEN;
        if (CheckCollisionPointRec(mouse, box)) {
            currentColor = RED;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(box, currentColor);
        EndDrawing();
    }
    CloseWindow();
}