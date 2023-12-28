#include <iostream>
using namespace std;

void func_2(){
    cout <<"Start function 2" << endl;
    throw 100;
    cout <<"End function 2" << endl; 
}

void func_1(){
    cout <<"Start fucntion 1" << endl;
    func_2();
    cout << "End function 1" << endl;
}

int main(){
    cout << "Start main function " << endl;
    try{
        func_1();
    }
    catch (int &ex){
        cout <<"Catch exception in Main" << endl;
    }
    cout << "End main function" << endl;
    return 0;
}