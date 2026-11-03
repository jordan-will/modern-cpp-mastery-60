#pragma once

#include "Device.hpp"

#include <string>

void print_device_info(const Device& device);
std::string statusToString(DeviceStatus status);
std::string modeToString(OperationMode mode);