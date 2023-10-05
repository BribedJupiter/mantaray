#include <raylib.h>
#include <stdio.h>
#include "game/ball.h"
#include "game/cubej.h"
#include "game/collisionManager.h"

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
        ball mode when gameMode == 1
        1st person mode when gameMode == 2
    */
    const int gameMode = 1; 

    if (gameMode == 1) {
        Ball ball = Ball();
        Cubej cubej = Cubej();
        CollisionManager collisionManager = CollisionManager();
        char fpsStr[16]; // Create FPS array
        printf("fpsStr size is %lld\n", sizeof(fpsStr));
        int collisionStatus; // De initialize when implement collision
        int pause;
        bool oscillate;
        oscillate = false;
        bool canChangeOsccilate;

        InitWindow(screenWidth, screenHeight, "Mantaray by Cool Co.");
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            if (IsKeyUp(KEY_O)) 
            {
                canChangeOsccilate = true;
            }
            if (IsKeyDown(KEY_SPACE)) pause = 1; else pause = 0;
            if (IsKeyDown(KEY_O) && canChangeOsccilate == true) 
            {
                oscillate = !oscillate;
                printf("Oscillate is: %i\n", oscillate);
                canChangeOsccilate = false;
            }  
            
            BeginDrawing();
            ClearBackground(BLACK);

            if (pause == 0) {
                collisionStatus = collisionManager.checkCollision(ball, cubej);
                cubej.Update(collisionStatus, oscillate);
                ball.Update(collisionStatus, oscillate);
            }
            cubej.Draw();
            ball.Draw();
            
            DrawText("Why... hello there.\nPress o to toggle oscillation\nPress down to shrink\nPress space to pause\nLeft click to summom ball\nRight click to summon square", 20, 20, 15, GOLD);
            
            // Draw FPS - need to check for truncation here later
            snprintf(fpsStr, sizeof(fpsStr), "FPS: %i", GetFPS()); // WARNING: Potential for issues here as if the fps is big enough then the buffer provided will be too small
            DrawText(fpsStr, 1100, 20, 20, RED); // Draw FPS to screen

            EndDrawing();         
        }

        CloseWindow();
        return 0;
    }
}

