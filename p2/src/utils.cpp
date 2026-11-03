#include "utils.hpp"

#include <iostream>



std::string statusToString(DeviceStatus status){
        switch(status){
            case DeviceStatus::Active: return "Active";
            case DeviceStatus::Inactive: return "Inactive";
            default: return "Unknown";
        }
}

std::string modeToString(OperationMode mode){
    switch(mode){
        case OperationMode::Normal: return "Normal";
        case OperationMode::PowerSaving: return "Power Saving";
        case OperationMode::Maintenance: return "Maintenance";
        default: return "Unknown";
    }
}

void print_device_info(const Device& device) {
    std::cout << "Device ID: " << device.get_id() << "\n";
    std::cout << "Transmission Interval: " << device.get_transmission_interval() << " seconds\n";
    std::cout << "Operation Mode: " << modeToString(device.get_operation_mode()) << "\n";
    std::cout << "Device Status: " << statusToString(device.get_device_status()) << "\n";
}