#ifndef VEHICLESENSORUNIT_HPP
#define VEHICLESENSORUNIT_HPP

#include "SensorUnitType.hpp"
#include <iostream>
#include <string>
#include <array>
class VehicleSensor {

private:
    SensorUnitType m_sensor_unit_type;
    std::array<float,5> m_sensor_last_5_reading;
    float m_sensor_threashold_value;

public:

    VehicleSensor() = delete;
    VehicleSensor(const VehicleSensor&) = delete;
    VehicleSensor(VehicleSensor&&) = default;

    ~VehicleSensor() = default;
    VehicleSensor& operator = (const VehicleSensor&) = delete;
    VehicleSensor& operator = (VehicleSensor&&) = delete;

    VehicleSensor(SensorUnitType type,std::array<float,5> reading,float value);
    
    SensorUnitType sensorUnitType() const { return m_sensor_unit_type; }

    float sensorThreasholdValue() const { return m_sensor_threashold_value; }

    std::array<float,5> sensorLast5Reading() const { return m_sensor_last_5_reading; }

    friend std::ostream &operator<<(std::ostream &os, const VehicleSensor &rhs);
    
};

#endif // VEHICLESENSORUNIT_HPP
