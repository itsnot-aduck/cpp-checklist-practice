#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable{
    private:
        static const int hashGroup = 10;
        list <pair<int, string>> table[hashGroup];
    public: 
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i = 0; i < hashGroup; i++){
        sum += table[i].size();
    }
    if(!sum)
        return true;
    else 
        return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroup;
}
 
void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++){
        if (bItr->first == key){
            keyExist = true;
            bItr->second = value;
            cout << "Warning: Key exist. Value replaced" << endl;
            break;
        }
    }

    if (!keyExist){
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++){
        if (bItr->first == key){
            keyExist = true;
            bItr = cell.erase(bItr);
            cout << "item removed" << endl;
            break;
        }
    }

    if (!keyExist){
        cout << "Item not found" << endl;
    }
    return;
}

void HashTable::printTable(){
    for (int i = 0; i < hashGroup ; i++){
        if(table[i].size() == 0){
            continue;
        }
        auto bItr = table[i].begin();
            for (; bItr != table[i].end(); bItr++){
                cout << "Key: " << bItr ->first <<", Value: " << bItr->second << endl;
            }
    }
}

int main(){
    HashTable HT;

    if(!HT.isEmpty()){
        cout << "HashTable is empty" << endl;
    }

    return 0;
}