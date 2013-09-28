#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(30);
    
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(ofColor::sandyBrown);
    
    ofFill();
    ofSetColor(ofColor::seaShell);
    for(int i=0; i<circles.size(); i++){
        circles[i].draw();
    }
    
    box2d.drawGround();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ofxBox2dCircle circle;
    circle.setPhysics(3.0, .53, .1);
    circle.setup(box2d.getWorld(), x, y, ofRandom(5,20));
    circles.push_back(circle);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
