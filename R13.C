#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define TURBOC_GRAPHICS
#define BGI "C:\\turboc3\\bgi"

void drawRocket(int xOffset, float scaleFactor, int rotate) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle((60 + xOffset) * scaleFactor, 130 * scaleFactor, (260 + xOffset) * scaleFactor, 160 * scaleFactor);
    floodfill((160 + xOffset) * scaleFactor, 140 * scaleFactor, BLACK);

    // Rocket Head
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse((260 + xOffset) * scaleFactor, 145 * scaleFactor, 270, 90, 15 * scaleFactor, 15 * scaleFactor);
    floodfill((261 + xOffset) * scaleFactor, 141 * scaleFactor, BLACK);


    setcolor(WHITE);
    line((260 + xOffset) * scaleFactor, 130 * scaleFactor, (260 + xOffset) * scaleFactor, 160 * scaleFactor);

    // Rocket tail
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle((60 + xOffset) * scaleFactor, 130 * scaleFactor, (20 + xOffset) * scaleFactor, 160 * scaleFactor);
    floodfill((40 + xOffset) * scaleFactor, 140 * scaleFactor, DARKGRAY);

}


void drawFlames(int xOffset, float scaleFactor, int rotate) {
    // Body flames
    setcolor(14);
    setfillstyle(1, 14);
    circle((5+ xOffset) * scaleFactor, 145 * scaleFactor, 15 * scaleFactor);
    floodfill((5 + xOffset) * scaleFactor, 147 * scaleFactor, 14);
    circle((-2 + xOffset) * scaleFactor, 147 * scaleFactor, 7 * scaleFactor);
    floodfill((3 + xOffset) * scaleFactor, 147 * scaleFactor, 14);
    circle((-6 + xOffset) * scaleFactor, 147 * scaleFactor, 4 * scaleFactor);
    floodfill((-5 + xOffset) * scaleFactor, 147 * scaleFactor, 14);

}

void drawScene() {
    // Background
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(50, 50, LIGHTCYAN);

    // Ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
   rectangle(0, 420, 650, 500);
    floodfill(325, 460, WHITE);
}

void hide(int xOffset, float scaleFactor, int rotate)
{
  setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar((60+xOffset)*scaleFactor,130*scaleFactor, (260+xOffset)*scaleFactor, 160*scaleFactor);
}
int main() {
    int i;
    float s= 1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, BGI);


    // Initial scene
   drawScene();
    // Animation loop
    for (i = 1; i <= 330; i += 10) {
	setactivepage(0);
	  // Draw Rocket
    drawRocket(i, s, 0);
    // Draw Flames
    drawFlames(i, s, 0);
     // Draw on the back buffer with scaled parameters
       setfillstyle(SOLID_FILL, LIGHTCYAN);
	//hide(i,s,0);
	setvisualpage(0); // Switch to the back buffer
	delay(100); // Adjust delay as needed
    }

    getch();
    closegraph();
    return 0;
}

