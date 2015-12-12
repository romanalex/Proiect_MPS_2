#include<stdio.h>

int main() {

	FILE *f = fopen("date.in", "r");

	int d;

	d = fscanf(f, "%d", &d);

	printf("%d", d);

	return 0;
}