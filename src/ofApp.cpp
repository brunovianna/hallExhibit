#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);
	ttf.load("mono.ttf", 8);

	ofFile file("videos.json");
	if (file.exists()) {
		file >> js;
		for (auto & video : js) {
			if (!video.empty()) {
				if (!oneVideo.load(video["file"])) {
					cout << "couldn't load video file" << video["file"] << endl;
					ofExit(-1);
				}

				// 	path.moveTo(stroke[0]["x"], stroke[0]["y"]);
				// 	for(auto & p: stroke){
				// 		path.lineTo(p["x"], p["y"]);
				// 	}
			}
		}
	}

	state = 1;
	timer = ofGetElapsedTimeMillis();
	oneVideo.load(js[videoCounter]["file"]);
	videoProportion = oneVideo.getWidth() / oneVideo.getHeight();
	videoX = ofGetWidth() / 2.0f + (ofGetWidth() / 2.0f - (ofGetHeight() * videoProportion)) / 2;


	//calculate drawing positions

	float drawingWidth = ofGetWidth() / 2* A4longsize;
	float spacingX = (ofGetWidth() / 2 - drawingWidth * numberOfColumns) / (numberOfColumns + 1);
	float spacingY = spacingX;


}

//--------------------------------------------------------------
void ofApp::update(){


    if (state == 1) {
		if (ofGetElapsedTimeMillis() > timer + 10000) {
			state = 2;
			oneVideo.play();
		}
	} else	if (state == 2) {
		oneVideo.update();
	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	//drawings

	ofSetColor(255);
	for (int i = 0; i < numberOfDrawings; i++) {
		float drawingWidth = ofGetWidth() / 2 * A4longsize;
		float spacingX = (ofGetWidth() / 2 - drawingWidth * numberOfColumns) / (numberOfColumns + 1);
		float spacingY = spacingX;
		int row = i / numberOfColumns;
		int column = i % numberOfColumns;
		float x = spacingX + column * (drawingWidth + spacingX);
		float y = spacingY + row * (drawingWidth + spacingY);

		if (row == (int)(numberOfDrawings / numberOfColumns)) {
			x = x + (numberOfColumns - (numberOfDrawings % numberOfColumns))  * (spacingX+drawingWidth) / 2;
		}

		ofDrawRectangle(x, y, drawingWidth, drawingWidth / 1.4142);
	}


	if (state == 1) {
		ofSetColor(0, 0, 0, 10);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		ofSetColor(255);
		string title = js[videoCounter]["title"];
		if (title == "") {
			title = js[videoCounter]["file"];
		}
		float textY = 50;
		
		ttf.drawString(title, videoX, textY);
		textY = textY + ttf.getLineHeight() * 1.5;
		for (auto & names : js[videoCounter]["members"]) {
			ttf.drawString(names, videoX, textY);
			textY += ttf.getLineHeight();
		}



	} else if (state == 2) {
		ofSetColor(255);
		oneVideo.draw(videoX, 0, ofGetHeight() * videoProportion, ofGetHeight());
		if (oneVideo.getCurrentFrame() >= oneVideo.getTotalNumFrames() - 1) {
			videoCounter++;
			if (videoCounter >= js.size()) {
				videoCounter = 0;
			}
			oneVideo.load(js[videoCounter]["file"]);
			videoProportion = oneVideo.getWidth() / oneVideo.getHeight();
			videoX = ofGetWidth() / 2.0f + (ofGetWidth() / 2.0f - (ofGetHeight() * videoProportion)) / 2;
			state = 1;
			timer = ofGetElapsedTimeMillis();
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


