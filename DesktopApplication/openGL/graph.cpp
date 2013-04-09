#include "graph.h"
#include <iostream>
#include <cmath>

graph::graph () {}

graph::graph (int _x,int _y, int _width, int _height, int _xMin, int _xMax, string sFont)
{
	xGraph = _x;
	yGraph = _y;
	width = _width;
	height = _height;
	xMin = _xMin;
	xMax = _xMax;
	//font.loadFont(sFont, 14);
	views = vector<viewContext>();
	views.push_back(viewContext(0,1.0));
	viewLength = 2048;
	viewStartOffset = 0;
	inc = width / (float)viewLength;
}

void graph::drawGraph ()
{
	//glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(xGraph,yGraph,0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	//ofRotateX(mouseY);
	//ofRotateY(mouseX);
	
	// TODO: fix drawing in a certain view
	/*
	for(int i=viewStartOffset; i<viewStartOffset+viewLength; i++) {
		glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex2f(points[i].x, points[i].y);
	}*/
	
	float r;
	float g;
	float b;

	for (int i = 0; i <2048; i++){
		HSVtoRGB(&r,&g,&b,(float)i*330/2048.0,(float)1.0,(float)1.0);
		glColor3f(r,g,b);
		glVertex2f(points[i].x*1000/2248.0, points[i].y+rand()%40);
	}
	
	
	glEnd();
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(0,0); glVertex2f(0, height);	 		// xAxis
	glVertex2f(0, height); glVertex2f(width, height);   // yAxis
	for(int i=0; i <11; i++)
	{
		glVertex2f(0, height*i/10); glVertex2f(-30, height*i/10);			// yTicks
		glVertex2f(width*i/10, height); glVertex2f(width*i/10, height+30);	// xTicks
	}
	glEnd();

	for(int i=0; i < 11; i++)
	{
		// TODO: fix font drawing
		//font.drawString(ofToString(i/10) + "." + ofToString(i%10),-32, height*(10-i)/10-5);
		//font.drawString(ofToString((xMax-xMin)*i/10+xMin), width*i/10+2, height+30);
	}

	// TODO: fix view box rendering
/*	if(drawViewBox)
	{
		ofSetColor(160,60,0,150);
		ofFill();
		ofRect(viewStart, 0, viewEnd-viewStart, height);
	}*/

	glPopMatrix();
}



void graph::setViewContext()
{
	float newViewStart = 0;
	float newViewEnd   = 0;
	float viewScale = 1;
	xMin = 250;
	xMax = 800;
	int range = xMax - xMin;
	for(unsigned int i=1; i< views.size(); i++)
	{
		viewScale *= (views[i-1].pEnd - views[i-1].pStart);
		newViewEnd   = newViewStart + views[i].pEnd * viewScale;
		newViewStart = newViewStart + views[i].pStart * viewScale;
	}
//	ofLog(OF_LOG_NOTICE, ofToString(newViewStart) + ", " + ofToString(newViewEnd));
	viewStartOffset = newViewStart*2048;
	viewLength = (newViewEnd - newViewStart)*2048;
	xMax = xMin + newViewEnd * range;
	xMin += newViewStart * range;
	inc = width/((float)viewLength);
}

void graph::HSVtoRGB( float *r, float *g, float *b, float h, float s, float v )
{
	int i;
	float f, p, q, t;
	if( s == 0 ) {
		// achromatic (grey)
		*r = *g = *b = v;
		return;
	}
	h /= 60;			// sector 0 to 5
	i = floor( h );
	f = h - i;			// factorial part of h
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );
	switch( i ) {
		case 0:
			*r = v;
			*g = t;
			*b = p;
			break;
		case 1:
			*r = q;
			*g = v;
			*b = p;
			break;
		case 2:
			*r = p;
			*g = v;
			*b = t;
			break;
		case 3:
			*r = p;
			*g = q;
			*b = v;
			break;
		case 4:
			*r = t;
			*g = p;
			*b = v;
			break;
		default:		// case 5:
			*r = v;
			*g = p;
			*b = q;
			break;
	}
}

