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
    const int screenWidth = 1280;
    const int screenHeight = 720;
    /* 
        Define the different game modes
        ball mode when mode == 1
        1st person mode when mode == 2
    */
    const int mode = 1; 

    if (mode == 1) {
        Ball ball = Ball();
        Cubej cubej = Cubej();
        char fpsStr[16]; // Create FPS array
        printf("fpsStr size is %lld\n", sizeof(fpsStr));

        InitWindow(screenWidth, screenHeight, "Mantaray by Cool Co.");
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLACK);

            cubej.Update();
            cubej.Draw();
            ball.Update();
            ball.Draw();
            
            DrawText("Why... hello there.", 20, 20, 20, GOLD);
            
            // Draw FPS - need to check for truncation here later
            snprintf(fpsStr, sizeof(fpsStr), "FPS: %i", GetFPS()); // WARNING: Potential for issues here as if the fps is big enough then the buffer provided will be too small
            DrawText(fpsStr, 700, 20, 20, RED); // Draw FPS to screen

            EndDrawing();            
        }

        CloseWindow();
        return 0;
    }
}

