#include <raylib.h>
#include "ball.h"
#include "cubej.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball = Ball();
    Cubej cubej = Cubej();

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        cubej.Update();
        cubej.Draw();
        ball.Update();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}