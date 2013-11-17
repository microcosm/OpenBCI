#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void initBuffers();
        void initBuffer(vector<float> *buffer);
        void createMovingGraphs();
        void createTimeAxis();
        void generateRandomPoints();
        void stretchPaddingAcross(int range, int numIntervals);
        void resetPadding();
        string toString(int i);
    
        float red, green, blue;
        int targetFramerate;
    
        int eegMin, eegMax;
        string eegLabel;
        int numChannels, numSeconds;
        int bufferSize;
        int charWidthPx;
        vector< vector<float> > buffers;
        vector< ofxUIMovingGraph* > eegGraphs;
    
        ofxUICanvas *gui;
};
