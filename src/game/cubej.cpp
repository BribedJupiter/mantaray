#include "cubej.h"
#include <raylib.h>
#include <math.h>

Cubej::Cubej()
{
    x = 100.0f;
    y = 100.0f;
    w = 20.0f;
    h = 20.0f;
    speedX = 500.0f;
    speedY = 500.0f;

}

void Cubej::Update(int collisionStatus, int oscillate)
{
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();

    if (IsKeyDown(KEY_DOWN)) 
    {
        w -= 1;
        h -= 1;
    } else if (oscillate == true) 
    {
        w += rand() % 15 - 5;
        h += rand() % 15 - 5;

        if (w <= 0) w = 1;
        if (h <= 0) h = 1;
    }

    if (IsMouseButtonDown(1))
    {
        x = GetMouseX();
        y = GetMouseY();
    }

    if (x + w >= GetScreenWidth() || x <= 0)
        speedX *= -1;
    if (y + h >= GetScreenHeight() || y <= 0)
        speedY *= -1;

    bounds.x_left = x - w;
    bounds.x_right = x + w;
    bounds.y_top = y + h;
    bounds.y_bottonm = y -h;
}

void Cubej::Draw()
{
    DrawRectangle(x, y, w, h, RED);
}

Cubej::~Cubej() 
{
    // Stuff for when deconstruct
};