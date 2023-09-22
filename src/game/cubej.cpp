#include "cubej.h"
#include <raylib.h>

Cubej::Cubej()
{
    x = 100;
    y = 100;
    w = 20;
    h = 20;
    speedX = 10;
    speedY = 10;
}

void Cubej::Update()
{
    x += speedX;
    y += speedY;

    if (x + w >= GetScreenWidth() || x <= 0)
        speedX *= -1;
    if (y + h >= GetScreenHeight() || y <= 0)
        speedY *= -1;
}

void Cubej::Draw()
{
    DrawRectangle(x, y, w, h, RED);
}