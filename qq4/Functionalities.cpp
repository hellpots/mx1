#include "Functionalities.hpp"

void CreateObject(Container &data, SensorContainer &scdata)
{

    scdata.push_back(VehicleSensor(SensorUnitType::INTEGRATED,std::array<float,5>{1.1f,2.2f,3.3f,4.4f,5.5f},20.2f));

    scdata.push_back(VehicleSensor(SensorUnitType::PLUG_IN,std::array<float,5>{1.1f,2.2f,3.3f,4.4f,5.5f},21.2f));


    data.push_back(std::make_shared<Vehicle>("100","Hyundai",scdata[0]));

    data.push_back(std::make_shared<Vehicle>("100","Maruti",scdata[0]));

    data.push_back(std::make_shared<Vehicle>("100","Tata",scdata[1]));

    data.push_back(std::make_shared<Vehicle>("100","BMW",scdata[1]));

}

std::unordered_set<int> ReturnAllUniqueSensorTypes(const Container& data){
    if(data.empty()){
        throw;
    }

    std::unordered_set<int> ans;
    for(const Vehicleptr& ptr : data){
        ans.insert(static_cast<int>(ptr.get()->ref().get().sensorUnitType()));
    }

    return ans;
}



Container LastNInstances(const Container& data, unsigned int N){
    if(data.empty()){
        throw;
    }

    Container lastN;
    auto itr = data.begin();
    std::advance(itr, data.size()- N);

    for(auto itr1 : data){
        lastN.push_back(itr1);
    }

    return lastN;

}

int ReturnMaxReading(const Container& data, std::string v_id){
    if(data.empty()){
        throw;
    }

    Container result;
    std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),
        [&](const Vehicleptr& p1){
            return p1->vehicleId() == v_id;
        }
    );

    int maxi;
    for(const Vehicleptr& ptr : data){
        std::array<float,5> v = ptr.get()->ref().get().sensorLast5Reading();

        maxi = v[0];
        for(int i=0; i<5 ;i++){
            if(v[i] > maxi){
                maxi = v[i];
            }
        }
    }
    return maxi;
}


std::size_t InstanceCount(const Container& data, Predicate pred){
    if(data.empty()){
        throw;
    }

    int count  = std::count_if(
        data.begin(),
        data.end(),
        [&](const Vehicleptr& ptr) -> bool {
            return ptr.get()->modelName() == "Hyundai";
        }
    );

    return count;
}




