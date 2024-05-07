#include "Functionalities.hpp"

int main()
{

    Container data;
    SensorContainer scdata;

    CreateObject(data, scdata);

    try
    {

        std::future<std::unordered_set<int>> F1 = std::async(&ReturnAllUniqueSensorTypes, std::ref(data));

        std::unordered_set<int> f1result = F1.get();

        for (int num : f1result)
        {
            if (num == 1)
            {
                std::cout << "INTEGRATED \n";
            }
            else
            {
                std::cout << "PLUG_IN \n";
            }
        }

        std::future<Container> F2 = std::async(&LastNInstances, std::ref(data), 3);


        Container f2result = F2.get();

        for(auto v : f2result) {

            std::cout << *v << std::endl;
        }

        std::future<int> F3 = std::async(&ReturnMaxReading, std::ref(data), "100");

        int f3result = F3.get();

        std::cout << f3result << std::endl;

        Predicate pred = [](Vehicleptr& ptr) -> bool {
            return ptr.get()->modelName() == "Hyundai";
        };
        
        std::future<std::size_t> F4 = std::async(&InstanceCount,std::ref(data),pred);

        std::size_t result =  F4.get();

        std::cout << result << std::endl;
    }
    catch (std::future_error e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}