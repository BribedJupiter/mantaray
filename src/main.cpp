#include <raylib.h>
#include <stdio.h>
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
    /* 
        Define the different game modes
        ball mode when mode == 1
        1st person mode when mode == 2
    */
    const int mode = 1; 

    if (mode == 1) {
        Ball ball = Ball();
        Cubej cubej = Cubej();

        InitWindow(screenWidth, screenHeight, "Mantaray by Cool Co.");
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {

            BeginDrawing();
            ClearBackground(BLACK);
            
            DrawText("Why... hello there.", 20, 20, 20, GOLD);
            // Draw FPS
            char fpsStr[] = {16}; // Create FPS array
            sprintf(fpsStr, "FPS: %i", GetFPS()); // Get FPS value and build the string
            DrawText(fpsStr, 700, 20, 20, RED); // Draw FPS to screen

            cubej.Update();
            cubej.Draw();
            ball.Update();
            ball.Draw();

            EndDrawing();
            
        }

        CloseWindow();
        return 0;
    }
}

