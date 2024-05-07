#include "VehicleSensorUnit.hpp"

VehicleSensor::VehicleSensor(SensorUnitType type, std::array<float, 5> reading, float value) :
m_sensor_unit_type{type},
m_sensor_last_5_reading{reading},
m_sensor_threashold_value{value}
{
}
std::ostream &operator<<(std::ostream &os, const VehicleSensor &rhs) {
    os << " m_sensor_threashold_value: " << rhs.m_sensor_threashold_value;
    return os;
}
