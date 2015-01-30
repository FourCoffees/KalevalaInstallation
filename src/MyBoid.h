//
//  MyBoid.h
//  testingSurfaces
//
//  Created by georgia panagiotidou on 29/01/2015.
//
//

#ifndef __testingSurfaces__MyBoid__
#define __testingSurfaces__MyBoid__

#include <iostream>
#include "ofMain.h"


class MyBoid{
    
public:
    ofVec2f position;
    ofVec2f nonAnimatedPosition;
    
    ofVec2f force1;
    ofVec2f force2;
    
    ofVec2f finalPoint1;

    float finalDistance;
    float maxDistance;
    
    int speed;
    
    int timer1;
    int timer2;
    
    MyBoid(float x, float y);
    void draw();
    void update();
    void addForce(ofVec2f p);
    
};


#endif /* defined(__testingSurfaces__MyBoid__) */

