#pragma once

#include <cstddef>

struct TelemetryStatistics{
    std::size_t count{0};
    double min{0.0};
    double max{0.0};
    double average{0.0};
};