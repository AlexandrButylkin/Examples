#ifndef SHAPES_FIGURES_H
#define SHAPES_FIGURES_H

#include "Primitives.h"

const double pi = 3.1415926535;
const double pi_2 = 6.28318530718;
double to_rad(int i);

namespace Figures {

    class Polygon {
    protected:
        std::vector<Point> peaks_;
        size_t num_peaks_ = 0;
    public:
        Polygon() = default;

        explicit Polygon(const std::vector<Point> &peaks);

        Point& operator[](size_t index);
        const Point& operator[](size_t index) const;

        size_t GetNumPeaks() const;

        virtual double Perimeter() const;
        virtual double Area() const;

        virtual ~Polygon() = default;
    };

    class Triangle final : public Polygon {
    public:
        Triangle(const Point &a, const Point &b, const Point &c);

        double Area() const override;
    };

    class Rectangle final : public Polygon {
    private:
        double height_;
        double weight_;
    public:
        Rectangle(const Point &a, const Point &c);

        double Perimeter() const override;
        double Area() const override;
    };

    class Square final : public Polygon {
    private:
        double length_;
    public:
        Square(const Point &a, double length);

        double Perimeter() const override;
        double Area() const override;
    };

    std::vector<Point> GetPoints(size_t size, const Point& start, double radius);

    class EquilateralPolygon final : public Polygon{
    private:
        double length_;
    public:
        EquilateralPolygon(const Point& start, size_t num_peaks, double radius);

        double Area() const override;

        double GetLength() const;
    };

    class Circle final {
    private:
        Point center_;
        int radius_;
    public:
        Circle(const Point& center, int radius);

        double Perimeter() const;
        double Area() const;

        Point GetCenterPoint() const;
        int GetRadius() const;
    };


    std::vector<Point> GetPoints(const Point& start, int small_radius, double big_radius);

    class Ellipse final {
    private:
        int vertical_radius_;
        int horizontal_radius_;
        Point center_;
    public:
        Ellipse(const Point& center, int vertical_radius, int horizontal_radius);

        double Perimeter() const;
        double Area() const;

        Point GetCenterPoint() const;
        int GetSmallRadius() const;
        int GetBigRadius() const;

    };

}

#endif //SHAPES_FIGURES_H
