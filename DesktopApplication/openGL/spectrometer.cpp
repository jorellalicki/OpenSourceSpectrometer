#include <GL/glut.h>
#include <iostream>

using namespace std;

void drawScene(void)
{
	cout << "drawScene" << endl;
	glClear (GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	
	glFlush();
}


void setup(void) 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	/*glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float size = 5.0;
	glOrtho(-size, size, -size, size, -size, size);
	glMatrixMode(GL_MODELVIEW);*/
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
	glutReshapeFunc(resize);  
	glutKeyboardFunc(keyInput);
	glutMainLoop(); 

	return 0;  
}

