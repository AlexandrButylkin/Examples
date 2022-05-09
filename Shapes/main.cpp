#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Drawer.h"
#include "Tests.h"

int main() {
    std::cout << "\rPress Enter ...";
    {
        Screen screen;
        DrawPointTest(screen);
        DrawLineTest(screen);
        DrawPolygonTest(screen);
        DrawFiguresTest(screen);
        DrawEquilateralPolygonTest(screen);
        DrawCircleTest(screen);
        DrawEllipseTest(screen);
        DrawHouse(screen);
    }
    getch();
    return 0;
}