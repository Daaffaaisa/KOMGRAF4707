#include <GLFW/glfw3.h>
#include <iostream>

// Struct untuk merepresentasikan titik
struct Point {
    double x, y;
};

// Fungsi untuk menggambar garis antara dua titik
void drawLine(const Point& p1, const Point& p2) {
    glBegin(GL_LINES);
    glVertex2d(p1.x, p1.y);
    glVertex2d(p2.x, p2.y);
    glEnd();
}

// Fungsi untuk menggambar titik potong
void drawIntersectionPoint(const Point& intersectionPoint) {
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk titik potong
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2d(intersectionPoint.x, intersectionPoint.y);
    glEnd();
}

// Fungsi untuk menghitung titik potong
Point calculateIntersectionPoint(const Point& p1, const Point& p2, const Point& q1, const Point& q2) {
    Point intersectionPoint;

    double m1 = (p2.y - p1.y) / (p2.x - p1.x);
    double m2 = (q2.y - q1.y) / (q2.x - q1.x);

    intersectionPoint.x = (m1 * p1.x - p1.y - m2 * q1.x + q1.y) / (m1 - m2);
    intersectionPoint.y = m1 * (intersectionPoint.x - p1.x) + p1.y;

    return intersectionPoint;
}

int main() {
    GLFWwindow* window;

    // Inisialisasi GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Membuat window
    window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Mengatur window sebagai konteks utama
    glfwMakeContextCurrent(window);

    // Loop utama
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Garis P
        Point p1 = { -1, -2 };
        Point p2 = { 5, 6 };
        drawLine(p1, p2);

        // Garis Q
        Point q1 = { -1, 5 };
        Point q2 = { 6, 7 };
        drawLine(q1, q2);

        // Menghitung dan menggambar titik potong
        Point intersectionPoint = calculateIntersectionPoint(p1, p2, q1, q2);

        if (intersectionPoint.x >= 1 && intersectionPoint.x <= 4 && intersectionPoint.y <= 5) {
            drawIntersectionPoint(intersectionPoint);
        }

        glfwSwapBuffers(window);

        // Menunggu event
        glfwPollEvents();
    }

    // Membersihkan GLFW
    glfwTerminate();

    return 0;
}
