#include <set>
#include <iostream>
using namespace std;

/*
g++ 2336.cpp -std=c++17 -o 2336 && ./2336
*/

class SmallestInfiniteSet {
public:
    int currentNum {1};
    set<int> s;

    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if (s.empty() != true) {
            int smallest {*s.begin()};
            s.erase(s.begin());
            return smallest;
        }
        else {
            currentNum += 1;
            return (currentNum - 1);
        }
    }
    
    void addBack(int num) {
        if (num < currentNum) {
            s.insert(num);
        }
    }
};

int main() {

    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    obj->addBack(2);
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    obj->addBack(1);
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;
    cout << obj->popSmallest() << endl;

    return 0;
}