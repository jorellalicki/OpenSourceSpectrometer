#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(30);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	glEnable(GL_DEPTH_TEST);

    ofSetFrameRate(60);

    spec = graph(50,75, ofGetWidth()-100, ofGetHeight()-140, 250, 800, "UbuntuMono-R.ttf");
	isFullScreen= false;

	for(int i=0; i<2048;i++) {
	    spec.colors[i]= ofFloatColor::fromHsb(ofMap(spec.inc*(float)i,0, spec.width, .902,0), 1.0, 1.0);
	}
}

void testApp::createCSV(ofPoint input[2048]) {
	stringstream newCSV;
	ofstream outFile;
	outFile.open("points.csv");
	for (int i = 0; i < 2048; i++) {
		newCSV << input[i].x << "," << input[i].y << endl;
	}
	outFile << newCSV.str();
	outFile.close();
}

vector<ofPoint> testApp::importCSV(string filename) {
	vector<ofPoint> newPoints;
	string inString;
	ifstream inFile(filename);

	vector<double> pointsVec;
	for (int i = 0; i < 2048; i++) newPoints.push_back(ofPoint(0, 0, 0));
	double v;
	while (inFile >> v) {
		pointsVec.push_back(v);
		if (inFile.peek() == ',') inFile.ignore();
	}

	for (int i = 0; i < pointsVec.size(); i++) {
		if (i % 2 == 0) newPoints[i/2].x = pointsVec[i];
		else newPoints[(i-1)/2].y = pointsVec[i];
	}

	/*inFile.open(filename);
	inFile.seekg(0, ios::end);
	inString.resize(inFile.tellg());
	inFile.seekg(0, ios::beg);
	inFile.read(&inString[0], inString.size());

	stringstream ss(inString);
	while (ss >> v) {
		pointsVec.push_back(v);
		if (ss.peek() == ',') inFile.ignore();
	} */

	return newPoints;
}

//--------------------------------------------------------------
void testApp::update(){
    float seed = ofRandom(0.995,1.005);
	vector<ofPoint> importedPoints = importCSV("points.csv");
    for(int i=spec.viewStartOffset; i<spec.viewStartOffset+spec.viewLength; i++) {
		spec.points[i].x = importedPoints[i].x;
		spec.points[i].y = importedPoints[i].y * seed;
		//spec.points[i]= ofPoint(spec.inc*(float)(i-spec.viewStartOffset), ofNoise(i/100.0*seed) * spec.height);
	}
	//createCSV(spec.points);
}

//--------------------------------------------------------------
void testApp::draw(){
//  (doShader ? "ON" : "OFF")
    spec.drawGraph();

    ofSetColor(255,255,255);
	ofDrawBitmapString("fps: " + ofToString( (int)(ofGetFrameNum()/ofGetElapsedTimef()) ), 20, 20);
	ofDrawBitmapString(ofToString(spec.viewStartOffset) + ", " + ofToString(spec.viewLength), 20,40);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if( key == 'z' ){
        spec.views.clear();
        spec.views.push_back(viewContext(0,1.0));
		spec.viewLength = 2048;
		spec.viewStartOffset=0;
		spec.xMax = 800;
		spec.xMin = 250;
		spec.inc = spec.width/((float)spec.viewLength);
	}
	if( key == 'f'){
        isFullScreen = !isFullScreen;
        if(isFullScreen)
        {
            ofSetFullscreen(true);
        }
        else
        {
            ofSetFullscreen(false);
        }
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
        //spec.viewStartOffset=spec.viewStart/(float)spec.width*spec.viewLength;
        spec.views.push_back(viewContext(spec.viewStart/((float)spec.width), spec.viewEnd/((float)spec.width)));
	}
	else if (spec.viewEnd < spec.viewStart)
	{
	    spec.views.push_back(viewContext(spec.viewEnd/((float)spec.width), spec.viewStart/((float)spec.width)));
        //spec.viewStartOffset=(spec.viewEnd)/(float)spec.width*spec.viewLength;
	}
	//spec.viewLength=(float)abs(spec.viewStart-spec.viewEnd)/(float)spec.width*spec.viewLength;
	//spec.inc = spec.width/((float)spec.viewLength);
	spec.setViewContext();
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

