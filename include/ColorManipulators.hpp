#pragma once

#include <iosfwd>

namespace Coloring {

class setColor final {
public:

    enum class Color : int {
        Black   = 30,
        Red     = 31,
        Green   = 32,
        Yellow  = 33,
        Blue    = 34,
        Magenta = 35,
        Cyan    = 36,
        White   = 37
    };

    setColor(Color value);
    ~setColor() = default;

    setColor(const setColor& other)            = delete;
    setColor(setColor&& other)                 = delete;
    setColor& operator=(const setColor& other) = delete;
    setColor& operator=(setColor&& other)      = delete;

    std::ostream& operator()(std::ostream& out) const;

private:
    Color color;
};

std::ostream& operator<<(std::ostream& out, const setColor& sc);

using Color = setColor::Color;


class resetColor final {
public:
    resetColor()  = default;
    ~resetColor() = default;

    resetColor(const resetColor& other)            = delete;
    resetColor(resetColor&& other)                 = delete;
    resetColor& operator=(const resetColor& other) = delete;
    resetColor& operator=(resetColor&& other)      = delete;

    std::ostream& operator()(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const resetColor &rc);

} //namespace Coloring