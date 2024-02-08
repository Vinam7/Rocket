#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define TURBOC_GRAPHICS
#define BGI "C:\\turboc3\\bgi"

int main()
{
	int i;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, BGI);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(50,50,LIGHTCYAN);
    // Ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0,420, 650, 500);
    floodfill(325, 460, WHITE);


    //Rocket body
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(315, 200, 340, 400);
    floodfill(320, 300, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(295, 250, 315, 400);
    floodfill(300, 300, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(340, 250, 360, 400);
    floodfill(350, 300, BLACK);
    //Rocket Head
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(350,250,0,180,10,10);
    floodfill(350, 245,BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(305,250,0,180,10,10);
    floodfill(305, 245,BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(327,200,0,180,12,12);
    floodfill(327, 195 ,BLACK);

    setcolor(WHITE);
    line(341,250,359,250);
    line(296,250,314,250);
    line(316,200,339,200);

    //Rocket tail
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(295,400, 360, 420);
    floodfill(347, 410, DARKGRAY);

    line(295,400,275,420);
    line(275,420,295,420);
    line(295,400,295,420);
    floodfill(287,410,DARKGRAY);

    line(360,420,380,420);
    line(380,420,360,400);
    line(360,400,380,420);
    floodfill(365,410,DARKGRAY);

    getch();
    cleardevice();

    for(i=1;i<=330;i=i+10){
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(50,50,LIGHTCYAN);
    // Ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0,420, 650, 500);
    floodfill(325, 460, WHITE);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(315, 95-i, 340, 295-i);
    floodfill(320, 294-i, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(295, 145-i, 315, 295-i);
    floodfill(300, 294-i, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(340, 145-i, 360, 295-i);
    floodfill(350, 294-i, BLACK);

    //Rocket Head
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(350,145-i,0,180,10,10);
    floodfill(350, 144-i,BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(305,145-i,0,180,10,10);
    floodfill(305, 144-i,BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(327,95-i,0,180,12,12);
    floodfill(327, 94-i ,BLACK);

    setcolor(WHITE);
    line(341,145-i,359,145-i);
    line(296,145-i,314,145-i);
    line(316,95-i,339,95-i);

    //Rocket tail
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(295,285-i, 360, 305-i);
    floodfill(347, 304-i, DARKGRAY);

    line(295,285-i,275,305-i);
    line(275,305-i,295,305-i);
    line(295,285-i,295,285-i);
    floodfill(287,304-i,DARKGRAY);

    line(360,305-i,380,305-i);
    line(380,305-i,360,285-i);
    line(360,285-i,380,305-i);
    floodfill(365,304-i,DARKGRAY);

     //body flames
	    setcolor(14);
	    setfillstyle(1, 14);
	    circle(328, 338-i, 33);
	    floodfill(328, 338-i, 14);
	    circle(328, 375-i, 25);
	    floodfill(328, 375-i, 14);
	    circle(328, 405-i, 15);
	    floodfill(328, 405-i, 14);
	    //booster 1 flames
	    circle(293, 325-i, 20);
	    floodfill(293, 325-i, 14);
	    circle(293, 350-i, 12);
	    floodfill(293, 350-i, 14);
	    circle(293, 365-i, 8);
	    floodfill(293, 365-i, 14);
	    //booster 2 flames
	    circle(363, 325-i, 20);
	    floodfill(363, 325-i, 14);
	    circle(363, 350-i, 12);
	    floodfill(363, 350-i, 14);
	    circle(363, 365-i, 8);
	    floodfill(363, 365-i, 14);
	    delay(1);
	    cleardevice();
    }

    getch();
    closegraph();

    return 0;
}

