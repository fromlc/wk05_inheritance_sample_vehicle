//------------------------------------------------------------------------------
// Vehicles.h
//
// Base class Vehicle and derived classes Car, Boat
//
// Example of 
//      1) Redefining base class member functions:
//         Boat redefines Vehicle::getRegType()
//      2) Polymorphism: a derived class instance has
//         more than one type. Here Car is-a Vehicle and
//         Boat is-a Vehicle.
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// Vehicle : base class
//------------------------------------------------------------------------------
class Vehicle {
private:

protected:
    char classId;
    std::string info;
    std::string regType;

public:
    // constructors
    Vehicle() : Vehicle("vehicle") { }

    Vehicle(const std::string _info) {
        classId = 'v';
        info = _info;
        regType = "Plate#";
        std::cout << "Vehicle constructor: new " << _info << "\n";
    }

    // member functions
    std::string getInfo() const { return info; }

    virtual std::string getRegType() const { return regType; }
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
private:
    std::string year;

public:
    // constructor
    Car() : Vehicle("car") {
        classId = 'c';
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
        classId = 'b';
        std::cout << "new Boat\n";
        regType = "CF#";
    }   

    // redefines base class member function
    std::string getRegType() const { return "California boat CF"; }
};
