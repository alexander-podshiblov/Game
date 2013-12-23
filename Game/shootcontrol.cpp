#include "shootcontrol.h"

ShootControl::ShootControl()
{
    firePlayer = 1;
    isReady = true;
}

int ShootControl::whoShoot()
{
    return firePlayer;
}

bool ShootControl::isReadyForShoot()
{
    return isReady;
}

void ShootControl::wasShoot()
{
    if (firePlayer == 1)
        firePlayer = 2;
    else
        firePlayer = 1;
    isReady = false;
}

void ShootControl::setReady()
{
    isReady = true;
}
