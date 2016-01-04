#include <stdio.h>

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

int main() {

	FILE *f = fopen("date.in", "r");
	FILE *g = fopen("date.out", "w");
	int d;

	fscanf(f, "%d", &d);

	fprintf(g, "%d\n", d);

	return 0;
}