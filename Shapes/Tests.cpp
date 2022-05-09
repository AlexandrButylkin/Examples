#include "Tests.h"
#include <conio.h>
#include <iostream>

void Reset(Screen& screen) {
    _getch();
    PatBlt(screen.GetHdc(), 0, 0, screen.GetWeight(), screen.GetHeight(), BLACKNESS);
}

void draw(const Model &document, Screen &screen, const std::string& Hint) {
    for (const auto &item : document) {
        Reset(screen);
        std::cout << "\r" << Hint << " Press Enter ..." ;
        draw(item, screen);
    }
}

void draw_all(const Model &document, Screen &screen) {
    Reset(screen);
    for (const auto &item : document) {
        draw(item, screen);
    }
}

void DrawPointTest(Screen& screen) {
    using Figures::Point;

    Point point1(100, 100);
    Point point2(150, 150);
    Point point3(200, 200);
    Point point4(250, 250);
    Point point5(300, 300);
    Point point6(350, 350);
    Point point7(400, 400);
    Point point8(450, 450);
    Point point9(500, 500);

    Model model;

    model.push_back(point1);
    model.push_back(point2);
    model.push_back(point3);
    model.push_back(point4);
    model.push_back(point5);
    model.push_back(point6);
    model.push_back(point7);
    model.push_back(point8);
    model.push_back(point9);

    PatBlt(screen.GetHdc(), 0, 0, screen.GetWeight(), screen.GetHeight(), BLACKNESS);
    draw(model, screen,  "Draw Points.");

}



void DrawLineTest(Screen& screen) {
    using Figures::Point;
    using Figures::Line;

    Line line1(Point(100, 100), Point(200, 100));
    Line line2(Point(100, 150), Point(250, 150));
    Line line3(Point(100, 200), Point(300, 200));
    Line line4(Point(100, 250), Point(350, 250));
    Line line5(Point(100, 300), Point(400, 300));
    Line line6(Point(100, 350), Point(450, 350));
    Line line7(Point(100, 400), Point(500, 400));
    Line line8(Point(100, 450), Point(550, 450));
    Line line9(Point(100, 500), Point(600, 500));

    Model model;

    model.push_back(line1);
    model.push_back(line2);
    model.push_back(line3);
    model.push_back(line4);
    model.push_back(line5);
    model.push_back(line6);
    model.push_back(line7);
    model.push_back(line8);
    model.push_back(line9);

    PatBlt(screen.GetHdc(), 0, 0, screen.GetWeight(), screen.GetHeight(), BLACKNESS);
    draw(model, screen, "Draw Line.");

}

void DrawPolygonTest(Screen& screen) {
    using Figures::Point;

    Point point1(100, 700);
    Point point2(400, 500);
    Point point3(900, 600);
    Point point4(1000, 300);
    Point point5(700, 50);
    Point point6(300, 400);
    Point point7(200, 200);
    Point point8(100, 150);
    Point point9(50, 10);

    Figures::Polygon polygon1(std::vector<Point>{ point1,
                                                  point2,
                                                  point3 });

    Figures::Polygon polygon2(std::vector<Point>{ point1,
                                                  point2,
                                                  point3,
                                                  point4,
                                                  point5});

    Figures::Polygon polygon3(std::vector<Point>{ point1,
                                                  point2,
                                                  point3,
                                                  point4,
                                                  point5,
                                                  point6,
                                                  point7});

    Figures::Polygon polygon4(std::vector<Point>{ point1,
                                                  point2,
                                                  point3,
                                                  point4,
                                                  point5,
                                                  point6,
                                                  point7,
                                                  point8,
                                                  point9});

    Model model;
    model.push_back(polygon1);
    model.push_back(polygon2);
    model.push_back(polygon3);
    model.push_back(polygon4);

    draw(model, screen, "Draw Polygon.");
}

void DrawFiguresTest(Screen& screen) {
    using Figures::Point;

    Figures::Triangle triangle1(Point(100, 100), Point(120, 200), Point(160, 150));
    Figures::Triangle triangle2(Point(100, 100), Point(430, 200), Point(300, 500));
    Figures::Triangle triangle3(Point(200, 220), Point(120, 200), Point(400, 400));
    Figures::Triangle triangle4(Point(300, 300), Point(500, 100), Point(200, 100));
    Figures::Triangle triangle5(Point(100, 100), Point(200, 200), Point(300, 150));


    Figures::Rectangle rectangle1(Point(100, 100), Point(500, 200));
    Figures::Rectangle rectangle2(Point(200, 200), Point(250, 500));
    Figures::Rectangle rectangle3(Point(100, 100), Point(350, 450));
    Figures::Rectangle rectangle4(Point(200, 200), Point(650, 100));
    Figures::Rectangle rectangle5(Point(100, 100), Point(250, 500));


    Figures::Square square1(Point(100, 100), 100);
    Figures::Square square2(Point(100, 100), 200);
    Figures::Square square3(Point(100, 100), 300);
    Figures::Square square4(Point(100, 100), 400);
    Figures::Square square5(Point(100, 100), 500);


    Model model;
    model.push_back(triangle1);
    model.push_back(triangle2);
    model.push_back(triangle3);
    model.push_back(triangle4);
    model.push_back(triangle5);

    model.push_back(rectangle1);
    model.push_back(rectangle2);
    model.push_back(rectangle3);
    model.push_back(rectangle4);
    model.push_back(rectangle5);

    model.push_back(square1);
    model.push_back(square2);
    model.push_back(square3);
    model.push_back(square4);
    model.push_back(square5);

    draw(model, screen, "Draw Triangle. Rectangle. Square.");
}

