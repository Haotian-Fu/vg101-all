#include <GL/glut.h>
#include <cmath>

#define PI 3.1415926535

typedef struct _Point
{
    float x, y;
} Point;

class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() = 0;

protected:
    float r, g, b;
};

class Circle : public Shape
{
public:
    Circle(Point center, float radius,
           float r = 255.0, float g = 140.0, float b = 140.0);
    void draw();
    void move(float dx, float dy);

private:
    Point center;
    float radius;
};

class Rect : public Shape
{
public:
    Rect(Point pt1, Point pt2,
         float r, float g, float b); //diagonal points
    void draw();
    void move(float dx, float dy);

private:
    Point p1, p2;
};

class Triangle : public Shape
{
public:
    Triangle(Point pt1 = {-5.0, -1.0}, Point pt2 = {-7.0, -1.0}, Point pt3 = {-6.0, -2.0},
             float r = 255, float g = 0, float b = 0);
    void draw();
    void move(float dx, float dy);

private:
    Point p1, p2, p3;
};

class Parallelogram : public Shape
{
public:
    Parallelogram(Point pt1 = {5.0, 1.0}, Point pt2 = {6.0, 2.0}, Point pt3 = {6.0, 1.0},
                  float r = 153, float g = 217, float b = 234);
    void draw();
    void move(float dx, float dy);

private:
    Point p1, p2, p3, p4;
};

class Trapezium : public Shape
{
public:
    Trapezium(Point pt1 = {-3.0, 4.0}, Point pt2 = {-4.0, 2.0}, float l1 = 4.0, float l2 = 7.0,
              float r = 140, float g = 140, float b = 255); //S=0.5*(l1+l2)
    void draw();
    void move(float dx, float dy);

private:
    Point p1, p2, p3, p4;
};

class Car
{
public:
    Car();
    ~Car();
    void draw();
    void move(float dx, float dy);

private:
    Shape *car[6];
};

Shape::~Shape() {}

Rect::Rect(Point pt1, Point pt2,
           float red, float green, float blue)
{
    p1 = pt1;
    p2 = pt2;
    r = red;
    g = green;
    b = blue;
}
void Rect::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p1.x, p2.y);
    glEnd();
}
Triangle::Triangle(Point pt1, Point pt2, Point pt3,
                   float red, float green, float blue)
{
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
    r = red;
    g = green;
    b = blue;
}
void Triangle::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p3.x, p3.y);
    glEnd();
}

Parallelogram::Parallelogram(Point pt1, Point pt2, Point pt3, float red, float green, float blue)
{
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
    p4 = {pt1.x - pt2.x + pt3.x, pt3.y};
    r = red;
    g = green;
    b = blue;
}
void Parallelogram::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p1.y);
    glVertex2f(p3.x, p3.y);
    glVertex2f(p4.x, p4.y);
    glEnd();
}

Circle::Circle(Point c, float rr, float red, float green, float blue)
{
    center = c;
    radius = rr;
    r = red;
    g = green;
    b = blue;
}
void Circle::draw()
{
    glPushMatrix();
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN); //use triangle to fill it
    // glVertex2f(0.0,0.0);
    int n = 50;
    for (int i = 0; i <= n; i++)
        glVertex2f((float)(center.x + radius * cos(2 * PI / n * i)), (float)(radius * sin(2 * PI / n * i)));
    glEnd();
    glPopMatrix();
}

Trapezium::Trapezium(Point pt1, Point pt2, float l1, float l2, float red, float green, float blue)
{
    p1 = pt1;
    p2 = pt2;
    p4 = {p1.x+l1,p1.y};
    p3 = {p2.x+l2,p2.y};
    r = red;
    g = green;
    b = blue;
}
void Trapezium::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p3.x, p3.y);
    glVertex2f(p4.x, p4.y);
    glEnd();
}

Car::Car()
{
    car[0] = new Triangle({-0.5f, -0.1f}, {-0.7f, -0.1f}, {-0.6f, -0.2f}, 1, 0, 0);
    car[1] = new Parallelogram({0.5f, 0.1f}, {0.6f, 0.2f}, {0.7f, 0.2f}, 0.6f, 0.85f, 0.91f);
    car[2] = new Circle({-0.2f, 0.0f}, 0.07f, 1, 0.55f, 0.55f);
    car[3] = new Circle({0.2f, 0.0f}, 0.07f, 1, 0.55f, 0.55f);
    car[4] = new Rect({-0.3f, 0.0f}, {0.3f, 0.2f}, 0.89f, 0.89f, 0.31f);
    car[5] = new Trapezium({-0.28f, 0.4f}, {-0.3f, 0.2f}, 0.4f, 0.6f, 0.55f, 0.55f, 1);
}

Car::~Car()
{
    for (int i = 0; i < 6; i++)
        delete car[i];
}

void Car::draw()
{
    for (int i = 0; i < 6; i++)
        car[i]->draw();
}

void TimeStep(int n)
{
    glutTimerFunc((unsigned int)n, TimeStep, n);
    glutPostRedisplay();
}

void glDraw()
{
    Car a;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    a.draw();
    glutSwapBuffers();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("ex2");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 25);
    glutMainLoop();
}
