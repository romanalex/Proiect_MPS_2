#include <stdio.h>
#include <math.h>

struct Point {
   double xval;
   double yval;
};

struct Point translate(struct Point p, double x, double y)
{
    p.xval += x;
    p.yval += y;

    return p;
}

struct Point rotate(struct Point p, struct Point p1, float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	p.xval -= p1.xval;
	p.yval -= p1.yval;

	// rotate point
	float xnew = p.xval * c - p.yval * s;
	float ynew = p.xval * s + p.yval * c;

	// translate point back:
	p.xval = xnew + p1.xval;
	p.yval = ynew + p1.xval;
	return p;
}

int main() {

	FILE *f = fopen("date.in", "r");
	FILE *g = fopen("date.out", "w");
	int d;

	fscanf(f, "%d", &d);

	fprintf(g, "%d\n", d);

	struct Point p;
    
	return 0;
}