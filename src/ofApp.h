#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		
		ofJson js;
		ofTrueTypeFont ttf;
		ofVideoPlayer oneVideo;


		int state = 0; //0 - beginning 1 - credits, 2 - video,
		float timer = 0;
		int videoCounter = 0;
		float videoX = 0;
		float videoProportion;
		float blankTime = 1000.0;
		float creditsTime = 1000.0;

		float A4longsize = 0.05;
		int numberOfColumns = 5;
		int numberOfDrawings = 13;

		
};
