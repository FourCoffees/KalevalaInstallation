//
//  MyFlock.cpp
//  testingSurfaces
//
//  Created by georgia panagiotidou on 29/01/2015.
//
//

#include "MyFlock.h"
#include "ofApp.h"
#include "MyBoid.h"

MyFlock::MyFlock(){
    
    int timer = 0;
    int dist = 30; // Change the frequence of appearance of the 'dots'
    float xnow = -WIDTH;
    float ynow = -HEIGHT;
    
    while(ynow< 2*HEIGHT){
        if(xnow < 2*WIDTH){
            xnow += dist;
        }else{
            xnow = -WIDTH;
            ynow +=dist;
        }
        
        MyBoid *b = new MyBoid(xnow, ynow);
        boids.push_back(b);
    }
}

void MyFlock::update(){
    
    for(vector<MyBoid*>::iterator it=boids.begin();it!=boids.end(); it++ ){
          (*it)->update();
    }
}

void MyFlock::draw(){
  
    for(vector<MyBoid*>::iterator it=boids.begin();it!=boids.end(); it++ ){
        
        (*it)->draw();
    }
}

void MyFlock::addRepulsionPoint( ofVec2f p, int ms){
    
    repulsionPoint.set(p);
    timer = ms;
    
    for(vector<MyBoid*>::iterator it=boids.begin();it!=boids.end(); it++ ){
        (*it)->addForce(p);
    }
    
    
}

void MyFlock::addAttractionPoint( ofVec2f p, int ms){
    
    attractionPoint.set(p);
    timer = ms;
    
}



