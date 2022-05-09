#include "Primitives.h"

namespace Figures {
    double Point::GetX() const { return x_; }

    double Point::GetY() const { return y_; }

    double Distance(const Point &first, const Point &second) {
        return sqrt(
                pow((second.GetX() - first.GetX()), 2) +
                pow((second.GetY() - first.GetY()), 2)
        );
    }


    double Line::GetLength() const {
        return length_;
    }

    Point Line::GetStart() const { return start_; }
    Point Line::GetFinish() const { return finish_; }

}