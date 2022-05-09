#include "Figures.h"

double to_rad(int i){
    return pi_2 * i / 360;
}

namespace Figures {

    Polygon::Polygon(const std::vector<Point> &peaks) : num_peaks_(peaks.size()), peaks_(peaks) {}

    Point& Polygon::operator[](size_t index){
        return const_cast<Point&>(static_cast<const Polygon&>(*this)[index]);
    }

    const Point& Polygon::operator[](size_t index) const {
        return peaks_[index];
    }

    size_t Polygon::GetNumPeaks() const { return num_peaks_; }

    double Polygon::Perimeter() const {
        double P = 0.0;
        for(size_t i = 0; i < num_peaks_ - 1; ++i){
            P += Distance(peaks_[i], peaks_[i + 1]);
        }
        return P + Distance(peaks_[num_peaks_ - 1], peaks_[0]);
    }

    double Polygon::Area() const {
        double A = 0.0;
        for(size_t i = 0; i < num_peaks_ - 1; ++i){
            A += peaks_[i].GetX() * peaks_[i + 1].GetY() - peaks_[i].GetY() * peaks_[i + 1].GetX();
        }
        A += peaks_[num_peaks_ - 1].GetX() * peaks_[0].GetY() - peaks_[num_peaks_ - 1].GetY() * peaks_[0].GetX();
        return A;
    }


    Triangle::Triangle(const Point &a, const Point &b, const Point &c) :
        Polygon(std::vector<Point>{a, b, c}){}


    double Triangle::Area() const {
        auto p = Perimeter() / 2;
        return sqrt(p *
                    (p - Distance(peaks_[0], peaks_[1])) *
                    (p - Distance(peaks_[1], peaks_[2])) *
                    (p - Distance(peaks_[2], peaks_[0])));
    }


    Rectangle::Rectangle(const Point &a, const Point &c) :
            Polygon(std::vector<Point>{a, Point(c.GetX(), a.GetY()),
                                         c, Point(a.GetX(), c.GetY())}),
            weight_(Distance(a, Point(c.GetX(), a.GetY()))),
            height_(Distance(Point(c.GetX(), a.GetY()), c)){}

    double Rectangle::Perimeter() const {
        return (weight_ + height_) * 2;
    }

    double Rectangle::Area() const {
        return weight_ * height_;
    }


    Square::Square(const Point &a, double length) :
        Polygon(std::vector<Point>{a, Point(a.GetX() + length, a.GetY()),
                                        Point(a.GetX() + length, a.GetY() + length),
                                        Point(a.GetX(), a.GetY() + length)}),
                                        length_(length){}

    double Square::Perimeter() const {
        return length_ * 4;
    }

    double Square::Area() const {
        return length_ * length_;
    }

    std::vector<Point> GetPoints(size_t size, const Point& start, double radius){
        std::vector<Point> points;
        points.reserve(size);

        auto delta_x = start.GetX();
        auto delta_y = start.GetY();

        for(size_t i = 0; i < size; ++i){
            auto x = radius * sin((pi_2 / size) * i) + delta_x;
            auto y = radius * cos((pi_2 / size) * i) + delta_y;
            points.emplace_back(x, y);
        }
        return points;
    }

    EquilateralPolygon::EquilateralPolygon(const Point& start, size_t num_peaks, double radius) :
        Polygon(GetPoints(num_peaks, start, radius)),
        length_(Distance(peaks_[0], peaks_[1])) {}

    double EquilateralPolygon::Area() const {
        return ((num_peaks_ * 1.0) * length_ * length_) /
                (4 * tan(180.0 / (num_peaks_ * 1.0)));
    }

    double EquilateralPolygon::GetLength() const{
        return length_;
    }

    Circle::Circle(const Point& center, int radius) : center_(center), radius_(radius) {}

    double Circle::Perimeter() const {
        return pi_2 * radius_;
    }

    double Circle::Area() const {
        return pi * radius_ * radius_;
    }

    Point Circle::GetCenterPoint() const { return center_; }
    int Circle::GetRadius() const { return radius_; }


    std::vector<Point> GetPoints(const Point& start, int small_radius, double big_radius){
        std::vector<Point> points;
        points.reserve(360);
        //     x = a * cos t
        //     y = b * sin t
        //          a * sin(f)
        //tan(t) = ----------
        //          b * cos(f)
        auto delta_x = start.GetX();
        auto delta_y = start.GetY();

        for(int i = 0; i < 360; ++i){
            auto sinus = sin(to_rad(i));
            auto cosinus = cos(to_rad(i));
            auto t = atan2((small_radius * sinus), (big_radius * cosinus));

            auto x = big_radius * cos(t) + delta_x;
            auto y = small_radius * sin(t) + delta_y;
            points.emplace_back(x, y);
        }
        return points;
    }

    Ellipse::Ellipse(const Point& center, int vertical_radius, int horizontal_radius) :
            center_(center), vertical_radius_(vertical_radius), horizontal_radius_(horizontal_radius) {}

    double Ellipse::Perimeter() const{
        return pi_2 * sqrt((vertical_radius_ * vertical_radius_ * 1.0 +
                            horizontal_radius_ * horizontal_radius_ * 1.0) / 2);
    }

    double Ellipse::Area() const{
        return pi * vertical_radius_ * horizontal_radius_;
    }

    Point Ellipse::GetCenterPoint() const { return center_; }
    int Ellipse::GetSmallRadius() const { return vertical_radius_; }
    int Ellipse::GetBigRadius() const { return horizontal_radius_; }

}

