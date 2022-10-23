#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct IdxNum {
    IdxNum(int i, int n): idx(i), num(n) {}
    int idx;
    int num;
    bool operator<(const IdxNum& other) const {
        return other.num < num;
    }
};

int main() {
    vector<int> arr = {5, 3, 9, 21, 54, 7};
    vector<IdxNum> v;
    for (int i = 0; i < arr.size(); i++) {
        v.push_back({i, arr[i]});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].num << endl;
    }
}
