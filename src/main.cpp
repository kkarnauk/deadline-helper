#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "DeadlineHolder.hpp"

int main() {
    static const char* filename = "deadlineList.txt";

    std::cin.exceptions(std::istream::failbit | std::istream::badbit);
    std::cout.exceptions(std::ostream::failbit | std::ostream::badbit);

    while (true) {
        try {
            std::ifstream in(filename);
            Deadline::Holder holder;
            if (in.is_open()) {
                in >> holder;
            }

            std::string command;
            std::cin >> command;
            if (command == "exit") {
                break;
            } else if (command == "list") {
                holder.printDeadlineList(std::cout);
            } else if (command == "add") {
                holder.readNewDeadline(std::cin);
            } else if (command == "remove") {
                std::string name;
                std::cin >> name;
                holder.removeDeadline(name);
            } else if (command == "change") {
                std::string name;
                std::string what;
                std::cin >> name >> what;
                if (what == "progress") {
                    holder.readNewDeadlineProgress(std::cin, name);
                } else if (what == "date") {
                    holder.readNewDeadlineDate(std::cin, name);
                } else if (what == "time") {
                    holder.readNewDeadlineTime(std::cin, name);
                } else {
                    throw std::logic_error("Unknown changing kind.");
                }
            } else if (command == "clear") {
                holder.clear();
            } else {
                throw std::logic_error("Unknown command.");
            }
            std::ofstream out(filename);
            out << holder;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cin.ignore(256, '\n');
        } catch (...) {
            std::cerr << "Unknown error occurred." << std::endl;
            break;
        }
    }
}