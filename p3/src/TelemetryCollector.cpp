#include "TelemetryCollector.hpp"
#include <algorithm>
#include <numeric>
#include <string>
#include <stdexcept>


void TelemetryCollector::add_reading(TelemetryReading reading){
    readings.push_back(std::move(reading));
}

std::size_t TelemetryCollector::get_total_readings() const {
    return readings.size();
}

std::size_t TelemetryCollector::count_readings_by_type(SensorType type) const {
    return std::count_if(
        readings.begin(), readings.end(),
        [type](const TelemetryReading& reading){
            return reading.get_sensor_type() == type;           
        }
    );
}


TelemetryStatistics TelemetryCollector::get_statistics_by_type(SensorType type) const {
   
    
    std::size_t count = 0;
    double sum = 0.0;
    double min_val = 0.0;
    double max_val = 0.0;

    bool first = true;

    for (const auto& r : readings) {
        if (r.get_sensor_type() == type) {
            double val = r.get_measured_value();
            if (first) {
                min_val = val;
                max_val = val;
                first = false;
            } else {
                if (val < min_val) min_val = val;
                if (val > max_val) max_val = val;
            }
            sum += val;
            ++count;
        }
    }

    if (count == 0) {
        throw std::logic_error("No readings available for the requested sensor type to calculate statistics.");
    }

    double average = sum / static_cast<double>(count);

    return TelemetryStatistics{count, min_val, max_val, average};
}