void DrawEquilateralPolygonTest(Screen& screen){
    using Figures::Point;

    Figures::EquilateralPolygon eqpolygon3(Point(125, 125), 3, 100);
    Figures::EquilateralPolygon eqpolygon4(Point(150, 150), 4, 125);
    Figures::EquilateralPolygon eqpolygon5(Point(175, 175), 5, 150);
    Figures::EquilateralPolygon eqpolygon6(Point(200, 200), 6, 175);
    Figures::EquilateralPolygon eqpolygon7(Point(225, 225), 7, 200);
    Figures::EquilateralPolygon eqpolygon8(Point(250, 250), 8, 225);
    Figures::EquilateralPolygon eqpolygon9(Point(275, 275), 9, 250);
    Figures::EquilateralPolygon eqpolygon10(Point(300, 300), 10, 275);

    Model model;
    model.push_back(eqpolygon3);
    model.push_back(eqpolygon4);
    model.push_back(eqpolygon5);
    model.push_back(eqpolygon6);
    model.push_back(eqpolygon7);
    model.push_back(eqpolygon8);
    model.push_back(eqpolygon9);
    model.push_back(eqpolygon10);

    draw(model, screen, "Draw Equilateral Polygon.");
}

void DrawCircleTest(Screen& screen) {
    using Figures::Point;

    Figures::Circle circle1(Point(250, 250), 50);
    Figures::Circle circle2(Point(250, 250), 100);
    Figures::Circle circle3(Point(250, 250), 150);
    Figures::Circle circle4(Point(250, 250), 200);
    Figures::Circle circle5(Point(500, 500), 250);
    Figures::Circle circle6(Point(500, 500), 300);
    Figures::Circle circle7(Point(500, 500), 350);
    Figures::Circle circle8(Point(500, 500), 400);
    Figures::Circle circle9(Point(500, 500), 450);

    Model model;
    model.push_back(circle1);
    model.push_back(circle2);
    model.push_back(circle3);
    model.push_back(circle4);
    model.push_back(circle5);
    model.push_back(circle6);
    model.push_back(circle7);
    model.push_back(circle8);
    model.push_back(circle9);

    draw(model, screen, "Draw Circle.");
}

void DrawEllipseTest(Screen& screen) {
    using Figures::Point;

    Figures::Ellipse ellipse1(Point(400, 400), 25, 125);
    Figures::Ellipse ellipse2(Point(400, 400), 50, 100);
    Figures::Ellipse ellipse3(Point(400, 400), 100, 200);
    Figures::Ellipse ellipse4(Point(400, 400), 200, 100);
    Figures::Ellipse ellipse5(Point(400, 400), 100, 50);
    Figures::Ellipse ellipse6(Point(400, 400), 125, 25);

    Model model;
    model.push_back(ellipse1);
    model.push_back(ellipse2);
    model.push_back(ellipse3);
    model.push_back(ellipse4);
    model.push_back(ellipse5);
    model.push_back(ellipse6);

    draw(model, screen, "Draw Ellipse.");

}

void DrawHouse(Screen& screen) {
    using Figures::Point;

    Figures::Square wall1(Point(100 * 2, 100 * 2), 100 * 2);
    Figures::Rectangle wall2(Point(200 * 2, 100 * 2), Point(400 * 2, 200 * 2));
    Figures::Triangle roof1(Point(100 * 2, 100 * 2), Point(200 * 2, 100 * 2), Point(150 * 2, 50 * 2));
    Figures::Polygon roof2({Point(150 * 2, 50 * 2), Point(350 * 2, 50 * 2), Point(400 * 2, 100 * 2), Point(200 * 2, 100 * 2)});
    Figures::Circle window1(Point(150 * 2, 75 * 2), 10 * 2);
    Figures::Square window2(Point(125 * 2, 125 * 2), 50 * 2);
    Figures::Ellipse window3(Point(300 * 2, 150 * 2), 25 * 2, 75 * 2);

    Model model;
    model.push_back(wall1);
    model.push_back(wall2);
    model.push_back(roof1);
    model.push_back(roof2);
    model.push_back(window1);
    model.push_back(window2);
    model.push_back(window3);

    draw_all(model, screen);

}