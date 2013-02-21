#include "ofMain.h"

struct viewContext
{
    //d
};

class graph{

    public:
        graph();
        graph(int _x,int _y, int _width, int _height, int _xMin, int _xMax, string sFont);

        void drawGraph();
        void mousePressed();
        void mouseReleased();
        void mouseDragged();
        void keyPressed();


        ofTrueTypeFont font;

        bool drawViewBox;
        ofPoint points [2048];
        ofFloatColor colors [2048];
        int x, y, width, height;
        float inc;
        float viewStart, viewEnd;
        int viewLength = 2048;
        int viewStartOffset = 0;
        int xMin;
        int xMax;
};
