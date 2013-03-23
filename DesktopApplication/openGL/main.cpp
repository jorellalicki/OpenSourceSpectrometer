#include <GL/glut.h>
#include <iostream>
#include "graph.h"

using namespace std;

#define WINDOW_INIT_WIDTH 1024
#define WINDOW_INIT_HEIGHT 768


graph spec;

// This can be used to do stuff while idling
void onIdle(void) {

	
	// call this if the display should be updated (got new data)
	glutPostRedisplay();
}

// OpenGL display routine
void drawScene(void)
{
	// *** BEGIN Drawing ***
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	// draw a test quadrilateral...	
	glBegin(GL_QUADS);
	unsigned int x1 = 60, y1 = 22, x2 = 200, y2 = 37;
	glVertex2f(x1, y1); glVertex2f(2*x2, y1); glVertex2f(x2, y2); glVertex2f(x1, y2);
	glEnd();
	
	
	spec.drawGraph();
	
	// *** END Drawing ***
	
	// Refresh display
	glutSwapBuffers();
	
	// Limit framerate
	sleep(1.0/60.0);
}

// OpenGL window reshape/resize routine.
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	
	/*	OpenGL lesson:
	
		The 1000's specify the size of the OpenGL coordinate grid. 
		All points are drawn to this grid, not actual pixels.
		Resizing the window will not affect this grid, it will only scale your view of it.
	*/
	glOrtho (0, 1000, 1000, 0, 0, 1);
	glMatrixMode (GL_MODELVIEW);
}

void setup(void) 
{
	// Set background color
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	// Use reshape function to initialize viewport
	reshape(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT);
	
	// Disable depth-testing because we are using 2D
	glDisable(GL_DEPTH_TEST);
	
	/*
	TODO: figure out glXSwapIntervalEXT (or some other fucntion) to enable v-sync/frame-limiting
	Maybe just use timers in display function?
	*/
		
	//	glXSwapIntervalEXT(1);


	spec = graph(50,75, WINDOW_INIT_WIDTH-100, WINDOW_INIT_HEIGHT-140, 250, 800, "UbuntuMono-R.ttf");
	vector<point> pts = vector<point>();
	for (int i = 0; i < 2048; i++) {
		pts.push_back(point(i,i));
	}
	spec.updatePoints(pts);
}



// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	// Determine which key was pressed
	switch(key) 
	{
		// ESC key: exit program
		case 27:
			exit(0);
			break;
		// Example -- press the x key
		case 'x':
			cout << "you pressed x" << endl;
			break;
		// Example -- press the x key while holding shift
		case 'X':
			cout << "you pressed X" << endl;
			break;
			
		default:
			break;
	}
}


// Main routine.
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //GLUT_DOUBLE = double buffering
	
	// initialize window -- size & location
	glutInitWindowSize(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT);
	//glutInitWindowPosition(0, 0);
	glutCreateWindow("Spectrometer Graph");

	setup();
	
	// specify functions for OpenGL 
	glutDisplayFunc(drawScene); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyInput);
	glutIdleFunc(onIdle);
	
	glutMainLoop(); // this blocks; nothing past here is executed

	return 0;
}

