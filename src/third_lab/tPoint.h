#ifndef tPoint_H
#define tPoint_H

#endif

class tPoint
{
    private:
        float x;
        float y;
        float vx;
        float vy;
        float m;

    public:
        tPoint();
        tPoint(float x, float y, float vx, float vy, float m);
        float getX();
        float getY();
        float getVX();
        float getVY();
        float getM();
        void setX(float x);
        void setY(float y);
        void setVX(float vx);
        void setVY(float vy);
        void setM(float m);

};
