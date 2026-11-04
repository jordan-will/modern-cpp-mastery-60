#pragma once

#include <cstdint>
#include <string>

enum class SensorType: std::uint8_t{
    Temperature,
    Humidity,
    Pressure
};

inline std::string sensorTypeToString(SensorType type){
    switch(type){
        case SensorType::Temperature: return "Temperature";
        case SensorType::Humidity: return "Humidity";
        case SensorType::Pressure: return "Pressure";
        default: return "Unknown Sensor Type";
    }
}