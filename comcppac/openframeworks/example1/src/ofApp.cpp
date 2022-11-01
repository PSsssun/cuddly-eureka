#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    numOfXTiles=20;
    numOfYTiles=20;
    spacingX=ofGetWidth()/numOfXTiles;
    spacingY=ofGetHeight()/numOfYTiles;
    
    startingX = spacingX / 2;
    startingY = spacingY / 2;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int x=0;x<numOfXTiles;x++){
        for(int y=0;y<numOfYTiles;y++){
            int locX=spacingX*x+startingX;
            int locY=spacingY*y+startingY;
            
           
            
            ofPushMatrix();
            ofTranslate(locX,locY);
            float angle = ofRadToDeg(atan2(mouseY-locY, mouseX-locX));
            ofRotateDeg(angle+180);
            ofTranslate(100,0);
            ofSetCircleResolution(50);
            
            float distanceA= ofDist(mouseX,mouseY,locX,locY);
            float scale= ofMap(distanceA,0,ofGetWidth()/2,2,0.5,true);
            ofScale(scale,scale);
            ofDrawCircle(0,0,10);
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
