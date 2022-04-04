#include <iostream>
using namespace std;

class rectangle;
class triangle;
class circle;

class visitor{
    public:
    virtual void visit(rectangle& s) = 0;
    virtual void visit(triangle& s) = 0;
    virtual void visit(circle& s) = 0;
};

class visitor_concrete : public visitor{
    public:
    virtual void visit(class rectangle& s) override {
        //do
    };
    virtual void visit(class triangle& s) override {
        //do
    };
    virtual void visit(class circle& s) override {
        //do
    };
};

class shape{
    public:
    virtual void accept(visitor& v) = 0;
};


class rectangle : public shape{
    private:
    int height;
    int base;
    int x;
    int y;
    public:
    virtual void accept(visitor& v) override {
        v.visit(*this);
    }
    void setRectangle(int height, int base, int x, int y){
        this -> height = height;
        this -> base = base;
        this -> x = x;
        this -> y = y;
    }
};

class triangle : public shape{
    private:
    int height;
    int base;
    int x;
    int y;
    public:
    virtual void accept(visitor& v) override {
        v.visit(*this);
    }
    void setTriangle(int height, int base, int x, int y){
        this -> height = height;
        this -> base = base;
        this -> x = x;
        this -> y = y;
    }
};

class circle : public shape{
    private:
    int rad;
    int x;
    int y;
    public:
    virtual void accept(visitor& v) override {
        v.visit(*this);
    }
    void setCircle(int rad, int x, int y){
        this -> rad = rad;
        this -> x = x;
        this -> y = y;
    }
};


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

