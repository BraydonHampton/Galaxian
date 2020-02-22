#ifndef BUILDLAZERS_H
#define BUILDLAZERS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

void build_lazers(std::vector < Lazer > & l)
{
    for (int i = 0; i < NUM_LAZ; ++i)
    {
        l.push_back(Lazer(0, 0));
    }
}

void init_lazers(std::vector < Lazer > & l, int x, int y, int i)
{
    // init
    l[i].setx(x);
    l[i].sety(y);
    l[i].setw(2);
    l[i].seth(12);
    l[i].setspd(5);
    l[i].set_alive(true);   
}

void draw_lazers(std::vector < Lazer > & l, Surface & surface, int i)
{

    
        // move
        l[i].sety(l[i].y() - l[i].speed());


        // draw
        surface.put_rect(l[i].x(), l[i].y(), l[i].w(), l[i].h(), RED);
    
}



#endif
