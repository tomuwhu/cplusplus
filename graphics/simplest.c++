#include <raylib.h>
#include <iostream>

int main() {
  SetTargetFPS( 300 );
  const int wx = 1280, wy = 877, r=20;
  InitWindow(wx, wy, "Raylib - Kör");
  double x = 100, y = 200, vx = 1, vy = 1;
  int mx = 100, my = 200;
  while ( !WindowShouldClose() ) {
    x += vx;
    y += vy;
    BeginDrawing();      
    HideCursor();
    ClearBackground( BLACK );
    if ( IsMouseButtonDown( 0 ) ) {
      mx = GetMouseX();
      my = GetMouseY();
      vx += ( mx - x ) / 10000.0;
      vy += ( my - y ) / 10000.0;
    } else {
      mx = GetMouseX();
      my = GetMouseY();
    }
    DrawCircleLines( mx, my, 20, GREEN );
    DrawCircle(x, y, 20, YELLOW);
    if ( x > wx - r || x < r ) vx = -vx; 
    if ( y > wy - r || y < r) vy = -vy;
    DrawText( "Dr. Németh Tamás", 20, 20, 80, GREEN );
    DrawFPS( 1100, 800 );
    EndDrawing();
  }
  CloseWindow();
  std::cout << "Bye..." << std::endl; 
  return 0;
}