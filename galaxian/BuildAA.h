#ifndef BUILDAA_H
#define BUILDAA_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

void build_aa(std::vector < AquaAlien > & aa)
{
    int x = 50;
    for (int i = 0; i < NUM_AA; ++i)
    {
        aa.push_back(AquaAlien(x, H/4));
        aa[i].setAlive(true);
        x += 40;
    }
}


#endif
