#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    min = 0;
    max = 255;
    bufferSize = 256;
    gui = new ofxUICanvas(0, 0, 500, 300);
    
    vector<float> buffer;
    for(int i = 0; i < bufferSize; i++)
    {
        buffer.push_back(0.0);
    }
    
    movingGraph = (ofxUIMovingGraph *) gui->addWidgetDown(new ofxUIMovingGraph(255, 120, buffer, bufferSize, min, max, "MOVING GRAPH"));
    
    gui->addWidgetDown(new ofxUILabel("MOVING GRAPH", OFX_UI_FONT_MEDIUM));

    red = 233; blue = 52; green = 27;
	ofBackground(red, green, blue, 255);
     
}

//--------------------------------------------------------------
void testApp::update(){
    movingGraph->addPoint((float)rand()/RAND_MAX*max);
}

//--------------------------------------------------------------
void testApp::draw(){
	
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
