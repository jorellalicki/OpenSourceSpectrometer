#include "graph.h"

graph::graph () {}

graph::graph (int _x,int _y, int _width, int _height, int _xMin, int _xMax, string sFont)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    xMin = _xMin;
    xMax = _xMax;
    font.loadFont(sFont, 14);

    inc = width / (float)viewLength;
}

void graph::drawGraph ()
{
    //glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(x,y,0);
	glLineWidth(1);
    glBegin(GL_LINE_STRIP);
	//ofRotateX(mouseY);
	//ofRotateY(mouseX);
	for(int i=viewStartOffset; i<viewStartOffset+viewLength; i++) {
		glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex2f(points[i].x, points[i].y);
	}
	glEnd();
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(0,0); glVertex2f(0, height);     		// xAxis
	glVertex2f(0, height); glVertex2f(width, height);   // yAxis
	for(int i=0; i <11; i++)
	{
		glVertex2f(0, height*i/10); glVertex2f(-30, height*i/10);			// yTicks
		glVertex2f(width*i/10, height); glVertex2f(width*i/10, height+30);	// xTicks
	}
	glEnd();

	for(int i=0; i <11; i++)
	{
		font.drawString(ofToString(i/10) + "." + ofToString(i%10),-32, height*(10-i)/10-5);
		font.drawString(ofToString((800-250)*i/10+250), width*i/10+2, height+30);
	}

	if(drawViewBox)
	{
	    ofSetColor(160,60,0,150);
	    ofFill();
	    ofRect(viewStart, 0, viewEnd-viewStart, height);
	}

	glPopMatrix();
}
