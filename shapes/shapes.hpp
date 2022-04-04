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
    virtual void visit(rectangle& s);
    virtual void visit(triangle& s);
    virtual void visit(circle& s);
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
    virtual void accept(visitor& v);
    void setRectangle(int height, int base, int x, int y);
};

class triangle : public shape{
    private:
    int height;
    int base;
    int x;
    int y;
    public:
    virtual void accept(visitor& v);
    void setTriangle(int height, int base, int x, int y);
};

class circle : public shape{
    private:
    int rad;
    int x;
    int y;
    public:
    virtual void accept(visitor& v);
    void setCircle(int rad, int x, int y);
};