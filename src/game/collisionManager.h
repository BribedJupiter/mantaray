#pragma once
#include "ball.h"
#include "cubej.h"

class CollisionManager
{
    public:
        CollisionManager();
        ~CollisionManager();
        int checkCollision(Ball& ball, Cubej& cubej);
};