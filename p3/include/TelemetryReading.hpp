#pragma once

#include <string>
#include "SensorType.hpp"

class TelemetryReading{
private:
    std::string sensor_id;
    SensorType sensor_type;
    double measured_value;

    //static validation helper to protect class invariants
    static std::string validate_id(const std::string& id);
    static double validate_value(double value);
    static SensorType validate_sensor_type(SensorType type);

public:
    TelemetryReading(std::string id, SensorType type, double value);

    const std::string& get_sensor_id() const;
    SensorType get_sensor_type() const;
    double get_measured_value() const;

};