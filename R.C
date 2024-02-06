#include <conio.h>
#include <graphics.h>
#include <stdio.h>

#define TURBOC_GRAPHICS
#define BGI "C:\\turboc3\\bgi"

int main()
{
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
    closegraph();

    return 0;
}

