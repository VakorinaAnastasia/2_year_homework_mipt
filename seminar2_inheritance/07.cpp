#include <raylib.h>
#include <vector>
#include <string>

class DropList {
private:
    Rectangle mMainRect;
    std::vector<std::string> mItems;
    int mSelected;
    bool mExpanded;
    int mHoveredIndex;

    Color mNormalColor;
    Color mHoverColor;
    Color mSelectedColor;

public:
    DropList(Vector2 position, float width, float height, const std::vector<std::string>& items)
        : mItems(items), mSelected(0), mExpanded(false), mHoveredIndex(-1)
    {
        mMainRect = { position.x, position.y, width, height };
        mNormalColor = { 173, 216, 230, 255 };
        mHoverColor = { 135, 206, 250, 255 };
        mSelectedColor = { 100, 149, 237, 255 };
    }

    void handleEvent() {
        Vector2 mouse = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        mHoveredIndex = -1;
        if (mExpanded) {
            for (size_t i = 0; i < mItems.size(); ++i) {
                Rectangle itemRect = { mMainRect.x, mMainRect.y + (i + 1) * mMainRect.height, mMainRect.width, mMainRect.height };
                if (CheckCollisionPointRec(mouse, itemRect)) {
                    mHoveredIndex = i;
                    break;
                }
            }
        } else {
            if (CheckCollisionPointRec(mouse, mMainRect)) {
                mHoveredIndex = -2;
            }
        }

        if (mousePressed) {
            if (mExpanded) {
                bool clickedOnItem = false;
                for (size_t i = 0; i < mItems.size(); ++i) {
                    Rectangle itemRect = { mMainRect.x, mMainRect.y + (i + 1) * mMainRect.height, mMainRect.width, mMainRect.height };
                    if (CheckCollisionPointRec(mouse, itemRect)) {
                        mSelected = i;
                        mExpanded = false;
                        clickedOnItem = true;
                        break;
                    }
                }
                if (!clickedOnItem) {
                    if (CheckCollisionPointRec(mouse, mMainRect)) {
                        mExpanded = false;
                    } else {
                        mExpanded = false;
                    }
                }
            } else {
                if (CheckCollisionPointRec(mouse, mMainRect)) {
                    mExpanded = true;
                }
            }
        }
    }

    void draw(Font font) const {
        Color mainColor = (mHoveredIndex == -2 && !mExpanded) ? mHoverColor : mSelectedColor;
        DrawRectangleRec(mMainRect, mainColor);
        DrawRectangleLinesEx(mMainRect, 1, BLACK);

        const char* text = mItems[mSelected].c_str();
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(font, text, fontSize, 1);
        DrawTextEx(font, text, { mMainRect.x + 5, mMainRect.y + (mMainRect.height - textSize.y) / 2 }, fontSize, 1, BLACK);

        float triangleSize = 10;
        Vector2 triangleCenter = { mMainRect.x + mMainRect.width - 15, mMainRect.y + mMainRect.height / 2 };
        if (mExpanded) {
            DrawTriangle(
                { triangleCenter.x, triangleCenter.y - triangleSize },
                { triangleCenter.x - triangleSize, triangleCenter.y + triangleSize },
                { triangleCenter.x + triangleSize, triangleCenter.y + triangleSize },
                BLACK
            );
        } else {
            DrawTriangle(
                { triangleCenter.x, triangleCenter.y + triangleSize },
                { triangleCenter.x - triangleSize, triangleCenter.y - triangleSize },
                { triangleCenter.x + triangleSize, triangleCenter.y - triangleSize },
                BLACK
            );
        }

        if (mExpanded) {
            for (size_t i = 0; i < mItems.size(); ++i) {
                Rectangle itemRect = { mMainRect.x, mMainRect.y + (i + 1) * mMainRect.height, mMainRect.width, mMainRect.height };
                Color color;
                if (i == mSelected) {
                    color = mSelectedColor;
                } else if (i == mHoveredIndex) {
                    color = mHoverColor;
                } else {
                    color = mNormalColor;
                }
                DrawRectangleRec(itemRect, color);
                DrawRectangleLinesEx(itemRect, 1, BLACK);

                const char* itemText = mItems[i].c_str();
                Vector2 textSize = MeasureTextEx(font, itemText, fontSize, 1);
                DrawTextEx(font, itemText, { itemRect.x + 5, itemRect.y + (itemRect.height - textSize.y) / 2 }, fontSize, 1, BLACK);
            }
        }
    }

    int getSelected() const { return mSelected; }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "DropList Example");
    SetTargetFPS(60);

    Font font = LoadFontEx("C:/Windows/Fonts/arial.ttf", 32, 0, 250);
    if (font.texture.id == 0) font = GetFontDefault();

    std::vector<std::string> items = {"Круг", "Квадрат", "Треугольник"};
    DropList list({ 300, 100 }, 200, 40, items);

    while (!WindowShouldClose()) {
        list.handleEvent();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        list.draw(font);

        int sel = list.getSelected();
        Vector2 shapeCenter = { 400, 450 };

        if (sel == 0) {
            DrawCircleV(shapeCenter, 80, WHITE);
            DrawCircleLines(shapeCenter.x, shapeCenter.y, 80, BLACK);
        } else if (sel == 1) {
            DrawRectangleV({ shapeCenter.x - 80, shapeCenter.y - 80 }, { 160, 160 }, WHITE);
            DrawRectangleLines(shapeCenter.x - 80, shapeCenter.y - 80, 160, 160, BLACK);
        } else {
            Vector2 p1 = { shapeCenter.x, shapeCenter.y - 80 };
            Vector2 p2 = { shapeCenter.x - 69.28f, shapeCenter.y + 40 };
            Vector2 p3 = { shapeCenter.x + 69.28f, shapeCenter.y + 40 };
            DrawTriangle(p1, p2, p3, WHITE);
            DrawTriangleLines(p1, p2, p3, BLACK);
        }

        EndDrawing();
    }

    UnloadFont(font);
    CloseWindow();
}
