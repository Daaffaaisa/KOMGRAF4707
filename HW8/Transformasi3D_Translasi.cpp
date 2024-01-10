#include <GL/glut.h>

float translateX = 0.0f;
float translateY = 0.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Posisi kamera
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Transformasi translasi
    glTranslatef(translateX, translateY, 0.0f);

    // Gambar model 3D (contoh: kubus)
    glutWireCube(1.0);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        translateX -= 0.1f;
        break;
    case 'd':
        translateX += 0.1f;
        break;
    case 'w':
        translateY += 0.1f;
        break;
    case 's':
        translateY -= 0.1f;
        break;
    case 27: // ASCII untuk tombol Esc
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL 3D Transformasi Translasi");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
