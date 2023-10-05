#pragma once

class Ball
{
    public:
        Ball();
        void Update(int collisionStatus);
        void Draw();
        struct BoundingBox {
            float x_left;
            float x_right;
            float y_top;
            float y_bottonm;
        } bounds;
        ~Ball();

    private:
        float x;
        float y;
        float speedX;
        float speedY;
        float radius;
};