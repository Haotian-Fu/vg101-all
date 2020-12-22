//
// Created by EricD on 2020/12/9.
//
#include"P2parkinglot.h"
Parkinglot::Parkinglot(Vec **_p0,Vec **_ber,int **_status,int **side,int _number,int _n,Vec **_pointing) {
    num=_number;
    n=_n;
    unsigned long int i=0;
    for(;i<(unsigned long)n;i++){
        p0.push_back(_p0[i]);
        ber.push_back(_ber[i]);
        status.push_back(_status[i]);
        pointing.push_back(_pointing[i]);
        Group *_g;
        switch(i%3){
            case 0:
                _g=new Car(*p0[i],*ber[i],*status[i],num);
                g.push_back(_g);
                break;
            case 1:
                _g=new rocket(*p0[i],*ber[i],*status[i],num);
                g.push_back(_g);
                break;
            case 2:
                _g=new UFO(*p0[i],*ber[i],*status[i],num,*pointing[i]);
                g.push_back(_g);
                break;
        }
    }
    ber.push_back(_ber[n]);
    status.push_back(_status[n]);
    gate=new Gate{*ber[n],*status[n]};
    for(i=n+1;i<(unsigned long)num+1;i++){
        status.push_back(_status[i]);
        Teleporter* T=new Teleporter(*status[i],num,side[i-n-1]);
        t.push_back(T);
    }

}
Parkinglot::~Parkinglot() {
    unsigned long i=0;
    for(;i<(unsigned long)n;i++){
        delete g[i];
    }
    delete gate;
    for(i=(unsigned long)n+1;i<(unsigned long)num+1;i++){
        delete t[i-n-1];
    }
}
void Parkinglot::move() {
    for(unsigned long int i=0;i<(unsigned long)n;i++){
        if(g[i]->returntype()==3){
            g[i]->special(pointing[i]);
        }else{
            g[i]->special(ber[i]);
        }
        if(g[i]->getstatus()!=-2) {
            if (gate->returnstatus() == 0 && g[i]->getAnchor().getY() <= -1.4 && g[i]->getAnchor().getY() >= -1.5) {
                gate->open(ber[(unsigned long)n], status[(unsigned long)n]);
            } else if (gate->returnstatus() == 1 && g[i]->getAnchor().getY() > 1) {
                gate->close(ber[(unsigned long)n], status[(unsigned long)n]);
                g[i]->findingslot(p0[i], ber[i], status[i],num);
            } else {
                g[i]->findingslot(p0[i], ber[i], status[i],num);
            }
            break;
        }
    }
}
void Parkinglot::draw() {
    int h=(int)ceil(1.0*num/2);
    glColor3f(0,0,0);
    glLineWidth(10);
    glBegin(GL_LINE_STRIP);
    glVertex2f(4.0,0);
    glVertex2f((GLfloat)(8+3*h),0);
    glVertex2f((GLfloat)(8+3*h),16);
    glVertex2f(0,16.0);
    glVertex2f(0,0);
    glEnd();
    glLineWidth(5);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
    for (int i=0;i<=h;i++){
        glVertex2f((GLfloat)(4+i*3),4);glVertex2f((GLfloat)(4+i*3),0);
        glVertex2f((GLfloat)(4+i*3),12);glVertex2f((GLfloat)(4+i*3),16);
    }
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0,7);glVertex2f((GLfloat)(4+h*3),7);
    glVertex2f((GLfloat)(4+h*3),9);glVertex2f(0,9);
    glEnd();
    unsigned long i=0;
    for(;i<(unsigned long)n;i++){
        g[i]->draw();
    }
    gate->draw();
    for(i=n+1;i<(unsigned long)num+1;i++){
        t[i-n-1]->draw();
    }
}

