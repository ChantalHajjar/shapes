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
    Shape(double x = 0, double y = 0, double elevation =0):c(x,y), elevation(elevation) {}
    
    string toString() const{
        stringstream ss;
        ss << "Centre:" << c << " Elevation:" << elevation << endl;
        return ss.str();
    }
    private:
    Point c;
    double elevation;
};
ostream& operator<<(ostream& os, const Shape& s) {
    return os << s.toString();
}

int main(){
    Point p1(1.2, 3.4);
    Point p2;
    Shape s1(1,2,5);
    cout << s1 << endl;
    Shape s2;
    cout << s2 << endl;
    return 0;
}   

