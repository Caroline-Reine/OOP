#include "tPoint.h"

tPoint::tPoint(float x, float y, float vx, float vy, float m)
{
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->m = m;
}

float tPoint::getM()
{
    return this->m;
}

float tPoint::getX()
{
    return this->x;
}

float tPoint::getY()
{
    return this->y;
}

float tPoint::getVX()
{
    return this->vx;
}

float tPoint::getVY()
{
    return this->vy;
}

void tPoint::setM(float m)
{
    if (m < 1) this->m = 1;
    else this->m = m;
}

void tPoint::setX(float x)
{
    this->x = x;
}

void tPoint::setY(float y)
{
    this->y = y;
}

void tPoint::setVX(float vx)
{
    this->vx = vx;
}

void tPoint::setVY(float vy)
{
    this->vy = vy;
}
