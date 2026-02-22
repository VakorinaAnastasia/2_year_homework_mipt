#include <raylib.h>
#include <math.h>

int main() {
    int sx = 600;
    int sy = 600;
    InitWindow(sx, sy, "");
    SetTargetFPS(60);

    float ballR = 22.0f;
    float ballX = sx / 2;
    float ballY = sy / 2;
    float velConst = 190.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 ms = GetMousePosition();
            float dx = ms.x - ballX;
            float dy = ms.y - ballY;
            float dist = sqrtf(dx*dx + dy*dy);
            if (dist > 0.5f) {
                ballX = ballX + (dx / dist) * velConst * dt;
                ballY = ballY + (dy / dist) * velConst * dt;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(ballX, ballY, ballR, ORANGE);
        EndDrawing();
    }
    CloseWindow();
}