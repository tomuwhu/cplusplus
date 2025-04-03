#include <raylib.h>

int main() {
    SetTargetFPS(300);
    const int wx = 1280, wy = 877;
    InitWindow(wx, wy, "Raylib - Kör");
    double x = 0, y = 0, vx = 1, vy = 1;
    while (!WindowShouldClose()) {
        x += vx;
        y += vy;
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(x, y, 20, YELLOW);
        if (x > wx) {
            vx = -1;
        }
        if (x < 0) {
            vx = 1;
        }
        if (y > wy) {
            vy = -1;
        }
        if (y < 0) {
            vy = 1;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}