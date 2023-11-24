#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
const double PI = 3.1415926535897932384626433;
class Point{
  public:
    Point(double x, double y): x(x), y(y) {}
    
    Point(double a = 0):  x(a),y(a) {}
        
    string toString() const {
        stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }
  
  private:
    double x;
    double y;
};

ostream& operator<<(ostream& os, const Point& p) {
    os << p.toString();
    return os;
}
class Shape{

    public:
    Shape(double x = 0, double y = 0, double elevation =0):c(x,y), elevation(elevation) {}
    
    double volume() const {
        return elevation * surface();
    }
    virtual double surface() const = 0;
   
    string toString() const{
        stringstream ss;
        ss << toStringSpecial() << endl;
        ss << "Centre:" << c << " Elevation:" << elevation ;
        ss << " Surface:" << surface();
        ss << " Volume:" << volume();
        ss << endl;
        return ss.str();
    }
    virtual Shape* copy() const = 0;

    protected:
    virtual string toStringSpecial() const = 0;
    private:
    Point c;
    double elevation;
};
ostream& operator<<(ostream& os, const Shape& s) {
    return os << s.toString();
}
class Rectangle: public Shape{
public:
Rectangle(double x = 0, double y = 0, double elevation = 0, double width = 0, double height = 0):
Shape(x,y,elevation), width(width), height(height) { }

string toStringSpecial() const override {
    stringstream ss;
    ss << "Rectangle - " << " Width:" << width << " Height:" << height ;
    return ss.str();
}
double surface() const override{
    return width*height;
}
Shape* copy() const override{
    return new Rectangle(*this);
}    
private:
    double width;
    double height;
};
ostream& operator<<(ostream& os, const Rectangle& r) {
     return os << r.toString();
 }

class Circle: public Shape{
public:
Circle(double x = 0, double y = 0, double elevation = 0, double radius = 0):
Shape(x,y,elevation), radius(radius) { }

string toStringSpecial() const override{
    stringstream ss;
    ss << "Cercle - " <<" Radius:" << radius;
    return ss.str();
}
double surface() const override{
    return PI*radius*radius;
}
Shape* copy() const override{
    return new Circle(*this);
}   
private:
    double radius;
    
};
ostream& operator<<(ostream& os, const Circle& c) {
     return os << c.toString();
 }

class Canvas{
public:
Canvas() {}
~Canvas(){
    for(auto& s: shapes){
       delete s;
       s = nullptr;
    }   
} 
Canvas(const Canvas& c){
    for(const auto& s: c.shapes){
        shapes.push_back(s->copy());
    }
}    
Canvas& operator=(Canvas c){
    swap(c, *this);
    return *this;
}    

void addShape(const Shape& shape)  {
    shapes.push_back(shape.copy());

}    
void display() const{
    for (const auto& s: shapes){
        cout << *s << endl;
}
}
private:
vector<Shape*> shapes;
friend void swap(Canvas& a, Canvas& b);
} ;
void swap(Canvas& a, Canvas& b){
    using std::swap;
    swap(a.shapes, b.shapes);
}    
int main(){
    Canvas canvas;
    Circle c1(1,2,3,4);
    canvas.addShape(c1);
    Rectangle r1(1,2,3,4,5);
    canvas.addShape(r1);
    cout << "Canvas 1" << endl;
    canvas.display();
    Canvas canvas2(canvas);
    canvas2.display();
    canvas = canvas2;
    canvas.display();
    
    return 0;
}   

