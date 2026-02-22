#include <raylib.h>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    int w = 600;
    int h = 600;
    InitWindow(w, h, "");
    SetTargetFPS(60);

    float rad = 28.0f;
    float px = w / 2;
    float py = h / 2;
    float sp = 280.0f;
    Color col = BLUE;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) px = px + sp * dt;
        if (IsKeyDown(KEY_LEFT)) px = px - sp * dt;
        if (IsKeyDown(KEY_UP)) py = py - sp * dt;
        if (IsKeyDown(KEY_DOWN)) py = py + sp * dt;
        if (IsKeyPressed(KEY_SPACE)) {
            unsigned char cr = GetRandomValue(0, 255);
            unsigned char cg = GetRandomValue(0, 255);
            unsigned char cb = GetRandomValue(0, 255);
            col = (Color){cr, cg, cb, 255};
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(px, py, rad, col);
        EndDrawing();
    }
    CloseWindow();
}