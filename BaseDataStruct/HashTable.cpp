#include <iostream>
#include <string>
using namespace std;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {
        size = 2000;
        elem = new string[size];
        for (int i = 0; i < size; i++) {
            elem[i] = "#";
        }
    }
    ~HashTable() {
        delete[] elem;
    }
    int hash(string& index) {
        int code = 0;
        for (size_t i = 0; i < index.length(); i++) {
            code = (code * 256 + index[i] + 128) % size;
        }
        return code;
    }
    
};
int main() {
    HashTable hashtable;
    return 0;
}