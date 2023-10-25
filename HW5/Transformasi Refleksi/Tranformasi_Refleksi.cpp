#include <GL/glut.h>

// Koordinat titik A dan B
float A[] = { 7.0f, 6.0f };
float B[] = { 7.0f, 4.0f };

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 15, 0, 10);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar garis sebelum refleksi dengan warna merah
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(A[0], A[1]);
    glVertex2f(B[0], B[1]);
    glEnd();

    // Melakukan transformasi refleksi
    A[1] = -A[1];
    B[1] = -B[1];

    // Gambar garis setelah refleksi dengan warna hijau
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(A[0], A[1]);
    glVertex2f(B[0], B[1]);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Reflection Transformation with Different Colors");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
