#pragma once

#include <vector>
#include <cstddef>
#include "TelemetryReading.hpp"
#include "SensorType.hpp" 
#include "TelemetryStatistics.hpp"

class TelemetryCollector{
private:
    std::vector<TelemetryReading> readings;

public:
    TelemetryCollector() = default;

    void add_reading(TelemetryReading reading);

    std::size_t get_total_readings() const;
    std::size_t count_readings_by_type(SensorType type) const;

    TelemetryStatistics get_statistics_by_type(SensorType type) const;
};