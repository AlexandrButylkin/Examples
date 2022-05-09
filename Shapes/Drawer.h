#ifndef SHAPES_DRAWER_H
#define SHAPES_DRAWER_H

#include <windows.h>
#include <memory>

#include "Primitives.h"
#include "Figures.h"

class Screen {
private:
    HWND hwnd;
    HDC  hdc;
    RECT user_window;
    HPEN pen;
    int weight;
    int height;
public:
    Screen();

    HDC& GetHdc();
    int GetWeight() const;
    int GetHeight() const;
    ~Screen();
};

class Drawer final {
private:
    struct IDrawer {
        virtual void Draw(Screen&) const = 0;
        virtual std::unique_ptr<IDrawer> Copy() const = 0;
        virtual ~IDrawer() = default;
    };

    template <typename T>
    struct ObjectDrawer final : public IDrawer {
    private:
        T data_;
    public:
        ObjectDrawer(T object) : data_(std::move(object)){}

        std::unique_ptr<IDrawer> Copy() const override;
        void Draw(Screen& out) const override;
    };

    std::unique_ptr<IDrawer> self_;
public:
    template <typename T>
    Drawer(T data) : self_(std::make_unique<ObjectDrawer<T>>(std::move(data))) {}

    Drawer(const Drawer & dm) : self_(dm.self_->Copy()) {}
    Drawer(Drawer&&) noexcept = default;
    Drawer& operator=(Drawer dm) noexcept;

    friend void draw(const Drawer& dm, Screen& screen);

};

void Draw(const Figures::Point& data, Screen& screen);
void Draw(const Figures::Line& data, Screen& screen);
void Draw(const Figures::Polygon& data, Screen& screen);

template <typename T>
void Draw(const T& data, Screen& screen){
    Draw(static_cast<Figures::Polygon>(data), screen);
}

void Draw(const Figures::Circle& data, Screen& screen);
void Draw(const Figures::Ellipse& data, Screen& screen);

template <typename T>
std::unique_ptr<Drawer::IDrawer> Drawer::ObjectDrawer<T>::Copy() const{
    return std::make_unique<ObjectDrawer>(*this);
}

template <typename T>
void Drawer::ObjectDrawer<T>::Draw(Screen& out) const {
    ::Draw(data_, out);
}


#endif //SHAPES_DRAWER_H
