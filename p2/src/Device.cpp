#include "Device.hpp"

#include <iostream>
#include <stdexcept>

namespace{
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
}

int Device::validate_transmission_interval(int interval){
    if(interval < 1 || interval > 3600) throw std::invalid_argument("Transmission interval must be between 1 and 3600 seconds.");
    return interval;
}

std::string Device::validate_id(std::string id){
    if(id.empty()) throw std::invalid_argument("Device ID cannot be empty");
    return id;
}

Device::Device(std::string id, int transmission_interval) : 
    id(std::move(validate_id(id))), transmission_interval(validate_transmission_interval(transmission_interval)){}

void Device::set_operation_mode(OperationMode opMode){
    if(deviceStatus == DeviceStatus::Active) throw std::logic_error("Cannot change operation mode while device is active.");
    operationMode = opMode;
}

void Device::set_transmission_interval(int interval){
    if(deviceStatus == DeviceStatus::Active) throw std::logic_error("Cannot change transmission interval while device is active.");
    transmission_interval = validate_transmission_interval(interval);
}

void Device::deactivate_device(){
    deviceStatus = DeviceStatus::Inactive;
}

void Device::activate_device(){
    deviceStatus = DeviceStatus::Active;
} 

std::string Device::get_id() const { 
    return id; 
}

std::string Device::get_device_status() const {
    return statusToString(deviceStatus);
}

std::string Device::get_operation_mode() const {
    return modeToString(operationMode);
}

int Device::get_transmission_interval() const {
    return transmission_interval;
}

void Device::info() const{
    std::cout << "########## Device Information ##########" << '\n';
    std::cout << "Device ID: " << get_id() << '\n';
    std::cout << "Transmission Interval: " << get_transmission_interval() << " seconds" << '\n';
    std::cout << "Operation Mode: " << modeToString(operationMode) << '\n';
    std::cout << "Device Status: " << statusToString(deviceStatus) << '\n';
}