#include "bullet.h"

Bullet::Bullet(int sX, int sY, int speedX, int speedY, double res, Gun *g1, Gun *g2)
{
    gun1 = g1;
    gun2 = g2;
    startX = sX;
    startY = sY;
    setPos(sX - 5, sY - 5);
    t = 0;
    vX = speedX;
    vY = speedY;
    resis = res;
}

Bullet::~Bullet()
{

}
