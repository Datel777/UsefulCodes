#pragma once

#include <chrono>

namespace Benchmark
{
    using time = unsigned long long;
    using timestamp = std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds>;

    inline timestamp getTimestamp()
    {
        return std::chrono::steady_clock::now();
    }

    //usec = microseconds
    inline time getUSecDuration(const timestamp &start, const timestamp &end)
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
}


//----BENCHMARK
#define BENCHMARK(function, count, timeOut)\
    {\
        Benchmark::timestamp ___timeStart___(Benchmark::getTimestamp());\
        for (int ___i___=0; ___i___<count; ++___i___)\
            function;\
        timeOut = Benchmark::getUSecDuration(___timeStart___, Benchmark::getTimestamp());\
    }

/* Using
    Benchmark::time time;

    BENCHMARK(test(1,2), 100000, time)

    cout << "time = " << time << endl;
*/


//----BENCHMARKDEBUG
#include <iostream>

#define BENCHMARKDEBUG(function, count)\
    {\
        Benchmark::time ___time___;\
        BENCHMARK(function, count, ___time___);\
        std::cout << "BENCHMARK(" #function ", " #count ") = " << time << std::endl;\
    }

/* Using
    BENCHMARKDEBUG(test(1,2), 100000)
*/
