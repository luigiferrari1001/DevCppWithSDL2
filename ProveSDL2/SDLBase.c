#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "Point.h"

/*
  traslate color from 0xff00ff to RGB values
*/
void color2Rgb(int color, int rgb[3]){
     rgb[0] = (color & 0xFF0000) >> 16;
     rgb[1] = (color & 0x00FF00) >> 8;
     rgb[2] = (color & 0x0000FF) ;
}


/*
   paint a quadrilateral
   Input:
         int xarray[4], yarray[4] coordinates
         int color (hexadecimal format i.e. 0xff0000 for red)
         
         p1 -------- p2
          \          /
           \        /
            p4 -- p3
*/
void paintQuadrilateralOld(SDL_Renderer* renderer, int coord[4][2], int color){
      int x1 = coord[0][0], y1 = coord[0][1];
      int x2 = coord[1][0], y2 = coord[1][1];
      int x3 = coord[2][0], y3 = coord[2][1];
      int x4 = coord[3][0], y4 = coord[3][1];
      
      int x,y, tox, toy, flag;
      
      float m1, m2;
      int rgb[3];
      SDL_Rect r;  // a rectangle
      
      color2Rgb(color, rgb);
      SDL_SetRenderDrawColor( renderer, rgb[0], rgb[1], rgb[2], 255 );
      
      /*
      m1 = (y4-y1)*1.0/(x4-x1);
      m2 =100.0;
      if(x2!= x3)
         m2 = (y3-y2)*1.0/(x3-x2);
      tox = x2;
      toy = y2;
      
      printf("m1 = %.2f m2 = %.2f\n", m1, m2 );
         
      for(x = x1; x<= x4; x++){
         y = (int)(m1*(x-x1)+y1);
         if(tox<x3) 
             tox ++;
         toy = (int) (m2*(tox-x2)+y2); 
         printf("(%3d %3d) ---> (%3d %3d)\n", x,y,tox,toy);
         //SDL_RenderDrawLine( renderer, x, y, tox, toy );
         
         r.x = x;
         r.y = y;
         r.w = tox-x;
	      r.h = toy-y;
	      SDL_RenderFillRect( renderer, &r );
      
      }
      */
   printf("\n");
   do{
      flag = 0;
      printf("p1 (%3d %3d) p2 (%3d %3d) p2 (%3d %3d) p4 (%3d %3d)\n", x1,y1,x2,y2,x3,y3,x4,y4);
      SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
      SDL_RenderDrawLine( renderer, x1, y1, x2, y2 );
      SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
      SDL_RenderDrawLine( renderer, x2, y2, x3, y3 );
      SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
      SDL_RenderDrawLine( renderer, x3, y3, x4, y4 );
      SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
      SDL_RenderDrawLine( renderer, x4, y4, x1, y1 );
      /*
      if( x1 < x2 ) { x1++; flag++; }
      if( y1 < y4 ) { y1++; flag++; } 
      if( x2 > x1 ) { x2--; flag++; }
      if( y2 < y3 ) { y2++; flag++; }
      if( x3 > x4 ) { x3--; flag++; }
      if( y3 > y2 ) { y3--; flag++; }
      if( x4 < x3 ) { x4++; flag++; }
      if( y4 > y1 ) { y4--; flag++; }
      
      if( x1 < x4 ) { x1++; flag++; }
      if( y1 < y2 ) { y1++; flag++; } 
      if( x2 < x3 ) { x2++; flag++; }
      if( y2 > y1 ) { y2--; flag++; }
      if( x3 > x2 ) { x3--; flag++; }
      if( y3 > y4 ) { y3--; flag++; }
      if( x4 > x1 ) { x4--; flag++; }
      if( y4 < y3 ) { y4++; flag++; }
      */
      
      if(x1 < x2 && y1 < y4){
         printf(" p1 in alto a sx, orario\n");
         //   p1 p2
         //   p4 p3         
         if( x1 < x2 ) { x1++; flag++; }
         if( y1 < y4 ) { y1++; flag++; } 
         if( x2 > x1 ) { x2--; flag++; }
         if( y2 < y3 ) { y2++; flag++; }
         if( x3 > x4 ) { x3--; flag++; }
         if( y3 > y2 ) { y3--; flag++; }
         if( x4 < x3 ) { x4++; flag++; }
         if( y4 > y1 ) { y4--; flag++; }
      }else if(x1 < x4 && y1 < y2 && ((x1 < x3 )||(y1<y3))){
         printf(" p1 in alto a sx, antiorario\n");
         // p1 in alto a sx, antiorario
         //   p1 p4
         //   p2 p3         
         if( x1 < x4 ) { x1++; flag++; }
         if( y1 < y2 ) { y1++; flag++; } 
         if( x2 < x3 ) { x2++; flag++; }
         if( y2 > y1 ) { y2--; flag++; }
         if( x3 > x2 ) { x3--; flag++; }
         if( y3 > y4 ) { y3--; flag++; }
         if( x4 > x1 ) { x4--; flag++; }
         if( y4 < y3 ) { y4++; flag++; }
      }else if(x1 < x4 && y1 > y2) {
         printf(" p1 in basso a sx, orario\n");
         // p1 in basso a sx, orario
         //   p2 p3
         //   p1 p4         
         if( x1 < x4 ) { x1++; flag++; }
         if( y1 > y2 ) { y1--; flag++; } 
         if( x2 < x3 ) { x2++; flag++; }
         if( y2 < y1 ) { y2++; flag++; }
         if( x3 > x2 ) { x3--; flag++; }
         if( y3 < y4 ) { y3++; flag++; }
         if( x4 > x1 ) { x4--; flag++; }
         if( y4 > y3 ) { y4--; flag++; }
       }else if(x1 < x4 && y1 < y2 && ((x1 > x3 )||(y1>y3))){
         printf(" p1 in basso a sx, orario\n");
         //   p3 p4
         //   p2 p1         
         if( x1 > x2 ) { x1--; flag++; }
         if( y1 > y4 ) { y1--; flag++; } 
         if( x2 < x1 ) { x2++; flag++; }
         if( y2 > y3 ) { y2--; flag++; }
         if( x3 < x4 ) { x3++; flag++; }
         if( y3 < y2 ) { y3++; flag++; }
         if( x4 > x3 ) { x4--; flag++; }
         if( y4 < y1 ) { y4++; flag++; }
       }
   } while ( flag );
      
      
}

