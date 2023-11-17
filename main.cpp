#include <iostream>
#include <sstream>
using namespace std;

class Point{
  public:
    Point(double x, double y): x(x), y(y) 
    { 
        cout << "Point(double, double) called" << endl;
    }
    Point(double a = 0): x(a), y(a) {
        cout << "Point(double) called" << endl;
    }
    ~Point(){cout << "Point destroyed" << endl;}
    
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
int main(){
    Point p1(1.2, 3.4);
    cout << p1 << endl;
}