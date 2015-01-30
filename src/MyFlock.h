//
//  MyFlock.h
//  testingSurfaces
//
//  Created by georgia panagiotidou on 29/01/2015.
//
//

#ifndef __testingSurfaces__MyFlock__
#define __testingSurfaces__MyFlock__

#include <iostream>
#include "MyBoid.h"
#include "ofMain.h"


class MyFlock{
public:
    
    vector<MyBoid*> boids;
    ofVec2f repulsionPoint;
    ofVec2f attractionPoint;
    int timer;
    
    
    MyFlock();
    void draw();
    void update();
    void addRepulsionPoint(ofVec2f p, int ms);
    void addAttractionPoint(ofVec2f p, int ms);

};


#endif /* defined(__testingSurfaces__MyFlock__) */
