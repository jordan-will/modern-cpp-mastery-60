#include "utils.hpp"
#include "TelemetryCollector.hpp"
#include "SensorType.hpp"
#include <iostream>
#include <iomanip>

namespace presentation {

void print_telemetry_summary(const TelemetryCollector& collector) {

    std::cout << "\n========================================\n";
    std::cout << "         IOT TELEMETRY SUMMARY          \n";
    std::cout << "========================================\n";
    
    std::cout << "Total Readings Recorded: " << collector.get_total_readings() << "\n\n";

    const SensorType types[] = {
        SensorType::Temperature,
        SensorType::Humidity,
        SensorType::Pressure
    };

    for (SensorType type : types) {
        std::string type_name = sensorTypeToString(type);
        std::size_t count = collector.count_readings_by_type(type);

        std::cout << "--- Sensor Type: " << type_name << " ---\n";
        std::cout << "  Readings Count: " << count << "\n";

        if (count > 0) {
            try {
                TelemetryStatistics stats = collector.get_statistics_by_type(type);
                
                // Formatting floating-point outputs to 2 decimal places
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "  Min Value:     " << stats.min << "\n";
                std::cout << "  Max Value:     " << stats.max << "\n";
                std::cout << "  Average Value: " << stats.average << "\n";

            } catch (const std::exception& e) {
                std::cout << "  Statistics Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "  Status: No data recorded.\n";
        }
        std::cout << "\n";
    }
    std::cout << "========================================\n";
}

} 