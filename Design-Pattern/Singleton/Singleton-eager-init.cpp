/**
 * Singleton Design 
 * 
 * Usage:
 * - Multithread: Threadpool
 * - Database application: Logging
 * - Configuration Setting: Game settings, application setting, ...
*/

#include <iostream>
#include <string>

using namespace std;

class Singleton{
protected:
    Singleton (const int value): value(value){};
    static Singleton* _Instance;
    int value;
public:
    /* Prevent cloning the singleton */
    Singleton (Singleton &other) = delete;
    /* Prevent assigning singleton */
    void operator=(const Singleton &) = delete;
    /* Initialize the Instance */
    static Singleton* getInstance(const int& value);
    /* Free the Instance */
    void free();
    void setNum(int num);
    int getNum();
};

/* Make static instance outside the class */
Singleton* Singleton::_Instance = nullptr;

/* Create Instance */
Singleton *Singleton::getInstance(const int& value){
    if(_Instance == nullptr){
        _Instance = new Singleton(value);
    }
    return _Instance;
}

void Singleton::free(){
    cout << "test" << endl;
    if (_Instance != nullptr){
        cout << "Instance deleted" << endl;
        delete _Instance;
        _Instance = nullptr;
    }
}


void Singleton::setNum(int num){
    _Instance->value = num;
}

int Singleton::getNum(){
    return _Instance->value;
}

int main(){
    /* Make Instance */
    Singleton* Instance = Singleton::getInstance(10);
    Singleton* Instance2 = Singleton::getInstance(20);

    /* Check for value of instance */
    cout << Instance->getNum() << endl;
    cout << Instance2->getNum() << endl;

    /* Free the Instance, avoid memory leak */
    Instance->free();
    Instance2->free();
    return 0;
}