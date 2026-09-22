#ifndef TIMER_H

#define TIMER_H

#include <chrono>
#include <cstdint>

class Timer {
public:
    using Nanos = std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;

    Timer() {
        restart();
    }

    void restart() {
        timerStart = std::chrono::steady_clock::now();
    }

    template <typename T>
    uint64_t click() { // look and reset time
        auto elapsed = glance<T>(); // look at elapsed time
        restart();
        return elapsed;
    }

    template <typename T>
    uint64_t glance() { // look at time without resetting
        auto now = std::chrono::steady_clock::now(); // gets current time
        return std::chrono::duration_cast<T>(now - timerStart).count(); // current - starting time
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> timerStart;
};

#endif  // TIMER_H