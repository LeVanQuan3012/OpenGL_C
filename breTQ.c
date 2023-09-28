#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdbool.h>

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int d = dx - dy;
    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    bool done = false;
    while (!done) {
        glVertex2i(x, y);

        if (x == x2 && y == y2) {
            done = true;
        }

        int doubleError = 2 * d;

        if (doubleError > -dy) {
            d -= dy;
            x += sx;
        }

        if (doubleError < dx) {
            d += dx;
            y += sy;
        }
    }
    glEnd();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
		bresenham(200,200,40,50);
		bresenham(200,200,50,200);
		bresenham(200,200,50,300);
   		bresenham(200,200,200,400);
   		bresenham(200,200,300,320);
		bresenham(200,200,300,200);
		bresenham(200,200,400,60);
		bresenham(200,200,200,60);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
