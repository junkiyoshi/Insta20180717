#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int rect_size = 36;
	for (int i = 0; i < 64; i++) {

		ofColor rect_color;
		rect_color.setHsb(ofRandom(255), 200, 255);
		ofSetColor(rect_color);

		int x = ofNoise(ofRandom(100), ofGetFrameNum() * 0.003) * ofGetWidth() / rect_size;
		int y = ofNoise(ofRandom(100, 200), ofGetFrameNum() * 0.003) * ofGetHeight() / rect_size;

		x *= rect_size;
		y *= rect_size;

		ofPoint point(x, y);
		ofDrawRectangle(point, rect_size, rect_size);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}