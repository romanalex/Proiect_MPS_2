#include <iostream>
#include <math.h>

using namespace std;

// Class to represent points.
class Point {
private:
        double xval, yval;
public:
        // Constructor uses default arguments to allow calling with zero, one,
        // or two values.
        Point(double x = 0.0, double y = 0.0) {
                xval = x;
                yval = y;
        }

        // Distance to another point.  Pythagorean thm.
        double dist(Point other) {
                double xd = xval - other.xval;
                double yd = yval - other.yval;
                return sqrt(xd*xd + yd*yd);
        }

        void translate(double a, double b)
        {
                xval += a;
                yval += b;
        }

        // Print the point on the stream.  The class ostream is a base class
        // for output streams of various types.
        void print(ostream &strm)
        {
                strm << "(" << xval << "," << yval << ")";
        }
};