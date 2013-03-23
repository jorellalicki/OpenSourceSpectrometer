/*
	TODO:
	Implemnt appropriate data-polling
	This should probably happen in display function, after flushing
*/

#include <GL/glut.h>
#include <iostream>

using namespace std;

#define WINDOW_INIT_WIDTH 1000
#define WINDOW_INIT_HEIGHT 800

// This can be used to do stuff while idling
void onIdle(void) {
}

// OpenGL display routine
void drawScene(void)
{
	cout << "drawScene" << endl;


	// *** BEGIN Drawing ***
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	// draw a test rectangle...	
	glBegin(GL_QUADS);
	unsigned int x1 = 60, y1 = 22, x2 = 200, y2 = 37;
	glVertex2f(x1, y1); glVertex2f(2*x2, y1); glVertex2f(x2, y2); glVertex2f(x1, y2);
	glEnd();
	
	
	// *** END Drawing ***
	
	// Use double-buffering to prevent tearing
	glutSwapBuffers();
	
	// Force re-display (flush)
	glutPostRedisplay();
	
	
	// TODO: poll spectrometer here, and analyze data	
	
		
	//glFlush(); // could possibly use this instead of glutpostredisplay?
}

// OpenGL window reshape/resize routine.
void reshape(int w, int h)
{
	/*glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float size = 5.0;
	glOrtho(-size, size, -size, size, -size, size);
	glMatrixMode(GL_MODELVIEW);*/
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0, 500, 500, 0, 0, 1);
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // not sure what this does
	
	// initialize window -- size & location
	glutInitWindowSize(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT);
	glutInitWindowPosition(100, 100);
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

