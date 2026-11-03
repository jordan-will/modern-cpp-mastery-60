#pragma once

#include <string>

enum class OperationMode{
    Normal,
    PowerSaving,
    Maintenance
};

enum class DeviceStatus{
    Active,
    Inactive
};

class Device{
private:
    std::string id;
    int transmission_interval;
    OperationMode operation_mode{OperationMode::Normal};
    DeviceStatus device_status{DeviceStatus::Inactive};

    static int validate_transmission_interval(int interval);
    static std::string validate_id(const std::string& id);


public:
    Device(std::string id, int transmission_interval);

    const std::string& get_id() const;
    int get_transmission_interval() const;
    DeviceStatus get_device_status() const;
    OperationMode get_operation_mode() const;

    void set_transmission_interval(int interval);
    void set_operation_mode(OperationMode operationMode);
    void deactivate_device();
    void activate_device();

};