#include <raylib.h>

class Slider {
private:
    Rectangle mTrack;
    Rectangle mThumb;
    bool mIsPressed;
    float mMinX, mMaxX;
    float mValue;

public:
    Slider(Vector2 center, float trackWidth, float trackHeight, float thumbWidth, float thumbHeight)
        : mIsPressed(false), mValue(50.0f)
    {
        mTrack = { center.x - trackWidth/2, center.y - trackHeight/2, trackWidth, trackHeight };
        mThumb = { center.x - thumbWidth/2, center.y - thumbHeight/2, thumbWidth, thumbHeight };
        mMinX = mTrack.x;
        mMaxX = mTrack.x + mTrack.width - mThumb.width;
    }

    void handleEvents() {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mouse, mThumb) || CheckCollisionPointRec(mouse, mTrack)) {
                mIsPressed = true;
            }
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            mIsPressed = false;
        }

        if (mIsPressed && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            float newX = mouse.x - mThumb.width / 2;
            if (newX < mMinX) newX = mMinX;
            if (newX > mMaxX) newX = mMaxX;
            mThumb.x = newX;
            mValue = (mThumb.x - mMinX) / (mMaxX - mMinX) * 100.0f;
        }
    }

    void draw() const {
        DrawRectangleRec(mTrack, { 200, 200, 220, 255 });
        DrawRectangleRec(mThumb, { 150, 150, 240, 255 });
    }

    float getValue() const { return mValue; }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "RGB Circle with Raylib");
    SetTargetFPS(60);

    Slider sliderR({150, 150}, 300, 20, 30, 60);
    Slider sliderG({150, 300}, 300, 20, 30, 60);
    Slider sliderB({150, 450}, 300, 20, 30, 60);

    Vector2 circleCenter = { 550, 300 };
    float circleRadius = 150;

    while (!WindowShouldClose()) {
        sliderR.handleEvents();
        sliderG.handleEvents();
        sliderB.handleEvents();

        unsigned char r = (unsigned char)(sliderR.getValue() * 2.55f);
        unsigned char g = (unsigned char)(sliderG.getValue() * 2.55f);
        unsigned char b = (unsigned char)(sliderB.getValue() * 2.55f);
        Color circleColor = { r, g, b, 255 };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        sliderR.draw();
        sliderG.draw();
        sliderB.draw();

        DrawCircleV(circleCenter, circleRadius, circleColor);

        EndDrawing();
    }

    CloseWindow();
}
