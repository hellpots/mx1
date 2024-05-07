#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "VehicleSensorUnit.hpp"
#include <functional>
#include <ostream>

class Vehicle {

private:
    std::string m_vehicle_id;
    std::string m_model_name;
    std::reference_wrapper<VehicleSensor> m_ref;

public:
    Vehicle() = delete;
    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;

    ~Vehicle() = default;
    Vehicle& operator = (const Vehicle&) = delete;
    Vehicle& operator = (Vehicle&&) = delete;

    Vehicle(std::string id,std::string name,std::reference_wrapper<VehicleSensor> ref);

    std::string vehicleId() const { return m_vehicle_id; }

    std::string modelName() const { return m_model_name; }

    std::reference_wrapper<VehicleSensor> ref() const { return m_ref; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

};

#endif // VEHICLE_HPP
