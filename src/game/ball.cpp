#include "ball.h"
#include <raylib.h>
#include <math.h>

Ball::Ball()
{
    x = 100.0f;
    y = 100.0f;
    speedX = 500.0f;
    speedY = 500.0f;
    radius = 15.0f;
}

void Ball::Update(int collisionStatus, int oscillate)
{   
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();\

    if (IsMouseButtonDown(0))
    {
        x = GetMouseX();
        y = GetMouseY();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        radius -= 1;
    } else if (oscillate == true)
    {
        radius += rand() % 15 - 5;
        if (radius <= 0) radius = 1;
    }

    if (x + radius >= GetScreenWidth() || x - radius <= 0 || collisionStatus == 1)
        speedX *= -1;

    if (y + radius >= GetScreenHeight() || y - radius <= 0 || collisionStatus == 1)
        speedY *= -1;

    bounds.x_left = x - radius;
    bounds.x_right = x + radius;
    bounds.y_top = y + radius;
    bounds.y_bottom = y - radius;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

Ball::~Ball() 
{
    // Put stuff to delete here
}