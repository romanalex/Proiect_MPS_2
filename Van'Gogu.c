#include<stdio.h>

int main() {

	FILE *f = fopen("date.in", "r");
	FILE *g = fopen("date.out", "w");
	int d;

	fscanf(f, "%d", &d);

	fprintf(g, "%d\n", d);

	return 0;
}