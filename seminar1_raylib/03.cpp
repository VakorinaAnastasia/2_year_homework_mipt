#include <raylib.h>
#include <math.h>

int main() {
    int w = 600;
    int h = 600;
    InitWindow(w, h, "");
    SetTargetFPS(60);

    float a = 100.0f;
    float rotX = 300.0f;
    float rotY = 300.0f;
    float deg = 0.0f;
    float rotSpeed = 80.0f;

    while (!WindowShouldClose()) {
        deg = deg + rotSpeed * GetFrameTime();

        float rad = deg * DEG2RAD;
        float c = cosf(rad);
        float s = sinf(rad);

        float x2 = rotX + a;
        float y2 = rotY;
        float x3 = rotX + a;
        float y3 = rotY + a;
        float x4 = rotX;
        float y4 = rotY + a;

        float rx2 = rotX + (x2 - rotX) * c - (y2 - rotY) * s;
        float ry2 = rotY + (x2 - rotX) * s + (y2 - rotY) * c;
        float rx3 = rotX + (x3 - rotX) * c - (y3 - rotY) * s;
        float ry3 = rotY + (x3 - rotX) * s + (y3 - rotY) * c;
        float rx4 = rotX + (x4 - rotX) * c - (y4 - rotY) * s;
        float ry4 = rotY + (x4 - rotX) * s + (y4 - rotY) * c;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLine(rotX, rotY, rx2, ry2, DARKBLUE);
        DrawLine(rx2, ry2, rx3, ry3, DARKBLUE);
        DrawLine(rx3, ry3, rx4, ry4, DARKBLUE);
        DrawLine(rx4, ry4, rotX, rotY, DARKBLUE);
        EndDrawing();
    }
    CloseWindow();
}