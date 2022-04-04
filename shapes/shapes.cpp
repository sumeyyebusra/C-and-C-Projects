#include "shapes.hpp"

void visitor_concrete::visit(class rectangle& s){
    cout << "Rectangle" << endl;
}
void visitor_concrete::visit(class triangle& s){
        cout << "Triangle" << endl;
}
void visitor_concrete::visit(class circle& s){
        cout << "Circle" << endl;
}

void rectangle::accept(visitor& v){
        v.visit(*this);
}
void rectangle::setRectangle(int height, int base, int x, int y){
    this -> height = height;
    this -> base = base;
    this -> x = x;
    this -> y = y;
}

void triangle::accept(visitor& v){
    v.visit(*this);
}
void triangle::setTriangle(int height, int base, int x, int y){
    this -> height = height;
    this -> base = base;
    this -> x = x;
    this -> y = y;
}


void circle::accept(visitor& v){
    v.visit(*this);
}

void circle::setCircle(int rad, int x, int y){
    this -> rad = rad;
    this -> x = x;
    this -> y = y;
}


int main(){
    triangle x;
    x.setTriangle(10,3,2,5);
    rectangle y;
    y.setRectangle(5,4,1,3);
    circle z;
    z.setCircle(10,7,4);

    shape& s1 = x;
    shape& s2 = y;
    shape& s3 = z;

    visitor_concrete v;
    s1.accept(v);
    s2.accept(v);
    s3.accept(v);
    return 0;
}