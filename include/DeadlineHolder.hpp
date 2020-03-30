#pragma once

#include <iosfwd>
#include <string>
#include <vector>
#include "Deadline.hpp"

namespace Deadline {

class Holder final {
public:
    void readNewDeadline(std::istream& in);
    void removeDeadline(const std::string& subjectName);
    void readNewDeadlineDate(std::istream& in, const std::string& subjectName);
    void readNewDeadlineTime(std::istream& in,  const std::string& subjectName);
    void readNewDeadlineProgress(std::istream& in, const std::string& subjectName);

    void printDeadlineList(std::ostream& out) const;
    void clear();

    friend std::ostream& operator<<(std::ostream& out, const Holder& holder);
    friend std::istream& operator>>(std::istream& in, Holder& holder);
private:
    std::vector<Deadline> deadlines;

    Deadline& findDeadline(const std::string& subjectName);
};

} //namespace Deadline