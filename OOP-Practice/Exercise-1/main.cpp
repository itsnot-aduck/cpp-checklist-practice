#include <iostream>
#include <list>

typedef enum{
    MALE,
    FEMALE,
    OTHER
} gender_t;


class Officer{
protected:
    std::string name;
    int age;
    gender_t gender;
    std::string address;
public:
    Officer(std::string name = "None", int age = 0, gender_t gender = OTHER, std::string address = "None");
    /* Set function */
    void set_name(std::string name);
    void set_age(int age);
    void set_gender(gender_t gender);
    void set_address(std::string address);
    /* Get functions */
    std::string get_name();
    int get_age();
    gender_t get_gender();
    std::string get_address();
    /* Get info of Officer */
    virtual void get_info();
};

Officer::Officer(std::string name, int age, gender_t gender, std::string address)
    : name{name}, age{age}, gender{gender}, address{address}{}

void Officer::set_name(std::string name){
    this->name = name;
}

void Officer::set_age(int age){
    this->age = age;
}

void Officer::set_gender(gender_t gender){
    this->gender = gender;
}

void Officer::set_address(std::string address){
    this->address = address;
}

std::string Officer::get_name(){
    return this -> name;
}

int Officer::get_age(){
    return this -> age;
}

gender_t Officer::get_gender(){
    return this -> gender;
}

std::string Officer::get_address(){
    return this -> address;
}


/* Subclass Worker */
class Worker : public Officer{
private:
    /* Level of worker, from 1 to 10 */
    int level;
public:
    Worker(std::string name = "None", int age = 0, gender_t gender = OTHER, std::string address = "None", int level = 1);
    void set_level(int level);
    int get_level();
    virtual void get_info() override;
};

Worker::Worker(std::string name, int age, gender_t gender, std::string address, int level)
    : Officer{name, age, gender, address}, level{level}{}

void Worker::set_level(int level){
    this -> level = level;
}

int Worker::get_level(){
    return this -> level;
}

void Worker::get_info(){
    std::cout << "Worker: " << name << ", Age: " << age << "Level: " << level << std::endl;
}

/* Subclass Engineer */
class Engineer : public Officer{
private:    
    std::string branch;
public:
    Engineer(std::string name = "None", int age = 0, gender_t gender = OTHER, std::string address = "None", std::string branch = "None");
    void set_branch(std::string branch);
    std::string get_branch();
    void get_info() override;
};

// Engineer::Engineer(std::string name, int age, gender_t gender, std::string address, std::string branch)
//     :Officer(name, age, gender, name), branch{branch} {}

// void Engineer::set_branch(std::string set_branch){
//     this -> branch = branch;
// }

// std::string Engineer::get_branch(){
//     return this->branch;
// }

// void Engineer::get_info(){
//     std::cout << "Engineer: " << name << ", Age: " << age << "Branch: " << branch << std::endl;
// }

// /* Subclass Staff */
// class Staff : public Officer{
// private:
//     std::string work;
// public:
//     Staff(std::string name = "None", int age = 0, gender_t gender = OTHER, std::string address = "None", std::string work = "None");
//     void set_work(std::string work);
//     std::string get_work();
//     void get_info() override;
// };

// Staff::Staff(std::string name, int age, gender_t gender, std::string address, std::string work)
//  :Officer{name, age, gender, address}, work{work}{}

// void Staff::set_work(std::string work){
//     this->work = work;
// }

// std::string Staff::get_work(){
//     return this -> work;
// }

// void Staff::get_info(){
//     std::cout << "Staff: " << name << ", Age: " << age << "Work: " << work << std::endl;
// }

/* Officer Management */
// class Officer_management{
//     private:
//         std::list<Officer> Officer_list;
//     public: 
//         void add_Officer(Officer new_officer); 
//         void find_officer_by_name(std::string name);
//         void show_list_officer();
// };

// void Officer_management::add_Officer(Officer new_officer){

// }

int main(){
    int mode;
    Officer* test = new Worker("Hello", 12, OTHER, "Hanoi", 10);
    test->get_info();
    // while(1){
    //     std::cout << "Choose action | 1. Add | 2. Find | 3. Export | 4. Exit ";
    //     std::cin >> mode;
    //     /* Base info of officer */
    //     std::string new_name = "None";
    //     int new_age;
    //     int new_gender;
    //     std::string new_address = "None";
    //     switch(mode){
    //         case 1: 
    //         {
    //         int role;
    //         /* base information of Officer */
    //         std::cout << "[Add Officer] Choose role of officer | 1. Worker | 2. Engineer | 3. Staff ";
    //         std::cin >> role;
    //         std::cout << "Name: ";
    //         std::cin >> new_name;
    //         std::cout << "Age: ";
    //         std::cin >> new_age;
    //         std::cout << "Gender: 1. Male | 2. Female | 3. Other "; 
    //         std::cin >> new_gender;
    //         switch (role){
    //             case 1: /* worker */
    //             {
    //                 int new_level;
    //                 std::cout << "Level: ";
    //                 std::cin >> new_level;
    //                 Worker new_officer(new_name, new_age, OTHER, new_address, new_level);
    //                 break;
    //             }
    //             case 2: /* Engineer */
    //             break;
    //             case 3: /* Staff */
    //             break;
    //         }
    //         /* Input information of officers */
    //         break;
    //         }
    //         case 2:
    //         break;
    //         case 3:
    //         break;
    //         case 4:
    //             std::cout << "End!" << std::endl;
    //             return 0;
    //         break;
    //         default:
    //             std::cout << "Invalid mode" << std::endl;
    //     }
    // }
    return 0;
}