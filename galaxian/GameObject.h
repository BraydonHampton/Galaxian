#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include <ctime>
#include <vector>

class GameObject
{
protected:
    int x_;
    int y_;
    int w_;
    int h_;
    int speed_;
    Surface & surface;

public:

GameObject(Surface & surface):
    x_(0), y_(0), speed_(0), w_(0), h_(0), surface(surface) {}
    
GameObject(int x, int y, int speed, int w, int h, Surface & surface):
    x_(x), y_(y), speed_(speed), w_(w), h_(h), surface(surface) {}

    int x() {return x_;}
    int y() {return y_;}
    int w() {return w_;}
    int h() {return h_;}
    int speed() {return speed_;}

    void setx(int x) {x_ = x;}
    void sety(int x) {y_ = x;}
    void setw(int x) {w_ = x;}
    void seth(int x) {h_ = x;}
    void setspd(int x) {speed_ = x;}

    /*
    void draw()
    {
        std::cout << 'y';
        surface.put_rect(x_, y_, w_, h_, WHITE);
        }*/

    
};

#endif
