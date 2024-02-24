#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define BGI "C:\\turboc3\\bgi"

void drawRocket(int yOffset, float scaleFactor, int rotate) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(315 * scaleFactor, (95 - yOffset) * scaleFactor, 340 * scaleFactor, (295 - yOffset) * scaleFactor);
    floodfill(320 * scaleFactor, (294 - yOffset) * scaleFactor, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(295 * scaleFactor, (145 - yOffset) * scaleFactor, 315 * scaleFactor, (295 - yOffset) * scaleFactor);
    floodfill(300 * scaleFactor, (294 - yOffset) * scaleFactor, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(340 * scaleFactor, (145 - yOffset) * scaleFactor, 360 * scaleFactor, (295 - yOffset) * scaleFactor);
    floodfill(350 * scaleFactor, (294 - yOffset) * scaleFactor, BLACK);

    // Rocket Head
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(350 * scaleFactor, (145 - yOffset) * scaleFactor, 0, 180, 10 * scaleFactor, 10 * scaleFactor);
    floodfill(350 * scaleFactor, (144 - yOffset) * scaleFactor, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(305 * scaleFactor, (145 - yOffset) * scaleFactor, 0, 180, 10 * scaleFactor, 10 * scaleFactor);
    floodfill(305 * scaleFactor, (144 - yOffset) * scaleFactor, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(327 * scaleFactor, (95 - yOffset) * scaleFactor, 0, 180, 12 * scaleFactor, 12 * scaleFactor);
    floodfill(327 * scaleFactor, (94 - yOffset) * scaleFactor, BLACK);

    setcolor(WHITE);
    line(341 * scaleFactor, (145 - yOffset) * scaleFactor, 359 * scaleFactor, (145 - yOffset) * scaleFactor);
    line(296 * scaleFactor, (145 - yOffset) * scaleFactor, 314 * scaleFactor, (145 - yOffset) * scaleFactor);
    line(316 * scaleFactor, (95 - yOffset) * scaleFactor, 339 * scaleFactor, (95 - yOffset) * scaleFactor);

    // Rocket tail
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(295 * scaleFactor, (285 - yOffset) * scaleFactor, 360 * scaleFactor, (305 - yOffset) * scaleFactor);
    floodfill(347 * scaleFactor, (304 - yOffset) * scaleFactor, DARKGRAY);

    line(295 * scaleFactor, (285 - yOffset) * scaleFactor, 275 * scaleFactor, (305 - yOffset) * scaleFactor);
    line(275 * scaleFactor, (305 - yOffset) * scaleFactor, 295 * scaleFactor, (305 - yOffset) * scaleFactor);
    line(295 * scaleFactor, (285 - yOffset) * scaleFactor, 295 * scaleFactor, (285 - yOffset) * scaleFactor);
    floodfill(287 * scaleFactor, (304 - yOffset) * scaleFactor, DARKGRAY);

    line(360 * scaleFactor, (305 - yOffset) * scaleFactor, 380 * scaleFactor, (305 - yOffset) * scaleFactor);
    line(380 * scaleFactor, (305 - yOffset) * scaleFactor, 360 * scaleFactor, (285 - yOffset) * scaleFactor);
    line(360 * scaleFactor, (285 - yOffset) * scaleFactor, 380 * scaleFactor, (305 - yOffset) * scaleFactor);
    floodfill(365 * scaleFactor, (304 - yOffset) * scaleFactor, DARKGRAY);
}

void drawFlames(int yOffset, float scaleFactor, int rotate) {
    // Body flames
    setcolor(14);
    setfillstyle(1, 14);
    circle(328 * scaleFactor, (338 - yOffset) * scaleFactor, 33 * scaleFactor);
    floodfill(328 * scaleFactor, (338 - yOffset) * scaleFactor, 14);
    circle(328 * scaleFactor, (375 - yOffset) * scaleFactor, 25 * scaleFactor);
    floodfill(328 * scaleFactor, (375 - yOffset) * scaleFactor, 14);
    circle(328 * scaleFactor, (405 - yOffset) * scaleFactor, 15 * scaleFactor);
    floodfill(328 * scaleFactor, (405 - yOffset) * scaleFactor, 14);

    // Booster 1 flames
    circle(293 * scaleFactor, (325 - yOffset) * scaleFactor, 20 * scaleFactor);
    floodfill(293 * scaleFactor, (325 - yOffset) * scaleFactor, 14);
    circle(293 * scaleFactor, (350 - yOffset) * scaleFactor, 12 * scaleFactor);
    floodfill(293 * scaleFactor, (350 - yOffset) * scaleFactor, 14);
    circle(293 * scaleFactor, (365 - yOffset) * scaleFactor, 8 * scaleFactor);
    floodfill(293 * scaleFactor, (365 - yOffset) * scaleFactor, 14);

    // Booster 2 flames
    circle(363 * scaleFactor, (325 - yOffset) * scaleFactor, 20 * scaleFactor);
    floodfill(363 * scaleFactor, (325 - yOffset) * scaleFactor, 14);
    circle(363 * scaleFactor, (350 - yOffset) * scaleFactor, 12 * scaleFactor);
    floodfill(363 * scaleFactor, (350 - yOffset) * scaleFactor, 14);
    circle(363 * scaleFactor, (365 - yOffset) * scaleFactor, 8 * scaleFactor);
    floodfill(363 * scaleFactor, (365 - yOffset) * scaleFactor, 14);
}

void drawScene(int yOffset, float scaleFactor) {
    // Background
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(50, 50, LIGHTCYAN);

    // Ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 420, 650, 500);
    floodfill(325, 460, WHITE);

    // Draw Rocket
    drawRocket(yOffset, scaleFactor, 0);

    // Draw Flames
    drawFlames(yOffset, scaleFactor, 0);
}

int main() {
    int i;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, BGI);


    // Initial scene
    drawScene(i, 0.25);


    // Animation loop
    for (i = 1; i <= 330; i += 10) {
	setactivepage(0);
	drawScene(i, 0.25); // Draw on the back buffer with scaled parameters
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(270, 95 - (i-10), 385, 420);
	setvisualpage(0); // Switch to the back buffer
	delay(100); // Adjust delay as needed
    }

    getch();
    closegraph();
    return 0;
}
