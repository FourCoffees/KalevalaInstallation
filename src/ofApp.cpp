#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    flock = new MyFlock();
    
  }

//--------------------------------------------------------------
void ofApp::update(){
    
    flock->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    flock->draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
        case OF_KEY_UP:{
            flock->addRepulsionPoint(ofVec2f(WIDTH/2, HEIGHT/2), 50);
            break;
        }
     };

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
