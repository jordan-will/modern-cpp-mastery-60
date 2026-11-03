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
    OperationMode operationMode{OperationMode::Normal};
    DeviceStatus deviceStatus{DeviceStatus::Inactive};

    static int validate_transmission_interval(int interval);
    static std::string validate_id(std::string id);


public:
    Device(std::string id, int transmission_interval);

    std::string get_id() const;
    std::string get_device_status() const;
    std::string get_operation_mode() const;
    int get_transmission_interval() const;

    void set_transmission_interval(int interval);
    void set_operation_mode(OperationMode operationMode);
    void deactivate_device();
    void activate_device();

    void info() const;

};