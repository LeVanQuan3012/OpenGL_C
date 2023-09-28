#include <GL/gl.h>
#include <GL/glut.h>

void MidPoint(int x1, int y1, int x2, int y2){
	int x, y, dx, dy, d;
	x = x1;
	y = y1;
	dx = x2-x1;
	dy = y2-y1;
	d = -dx + 2*dy;
	int i,j;
	while(x<=x2){
		if((x%20)<10){
			for(i=-5; i<5; i++){
				glVertex2i(x,y+i);
			}
		}
		
		//glVertex2i(x,y);
		if(d>=0){
			y++;
			d = d + 2*dy - 2*dx;
		}
		else{
			d = d + 2*dy;
		}
		x++;
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0); //mau cua doi tuong do hoa
	glBegin(GL_POINTS);
		MidPoint(1,1,120,100);
	glEnd();
	glFlush ();
}
void init (void){
glClearColor (0.0, 0.0, 0.0, 0.0);//dinh nghia mau nen cua so
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);//
}

int main(int argc, char** argv){
	glutInit(&argc, argv);// Khoi tao Glut và xu ly moi dong lenh doi so, 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// su dung mô hình RGBA
	glutInitWindowSize (400,400);// kich co cua so 
	glutInitWindowPosition (100, 100);// chi ra vi trí màn hình góc trên bên trái
	glutCreateWindow ("hello"); // Tao tiêu de cua so “hello”
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; 
}


