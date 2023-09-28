#include "cubej.h"
#include <raylib.h>

Cubej::Cubej()
{
    x = 100.0f;
    y = 100.0f;
    w = 20.0f;
    h = 20.0f;
    speedX = 500.0f;
    speedY = 500.0f;
}

void Cubej::Update()
{
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();

    if (IsMouseButtonDown(1))
    {
        x = GetMouseX();
        y = GetMouseY();
    }

    if (x + w >= GetScreenWidth() || x <= 0)
        speedX *= -1;
    if (y + h >= GetScreenHeight() || y <= 0)
        speedY *= -1;
}

void Cubej::Draw()
{
    DrawRectangle(x, y, w, h, RED);
}