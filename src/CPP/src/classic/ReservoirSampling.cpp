#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class Reservoir {
public:
    Reservoir(int size): size_(size) {
        inLen_ = 0;
    }

    void push(int num) {
        ++inLen_; // increase first to make sure it is already larger than 0
        if ((int)pool_.size() < size_) {
            pool_.push_back(num);
        } else {
            int idx = rand() % inLen_;
            cout << idx << endl;
            if (idx < size_)
                pool_[idx] = num;
        }
    }

    void printPool() {
        sort(pool_.begin(), pool_.end());
        for (int &num : pool_)
            cout << num << " ";
        cout << endl;
    }

private:
    int size_;
    int inLen_;
    vector<int> pool_;
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    for (int i = 0; i < 16; ++i) {
        // Reservoir sampling is to pick k items from n inputs with access to each input only once
        Reservoir r(3);
        for (int &num : nums)
            r.push(num);
        r.printPool();
    }

    return 0;
}
