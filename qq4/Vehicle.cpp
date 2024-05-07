#include "Vehicle.hpp"

Vehicle::Vehicle(std::string id, std::string name, std::reference_wrapper<VehicleSensor> ref) :
m_vehicle_id{id},
m_model_name{name},
m_ref{ref}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_vehicle_id: " << rhs.m_vehicle_id
       << " m_model_name: " << rhs.m_model_name
       << " m_ref: " << rhs.m_ref;
    return os;
}
