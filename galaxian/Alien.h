#ifndef ALIEN_H
#define ALIEN_H

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "Lazer.h"
#include <ctime>
#include <vector>

class Alien
{
protected:
    int x_;
    int y_;
    int w_;
    int h_;
    int speed_;
    Rect alien_;
    bool alive_;
    int state_;
    int ogy_;
    int rat_;
    Surface & surface;

public:

Alien(Surface & surface):
    x_(0), y_(0), speed_(0), w_(0), h_(0), alive_(0), state_(0), ogy_(0), rat_(0), surface(surface) {}

Alien(int x, int y, int speed, int w, int h, bool alive, Surface & surface):
    x_(x), y_(y), speed_(speed), w_(w), h_(h), alive_(alive), ogy_(y), rat_(0), surface(surface) { state_ = 0;}
    
/*    int x() {return x_;}
    int y() {return y_;}
    int w() {return w_;}
    int h() {return h_;}*/
    int speed() {return speed_;}
    bool alive() {return alive_;}
    Rect alienRect() {return alien_;}
    int state() {return state_;}
    int ogy() {return ogy_;}
    int rat() {return rat_;}
    
    void setx(int x) {x_ = x;}
    void sety(int x) {y_ = x;}
    void setw(int x) {w_ = x;}
    void seth(int x) {h_ = x;}
    void setspd(int x) {speed_ = x;}
    void setAlive(bool x) {alive_ = x;}
    void setAlienRect(Rect alien) {alien_ = alien;}
    void setAlienRectx(int x) {alien_.x = x;}
    void setAlienRecty(int y) {alien_.y = y;}
    void setState(int x) {state_ = x;}
    void setOgy(int x) {ogy_ = x;}
    void setRat(int x) {rat_ = x;}
    
    bool alienCol(Lazer & lazer)
    {
        if (lazer.x()  > alien_.x + alien_.w) return false;
        if (lazer.x() + lazer.w() < alien_.x) return false; 
        if (lazer.y() < alien_.y) return false;
        if (lazer.y() + lazer.h() > alien_.y + alien_.h) return false; 
        return true; 
    }

    void attack()
    {
        // alien is attacking
        // sin curve and track
        /* rect.y += 2; */
        /* rect.x = 45 * sin(rect.y/10.0) + median; */
        /* if (rect.x > x0) median -= 1; */
        /* else if (rect.x < x0) median += 1; */
        /* if (rect.y >= H) */
        /* { */
        /*     rect.y = 0; */
        /*     state = 2; */
        /* }         */
        
        alien_.y += 2;
        
    }

    void returnOp(int right)
    {
        bool start = false;
        if (alien_.y != ogy_) alien_.y += 1;
        else start = true;
        if (right == rat() && start)
        {
            state_ = 0;
        }
    }
    

};


#endif
