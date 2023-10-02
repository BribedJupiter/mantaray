#pragma once

class Ball
{
    public:
        Ball();
        void Update();
        void Draw();
        struct BoundingBox;

    private:
        float x;
        float y;
        float speedX;
        float speedY;
        float radius;
};