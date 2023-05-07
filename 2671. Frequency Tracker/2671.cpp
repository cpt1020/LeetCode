#include <unordered_map>
#include <iostream>
using namespace std;

/*
g++ 2671.cpp -std=c++17 -o 2671 && ./2671
*/

class FrequencyTracker {
private:
    unordered_map<int, int> umap;
    unordered_map<int, int> freq;
public:
    FrequencyTracker() {}
    
    void add(int number) {
        umap[number] += 1;
        freq[umap[number]] += 1;
        freq[umap[number] - 1] -= 1;

        if (freq[umap[number] - 1] == 0) {
            freq.erase(umap[number] - 1);
        }
    }
    
    void deleteOne(int number) {
        if (umap.find(number) != umap.end()) {
            umap[number] -= 1;

            freq[umap[number] + 1] -= 1;
            freq[umap[number]] += 1;
            
            if (freq[umap[number] + 1] == 0) {
                freq.erase(umap[number] + 1);
            }
        }

        if (umap[number] == 0){
            umap.erase(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        if (freq.find(frequency) != freq.end()) {
            return true;
        }
        return false;
    }
};

int main() {

    FrequencyTracker* obj1 = new FrequencyTracker();
    obj1->add(3);
    obj1->add(3);
    cout << boolalpha << obj1->hasFrequency(2) << endl;
    // Output [null, null, null, true]

    cout << endl;
    FrequencyTracker* obj2 = new FrequencyTracker();
    obj2->add(1);
    obj2->deleteOne(1);
    cout << boolalpha << obj2->hasFrequency(1) << endl;
    // Output [null, null, null, false]

    cout << endl;
    FrequencyTracker* obj3 = new FrequencyTracker();
    cout << boolalpha << obj3->hasFrequency(2) << endl;
    obj3->add(3);
    cout << boolalpha << obj3->hasFrequency(1) << endl;
    // Output [null, false, null, true]

    return 0;
}