#ifndef SHAPES_PRIMITIVES_H
#define SHAPES_PRIMITIVES_H

#include <cmath>
#include <vector>

namespace Figures {
    class Point final {
    private:
        double x_ = 0;
        double y_ = 0;
    public:
        Point() = default;
        Point(double x, double y) : x_(x), y_(y) {}

        double GetX() const;
        double GetY() const;
    };

    double Distance(const Point &first, const Point &second);

    class Line final {
    private:
        Point start_;
        Point finish_;
        double length_;
    public:
        Line() = default;

        Line(const Point &start, const Point &finish) : start_(start), finish_(finish), length_(Distance(start, finish)) {}


        double GetLength() const;
        Point GetStart() const;
        Point GetFinish() const;

    };

}


#endif //SHAPES_PRIMITIVES_H
