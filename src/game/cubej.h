#pragma once

class Cubej
{
    public:
        Cubej();
        void Update(int collisionStatus);
        void Draw();
        struct BoundingBox {
            float x_left;
            float x_right;
            float y_top;
            float y_bottonm;
        } bounds;
        ~Cubej();

    private:
        float x;
        float w;
        float y;
        float h;
        float speedX;
        float speedY;
};