#pragma once

class Ball
{
    public:
        Ball();
        void Update(int collisionStatus, int oscillate);
        void Draw();
        struct BoundingBox {
            float x_right;
            float x_left;
            float y_top;
            float y_bottom;
        } bounds;
        ~Ball();

    private:
        float x;
        float y;
        float speedX;
        float speedY;
        float radius;
};