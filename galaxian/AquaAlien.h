#ifndef AQUAALIEN_H
#define AQUAALIEN_H

#include "Constants.h"
#include "Includes.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "Alien.h"

#include <iostream>
#include <ctime>
#include <vector>


class AquaAlien : public Alien
{
protected:
//    Rect AAship;
//    int score;
    static Image aAlien;

public:
    
AquaAlien(int x, int y) : Alien(surface)
    {
//        AAship = aAlien.getRect();
//        AAship.x = x;        
//        AAship.y = y;
        setAlienRect(aAlien.getRect());
        setAlienRectx(x);
        setAlienRecty(y);
        setspd(4);
        setAlive(true);
        setOgy(y);
        //  score = 20;
    }

    //  Rect getAA() {return alienRect();}
    //int score() {}

    void draw(Surface & surface)
    {
        surface.put_image(aAlien, alienRect());
    }

    /*  void move_left()
    {
//        AAship.x -= speed();
        setAlienRectx(alienRect().x - speed());
        
    }

    
    void move_right()
    {
//        AAship.x += speed();
        setAlienRecty(alienRect().y - speed());
    }
*/
/*    bool alienCol(Lazer & lazer)
    {
        if (lazer.x()  > AAship.x + AAship.w) return false;
        if (lazer.x() + lazer.w() < AAship.x) return false; 
        if (lazer.y() < AAship.y) return false;
        if (lazer.y() + lazer.h() > AAship.y + AAship.h) return false; 
        return true; 
    }*/

};

#endif
