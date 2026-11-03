#include "Device.hpp"

#include <stdexcept>

int Device::validate_transmission_interval(int interval){
    if(interval < 1 || interval > 3600) throw std::invalid_argument("Transmission interval must be between 1 and 3600 seconds.");
    return interval;
}

std::string Device::validate_id(const std::string& id){
    if(id.empty()) throw std::invalid_argument("Device ID cannot be empty");
    return id;
}

Device::Device(std::string id, int transmission_interval) : 
    id(validate_id(id)), transmission_interval(validate_transmission_interval(transmission_interval)){}

void Device::set_operation_mode(OperationMode opMode){
    if(device_status == DeviceStatus::Active) throw std::logic_error("Cannot change operation mode while device is active.");
    operation_mode = opMode;
}

void Device::set_transmission_interval(int interval){
    if(device_status == DeviceStatus::Active) throw std::logic_error("Cannot change transmission interval while device is active.");
    transmission_interval = validate_transmission_interval(interval);
}

void Device::deactivate_device(){
    device_status = DeviceStatus::Inactive;
}

void Device::activate_device(){
    device_status = DeviceStatus::Active;
} 

const std::string& Device::get_id() const { 
    return id; 
}

DeviceStatus Device::get_device_status() const {
    return device_status;
}

OperationMode Device::get_operation_mode() const {
    return operation_mode;
}

int Device::get_transmission_interval() const {
    return transmission_interval;
}
