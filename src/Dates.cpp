#include <iostream>
#include <iomanip>
#include <chrono>
#include <stddef.h>
#include <exception>
#include "Dates.hpp"

namespace Dates {

Date::Date(std::time_t time) :
    currentTime{time} {}

std::size_t Date::getYear() const {
    return std::localtime(&currentTime)->tm_year + 1900;
}

std::size_t Date::getMonth() const {
    return std::localtime(&currentTime)->tm_mon + 1;
}

std::size_t Date::getDay() const {
    return std::localtime(&currentTime)->tm_mday;
}

std::size_t Date::getHour() const {
    return std::localtime(&currentTime)->tm_hour;
}

std::size_t Date::getMinute() const {
    return std::localtime(&currentTime)->tm_min;
}

std::size_t Date::getSecond() const {
    return std::localtime(&currentTime)->tm_sec;
}

std::chrono::system_clock::duration Date::operator-(const Date& other) const {
    auto end   = std::chrono::system_clock::from_time_t(currentTime);
    auto start = std::chrono::system_clock::from_time_t(other.currentTime);
    if (start > end) {
        return std::chrono::system_clock::duration(0);
    }
    return end - start;
}

void Date::readDate(std::istream& in) {
    char firstDelimiter;
    char secondDelimiter;
    std::size_t readDay;
    std::size_t readMonth;
    std::size_t readYear;
    in >> readDay >> firstDelimiter >> readMonth >> secondDelimiter >> readYear;
    if (firstDelimiter != '.' || secondDelimiter != '.') {
        throw std::logic_error("Invalid format of date.");
    }
    std::tm* date = localtime(&currentTime);
    date->tm_mday = readDay;
    date->tm_mon = readMonth - 1;
    date->tm_year = readYear - 1900;

    currentTime = mktime(date);
}

void Date::readTime(std::istream& in) {
    char firstDelimiter;
    char secondDelimiter;
    std::size_t readHour;
    std::size_t readMinute;
    std::size_t readSecond;
    in >> readHour >> firstDelimiter >> readMinute >> secondDelimiter >> readSecond;
    if (firstDelimiter != ':' || secondDelimiter != ':') {
        throw std::logic_error("Invalid format of time.");
    }
    std::tm* date = localtime(&currentTime);
    date->tm_hour = readHour;
    date->tm_min = readMinute;
    date->tm_sec = readSecond;

    currentTime = mktime(date);
}

bool Date::isBad() const {
    Date currentDate{std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
    auto diff = (*this) - currentDate;
    return (diff <= std::chrono::hours(24));
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << std::setw(2) << std::setfill('0') << date.getDay() << "."
        << std::setw(2) << std::setfill('0') << date.getMonth() << "." 
        << date.getYear() << " "
        << std::setw(2) << std::setfill('0') << date.getHour() << ":"
        << std::setw(2) << std::setfill('0') << date.getMinute() << ":"
        << std::setw(2) << std::setfill('0') << date.getSecond();

    return out;
}

} //namespace Dates