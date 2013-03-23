//#include "ofMain.h"
#include <string>

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
		Point(int _x, int _y) {
			x = _x;	// wavelength
			y = _y;	// intensity
		}
		/*int getX() { return x; }
		int getY() { return y; }		*/
};

class color {
	public:
		int r,g,b;
		Point(int _r, int _g, int _b) {
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
		
		
		void updatePoints(vector<int>);
		void setViewContext();

		void drawGraph();
		void mousePressed();
		void mouseReleased();
		void mouseDragged();
		void keyPressed();


		//ofTrueTypeFont font;

		bool drawViewBox;
		point points [NUM_POINTS];
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
