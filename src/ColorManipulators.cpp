#include <iostream>
#include "ColorManipulators.hpp"

namespace Coloring {

setColor::setColor(Color value) :
    color{value} {}

std::ostream& setColor::operator()(std::ostream& out) const {
    if (&out != &std::cout) {
        return out;
    }
    return out << "\033[1;" << static_cast<int>(color) << "m";
}

std::ostream& operator<<(std::ostream& out, const setColor &sc) {
    return sc(out);
}

std::ostream& resetColor::operator()(std::ostream& out) const {
    if (&out != &std::cout) {
        return out;
    }
    return out << "\033[0m";
}

std::ostream& operator<<(std::ostream& out, const resetColor &rc) {
    return rc(out);
}

} //namespace Coloring