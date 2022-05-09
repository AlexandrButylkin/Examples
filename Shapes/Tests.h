#ifndef SHAPES_TESTS_H
#define SHAPES_TESTS_H

#include "Primitives.h"
#include "Drawer.h"
#include <vector>

using Model = std::vector<Drawer>;

void Reset(Screen& screen);
void draw(const Model &document, Screen &screen, const std::string& Hint = "");
void draw_all(const Model &document, Screen &screen);

void DrawPointTest(Screen& screen);
void DrawLineTest(Screen& screen);
void DrawPolygonTest(Screen& screen);
void DrawFiguresTest(Screen& screen);
void DrawEquilateralPolygonTest(Screen& screen);
void DrawCircleTest(Screen& screen);
void DrawEllipseTest(Screen& screen);
void DrawHouse(Screen& screen);



#endif //SHAPES_TESTS_H
