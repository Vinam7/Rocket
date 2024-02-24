#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define TURBOC_GRAPHICS
#define BGI "C:\\turboc3\\bgi"

void drawRocket(int yOffset, float scaleFactor, int rotate) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(315, 95 - yOffset, 340, 295 - yOffset);
    floodfill(320, 294 - yOffset, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(295, 145 - yOffset, 315, 295 - yOffset);
    floodfill(300, 294 - yOffset, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    rectangle(340, 145 - yOffset, 360, 295 - yOffset);
    floodfill(350, 294 - yOffset, BLACK);

    // Rocket Head
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(350, 145 - yOffset, 0, 180, 10 * scaleFactor, 10 * scaleFactor);
    floodfill(350, 144 - yOffset, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(305, 145 - yOffset, 0, 180, 10 * scaleFactor, 10 * scaleFactor);
    floodfill(305, 144 - yOffset, BLACK);

    setfillstyle(SOLID_FILL, WHITE);
    ellipse(327, 95 - yOffset, 0, 180, 12 * scaleFactor, 12 * scaleFactor);
    floodfill(327, 94 - yOffset, BLACK);

    setcolor(WHITE);
    line(341, 145 - yOffset, 359, 145 - yOffset);
    line(296, 145 - yOffset, 314, 145 - yOffset);
    line(316, 95 - yOffset, 339, 95 - yOffset);

    // Rocket tail
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(295, 285 - yOffset, 360, 305 - yOffset);
    floodfill(347, 304 - yOffset, DARKGRAY);

    line(295, 285 - yOffset, 275, 305 - yOffset);
    line(275, 305 - yOffset, 295, 305 - yOffset);
    line(295, 285 - yOffset, 295, 285 - yOffset);
    floodfill(287, 304 - yOffset, DARKGRAY);

    line(360, 305 - yOffset, 380, 305 - yOffset);
    line(380, 305 - yOffset, 360, 285 - yOffset);
    line(360, 285 - yOffset, 380, 305 - yOffset);
    floodfill(365, 304 - yOffset, DARKGRAY);
}

void drawFlames(int yOffset, float scaleFactor, int rotate) {
    // Body flames
    setcolor(14);
    setfillstyle(1, 14);
    circle(328, 338 - yOffset, 33 * scaleFactor);
    floodfill(328, 338 - yOffset, 14);
    circle(328, 375 - yOffset, 25 * scaleFactor);
    floodfill(328, 375 - yOffset, 14);
    circle(328, 405 - yOffset, 15 * scaleFactor);
    floodfill(328, 405 - yOffset, 14);

    // Booster 1 flames
    circle(293, 325 - yOffset, 20 * scaleFactor);
    floodfill(293, 325 - yOffset, 14);
    circle(293, 350 - yOffset, 12 * scaleFactor);
    floodfill(293, 350 - yOffset, 14);
    circle(293, 365 - yOffset, 8 * scaleFactor);
    floodfill(293, 365 - yOffset, 14);

    // Booster 2 flames
    circle(363, 325 - yOffset, 20 * scaleFactor);
    floodfill(363, 325 - yOffset, 14);
    circle(363, 350 - yOffset, 12 * scaleFactor);
    floodfill(363, 350 - yOffset, 14);
    circle(363, 365 - yOffset, 8 * scaleFactor);
    floodfill(363, 365 - yOffset, 14);
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
    drawScene(0, 1.0);

    // Animation
    for (i = 1; i <= 330; i += 10) {
        drawScene(i, 1.0); // Example values for yOffset and scaleFactor
        delay(100); // Adjust as needed
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
