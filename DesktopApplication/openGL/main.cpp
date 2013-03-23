#include <GL/glut.h>
#include <iostream>

using namespace std;

#define WINDOW_INIT_WIDTH 1000
#define WINDOW_INIT_HEIGHT 800

void drawScene(void)
{
	cout << "drawScene" << endl;

	unsigned int x1 = 60, y1 = 22, x2 = 200, y2 = 37;
	
	glClearColor(.5,0,0,0);
	glClear (GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	
	glBegin(GL_QUADS);
	glVertex2f(x1, y1); glVertex2f(x2, y1); glVertex2f(x2, y2); glVertex2f(x1, y2);
	glEnd();
	
	glFlush();
//	SwapBuffers();
}

// OpenGL window reshape routine.
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
	glOrtho (0, w, h, 0, 0, 1);
	glMatrixMode (GL_MODELVIEW);
}


void setup(void) 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
//	const unsigned int XSize = 640, YSize = 480;

/*	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0, XSize, YSize, 0, 0, 1);
	glMatrixMode (GL_MODELVIEW);
	
	glDisable(GL_DEPTH_TEST);*/
	reshape(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT);
	
	glDisable(GL_DEPTH_TEST);
}



// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch(key) 
	{
		case 27:
			exit(0);
			break;
		case 'x':
			cout << "you pressed x" << endl;
			break;
		default:
			break;
	}
}


// Main routine.
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("Spectrometer Graph");
	setup(); 
	glutDisplayFunc(drawScene); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyInput);
	glutMainLoop(); 

	return 0;
}

