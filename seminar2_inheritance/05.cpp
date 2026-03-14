#include <raylib.h>
#include <vector>

class Toggle {
private:
    Rectangle mRect;
    bool mState;
    Color mOnColor;
    Color mOffColor;
    float mRadius;

public:
    Toggle(Vector2 position, Vector2 size, bool initialState = false)
        : mState(initialState), mOnColor(GREEN), mOffColor(LIGHTGRAY)
    {
        mRect = { position.x, position.y, size.x, size.y };
        mRadius = size.y / 2.0f - 2.0f;
    }

    void setPosition(Vector2 position) {
        mRect.x = position.x;
        mRect.y = position.y;
    }

    void handleEvent() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            if (CheckCollisionPointRec(mouse, mRect)) {
                mState = !mState;
            }
        }
    }

    void draw() const {
        Color bgColor = mState ? mOnColor : mOffColor;
        float roundness = 0.5f;
        DrawRectangleRounded(mRect, roundness, 0, bgColor);
        DrawRectangleRoundedLines(mRect, roundness, 0, WHITE);

        float handleX = mState ? mRect.x + mRect.width - mRadius - 2 : mRect.x + mRadius + 2;
        float handleY = mRect.y + mRect.height / 2;
        DrawCircle(handleX, handleY, mRadius, WHITE);
    }
};

int main() {
    InitWindow(800, 800, "Toggles with Raylib");
    SetTargetFPS(60);

    std::vector<Toggle> toggles;
    float toggleWidth = 80;
    float toggleHeight = 40;
    for (int i = 0; i < 10; ++i) {
        toggles.emplace_back(Vector2{0, 0}, Vector2{toggleWidth, toggleHeight}, false);
    }

    while (!WindowShouldClose()) {
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        float startY = screenHeight * 0.1f;
        float spacing = toggleHeight * 1.5f;
        for (int i = 0; i < 10; ++i) {
            float x = (screenWidth - toggleWidth) / 2;
            float y = startY + i * spacing;
            toggles[i].setPosition({x, y});
        }

        for (auto& t : toggles) {
            t.handleEvent();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (const auto& t : toggles) {
            t.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
