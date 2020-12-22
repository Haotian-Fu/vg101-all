#include <GL/glut.h>
#include <iostream>
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


class Truck
{
public:
    Truck();
    ~Truck();
    void draw();
    void move(float dx, float dy);

private:
    Shape *car[5];
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
void Rect::move(float dx, float dy)
{
    p1.x += dx;
    p1.y += dy;
    p2.x += dx;
    p2.y += dy;
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
void Circle::move(float dx, float dy)
{
    center.x += dx;
    center.y += dy;
}


Truck::Truck()
{
    car[0] = new Circle({0.1f, 0.45f}, 0.05f, 1, 0.55f, 0.55f);
    car[1] = new Circle({0.2f, 0.45f}, 0.05f, 1, 0.55f, 0.55f);
    car[2] = new Rect({0.05f, 0.45f}, {0.25f, 0.6f}, 0.89f, 1, 0.31f);
    car[3] = new Rect({0.25f, 0.45f}, {0.3f, 0.55f}, 0.77f, 0.59f, 0.31f);
    car[4] = new Rect({0.0f, 0.0f}, {0.5f, 0.4f}, 0.89f, 0.89f, 0.31f);//cliff
}

Truck::~Truck()
{
    for (int i = 0; i < 4; i++)
        delete car[i];
}

void Truck::draw()
{
    for (int i = 0; i < 4; i++)
        car[i]->draw();
}
void Truck::move(float dx, float dy)
{
    for (int i = 0; i < 3; i++)
        car[i]->move(dx, dy);
}

void TimeStep(int n)
{
    glutTimerFunc((unsigned int)n, TimeStep, n);
    glutPostRedisplay();
}

void glDraw()
{
    float dr = 0;
    Truck a;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    a.draw();
    while (dr < 0.25f)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        dr += 0.0001f;
        a.move(0.0001f, 0);
        a.draw();
        //glutSwapBuffers();
        glFlush();
    }
    while (dr >= 0.5f)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        a.move(0,-0.0001f);
        a.draw();
        //glutSwapBuffers();
        glFlush();
    }
    glutSwapBuffers();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("ex1");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 25);
    glutMainLoop();
}



