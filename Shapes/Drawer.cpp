#include "Primitives.h"
#include "Drawer.h"

Screen::Screen() {
    hwnd = GetConsoleWindow();

    MoveWindow(hwnd, 100, 100, 1520, 780, TRUE);
    hdc =  GetDC(hwnd);
    GetClientRect(hwnd, &user_window);
    pen =  CreatePen(PS_SOLID, 7, RGB(0, 255, 0));
    weight = user_window.right  - user_window.left;
    height = user_window.bottom - user_window.top;
    SelectObject(hdc, pen);
}

HDC& Screen::GetHdc() { return hdc; }
int Screen::GetWeight() const { return weight; }
int Screen::GetHeight() const { return height; }

Screen::~Screen() {
    DeleteObject(pen);
}

Drawer& Drawer::operator=(Drawer dm) noexcept {
    self_ = std::move(dm.self_);
    return *this;
}

void draw(const Drawer& dm, Screen& screen) {
    dm.self_->Draw(screen);
}

void Draw(const Figures::Point& data, Screen& screen){
    SetPixel(screen.GetHdc(), data.GetX(), data.GetY(), RGB(0, 255, 0));
}

void Draw(const Figures::Line& data, Screen& screen){
    MoveToEx(screen.GetHdc(), data.GetStart().GetX(), data.GetStart().GetY(), nullptr);
    LineTo(screen.GetHdc(), data.GetFinish().GetX(), data.GetFinish().GetY());
}

void Draw(const Figures::Polygon& data, Screen& screen){
    for(size_t i = 0, size = data.GetNumPeaks(); i < size - 1; ++i){
        MoveToEx(screen.GetHdc(), data[i].GetX(), data[i].GetY(), nullptr);
        LineTo(screen.GetHdc(), data[i + 1].GetX(), data[i + 1].GetY());
    }
    MoveToEx(screen.GetHdc(), data[data.GetNumPeaks() - 1].GetX(), data[data.GetNumPeaks() - 1].GetY(), nullptr);
    LineTo(screen.GetHdc(), data[0].GetX(), data[0].GetY());
}

void Draw(const Figures::Circle& data, Screen& screen){
    std::vector<Figures::Point> points = Figures::GetPoints(360, data.GetCenterPoint(), data.GetRadius());
    Draw(Figures::Polygon(points), screen);
}

void Draw(const Figures::Ellipse& data, Screen& screen){
    std::vector<Figures::Point> points = Figures::GetPoints(data.GetCenterPoint(), data.GetSmallRadius(), data.GetBigRadius());
    Draw(Figures::Polygon(points), screen);
}

