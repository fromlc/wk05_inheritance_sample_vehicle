//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
#include "Vehicles.h"   // classes Vehicle, Car, Boat

#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;
using std::vector;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
//namespace poly { vector<Vehicle*> vv; }

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
inline void showInfo(vector<Vehicle*>&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
    // vector vv can store pointers to
    //      1) Vehicle instances, and
    //      2) Car instances (Car is-a Vehicle), and
    //      3) Boat instances (Boat is-a Vehicle)

    vector<Vehicle*> vv;

    // vector of Vehicle* can hold pointers to any class derived from Vehicle
    Vehicle* pV = new Vehicle;
    vv.push_back(pV);
    cout << "added Vehicle element\n\n";
    decltype(pV) pDeclV = pV;
    cout << "decltype: " << typeid(pDeclV).name() << '\n';

    cout << "typeid.name(): " << typeid(pV).name() << '\n';
    cout << pV->getInfo() << ' ' << pV->getRegType() << "\n\n";

    Car* pC = new Car;
    vv.push_back(pC);
    cout << "added Car element\n\n";

    decltype(pC) pDeclC = pC;
    cout << "decltype: " << typeid(pDeclC).name() << '\n';

    cout << "typeid.name(): " << typeid(pC).name() << '\n';
    cout << pC->getInfo() << ' ' << pC->getRegType() << "\n\n";

    Boat* pB = new Boat;
    vv.push_back(pB);
    cout << "added Boat element\n\n";

    decltype(pB) pDeclB = pB;
    cout << "decltype: " << typeid(pDeclB).name() << '\n';

    cout << "typeid.name(): " << typeid(pB).name() << '\n';
    cout << pB->getInfo() << ' ' << pB->getRegType() << "\n\n";

    // each vector element displays its info based on its class
    
    // with code in the same function
    cout << "main(): traversing vector of typeid "
        << typeid(vv).name() << ":\n\n";

    for (int i = 0; i < vv.size(); ++i) {
        decltype(vv.at(i)) pDecl = vv.at(i);
        cout << "decltype " << typeid(pDecl).name() << '\n';

        auto p = vv.at(i);
        cout << typeid(p).name() << '\n';
        cout << p->getInfo() << ' ' << p->getRegType() << "\n\n";
    }

    // with code in a called function
    showInfo(vv);

    cout << '\n';
    cin.get();

    return 0;
}

//------------------------------------------------------------------------------
// displays info and vector index for any vector element type
//------------------------------------------------------------------------------
void showInfo(vector<Vehicle*>& v) {

    cout << "showInfo(): traversing vector of typeid " 
        << typeid(v).name() << ":\n\n";

    for (int i = 0; i < v.size(); ++i) {
        decltype(v.at(i)) pDecl = v.at(i);
        cout << "decltype: " << typeid(pDecl).name() << '\n';

        auto p = v.at(i);
        cout << "typeid.name(): " << typeid(p).name() << '\n';
        cout << p->getInfo() << ' ' << p->getRegType() << "\n\n";
    }
}
