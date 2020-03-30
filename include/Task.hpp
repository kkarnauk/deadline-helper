#pragma once

#include <iosfwd>
#include <string>
#include <stddef.h>
#include <memory>

namespace Task {

class Task {
public:

    enum class TaskId {
        ProblemSet = 0,
        BigTask = 1
    };

    static std::string toStringTaskId(TaskId id);

    virtual std::ostream& saveProgress(std::ostream& out) const = 0;
    virtual bool isBad() const = 0;
    virtual bool isFull() const = 0;

    virtual void printDescription(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Task& task);
    friend std::istream& operator>>(std::istream& in, Task& task);

protected:
    virtual void printProgress(std::ostream& out) const = 0;
    virtual void readProgress(std::istream& in) = 0;  
};

class ProblemSet final : public Task {
public:
    std::ostream& saveProgress(std::ostream& out) const override;
    bool isBad() const override;
    bool isFull() const override;

    void printDescription(std::ostream& out) const override;
private:
    std::size_t allProblemNumber;
    std::size_t completedProblemsNumber;

    void printProgress(std::ostream& out) const override;
    void readProgress(std::istream& in) override;
};


class BigTask final : public Task {
public:
    std::ostream& saveProgress(std::ostream& out) const override;
    bool isBad() const override;
    bool isFull() const override;

    void printDescription(std::ostream& out) const override;
private:
    std::size_t completenessPercent;

    void printProgress(std::ostream& out) const override;
    void readProgress(std::istream& in) override;
};


std::unique_ptr<Task> readTask(std::istream& in);

} //namespace Task