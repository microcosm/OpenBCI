#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Init oF
    red = 233; blue = 52; green = 27;
    targetFramerate = 60;
    charWidthPx = 16;
	ofBackground(red, green, blue, 255);
    ofSetFrameRate(targetFramerate);
    
    //Init BCI values
    eegMin = 0, eegMax = 63, eegLabel = "EEG CHANNELS";
    numChannels = 8, numSeconds = 5;
    bufferSize = 256;
    initBuffers();
    
    //Create GUI
    gui = new ofxUICanvas(0, 0, 500, 1000);
    
    gui->addWidgetDown(new ofxUILabel(eegLabel, OFX_UI_FONT_MEDIUM));
    createMovingGraphs();
    createTimeAxis();
}

//--------------------------------------------------------------
void testApp::update(){
    generateRandomPoints();
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

void testApp::initBuffers(){
    for(int i = 0; i < numChannels; i++){
        vector<float> buffer;
        initBuffer(&buffer);
        buffers.push_back(buffer);
    }
}

void testApp::initBuffer(vector<float> *buffer){
    for(int i = 0; i < bufferSize; i++){
        buffer->push_back(0.0);
    }
}

void testApp::createMovingGraphs(){
    resetPadding();
    for(int i = 0; i < numChannels; i++){
        ofxUIMovingGraph *movingGraph = new ofxUIMovingGraph(0, 0, bufferSize, eegMax, buffers[i], bufferSize, eegMin, eegMax, eegLabel);
        gui->addWidgetDown(movingGraph);
        eegGraphs.push_back(movingGraph);
    }
}

void testApp::createTimeAxis(){
    
    bool first = true;
    ofxUILabel *label;
    stretchPaddingAcross(bufferSize, numSeconds);
    
    for(int i = -numSeconds; i <= 0; i++){
        label = new ofxUILabel(toString(i), OFX_UI_FONT_SMALL);
        
        if(first) gui->addWidgetDown(label);
        else gui->addWidgetRight(label);
        
        first = false;
    }
    
    resetPadding();
    label = new ofxUILabel("Secs", OFX_UI_FONT_SMALL);
    gui->addWidgetDown(label);
}

void testApp::generateRandomPoints(){
    for(int i = 0; i < numChannels; i++){
        eegGraphs[i]->addPoint((float)rand()/RAND_MAX*(eegMax*0.2));
    }
}

void testApp::stretchPaddingAcross(int range, int numIntervals){
    gui->setPadding(floor((range - charWidthPx) / numIntervals) - charWidthPx);
}

void testApp::resetPadding(){
    gui->setPadding(OFX_UI_GLOBAL_PADDING);
}

string testApp::toString(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}
