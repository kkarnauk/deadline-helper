#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Task.hpp"
#include "Dates.hpp"

namespace Deadline {

class Deadline final {
public:
    std::string getName() const;

    void readNewProgress(std::istream& in);
    void readNewTime(std::istream& in);
    void readNewDate(std::istream& in);

    void printTask(std::ostream& out) const;
    void printDate(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Deadline& deadline);
    friend std::istream& operator>>(std::istream& in, Deadline& deadline);
private:
    std::string subjectName;
    std::unique_ptr<Task::Task> task;
    Dates::Date date;
};

} //namespace Deadline