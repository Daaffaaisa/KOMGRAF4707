#include <GL/glut.h>

GLfloat scaleX = 1.0f;   // Faktor skala pada sumbu X
GLfloat scaleY = 1.0f;   // Faktor skala pada sumbu Y
GLfloat scaleZ = 1.0f;   // Faktor skala pada sumbu Z

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Skala objek
    glScalef(scaleX, scaleY, scaleZ);

    // Gambar objek 3D (misalnya, kubus)
    glutWireCube(1.0);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':  // Memperbesar objek
        scaleX += 0.1f;
        scaleY += 0.1f;
        scaleZ += 0.1f;
        break;
    case 's':  // Memperkecil objek
        scaleX -= 0.1f;
        scaleY -= 0.1f;
        scaleZ -= 0.1f;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OpenGL 3D Skala");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Tambahkan inisialisasi skala awal di sini jika diinginkan
    // scaleX = 1.0f;
    // scaleY = 1.0f;
    // scaleZ = 1.0f;

    glutMainLoop();

    return 0;
}
