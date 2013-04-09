//#include "ofMain.h"
#include <string>
#include <vector>
#include <GL/glut.h>

#define NUM_POINTS 2048

using namespace std;

class viewContext
{
public:
	viewContext();
	viewContext(float _start, float _end)
	{
		pStart = _start;
		pEnd   = _end;
	}

	float pStart;
	float pEnd;
};

class point {
	public:
		int x,y;
		point() {}
		point(int _x, int _y) {
			x = _x;	// wavelength
			y = _y;	// intensity
		}
		/*int getX() { return x; }
		int getY() { return y; }		*/
};

class color {
	public:
		int r,g,b;
		color() {}
		color(int _r, int _g, int _b) {
			r = _r;
			g = _g;
			b = _b;
		}
};

class graph{
	private:

	public:
		graph();
		graph(int _x,int _y, int _width, int _height, int _xMin, int _xMax, string sFont);
		
		void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v );
		void updatePoints(vector<point> p) {
			points = p;
		}
		void setViewContext();

		void drawGraph();
		void mousePressed();
		void mouseReleased();
		void mouseDragged();
		void keyPressed();


		//ofTrueTypeFont font;

		bool drawViewBox;
//		point points [NUM_POINTS];
		vector<point> points;
		color colors [NUM_POINTS];
		int xGraph, yGraph, width, height;
		float inc;
		float viewStart, viewEnd;
		int viewLength;
		int viewStartOffset;
		int xMin;
		int xMax;

        vector <viewContext> views;
};
