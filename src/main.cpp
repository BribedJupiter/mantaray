#include <raylib.h>
#include "game/ball.h"
#include "game/cubej.h"

/*
    This will be the entry point of the application as well
    as where we will initialize it.
*/

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