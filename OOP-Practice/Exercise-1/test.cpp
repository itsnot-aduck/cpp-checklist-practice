#include <iostream>
#include <vector>

class Officer{
protected:
    std::string name;
    int age;
    int gender;
    std::string address;
public:
    Officer(std::string name, int age = 0, int gender = 2, std::string address = "None");
    virtual ~Officer(){};
    virtual void get_info() = 0;
    /* Set function */
    void set_name(std::string name);
    void set_age(int age);
    void set_gender(int gender);
    void set_address(std::string address);
    /* Get functions */
    std::string get_name();
    int get_age();
    int get_gender();
    std::string get_address();
};

Officer::Officer(std::string name, int age, int gender, std::string address)
    :name{name}, age{age}, gender{gender}, address{address}{
    std::cout << "Constructor made for " << name << std::endl;
}

class Worker : public Officer{
private:
    int level;
public:
    Worker(std::string name, int age = 0, int gender = 2, std::string address = "None", int level = 1);
    ~Worker(){};
    void set_level(int level);
    int get_level();
    void get_info() override;
};

Worker::Worker(std::string name, int age, int gender, std::string address, int level)
    : Officer{name, age, gender, address}, level{0}{
      std::cout << "Constructor for worker done" << std::endl;  
}

void Worker::get_info(){
    std::cout << "Worker: " << name <<", level: " << level << std::endl;
}

/* Subclass Engineer */
class Engineer : public Officer{
private:    
    std::string branch;
public:
    Engineer(std::string name, int age = 0, int gender = 2, std::string address = "None", std::string branch = "Base");
    void set_branch(std::string branch);
    std::string get_branch();
    void get_info() override;
};

Engineer::Engineer(std::string name, int age, int gender, std::string address, std::string branch)
    : Officer(name, age, gender, address), branch{branch}{}

void Engineer::get_info(){
    std::cout << "Engineer: " << name << ", Branch: " << branch << std::endl;
}

/* Main library for MemberManager */
class OfficerManagement{
private:
    std::vector<Officer*> Mem_list;
    void add_officer(Officer *new_person);
public:
    OfficerManagement(){};
    ~OfficerManagement();
    void add_worker(std::string name, int age, int gender, std::string address, int level);
    void add_engineer(std::string name, int age, int gender, std::string address, std::string branch);
    int search_person_by_name(std::string name);
    void get_info_member();
};

OfficerManagement::~OfficerManagement(){
    for (std::vector<Officer*>::iterator it; it != Mem_list.end(); it++){
        delete *it;
    }
}

void OfficerManagement::add_officer(Officer *new_person){
    Mem_list.push_back(new_person);
    std::cout << "Add person done " << std::endl;
}

void OfficerManagement::get_info_member(){
    std::cout << "[Officer List]" << std::endl;
    for (auto &element : Mem_list){
        element->get_info();
    }
}

int main(){
    std::vector <Officer*> Member;
    Officer* test = new Worker{"Duck"};
    Officer* test2 = new Engineer{"TPA"};
    OfficerManagement Officer_list;
    // Officer_list.add_officer(test);
    // Officer_list.add_officer(test2);
    Officer_list.get_info_member();
    return 0;
}