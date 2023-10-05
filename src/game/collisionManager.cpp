#include <raylib.h>
#include <stdio.h>
#include "ball.h"
#include "cubej.h"
#include "collisionManager.h"

CollisionManager::CollisionManager()
{
    // Constructor here
}

CollisionManager::~CollisionManager()
{
    // Deconstructor here
}

int CollisionManager::checkCollision(Ball& ball, Cubej& cubej)
{
    // Cases where ball is in cubej
    if (ball.bounds.y_top > cubej.bounds.y_bottonm && ball.bounds.x_left < cubej.bounds.x_right && ball.bounds.x_right > cubej.bounds.x_right && ball.bounds.y_bottom < cubej.bounds.y_bottonm)
    {
        printf("Colliding!\n");
        return 1;
    }
    // Cases where cubej is in ball
    return 0;
}