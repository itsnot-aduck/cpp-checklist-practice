#include <iostream>
#include <set>
#include <stdlib.h>

struct custom_compare final{
    bool operator() (const std::string& left, const std::string& right) const {
        int nleft = atoi(left.c_str());
        int nRight = atoi(right.c_str());
        return nleft < nRight;
    }
};

int main(){
    
    /* Define a set */
    std::set<std::string> stringSet({"1", "2", "3", "347", "289", "6"});

    /* Default sort method of set */
    std::cout << "Default sort on std::set" << std::endl;
    for (auto data: stringSet)
        std::cout << data << " ";
    std::cout << std::endl;  

    /* Sort method overloading by struct */
    std::set<std::string, custom_compare> customStringSet({"1", "2", "3", "347", "289", "6"}, 
                                                                            custom_compare{}); //custom compare of set
    std::cout << "Custom sort on std::set by struct" << std::endl;
    for (auto data: customStringSet)
        std::cout << data << " ";
    std::cout << std::endl;  

    /* Sort method overloading by lambda function */
    auto compare_lambda = [](auto &&lhs, auto &&rhs){return lhs > rhs; };
    using set_by_lambda = std::set<std::string, decltype(compare_lambda)>;
    set_by_lambda set_des_by_lambda({"1", "2", "5", "23", "6", "290"}, compare_lambda);
    std::cout << "Custom sort on std::set by lambda function" << std::endl;
    for (auto data: set_des_by_lambda)
        std::cout << data << " ";
    std::cout << std::endl;  

    return 0;
}