#ifndef GOLDALIEN_H
#define GOLDALIEN_H

#include "Constants.h"
#include "Includes.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "Alien.h"

#include <iostream>
#include <ctime>
#include <vector>


class GoldAlien : public Alien
{
protected:
    
    static Image gAlien;

public:
    
GoldAlien(int x, int y) : Alien(surface)
    {
        setAlienRect(gAlien.getRect());
        setAlienRectx(x);
        setAlienRecty(y);
        setspd(4);
        setAlive(true);
        setOgy(y);
    }


    void draw(Surface & surface)
    {
        surface.put_image(gAlien, alienRect());
    }

};

#endif
