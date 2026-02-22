#include <raylib.h>
#include <string>

int main() {
    int W = 600;
    int H = 600;
    InitWindow(W, H, "");
    SetTargetFPS(60);

    while (WindowShouldClose() == 0) {
        Vector2 m = GetMousePosition();
        std::string s = "X:" + std::to_string((int)m.x) + " Y:" + std::to_string((int)m.y);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(s.c_str(), 15, 15, 22, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
}