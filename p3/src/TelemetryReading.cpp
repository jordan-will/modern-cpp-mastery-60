#include "TelemetryReading.hpp"

#include <stdexcept>
#include <cmath>

std::string TelemetryReading::validate_id(const std::string& id){
    if(id.empty()){
        throw std::invalid_argument("Sensor ID cannot be empty");
    }

    return id;
}

double TelemetryReading::validate_value(double value){
    if(std::isnan(value) || std::isinf(value)){
        throw std::invalid_argument("Measured value must be a valid number");
    }

    return value;
}

SensorType TelemetryReading::validate_sensor_type(SensorType type) {
    switch (type) {
        case SensorType::Temperature:
        case SensorType::Humidity:
        case SensorType::Pressure:
            return type;

        default:
            throw std::invalid_argument("Invalid sensor type.");
    }
}

TelemetryReading::TelemetryReading(std::string id, SensorType type, double value) : 
                                  sensor_id(validate_id(id)), sensor_type(validate_sensor_type(type)), measured_value(validate_value(value)){}

const std::string& TelemetryReading::get_sensor_id() const{
    return sensor_id;
}

SensorType TelemetryReading::get_sensor_type() const {
    return sensor_type;
}

double TelemetryReading::get_measured_value() const{
    return measured_value;
}