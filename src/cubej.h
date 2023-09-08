#pragma once

class Cubej
{
    public:
        Cubej();
        void Update();
        void Draw();

    private:
        int x;
        int w;
        int y;
        int h;
        int speedX;
        int speedY;
};