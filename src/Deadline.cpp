#include <iostream>
#include <chrono>
#include "Dates.hpp"
#include "Deadline.hpp"
#include "Task.hpp"
#include "ColorManipulators.hpp"

namespace Deadline {

void Deadline::readNewProgress(std::istream& in) {
    in >> (*task);
}

void Deadline::readNewDate(std::istream& in) {
    date.readDate(in);
}

void Deadline::readNewTime(std::istream& in) {
    date.readTime(in);
}

std::string Deadline::getName() const {
    return subjectName;
}

void Deadline::printTask(std::ostream& out) const {
    task->printDescription(out);
}

void Deadline::printDate(std::ostream& out) const {
    out << date;
}

std::ostream& operator<<(std::ostream& out, const Deadline& deadline) {
    if (deadline.task->isFull()) {
        out << Coloring::setColor(Coloring::Color::Green);
    } else if (deadline.date.isBad() || deadline.task->isBad()) {
        out << Coloring::setColor(Coloring::Color::Red);
    } else {
        out << Coloring::setColor(Coloring::Color::Blue);
    }
    out << deadline.subjectName << ":\n";

    if (deadline.date.isBad()) {   
        out << Coloring::setColor(Coloring::Color::Red);
    } else {
        out << Coloring::setColor(Coloring::Color::Green);
    }
    out << "  Date: " << deadline.date << "\n";

    if (deadline.task->isBad()) {   
        out << Coloring::setColor(Coloring::Color::Red);
    } else if (deadline.task->isFull()) {
        out << Coloring::setColor(Coloring::Color::Green);
    } else {
        out << Coloring::setColor(Coloring::Color::Blue);
    }
    out << "  Task: " << (*deadline.task) << Coloring::resetColor();
    
    return out;
}

std::istream& operator>>(std::istream& in, Deadline& deadline) {
    try {
        in >> deadline.subjectName;
        deadline.task = Task::readTask(in);
        deadline.date.readDate(in);
        deadline.date.readTime(in);
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return in;
}

} //namespace Deadline