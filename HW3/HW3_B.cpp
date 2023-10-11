#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2, float scale) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;
    float x = x1 * scale, y = y1 * scale;

    for (int i = 0; i <= steps; ++i) {
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        x += xIncrement * scale;
        y += yIncrement * scale;
    }
}

void render(GLFWwindow* window, int x1, int y1, int x2, int y2, float scale) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Warna garis (putih)
    drawLineDDA(x1, y1, x2, y2, scale);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "DDA Line Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glOrtho(0, 800, 0, 600, -1, 1);

    int x1 = 4;
    int y1 = 8;
    int x2 = 1;
    int y2 = 12;

    // Faktor skala untuk memperbesar garis
    float scale = 30.0;

    while (!glfwWindowShouldClose(window)) {
        render(window, x1, y1, x2, y2, scale);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
