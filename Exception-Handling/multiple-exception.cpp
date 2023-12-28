#include <iostream>

double average(int sum, int total){
    if (total == 0)
        throw 0;
    if (sum < 0 || total < 0)
        throw std::string{"Negative value error"};
    return static_cast<double>(sum)/total;
}

int main(){
    int sum{}, total{};
    double result {};
    std::cout <<"Enter sum ";
    std::cin >> sum;
    std::cout << "Enter total ";
    std::cin >> total;
    try{
        result = average(sum, total);
        std::cout << "Result :" << result << std::endl;
    } 
    catch (int &ex){
        std::cout << "Cannot divide by 0" << std::endl;
    } 
    catch (std::string &ex){
        std::cout << ex << std::endl;
    }
    catch (...){
        std::cout << "Unknown exception" << std::endl;
    }   
    return 0;
}