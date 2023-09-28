#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    GLfloat step = 3.14 / 180.0;
	register int i;
	GLfloat angle, r;
	//ve nua duoi so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			r = (i % 2 == 0 ? 10 : 20);
			angle = i * step;
			if(r*sin(angle)-15>0) {
				glVertex3f(r*cos(angle), 0.0, 0.0);
			}
			else
				glVertex3f(r*cos(angle), r*sin(angle)-15, 0.0);
		}
	glEnd();
	
	//ve nua tren so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			r = (i % 2 == 0 ? 10 : 20);
			angle = i * step;
			if(r*sin(angle)+15<0) {
				glVertex3f(r*cos(angle), 0, 0.0);
			}
			else
				glVertex3f(r*cos(angle), r*sin(angle)+15, 0.0);
		}
	glEnd();
	
	//ve vien ngoai duong tron to nua duoi so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			angle = i * step;
			if(20 * sin(angle)-15<0)
				glVertex3f(20 * cos(angle), 20 * sin(angle)-15, 0.0);
		}
	glEnd();
	
	//ve vien ngoai duong tron to nua tren so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			angle = i * step;
			if(20 * sin(angle)+15>0)
				glVertex3f(20 * cos(angle), 20 * sin(angle)+15, 0.0);
		}
	glEnd();
	
	//ve vien ngoai duong tron nho tren so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			angle = i * step;
			glVertex3f(10 * cos(angle), 10 * sin(angle)+15,0.0);
		}
	glEnd();
	
	//ve vien ngoai duong tron nho duoi so 8
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < 360; i++) {
			angle = i * step;
			glVertex3f(10 * cos(angle), 10 * sin(angle)-15,0.0);
		}
	glEnd();
    glFlush ();
}

void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW); // Thêm dòng này
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Le Van Quan - 2151170561");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

