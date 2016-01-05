#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROWS 900
#define COLS 900
#define PI 3.14159265

typedef struct  {
   int xval;
   int yval;
}Point ;


void draw_line (Point p1, Point p2,int matr[COLS][ROWS]){
    int i,y;

    if(p2.xval != p1.xval ){
        double m = (p2.yval-p1.yval)/(p2.xval-p1.xval);

        printf("M : %4.2f %d %d \n",m,p2.yval-p1.yval,p2.xval-p1.xval);
        if(p1.xval < p2.xval){
            for(i=p1.xval; i<p2.xval; i++){
                printf("in matrice : %d %d\n",i,(int )round(m*(i-p1.xval)+p1.yval));
                matr[i][(int )round(m*(i-p1.xval)+p1.yval)] = 1;
            }
        }else{
            for(i=p1.xval; i > p2.xval; i--){
                matr[i][(int )round(m*(i-p1.xval)+p1.yval)] = 1;
            }
        }
    }else{
        if(p1.yval < p2.yval){
            for(i=p1.yval; i < p2.yval; i++){
                matr[i][p1.xval] = 1;
            }
        }else{
            for(i=p2.yval; i < p1.yval; i++){
                matr[i][p1.xval] = 1;
            }
        }
    }



}

Point translate(Point p, int x, int y)
{
    p.xval += x;
    p.yval += y;

    return p;
}

Point rotate(Point p, Point p1, float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	printf("ALEX INTAINTE %d %d %f %f\n",p.xval,p.yval,s,c);
	p.xval -= p1.xval;
	p.yval -= p1.yval;
	// rotate point
		printf("ALEX translat %d %d \n",p.xval,p.yval);

	int xnew = (int )round(p.xval * c - p.yval * s);
	int ynew = (int )round(p.xval * s + p.yval * c);

	// translate point back:
	p.xval = xnew + p1.xval;
	p.yval = ynew + p1.yval;
			printf("ALEX rotat %d %d \n",p.xval,p.yval);

	return p;
}

int main() {

	FILE *f = fopen("date.in", "r");
	FILE *g = fopen("date.pmg", "w");
	int a[ROWS][COLS];
	int i,j;
	/*
    Point p1 = malloc(sizeof(Point));
    Point p2 = malloc(sizeof(Point));
    Point p_old = malloc(sizeof(Point));
    */

    Point p1,p2,p_old;
    p1.xval = 450;
    p1.yval = 899;

    p2.xval = 450;
    p2.yval = 799;

    p_old.xval = 0;
    p_old.yval = 0;
    int x,y;

    for(i=0;i<COLS;i++)
        for(j=0;j<ROWS;j++)
            a[i][j] = 255;

    draw_line(p1,p2,a);

    p_old.xval = p1.xval;
    p_old.yval = p1.yval;

    p1.xval = p2.xval;
    p1.yval = p2.yval;

    printf("%d %d %d %d\n",p1.xval,p1.yval,p2.xval,p2.yval);
    printf("%d %f \n",abs(p2.xval-p_old.xval),(p2.yval-p_old.yval)*0.66);

    p2 = translate(p2,p2.xval-p_old.xval,(p2.yval-p_old.yval)*0.66);



    printf("%d %d\n",p2.xval,p2.yval);


    p2 = rotate(p1,p2,45*(PI/180));

    printf("%d %d %d %d\n",p1.xval,p1.yval,p2.xval,p2.yval);

    draw_line(p1,p2,a);

 //   p2 = rotate(p2,p1,90 * (PI/180));

 //   draw_line(p1,p2,a);

    fprintf(g,"P2\n900 900\n255\n");

    for(i=0;i<COLS;i++){
        for(j=0;j<ROWS;j++)
            fprintf(g,"%d ",a[i][j]);
        fprintf(g,"\n");
    }

    close(g);


	//fscanf(f, "%d", &d);

	//fprintf(g, "%d\n", d);


	return 0;
}
