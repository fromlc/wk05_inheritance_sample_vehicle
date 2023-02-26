//------------------------------------------------------------------------------
// Vehicles.h
//
// Base class Vehicle and derived classes Car, Boat
//
// Example of 
//      1) Redefining base class member functions, and
//      2) Polymorphism: derived class instances have
//         more than one type
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// Vehicle : base class
//------------------------------------------------------------------------------
class Vehicle {
protected:
    std::string info;
    std::string regType;

public:
    // constructors
    Vehicle() : Vehicle("vehicle") { }

    Vehicle(const std::string _info) {
        info = _info;
        regType = "Plate#";
        std::cout << "new Vehicle\n";
    }

    // member functions
    std::string getInfo() const { return info; }

    std::string getRegType() const { return regType; }
};

//------------------------------------------------------------------------------
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
// Car class has a constructor but no member functions.
// Car instances inherit Vehicle's member functions.
//
//------------------------------------------------------------------------------
class Car : public Vehicle {
public:
    // constructor
    Car() : Vehicle("car") {
        std::cout << "new Car\n";
    }
};

//------------------------------------------------------------------------------
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
// Boat class has a constructor.
// Boat instances inherit Vehicle's member functions, and
// Boat redefines Vehicle's getRegType() member function
//------------------------------------------------------------------------------
class Boat : public Vehicle {
public:
    // Constructor
    Boat() : Vehicle("boat") {
        std::cout << "new Boat\n";
        regType = "CF#";
    }   

    // redefines base class member function
    std::string getRegType() const { return regType; }
};
