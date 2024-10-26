// Topic : std::array

//  Syntax : std::array<datatype, size> array;

//Notice :
//1. std::array is a container that encapsulate fized size arrays .
//2. arraysize is needed at the compile time. means that the size element should be always filled.
//3. Assign by value os actually by value means that if we put our array in afunction then normal array doesnt create a copy of that array so we cant find size of it inside the function but in stl array we can.
//4. Acces elements :
//    at() , [] - both functions the same but if we go put value beyond the size of array in at it will go out of bounds
//    front() , back() - gives 1st and last element
//    data() 

#include <iostream>
#include <array>
using namespace std;

int mainO(){
    array <int, 5> arr = {1,2,3,4,5};
    array <int, 5> arr {1,2,3,4,5};

}