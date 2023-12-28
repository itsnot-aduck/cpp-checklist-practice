#include <iostream>
#include <list>
#include <string>

using namespace std;

template<typename K, typename V>
class HashMap{
    private:
        int hashGroup;
        list <pair<K, V>> *table;
    public: 
        HashMap(int numOfGroup = 10);
        ~HashMap();
        int hashFunction(K key);
        void insert(K key, V value);
        void remove(K key);
        V search(K key);
        void print();
};

template<typename K, typename V>
HashMap<K, V>::HashMap(int numOfGroup)
    : hashGroup(numOfGroup){
    table = new list<pair<K, V>>[numOfGroup];
}

template<typename K, typename V>
HashMap<K, V>::~HashMap(){
    delete[] table;
}

template<typename K, typename V>
int HashMap<K, V>::hashFunction(K key){
    return key % hashGroup;
}

template<typename K, typename V>
void HashMap<K, V>::insert(K key, V value){
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

template<typename K, typename V>
void HashMap<K, V>::remove(K key){
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

template<typename K, typename V>
void HashMap<K, V>::print(){
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
    HashMap<int, int> HT;
    HT.insert(20, 10);
    HT.insert(20, 20);
    HT.print();
    return 0;
}