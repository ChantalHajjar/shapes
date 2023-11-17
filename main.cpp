#include <iostream>
#include <sstream>
using namespace std;

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
    Shape(double x = 0, double y = 0, double elevation =0):c(x,y), elevation(elevation) {cout << "Shape created" << endl;}
    
    virtual double surface() const{
        return -1;
    }
    protected:
    string toStringS() const{
        stringstream ss;
        ss << "Centre:" << c << " Elevation:" << elevation << endl;
        return ss.str();
    }
    private:
    Point c;
    double elevation;
};
// ostream& operator<<(ostream& os, const Shape& s) {
//     return os << s.toStringS();
// }
class Rectangle: public Shape{
public:
Rectangle(double x = 0, double y = 0, double elevation = 0, double width = 0, double height = 0):
Shape(x,y,elevation), width(width), height(height) { cout << "Rectangle created" << endl;}

string toString() const{
    stringstream ss;
    ss << toStringS() << " Width:" << width << " Height:" << height << endl;
    return ss.str();
}
double surface() const{
    return width*height;
}
private:
    double width;
    double height;
};
ostream& operator<<(ostream& os, const Rectangle& r) {
     return os << r.toString();
 }
int main(){
    Point p1(1.2, 3.4);
    Point p2;
    Rectangle r1(1.2, 3.4, 10, 20, 30);
    cout << r1 << endl;
    cout << r1.surface() << endl;
    Shape& s1 = r1;
    cout << s1.surface() << endl; 

    return 0;
}   

