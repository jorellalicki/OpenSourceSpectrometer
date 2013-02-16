#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(50, 50, 50);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();

	shader.setGeometryInputType(GL_LINES);
	shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	shader.setGeometryOutputCount(4);
	shader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom.glsl");

	printf("Maximum number of output vertices support is: %i\n", shader.getGeometryMaxOutputCount());
	
	font.loadFont("UbuntuMono-R.ttf", 14);

	height = ofGetHeight()-100;
	width = ofGetWidth()-100;
	inc = (width)/((float)2048-1.0);
	for(int i=0; i<2048; i++) {
		points[i]= ofPoint(inc*(float)i, ofRandom(1.0) * height);
	}
	for(int i=0; i<2048;i++) {
	    colors[i]= ofFloatColor::fromHsb(ofMap(inc*(float)i,0, width, .902,0), 1.0, 1.0);
	}

	doShader = true;
	glEnable(GL_DEPTH_TEST);

	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<2048; i++) {
		points[i]= ofPoint(inc*(float)i, ofRandom(1.0) * height);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	//glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(50,75,0);
	glLineWidth(1);
    glBegin(GL_LINE_STRIP);
	//ofRotateX(mouseY);
	//ofRotateY(mouseX);
	for(int i=1; i<2048; i++) {
		glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex2f(points[i].x, points[i].y);
	}
	glEnd();
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(0,0); glVertex2f(0,height);					// xAxis
	glVertex2f(0,height); glVertex2f(width,height);	        // yAxis
	for(int i=0; i <11; i++)
	{
		glVertex2f(0,height*i/10); glVertex2f(-30,height*i/10);  // yTicks
		glVertex2f(width*i/10,height); glVertex2f(width*i/10,height+30); //xTicks
		//ofDrawBitmapString(ofToString(i/10) + "." + ofToString(i%10),-32,height*(10-i)/10+18);
	}
	glEnd();

	for(int i=0; i <11; i++)
	{
		//glVertex2f(0,height*i/10); glVertex2f(-30,height*i/10);  // yTicks
		font.drawString(ofToString(i/10) + "." + ofToString(i%10),-32,height*(10-i)/10-5);
		font.drawString(ofToString((800-250)*i/10+250), width*i/10+2,height+30);
		//glVertex2f(width*i/10,height); glVertex2f(width*i/10,height+30); //xTicks
	}

	if(doShader) shader.end();

	glPopMatrix();

	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()) + "\nPress 's' to toggle shader: " + (doShader ? "ON" : "OFF"), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if( key == 's' ){
		doShader = !doShader;
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    height = h-140;
	width = w-100;

	inc = (ofGetWidth()-100)/((float)2048-1.0);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

