#include <iostream>
using namespace std;

class IVehicle
{
public:
    // pure virtual function
    // this must be overridden by every child class
    virtual void getInfo() = 0;
};

class TwoWheeler : public IVehicle
{
    void getInfo()
    {
        cout << "Its a 2 wheeler";
    }
};
class ThreeWheeler : public IVehicle
{
    void getInfo()
    {
        cout << "Its a 3 wheeler";
    }
};
class FourWheeler : public IVehicle
{
    void getInfo()
    {
        cout << "Its a 4 wheeler";
    }
};

class VehicleFactory
{
public:
    static IVehicle *getVehicle(int passengerCount)
    {
        if (passengerCount == 1)
        {
            return new TwoWheeler();
        }
        else if (passengerCount == 2)
        {
            return new TwoWheeler();
        }
        else if (passengerCount == 3)
        {
            return new ThreeWheeler();
        }
        else
        {
            return new FourWheeler();
        }
    }
};

int main()
{
    IVehicle *vehicle1 = VehicleFactory::getVehicle(2);
    vehicle1->getInfo();
    IVehicle *vehicle2 = VehicleFactory::getVehicle(5);
    vehicle2->getInfo();
}