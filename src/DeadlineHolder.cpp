#include <iostream>
#include <string>
#include "DeadlineHolder.hpp"

namespace Deadline {

void Holder::readNewDeadline(std::istream& in) {
    Deadline deadline;
    in >> deadline;
    deadlines.push_back(std::move(deadline));
}

void Holder::removeDeadline(const std::string& subjectName) {
    for (std::size_t i = 0; i < deadlines.size(); i++) {
        if (deadlines[i].getName() == subjectName) {
            deadlines.erase(deadlines.begin() + i);
            break;
        }
    }
}

Deadline& Holder::findDeadline(const std::string& subjectName) {
    for (Deadline& currentDeadline : deadlines) {
        if (currentDeadline.getName() == subjectName) {
            return currentDeadline;
        }
    }
    throw std::logic_error("No such a name");
}

void Holder::readNewDeadlineDate(std::istream& in, const std::string& subjectName) {
    Deadline& deadline = findDeadline(subjectName);
    deadline.readNewDate(in);
}

void Holder::readNewDeadlineTime(std::istream& in, const std::string& subjectName) {
    Deadline& deadline = findDeadline(subjectName);
    deadline.readNewTime(in);
}

void Holder::readNewDeadlineProgress(std::istream& in, const std::string& subjectName) {
    Deadline& deadline = findDeadline(subjectName);
    deadline.readNewProgress(in);
}

void Holder::printDeadlineList(std::ostream& out) const {
    for (const Deadline& deadline : deadlines) {
        out << deadline << std::endl << std::endl;
    }
}

void Holder::clear() {
    deadlines.clear();
}

std::ostream& operator<<(std::ostream& out, const Holder& holder) {
    out << holder.deadlines.size() << std::endl;
    for (const Deadline& deadline : holder.deadlines) {
        out << deadline.getName() << " ";
        deadline.printTask(out);
        out << " ";
        deadline.printDate(out);
        out << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Holder& holder) {
    std::size_t number;
    in >> number;
    for (size_t i = 0; i < number; i++) {
        holder.readNewDeadline(in);
    }
    return in;
}

} //namespace Deadline