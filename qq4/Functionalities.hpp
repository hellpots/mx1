#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Vehicle.hpp"
#include "EmptyContainer.hpp"
#include "InstanceOutOfBound.hpp"
#include "NegativeInstance.hpp"
#include <list>
#include <memory>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <future>


using Vehicleptr = std::shared_ptr<Vehicle>;
using Container = std::list<Vehicleptr>;
using SensorContainer = std::vector<VehicleSensor>;
using Predicate = std::function<bool(Vehicleptr& ptr)>;


void CreateObject(Container& data,SensorContainer& scdata);

std::unordered_set<int> ReturnAllUniqueSensorTypes(const Container& data);

Container LastNInstances(const Container& data, unsigned int N);

int ReturnMaxReading(const Container& data, std::string v_id);

int ReturnMaxReading(const Container& data, std::string v_id);

std::size_t InstanceCount(const Container& data, Predicate pred);


#endif // FUNCTIONALITIES_HPP