#ifndef FLEET_H
#define FLEET_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "AquaAlien.h"
#include "PurpAlien.h"
#include "RedAlien.h"
#include "GoldAlien.h"


class Fleet
{
private:
    std::vector< AquaAlien > aa; 
    std::vector< PurpAlien > pa;
    std::vector< RedAlien > ra;
    std::vector< GoldAlien > ga;
    Surface & surface_;
    int left;
    int right;
public:

Fleet(Surface & surface) : surface_(surface), right(482), left(50) {}
    
    std::vector< AquaAlien > & getAA() { return aa; }
    std::vector< RedAlien > & getRA() { return ra; }
    std::vector< PurpAlien > & getPA() { return pa; }
    std::vector< GoldAlien > & getGA() { return ga; }

    int getLeft() {return left;}
    int getRight() {return right;}

    void setLeft(int x) {left = x;}
    void setRight(int x) {right = x;}
    
    
    void buildFleet()
    {
        int AAx = 50;
        int AAy = H/2;

        int PAx = 90;
        int PAy = H/2 - 160;

        int RAx = 130;
        int RAy = H/2 - 200;

        int GAx = 170;
        int GAy = H/2 - 240;
        for (int i = 0; i < NUM_AA; ++i)
        {
            if (i % 10 == 0) // build Aqua
            {
                AAx = 50;
                AAy -= 40;
            }
            getAA().push_back(AquaAlien(AAx, AAy));
            getAA()[i].setAlive(true);
            AAx += 40;


            if (i < NUM_PA) // build purple
            {
                getPA().push_back(PurpAlien(PAx, PAy));
                getPA()[i].setAlive(true);
                PAx += 40;
            }

            if (i < NUM_RA) // build red
            {
                getRA().push_back(RedAlien(RAx, RAy));
                getRA()[i].setAlive(true);
                RAx += 40;
            }

            if (i < NUM_GA) // build red
            {
                getGA().push_back(GoldAlien(GAx, GAy));
                getGA()[i].setAlive(true);
                GAx += 120;
            }
            
        }
        setRight(getAA()[9].alienRect().x + getAA()[9].alienRect().w);
        setLeft(getAA()[0].alienRect().x);
    }

    
    
    void draw_fleet()
    {
        for (int i = 0; i < NUM_AA; ++i)
        {
            if (aa[i].alive()) aa[i].draw(surface_); // draw aqua
            if (i < NUM_PA && pa[i].alive()) pa[i].draw(surface_); // draw purp
            if (i < NUM_RA && ra[i].alive()) ra[i].draw(surface_); // draw red
            if (i < NUM_GA && ga[i].alive()) ga[i].draw(surface_); // draw flagship
        }
    }

    bool aaAlive(int i)
    {
        if (aa[i].alive()) return true;
        return false;
    }

    bool paAlive(int i)
    {
        if (pa[i].alive()) return true;
        return false;
    }

    bool raAlive(int i)
    {
        if (ra[i].alive()) return true;
        return false;
    }

    bool gaAlive(int i)
    {
        if (ga[i].alive()) return true;
        return false;
    }


    void move(int speed)
    {
        int dx = speed;
        bool setState = true;
        setRight(getRight() + speed);
        setLeft(getLeft() + speed);
        for (int i = 0; i < NUM_AA; ++i)
        {
//            std::cout << dx << '\n';
            if (aa[i].state() == 0)aa[i].setAlienRectx(aa[i].alienRect().x + speed);
            if (i < NUM_PA && pa[i].state() == 0) pa[i].setAlienRectx(pa[i].alienRect().x + speed);
            if (i < NUM_RA && ra[i].state() == 0) ra[i].setAlienRectx(ra[i].alienRect().x + speed);
            if (i < NUM_GA && ga[i].state() == 0) ga[i].setAlienRectx(ga[i].alienRect().x + speed);
            
            if (rand() % 5000 == 0)
            {
//                std::cout << "here";
                if (setState)
                {
                    if (aa[i].state() == 0 && aa[i].alive())
                    {
                        aa[i].setState(1);
                        aa[i].setRat(getRight());
                        if (i < NUM_PA)
                        {
                            ga[i].setState(1);
                        }
                        if (i < NUM_GA)
                        {
                            ga[i].setState(1);
                            ga[i].setRat(getRight());
                            if (i == 0)
                            {
                                ra[0].setState(1);
                                ra[1].setState(1);
                                ra[2].setState(1);

                                ra[0].setRat(getRight());
                                ra[1].setRat(getRight());
                                ra[2].setRat(getRight());
                            }
                            else
                            {
                                ra[3].setState(1);
                                ra[4].setState(1);
                                ra[5].setState(1);

                                ra[3].setRat(getRight());
                                ra[4].setRat(getRight());
                                ra[5].setRat(getRight());
                            }
                        }
                        setState = false;
                    }
                }
            }

            // attack state
            if (aa[i].state() == 1)
            {
                aa[i].attack();
                if (aa[i].alienRect().y > H)
                {
                    aa[i].setState(2);
                    aa[i].setAlienRecty(0);
                }
            }
            if (i < NUM_PA && pa[i].state() == 1)
            {
                pa[i].attack();
                if (pa[i].alienRect().y > H)
                {
                    pa[i].setState(2);
                    pa[i].setAlienRecty(0);
                }
            }
            if (i < NUM_GA && ga[i].state() == 1)
            {
                ga[i].attack();
                if (i == 0)
                {
                    ra[0].attack();
                    ra[1].attack();
                    ra[2].attack();
                }
                else
                {
                    ra[3].attack();
                    ra[4].attack();
                    ra[5].attack();
                }
                
                if (ga[i].alienRect().y > H)
                {
                    ga[i].setState(2);
                    ga[i].setAlienRecty(0);           
                    if (i == 0)
                    {
                        ra[0].setState(2);
                        ra[1].setState(2);
                        ra[2].setState(2);

                        ra[0].setAlienRecty(0);
                        ra[1].setAlienRecty(0);
                        ra[2].setAlienRecty(0);
                    }
                    else
                    {
                        ra[3].setState(2);
                        ra[4].setState(2);
                        ra[5].setState(2);
                        std::cout << "j";
                        ra[3].setAlienRecty(0);
                        ra[4].setAlienRecty(0);
                        ra[5].setAlienRecty(0);
                    }
                }
            }
            
            // return state
            if (aa[i].state() == 2)
            {
                aa[i].returnOp(getRight());
            }
            if (i < NUM_PA && pa[i].state() == 2)
            {
                pa[i].returnOp(getRight());
            }
            if (i < NUM_GA && ga[i].state() == 2)
            {
                ga[i].returnOp(getRight());
            }
            if (i < NUM_RA && ra[i].state() == 2)
            {
                ra[i].returnOp(getRight());
            }
        }
    }
    
};

#endif
