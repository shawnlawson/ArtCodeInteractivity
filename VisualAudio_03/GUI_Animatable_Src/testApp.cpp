#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    
    int bufferSize = 256;
    vector<float> buffer;
    for(int i = 0; i < bufferSize; i++)
        buffer.push_back(0.0);
    
    gui = new ofxUICanvas();
    gui->addLabel("Controller", OFX_UI_FONT_LARGE);
    gui->addSpacer();
    backgroundSlider = (ofxUISlider *) gui->addSlider("backgroundColor", 0.0, 255.0, 128.0);
    gui->addSpacer();
    mgX = (ofxUIMovingGraph *) gui->addMovingGraph("MouseX", buffer, bufferSize, 0, ofGetWidth());
    mgY = (ofxUIMovingGraph *) gui->addMovingGraph("MouseY", buffer, bufferSize, 0, ofGetHeight());
    
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("gui_settings.xml");
    
    
    mPoint.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    mPoint.setRepeatType(PLAY_ONCE);
    curveType = 0;
    mPoint.setCurve((AnimCurve)curveType);

}

//--------------------------------------------------------------
void testApp::update(){
    float dt = ofGetLastFrameTime();
    mPoint.update(dt);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(backgroundSlider->getScaledValue());
    
    ofSetColor(ofColor::red);
    ofCircle(mPoint.getCurrentPosition(), 20);
}

//--------------------------------------------------------------

void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	cout << "got event from: " << name << endl;
	
	if(name == "backgroundColor")
	{
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        cout << name << slider->getScaledValue() << endl;
    }
}
void testApp::keyPressed(int key){

    switch (key)
	{
        case 'h':
        case 'H':
            gui->toggleVisible();
            break;
        case 's':
        case 'S':
            gui->saveSettings("gui_settings.xml");
            cout << "Settings Saved!" << endl;
            break;
        case 'l':
        case 'L':
            gui->loadSettings("gui_settings.xml");
            
        case OF_KEY_LEFT:
            curveType -= 1;
            if (curveType < 0)
                curveType = 24;
            mPoint.setCurve((AnimCurve)curveType);
            cout << mPoint.getCurveName((AnimCurve)curveType) << endl;
            break;
            
        case OF_KEY_RIGHT:
            curveType += 1;
            curveType %= 25;
            mPoint.setCurve((AnimCurve)curveType);
            cout << mPoint.getCurveName((AnimCurve)curveType) << endl;
            break;

        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mgX->addPoint(x);
    mgY->addPoint(y);
    
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mPoint.animateToIfFinished(ofPoint(x,y));
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
