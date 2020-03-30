#pragma once

#include <iosfwd>
#include <chrono>
#include <stddef.h>

namespace Dates {

class Date final {
public:
    Date(std::time_t time = 0);

    std::size_t getYear()   const;
    std::size_t getMonth()  const;
    std::size_t getDay()    const;
    std::size_t getHour()   const;
    std::size_t getMinute() const;
    std::size_t getSecond() const;

    std::chrono::system_clock::duration operator-(const Date& other) const;

    void readDate(std::istream& in);
    void readTime(std::istream& in);

    bool isBad() const;
private:
    std::time_t currentTime;
};

std::ostream& operator<<(std::ostream& out, const Date& date);

} //namespace Dates
