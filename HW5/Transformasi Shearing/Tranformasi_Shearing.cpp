#include <GL/glut.h>

int window_width = 800;
int window_height = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, window_width, 0, window_height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Titik awal A(7,6) dan B(7,4)
    float points[] = {
        7, 6,
        7, 4
    };

    // Shearing matrix untuk melakukan shear horizontal
    float shearMatrix[] = {
        1, 1, 0,
        0, 1, 0,
        0, 0, 1
    };

    // Transformasi shear
    for (int i = 0; i < 2; i++) {
        float x = points[i * 2];
        float y = points[i * 2 + 1];
        points[i * 2] = x + y;
        points[i * 2 + 1] = y;
    }

    // Perbesar 5x lipat
    for (int i = 0; i < 2; i++) {
        points[i * 2] *= 5;
        points[i * 2 + 1] *= 5;
    }

    // Pusatkan di tengah jendela
    for (int i = 0; i < 2; i++) {
        points[i * 2] += window_width / 2;
        points[i * 2 + 1] += window_height / 2;
    }

    glPointSize(5.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2f(points[0], points[1]);
    glVertex2f(points[2], points[3]);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(window_width / 2, window_height / 2);
    glVertex2f(points[0], points[1]);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Shearing Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
