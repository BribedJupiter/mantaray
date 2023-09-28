#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    x = 100.0f;
    y = 100.0f;
    speedX = 500.0f;
    speedY = 500.0f;
    radius = 15.0f;
}

void Ball::Update()
{   
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();

    if (IsMouseButtonDown(0))
    {
        x = GetMouseX();
        y = GetMouseY();
    }

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
        speedX *= -1;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
        speedY *= -1;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}