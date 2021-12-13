/*
   struttura e funzioni per utilizzare punti nel piano 2D
   le coordinate si intendono a partire dall'angolo in alto a sx
   I controlli sono minimi
   Luigi Ferrari 12.4.2021
*/

typedef struct{
   int x; int y;
}Point;

Point createPoint(int x, int y);
int minX(Point v[], int dim);
int maxX(Point v[], int dim);
int minY(Point v[], int dim);
int maxY(Point v[], int dim);
Point altoSx(Point v[], int dim);
Point bassoDx(Point v[], int dim);
/*
     0 1 2 3
     3 0 1 2
*/
void rotateR(Point v[], int dim);
/*
     0 1 2 3
     1 2 3 0
*/
void rotateL(Point v[], int dim);
void exchange(Point v[], int dim, int pos1, int pos2);
int upper(Point p1, Point p2);
int lower(Point p1, Point p2);
int left(Point p1, Point p2);
int right(Point p1, Point p2);
