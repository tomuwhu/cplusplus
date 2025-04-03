#include <raylib.h>

int main() {
    SetTargetFPS(300);
    const int wx = 1280, wy = 877, r=20;
    InitWindow(wx, wy, "Raylib - Kör");
    double x = 0, y = 0, vx = 1, vy = 1;
    while (!WindowShouldClose()) {
        x += vx;
        y += vy;
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(x, y, 20, YELLOW);
        if (x > wx - r) {
            vx = -1;
        }
        if (x < r) {
            vx = 1;
        }
        if (y > wy - r) {
            vy = -1;
        }
        if (y < r) {
            vy = 1;
        }
        DrawText("Dr. Németh Tamás", 20, 20, 120, GREEN);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}