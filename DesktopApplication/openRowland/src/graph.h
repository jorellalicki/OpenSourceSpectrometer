#include "ofMain.h"

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

class graph{

    public:
        graph();
        graph(int _x,int _y, int _width, int _height, int _xMin, int _xMax, string sFont);

        void setViewContext();

        void drawGraph();
        void mousePressed();
        void mouseReleased();
        void mouseDragged();
        void keyPressed();


        ofTrueTypeFont font;

        bool drawViewBox;
        ofPoint points [2048];
        ofFloatColor colors [2048];
        int xGraph, yGraph, width, height;
        float inc;
        float viewStart, viewEnd;
        int viewLength;
        int viewStartOffset;
        int xMin;
        int xMax;

        vector <viewContext> views;
};
