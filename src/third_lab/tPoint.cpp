#include "tPoint.h"

tPoint::tPoint()
{
    this->vx = -100 + rand() % 200;
    this->vy = -100 + rand() % 200;
    this->m = 2;
    this->x = this->m + 1 + rand() % 480;
    this->y = this->m + 1 + rand() % 480;
}

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

void tPoint::move(float DT)
{
    this->setX(this->getX() + (this->getVX() * DT));
    this->setY(this->getY() + (this->getVY() * DT));
}
void tPoint::chaoticMove()
{
    if (rand() % 2) {
        this->vx = -150+ rand() % 301;
        this->vy = -150 + rand() % 301;
        //this->x = this->x + (this->vx * (DT / DT)) * ((rand() % 3) ? (1) : (-1));
        //this->y = this->y + (this->vy * (DT / DT)) * ((rand() % 3) ? (1) : (-1));
    }
}

void tPoint::reverseVX()
{
    this->vx *= (-1);
}
void tPoint::reverseVY()
{
    this->vy *= (-1);
}
