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
    virtual string toStringSpecial() const = 0;
    string toString() const{
        stringstream ss;
        ss << toStringSpecial() << endl;
        ss << "Centre:" << c << " Elevation:" << elevation ;
        ss << " Surface:" << surface();
        ss << " Volume:" << volume();
        ss << endl;
        return ss.str();
    }
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
private:
    double radius;
    
};
ostream& operator<<(ostream& os, const Circle& c) {
     return os << c.toString();
 }
int main(){
    // Point p1(1.2, 3.4);
    // Point p2;
    // Rectangle r1(1.2, 3.4, 10, 20, 30);
    // Circle c1(1.2, 3.4, 10, 20);
    // cout << r1 << endl;
    // cout << r1.surface() << endl;
    // Shape& s1 = r1;
    // Shape s2 = c1;
    // cout << s2.surface() << endl; 
    // 
    // Rectangle r1(1,1,1,1,1);
    // Shape& s1 = r1;
    // cout << s1.surface() << endl;
    // Circle c1(1,1,1,1);
    // Shape* s2 = &c1;
    // cout << s2->surface() << endl;
    vector<Shape*> v  = {new Circle(1,1,1,1), new Rectangle(1,1,1,1,1), new Circle(1,2,1,1)};
    for (const auto& s : v) {
        cout << *s << endl;
    }
    return 0;
}   

