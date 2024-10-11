#include <iostream>
#include <raylib.h>
#include "graphgrid.h"

#define DARKBLUE \
    (Color) { 0, 82, 172, 255 }
#define PURPLE \
    (Color) { 200, 122, 255, 255 }
#define VIOLET \
    (Color) { 135, 60, 190, 255 }
#define DARKPURPLE \
    (Color) { 112, 31, 126, 255 }
#define LIME \
    (Color) { 0, 158, 47, 255 }

int main()
{

    InitWindow(450, 900, "!!TITRIS!!");

    Graph graph;
    graph.showgraph();
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKPURPLE);

        EndDrawing();
    }
    CloseWindow();
}