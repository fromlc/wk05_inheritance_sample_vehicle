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
protected:
    char classId;
    std::string info;
    std::string regType;

public:
    // constructor
    Vehicle() 
        : classId('v'), info("vehicle"), regType("Plate#") {

        std::cout << "Vehicle constructor: new Vehicle\n";
    }

    // member functions
    char getClassId() const { return classId; }

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
    Car() : year("2023") {
        classId = 'c';
        info = "car";

        std::cout << "Car constructor: new Car\n";
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
    Boat() {
        classId = 'b';
        info = "boat";
        regType = ("CF#");

        std::cout << "Boat constructor: new Boat\n";
    }   

    // redefines base class member function
    std::string getRegType() const { return "California CF#"; }
};
