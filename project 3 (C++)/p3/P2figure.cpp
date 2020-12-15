//
// Created by EricD on 2020/12/10.
//
#include "P2figure.h"
Vec::Vec(float _x, float _y){x = _x; y = _y;}
float Vec::getX() {return x;}
float Vec:: getY() {return y;}
Vec Vec::operator+(Vec v){return Vec(x + v.getX(), y + v.getY());}
Vec Vec::operator- (Vec v){return Vec(x-v.getX(),y-v.getY());}
Vec Vec::operator* (float k){return Vec(x*k,y*k);}
float Vec::operator* (Vec v){return x*v.getX()+y*v.getY();}
Vec Vec::operator<<(float a){return Vec(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}
Vec Vec:: operator>>(float a){return Vec(x*cos(-a)-y*sin(-a),x*sin(-a)+y*cos(-a));}
float Vec:: norm(){return (float)sqrt(pow(x,2)+pow(y,2));}

Figure::Figure() : anchor(0, 0) {}
Vec Figure::getAnchor() {return anchor;}

Gate::Gate(Vec _ber,int _status) {
    anchor={0,0};
    dir=_ber;
    p=anchor+dir*4;
    status=_status;
}
void Gate::draw() {
    glLineWidth(5);
    glColor3f(1.0f,0.1f,0.1f);
    glBegin(GL_LINES);
    glVertex2f(anchor.getX(),anchor.getY());
    glVertex2f(p.getX(),p.getY());
    glEnd();
}
void Gate::open(Vec *_ber,int *_status){
    dir=dir<<PI/(2*50);*_ber=dir;
    if(dir.getX()<=0){
        status=1;
        *_status=status;
    }
}
void Gate::close(Vec *_ber, int *_status) {
    dir=dir>>PI/(2*50);*_ber=dir;
    if(dir.getY()<=0){
        status=0;
        *_status=status;
    }
}
int Gate::returnstatus() {
    return status;
}

Line::Line(Vec ra, Vec rb, Vec anc) {
    t1 = ra;t2 = rb;
    r = 1;g = 0;b = 0;
    anchor=anc;
}
void Line::draw() {
    glColor3f((float)r, (float)g, (float)b);
    glBegin(GL_LINES);
    glVertex2f((float)t1.getX()+anchor.getX(), (float)t1.getY()+anchor.getY());
    glVertex2f((float)t2.getX()+anchor.getX(), (float)t2.getY()+anchor.getY());
    glEnd();
}
Triangle::Triangle(Vec _t1, Vec _t2, Vec _t3, Vec _anc,float _r,float _g,float _b){t1=_t1;t2=_t2;t3=_t3;anchor=_anc;r=_r;g=_g;b=_b;}
void Triangle::draw() {
    glColor3f(r, g, b);glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(anchor.getX()+t1.getX(),anchor.getY()+t1.getY());
    glVertex2f(anchor.getX()+t2.getX(),anchor.getY()+t2.getY());
    glVertex2f(anchor.getX()+t3.getX(),anchor.getY()+t3.getY());glEnd();
}

Trapezium::Trapezium(Vec _ll, Vec _lr, Vec _ul, Vec _ur, Vec _anc,float _r,float _g,float _b) {t1=_ll;t2=_lr;t3=_ul;t4=_ur;anchor=_anc;r=_r;g=_g;b=_b;}
void Trapezium::draw() {
    glColor3f(r, g, b);glBegin(GL_QUADS);
    glVertex2f(anchor.getX() + t1.getX(), anchor.getY() + t1.getY());
    glVertex2f(anchor.getX() + t2.getX(), anchor.getY() + t2.getY());
    glVertex2f(anchor.getX() + t3.getX(), anchor.getY() + t3.getY());
    glVertex2f(anchor.getX() + t4.getX(), anchor.getY() + t4.getY());
    glEnd();
}

void Teleporter::changeside(int *_side) {
    bool static flag=0;
    if(flag==0&&*_side<300){*_side=*_side+1;
    }else if(*_side>=0){
        *_side=*_side-1;
        flag=1;
    }else flag=0;

}
Teleporter::Teleporter(int _status,int _num,int *_side) {
    side=3+*_side/50;
    if(_status>=1&&_status<=(int)ceil(1.0*_num/2)){
        anchor={2.5f+(float)(3*_status),2};
    }else{
        anchor={2.5f+(float)(3*(2*(int)ceil(1.0*_num/2)+1-_status)),14};
    }
    setcolor();
    changeside(_side);
}

void Teleporter::draw() {
    glColor3f(r, g, b);glBegin(GL_POLYGON);
    for(int i=0;i<side;i++){
        glVertex2f(anchor.getX()+1.5f*(float)cos(2*PI*(float)i/(float)side+(float)PI/4),\
        anchor.getY()+1.5f*(float)sin(2*PI*(float)i/(float)side+(float)PI/4));
    }
    glEnd();
}
void Teleporter::setcolor() {
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}

Circle::Circle(Vec pos,Vec _anc, float Radius,float _r,float _g,float _b) {anchor=pos+_anc;R=Radius;r=_r;g=_g;b=_b;}
void Circle::draw() {
    glColor3f(r, g, b);glBegin(GL_POLYGON);
    int i;
    for(i=0;i<100;i++) glVertex2f(anchor.getX()+R*(float)cos(2*PI*(float)i/100),anchor.getY()+R*(float)sin(2*PI*(float)i/100));
    glEnd();
}

SemiCircle::SemiCircle(Vec pos, Vec anc,Vec pointing,float Radius, float _r,float _g,float _b){anchor=pos+anc,R=Radius;r=_r;g=_g;b=_b;pnt=pointing;}
void SemiCircle::draw(){
    glColor3f(r, g, b);glBegin(GL_POLYGON);
    int i;
    for(i=0;i<100;i++) {
        glVertex2f(anchor.getX()+R*(float)cos((float)PI/2*(float)i/100+(float)atan2((float)pnt.getY(),(float)pnt.getX())),\
        anchor.getY()+R*(float)sin((float)PI/2*(float)i/100+(float)atan2((float)pnt.getY(),(float)pnt.getX())));
        glVertex2f(anchor.getX()+R*(float)cos(-(float)PI/2*(float)i/100+(float)atan2((float)pnt.getY(),(float)pnt.getX())),\
        anchor.getY()+R*(float)sin(-(float)PI/2*(float)i/100+(float)atan2((float)pnt.getY(),(float)pnt.getX())));
    }
    glEnd();
}

Group::Group() {}
Group::~Group() {}
void Group::move(Vec *p0,float step) {anchor=anchor+y*(1.0f/y.norm())*step;*p0=anchor;}
void Group::rotate(float angle,Vec *ber) {
    if(angle>0){y=y>>angle;*ber=y;}
    else {y=y<<-angle;*ber=y;}
}

void Group::findingslot(Vec *_p0,Vec *_ber,int *_status,int _n) {
    if(status==0) {//reverse turning
        move(_p0, (float)-sin(PI / (100 * 2) * 1.5));
        rotate((float)-PI / (2 * 100), _ber);
        if (y.getX() < 0.0005f && y.getX() > -0.0005f) {status = -1;*_status = status;}
    }else if(status==-1){//reversing
        move(_p0,-V);
        if((anchor.getY()<2.2f&&anchor.getY()>1.8f)||(anchor.getY()>13.8f&&anchor.getY()<14.2f)){
            status=-2;*_status=status;
        }
    }else if(status>0&&anchor.getX()>slotpos.getX()-0.2f&&anchor.getX()<slotpos.getX()+0.2f&&anchor.getY()>slotpos.getY()-1.5f&&anchor.getY()<slotpos.getY()+1.5f){
        status=0;*_status=status;//reach the parking point
    }else if(status>0&&anchor.getX()==2.5f&&anchor.getY()<4) {
        move(_p0, V);
    }else if(status>0&&anchor.getX()<=4&&anchor.getY()<=7&&y.getY()>0){
        move(_p0,(float)sin(PI/(100*2)*1.5));
        rotate((float)PI/(2*100),_ber);
    }else if(status>0&&anchor.getX()<=(float)(4+3*(int)ceil(1.0*_n/2))&&anchor.getY()<=7){
        move(_p0,V);
    }else if(status>0&&anchor.getY()<=7&&y.getX()>0){
        move(_p0,(float)sin(PI / (100 * 2) * 1.5));
        rotate((float)-PI/(2*100),_ber);
    }else if(status>0&&anchor.getY()<=9){
        move(_p0,V);
    }else if(status>0&&anchor.getX()>=(float)(4+3*(int)ceil(1.0*_n/2))&&y.getY()>0){
        move(_p0,(float)sin(PI / (100 * 2) * 1.5));
        rotate((float)-PI/(2*100),_ber);
    }else if(status>0&&anchor.getX()>=2){
        move(_p0,V);
    }
}
int Group::getstatus() {
    return status;
}

rocket::rocket(Vec p0, Vec ber,int _status,int _n) {
    anchor=p0;status=_status;y=ber;
    x={y.getY(),-y.getX()};
    Vec p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
    p1=x*-1.8f-y*4;p2=x*1.8f-y*4;p3=x*1.8f+y*4;p4=x*-1.8f+y*4;p5=y*6;
    p6=x*-1.8f;p7=x*-4-y*4;p8=x*4-y*4;p9=x*1.8f;p10=x*-2-y*5,p11=x*2-y*5;
    s[0]=new Trapezium(p1,p2,p3,p4,anchor,0.8f,0.8f,0.8f);
    s[1]=new Triangle(p2,p8,p9,anchor,0.3f,0.5f,0.8f);
    s[2]=new Triangle(p4,p3,p5,anchor,0.8f,0.1f,0.1f);
    s[3]=new Triangle(p7,p1,p6,anchor,0.3f,0.5f,0.8f);
    s[4]=new Trapezium(p10,p11,p2,p1,anchor,0.2f,0.5f,0);
    if(status>=1&&status<=(int)ceil(1.0*_n/2))slotpos={(float)(4+3*status),5.5f};
    else slotpos={(float)4+(float)(3*(int)ceil(1.0*_n/2))-(float)(3*(status-(int)ceil(1.0*_n/2))),10.5f};
    type=1;
}
int rocket::returntype() {return type;}
rocket::~rocket() {for(int i=0;i<5;i++)delete s[i];}
void rocket::draw() {for(int i=0;i<5;i++)s[i]->draw();}
void rocket::special(Vec *ber) {
    int static flag=0;
    if(flag==0&&y.norm()<=0.25f){
        y=y*1.01f;
        *ber=y;
    }else if(y.norm()>=0.15f){
        flag=1;
        y=y*0.99f;
        *ber=y;
    }else{
        flag=0;
    }
}

Car::Car(Vec p0, Vec ber,int _status,int _n) {
    status=_status;anchor=p0;y=ber*(1.0f/ber.norm())*0.2f;x={y.getY(),-y.getX()};
    flag=Vec{-ber.getY(),ber.getX()};
    s[0]=new Circle(y*-2+x*3,anchor,y.norm(),0.5f,0.5f,0.5f);
    s[1]=new Circle(y*2+x*3,anchor,y.norm(),0.5f,0.5f,0.5f);
    s[2]=new Trapezium(y*-3,y*3,y*2-x*2,y*-2-x*2,anchor,0.2f,0.2f,0.7f);
    s[3]=new Trapezium(x*3-y*4,y*4.5+x*3,y*4,y*-4,anchor,0.1f,0.8f,0.8f);
    s[4]=new Triangle(flag-y*4,flag-x-y*4,flag-x*0.5f-y*6,anchor,1,0,0);
    if(status>=1&&status<=(int)ceil(1.0*_n/2))slotpos={(float)(4+3*status),5.5f};
    else slotpos={(float)4+(float)(3*(int)ceil(1.0*_n/2))-(float)(3*(status-(int)ceil(1.0*_n/2))),10.5f};
    type=2;
}
void Car::special(Vec *ber){
    if(status>0){
        int static up=1;
        if (up==1&&flag.norm()<=0.5) {
            flag=flag-x*0.05f;
            *ber={flag.getY(),-flag.getX()};
        }else if(flag.norm()>=0.1) {
            flag=flag+x*0.05f;
            *ber={flag.getY(),-flag.getX()};
            up=0;
        }else up=1;
    }
}
void Car::draw() {
    for(int i=0;i<5;i++) s[i]->draw();
    glColor3f(0.2f,0.2f,0.2f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f((anchor+y*-4).getX(),(anchor+y*-4).getY());
    glVertex2f((anchor+y*-4-x*4).getX(),(anchor+y*-4-x*4).getY());
    glEnd();
}
int Car::returntype() {return type;}
Car::~Car(){
    for(int i=0;i<5;i++) delete s[i];
}

UFO::UFO(Vec anc, Vec ber, int _status, int _n,Vec _pointing) {
    status=_status;anchor=anc;y=ber*(1.0f/ber.norm())*0.2f;x={y.getY(),-y.getX()};
    _y=_pointing;_x={_y.getY(),-_y.getX()};
    Vec p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;
    p1 ={0,0};p2 =_x * 7.07f + _y * 7.07f;
    p3 =_x * -7.07f + _y * 7.07f;p4 =_x * 10.605f + _y * 10.605f;
    p5 = _x * -10.605f + _y * 10.605f;p6 = _x * -8;
    p7 = _x * -2;p8 =  _y * -2;
    p9 = _x * -10 - _y * 2;p10 = _x * 2;
    p11 = _x * 8;p12 = _x * 10 - _y * 2;
    p13 = _y * -2;
    s[0] = new SemiCircle(p1,anchor,_y,1,0.1f,0.1f,1);
    s[1] = new Trapezium(p6, p7, p8, p9,anchor,0.5f,0.5f,0.1f);
    s[2] = new Trapezium(p10, p11, p12, p13,anchor,0.5f,0.5f,0.1f);
    s[3] = new Line(p3, p5,anchor);
    s[4] = new Line(p2, p4,anchor);
    if(status>=1&&status<=(int)ceil(1.0*_n/2))slotpos={(float)(4+3*status),5.5f};
    else slotpos={(float)4+(float)(3*(int)ceil(1.0*_n/2))-(float)(3*(status-(int)ceil(1.0*_n/2))),10.5f};
    type=3;
}

UFO::~UFO(){
    for (int i = 0; i < 5; i++)delete s[i];
}
int UFO::returntype() {return type;}
void UFO::special(Vec *pointing) {
    _y=_y>>0.1f;
    *pointing=_y;
}
void UFO::draw() {
    for (int i = 0; i < 5; i++)s[i]->draw();
}