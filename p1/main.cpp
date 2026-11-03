#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <string>

enum class SensorStatus {
    Normal,
    Warning,
    Critical
};

std::string get_sensor_status(SensorStatus status) {
    switch (status) {
        case SensorStatus::Normal:
            return "Normal";

        case SensorStatus::Warning:
            return "Warning";

        case SensorStatus::Critical:
            return "Critical";
    }

    return "Unknown";
}

void print_temperature_status(const std::array<int, 10>& temperatures, int min, int max){
    for(const int& temp : temperatures){
        if(temp < min){
            std::cout << temp << " is below the range." << '\n';
        } else if(temp > max){
            std::cout << temp << " is above the range." << '\n';
        } else {
            std::cout << temp << " is within the range." << '\n';
        }
    }
}

int main(){

    std::array<int, 10> temperatures{40, 7, 1, 47, 17, 15, 14, 8, 43, 26};

    constexpr int minimum_operating_temperature{10}; 
    constexpr int maximum_operating_temperature{40};

    // #3
    auto [min_it, max_it] = std::minmax_element(temperatures.begin(), temperatures.end());
    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double temperature_average = sum / temperatures.size();

    // #4
    std::size_t below_the_range = std::count_if(
        temperatures.begin(), temperatures.end(),
        [minimum_operating_temperature](int temperature){
            return temperature < minimum_operating_temperature;
        }
    );

    std::size_t within_the_range = std::count_if(
        temperatures.begin(), temperatures.end(),
        [minimum_operating_temperature, maximum_operating_temperature](int temperature){
            return temperature >= minimum_operating_temperature && temperature <= maximum_operating_temperature;
        }
    );

    std::size_t above_the_range = std::count_if(
        temperatures.begin(), temperatures.end(),
        [maximum_operating_temperature](int temperature){
            return temperature > maximum_operating_temperature;
        }
    );

    std::cout << "########## SENSOR REPORT ##########" << '\n';
    std::cout << "Below Range: " << below_the_range << '\n';
    std::cout << "Within Range: " << within_the_range << '\n';
    std::cout << "Above Range: " << above_the_range << '\n';
    std::cout << "Temperature Average: " << temperature_average << '\n';

    if(min_it != temperatures.end() && max_it != temperatures.end()){
        std::cout << "Minimum Temperature: " << *min_it << '\n';
        std::cout << "Maximum Temperature: " << *max_it << '\n';
    }else{
        std::cout << "Error: Unable to determine minimum and maximum temperatures." << '\n';
    }

    print_temperature_status(temperatures, minimum_operating_temperature, maximum_operating_temperature);

    SensorStatus sensor_status{SensorStatus::Warning};

    if (within_the_range == temperatures.size()) {
        sensor_status = SensorStatus::Normal;
    } else if (within_the_range == 0) {
        sensor_status = SensorStatus::Critical;
    } else {
        sensor_status = SensorStatus::Warning;
    }

    std::cout << "Sensor Status: " << get_sensor_status(sensor_status) << '\n';

    return 0;
}