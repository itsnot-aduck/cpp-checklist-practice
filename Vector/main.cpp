#include <iostream>
#include "custom-vector.h"



int main(){
    Vector<int> MyVector;
    MyVector.push_back(1);
    std::cout << MyVector[0] << std::endl;
    MyVector[0] = 2;
    std::cout << MyVector[0] << std::endl;
    return 0;
}