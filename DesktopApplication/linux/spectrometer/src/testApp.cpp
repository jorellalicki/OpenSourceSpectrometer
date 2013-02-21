#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(30);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	glEnable(GL_DEPTH_TEST);

    spec = graph(50,75, ofGetWidth()-100, ofGetHeight()-100, 250, 800, "UbuntuMono-R.ttf");

	for(int i=0; i<2048;i++) {
	    spec.colors[i]= ofFloatColor::fromHsb(ofMap(spec.inc*(float)i,0, spec.width, .902,0), 1.0, 1.0);
	}

	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    float seed = ofRandom(0.995,1.005);
    for(int i=spec.viewStartOffset; i<spec.viewStartOffset+spec.viewLength; i++) {
		spec.points[i]= ofPoint(spec.inc*(float)(i-spec.viewStartOffset), ofNoise(i/100.0*seed) * spec.height);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
//  (doShader ? "ON" : "OFF")
    spec.drawGraph();
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if( key == 'z' ){
		spec.viewLength = 2048;
		spec.viewStartOffset=0;
		spec.inc = spec.width/((float)spec.viewLength);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	spec.viewEnd = x-50;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	spec.viewStart = x-50;
	spec.viewEnd = spec.viewStart;
	spec.drawViewBox = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	spec.drawViewBox = false;
	if(spec.viewStart < spec.viewEnd)
	{
        spec.viewStartOffset=spec.viewStart/(float)spec.width*spec.viewLength;
	}
	else
	{
        spec.viewStartOffset=(spec.viewEnd)/(float)spec.width*spec.viewLength;
	}
	spec.viewLength=(float)abs(spec.viewStart-spec.viewEnd)/(float)spec.width*spec.viewLength;
	spec.inc = spec.width/((float)spec.viewLength);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    spec.height = h-140;
	spec.width = w-100;

	spec.inc = (ofGetWidth()-100)/((float)spec.viewLength);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