/*
   paint a quadrilateral
   Input:
         int xarray[4], yarray[4] coordinates
         int color (hexadecimal format i.e. 0xff0000 for red)
         
         p1 -------- p2
          \          /
           \        /
            p4 -- p3
*/

void paintQuadrilateral(SDL_Renderer* renderer, Point p[4], int color){
      int x1 , y1 ;
      int x2, y2;
      int x3, y3;
      int x4, y4;
      int x,y, tox, toy, flag;
      int i;
      
      float m1, m2;
      int rgb[3];
      SDL_Rect r;  // a rectangle
      
      color2Rgb(color, rgb);
      SDL_SetRenderDrawColor( renderer, rgb[0], rgb[1], rgb[2], 255 );
   
   printf("\n");   
   printf("IN ");
   for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
   printf("\n");
   
   if(( upper(p[0], p[2]) && left(p[0], p[2])) && left(p[0], p[1]) &&upper(p[0], p[3])){
      printf("a1 ");
   }
         
   // 0 1    a d  --> a b 
   // 3 2    b c      d c
   if(( upper(p[0], p[2]) && left(p[0], p[2])) && left(p[0], p[3]) &&upper(p[0], p[1])){
      exchange(p, 4, 1 ,3);   // 1 <--> 3 
      printf("a2 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       

   }


   //         B1
   // 0 1     d a  rotateL  a b 
   // 3 2     c b           d c
   if(( upper(p[0], p[2]) && right(p[0], p[2])) && right(p[0], p[3]) && upper(p[0], p[1])){
      rotateL(p, 4);
      printf("b1 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       
 
   }
   // 0 1   b a  rotateL  0 1 
   // 3 2   c d           3 2
   if(( upper(p[0], p[2]) && right(p[0], p[2])) && right(p[0], p[1]) && upper(p[0], p[3])){
      exchange(p, 4, 0, 2);  // 0 <--> 2 caso precedente 
      rotateR(p, 4);
      printf("b2 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       
 
   }
   
   // 0 1     c b   -->  a b 
   // 3 2     d a        d c
   if(( lower(p[0], p[2]) && right(p[0], p[2])) && right(p[0], p[1]) && lower(p[0], p[3])){
      exchange(p, 4, 0, 2); 
      exchange(p, 4, 1, 3); 
      printf("c1 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       
   }
   // 0 1   c d      c  b      a b      
   // 3 2   b a      d  a      d c
   if(( lower(p[0], p[2]) && right(p[0], p[2])) && right(p[0], p[3]) && lower(p[0], p[1])){
      exchange(p, 4, 0, 2); 
      printf("c2 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       

   }

   // 0 1     b c   -->  a b 
   // 3 2     a d        d c
   if(( lower(p[0], p[2]) && left(p[0], p[2])) && left(p[0], p[3]) && lower(p[0], p[1])){
      rotateL(p, 4);  
      printf("d1 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       
   }
   
   // 0 1     d  c      b  c      a b      
   // 3 2     a  b      a  d      d c
   if(( lower(p[0], p[2]) && left(p[0], p[2])) && left(p[0], p[1]) && lower(p[0], p[3])){
      exchange(p, 4, 0, 2); 
      rotateL(p, 4);
      printf("d2 ");
      for(i=0; i<4; i++) printf(" (%3d, %3d)", p[i].x, p[i].y);
      printf("\n");       
   }

   x1 = p[0].x;   y1 = p[0].y; 
   x2 = p[1].x;   y2 = p[1].y; 
   x3 = p[2].x;   y3 = p[2].y; 
   x4 = p[3].x;   y4 = p[3].y; 

   do{
      flag = 0;
      printf("    (%3d, %3d) (%3d, %3d) (%3d, %3d) (%3d, %3d)\n", x1,y1,x2,y2,x3,y3,x4,y4);
      SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
      SDL_RenderDrawLine( renderer, x1, y1, x2, y2 );
      SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
      SDL_RenderDrawLine( renderer, x2, y2, x3, y3 );
      SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
      SDL_RenderDrawLine( renderer, x3, y3, x4, y4 );
      SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
      SDL_RenderDrawLine( renderer, x4, y4, x1, y1 );
      
         //   p1 p2
         //   p4 p3         
         if( x1 < x2 ) { x1++; flag++; }
         if( y1 < y4 ) { y1++; flag++; } 
         if( x2 > x1 ) { x2--; flag++; }
         if( y2 < y3 ) { y2++; flag++; }
         if( x3 > x4 ) { x3--; flag++; }
         if( y3 > y2 ) { y3--; flag++; }
         if( x4 < x3 ) { x4++; flag++; }
         if( y4 > y1 ) { y4--; flag++; }
       
   } while ( flag );
      
      
}


   void fillCoord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int offset, int coord[4][2]){
       coord[0][0] = offset+x1;
       coord[0][1] = offset+y1;
       coord[1][0] = offset+x2;
       coord[1][1] = offset+y2;
       coord[2][0] = offset+x3;
       coord[2][1] = offset+y3;
       coord[3][0] = offset+x4;
       coord[3][1] = offset+y4;
    }


void fillPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int offset, Point coord[4]){
       coord[0].x = offset+x1;
       coord[0].y = offset+y1;
       coord[1].x = offset+x2;
       coord[1].y = offset+y2;
       coord[2].x= offset+x3;
       coord[2].y = offset+y3;
       coord[3].x = offset+x4;
       coord[3].y = offset+y4;

}
/* Gli esempi sono una rielaborazione di quelli che si possono trovare a questi indirizzi:
   https://thenumbat.github.io/cpp-course/sdl2/04/04.html
*/
int main( int argc, char* args[] ) {
    // Pointers to our window and surface and renderer
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer;
	int i, j, red, green, blue;
	SDL_Rect r;  // a rectangle
	
	int coord[4][2];
	Point c[4];
	int color, rgb[3];
	int offset;

	// Initialize SDL. SDL_Init will return -1 if it fails.
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		printf("Error initializing SDL: %d\n", SDL_GetError());
		system("pause");
		// End the program
		return 1;
	} 
    srand(time(NULL));
   
   /* 
    color = 0xff40ff;
    color2Rgb(color, rgb);
    printf("%6x -> (%3d %3d %3d\n", color, rgb[0], rgb[1], rgb[2]);
   */

	// Create our window
	window = SDL_CreateWindow( "Esempio di uso di SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 1000, SDL_WINDOW_SHOWN );

	// Make sure creating the window succeeded
	if ( !window ) {
		printf("Error creating window: %d\n", SDL_GetError());
		system("pause");
		// End the program
		return 1;
	}

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( !renderer ) {
		printf("Error creating renderer: %d\n", SDL_GetError());
		system("pause");
		return 1;
	}

	// Clear the window to white
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	
	/*
	// Set drawing color to black and draw some point
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    for(i=0;i<10;i++)
	    SDL_RenderDrawPoint(renderer, 20+10*i, 100 );

	// Set drawing color to red
	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderDrawLine( renderer, 30, 40, 80, 80 );


    // Set drawing color to blue and draw a rectangle
	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    r.x = 180;
	r.y = 20;
	r.w = 50;
	r.h = 100;
	SDL_RenderDrawRect( renderer, &r );

    // Set drawing color to green and draw a filled rectangle
    // with black border (order is important)
	r.x = 240;
	r.y = 20;
	r.w = 150;
	r.h = 80;
	SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    SDL_RenderFillRect( renderer, &r );
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderDrawRect( renderer, &r );
   */
/*   
    coord[0][0] = offset+564;
    coord[0][1] = offset+532;
    coord[1][0] = offset+604;
    coord[1][1] = offset+493;
    coord[2][0] = offset+646;
    coord[2][1] = offset+501;
    coord[3][0] = offset+606;
    coord[3][1] = offset+543;
    paintQuadrilateral(renderer, coord, 0xff0000);

    coord[0][0] = 469;
    coord[0][1] = 405;
    coord[1][0] = 414;
    coord[1][1] = 414;
    coord[2][0] = 446;
    coord[2][1] = 446;
    coord[3][0] = 501;
    coord[3][1] = 437;
    paintQuadrilateral(renderer, coord, 0x0000ff);
*/

    fillCoord(300,100,  290,200, 400,190, 390,100,   100, coord);
    fillPoints(300,100,  290,200, 400,190, 390,100,   100, c);
    paintQuadrilateral(renderer, c, 0x0000ff);

    fillCoord(100,100,  110,200, 120,200, 190,100,   200, coord);
    fillPoints(100,100,  110,200, 120,200, 190,100,   200, c);
    paintQuadrilateral(renderer, c, 0xff0000);

    fillCoord(100,100,  110,200, 120,200, 190,100,   300, coord);
    fillPoints(100,100,  110,200, 120,200, 190,100,   300, c);
    paintQuadrilateral(renderer, c, 0xff00ff);
    
    fillCoord(228,228,  9,265, 46,46, 265,9,   500, coord);
    fillPoints(228,228,  9,265, 46,46, 265,9,   500, c);
    paintQuadrilateral(renderer, c, 0xff8080);


    // Update window
	SDL_RenderPresent( renderer );
	
	// ciclo infinito di esecuzione
	i = -150;
	red = rand()%256;
	green = rand()%256;
	blue = rand()%256;
	while (1) {
	   // drawing example
	   // Set drawing color to blue and draw a rectangle
	   /*
	   SDL_SetRenderDrawColor( renderer, red, green, blue, 255 );
       i+=5;
       red += 5;
       green += 30;
       blue += 2;
       red%=256;
       green %= 256;
       blue %= 256;
	   if(i == 15) i = -15;
	   SDL_RenderDrawLine( renderer, 30-15, 30+i, 30+15, 30-i );
	   SDL_RenderDrawLine( renderer, 30-i, 30+15, 30+i, 30-15 );
	   
	   // Update window
	   SDL_RenderPresent( renderer );
	  	  */ 

	   // Get the next event
	   SDL_Event event;
	   if (SDL_PollEvent(&event))  {
	      if (event.type == SDL_QUIT)    {
	         // Break out of the loop on quit
	         break;
	      }
	   }
	   
	   // Wait a bit
       SDL_Delay(100);
	   
	}
	
	

	// Wait
	//system("pause");

	// Destroy the renderer and the windows
	SDL_DestroyRenderer ( renderer ); 
	SDL_DestroyWindow( window );

	// Quit SDL
	SDL_Quit();
	
	// End the program
	return 0;
}
