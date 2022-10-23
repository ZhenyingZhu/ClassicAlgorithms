#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{5, 6, 4, 3, 2, 6, 7, 9, 3};
    nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
    cout << vec[vec.size() / 2] << endl;
    for (int& num : vec)
        cout << num << " ";
    cout << endl;

    return 0;
}

