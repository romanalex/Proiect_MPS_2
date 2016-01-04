#include <stdio.h>
#include <math.h>

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

        // Translate function
        void translate(double a, double b)
        {
                xval += a;
                yval += b;
        }

        // Rotate function
        void rotate(Point p, float angle)
		{
		  float s = sin(angle);
		  float c = cos(angle);

		  // translate point back to origin:
		  xval -= p.xval;
		  yval -= p.yval;

		  // rotate point
		  float xnew = xval * c - yval * s;
		  float ynew = xval * s + yval * c;

		  // translate point back:
		  xval = xnew + p.xval;
		  yval = ynew + p.yval;
		}

        // Print the point on the stream.  The class ostream is a base class
        // for output streams of various types.
        void print(ostream &strm)
        {
                strm << "(" << xval << "," << yval << ")";
        }
};