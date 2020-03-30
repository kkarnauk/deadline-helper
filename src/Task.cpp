#include <iostream>
#include <stddef.h>
#include <memory>
#include <string>
#include "Task.hpp"

namespace Task {

std::string Task::toStringTaskId(Task::TaskId id) {
    switch(id) {
        case Task::TaskId::BigTask:
            return std::string("big");
        case Task::TaskId::ProblemSet:
            return std::string("set");
        default:
            throw std::logic_error("No such a kind of task.");
    }
}

std::ostream& operator<<(std::ostream& out, const Task& task) {
    task.printProgress(out);

    return out;
}

std::istream& operator>>(std::istream&in, Task& task) {
    task.readProgress(in);

    return in;
}

std::ostream& ProblemSet::saveProgress(std::ostream& out) const {
    out << static_cast<int>(TaskId::ProblemSet) << " " << allProblemNumber 
        << " " << completedProblemsNumber << std::endl;

    return out;
}

void ProblemSet::printProgress(std::ostream& out) const {
    out << completedProblemsNumber << "/" << allProblemNumber << " completed";
}

void ProblemSet::readProgress(std::istream& in) {
    in >> allProblemNumber >> completedProblemsNumber;
}

bool ProblemSet::isBad() const {
    return allProblemNumber * 4 / 5 > completedProblemsNumber || completedProblemsNumber == 0;
}

bool ProblemSet::isFull() const {
    return allProblemNumber == completedProblemsNumber;
}

void ProblemSet::printDescription(std::ostream& out) const {
    out << Task::toStringTaskId(Task::TaskId::ProblemSet) << " " << allProblemNumber << " " << completedProblemsNumber;
}


std::ostream& BigTask::saveProgress(std::ostream& out) const {
    out << static_cast<int>(TaskId::BigTask) << " " << completenessPercent;

    return out;
}

void BigTask::printProgress(std::ostream& out) const {
    out << completenessPercent << "% completed";
}

void BigTask::readProgress(std::istream& in) {
    in >> completenessPercent;
}

bool BigTask::isBad() const {
    return completenessPercent < 85;
}

bool BigTask::isFull() const {
    return completenessPercent == 100;
}

void BigTask::printDescription(std::ostream& out) const {
    out << Task::toStringTaskId(Task::TaskId::BigTask) << " " << completenessPercent;
}


std::unique_ptr<Task> readTask(std::istream& in) {
    std::string type;
    in >> type;
    std::unique_ptr<Task> task = nullptr;
    if (type == Task::toStringTaskId(Task::TaskId::BigTask)) {
        task = std::make_unique<BigTask>();
    } else if (type == Task::toStringTaskId(Task::TaskId::ProblemSet)) {
        task = std::make_unique<ProblemSet>();
    } else {
        throw std::logic_error("No such a kind of task.");
    }
    in >> (*task);
    
    return task;
}

} //namespace Task