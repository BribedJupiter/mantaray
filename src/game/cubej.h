#pragma once

class Cubej
{
    public:
        Cubej();
        void Update();
        void Draw();

    private:
        float x;
        float w;
        float y;
        float h;
        float speedX;
        float speedY;
};