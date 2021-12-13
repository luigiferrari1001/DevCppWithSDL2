#include "Point.h"


Point createPoint(int x, int y){
   Point p;
   p.x=x; p.y=y;
   return p;
}

int minX(Point v[], int dim){
    int i,  min = v[0].x;
    for(i=1; i<dim; i++)
       if(v[i].x<min) min = v[i].x;
    return min;
}

int maxX(Point v[], int dim){
    int i, max = v[0].x;
    for(i=1; i<dim; i++)
       if(v[i].x>max) max = v[i].x;
    return max;
}

int minY(Point v[], int dim){
    int i, min = v[0].y;
    for(i=1; i<dim; i++)
       if(v[i].y<min) min = v[i].y;
    return min;
}

int maxY(Point v[], int dim){
    int i, max = v[0].y;
    for(i=1; i<dim; i++)
       if(v[i].y>max) max = v[i].y;
    return max;
}

Point altoSx(Point v[], int dim){
    Point p; p.x = minX(v, dim); p.y = minY(v, dim); return p;
}

Point bassoDx(Point v[], int dim){
    Point p; p.x = maxX(v, dim); p.y = maxY(v, dim); return p;
}

/*
     0 1 2 3
     3 0 1 2
*/
void rotateR(Point v[], int dim){
     Point tmp;
     int i;
     tmp = v[dim-1];
     for(i=dim-1; i>0; i--)
         v[i]=v[i-1];
     v[0]= tmp;
}

/*
     0 1 2 3
     1 2 3 0
*/

void rotateL(Point v[], int dim){
     Point tmp;
     int i;
     tmp = v[0];
     for(i=0; i<dim-1; i++)
         v[i]=v[i+1];
     v[i]= tmp;
}

void exchange(Point v[], int dim, int pos1, int pos2){
     Point tmp;
     if (pos1<0 || pos1 >= dim || pos2<0 || pos2 >=dim) return;
     tmp = v[pos1];
     v[pos1]= v[pos2];
     v[pos2] = tmp;
}

int upper(Point p1, Point p2){ return p1.y <= p2.y; }
int lower(Point p1, Point p2){ return p1.y >= p2.y; }
int left(Point p1, Point p2){ return p1.x <= p2.x; }
int right(Point p1, Point p2){ return p1.x >= p2.x; }

