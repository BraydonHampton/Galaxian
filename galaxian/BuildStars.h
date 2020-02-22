#ifndef BUILDSTARS_H
#define BUILDSTARS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

void init_stars(std::vector < Stars > & s)
{
        srand((unsigned int) time(NULL));
        for (int i = 0; i < NUM_STARS; ++i)
        {
            int factor = 1 + rand() % 2;
            int x = rand() % W;
            int y = rand() % H;

            s[i].setx(x);
            s[i].sety(y);
            s[i].setw(factor);
        }
        s.shrink_to_fit();
}

void draw_stars(std::vector < Stars > & s, Surface & surface)
{
    //srand((unsigned int) time(NULL));
    for(int i = 0; i < NUM_STARS; ++i)
    {
        // move
        s[i].sety(s[i].y() + s[i].w());

        // if off screen
        if (s[i].y() > H - 1)
        {
            int factor = rand() % 2 + 1;
            int x = rand() % W;
            s[i].sety(0);
            s[i].setx(x);
            s[i].setw(factor);
            // draw
            //          s[i].print();
        }

                
        surface.put_rect(s[i].x(), s[i].y(), s[i].w(), s[i].w(), WHITE);
    }
}

#endif
