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
	glutInit(&argc, argv);// Kh?i t?o Glut và x? lí m?i dòng l?nh d?i s?, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng mô hình RGBA
	glutInitWindowSize (500, 500);// kích c? c?a s? 
	glutInitWindowPosition (100, 100);// ch? ra v? trí màn hình góc trên bên trái
	glutCreateWindow ("hello"); // T?o tiêu d? c?a s? “hello”
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}

