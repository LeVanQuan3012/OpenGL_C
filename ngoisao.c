#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	GLfloat step = 3.14/6.0;
	register int i;
	GLfloat angle,r;
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<12; i++){
		r = (i%2 ==0 ? 5:15);
		angle = i * step;
		glVertex3f(r*cos(angle), r*sin(angle),0.0);
	}	
	glEnd();
	
	
	glFlush ();
	
	
}
void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 3.0, 0.0, 3.0, -1.0, 1.0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);// Kh?i t?o Glut v� x? l� m?i d�ng l?nh d?i s?, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng m� h�nh RGBA
	glutInitWindowSize (500, 500);// k�ch c? c?a s? 
	glutInitWindowPosition (100, 100);// ch? ra v? tr� m�n h�nh g�c tr�n b�n tr�i
	glutCreateWindow ("hello"); // T?o ti�u d? c?a s? �hello�
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}

