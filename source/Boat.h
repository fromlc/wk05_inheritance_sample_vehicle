//----------------------------------------------------------
// polymorphic_vector.cpp
//
// Base class Vehicle
// Derived classes Car, Boat
//
// Example of 
//      1) Redefining base class member functions, and
//      2) Polymorphism: derived class instances have
//         more than one type
//      3) Pointers are interchangeable, but
//         programmers must use the correct type
//         to access data.
//----------------------------------------------------------
#include <iostream>
#include <vector>

//----------------------------------------------------------
// base class Vehicle
//
// member data is a class identifier: 'v' for Vehicle
//----------------------------------------------------------
class Vehicle {
protected:
    char m_classId;

public:
    // Constructor
    Vehicle() : m_classId('v') { std::cout << "New Vehicle\n"; }

    // Base class member functions
    char getClass() { return m_classId; }
    void showInfo() { std::cout << "showInfo: Vehicle\n"; }
};

//----------------------------------------------------------
// Car class is derived from Vehicle
//
// Car inherits from Vehicle as public:
//      Vehicle's private members are not accessible to Car
//
//      Vehicle's protected members become 
//      Car's protected members
//
//      Vehicle's public members become
//      Car's public members
//
// Car redefines Vehicle's showInfo() member function
//----------------------------------------------------------
class Car : public Vehicle {
public:
    // Constructor
    Car() { m_classId = 'c'; std::cout << "New Car\n"; }

    // Vehicle's showInfo() member function is redefined.
    // This function has the same name and the same parameter list.
    // But this function is Car's member function, not Vehicle's.
    void showInfo() { std::cout << "showInfo: Car\n"; }

    // showInfo() is also overloaded: this function is also Car's
    // member function. It has the same name but a different
    // parameter list.
    void showInfo(int x) { std::cout << "showInfo: Car " << x << "\n"; }
};

//----------------------------------------------------------
// Boat class is derived from Vehicle
// 
// Boat inherits from Vehicle as public:
//      Vehicle's private members are not accessible to Boat
//
//      Vehicle's protected members become 
//      Boat's protected members
//
//      Vehicle's public members become
//      Boat's public members
//
//      Boat class does not declare any member functions.
//      Boat instances inherit Vehicle's protected and 
//      public member functions.
//----------------------------------------------------------
class Boat : public Vehicle {
public:
    // Constructor
    Boat() { m_classId = 'b'; }
};

//----------------------------------------------------------
// main() : entry point
//----------------------------------------------------------
int main() {
    // This vector stores pointers to
    //      1) Vehicle instances
    //      2) Car instances (because a Car is a Vehicle)
    //      3) Boat instances (because a Boat is a Vehicle)

    std::vector<Vehicle*> vehicleVector;

    // Question:
    // How can we tell the difference between Vehicle, Car,
    // and Boat addresses stored together in this vector?

    // Answer:
    // We need to use the m_classId data member that is
    // present in Vehicle, Car, and Boat instances.

    // create a Vehicle instance and store its address in our vector
    Vehicle* pVehicle = new Vehicle;
    vehicleVector.push_back(pVehicle);

    std::cout << std::endl;

    // create a Car instance and store its address in our vector
    Car* pCar = new Car;
    vehicleVector.push_back(pCar);

    std::cout << std::endl;

    // create a Boat instance and store its address in our vector
    Boat* pBoat = new Boat;
    vehicleVector.push_back(pBoat);

    std::cout << std::endl;

    // determine class of each element by m_classId member
    for (Vehicle* pV : vehicleVector)
    {
        if (pV->getClass() == 'v')
            std::cout << "Vehicle instance\n";
        else if (pV->getClass() == 'c')
            std::cout << "Car instance\n";
        else if (pV->getClass() == 'b')
            std::cout << "Boat instance\n";
        else
            std::cout << "Unknown instance\n";
    }

    std::cout << std::endl;

    for (auto* pV : vehicleVector)
    {
        if (pV->getClass() == 'v')
        {
            std::cout << "Vehicle instance\n";
            pVehicle->showInfo();
        }
        else if (pV->getClass() == 'c')
        {
            std::cout << "Car instance\n";
            pCar->showInfo();
            pCar->showInfo(2);
        }
        else if (pV->getClass() == 'b')
        {
            std::cout << "Boat instance\n";
            pBoat->showInfo();
        }
        else
            std::cout << "Unknown instance\n";

        std::cout << std::endl;
    }

    system("pause");

    return 0;

}