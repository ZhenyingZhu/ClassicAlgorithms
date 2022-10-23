#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://en.wikipedia.org/wiki/Bubble_sort

void bubbleSort(vector<int> &vec) {
    int len = vec.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < len; i++) {
            if (vec[i] < vec[i - 1]) {
                swap(vec[i], vec[i - 1]);
                swapped = true;
            }
        }
        len--;
    }
}

int main() {
    for (int i = 0; i < 100; i++) {
        vector<int> vec;
        int nums = rand() % 20;
        for (int j = 0; j < nums; ++j) {
            vec.push_back(rand() % nums + 10);
        }

        vector<int> tmp = vec;

        sort(vec.begin(), vec.end());
        bubbleSort(tmp);
        if (tmp != vec) {
            for (int &num : tmp)
                cout << num << ", ";
            cout << endl;
            for (int &num : vec)
                cout << num << ", ";
            cout << endl;
            break;
        }
    }

    return 0;
}
