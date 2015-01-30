//
//  MyBoid.cpp
//  testingSurfaces
//
//  Created by georgia panagiotidou on 29/01/2015.
//
//

#include "MyBoid.h"
#include "ofApp.h"



 MyBoid::MyBoid(float xinit, float yinit){
    
    position.x = xinit;
    position.y = yinit;
    nonAnimatedPosition.set(position);
    
    //There are no forces to start with
    force1.set(0,0);
    force2.set(0,0);
     
    timer1 = 2000;
    timer2 = 2000;
     
    speed = ofRandom( 20, 70); // Quite ok value 60 if not random
     
     
     //This shoudlnt be here...
     ofVec2f min, max;
     min.set(0,0);
     max.set(2*WIDTH, 2*HEIGHT);
     maxDistance = min.distance(max);
     ///

}

void MyBoid::draw(){
    
    ofSetColor(255, 255, 255);

    //    ofCircle(position.x, position.y, 2);
    
    ofVec2f tmp = position.getInterpolated(ofVec2f(WIDTH/2, HEIGHT/2),0.1);
    float dist = position.distance(ofVec2f(WIDTH/2, HEIGHT/2));
    float distMap = ofMap(dist, 0, maxDistance,1,0);
    tmp.interpolate(position, distMap);
  
    //!TO DO!
    //Check if the values are in the showing plane else dont draw them
    // for faster fps
    
    ofSetLineWidth(1); // It looks more clean with 1px line width..
    ofLine(position.x, position.y, tmp.x, tmp.y);
    
}


void MyBoid::update(){
 
    //Somehow combine forces...then:
    
    //Apply force 1
   
    // timer works also as flag that force is applied
    // 50 represents the speed
    if(timer1<speed){
        position  = nonAnimatedPosition.getInterpolated(finalPoint1, finalDistance*timer1/speed);//*(1-timer1/100)
        timer1++;
    }else{
        nonAnimatedPosition.set(position);
    }
    
}

void MyBoid::addForce(ofVec2f p){
    
    timer1 = 0;
    force1.set(p);
    
    finalPoint1 = force1.getInterpolated(nonAnimatedPosition, 0.2);

    //Calculate how close is the force to the boid
    float dis = force1.distance(nonAnimatedPosition);
    
    
    //Normalize the value for easier calculations.
    finalDistance = ofMap(dis, 0, maxDistance, 0, 1); // Change the last value for less movement
    
}