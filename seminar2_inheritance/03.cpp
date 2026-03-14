#include <raylib.h>

class Draggable {
protected:
    Rectangle mRect{};
    Color mColor{};
    bool mIsDragged{false};
    Vector2 mOffset{0,0};
public:
    Draggable(Vector2 position, Vector2 size, Color color) : mColor{color} {
        mRect.x = position.x; mRect.y = position.y;
        mRect.width = size.x; mRect.height = size.y;
    }
    bool onMousePressed(Vector2 mousePosition) {
        if (CheckCollisionPointRec(mousePosition, mRect)) {
            mIsDragged = true;
            mOffset.x = mousePosition.x - mRect.x;
            mOffset.y = mousePosition.y - mRect.y;
        }
        return mIsDragged;
    }
    void onMouseReleased() { mIsDragged = false; }
    void onMouseMoved(Vector2 mousePosition) {
        if (mIsDragged) {
            mRect.x = mousePosition.x - mOffset.x;
            mRect.y = mousePosition.y - mOffset.y;
        }
    }
    void handleEvents() {
        Vector2 mouse = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) onMousePressed(mouse);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) onMouseReleased();
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || GetMouseDelta().x != 0 || GetMouseDelta().y != 0)
            onMouseMoved(mouse);
    }
    void setColor(Color c) { mColor = c; }
    void draw() const { DrawRectangleRec(mRect, mColor); }
};

class DraggableWithColorChange : public Draggable {
    Color baseColor, dragColor;
public:
    DraggableWithColorChange(Vector2 position, Vector2 size, Color base, Color drag)
        : Draggable(position, size, base), baseColor(base), dragColor(drag) {}
    void handleEvents() {
        Draggable::handleEvents();
        setColor(mIsDragged ? dragColor : baseColor);
    }
};

int main() {
    InitWindow(800, 600, "Draggable Color Change");
    SetTargetFPS(60);
    DraggableWithColorChange d{{100,100}, {200,150}, RED, BLUE};
    while (!WindowShouldClose()) {
        d.handleEvents();
        BeginDrawing();
        ClearBackground(BLACK);
        d.draw();
        EndDrawing();
    }
    CloseWindow();
}