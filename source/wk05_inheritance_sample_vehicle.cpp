//----------------------------------------------------------
// wk05_inheritance_sample_vehicle.cpp
//
// Demos inheritance:
//      - base class Vehicle
//      - derived classes Car, Boat
//
// Example of 
//      1) Redefining base class member functions, and
//      2) Polymorphism: derived class instances have
//         more than one type
//      3) Pointers are interchangeable, but
//         programmers must use the correct type
//         to access data.
//----------------------------------------------------------
#include "Vehicles.h"   // classes Vehicle, Car, Boat

#include <iostream>
#include <vector>

//----------------------------------------------------------
// using symbols
//----------------------------------------------------------
using std::cin;
using std::cout;
using std::vector;

//----------------------------------------------------------
// entry point
//----------------------------------------------------------
int main() {
    // vector vv can store pointers to
    //      1) Vehicle instances, and
    //      2) Car instances (Car is-a Vehicle), and
    //      3) Boat instances (Boat is-a Vehicle)

    // create a Car instance and store its address in our vector
    vector<Vehicle*> vv;

    Vehicle* pVehicle = new Vehicle;
    vv.push_back(pVehicle);
    cout << "Element " << vv.size() - 1 
        << " is a " << pVehicle->getInfo() << "\n\n";

    Car* pCar = new Car;
    vv.push_back(pCar);
    cout << "Element " << vv.size() - 1
        << " is a " << pCar->getInfo() << "\n\n";

    Boat* pBoat = new Boat;
    vv.push_back(pBoat);
    cout << "Element " << vv.size() - 1
        << " is a " << pBoat->getInfo() << "\n\n";

    // each vector element displays its info
    cout << "Traversing vector vv:\n\n";

    for (Vehicle* pV : vv) {
        cout << pV->getInfo() << ' '
            << pV->getRegType() << '\n';
    }

    cout << '\n';
    cin.get();

    return 0;
}
