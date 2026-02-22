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
    float vx = 0.0f;
    float vy = 0.0f;
    float acc = 480.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 ms = GetMousePosition();
            float dx = ms.x - ballX;
            float dy = ms.y - ballY;
            float dist = sqrtf(dx*dx + dy*dy);
            if (dist > 0.5f) {
                vx = vx + (dx / dist) * acc * dt;
                vy = vy + (dy / dist) * acc * dt;
            }
        }
        ballX = ballX + vx * dt;
        ballY = ballY + vy * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(ballX, ballY, ballR, DARKGREEN);
        EndDrawing();
    }
    CloseWindow();
}