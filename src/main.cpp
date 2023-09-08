#include <raylib.h>
#include "ball.h"
#include "cubej.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball = Ball();
    Cubej cubej = Cubej();

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawText("Why... hello there.", 20, 20, 20, GOLD);

        cubej.Update();
        cubej.Draw();
        ball.Update();
        ball.Draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}